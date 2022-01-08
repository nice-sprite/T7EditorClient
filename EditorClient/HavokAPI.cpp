#include "HavokAPI.h"
#include "Utility.h"
// TODO: Can we write this shorter without the function functions all the time??
namespace Havok
{

	int hksi_hksL_loadbuffer(lua_State* s, HksCompilerSettings* options, char const* buff, size_t sz, char const* name)
	{
		typedef int hksi_hksL_loadbuffer_t(lua_State*, HksCompilerSettings*, char const*, size_t, char const*);
		auto* f = (hksi_hksL_loadbuffer_t*)(GetBaseAddress() + 0x1D4BD80);
		return f(s, options, buff, sz, name);
	}

	void hksI_openlib(lua_State* s, const char* libname, const luaL_Reg l[], int nup, int isHksFunc)
	{
		typedef void hksI_openlib_t(lua_State*, const char*, const luaL_Reg[], int, int);
		auto* f = (hksI_openlib_t*)(GetBaseAddress() + 0x1D49440);
		f(s, libname, l, nup, isHksFunc);
	}

	void hks_pushnamedcclosure(lua_State* s, lua_CFunction fn, int n, const char* functionName, int treatClosureAsFuncForProf)
	{
		typedef void hks_pushnamedcclosure_t(lua_State*, lua_CFunction, int, const char*, int);
		auto* f = (hks_pushnamedcclosure_t*)(GetBaseAddress() + 0x1D4BA70);
		f(s, fn, n, functionName, treatClosureAsFuncForProf);
	}

	const char* hksi_lua_pushvfstring(lua_State* s, const char* fmt, va_list* argp)
	{
		typedef const char* hksi_lua_pushvfstring_t(lua_State*, const char*, va_list*);
		auto f = (hksi_lua_pushvfstring_t*)(GetBaseAddress() + 0x1D4E630);
		return f(s, fmt, argp);
	}

	const char* hks_obj_tolstring(lua_State* s, HksObject* obj, size_t* len)
	{
		typedef const char* hks_obj_tolstring_t(lua_State*, HksObject*, size_t*);
		auto f = (hks_obj_tolstring_t*)(GetBaseAddress() + 0x1D4B6C0);
		return f(s, obj, len);
	}

	void hksi_luaL_error(lua_State* s, const char* fmt, ...)
	{
		typedef void hksi_luaL_error_t(lua_State*, const char*, ...);
		auto f = (hksi_luaL_error_t*)(GetBaseAddress() + 0x1D4D050);
		f(s, fmt);
	}

	void luaL_argerror(lua_State* s, int narg, const char* extramsg)
	{
		typedef void luaL_argerror_t(lua_State*, int, const char*);
		auto f = (luaL_argerror_t*)(GetBaseAddress() + 0x1D4CE50);
		f(s, narg, extramsg);
	}

	// todo move to engine
	void Lua_CoD_LuaStateManager_Error(const char* error, lua_State* luaVM)
	{
		typedef void Lua_CoD_LuaStateManager_Error_t(const char*, lua_State*);
		auto f = (Lua_CoD_LuaStateManager_Error_t*)(GetBaseAddress() + 0x1F12640);
		f(error, luaVM);
	}

	int vm_call_internal(lua_State* s, int nargs, int nresults, const hksInstruction* pc)
	{
		typedef int vm_call_internal_t(lua_State*, int, int, const hksInstruction*);
		auto f = (vm_call_internal_t*)(GetBaseAddress() + 0x1D71070);
		return f(s, nargs, nresults, pc);
	}

    HksObject getObjectForIndex(lua_State* s, int index)
    {
        HksNumber result;
        HksObject* object;
        int failure;

        if (index <= RegisteryIndex)
        {
            failure = 0;
            switch (index)
            {
            case RegisteryIndex:
                object = &s->m_global->m_registry;
                break;
            case GlobalIndex:
                object = &s->globals;
                break;
            case EnvironIndex:
                s->m_cEnv.v.cClosure = (cclosure*)s->m_apistack.base[-1].v.cClosure->m_env;
                s->m_cEnv.t = 5;
                object = &s->m_cEnv;
                break;
            default:
                object = (HksObject*)(&s->m_apistack.base[-1].v.cClosure->m_numUpvalues + 8 * (GlobalIndex - index));
                break;
            }
        }
        else if (index <= 0)
        {
            if (index >= 0)
            {
                failure = 1;
                object = 0LL;
            }
            else if (&s->m_apistack.top[index] < s->m_apistack.base)
            {
                failure = 1;
                object = 0LL;
            }
            else
            {
                failure = 0;
                object = &s->m_apistack.top[index];
            }
        }
        else if (&s->m_apistack.base[index - 1] >= s->m_apistack.top)
        {
            failure = 1;
            object = 0LL;
        }
        else
        {
            failure = 0;
            object = &s->m_apistack.base[index - 1];
        }
        // TODO: Handle failures
        return *object;
    }

