#include "ClientConnectionFactory.hpp"

//#include "StringFunction.hpp"
#include <string.h>
#include <iostream>
#ifdef _WIN32
    #pragma comment (lib, "ws2_32.lib")
#endif

namespace CppSocket
{
    ClientConnectionFactory::ClientConnectionFactory(std::string *hostname_in, int port_in, SocketType::SocketTypes sock_enum_in)
        :ConnectionFactory()
    {
        setSockType(sock_enum_in);
		std::string port = to_string(port_in);
		setPort(&port);
        setHost(hostname_in);
        initConstructor();
    }

    ClientConnectionFactory::ClientConnectionFactory(std::string *hostname_in, std::string *port_in, SocketType::SocketTypes sock_enum_in)
        :ConnectionFactory()
    {
        setSockType(sock_enum_in);
        setPort(port_in);
        setHost(hostname_in);
        initConstructor();
    }

    void ClientConnectionFactory::initConstructor()
    {
        m_res = NULL;
        m_p = NULL;

    }

    ClientConnectionFactory::~ClientConnectionFactory()
    {
        ;
    }

    void ClientConnectionFactory::setAddrInfo()
    {
        if(getSockType() == SocketType::TCP_SOCK )
            m_protocol = IPPROTO_TCP;
        else if(getSockType() == SocketType::UDP_SOCK )
            m_protocol = IPPROTO_UDP;

        memset(&m_hints,0, sizeof m_hints);
        m_hints.ai_family = AF_UNSPEC;
        m_hints.ai_socktype = getSockType();
        m_hints.ai_protocol = m_protocol;
    }

    int ClientConnectionFactory::getAddrInfo()
    {

        if ((m_status = getaddrinfo(getHost().c_str(), getPort().c_str(), &m_hints, &m_res)) != 0)
        {
    #ifdef _DEBUG
            std::cerr << "getaddrinfo" << std::endl;
    #endif
        }
        for( m_p = m_res; m_p != NULL; m_p = m_p->ai_next )
        {
            if (( m_sock_fd = socket(m_p->ai_family, m_p->ai_socktype, m_p->ai_protocol )) == -1 )
            {
    #ifdef _DEBUG
                std::cerr << "socket:" << std::endl;
    #endif
                continue;
            }

            if ( connect ( m_sock_fd, m_p->ai_addr,static_cast<int>( m_p->ai_addrlen) ) == -1 )
            {
    #ifdef _DEBUG
                std::cerr << "connect:" << std::endl;
    #endif
                close(m_sock_fd);
                continue;
            }
            break;
        }
        if(m_p == NULL)
        {
    #ifdef _DEBUG
        std::cerr << "failed";
    #endif
        m_sock_fd =  0;
        }
		
        //free memory.
        while(m_p != NULL)
            m_p = m_p->ai_next;
        while(m_res != NULL)
            m_res = m_res->ai_next;
        freeaddrinfo(m_p);
        freeaddrinfo(m_res);
        delete m_p;
        delete m_res;

        return 0;


    }

    Connection CppSocket::ClientConnectionFactory::getConnection()
    {
        setAddrInfo();
        if (getAddrInfo() == -1)
            return Connection(0);
        return Connection(m_sock_fd); 
    }
}
