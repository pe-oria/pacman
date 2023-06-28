#pragma once
#include "pacMan.h"
#include "moveObj.h"

class CGhost :
  public CMoveObj
{
public:
  CGhost(int nRow, int nCol);
  virtual ~CGhost();
  virtual IGameElement* creatSelf(int nRow, int nCol);
  // ��ȡ����
  virtual const int getType();
  // ����־�ģʽ
  void toFear();

  void beHit();

  // ����ʱ�䣬������ʱ���Ƿ���ڶ����ٶ�
  int updateClock();
  // ��λ
  virtual void backPos();

  // ��ȡ��ʲô��ɫ�Ĺ�
  virtual int getWhatGhost();

private:
  int m_nWhatGhost;
};

