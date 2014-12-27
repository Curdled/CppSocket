#ifndef _SELECT_SOCKET_MONITOR_IMP_HPP_
#define _SELECT_SOCKET_MONITOR_IMP_HPP_


#include "SocketMonitorImp.hpp"
#include <vector>




namespace CppSocket
{
	class __DLL__ SelectSocketMonitorImp : public SocketMonitorImp
	{
        
	private:
		fd_set m_read_fd, m_master_fd;
		size_t m_max_len; // for looping
		Listener m_listener;
        timeval m_time_out;

		std::vector<Connection> *m_conn_list;
		std::vector<Connection>::iterator *m_iter_conn_list;

		SocketMonitorCallBack *m_call_back;
	public:
		SelectSocketMonitorImp(SocketMonitorCallBack *call_back_in);
		SelectSocketMonitorImp(SocketMonitorCallBack *call_back_in, Listener list_in);
		virtual ~SelectSocketMonitorImp();
		//void setCallBack(SocketMonitorCallBack *call_back_in);
		void virtual checkUpdate() override;
        
        void virtual setTimeOut(const int& mili_sec) override;
        
		void virtual sendAll(SocketMessage* msg_in, Connection except) override; // will send msg_in to all connection unless connection excpet is specified
        //void sendAll(SocketMessage msg_in,std::vector<Connection> except); // TODO same as above except list of conns to not send to
		//bool virtual changeListener(const Listener& listener_in) override;
		bool virtual addSocket(Connection socket_in) override;
		bool virtual removeSocket(Connection socket_in) override;
	private:
		void initConstructor();
        
		void callSocketLoop();
        
        void removeSocket(std::vector<Connection>::iterator socket_iter_in);
	};
};

#endif