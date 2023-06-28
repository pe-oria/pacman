#include "ghost.h"


CGhost::CGhost(int nRow, int nCol)
  : CMoveObj(nRow , nCol) , m_nWhatGhost(0)
{
  static int nNum = CGame::itemGhoRed;
  m_nWhatGhost = nNum++;
  m_nType = CGame::itemGhoNormal;
  m_nAction = CGame::actUp;
  m_nSpead = g_nInitGhoSpead;
}


CGhost::~CGhost()
{
}


IGameElement* CGhost::creatSelf(int nRow, int nCol)
{
  return NULL;
}

// ��ȡ����
const int CGhost::getType()
{
  return (m_nType == CGame::itemGhoNormal) ?
          m_nWhatGhost : m_nType;
}

// ��ȡ��ʲô��ɫ�Ĺ�
int CGhost::getWhatGhost()
{
  return m_nWhatGhost;
}

// ����־�ģʽ
void CGhost::toFear()
{
  if(m_nType != CGame::itemGhoDie)
  {
    m_nType = CGame::itemGhoFear;
  }
}

void CGhost::beHit()
{
  if(m_nType == CGame::itemGhoFear)
  {
    g_nAddScore += g_nPlayerEatGhostScore;
    g_nPlayerEatGhostScore = (int)(g_nPlayerEatGhostScore * g_fMagScore);
    g_nGhostBeEat += 1;
    m_nType = CGame::itemGhoDie;
    // m_nSpead -= 100;
  }
}

// ����ʱ�䣬������ʱ���Ƿ���ڶ����ٶ�
int CGhost::updateClock()
{
  clock_t nowTime = clock();
  if(nowTime - m_nSpead >= m_nPreMoveClock)
  {
    m_nPreMoveClock = nowTime;
    return 1;
  }
  return 0;
}

// ��λ
void CGhost::backPos()
{
  static int nCol = g_nFirstGhoCol;
  m_nAction = CGame::actUp;
  m_postion.set(g_nFirstGhoRow, nCol++);
  m_nType = CGame::itemGhoNormal;

  if(nCol == g_nFirstGhoCol + 4)
  {
    nCol = g_nFirstGhoCol;
  }
}
