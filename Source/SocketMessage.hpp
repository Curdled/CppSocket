#ifndef _SOCKET_MESSAGE_HPP_
#define _SOCKET_MESSAGE_HPP_

#include "SocketInclude.hpp"
#include <string>

namespace CppSocket
{
	class __DLL__ SocketMessage
	{
	private:
		std::string *m_message;
		size_t m_sock_id;
    
		void initConstructor();
	public:

		SocketMessage();
		SocketMessage(const SocketMessage &msg_in);
		SocketMessage(const std::string& string_in, const size_t& sock_in );
		SocketMessage(std::string str_in);
		~SocketMessage();

		void setMessage(const std::string& string_in);
		void appendMessage(std::string* string_in);
		void appendMessage(std::string string_in);
		void setSock(const size_t& sock_in);
	
		size_t getLen();
		size_t getID();
		std::string getMessage();
	};
};

std::ostream& operator<<(std::ostream& cout, CppSocket::SocketMessage obj);

#endif