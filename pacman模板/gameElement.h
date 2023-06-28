#ifndef CGAMEELEMENTHEADER
#define CGAMEELEMENTHEADER
#pragma once

#include "pacMan.h"
#include "iGameElement.h"

class CGameElement :
  public IGameElement
{
public:
  CGameElement();
  CGameElement(int nRow , int nCol);
  virtual ~CGameElement();
  // ��ȡ��������
  virtual int& operator[](int nIndex);
  // ����������Ƚ���ײ�ȼ�
  virtual const int operator==(IGameElement& obj);
  // ��ȡ�������
  virtual CPostion& getPos();
  // ��ȡ����
  virtual const int getType();
  // �ı�����
  virtual void changeType(int nType);
  // �ƶ�
  virtual int move();
  // �ı䷽��
  virtual int changeAction(int nAct, int nMode = 1);
  // ��ײ���
  virtual const int isCrash(int nMode = 0);
  // ײ�����Լ���ײ�ȼ��ߵ�
  virtual void beHit();
  // ײ�����Լ���ײ�ȼ��͵�
  virtual void hitAnthor();
  // ��������
  virtual IGameElement* creatSelf(int nRow, int nCol);

protected:
  CPostion m_postion;
  int m_nType;
  int m_nAction;
};

#endif // CGAMEELEMENTHEADER