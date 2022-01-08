#include "EditorClient.h"
#include <Windows.h>
namespace Client
{
	
	EditorClient* GetClient()
	{
		if (client)
		{
			return client;
		}
		else 
		{
			client = new EditorClient();
			return client;
		}
	}

	int RetryConnection_Thunk(Havok::lua_State* L)
	{
		auto result = GetClient()->RetryConnection();
		Havok::lua_pushinteger(L, result);
		return 1;
	}

	int EndConnection_Thunk(Havok::lua_State* L)
	{
		auto result = GetClient()->EndConnection();
		Havok::lua_pushinteger(L, result);
		return 1;
	}

	int ReportMemoryUsage_Thunk(Havok::lua_State* L)
	{
		// I want this to draw directly on screen
		// but if that is too much pain 
		// grab stats from s_ pools and g_ stats
		// and send to lua as a table or a string 
		// we can also get debug info out of the L
		//GetClient()->ReportMemoryUsage();

		auto s_subscriptionPool = GetBaseAddress() + (uintptr_t)(0x00007FF7800FCFD0 - 0x7FF769E10000);
		auto s_firstFreeModelNode = GetBaseAddress() + (uintptr_t)(0x00007FF7801240D0 - 0x7FF769E10000);
		auto s_modelNodePool = GetBaseAddress() + (uintptr_t)(0x00007FF7801240E0 - 0x7FF769E10000);
		auto s_eventsWithoutGC	= GetBaseAddress() + (uintptr_t)(0x00007FF783A88D9C - 0x7FF769E10000);
		auto s_LUIAllocatedElements= GetBaseAddress() + (uintptr_t)(0x00007FF783A88DA0 - 0x7FF769E10000);
		auto s_LUIAllocatedAnimationStates = GetBaseAddress() + (uintptr_t)(0x00007FF783A88DA4 - 0x7FF769E10000);
		auto g_LUIAllocatedQuadCaches = GetBaseAddress() + (uintptr_t)(0x00007FF783A88D70 - 0x7FF769E10000);
		auto g_LUIAllocatedQuadCachesMemory = GetBaseAddress() + (uintptr_t)(0x00007FF783A88D78 - 0x7FF769E10000);
		Havok::lua_pushinteger(L, *(int*)s_LUIAllocatedElements);
		//Engine::UI_ReportMemoryUsage();
		return 1;
	}

	int Test_Thunk(Havok::lua_State* L)
	{
		Havok::lua_pushinteger(L, 1);
		return 1;
	}
	
	int FreeLibrary_Thunk(Havok::lua_State* L)
	{
		::FreeLibrary(g_Module);
		return 0;
	}
}

EditorClient::EditorClient()
{

}

bool EditorClient::RetryConnection()
{
	return false;
}

bool EditorClient::EndConnection()
{
	return false;
}

bool EditorClient::MakePacket()
{
	return false;
}

bool EditorClient::ReportMemoryUsage()
{
	return false;
}

bool EditorClient::ReportClientMemoryUsage()
{
	return false;
}

