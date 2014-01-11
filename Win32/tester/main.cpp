////
////
////#include "ClientConnectionFactory.hpp"
////#include "HttpClientHeader.hpp"
////#include "HttpServerHeader.hpp"
////#include "DLL_Func.hpp"
////#include <iostream>
////using namespace CppSocket::HTTP;
////using namespace CppSocket;
////using namespace std;
////int
////main()
////{
////	u_long iMode = 1;
////	std::string host = "www.google.co.uk";
////	HttpClientHeader h(HttpVersionType::HTTP_1_1);
////	h.setUserAgent("CppHTTP/0.0.1");
////	h.setRequestType(HttpRequestType::GET);
////	h.setConnection("close");
////	h.setWhoFrom("joe.isaacs@live.co.uk");
////	h.setContentType(HttpContentType::HttpContentTypes::CSS);
////	h.getHost(host);
////	
////	
////	CppSocket::SocketMessage msgs;
////	ClientConnectionFactory *s =  new ClientConnectionFactory(host, "80", CppSocket::SocketType::TCP_SOCK);
////	h.setHost(s->getHost());
////	CppSocket::SocketMessage msg= h.getSocketMessage();
////    Connection conn = s->getConnection();
////	std::cout << msg.getMessage() << std::endl;
////	conn.sendMessage(msg);
////	Sleep(1000);
////
////	for(int i = 0; i != 10; i++)
////	{
////	conn.recvMessage(msg);
////	std::cout << msg.getMessage();
////	}
////	std::string strstmp = msg.getMessage();
////	auto iter = strstmp.end();
////	iter -= 4;
////	std::string strs;
////	strs.assign(iter, strstmp.end());
////	for(auto i: strs)
////		std::cout << (int)i << std::endl;
////	if(strs== std::string("\r\n\r\n"))
////		std::cout << "woot";
////
////	HttpServerHeader h(HttpVersionType::HTTP_1_1);
////	h.setContentLength("100");
////	h.setContentType(HttpContentType::JAVASCRIPT);
////	h.setLocation("www.joe.com");
////	h.setStatus(HttpStatusType::OK);
////	h.setServer("JOESERVER/0.0.1");
////	cout << h.getSocketMessage().getMessage();
////	system("PAUSE");
////	return 0;
////}
////
////
////
////
////
////#include "ClientConnectionFactory.hpp"
////
////#include "MessageParser.hpp"
////#include "ServerConnectionFactory.hpp"
////#include "SocketIOServerAsync.hpp"
////#include <iostream>
////#include <regex>
////#include <map>
////
////#include "SocketIOThread.hpp"
////using namespace CppSocket::Protocol;
////using namespace CppSocket;
////using namespace std;
////
////<CONN>User:Joe|Pass:Isaacs;
////void connect(Connection conn_in);
////
////int
////main()
////{
////
////	/*string st("<CONN>joe;"), user, pass;
////	std::cout << "username: ";
////	cin >> user;
////	user = std::string("<CONN>") + user;
////
////	ClientConnectionFactory *s =  new ClientConnectionFactory("192.168.1.124", "6000", CppSocket::SocketType::TCP_SOCK);
////	Connection *conn = new Connection(s->getConnection());
////	conn->sendMessage(user);
////	while(1)
////	{
////		getline(cin, pass);
////		conn->sendMessage("<MSG>"+pass+";\n");
////	}*/
////
////	/*if( (char)13 == '\r')
////		std::cout << "char(10) == '\\r'" << std::endl;
////	else 
////		std::cout << (int)'\r' << std::endl;
////	if( (char)10 == '\n')
////		std::cout << "char(13) == '\\n'" << std::endl;
////*/
////	std::cout << "hello, world \r\nHow are we all" << std::endl;
////	system("PAUSE");
////	return 0;
////};
////
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int
//main()
//{
//
//	
//	string httpHeader = std::string("POST / HTTP/1.0 \r\n  Content-Length: 789\r\nUSER: 1323\r\n\r\n");
//	//cout << httpHeader;
//	
//	vector<string> str; 
//	//for(string::iterator i = httpHeader.begin(); i != httpHeader.end(); i++)
//	//{	
//	//	//cout << (int)*i << endl;
//	//	if((int)*i == 13)
//	//		httpHeader.erase(i);
//	//	if((int)*i == 10)
//	//	{
//	//		str.push_back(string(httpHeader.begin(), i));
//	//		if(i+1 == httpHeader.end())
//	//			break;
//	//		httpHeader = string((i+1), (httpHeader.end()));
//	//		i = httpHeader.begin();
//	//	}
//	//}
//	////cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << "sz: " << str.size() << endl;
//	////if(*(str.end()-1) == std::string("\r"))
//	////	str.pop_back();
//	//cout << str.size() << endl;
//	//for(vector<string>::iterator i = str.begin(); i != str.end(); i++)
//	//{
//	//	//for(string::iterator j = i->begin(); j != i->end(); j++)
//	//				cout << ":" << *i << ":" <<  endl;
//	//	cout << "\n------\n";
//	//}
//	/*for(vector<string>::iterator i = str.begin(); i != str.end(); i++)
//	{
//		if((int)*(i->begin()) == 13 || (int)*(i->begin()) == 10)
//
//	}*/
//	//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
//	//for(vector<string>::iterator i = str.begin(); i != str.end(); i++)
//	//{
//	//	for(string::iterator j = i->begin(); j != i->end(); j++)
//	//				if((int)*j == 13 || 10)
//	//					str.assign(
//	//}
//	std::string *m_http_buffer = &httpHeader;
//	vector<string> *m_header_split = new std::vector<string>(); 
//			int begin = 0, current = 0, tmp = 0;
//		bool inWord = false;
//		for(std::string::iterator i = m_http_buffer->begin(); i != m_http_buffer->end(); i++, current++)//, j++)
//		{
//			//cout << "inWord: " << inWord << " word: " << (int)*i << " current: " << current << endl;
//			if(!inWord && ((int)*i - 32 > 0) )
//			{
//				inWord = true;
//				begin = current;
//				//cout << "begin: " << begin << endl;
//				//j ==0;
//			}
//			else if((int)*i == 10)
//			{
//			
//				if(current > 0)
//				{
//					if((int)(*m_http_buffer)[current-1] == 13)
//						tmp = current-2;
//				tmp = current-1 - begin;
//				m_header_split->push_back(std::string(*m_http_buffer, begin, tmp));
//				inWord = false;
//				begin = current;
//				}
//			}
//		}
//	for(vector<string>::iterator i = m_header_split->begin(); i != m_header_split->end(); i++)
//	{
//		
//
//		cout << "\n------\n";
//		//for(string::iterator j = i->begin(); j != i->end(); j++)
//			cout << ":|:" << *i << ":|:" <<  endl;
//		//cout << *i << endl;
//		cout << "\n------\n";
//	}
//
//
//
//
//	system("PAUSE");
//}
	//smatch mch;
	//regex regMatch("[^]*((?=\r\n\r\n)|\n(?=\n))", regex::ECMAScript);
	//string getReq = "GET / HTTP/1.1\r\nLength: 123\r\nConnection: closed\r\n\r\n  sdfgsdgsdgsdgdsgdgsdgsdf\r\n\r\n";
	//regex_search(getReq, mch, regMatch);
	//for( auto x : mch)
	//{
	//std::string tmp = x.str();
	//	
	////for(int i = 0; i != tmp.length(); i++)
	//for(auto y : tmp)
	//	cout << (int)y << std::endl;
	//cout << "-------------------------------" << endl;
	//}
	//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

