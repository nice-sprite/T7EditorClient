#pragma once
#include "Engine.h"
#include "HavokAPI.h"
#include <vector>
#define LUA_LIB extern "C" int __declspec(dllexport)

#define FUNC_NAME(name) #name
#define LUA_C_LIB(func) {FUNC_NAME(func), func}

class EditorClient
{
public:
	struct ClientConnectionConfig
	{
		std::string server;
		int port;
		int sendIntervalMs;
		int maxSendSize;
		int version;
		int retry;
		int status;
	};

	struct ClientSettings
	{
		bool reportMemory;
		bool reportConnectionStatus;
		bool enableServerWrite; // allows server to send messages to the client to modify values.
	};

	union UIModelValue
	{
		float Float; // 4bytes
		int Integer; // 4bytes
		char* String; // 8bytes 
	};

	struct UIModelDef 
	{
		int type;
		std::string path;
		UIModelValue value;
	};

	

	EditorClient();
	bool RetryConnection();
	bool EndConnection();
	bool MakePacket();
	bool ReportMemoryUsage();
	bool ReportClientMemoryUsage();
	bool RegisterTrackedModelForEditor(UIModelIndex modelIndex);

private:
	ClientConnectionConfig connection;
	std::vector<UIModelDef> modelDataPool{ 1024 }; // reserve 1024 slots 

};

namespace Client
{
	static EditorClient* client;
	EditorClient* GetClient();
	LUA_LIB RetryConnection_Thunk(Havok::lua_State* L);
	LUA_LIB EndConnection_Thunk(Havok::lua_State* L);
	LUA_LIB ReportMemoryUsage_Thunk(Havok::lua_State* L);
	LUA_LIB Test_Thunk(Havok::lua_State* L);
	LUA_LIB FreeLibrary_Thunk(Havok::lua_State* L);

	static Havok::luaL_Reg Library[] = {
		LUA_C_LIB(RetryConnection_Thunk),
		LUA_C_LIB(EndConnection_Thunk),
		LUA_C_LIB(ReportMemoryUsage_Thunk),
		LUA_C_LIB(Test_Thunk),
		LUA_C_LIB(FreeLibrary_Thunk)
	};
}