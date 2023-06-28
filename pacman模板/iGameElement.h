#ifndef IGAMEELEMENTHEADER
#define IGAMEELEMENTHEADER
#pragma once
#include "pacMan.h"
#include "preStatement.h"

class IGameElement
{
public:
  virtual ~IGameElement() = 0;

  /* ��ȡ�������� */
  virtual int& operator[](int nIndex) = 0;

  /* ����������Ƚ���ײ�ȼ� */
  virtual const int operator==(IGameElement& obj) = 0;

  /* ��ȡ������� */
  virtual CPostion& getPos() = 0;

  /* ��ȡ��ǰ�������� */
  virtual const int getType() = 0;

  /* �ı����� */
  virtual void changeType(int nType) = 0;

  /* �ƶ� */
  virtual int move() = 0;

  /* �ı䷽�� */
  virtual int changeAction(int nAct, int nMode = 1) = 0;

  /* ��ײ��� */
  virtual const int isCrash(int nMode = 0) = 0;

  /* ײ�����Լ��ȼ��ߵ� */
  virtual void beHit() = 0;

  /* ײ�����Լ��ȼ��͵� */
  virtual void hitAnthor() = 0;

  /* �������� */
  virtual IGameElement* creatSelf(int nRow, int nCol) = 0;
};

#endif // IGAMEELEMENTHEADER
