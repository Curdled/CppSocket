#include "SelectCallBackOne.hpp"
#include "Select.hpp"
#include <iostream>

class Select;

namespace CppSocket
{
    
    SelectCallBackOne::SelectCallBackOne(Select* select_in)
    :SelectCallBack(select_in)
    {
        m_username_list = new std::map<size_t, std::string>();
    }
	int SelectCallBackOne::onAccpet(Connection conn_in)
	{
		std::cout << "socket accept: " <<  conn_in.getSocket() << std::endl;
        
		return 0;
	}

	int SelectCallBackOne::onMessage(SocketMessage msg_in, Connection conn_in)
	{
		std::cout << "message: " <<  msg_in.getMessage() << " from: " << msg_in.getID() << std::endl;
        MessageParser par;
		par.setMsg(msg_in);
		Action action_msg = par.getAction();
		if(action_msg.getToken() == ActionType::CONN)
        {
			(*m_username_list)[conn_in.getSocket()] = action_msg.getString();
            std::cout << "\nthis is the new username: " <<(*m_username_list)[conn_in.getSocket()];
        }
		else if(action_msg.getToken() == ActionType::MSG)
		{
			std::string str(std::string(m_username_list->find(conn_in.getSocket())->second)+": "+std::string(action_msg.getString())+"\n");
            std::cout << "\nthis is the new string: " << str << std::endl;
            msg_in.setMessage(str);
			m_select->sendAll(msg_in, conn_in);
		}
        
		return 0;
	}

	int SelectCallBackOne::onRemove(Connection conn_in)
	{
		m_username_list->erase(conn_in.getSocket());
		std::cout << "socket remove: " <<  conn_in.getSocket() << std::endl;
		return 0;
	}
};