#include "Listener.hpp"


namespace CppSocket
{
    Listener::Listener()
    {
        m_sock_fd = 0;
    }


	void Listener::closeSocket()
	{
		std::cout << "closing Listener" << std::endl;
		close(static_cast<int>(m_sock_fd));
		m_sock_fd = 0;
	}
    Connection CppSocket::Listener::getConnection()
    {
        return Connection(accept((SOCKET)m_sock_fd, NULL, NULL));
    }
}