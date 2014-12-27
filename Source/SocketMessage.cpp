#include "SocketMessage.hpp"

namespace CppSocket
{
    SocketMessage::SocketMessage()
    {
        m_message = new std::string();
    }

    SocketMessage::SocketMessage(const SocketMessage &msg_in)
    {
        m_message = new std::string(*msg_in.m_message);
        m_sock_id = msg_in.m_sock_id;
    }

    SocketMessage::SocketMessage(const std::string& string_in, const size_t& sock_in )
    {
        m_sock_id = sock_in;
        m_message = new std::string(string_in);
    }
	SocketMessage::SocketMessage(std::string str_in)
		:m_sock_id(0)
	{
		m_message = new std::string(str_in);
	}

    SocketMessage::~SocketMessage()
    {
        delete m_message;
    }

    void SocketMessage::setMessage(const std::string& string_in )
    {
        *m_message = string_in;
    }
	void SocketMessage::appendMessage(std::string* msg_in)
	{
		
		m_message->append(*msg_in);
	}
	void SocketMessage::appendMessage(std::string string_in)
	{
		m_message->append(std::string(string_in));
	}
    void SocketMessage::setSock(const size_t& sock_in)
    {
        m_sock_id = sock_in;
    }

    size_t SocketMessage::getLen()
    {
        return m_message->size();
    }

    size_t SocketMessage::getID()
    {
        return m_sock_id;
    }

    std::string SocketMessage::getMessage()
    {
        return *m_message;
    }

    std::ostream& operator<<(std::ostream& cout, CppSocket::SocketMessage obj)
    {
        cout << obj.getMessage();
        return cout;
    }
}
