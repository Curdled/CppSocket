CppSocket

This is a C++ Networking Abstraction that should work on Windows (MSVC 12) , OS X and Linux (Ubuntu 14.04).

This is a C++ library that I created to learn BSD-Socket and WinSock. 
I have used a virtual class to implement a simple class back system that can respond:
  to a tcp connection, recieving a message and disconnection.
  https://github.com/Curdled/CppSocket/blob/master/Source/SelectCallBack.hpp
There is an example of how to use this 
  https://github.com/Curdled/CppSocket/blob/master/Source/SelectCallBackOne.cpp

This library can use the select POSIX function http://en.wikipedia.org/wiki/Select_%28Unix%29. 
I am working to get this working with both epoll and kqueue working too.