#include "Class.hpp"

#include "HttpRequestType.hpp"
#include "HttpStatusType.hpp"

#include "HttpVersionType.hpp"
#include "HttpRequestParser.hpp"
#include "HttpResponseParser.hpp"

#include <iostream>
#include <string>
#include <regex>
//#include "ServerConnectionFactory.hpp"
using namespace std;
using namespace CppSocket;
using namespace CppSocket::HTTP;
// "Length: 123\r\n  HEAD /a/sdfsdfsdffdsfd/ HTTP/1.0 \r\nLength: 123\r\nConnection: closed\r\n\r\n  sdfgsdgsdgsdgdsgdgsdgsdf\r\n\r\n"
int
main()
{
	//cout << "start" << endl;


	//HttpRequestParser parsers("DELETE /Path/To/File HTTP/1.1\r\nConnection: close\r\nAccept: text/plain; q=0.5, text/html; q=0.4, text/css, hello/tr\r\nHost:  sql.injection.you\r\n\r\nHosts: byebys");

	//HttpRequest req;
	//if(!parsers.getHttpRequest(req))
	//	return 1;
	//
	//string valuesss = "Accept";
	//auto vec = req[valuesss];

	//if(!vec.empty())
	//{
	//	for(auto x: vec)
	//		cout << valuesss << ": |" << x << "|"<< endl;
	//}
	//cout << req.getHTTPVersion().str() << endl;
	//cout << req.getRequestType().str() << endl;

	//HttpResponseParser parsers2("HTTP/1.1 200 OK\r\nConnection: close\r\nAccept: text/plain; q=0.5, text/html; q=0.4, text/css, hello/tr\r\nHost:  sql.injection.you\r\n\r\nHosts: byebys");

	//HttpResponse res;
	//if(!parsers2.getResponse(res))
	//	return 1;

	//cout << res.getStatus().str() << endl;
	//cout << res.getStatusMesage();

	//
	
	





	
	
	
	
	//string html = "<!DOCTYPE html><html><body><h1>My First Heading</h1><p>My first paragraph.</p></body></html>";
	//



	//HttpResponse r;
	//r.setHTTPVersion(HttpVersionType::HttpVersionTypes::HTTP_1_1);
	//r.setStatus(HttpStatusType::HttpStatusTypes::OK);
	//
	//std::vector<std::string> vec;
	//vec.push_back("keep-alive");
	//r.setAttr("Connection", vec);
	//vec.clear();
	//vec.push_back(to_string(html.length()));
	//r.setAttr("Content-Length", vec);
	//SocketMessage msg;
	//r.getSocketMessage(msg);
	//std::string s = msg.getMessage();
	//s += html;
	//msg.setMessage(s);
	//ServerConnectionFactory f(8080);
	//Listener l = f.getConnection();
	//Connection c = l.getConnection();
	//SocketMessage msgs;
	//c.recvMessage(msgs);
	//cout << msgs.getMessage();




	//msg.setMessage("HTTP/1.1 200 OK\r\nContent-Length: 100\r\n\r\n<!DOCTYPE html><html><body><h1>My First Heading</h1><p>My first paragraph.</p></body></html>");
//	c.sendMessage(msg);

	system("PAUSE");
	return 0;
}



	