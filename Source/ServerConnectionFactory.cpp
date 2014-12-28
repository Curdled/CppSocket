#include "ServerConnectionFactory.hpp"
#include <string.h>
#include <iostream>

namespace CppSocket
{
    ServerConnectionFactory::ServerConnectionFactory(int port_in)
    {
        setSockType(SocketType::SocketTypes::TCP_SOCK);
		std::string port = to_string(port_in);
		setPort(&port);
        initConstructor();
    }

    ServerConnectionFactory::ServerConnectionFactory(int port_in, SocketType::SocketTypes conn_type)
    {
        setSockType(conn_type);
		std::string port = to_string(port_in);
		setPort(&port);
        initConstructor();
    }

    ServerConnectionFactory::ServerConnectionFactory(std::string *port_in, SocketType::SocketTypes conn_type)
    {
        setSockType(conn_type);
        setPort(port_in);
        initConstructor();
    }

    Listener CppSocket::ServerConnectionFactory::getConnection()
    {
        setAddrInfo();
        getAddrInfo();
        return *new Listener(m_sock_fd);
    }

    void ServerConnectionFactory::initConstructor()
    {
     ;   
    }

    void ServerConnectionFactory::setAddrInfo()
    {
        memset(&m_hints, 0, sizeof(m_hints));
        m_hints.ai_family = AF_UNSPEC;
        m_hints.ai_socktype = getSockType();
        m_hints.ai_flags = AI_PASSIVE;
    }

    void CppSocket::ServerConnectionFactory::getAddrInfo()
    {
    #ifdef _WIN32
        int m_yes = true;
    #define setsockopt_cross (char *)&m_yes
    #elif __linux__ || __APPLE__
		int m_yes = 1;
        #define setsockopt_cross &m_yes
        
    #endif
        if ((m_status = getaddrinfo(NULL, getPort().c_str(), &m_hints, &m_result)) != 0) 
		{
            std::cerr << "getaddrinfo: " << gai_strerror(m_status) << std::endl;

        }

        for(m_pointer = m_result; m_pointer != NULL; m_pointer = m_pointer->ai_next) 
		{
            if ((m_sock_fd = socket(m_pointer->ai_family, m_pointer->ai_socktype, m_pointer->ai_protocol)) == static_cast<size_t>(-1)) 
			{
                std::cerr <<"server: socket";
                continue;
            }

        if (setsockopt(static_cast<int>(m_sock_fd), SOL_SOCKET, SO_REUSEADDR, setsockopt_cross, sizeof(int)) == -1)
            {
                std::cerr << "setsockopt";
                exit(1);
            }

            if (bind(static_cast<int>(m_sock_fd), m_pointer->ai_addr, static_cast<int>(m_pointer->ai_addrlen)) == -1)
			{
                shutdown(static_cast<int>(m_sock_fd), 2);
                continue;
            }

            break;
        }

        if (m_pointer == NULL)  
		{
    #ifdef _DEBUG
            std::cerr << "server: failed to bind" << std::endl;
    #endif
            m_sock_fd = 0;
        }

        freeaddrinfo(m_pointer);
		if (listen(static_cast<int>(m_sock_fd), 5) == -1)
			return;

    }
}
