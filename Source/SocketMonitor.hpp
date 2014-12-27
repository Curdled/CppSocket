#ifndef _SOCKET_MONITOR_HPP_
#define _SOCKET_MONITOR_HPP_

#include "Listener.hpp"
#include "SocketMonitorImp.hpp"
#include "SocketMonitorCallBack.hpp"

namespace CppSocket
{
	class __DLL__ SocketMonitor
	{
	private:
		SocketMonitorImp* m_socket_monitor;
	public:
        SocketMonitor();
		SocketMonitor(SocketMonitorImp* socket_monitor_imp_in);
		~SocketMonitor();
		void setSocketMonitorImp(SocketMonitorImp *call_back_in);
		void checkUpdate();

		void setTimeOut(const int& mili_sec);

		void sendAll(SocketMessage* msg_in, Connection except); // will send msg_in to all connection unless connection excpet is specified
		//void sendAll(SocketMessage msg_in,std::vector<Connection> except); // TODO same as above except list of connections to not send to
		//bool virtual changeListener(const Listener& listener_in);
		bool addSocket(const Connection& socket_in);
		bool removeSocket(const Connection& socket_in);
	};
}

#endif
