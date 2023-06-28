#ifndef CGAMEUIHEADER
#define CGAMEUIHEADER
#pragma once
#include "pacMan.h"

extern int isInitRefash;
extern int echoInfoisStatic;
class CGameUI
{
public:
  enum gameColor
  {
    colBlack = 0,
    colBlue,
    colGreen,
    colLightBlue,
    colRed,
    colPurple,
    colYellow,
    colWhite,
    colGray,
    colThinBlue,
    colThinGreen,
    colThinLightGreen,
    colThinRed,
    colThinPurple,
    colThinYellow,
    colLightWhite
  };

  // ����ģʽ��������
  SINGLE_INSTANCE_STAT(CGameUI);

  void echoMap(int nRow , int nCol , int nType);

  // �����Ϸ��Ϣ
  void echoGameInfo(int nScore, int nGhostLevel, int nPlayerLife);

  // ����Ϣ������ʾ��Ϣ
  void echoGameMessage(char* szBuff, int nTime = 1200);

  void echoMapByPrintf(int nRow , int nCol , int nType);

  void echoMapByApi(int nRow , int nCol , int nType);

  /*******************************
  �������ܣ���ӡ�ַ�������̨�ƶ�λ��
  High: �߶�X�У�����
  Wide: ���Y�У�����
  pszChar: ��ӡ���ַ�
  wArr: ��ӡ�ַ�������
  *******************************/
  void writeChar(int High , int Wide , char* pszChar , WORD wArr);
  
  /*********************************
  ��������: ���ô�����Ϣ
  *pszWindewTitle: ��������
  nY: ���ڸ߶ȣ�����
  nX: ���ڿ�ȣ�����
  �ɹ�����ֵ: true
  *********************************/
  bool setWindowSize(char *pszWindowTitle , int nY , int nX);
private:
  CGameUI();
  virtual ~CGameUI();

  char* m_elementStr[ CGame::itemPlayer + 1 ];
  int m_elementColor[ CGame::itemPlayer + 1 ];
};

// �������������
CREATE_SINGLE_OBJ(CGameUI);

#endif // CGAMEUIHEADER