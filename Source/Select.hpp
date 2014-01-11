#ifndef _SELECT_HPP_
#define _SELECT_HPP_

#include "Listener.hpp"
#include "SelectCallBack.hpp"
#include <vector>



namespace CppSocket
{
	class __DLL__ Select
	{
        
	private:
		fd_set m_read_fd, m_master_fd;
		size_t m_max_len; // for looping
		Listener m_listener;
        timeval m_time_out;

		std::vector<Connection> *m_conn_list;
		std::vector<Connection>::iterator *m_iter_conn_list;

		SelectCallBack *m_call_back;
	public:
		Select();
		Select(Listener list_in);
        void setCallBack(SelectCallBack *call_back_in);
		void update();
        
        void setSelectTimeOut(int mili_sec);
        
        void sendAll(SocketMessage msg_in,Connection except); // will send msg_in to all connection unless connection excpet is specified
        //void sendAll(SocketMessage msg_in,std::vector<Connection> except); // TODO same as above except list of conns to not send to

        void accpetSocket(Connection socket_in);
        void removeSocket(Connection socket_in);
	private:
		void initConstructor();
        
		void callSocketLoop();
        
        void removeSocket(std::vector<Connection>::iterator socket_iter_in);
	};
};

#endif