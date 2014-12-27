#ifndef _SOCKET_MONITOR_CALL_BACK_HPP_
#define _SOCKET_MONITOR_CALL_BACK_HPP_

#include "Connection.hpp"





namespace CppSocket
{    
	class SocketMonitor;
    
	class SocketMonitorCallBack
	{
    protected:
        
	public:
		__DLL__ SocketMonitorCallBack();
		virtual __DLL__ ~SocketMonitorCallBack();
		virtual int onAccpet(SocketMonitor* monitor_in, Connection conn_in);
		virtual int onMessage(SocketMonitor* monitor_in, Connection conn_in, std::string msg_in);
		virtual int onRemove(SocketMonitor* monitor_in, Connection conn_in);
	};
};

#endif 