#ifndef _SDFSDFSDFSD_SDFF
#define _SDFSDFSDFSD_SDFF

#include "MessageParser.hpp"
#include "SelectCallBack.hpp"
#include "SocketInclude.hpp"

#include "map"

namespace CppSocket
{
	class __DLL__ SelectCallBackOne : public SelectCallBack
	{
	private:
		std::map<size_t, std::string> *m_username_list; 
	public:
		SelectCallBackOne(Select* select_in);

		int onAccpet(Connection conn_in);
		int onMessage(SocketMessage msg_in, Connection conn_in);
		int onRemove(Connection conn_in);
	};
};

#endif