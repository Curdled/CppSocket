#include "SocketMonitorCallBackCounted.hpp"

using std::cout;
using std::endl;


namespace CppSocket
{
	SocketMonitorCallBackCounted::SocketMonitorCallBackCounted()
	{
		//all = new std::map<Connection, CountedDataParser>();
	}
	SocketMonitorCallBackCounted::~SocketMonitorCallBackCounted()
	{
		//delete all;
		//std::cout << "decon SocketMonitorCallBackCounted and all" << std::endl;
	}

	int SocketMonitorCallBackCounted::onAccpet(SocketMonitor*, Connection conn_in)
	{
		
		all.insert(std::pair<Connection, CountedDataParser>(conn_in, CountedDataParser()));
		//std::cout << "added connection: " << conn_in.getSocket() << std::endl;
		return 0;
	}

	int SocketMonitorCallBackCounted::onMessage(SocketMonitor* , Connection conn_in, std::string msg_in)
	{
		auto parser = all.at(conn_in);
		parser.appendCountedData(msg_in);
		if (parser.checkAllData())
		{
			//std::cout <<  << std::endl;
			conn_in.sendMessage(*parser.getDataPacket());
		}
		
		all.at(conn_in) = parser;
		return 0;
	}
	int SocketMonitorCallBackCounted::onRemove(SocketMonitor* , Connection conn_in)
	{
		all.erase(conn_in);
		return 0;
	}

};