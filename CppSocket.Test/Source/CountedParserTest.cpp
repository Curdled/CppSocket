#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN 
#endif

#include "CountedDataParser.hpp"

#include "catch.hpp"


std::string packIntToString(size_t number)
{
	std::string str_in;
	str_in.resize(4);
	str_in[0] = (number >> 24) & 0xFF;
	str_in[1] = (number >> 16) & 0xFF;
	str_in[2] = (number >> 8) & 0xFF;
	str_in[3] = number & 0xFF;
	return str_in;
}


TEST_CASE("Testing the CountedDataParser for interger between 0 and UINT32_MAX and in parts", "[CountedDataParser][setCountedData][appendCountedData]")
{
	CppSocket::CountedDataParser p;
	
	uint32_t len = 1;
	std::string str = packIntToString(htonl(len));
	p.setCountedData(&str);
	REQUIRE(p.getLength() == len);
	len = 0;
	str = packIntToString(htonl(len));
	p.setCountedData(&str);
	REQUIRE(p.getLength() == len);
	len = UINT32_MAX;
	str = packIntToString(htonl(len));
	p.setCountedData(&str);
	REQUIRE(p.getLength() == len);


	CppSocket::CountedDataParser par;
	uint32_t numbe = 23423432;
	uint32_t number = htonl(numbe);
	std::string str_in;
	str_in.resize(1);
	str_in[0] = (number >> 24) & 0xFF;
	par.appendCountedData(&str_in);
	REQUIRE(par.getLength() != numbe);
	str_in.clear();
	str_in.resize(1);
	str_in[0] = (number >> 16) & 0xFF;
	par.appendCountedData(&str_in);
	REQUIRE(par.getLength() != numbe);
	str_in.clear();
	str_in.resize(2);
	str_in[0] = (number >> 8) & 0xFF;
	str_in[1] = number & 0xFF;
	par.appendCountedData(&str_in);
	REQUIRE(par.getLength() == numbe);

	CppSocket::CountedDataParser pars;
	uint32_t nu = 8089089;
	uint32_t numb = htonl(nu);
	std::string str_ins;
	str_ins.resize(3);
	str_ins[0] = (numb >> 24) & 0xFF;
	str_ins[1] = (numb >> 16) & 0xFF;
	str_ins[2] = (numb >> 8) & 0xFF;
	pars.setCountedData(&str_ins);
	REQUIRE(pars.getLength() != nu);

	str_ins.clear();
	str_ins.resize(1);
	str_ins[0] = numb & 0xFF;
	pars.appendCountedData(&str_ins);
	REQUIRE(pars.getLength() == nu);


}
TEST_CASE("Testing the CountedDataParser for intergers with data", "[CountedDataParser][setCountedData]")
{
	CppSocket::CountedDataParser p;
	std::string data = "this is a test string";
	uint32_t len = data.length();
	std::string str = packIntToString(htonl(len));
	str.append(data);
	p.setCountedData(&str);
	REQUIRE(p.getLength() == len);
	REQUIRE(p.getRemaining() == 0);
	REQUIRE(*p.getDataPacket() == data);
	
	data = "this is VERY VERY LONG test string";
	data.append(std::string(100000, 'a'));
	len = data.length();
	str = packIntToString(htonl(len));
	str.append(data);
	p.setCountedData(&str);
	REQUIRE(p.getLength() == len);
	REQUIRE(p.getRemaining() == 0);
	REQUIRE(*p.getDataPacket() == data);
	



	std::string first, firstLen, second, secondLen, third, thirdLen, all;
	first = "this is a test string";
	firstLen = packIntToString(htonl(first.length()));
	second = "this is a second part of a test string";
	secondLen = packIntToString(htonl(second.length()));
	third = "this is a third part of a test string";
	thirdLen = packIntToString(htonl(third.length()));
	all.append(firstLen);
	all.append(first);
	all.append(secondLen);
	all.append(second);
	all.append(thirdLen);
	all.append(third);
	

	p.setCountedData(&all);
	
	REQUIRE(p.getLength() == first.length());
	REQUIRE(p.getRemaining() == 0);
	REQUIRE(p.checkAllData() == true);
	REQUIRE(*p.getDataPacket() == first);

	REQUIRE(p.getLength() == second.length());
	REQUIRE(p.getRemaining() == 0);
	REQUIRE(p.checkAllData() == true);
	REQUIRE(*p.getDataPacket() == second);

	REQUIRE(p.getLength() == third.length());
	REQUIRE(p.getRemaining() == 0);
	REQUIRE(p.checkAllData() == true);
	REQUIRE(*p.getDataPacket() == third);

}
TEST_CASE("Testing the CountedDataParser for intergers with data in parts", "[CountedDataParser][setCountedData]")
{
	CppSocket::CountedDataParser p;
	std::string first, firstLen, second, total;
	first = "this is a test string";
	second = " with i final part.";
	uint32_t totalLen = first.length() + second.length();
	firstLen = packIntToString(htonl(totalLen));
	total.append(firstLen);
	total.append(first);
	//total.append(second);
	p.appendCountedData(&total);
	REQUIRE(p.getLength() == totalLen);
	REQUIRE(p.getRemaining() != 0);
	REQUIRE(p.checkAllData() == false);

	p.appendCountedData(&second);
	REQUIRE(p.getLength() == totalLen);
	REQUIRE(p.getRemaining() == 0);
	REQUIRE(p.checkAllData() == true);
	REQUIRE(*p.getDataPacket() == std::string(first + second));
}