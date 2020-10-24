extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}




int initial()
{
  lua_State *L = lua_open();
  lua_close(L);
  return 0;
}