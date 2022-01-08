#pragma once
#include "HavokAPI.h"
#include "Utility.h"
using Havok::lua_State;
#define LUACALL __int64(__fastcall*)(Havok::lua_State* L);
using UIModelIndex = unsigned __int16;
using TUI_ReportMemoryUsage = __int64(__cdecl*)();
using TUI_PutElementOnTopOfStack = __int64* (__fastcall*)(__int64* element, lua_State* L);
using TUI_LuaCall_RegisterMaterial = LUACALL;
using TUI_LuaCall_RegisterImage = LUACALL;
using TUI_LuaCall_RegisterFont = LUACALL;
using TUI_LuaCall_ProjectRootCoordinate = LUACALL;
using TUI_LuaCall_Print = LUACALL;
using TUI_LuaCall_GetTextDimensions = LUACALL;
using TUI_LuaCall_ConstructLUIElement = LUACALL;
using TUI_CoD_LuaCall_QuadCache_GC = LUACALL;
using TUIElement_MakeAnimationStateCurrent = __int64(__fastcall*)(__int64* element, __int64* animationState);
using TUIElement_CompleteAnimation = char(__fastcall*)(__int64 element, unsigned __int8 interrupted, lua_State* luaVM);
using TUI_Model_SetString = char(__fastcall*)(UIModelIndex model, char* stringValue);
using TUI_Model_SetReal = char(__fastcall*)(UIModelIndex model, float realValue);
using TUI_Model_SetBool = char(__fastcall*)(UIModelIndex model, bool boolValue);
using TUI_Model_NotifySubscriptions = void(__fastcall*)(UIModelIndex model);
using TUI_Model_GetUInt64 = __int64(__fastcall*)(UIModelIndex model);
using TUI_Model_GetString = const char* (__fastcall*)(UIModelIndex model);
using TUI_Model_GetReal = float(__fastcall*)(UIModelIndex model);
using TUI_Model_GetModelFromPath = __int64(__fastcall*)(UIModelIndex model, char* path);
using TUI_Model_GetInt = __int64(__fastcall*)(UIModelIndex model);
using TUI_Model_GetFunction = __int64(__fastcall*)(UIModelIndex model, lua_State* L);
using TUI_Model_GetDataType = __int64(__fastcall*)(UIModelIndex model);
using TUI_Model_GetBool = bool(__fastcall*)(UIModelIndex model);
using TUI_Model_ForceNotify = bool(__fastcall*)(UIModelIndex model);
using TUI_Model_CreateModelFromPath = __int64(__fastcall*)(UIModelIndex model, char* modelPath);
using TUI_Model_AllocateNode = __int64(__fastcall*)(UIModelIndex ancestorModel, char* key, char persist_maybe);
using TUI_GetMaxMemory = __int64(__stdcall*)();
using TCom_Error = char(__stdcall*)(const char* file, int line, ErrorCode code, const char* fmt, ...);


namespace Engine
{
	// LuaCall - default LUA -> C api
	extern TUI_CoD_LuaCall_QuadCache_GC UI_CoD_LuaCall_QuadCache_GC;
	extern TUI_LuaCall_ConstructLUIElement UI_LuaCall_ConstructLUIElement;
	extern TUI_LuaCall_GetTextDimensions UI_LuaCall_GetTextDimensions;
	extern TUI_LuaCall_Print UI_LuaCall_Print;
	extern TUI_LuaCall_ProjectRootCoordinate UI_LuaCall_ProjectRootCoordinate;
	extern TUI_LuaCall_RegisterFont UI_LuaCall_RegisterFont;
	extern TUI_LuaCall_RegisterImage UI_LuaCall_RegisterImage;
	extern TUI_LuaCall_RegisterMaterial UI_LuaCall_RegisterMaterial;

	// UI backend
	extern TUI_GetMaxMemory UI_GetMaxMemory;
	extern TUI_Model_AllocateNode UI_Model_AllocateNode;
	extern TUI_Model_CreateModelFromPath UI_Model_CreateModelFromPath;
	extern TUI_Model_ForceNotify UI_Model_ForceNotify;
	extern TUI_Model_GetBool UI_Model_GetBool;
	extern TUI_Model_GetDataType UI_Model_GetDataType;
	extern TUI_Model_GetFunction UI_Model_GetFunction;
	extern TUI_Model_GetInt UI_Model_GetInt;
	extern TUI_Model_GetModelFromPath UI_Model_GetModelFromPath;
	extern TUI_Model_GetReal UI_Model_GetReal;
	extern TUI_Model_GetString UI_Model_GetString;
	extern TUI_Model_GetUInt64 UI_Model_GetUInt64;
	extern TUI_Model_NotifySubscriptions UI_Model_NotifySubscriptions;
	extern TUI_Model_SetBool UI_Model_SetBool;
	extern TUI_Model_SetReal UI_Model_SetReal;
	extern TUI_Model_SetString UI_Model_SetString;
	extern TUI_PutElementOnTopOfStack UI_PutElementOnTopOfStack;
	extern TUI_ReportMemoryUsage UI_ReportMemoryUsage;
	extern TUIElement_CompleteAnimation UIElement_CompleteAnimation;
	extern TUIElement_MakeAnimationStateCurrent UIElement_MakeAnimationStateCurrent;

	// General Engine funcs
	extern TCom_Error Com_Error;
	//TUI_LuaCall_DrawText UI_LuaCall_DrawText = (TUI_LuaCall_DrawText)(GetBaseAddress() + 0X2706840);
	//TUI_DoModelStringReplacement UI_DoModelStringReplacement = (TUI_DoModelStringReplacement)(GetBaseAddress() + 0X1F33D60);
	//TUI_LuaCall_Zoom UI_LuaCall_Zoom = (TUI_LuaCall_Zoom)(GetBaseAddress() + 0X270D570);
	//TUI_LuaCall_UseStencil UI_LuaCall_UseStencil = (TUI_LuaCall_UseStencil)(GetBaseAddress() + 0X270D520);
	//TUI_LuaCall_UnregisterOpenedMenu UI_LuaCall_UnregisterOpenedMenu = (TUI_LuaCall_UnregisterOpenedMenu)(GetBaseAddress() + 0X270D400);
	//TUI_LuaCall_UndoLastTransformation UI_LuaCall_UndoLastTransformation = (TUI_LuaCall_UndoLastTransformation)(GetBaseAddress() + 0X270D3D0);
	//TUI_LuaCall_Rotate UI_LuaCall_Rotate = (TUI_LuaCall_Rotate)(GetBaseAddress() + 0X2707460);
	//TUI_LuaCall_RegisterOpenedMenu UI_LuaCall_RegisterOpenedMenu = (TUI_LuaCall_RegisterOpenedMenu)(GetBaseAddress() + 0X2707340);
	//using TUI_DoModelStringReplacement = this is usercall so call with asm
};
