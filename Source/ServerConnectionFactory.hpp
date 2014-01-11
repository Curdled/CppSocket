#ifndef _SERVER_CONNECTION_FACTORY_HPP_
#define _SERVER_CONNECTION_FACTORY_HPP_

#include "ConnectionFactory.hpp"
#include "Listener.hpp"

namespace CppSocket
{
	class __DLL__ ServerConnectionFactory : public ConnectionFactory
	{
	private:
		struct addrinfo m_hints, *m_result, *m_pointer;

		int m_yes, m_status;
		size_t m_sock_fd;

	
		void setAddrInfo();
		void getAddrInfo();
		void initConstructor();
	public:
        ServerConnectionFactory( int port_in);//, SOCK conn_type);
		ServerConnectionFactory( int port_in, SocketType::SocketTypes conn_type);
		ServerConnectionFactory( std::string port_in, SocketType::SocketTypes conn_type);
    
		Listener getConnection();
    

        
	};
};

#endif