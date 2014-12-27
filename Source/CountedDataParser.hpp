#ifndef _COUNTED_DATA_PARSER_HPP_
#define _COUNTED_DATA_PARSER_HPP_

#include "SocketInclude.hpp"
#include <string>
#include <cstdint>


namespace CppSocket
{
	class  CountedDataParser
	{
	public:
		__DLL__ CountedDataParser();
		__DLL__ CountedDataParser(std::string *data_in);
		__DLL__ CountedDataParser(char *data_in, size_t len);
		
		void __DLL__ setCountedData(std::string *data_in);
		void __DLL__ appendCountedData(std::string *data_appended);
		void __DLL__ appendCountedData(std::string data_appended);
		uint32_t __DLL__ getLength();
		uint32_t __DLL__ getRemaining();
		std::string __DLL__ *getData();
		std::string __DLL__ *getDataPacket();
			bool __DLL__ checkAllData();
	private:
		void getLengthFromCount();

		std::string m_data;
		uint32_t m_length;
	};
};


#endif 