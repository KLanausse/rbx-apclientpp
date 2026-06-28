#include <luau/lua.h>
#include <luau/lualib.h>

static int coolCustomFunctionThatIMade(lua_State* L)
{
    lua_pushlstring(L, "Hi there =]", 11);
    return 1;
}

static const struct luaL_Reg penguin_funcs[] = {
  { "coolCustomFunctionThatIMade",	coolCustomFunctionThatIMade },
  { nullptr, nullptr }
};

int luaopen_penguin(lua_State* L)
{
    luaL_register(L, "penguin", penguin_funcs);
    return 1;
}