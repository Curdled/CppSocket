#include "CountedDataParser.hpp"
#include <iostream>


namespace CppSocket
{
	CountedDataParser::CountedDataParser()
		:m_length(0)
	{
		m_data = std::string();
	}
	CountedDataParser::CountedDataParser(std::string *data_in)
		: m_length(0)
	{
		m_data = std::string(*data_in);
	}
	CountedDataParser::CountedDataParser(char *data_in, size_t len)
		: m_length(0)
	{
		m_data = std::string(data_in, len);
	}

	void CountedDataParser::setCountedData(std::string *data_in)
	{		
		m_length = 0;
		if (data_in->length() >= 4)
		{
			m_data = std::string(*data_in);
			getLengthFromCount();
			m_data = m_data.substr(4);
		}
		else
		{
			m_data = std::string(*data_in);
		}

	}
	void CountedDataParser::appendCountedData(std::string *data_appended)
	{
		if (m_length == 0)
		{
			if (m_data.length() == 0)
			{
				if (data_appended->length() >= 4)
				{
					m_data = std::string(*data_appended);
					getLengthFromCount();
					m_data = m_data.substr(4);
				}
				else
					m_data = std::string(*data_appended);
			}
			else
			{
				m_data.append(*data_appended);
				if (m_data.length() >= 4)
				{
					getLengthFromCount();
					m_data = m_data.substr(4);
				}
			}

		}
		else
			m_data.append(*data_appended);
	}
	void CountedDataParser::appendCountedData(std::string data_appended)
	{
        appendCountedData(&data_appended);
	}

	void CountedDataParser::getLengthFromCount()
	{
        //This will check the first char in the string and find the length of the this
        //Then this will be converted to the host length and used in the parser.
		if (m_length == 0 && m_data.length() >= 4)
		{
			m_length = (m_data[3] & 0xFF)
				+ ((m_data[2] & 0xFF) << 8)
				+ ((m_data[1] & 0xFF) << 16)
				+ ((m_data[0] & 0xFF) << 24);
			m_length = ntohl(m_length);
		}
	}


	uint32_t CountedDataParser::getLength()
	{
		return m_length;
	}

	uint32_t CountedDataParser::getRemaining()
	{
        //return the remaining data that must be recieve in this counted pack send from the client
        //This is specified the first time that the parser recieve data when m_length is 0 and the
        //parser is in the state where no data has been recieve of this packet.
		uint32_t remaining =  m_length - static_cast<uint32_t>(m_data.length());
		return m_length >= m_data.length() ? remaining : 0;
	}
	bool CountedDataParser::checkAllData()
	{
        //checks to see if all the data of the first packet in the data block has been completly trasnfered.
		return m_length <= m_data.length() ? true : false;
	}
	std::string * CountedDataParser::getData()
	{
		return new std::string(m_data);
	}

	std::string * CountedDataParser::getDataPacket()
	{
		if (checkAllData())
		{
			std::string *returnValue = new std::string(m_data, 0, m_length);
			if (m_data.length() > m_length)
			{
				m_data = m_data.substr(m_length );
				m_length = 0;
				if (m_data.length() > 4)
				{
					getLengthFromCount();
					m_data = m_data.substr(4);
				}
			}
			return returnValue;
		}
		else
		{
			return new std::string();
		}
	}


}