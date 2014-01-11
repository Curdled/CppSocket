#include "Action.hpp"

namespace CppSocket
{
	Action::Action()
	{
		argument = new std::string();
	}

	Action::Action(ActionType::ActionTypes token_in, std::string value_in)
	{
		argument = new std::string(value_in);
		m_token = token_in;
	}

	Action::Action(const Action &act_in)
	{
		argument = new std::string(*act_in.argument);
		m_token = act_in.m_token;
	}

	bool Action::setToken(std::string token_in)
	{
		if ("CONN" == token_in)//why does this not work strcmp("MSG", token_in.c_str())
		{
			m_token = ActionType::CONN;
			return true;
		}
		else if ("MSG" == token_in)
		{
			m_token = ActionType::MSG;
			return true;
		}
		else if ("DISCONN" == token_in)
		{
			m_token = ActionType::DISCONN;
			return true;
		}
		else
		{
			m_token = ActionType::NOTHING;
			return false;
		}
	}
	ActionType::ActionTypes Action::getToken()
	{
		return m_token;
	};

	bool Action::setToken(ActionType::ActionTypes token_in)
	{
		m_token = token_in; return true;
	};
}