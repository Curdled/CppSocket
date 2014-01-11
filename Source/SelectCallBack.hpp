#ifndef _SELECT_CALL_BACK_HPP_
#define _SELECT_CALL_BACK_HPP_

#include "Connection.hpp"





namespace CppSocket
{    
    class Select;
    
	class __DLL__ SelectCallBack
	{
    protected:
        Select *m_select;
	public:
        SelectCallBack(Select *select_in);
        
		virtual int onAccpet(Connection conn_in);
		virtual int onMessage(SocketMessage msg_in, Connection conn_in);
		virtual int onRemove(Connection conn_in);
	};
};

#endif 