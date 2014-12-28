#include "SocketMonitorCallBackCounted.hpp"




namespace CppSocket
{
	int SocketMonitorCallBackCounted::onAccpet(SocketMonitor*, Connection conn_in)
	{
		all.insert(std::pair<Connection, CountedDataParser>(conn_in, CountedDataParser()));
		return 0;
	}

	int SocketMonitorCallBackCounted::onMessage(SocketMonitor* , Connection conn_in, std::string msg_in)
	{
		auto parser = all.at(conn_in);
		parser.appendCountedData(msg_in);
		if (parser.checkAllData())
			conn_in.sendMessage(*parser.getDataPacket());
		
		all.at(conn_in) = parser;
		return 0;
	}
	int SocketMonitorCallBackCounted::onRemove(SocketMonitor* , Connection conn_in)
	{
		all.erase(conn_in);
		return 0;
	}

};