#ifndef __DLL_H__
#define __DLL_H__

#ifdef _WIN32

#if defined(DLL_EXPORT)

#define __DLL__ __declspec(dllexport)

#else

#define __DLL__ __declspec(dllimport)

#endif //DLL_MAKER
#endif
#if defined(__linux__) || defined(__APPLE__)

#define __DLL__



#endif //__WIN32


#endif //DLL.h