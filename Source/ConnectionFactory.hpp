#ifndef _CONNECTION_FACTORY_HPP_
#define _CONNECTION_FACTORY_HPP_


#include "SocketInclude.hpp"
#include "SocketType.hpp"
#include "Connection.hpp"

#include <string>

namespace CppSocket
{
	class __DLL__ ConnectionFactory
	{
	private:
		std::string *m_host, *m_port;
		SocketType::SocketTypes m_socktype;
	public:

//		enum SOCK
//		{
//			TCP_SOCK,
//			UDP_SOCK
//		};

		ConnectionFactory();
		~ConnectionFactory();
  
		void setPort( std::string port_in );
		void setHost (std::string host_in);
    
		//virtual Connection getConnection() =0;

		std::string getPort();
	
		std::string getHost();
		protected:
		void setSockType( SocketType::SocketTypes sock_in);
		SocketType::SocketTypes getSockType();
	};
};

#endif