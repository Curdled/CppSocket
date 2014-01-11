#ifndef _ACTION_HPP_
#define _ACTION_HPP_

#include "SocketInclude.hpp"
#include "SocketMessage.hpp"
#include "ActionType.hpp"

namespace CppSocket
{
	class __DLL__ Action
	{
	public:
		//enum ActionToken
		//{
		//	NOTHING,
		//	MSG,
		//	CONN,
		//	DISCONN
		//};
	private:
		ActionType::ActionTypes m_token;
		std::string *argument;
        size_t sock_fd;
	public:
		Action();
		Action(ActionType::ActionTypes token_in, std::string value_in);
		Action(const Action &act_in );
		ActionType::ActionTypes getToken();
		bool setToken(ActionType::ActionTypes token_in);
		bool setToken(std::string token_in);
		void setTokenNONE(){m_token = ActionType::NOTHING;};
        void setSockNumber(size_t sock_fd_in){sock_fd = sock_fd_in;};

		std::string getString(){return *argument;};
		void setString(std::string string_in){*argument = string_in;};
        size_t getSockNumber(){return sock_fd;};
	};
};

#endif
