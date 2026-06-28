#pragma once
#include <luau/lua.h>
#include <luau/lualib.h>

int luaopen_penguin(lua_State* L);
int luaopen_luamidi(lua_State* L);

static const luaL_Reg morelibs[] = {
    {"", luaopen_base},
    {"penguin", luaopen_penguin},
    {"midi", luaopen_luamidi},
    {NULL, NULL},
};