    int lua_pcall(lua_State* s, long nargs, long nresults)
    {
        typedef int lua_pcall_t(lua_State* luaState, long, long);
        lua_pcall_t* f2 = (lua_pcall_t*)(GetBaseAddress() + 0x1D53E40);
        return f2(s, nargs, nresults);
    }

    void luaL_register(lua_State* s, const char* libname, const luaL_Reg* l)
    {
        hksI_openlib(s, libname, l, 0, 1);
    }

    void lua_setfield(lua_State* s, int index, const char* k)
    {
        typedef void lua_setfield_t(lua_State* luaState, int, const char*);
        auto f = (lua_setfield_t*)(GetBaseAddress() + 0x1429680);
        f(s, index, k);
    }

    void lua_setglobal(lua_State* s, const char* k)
    {
        lua_setfield(s, GlobalIndex, k);
    }

    void lua_pop(lua_State* s, int n)
    {
        s->m_apistack.top -= n;
    }

    HksNumber lua_tonumber(lua_State* s, int index)
    {
        auto object = getObjectForIndex(s, index);
        return object.v.number;
    }

    const char* lua_tostring(lua_State* s, int index)
    {
        auto object = getObjectForIndex(s, index);
        return hks_obj_tolstring(s, &object, 0);
    }

    const void* lua_topointer(lua_State* s, int index)
    {
        typedef const void* lua_topointer_t(lua_State* luaState, int);
        auto f = (lua_topointer_t*)(GetBaseAddress() + 0x1D4F020);
        return f(s, index);
    }

    int lua_toboolean(lua_State* s, int index)
    {
        typedef int lua_toboolean_t(lua_State* luaState, int);
        auto f = (lua_toboolean_t*)(GetBaseAddress() + 0x14373D0);
        return f(s, index);
    }

    hksUint64 lua_toui64(lua_State* s, int index)
    {
        typedef hksUint64 lua_toui64_t(lua_State* luaState, int);
        auto f = (lua_toui64_t*)(GetBaseAddress() + 0x1D4C8A0);
        return f(s, index);
    }

    void lua_pushnumber(lua_State* s, HksNumber n)
    {
        auto top = s->m_apistack.top;
        top->v.number = n;
        top->t = TNUMBER;
        s->m_apistack.top = top + 1;
    }

    void lua_pushinteger(lua_State* s, int n)
    {
        auto top = s->m_apistack.top;
        top->v.number = float(n);
        top->t = TNUMBER;
        s->m_apistack.top = top + 1;
    }

    void lua_pushnil(lua_State* s)
    {
        auto top = s->m_apistack.top;
        top->v.number = 0;
        top->t = TNIL;
        s->m_apistack.top = top + 1;
    }

    void lua_pushboolean(lua_State* s, int b)
    {
        auto top = s->m_apistack.top;
        top->v.boolean = b;
        top->t = TBOOLEAN;
        s->m_apistack.top = top + 1;
    }

    void lua_pushvalue(lua_State* s, int index)
    {
        HksObject* st;
        auto object = getObjectForIndex(s, index);
        st = s->m_apistack.top;
        *st = object;
        s->m_apistack.top = st + 1;
    }

    void lua_pushlstring(lua_State* s, const char* str, size_t l)
    {
        typedef void lua_pushlstring_t(lua_State* luaState, const char*, size_t);
        auto f = (lua_pushlstring_t*)(GetBaseAddress() + 0xA18430);
        f(s, str, l);
    }

    void lua_pushfstring(lua_State* s, const char* fmt, ...)
    {
        va_list va;
        va_start(va, fmt);
        hksi_lua_pushvfstring(s, fmt, &va);
    }

    void lua_pushvfstring(lua_State* s, const char* fmt, va_list* argp)
    {
        hksi_lua_pushvfstring(s, fmt, argp);
    }

    void lua_getfield(lua_State* s, int index, const char* k)
    {
        auto object = getObjectForIndex(s, index);

        const HksRegister v16;

        auto top = --s->m_apistack.top;
        top->v.cClosure = object.v.cClosure;
        s->m_apistack.top = top++;
    }

    void lua_getglobal(lua_State* s, const char* k)
    {
        lua_getfield(s, GlobalIndex, k);
    }
}