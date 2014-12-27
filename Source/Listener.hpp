#ifndef _LISTENER_HPP_
#define _LISTENER_HPP_

#include "SocketInclude.hpp"
#include "Connection.hpp"

namespace CppSocket
{
	class __DLL__ Listener
	{
	private:
		size_t m_sock_fd;

		//friend
		friend class ServerConnectionFactory;
	public:
		Listener();
		Connection getConnection();
		void closeSocket();
		size_t getSocket(){return m_sock_fd;};
	private:
		
		Listener(size_t sock_in){m_sock_fd = sock_in;};
	};
};

#endif