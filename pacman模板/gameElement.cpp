#include "gameElement.h"


CGameElement::CGameElement()
  : m_nAction(0) , m_postion() , m_nType(0)
{
}

CGameElement::CGameElement(int nRow , int nCol)
  : m_nAction(0) , m_postion(nRow , nCol) , m_nType(0)
{

}


CGameElement::~CGameElement()
{
}


// ��ȡ��������
int& CGameElement::operator[](int nIndex)
{
  return m_postion[nIndex];
}

// ����������Ƚ���ײ�ȼ�
const int CGameElement::operator==(IGameElement& obj)
{
  int nMyType = this->getType();

  // ײǽ
  if(obj.getType() == CGame::itemWall)
  {
    return CGame::craNo;
  }
  // ����
  else if(nMyType == CGame::itemGhoDie)
  {
    return CGame::craPass;
  }
  // ײ·
  else if(obj.getType() == CGame::itemRoad)
  {
    return CGame::craPass;
  }
  // ײ����
  else if(obj.getType() == CGame::itemPean)
  {
    // ���ײ��
    if(nMyType == CGame::itemPlayer)
    {
      return CGame::craHitAn;
    }
    else
    {
      return CGame::craPass;
    }
  }
  // ײ���
  else if(obj.getType() == CGame::itemGhoHome)
  {
    // ���ײ���
    if(nMyType == CGame::itemPlayer)
    {
      return CGame::craNo;
    }
    else
    {
      return CGame::craPass;
    }
  }
  // ײ������
  else if(obj.getType() == CGame::itemSurperPean)
  {
    // ���ײ������
    if(nMyType == CGame::itemPlayer)
    {
      return CGame::craHitAn;
    }
    else
    {
      return CGame::craPass;
    }
  }
  // ײ����
  else if (obj.getType() == CGame::itemGhoDie)
  {
    return CGame::craPass;
  }
  // ��ײ��
  else if(nMyType >= CGame::itemGhoNormal && nMyType <= CGame::itemGhoDie &&
          obj.getType() >= CGame::itemGhoNormal && obj.getType() <= CGame::itemGhoDie)
  {
    // ���ǿ����໥��Խ��
    // �־�״̬�Ĺ�����໥����
    // if(nMyType == CGame::itemGhoFear || obj.getType() == CGame::itemGhoFear)
    // {
    //   return CGame::craPass;
    // }
    return CGame::craPass;
  }
  // �Լ�ײ�Լ��������ϲ����ܣ���Ҫ��ֹ���ⷢ����
  else if(nMyType == obj.getType())
  {
    return CGame::craPass;
  }
  // ��ײ���
  else if(obj.getType() == CGame::itemPlayer)
  {
    // �־�״̬�Ĺ�
    if(nMyType == CGame::itemGhoFear)
    {
      return CGame::craBeHit;
    }
    // ����״̬�����״̬�Ĺ�
    else
    {
      return CGame::craHitAn;
    }
  }
  // ���ײ��������������ô���жϻ��ܵ�����϶��������ײ����
  else if(nMyType == CGame::itemPlayer)
  {
    // �־�״̬�Ĺ�
    if(obj.getType() == CGame::itemGhoFear)
    {
      return CGame::craHitAn;
    }
    // ����״̬�����״̬�Ĺ�
    else
    {
      return CGame::craBeHit;
    }
  }

  return CGame::craNo;
}

// ��ȡ�������
CPostion& CGameElement::getPos()
{
  return m_postion;
}

// ��ȡ����
const int CGameElement::getType()
{
  return m_nType;
}

// �ı�����
void CGameElement::changeType(int nType)
{
  m_nType = nType;
}

// �ƶ�
int CGameElement::move()
{
  return 0;
}

// �ı䷽��
int CGameElement::changeAction(int nAct, int nMode)
{
  // if(m_nAction == nAct)
  // {
  //   return 0;
  // }
  int nPreAct = m_nAction;
  m_nAction = nAct;
  int nCrash = isCrash(nMode);
  if(nCrash == CGame::craNo)
  {
    m_nAction = nPreAct;
    return 1;
  }
  return 0;
}

// ��ײ���
const int CGameElement::isCrash(int nMode)
{
  CPostion nextPos = m_postion.getActionPostion(m_nAction);
  IGameElement* nextObj = NULL;
  int nCrash = CGame::craPass;

  if(nMode != 2)
  {
    // ��ȡ�붯̬������ײ���
    nCrash = CGame::craPass;
    IGameElement** moveObj = g_gameMap->getMoveObj();
    nextObj = NULL;
    for(int i = 0; i < g_nGhost + g_nPlayer; ++i)
    {
      if(m_nType == moveObj[ i ]->getType() && m_postion == moveObj[i]->getPos())
      {
        continue;
      }

      if(nextPos == moveObj[ i ]->getPos())
      {
        nCrash = (*this == *moveObj[ i ]);
        nextObj = moveObj[ i ];
      }
    }

    if(nCrash == CGame::craNo)
    {
      return CGame::craNo;
    }
    else if(nMode == 0 && nCrash == CGame::craBeHit)
    {
      beHit();
      return CGame::craNo;
    }
    else if(nMode == 0 && nextObj != NULL && nCrash == CGame::craHitAn)
    {
      nextObj->beHit();
      return CGame::craNo;
    }

  }

  // ��ȡ�뾲̬������ײ���
  nextObj = (*g_gameMap)[ nextPos[ CGame::posRow ] ][nextPos[CGame::posCol]];
  nCrash  = (*this == *nextObj);

  if(nCrash == CGame::craNo)
  {
    return CGame::craNo;
  }
  else if(nMode == 0 && nCrash == CGame::craHitAn)
  {
    nextObj->beHit();
  }
  return CGame::craPass;
}


// ײ�����Լ���ײ�ȼ��ߵ�
void CGameElement::beHit()
{

}


// ײ�����Լ���ײ�ȼ��͵�
void CGameElement::hitAnthor()
{

}

// ��������
IGameElement* CGameElement::creatSelf(int nRow, int nCol)
{
  return new CGameElement();
}