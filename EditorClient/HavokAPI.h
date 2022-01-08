#pragma once
// API for CoD LUA 
#include "HavokTypes.h"


namespace Havok
{
	static constexpr auto RegisteryIndex	= -10000;
	static constexpr auto EnvironIndex		= -10001;
	static constexpr auto GlobalIndex		= -10002;
	
	int hksi_hksL_loadbuffer(lua_State* s, HksCompilerSettings* options, char const* buff, size_t sz, char const* name);
	
	void hksI_openlib(lua_State* s, const char* libname, const luaL_Reg l[], int nup, int isHksFunc);
	
	void hks_pushnamedcclosure(lua_State* s, lua_CFunction fn, int n, const char* functionName, int treatClosureAsFuncForProf);
	
	const char* hksi_lua_pushvfstring(lua_State* s, const char* fmt, va_list* argp);
	
	const char* hks_obj_tolstring(lua_State* s, HksObject* obj, size_t* len);
	
	void hksi_luaL_error(lua_State* s, const char* fmt, ...);
	
	void luaL_argerror(lua_State* s, int narg, const char* extramsg);
	
	void Lua_CoD_LuaStateManager_Error(const char* error, lua_State* luaVM);
	
	int vm_call_internal(lua_State* s, int nargs, int nresults, const hksInstruction* pc);

	const char* lua_tostring(lua_State* s, int index);

	const void* lua_topointer(lua_State* s, int index);

	int lua_toboolean(lua_State* s, int index);

	hksUint64 lua_toui64(lua_State* s, int index);

	void lua_pushnumber(lua_State* s, HksNumber n);

	void lua_pushinteger(lua_State* s, int n);

	void lua_pushnil(lua_State* s);

	void lua_pushboolean(lua_State* s, int b);

	void lua_pushvalue(lua_State* s, int index);

	void lua_pushlstring(lua_State* s, const char* str, size_t l);

	void lua_pushfstring(lua_State* s, const char* fmt, ...);

	void lua_pushvfstring(lua_State* s, const char* fmt, va_list* argp);

	void lua_getfield(lua_State* s, int index, const char* k);

	void lua_getglobal(lua_State* s, const char* k);

	int lua_pcall(lua_State* s, long nargs, long nresults);

	void luaL_register(lua_State* s, const char* libname, const luaL_Reg* l);

	void lua_setfield(lua_State* s, int index, const char* k);

	void lua_setglobal(lua_State* s, const char* k);

	void lua_pop(lua_State* s, int n);

	HksNumber lua_tonumber(lua_State* s, int index);

}

