#include "superPean.h"


CSuperPean::CSuperPean(int nRow, int nCol)
  : CStaticObj(nRow, nCol)
{
  m_nType = CGame::itemSurperPean;
}


CSuperPean::~CSuperPean()
{
}


IGameElement* CSuperPean::creatSelf(int nRow, int nCol)
{
  return NULL;
}

void CSuperPean::beHit()
{
  // ��ұ���ʱ������ִ����Ӧ����
  if(g_isBeEat != 0)
  {
    return;
  }
  m_nType = CGame::itemRoad;
  g_nAddScore += g_nSuperPeanBeEatScore;
  g_nSuperPeanBeEat += 1;
  ++g_nEatPeanNum;
}
