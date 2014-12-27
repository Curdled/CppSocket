#ifndef _SOCKET_MONITOR_CALLBACK_COUNTED_HPP_
#define _SOCKET_MONITOR_CALLBACK_COUNTED_HPP_

#include "SocketMonitorCallBack.hpp"

#include "Connection.hpp"
#include "CountedDataParser.hpp"
#include <map>


namespace CppSocket
{
	class SocketMonitor;
	
	class  SocketMonitorCallBackCounted : public SocketMonitorCallBack
	{
	protected:
		std::map<Connection, CountedDataParser> all;
	public:
		__DLL__ SocketMonitorCallBackCounted();
		__DLL__ ~SocketMonitorCallBackCounted();
		virtual int onAccpet(SocketMonitor* monitor_in, Connection conn_in) override;
		virtual int onMessage(SocketMonitor* monitor_in, Connection conn_in, std::string msg_in) override;
		virtual int onRemove(SocketMonitor* monitor_in, Connection conn_in) override;
	private:
		
	};
};


#endif