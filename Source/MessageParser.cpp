#include "MessageParser.hpp"
#include <iostream>

namespace CppSocket
{

    MessageParser::MessageParser()
    {
        m_current_message = new std::string();
    }

    void MessageParser::processMessage()
    {
        using namespace std;
       

        std::string tmp, token;
        cmatch res;
        regex reg("<[^>]+[^;]+");//find token and value

        regex_search(m_current_message->c_str(), res, reg);
        tmp = res[0];
        if (tmp.length() == 0)
        {
            m_action.setTokenNONE();

            return;
        }
        reg = ( "<[^>]+");//for token
        regex_search(tmp.c_str(), res, reg);
        token = res[0];
        token.erase(token.begin());
        m_action.setToken(token);//set token based on string
        //std::cout << "token length: " << token.length() << std::endl;
        //find value for token
        tmp.erase(tmp.begin(),tmp.begin()+token.length()+2);//gets the value of the message
        m_action.setString(tmp);
    }

    Action CppSocket::MessageParser::getAction()
    {
        processMessage();
        return m_action;
    }
}

