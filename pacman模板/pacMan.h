#pragma once

/* ϵͳͷ�ļ� */
#include <cstdio>
#include <ctime>
#include <cstring>
#include <windows.h>
#include <conio.h>

/* ��Ŀͷ�ļ� */
#include "game.h"
#include "preStatement.h"
#include "single.h"
#include "funPtr.h"
#include "postion.h"
#include "gameUI.h"
#include "gameMap.h"
#include "gameCtrl.h"

#ifndef IGAMEELEMENTHEADER
#ifndef CGAMEELEMENTHEADER

#ifndef CSTATICOBJHEDAER
#include "road.h"
#include "pean.h"
#include "superPean.h"
#include "wall.h"
#include "ghoHome.h"
#endif // CSTATICOBJHEADER

#ifndef CMOVEOBJHEADER
#include "player.h"
#include "ghost.h"
#endif // CMOVEOBJHEADER

#endif // CGAMEELEMENTHEADER
#endif // IGAMEELEMENTHEADER