#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
// Get the base address of the Black Ops 3 process, Thanks porter
uintptr_t GetBaseAddress();

static HMODULE g_Module = 0;

