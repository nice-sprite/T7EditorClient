#include "Utility.h"


uintptr_t GetBaseAddress() {
	static uintptr_t BaseAddress{1}; // sentinel value
	if (BaseAddress != 1) return BaseAddress;
	PROCESSENTRY32 Entry;
	Entry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (Process32First(Snapshot, &Entry) == TRUE)
	{
		do
		{
			auto processName = std::string(Entry.szExeFile);
			if (processName == TEXT("BlackOps3.exe"))
			{
				HANDLE Bo3Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, Entry.th32ProcessID);
				MODULEENTRY32 moduleData;
				moduleData.dwSize = sizeof(MODULEENTRY32);
				if (!Module32First(Bo3Snapshot, &moduleData))
				{
					CloseHandle(Bo3Snapshot);
					return NULL;
				}
				uintptr_t MainModuleAddress = (uintptr_t)moduleData.modBaseAddr;
				CloseHandle(Bo3Snapshot);

				return MainModuleAddress;
			}

		} while (Process32Next(Snapshot, &Entry));
	}
	CloseHandle(Snapshot);

	return NULL;
}
