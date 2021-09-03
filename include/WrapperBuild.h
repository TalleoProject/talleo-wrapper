#ifdef WIN32
# ifdef BUILD_DLL
#  define EXPORT __declspec(dllexport)
# else
#  define EXPORT __declspec(dllimport)
# endif
#else
# ifdef BUILD_DLL
#  define EXPORT __attribute__ ((visibility ("default")))
# else
#  define EXPORT
# endif
#endif
