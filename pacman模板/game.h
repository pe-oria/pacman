#ifndef CGAMEHEADER
#define CGAMEHEADER
#pragma once
#include <ctime>
#include "preStatement.h"

/* Ĭ�ϱ��� */
extern const clock_t g_nInitGhoSpead;
extern const clock_t g_nInitPlayerSpead;
extern const int g_nMapRow;
extern const int g_nMapCol;
extern const int g_nPlayer;
extern const int g_nGhost;
extern const int g_nPean;
extern int g_nPlayerlife;

extern CGameMap* g_gameMap;

extern const int g_nFirstGhoRow;
extern const int g_nFirstGhoCol;

extern const int g_nPlayerRow;
extern const int g_nPlayerCol;

// ����ѵ÷���
extern int g_nAddScore;
// ��ҳԹ����
extern int g_nPlayerEatGhostScore;
extern int g_nPlayerEatGhostScore_show;
// ��ҳԹ�ӷֱ���
extern const float g_fMagScore;
// ��ұ��Ա�־
extern int g_isBeEat;
// �Ե�һֻ��
extern int g_nGhostBeEat;
// ��ҳԵ����ӵ������������������������300
extern int g_nEatPeanNum;
// ���������Ա�־����һ����1
extern int g_nSuperPeanBeEat;
// �Գ���������
extern const int g_nSuperPeanBeEatScore;
// �Զ��ӷ���
extern const int g_nPeanBeEatScore;
// ��־�ʱ��
extern const clock_t g_nGhostFearTime;
// ��ʼ�־�ʱ��
extern clock_t g_nFearStartTime;
// ��ȼ�
extern int g_nGhostLevel;
// ��ǰ�ٶ�
extern clock_t g_nNowGhostSpead;

#define MAPROW  31
#define MAPCOL  28
#define NPLAYER 1
#define NGHOST  4
#define NCLASS  14 // ��ϷԪ������
#define PLAYEREATGHOSTSCORE 50

class CGame
{
public:
  enum gameAction
  {
    actUp = 0,
    actDown,
    actLeft,
    actRight
  };
  enum gamePostion
  {
    posRow = 0,
    posCol
  };
  enum gameCrash
  {
    craBeHit = -1,
    craNo    = 0,
    craHitAn,
    craPass
  };
  enum gameElement
  {
    itemPean = 0,
    itemWall,
    itemSurperPean,
    itemRoad,
    itemGhoHome,
    itemGhoNormal,
    itemGhoRed,
    itemGhoYell,
    itemGhoBlue,
    itemGhoPink,
    itemGhoTremble,
    itemGhoFear,
    itemGhoDie,
    itemPlayer
  };

  CGame();
  ~CGame();
};

#endif // CGAMEHEADER