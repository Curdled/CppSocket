#include "ConnectionFactory.hpp"


namespace CppSocket
{
    ConnectionFactory::ConnectionFactory( )
    {
    #ifdef _WIN32
        //only need to peform this check on windows... Where the _WIN32 symbol is defined
        int iResult;
        WSADATA wsaData;

        iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
        if (iResult != 0) 
        {
            std::cerr << "WSAStartup failed: " << iResult << std::endl;
        }
    #endif
    }



    void ConnectionFactory::setSockType( SocketType::SocketTypes sock_in )
    {
        m_socktype = sock_in;
    }

    SocketType::SocketTypes ConnectionFactory::getSockType()
    {
        return m_socktype;
    }

    void ConnectionFactory::setPort(std::string *port_in)
    {
        int temp_port = std::stoi(*port_in);
        if (( temp_port > 0 )&&( temp_port <= 65535))
            m_port = std::string(*port_in);	
    }

    void ConnectionFactory::setHost(std::string *host_in)
    {
        m_host = std::string(*host_in);
    }

    std::string ConnectionFactory::getHost()
    {
        return m_host;
    }

    std::string ConnectionFactory::getPort()
    {
        return m_port;
    }
}
