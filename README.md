CppSocket

This is a C++ Networking Abstraction that should work on Windows (MSVC 12), OS X and Linux (Ubuntu 14.04).

This is a C++ library that I created to learn BSD-Socket and WinSock. 
This uses the Decorator pattern so select or epoll or any other implementation of a server could be used

````C++
SelectSocketMonitorImp imp(new SocketMonitorCallBackCounted, ServerConnectionFactory.getConnection());
SocketMonitor monitor;
monitor.setSocketMonitorImp(&imp);
````
  
I also created a callback system
This is an implemenation of SocketMonitor that uses a simple Counted message format with checking of the
inital length so tcp doens't break up the packets unexpectedly,
I have successfully send both binary and ascii files using this to a server and send >4GB files.
https://github.com/Curdled/CppSocket/blob/master/Source/SocketMonitorCallBackCounted.cpp
  
https://github.com/Curdled/CppSocket/blob/master/Source/CountedDataParser.hpp
which I created and wrote unit test for.
I am working to get this working with both epoll and kqueue working too.


There is also some client functionality 

````C++
std::string *hostname = new std::string("192.168.1.20");
std::string *port = new std::string("8080");
ClientConnectionFactory f(hostname, port);
Connection conn = f.getConnection();
conn >> "Example Message";
````
