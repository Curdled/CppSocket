#ifndef _SOCKET_MONITOR_IMP_HPP_
#define _SOCKET_MONITOR_IMP_HPP_

#include "Listener.hpp"
#include "SocketMonitorCallBack.hpp"

namespace CppSocket
{
	class SocketMonitor;
	class __DLL__ SocketMonitorImp
	{
	protected:
		SocketMonitor* m_socket_monitor;
	public:
		void setSocketMonitorPointer(SocketMonitor *socket_monitor_in){ m_socket_monitor = socket_monitor_in; };
		virtual ~SocketMonitorImp(){ std::cout << "calling  ~SocketMonitorImp" << std::endl; };
        
		void virtual checkUpdate() = 0;

		void virtual setTimeOut(const int& mili_sec) = 0;

		void virtual sendAll(SocketMessage* msg_in, Connection except) = 0; // will send msg_in to all connection unless connection excpet is specified
		//void sendAll(SocketMessage msg_in,std::vector<Connection> except); // TODO same as above except list of conns to not send to
		//bool virtual changeListener(const Listener& listener_in) override;
		bool virtual addSocket(Connection socket_in) = 0;
		bool virtual removeSocket(Connection socket_in) = 0;
	};
}

#endif