#include "Select.hpp"
#include "SelectCallBack.hpp"

namespace CppSocket
{
	Select::Select()
	{
		initConstructor();
	}
	Select::Select(Listener list_in)
	{
		m_listener = list_in;
		m_max_len = m_listener.getSocket();
		initConstructor();
	}

	void Select::initConstructor()
	{
        m_call_back = new SelectCallBack(NULL);
		m_conn_list = new std::vector<Connection>();
		FD_ZERO(&m_master_fd);
		FD_ZERO(&m_read_fd);
		FD_SET(m_listener.getSocket(), &m_master_fd);
        
        m_time_out.tv_sec = 0;
        m_time_out.tv_usec = 100;
	}
    
    void Select::setCallBack(SelectCallBack* call_back_in)
    {
        delete m_call_back;
        m_call_back = call_back_in;
    }

	void Select::update()
	{
		callSocketLoop();
	}
    
    void Select::setSelectTimeOut(int mili_sec)
    {
        int seconds = 0;
        while(mili_sec >= 1000)
        {
            mili_sec -= 1000;
            seconds++;
        }
        m_time_out.tv_sec = seconds;
        m_time_out.tv_usec = mili_sec%1000;
#ifdef _DEBUG
        std::cout << std::endl << "tv_sec: " << m_time_out.tv_sec << " t.tv_usec: " << m_time_out.tv_usec;
#endif
    }

    void Select::sendAll(SocketMessage msg_in, Connection except)
    {
        if(!m_conn_list->empty())
        {   
        for (auto iter = m_conn_list->begin(); iter != m_conn_list->end(); iter++)
            if(*iter != except)
                iter->sendMessage(msg_in);
        }
//            
        
    }
    
    
	void Select::callSocketLoop()
	{	
        m_read_fd = m_master_fd;
        timeval t;
        t = m_time_out;
        if (select(static_cast<int> (m_max_len+1), &m_read_fd, NULL, NULL, &t) == -1) 
        {
    #ifdef _DEBUG
            std::cout << "select: " << errno << std::endl;
    #endif
            return;
        }
       // std::cout << "past select" << std::endl;
        if (FD_ISSET(m_listener.getSocket(), &m_read_fd)) 
        {
           // std::cout << "past FD_ISSET 1" << std::endl;
            Connection tmp = m_listener.getConnection();

            if (static_cast<int>(tmp.getSocket()) > -1) 
            {
                m_call_back->onAccpet(tmp);
                accpetSocket(tmp);
            }
        }
        if(!m_conn_list->empty())
        {
            for (m_iter_conn_list = new std::vector<Connection>::iterator(m_conn_list->begin()); (*m_iter_conn_list) != m_conn_list->end(); (*m_iter_conn_list)++) 
            {
              //  std::cout << "past for" << std::endl;
                CppSocket::SocketMessage msg;
                if (FD_ISSET((*m_iter_conn_list)->getSocket(), &m_read_fd))
                {
                   // std::cout << "past FD_ISSET 2" << std::endl;
                    if ((*m_iter_conn_list)->recvMessage(msg) == 0)
                    {          
                        m_call_back->onRemove(**m_iter_conn_list);
                        removeSocket(*m_iter_conn_list);
                        break;
                    }
                    if (msg.getLen() > 0)
                    {
                        m_call_back->onMessage(msg, **m_iter_conn_list);
                    }
                }
               // std::cout << "left for" << std::endl;
            }
        }
        return;
	}
    
    void Select::accpetSocket(Connection socket_in)
    {
        FD_SET(socket_in.getSocket(), &m_master_fd);
        
        m_conn_list->push_back(socket_in);
        if (socket_in.getSocket() > m_max_len)
        {
            m_max_len = socket_in.getSocket();
        }
        m_iter_conn_list = new std::vector<Connection>::iterator(m_conn_list->begin());
    }
    
    void Select::removeSocket(Connection socket_in)
    {
        ;//for(auto iter = m_conn_list->start  // TODO: create and finish this
    }
    
    void Select::removeSocket(std::vector<Connection>::iterator socket_iter_in)
    {
        
        FD_CLR(socket_iter_in->getSocket(), &m_master_fd);
        socket_iter_in->closeSocket();
        m_conn_list->erase(socket_iter_in);
        
        m_iter_conn_list = new std::vector<Connection>::iterator(m_conn_list->begin());
    }
}
