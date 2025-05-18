#pragma once
#include "Windows.h"
#include <iostream>
#include <string>
#include <map>
#include "assert.h"
#include "flags.h"

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#include <wingdi.h>
#pragma comment(lib, "Msimg32.lib")  // TransparentBlt 사용 시 필요

using namespace Gdiplus;
using namespace std;



#include "define.h"


template<typename T1, typename T2>
void Safe_Delete_Map(map<T1, T2>& _map)
{
    typename map<T1, T2>::iterator iter = _map.begin();

    for (; iter != _map.end(); ++iter)
        delete iter->second;
    _map.clear();
}