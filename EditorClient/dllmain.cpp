#include "dllmain.h"
#include "HavokAPI.h"
#include "EditorClient.h"
#define DLLEXPORT __declspec(dllexport)

extern "C"
{
    int DLLEXPORT init(Havok::lua_State* L)
    {
        Havok::hksI_openlib(L, "EditorClient", Client::Library, 0, 1);
        return 1;
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) 
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        g_Module = hinstDLL;
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}