#include "pch.h"
#include <detours/detours.h>
#include <mmdeviceapi.h>
#include <Audioclient.h>
#include "wav.hpp"




// in chrome 
// 
// CAudioRenderClient::GetBuffer()
// CAudioRenderClient::ReleaseBuffer()
// CAudioClient::GetSerivce

/**
 *
 * CAudioClient vtable
 * 
 * 
 */
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        DetourTransactionCommit();
        DisableThreadLibraryCalls(hModule);
        break;
    case DLL_PROCESS_DETACH:
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());


        DetourTransactionCommit();
        break;
    }
    return TRUE;
}

