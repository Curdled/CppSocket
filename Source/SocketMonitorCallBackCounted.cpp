#include "SocketMonitorCallBackCounted.hpp"




namespace CppSocket
{
	int SocketMonitorCallBackCounted::onAccpet(SocketMonitor*, Connection conn_in)
	{
        //This is overriding the onAccept Command and will add the new commection the list of all connections (all).
		all.insert(std::pair<Connection, CountedDataParser>(conn_in, CountedDataParser()));
		return 0;
	}

	int SocketMonitorCallBackCounted::onMessage(SocketMonitor* , Connection conn_in, std::string msg_in)
	{
        //This will override the onMessage in SocketMonitorCallBack.
		auto parser = all.at(conn_in);
		parser.appendCountedData(msg_in);
		if (parser.checkAllData())
			conn_in.sendMessage(*parser.getDataPacket());
		
		all.at(conn_in) = parser;
		return 0;
	}
	int SocketMonitorCallBackCounted::onRemove(SocketMonitor* , Connection conn_in)
	{
        //this will remove the element from the list the SocketMonitor will handle closing the connection and cleaning up.
		all.erase(conn_in);
		return 0;
	}

};