#ifdef _WIN32
// we currently don't do project-wide defines for msvc, so define the relevant ones here
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef ASIO_STANDALONE
#define ASIO_STANDALONE
#endif
#endif


//#define APCLIENT_DEBUG // to get debug output


#ifndef _MSC_VER
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas" // gcc doesn't know -Wunknown-warning-option
#pragma GCC diagnostic ignored "-Wunknown-warning-option" // clang doesn't know -Wtemplate-id-cdtor
#pragma GCC diagnostic ignored "-Wtemplate-id-cdtor"
#pragma GCC diagnostic ignored "-Wnull-pointer-subtraction"
#pragma GCC diagnostic ignored "-Wdeprecated-literal-operator"
#ifdef _WIN32
#pragma GCC diagnostic ignored "-Wcast-function-type"
#endif
#endif

#include <luau/lua.h>
#include <luau/lualib.h>

#include <apclient.hpp>
#include <luacompat.h>
#include <luapp.h>
#include <luaref.h>
#include <lua_json.h>

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