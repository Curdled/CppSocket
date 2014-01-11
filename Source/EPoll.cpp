#include "EPoll.hpp"

#ifdef _DEBUG
#include <iostream>
#endif

#ifdef CPP_EPOLL

namespace CppSocket
{
    EPoll::EPoll(Listener list_in)
    {
        m_listener = list_in;
    }
    EPoll::~EPoll()
    {
        close(m_ep_fd);
        if(m_events)
            free(m_events);
    }
    
    int EPoll::init()
    {
        m_ep_fd = epoll_create1(0);
        if(m_ep_fd == -1)
            return -1; 
        
        m_event.data.fd = m_listener.getSocket();
        m_event.events = EPOLLIN | EPOLLET;
        
        if(epoll_ctl(m_ep_fd, EPOLL_CTL_ADD, m_listener.getSocket(), &m_event))
        {
#ifdef _DEBUG
            std::cout << "epoll_ctl" << std::endl;
#endif
            return -1;
        }   
        return 0;
    }

    int EPoll::makeNoneBlockingSocket (int s_fd)
    {
        int flags, s;

        flags = fcntl (s_fd, F_GETFL, 0);
        if (flags == -1)
        {
            perror ("fcntl");
            return -1;
        }
        s = fcntl (s_fd, F_SETFL, flags |= O_NONBLOCK);
        if (s == -1)
        {
            perror ("fcntl");
            return -1;
        }
        return 0;
    }
    
    int EPoll::check()
    {
        int number_socket_to_check;
        number_socket_to_check = epoll_wait(m_ep_fd, m_events, MAX_EVENTS, 10);
        for(int i = 0; i != number_socket_to_check; i++)
        {
            if((m_events[i].events & EPOLLERR) || (m_events[i].events & EPOLLHUP) || (!(m_events[i].events & EPOLLIN)))
            {
            #ifdef _DEBUG
                std::cout << "epoll_ctl" << std::endl;
            #endif   
                close(m_events[i].data.fd);
                continue;
            }
            else if (m_listener.getSocket() == m_events[i].data.fd)
            {
                size_t new_socket_fd = m_listener.getConnection().getSocket();
                if(new_socket_fd == -1)
                {
                    if(errno == EAGAIN || EWOULDBLOCK)
                        break;
                    else
                    {
                        #ifdef _DEBUG
                            std::cout << "accept error" << std::endl;
                        #endif   
                        break;
                    }
                }
            
            }
        }
        return 0;
    }
    

}
#endif