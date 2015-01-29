///////////////////////////////////////////////////////////
//  Connection.cpp
//  Implementation of the Class Connection
//  Created on:      29-Mar-2013 14:40:01
//  Original author: Joe
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
//Constructor
///////////////////////////////////////////////////////////

#include "Connection.hpp"

namespace CppSocket
{

  

    Connection::Connection( size_t sock_in )
    {
        m_sock_fd = sock_in;
        initConstructor();
    }

    Connection::~Connection()
    {

      //  close(m_sock_fd);

    }

    void Connection::initConstructor()
    {
        ;
    }

    ///////////////////////////////////////////////////////////
    //Public
    ///////////////////////////////////////////////////////////
    //Recv Func
    int Connection::operator>>(std::string &msg_out )
    {
		return Receive(msg_out);
    }

    int Connection::recvMessage(std::string &msg_out)
    {
        return Receive(msg_out);
    }

    int Connection::operator>> (CppSocket::SocketMessage &msg_out )
    {
        return recvSocket(msg_out);
    }

    int Connection::recvMessage(CppSocket::SocketMessage &msg_out)
    {
        return recvSocket(msg_out);
    }
	int Connection::operator>> (CppSocket::SocketMessage *msg_out)
	{
		return recvSocket(*msg_out);
	}

	int Connection::recvMessage(CppSocket::SocketMessage *msg_out)
	{
		return recvSocket(*msg_out);
	}
    //Recv Func

    //Send Func
	int Connection::sendMessage(std::uint32_t msg) 
	{
        
        std::string str_in;
        str_in.resize(4);
        str_in[0] = (msg >> 24) & 0xFF;
        str_in[1] = (msg >> 16) & 0xFF;
        str_in[2] = (msg >> 8) & 0xFF;
        str_in[3] = msg & 0xFF;
        //This will back a 32 bit int to 4 chars stored into a string.
		return static_cast<int>(send(static_cast<int>(m_sock_fd), &str_in[0], static_cast<int>(sizeof(uint32_t)), 0));
	}

    int Connection::operator<<(std::string &msg_in )
    {
        return Send(msg_in);
    }

    int Connection::sendMessage(std::string &msg_in)
    {
        return Send(msg_in);
    }

    int Connection::operator<< (CppSocket::SocketMessage &msg_in)
    {
        return Send(msg_in.getMessage());
    }

    int Connection::sendMessage(CppSocket::SocketMessage &msg_in)
    {
        return Send(msg_in.getMessage());
    }
    
    int Connection::operator <<(char* msg_in)
    {
        return Send(std::string(msg_in));
    }
    
    int Connection::sendMessage(char* msg_in)
    {
        return Send(std::string(msg_in));
    }
    
    //Send Func
	bool Connection::isConnected()
    {
		return 0 != m_sock_fd;
    }
    size_t Connection::getSocket ( )
    {
        return m_sock_fd;
    }

    ///////////////////////////////////////////////////////////
    //Private
    ///////////////////////////////////////////////////////////

    int Connection::recvSocket(SocketMessage& msg_out )
    {
        std::string msg_string(msg_out.getMessage());
        int status = Receive(msg_string);
        if (status == -1)
        {
            msg_string.empty();
            msg_out.setMessage(msg_string);
			msg_out.setSock(0);
            return -1;
        }
        msg_out.setMessage(msg_string);
        msg_out.setSock(m_sock_fd);
        return status;
    }

    int Connection::recvSocket( std::string& msg_out )
    {
        return Receive(msg_out);
    }

    int Connection::Send(std::string msg_in)         // Handles partial sends
    {
        int sent = 0;
        int count = 0;
        size_t status = 0;
        while (sent != msg_in.size())
        {
			
            status = (send(static_cast<int>(m_sock_fd), &msg_in[0], static_cast<int>(msg_in.size()), 0));
            if (status == -1 || count == 5)
                return -1;
            sent += static_cast<int>(status);
            count++;
        }
        return int(msg_in.size());
    }

    int Connection::Receive(std::string& msg_out)
    {
		size_t status;
		std::string buffers;
        char buf[_cm_message_len_] = {0};
		status = recv(static_cast<int>(m_sock_fd), buf, sizeof buf, 0);
		if(status == -1)
			return -1;
        msg_out.assign(buf, status);
        return static_cast<int>(status);
    }

	void Connection::closeSocket()
	{
		close(static_cast<int>(m_sock_fd));
		m_sock_fd = 0;
	}
    
    //Comparison operators for the Connectio class work by comparing the value for socket file handler.
    bool Connection::operator !=(Connection c_in)
    {
		return !(this->m_sock_fd == c_in.m_sock_fd);
    }
	bool Connection::operator == (Connection c_in)
	{
		return (this->m_sock_fd == c_in.m_sock_fd);
	}
	
	bool Connection::operator<(const Connection c_in) const
	{
		return m_sock_fd < c_in.m_sock_fd;
	}
	
}