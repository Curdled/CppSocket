///////////////////////////////////////////////////////////
//  Connection.hpp
//  Original author: Joe
///////////////////////////////////////////////////////////
#ifndef _CONNECTION_HPP_
#define _CONNECTION_HPP_



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
	private:
		

		size_t m_sock_fd;

		

	public:
		//friends
		friend class ClientConnectionFactory;
		friend class Listener;
		//friend Connection* __cdecl Connection_Constructor(size_t sock_in);

		~Connection();
		//Receive
		int operator>>(std::string &msg_out );
		int recvMessage(std::string &msg_out);
		int operator>> (CppSocket::SocketMessage &msg_out );
		int recvMessage(CppSocket::SocketMessage &msg_out);
		
		//Send
		int operator<<(std::string &msg_in );
		int sendMessage(std::string &msg_in);
		int operator<< (CppSocket::SocketMessage &msg_in);
		int sendMessage(CppSocket::SocketMessage &msg_in);
        int operator<<(char *msg_in);
        int sendMessage(char *msg_in);
    
		bool checkConn( );
		//void setSock( const int& sock_in );
		size_t getSocket ( );
		void closeSocket();
        
        bool operator!=(Connection c_in);
	private:
		Connection( size_t sock_in );

		void initConstructor();

		int recvSocket( CppSocket::SocketMessage& msg_out );
		
		int recvSocket( std::string& msg_out );
		
		int Send(std::string msg_in);
		int Receive(std::string& msg_out);
            
	};
};


#endif