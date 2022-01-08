#include "Engine.h"


// LuaCall - default LUA -> C api
TUI_CoD_LuaCall_QuadCache_GC Engine::UI_CoD_LuaCall_QuadCache_GC = (TUI_CoD_LuaCall_QuadCache_GC)(GetBaseAddress() + 0X1F2C6E0);
TUI_LuaCall_ConstructLUIElement Engine::UI_LuaCall_ConstructLUIElement = (TUI_LuaCall_ConstructLUIElement)(GetBaseAddress() + 0X27064C0);
TUI_LuaCall_GetTextDimensions Engine::UI_LuaCall_GetTextDimensions = (TUI_LuaCall_GetTextDimensions)(GetBaseAddress() + 0X2706B50);
TUI_LuaCall_Print Engine::UI_LuaCall_Print = (TUI_LuaCall_Print)(GetBaseAddress() + 0X2706D20);
TUI_LuaCall_ProjectRootCoordinate Engine::UI_LuaCall_ProjectRootCoordinate = (TUI_LuaCall_ProjectRootCoordinate)(GetBaseAddress() + 0X2706D30);
TUI_LuaCall_RegisterFont Engine::UI_LuaCall_RegisterFont = (TUI_LuaCall_RegisterFont)(GetBaseAddress() + 0X2707160);
TUI_LuaCall_RegisterImage Engine::UI_LuaCall_RegisterImage = (TUI_LuaCall_RegisterImage)(GetBaseAddress() + 0X2707210);
TUI_LuaCall_RegisterMaterial Engine::UI_LuaCall_RegisterMaterial = (TUI_LuaCall_RegisterMaterial)(GetBaseAddress() + 0X27072A0);

// Engine::UI backend
TUI_GetMaxMemory Engine::UI_GetMaxMemory = (TUI_GetMaxMemory)(GetBaseAddress() + 0X1F29090);
TUI_Model_AllocateNode Engine::UI_Model_AllocateNode = (TUI_Model_AllocateNode)(GetBaseAddress() + 0X2019660);
TUI_Model_CreateModelFromPath Engine::UI_Model_CreateModelFromPath = (TUI_Model_CreateModelFromPath)(GetBaseAddress() + 0X2019860);
TUI_Model_ForceNotify Engine::UI_Model_ForceNotify = (TUI_Model_ForceNotify)(GetBaseAddress() + 0X20199E0);
TUI_Model_GetBool Engine::UI_Model_GetBool = (TUI_Model_GetBool)(GetBaseAddress() + 0X2019CB0);
TUI_Model_GetDataType Engine::UI_Model_GetDataType = (TUI_Model_GetDataType)(GetBaseAddress() + 0X2019CE0);
TUI_Model_GetFunction Engine::UI_Model_GetFunction = (TUI_Model_GetFunction)(GetBaseAddress() + 0X2019D00);
TUI_Model_GetInt Engine::UI_Model_GetInt = (TUI_Model_GetInt)(GetBaseAddress() + 0X2019D40);
TUI_Model_GetModelFromPath Engine::UI_Model_GetModelFromPath = (TUI_Model_GetModelFromPath)(GetBaseAddress() + 0X2019F10);
TUI_Model_GetReal Engine::UI_Model_GetReal = (TUI_Model_GetReal)(GetBaseAddress() + 0X2019FB0);
TUI_Model_GetString Engine::UI_Model_GetString = (TUI_Model_GetString)(GetBaseAddress() + 0X2019FE0);
TUI_Model_GetUInt64 Engine::UI_Model_GetUInt64 = (TUI_Model_GetUInt64)(GetBaseAddress() + 0X201A010);
TUI_Model_NotifySubscriptions Engine::UI_Model_NotifySubscriptions = (TUI_Model_NotifySubscriptions)(GetBaseAddress() + 0X201A1F0);
TUI_Model_SetBool Engine::UI_Model_SetBool = (TUI_Model_SetBool)(GetBaseAddress() + 0X201A500);
TUI_Model_SetReal Engine::UI_Model_SetReal = (TUI_Model_SetReal)(GetBaseAddress() + 0X201A600);
TUI_Model_SetString Engine::UI_Model_SetString = (TUI_Model_SetString)(GetBaseAddress() + 0X201A650);
TUI_PutElementOnTopOfStack Engine::UI_PutElementOnTopOfStack = (TUI_PutElementOnTopOfStack)(GetBaseAddress() + 0X270D750);
TUI_ReportMemoryUsage Engine::UI_ReportMemoryUsage = (TUI_ReportMemoryUsage)(GetBaseAddress() + 0X270DAE0);
TUIElement_CompleteAnimation Engine::UIElement_CompleteAnimation = (TUIElement_CompleteAnimation)(GetBaseAddress() + 0X26FFDA0);
TUIElement_MakeAnimationStateCurrent Engine::UIElement_MakeAnimationStateCurrent = (TUIElement_MakeAnimationStateCurrent)(GetBaseAddress() + 0X27010B0);

// General Engine funcs
TCom_Error Com_Error = (TCom_Error)(GetBaseAddress() + 0x20F8BD0);