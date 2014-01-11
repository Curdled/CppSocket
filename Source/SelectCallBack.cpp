#include "SelectCallBack.hpp"
#include "Select.hpp"

namespace CppSocket
{
    SelectCallBack::SelectCallBack(Select* select_in)
    {
        m_select = select_in;
    }
    int SelectCallBack::onAccpet(Connection conn_in)
    {
        return 0;
    }
    int SelectCallBack::onMessage(SocketMessage msg_in, Connection conn_in)
    {
        return 0;
    }
    int SelectCallBack::onRemove(Connection conn_in)
    {
        return 0;
    }
}
        