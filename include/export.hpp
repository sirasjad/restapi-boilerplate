#ifndef EXPORT_HPP
#define EXPORT_HPP

#ifdef _WINDOWS
    #ifdef DLL_EXPORTS
        #define EXPORT_PUBLIC __declspec(dllexport)
    #else
        #define EXPORT_PUBLIC __declspec(dllimport)
    #endif
#else
    #if __GNUC__ >= 4
        #define EXPORT_PUBLIC __attribute__ ((visibility("default")))
    #else
        #define EXPORT_PUBLIC
    #endif
#endif

#endif
