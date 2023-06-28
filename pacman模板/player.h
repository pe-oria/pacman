#pragma once
#include "pacMan.h"
#include "moveObj.h"

class CPlayer :
  public CMoveObj
{
public:
  CPlayer(int nRow, int nCol);
  virtual ~CPlayer();
  virtual IGameElement* creatSelf(int nRow, int nCol);
  int getScore();
  void setScore(int nScore);
  void addScore(int nScore);
  int getlife();
  void setlife(int nlife);
  
  virtual void CPlayer::beHit();
  
  // ����ʱ�䣬������ʱ���Ƿ���ڶ����ٶ�
  int updateClock();
  // ��λ
  virtual void backPos();

private:
  int m_nScore;
  int m_nlife;
};

