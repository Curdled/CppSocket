#ifndef _CLIENT_CONNECTION_FACTORY_HPP_
#define _CLIENT_CONNECTION_FACTORY_HPP_

#include "ConnectionFactory.hpp"

#include <string>

namespace CppSocket
{
	class ClientConnectionFactory : public ConnectionFactory
	{
	private:
		friend class Connection;


		struct addrinfo m_hints, *m_res, *m_p;
		int m_status, m_protocol;
		SOCKET m_sock_fd;

		void initConstructor();
		void setAddrInfo();
		int getAddrInfo();	

	public:
	
		/*ClientConnectionFactory( std::string hostname_in, int port_in );
		ClientConnectionFactory( std::string hostname_in, std::string port_in );*/
		__DLL__ ClientConnectionFactory(std::string *hostname_in, int port_in, SocketType::SocketTypes sock_enum_in = SocketType::SocketTypes::TCP_SOCK);
		__DLL__ ClientConnectionFactory(std::string *hostname_in, std::string *port_in, SocketType::SocketTypes  sock_enum_in = SocketType::SocketTypes::TCP_SOCK);
		__DLL__ ~ClientConnectionFactory();

		Connection __DLL__ getConnection();

	};
};
#endif