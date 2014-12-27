///////////////////////////////////////////////////////////
//  Connection.hpp
//  Original author: Joe
///////////////////////////////////////////////////////////

#ifndef _CONNECTION_HPP_
#define _CONNECTION_HPP_


#include <cstdint>
#include "SocketInclude.hpp"
#include "SocketMessage.hpp"
#include <string>
#include <iostream>



namespace CppSocket
{
	static const int _cm_message_len_ = 1000000;
	static const std::string* _cm__END_LINE__ = new std::string("\r\n");
	
	class __DLL__ Connection
	{
	protected:
		
		size_t m_sock_fd;
	public:
		//friends
		friend class ClientConnectionFactory;
		friend class Listener;
		//friend class SocketMonitorCallBackCounted;
		

		~Connection();
		//Receive
		int operator>>(std::string &msg_out );
		int recvMessage(std::string &msg_out);
		
		int operator>>(CppSocket::SocketMessage &msg_out);
		int recvMessage(CppSocket::SocketMessage &msg_out);

		int operator>>(CppSocket::SocketMessage *msg_out);
		int recvMessage(CppSocket::SocketMessage *msg_out);
		//Send
		int sendMessage(std::uint32_t msg); //this will convert the uint32_t to host byte order

		int operator<<(std::string &msg_in );
		int sendMessage(std::string &msg_in);
		

		int operator<< (CppSocket::SocketMessage &msg_in);
		int sendMessage(CppSocket::SocketMessage &msg_in);

		int operator<<(CppSocket::SocketMessage *msg_out);
		int sendMessage(CppSocket::SocketMessage *msg_out);

        int operator<<(char *msg_in);
        int sendMessage(char *msg_in);
    
		bool isConnected( );
		//void setSock( const int& sock_in );
		size_t getSocket ( );
		void closeSocket();
        
        bool operator!=(Connection c_in);
		bool operator==(Connection c_in);
		
		bool operator<(const Connection c_in) const;
		Connection(size_t sock_in);
	private:
		
		Connection() { m_sock_fd = 0; };

		void initConstructor();

		int recvSocket( CppSocket::SocketMessage& msg_out );
		
		int recvSocket( std::string& msg_out );
		
		int Send(std::string msg_in);
		int Receive(std::string& msg_out);
            
	};
	
};


#endif