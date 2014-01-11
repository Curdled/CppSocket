#ifndef _SOCKET_INCLUDE_HPP_
#define _SOCKET_INCLUDE_HPP_



#ifdef _WIN32
#define CPP_WINSOCK 
#define CPP_IOCP

#elif __linux__
#define CPP_EPOLL
#define POSIX_

#elif __APPLE__
#define CPP_KQUEUE
#define POSIX_
#endif


#ifdef CPP_WINSOCK
#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment (lib, "ws2_32.lib")
inline int close(SOCKET a)
{
	return closesocket(a);
}
#endif
#ifdef POSIX_
typedef int  SOCKET;
#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#endif

#ifdef CPP_EPOLL
#include <sys/epoll.h>

#elif __APPLE__
#include <sys/event.h>
#endif


#include "DLL_Func.hpp"
#include "StringFunction.hpp"



#endif