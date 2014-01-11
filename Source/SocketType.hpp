#ifndef _SOCKET_TYPE_HPP_
#define _SOCKET_TYPE_HPP_

#include "SocketInclude.hpp"

namespace CppSocket
{
    class SocketType
    {
    public:
        enum SocketTypes
        {
            TCP_SOCK = SOCK_STREAM,
			UDP_SOCK = SOCK_DGRAM
        };
    };
}

#endif