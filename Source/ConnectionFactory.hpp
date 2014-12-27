#ifndef _CONNECTION_FACTORY_HPP_
#define _CONNECTION_FACTORY_HPP_


#include "SocketInclude.hpp"
#include "SocketType.hpp"
#include "Connection.hpp"

#include <string>

namespace CppSocket
{
	class  ConnectionFactory
	{
	private:
		std::string m_host, m_port;
		SocketType::SocketTypes m_socktype;
	public:

		__DLL__ ConnectionFactory();
		
  
		void __DLL__ setPort(std::string *port_in);
		void __DLL__ setHost(std::string *host_in);
    
		//virtual Connection getConnection() =0;

		std::string __DLL__ getPort();
	
		std::string __DLL__ getHost();
		
		void __DLL__ setSockType(SocketType::SocketTypes sock_in);
		__DLL__ SocketType::SocketTypes getSockType();
	};
};

#endif