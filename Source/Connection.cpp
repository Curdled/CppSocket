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
        return recvSocket(msg_out);
    }

    int Connection::recvMessage(std::string &msg_out)
    {
        return recvSocket(msg_out);
    }

    int Connection::operator>> (CppSocket::SocketMessage &msg_out )
    {
        return recvSocket(msg_out);
    }

    int Connection::recvMessage(CppSocket::SocketMessage &msg_out)
    {
        return recvSocket(msg_out);
    }
    //Recv Func

    //Send Func
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
    bool Connection::checkConn( )
    {
        ;// TODO :IMPLEMENT
        return true;
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
            status = (send(static_cast<int>(m_sock_fd), msg_in.c_str(), static_cast<int>(msg_in.size()), 0));
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
	}
    
    bool Connection::operator !=(Connection c_in)
    {
        if(this->m_sock_fd == c_in.m_sock_fd)
            return false;
        return true;
    }
}