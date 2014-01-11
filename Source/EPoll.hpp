#ifndef _EPOLL_HPP_
#define _EPOLL_HPP_

#include "Listener.hpp"
#include "SocketInclude.hpp"
#include <errno.h>

#ifdef CPP_EPOLL

namespace CppSocket
{
    class __DLL__ EPoll
    {
    private:
        struct epoll_event m_event, *m_events;
        
        int m_ep_fd;
        
        Listener m_listener;
    public:
        
        
        EPoll(Listener list_in);
        ~EPoll();
        int init();
        int check();
        
        static const int MAX_EVENTS = 1024;
    private:
        
        int makeNoneBlockingSocket(int s_td);
       
        
    };
}
#endif

#endif