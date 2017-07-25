#ifdef HERETIC3D_EXPORTS
#define HERETIC3D __declspec(dllexport)
#else
#define HERETIC3D __declspec(dllimport)
#endif