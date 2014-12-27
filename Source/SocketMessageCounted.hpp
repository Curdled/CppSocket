#ifndef _SOCKET_MESSAGE_COUNTED_HPP_
#define _SOCKET_MESSAGE_COUNTED_HPP_

#include "SocketMessage.hpp"
#include "stdint.h"

namespace CppSocket
{
	class __DLL__ SocketMessageCounted
	{
	private:

		size_t m_length_to_come;
		SocketMessage m_msg;

	public:
		SocketMessageCounted();
		size_t getRemaining();
		size_t getLengthRem();
		bool isEmpty(); // when length_to_come not set or 0;
		bool isFull(); //when all data has arrived;
		SocketMessage Empty();
		size_t appendString(SocketMessage* msg_in);
		size_t appendString(std::string* str_in);
		size_t appendString(std::string str_in);
		SocketMessage getSocketMessage();

		void setRemaining(uint32_t size_in);
		void setRemaining(size_t size_in);
	private:
		uint32_t getLengthFromString(SocketMessage msg_in);

	};
}
#endif