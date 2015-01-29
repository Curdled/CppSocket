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
		void closeSocket();//must be called before the Listner is delete or does out of scope.
		size_t getSocket(){return m_sock_fd;};//get the socket handler.
	private:
		
		Listener(size_t sock_in){m_sock_fd = sock_in;};
	};
};

#endif