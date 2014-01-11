#ifndef _MESSAGE_PARSER_HPP_
#define _MESSAGE_PARSER_HPP_

#include "SocketInclude.hpp"
#include "Action.hpp"


#include <regex>


namespace CppSocket
{
	class __DLL__ MessageParser
	{
	private:
		std::string *m_current_message;
		Action m_action;
	public:
		MessageParser();
		Action getAction();
		
		void setMsg(std::string message_in){*m_current_message = message_in;};
		void setMsg(CppSocket::SocketMessage msg_in){*m_current_message = msg_in.getMessage();};
	private:
		void processMessage();
		
	};
};

#endif