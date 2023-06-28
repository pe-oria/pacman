#ifndef POSTIONHEADER
#define POSTIONHEADER
#pragma once
#include "game.h"

class CPostion
{
public:
  CPostion();
  CPostion(int nRow , int nCol);
  CPostion(CPostion& obj);
  ~CPostion();
  // ��ȡ��Ӧ��������
  int& operator[](int nIndex);
  // ���긳ֵ
  CPostion& operator=(CPostion& obj);
  // ������������ӣ�ֱ����ӣ�
  CPostion operator+(CPostion& obj);
  // ��ȡ������������������Ĳ�����Ǹ�ֵ��
  CPostion operator-(CPostion& obj);
  // ���������������
  CPostion operator*(int nNum);
  // �ж������Ƿ����
  int operator==(CPostion& obj);
  // �������꣨��ֹԽ�磩
  void amend();
  // ��������
  void set(int nRow , int nCol);
  // ��ȡ��������¸�����
  CPostion getActionPostion(int nAction);
  // ���ݷ����޸�����
  void changePostion(int nAction);

private:
  int m_nRow;
  int m_nCol;
};

#endif // POSTIONHEADER