/* 
 * File:   function.h
 * Author: joe
 *
 * Created on 15 September 2012, 11:36
 */

#ifndef _STRING_FUNCTION_HPP_
#define	_STRING_FUNCTION_HPP_


#include <string>
#include <sstream>


template <class T>
inline std::string to_string (const T& t)
{
std::stringstream ss;
ss << t;
return ss.str();
}


template <class T>
inline int to_int (const T& t)
{
    //int inter = t;
    return t;
}


inline int stoi(std::string s)
{
    std::stringstream ss(s);
    int result;
    ss >> result;   
    return result;
}


#endif	/* FUNCTION_H */

