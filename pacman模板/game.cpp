#include "preStatement.h"
#include "game.h"

/* Ĭ�ϱ��� */
const clock_t g_nInitGhoSpead = 350;
const clock_t g_nInitPlayerSpead = 200;
const int g_nMapRow = 31;
const int g_nMapCol = 28;
const int g_nPlayer = 1;
const int g_nGhost = 4;
const int g_nPean = 300;
int g_nPlayerlife = 3;

CGameMap* g_gameMap = NULL;

const int g_nFirstGhoRow = 14;
const int g_nFirstGhoCol = 12;

const int g_nPlayerRow = 23;
const int g_nPlayerCol = 13;

// ����ѵ÷���
int g_nAddScore = 0;
// ��ҳԹ����
int g_nPlayerEatGhostScore = PLAYEREATGHOSTSCORE;
int g_nPlayerEatGhostScore_show = PLAYEREATGHOSTSCORE;
// ��ҳԹ�ӷֱ���
const float g_fMagScore = 1.5;
// ��ұ��Ա�־
int g_isBeEat = 0;
// �Ե�һֻ��
int g_nGhostBeEat = 0;
// ��ҳԵ����ӵ������������������������300
int g_nEatPeanNum = 1;
// ���������Ա�־����һ����1
int g_nSuperPeanBeEat = 0;
// �Գ���������
const int g_nSuperPeanBeEatScore = 1;
// �Զ��ӷ���
const int g_nPeanBeEatScore = 1;
// ��־�ʱ��
const clock_t g_nGhostFearTime = 10000;
// ��ʼ�־�ʱ��
clock_t g_nFearStartTime = 0;
// ��ȼ�
int g_nGhostLevel = 1;
// ��ǰ�ٶ�
clock_t g_nNowGhostSpead = g_nInitGhoSpead;

CGame::CGame()
{
}


CGame::~CGame()
{
}
