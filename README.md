CppSocket

This is a C++ Networking Abstraction that should work on Windows (MSVC 12), OS X and Linux (Ubuntu 14.04).

This is a C++ library that was created as a learning process BSD-Socket and WinSock and should not be used for production. 
This uses the Decorator pattern so select or epoll or any other implementation of a server could be used.

````C++
SelectSocketMonitorImp imp(new SocketMonitorCallBackCounted, ServerConnectionFactory.getConnection());
SocketMonitor monitor;
monitor.setSocketMonitorImp(&imp);
````
  
There is also a callback system. This is achieved by implementing SocketMonitor
There is an example of this using a simple Counted message format with checking of the
inital length so tcp doens't break up the packets unexpectedly.
It has successfully send both binary and ascii files using the client functionality to a server using
SocketMonitorCallBackCounted and has sent >4GB files.
https://github.com/Curdled/CppSocket/blob/master/Source/SocketMonitorCallBackCounted.cpp
  
https://github.com/Curdled/CppSocket/blob/master/Source/CountedDataParser.hpp
Which was created and unit tested.

The next step is to get this working with both epoll and kqueue.


There is also some client functionality 

````C++
std::string *hostname = new std::string("192.168.1.20");
std::string *port = new std::string("8080");
ClientConnectionFactory f(hostname, port);
Connection conn = f.getConnection();
conn >> "Example Message";
````
