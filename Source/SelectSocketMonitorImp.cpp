#include "SelectSocketMonitorImp.hpp"
#include "SocketMonitorCallBack.hpp"

namespace CppSocket
{
	SelectSocketMonitorImp::SelectSocketMonitorImp(SocketMonitorCallBack *call_back_in)
	{
		m_call_back = call_back_in;
		initConstructor();
	}
	SelectSocketMonitorImp::SelectSocketMonitorImp(SocketMonitorCallBack *call_back_in, Listener list_in)
	{
		m_call_back = call_back_in;
		m_listener = list_in;
		m_max_len = m_listener.getSocket();
		initConstructor();
	}
	SelectSocketMonitorImp::~SelectSocketMonitorImp()
	{
		m_listener.closeSocket();
		delete m_conn_list;
		delete m_iter_conn_list;
		delete m_call_back;
		
	}

	void SelectSocketMonitorImp::initConstructor()
	{
      //  m_call_back = new SelectSocketMonitorImpCallBack(NULL);
		m_conn_list = new std::vector<Connection>();
		FD_ZERO(&m_master_fd);
		FD_ZERO(&m_read_fd);
		FD_SET(m_listener.getSocket(), &m_master_fd);
        
        m_time_out.tv_sec = 0;
        m_time_out.tv_usec = 100;
	}
    


	void SelectSocketMonitorImp::checkUpdate()
	{
		callSocketLoop();
	}
    
	void SelectSocketMonitorImp::setTimeOut(const int& mili_sec)//sets the time out before the function will return when callSocketLoop() is run.
    {

		m_time_out.tv_sec = ((mili_sec - (mili_sec % 1000)) / 1000);
        m_time_out.tv_usec = mili_sec%1000;
#ifdef _DEBUG
        std::cerr << std::endl << "tv_sec: " << m_time_out.tv_sec << " t.tv_usec: " << m_time_out.tv_usec;
#endif
    }

    void SelectSocketMonitorImp::sendAll(SocketMessage* msg_in, Connection except)
    {
        if(!m_conn_list->empty())
        {   
        for (auto iter = m_conn_list->begin(); iter != m_conn_list->end(); iter++)
            if(iter->getSocket() != except.getSocket())
                iter->sendMessage(*msg_in);
        }
//            
        
    }
    
    
	void SelectSocketMonitorImp::callSocketLoop()
	{	
        m_read_fd = m_master_fd;
        timeval t;
        t = m_time_out;
        if (select(static_cast<int> (m_max_len+1), &m_read_fd, NULL, NULL, &t) == -1) 
        {
    #ifdef _DEBUG
            std::cerr << "select: " << errno << std::endl;
    #endif
            return;
        }
        if (FD_ISSET(m_listener.getSocket(), &m_read_fd)) 
        {
            Connection tmp = m_listener.getConnection();

            if (static_cast<int>(tmp.getSocket()) > -1) 
            {
				m_call_back->onAccpet(m_socket_monitor, tmp);
                addSocket(tmp);
            }
        }
        if(!m_conn_list->empty())
        {
            for (m_iter_conn_list = new std::vector<Connection>::iterator(m_conn_list->begin()); (*m_iter_conn_list) != m_conn_list->end(); (*m_iter_conn_list)++) 
            {
                std::string msg;
                if (FD_ISSET((*m_iter_conn_list)->getSocket(), &m_read_fd))
                {
                    if ((*m_iter_conn_list)->recvMessage(msg) == 0)
                    {          
						m_call_back->onRemove(m_socket_monitor, **m_iter_conn_list);
                        removeSocket(*m_iter_conn_list);
                        break;
                    }
                    if (msg.length() > 0)
                    {
						m_call_back->onMessage(m_socket_monitor, **m_iter_conn_list, msg);
                    }
                }
            }
        }
        return;
	}
    
    bool SelectSocketMonitorImp::addSocket(Connection socket_in)
    {
		FD_SET(socket_in.getSocket(), &m_master_fd);
        
		m_conn_list->push_back(socket_in);
		if (socket_in.getSocket() > m_max_len)
        {
			m_max_len = socket_in.getSocket();
        }
        m_iter_conn_list = new std::vector<Connection>::iterator(m_conn_list->begin());
		return true;
    }
    
    bool SelectSocketMonitorImp::removeSocket(Connection socket_in)
    {
        return true;// TODO: create and finish this
    }
    
    void SelectSocketMonitorImp::removeSocket(std::vector<Connection>::iterator socket_iter_in)
    {
        
        FD_CLR(socket_iter_in->getSocket(), &m_master_fd);
        socket_iter_in->closeSocket();
        m_conn_list->erase(socket_iter_in);
        
        m_iter_conn_list = new std::vector<Connection>::iterator(m_conn_list->begin());
    }
}
