#include "ConnectionFactory.hpp"


namespace CppSocket
{

    ConnectionFactory::ConnectionFactory( )
    {
        m_host = new std::string();
        m_port = new std::string();

    #ifdef _WIN32
        int iResult;
        WSADATA wsaData;

        iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
        if (iResult != 0) 
        {
            std::cout << "WSAStartup failed: " << iResult << std::endl;
        }
    #endif
    }

    ConnectionFactory::~ConnectionFactory()
    {
        delete m_host;
        delete m_port;
    }

    void ConnectionFactory::setSockType( SocketType::SocketTypes sock_in )
    {
        m_socktype = sock_in;
    }

    SocketType::SocketTypes ConnectionFactory::getSockType()
    {
        return m_socktype;
    }

    void ConnectionFactory::setPort(std::string port_in)
    {
        int temp_port = std::stoi(port_in);
        if (( temp_port > 0 )&&( temp_port <= 65535))
            *m_port = port_in;	
    }

    void ConnectionFactory::setHost(std::string host_in)
    {
        *m_host = host_in;
    }

    std::string ConnectionFactory::getHost()
    {
        return *m_host;
    }

    std::string ConnectionFactory::getPort()
    {
        return *m_port;
    }
}
