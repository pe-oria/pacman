#include "moveObj.h"


CMoveObj::CMoveObj()
  : CGameElement() , m_nSpead(0) , m_nPreMoveClock(0)
{
}

CMoveObj::CMoveObj(int nRow , int nCol)
  : CGameElement(nRow, nCol) , m_nSpead(0) , m_nPreMoveClock(0)
{
  // ���󣬽���ʼ�ٶ���Ϊ���ᵼ���߼�����
  // m_nPreMoveClock = -1 ^ (1 << (sizeof(clock_t) * 8 - 1));
}

CMoveObj::~CMoveObj()
{
}

// ����ʱ�䣬������ʱ���Ƿ���ڶ����ٶ�
int CMoveObj::updateClock()
{
  return 0;
}


// �ƶ�
int CMoveObj::move()
{
  // ����ұ���ץ����ʱ�����Ͳ����ٶ���
  // ������ڽ���ڲ�·��ʱ���⵽��ץ����ң�
  // �����ȴû�м�⵽����ץ��
  // ��Ϊ�߼����ǹ���������ƶ��ģ����Թ��������������
  if(m_nType == CGame::itemPlayer && g_isBeEat == 1)
  {
    return 0;
  }

  if(updateClock() == 0)
  {
    return 0;
  }
  int nCrash = isCrash();
  if(nCrash == CGame::craPass)
  {
    m_postion = m_postion.getActionPostion(m_nAction);
  }

  // ��������Ƿ�ؼ�
  if(m_nType == CGame::itemGhoDie)
  {
    if(m_postion[ CGame::posRow ] == g_nFirstGhoRow &&
       m_postion[ CGame::posCol ] >= g_nFirstGhoCol - 1 &&
       m_postion[ CGame::posCol ] <= g_nFirstGhoCol + g_nGhost)
    {
      m_nType = CGame::itemGhoNormal;
      // m_nSpead += 100;
    }
  }
  // ���ͬ�������û���ص�
  else if(m_nType <= CGame::itemGhoNormal || m_nType <= CGame::itemGhoDie)
  {
    // �������ڵ�ͼ�����к���Ĺ�
    for(int i = getType() - CGame::itemGhoRed + 1; i < g_nGhost; ++i)
    {
      // ����������
      if(g_gameMap->getMoveObj()[ i ]->getPos() == m_postion)
      {
        // �жϷ����Ƿ����
        if(((CMoveObj*)g_gameMap->getMoveObj()[ i ])->getAction() == m_nAction)
        {
          // ���Լ������Ϊ������
          m_nAction = m_nAction + (((m_nAction & 1) == 0) ? 1 : -1);
        }
      }
    }
  }

  return 0;
}

// �����ٶ�
void CMoveObj::setSpead(int nSpead)
{
  m_nSpead = nSpead;
}

clock_t CMoveObj::getSpead()
{
  return m_nSpead;
}

// ��λ
void CMoveObj::backPos()
{

}

// ��ȡ����
int CMoveObj::getAction()
{
  return m_nAction;
}
