#include "SocketMonitor.hpp"


namespace CppSocket
{
    SocketMonitor::SocketMonitor()
    {
        m_socket_monitor = NULL;
    }
	SocketMonitor::SocketMonitor(SocketMonitorImp* socket_monitor_imp_in)
	{
		setSocketMonitorImp(socket_monitor_imp_in);
    }
    
	void SocketMonitor::setSocketMonitorImp(SocketMonitorImp *call_back_in)
    {
        m_socket_monitor = call_back_in;
		//m_socket_monitor->setSocketMonitorPointer(this);
    }
	SocketMonitor::~SocketMonitor()
	{
		delete m_socket_monitor;
	}
	void SocketMonitor::checkUpdate()
	{
		m_socket_monitor->checkUpdate();
	}

	void SocketMonitor::setTimeOut(const int& mili_sec)
	{
		m_socket_monitor->setTimeOut(mili_sec);
	}

	void SocketMonitor::sendAll(SocketMessage* msg_in, Connection except)
	{
		m_socket_monitor->sendAll(msg_in, except);
	}
	//void sendAll(SocketMessage msg_in,std::vector<Connection> except); // TODO same as above except list of conns to not send to
	//bool changeListener(const Listener& listener_in);
	bool SocketMonitor::addSocket(const Connection& socket_in)
	{
		return m_socket_monitor->addSocket(socket_in);
	}
	bool SocketMonitor::removeSocket(const Connection& socket_in)
	{
		return m_socket_monitor->removeSocket(socket_in);
	}
}