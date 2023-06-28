#include "gameUI.h"

char* g_elementStr[ CGame::itemPlayer + 1 ] =
{"��", "��", "��", "  ", "  ", "��", "��", "��", "��", "��", "��", "��", "��", "��"};
int g_elementColor[ CGame::itemPlayer + 1 ] =
{
  CGameUI::colWhite * 16 + CGameUI::colYellow ,
  CGameUI::colWhite * 16 + CGameUI::colBlue ,
  CGameUI::colWhite * 16 + CGameUI::colThinYellow ,
  CGameUI::colWhite * 16 + CGameUI::colGray ,
  CGameUI::colWhite * 16 + CGameUI::colGray ,
  CGameUI::colWhite * 16 + CGameUI::colBlack ,
  CGameUI::colWhite * 16 + CGameUI::colThinRed   ,
  CGameUI::colWhite * 16 + CGameUI::colYellow,
  CGameUI::colWhite * 16 + CGameUI::colLightBlue  ,
  CGameUI::colWhite * 16 + CGameUI::colThinPurple,
  CGameUI::colWhite * 16 + CGameUI::colBlack ,
  CGameUI::colWhite * 16 + CGameUI::colBlack ,
  CGameUI::colWhite * 16 + CGameUI::colBlack ,
  CGameUI::colWhite * 16 + CGameUI::colThinYellow
};

int g_wallMap[ MAPROW ][ MAPCOL ] =
{
  2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
  1,9,9,9,9,9,9,9,9,9,9,9,9,2,3,9,9,9,9,9,9,9,9,9,9,9,9,1,
  1,9,2,0,0,3,9,2,0,0,0,3,9,1,1,9,2,0,0,0,3,9,2,0,0,3,9,1,
  1,9,1,6,6,1,9,1,6,6,6,1,9,1,1,9,1,6,6,6,1,9,1,6,6,1,9,1,
  1,9,4,0,0,5,9,4,0,0,0,5,9,4,5,9,4,0,0,0,5,9,4,0,0,5,9,1,
  1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,
  1,9,2,0,0,3,9,2,3,9,2,0,0,0,0,0,0,3,9,2,3,9,2,0,0,3,9,1,
  1,9,4,0,0,5,9,1,1,9,4,0,0,3,2,0,0,5,9,1,1,9,4,0,0,5,9,1,
  1,9,9,9,9,9,9,1,1,9,9,9,9,1,1,9,9,9,9,1,1,9,9,9,9,9,9,1,
  4,0,0,0,0,3,9,1,4,0,0,3,9,1,1,9,2,0,0,5,1,9,2,0,0,0,0,5,
  1,6,6,6,6,1,9,1,2,0,0,5,9,4,5,9,4,0,0,3,1,9,1,6,6,6,6,1,
  1,6,6,6,6,1,9,1,1,9,9,9,9,9,9,9,9,9,9,1,1,9,1,6,6,6,6,1,
  1,6,6,6,6,1,9,1,1,9,2,0,0,8,8,0,0,3,9,1,1,9,1,6,6,6,6,1,
  4,0,0,0,0,5,9,4,5,9,1,7,7,7,7,7,7,1,9,4,5,9,4,0,0,0,0,5,
  9,9,9,9,9,9,9,9,9,9,1,7,7,7,7,7,7,1,9,9,9,9,9,9,9,9,9,9,
  2,0,0,0,0,3,9,2,3,9,1,7,7,7,7,7,7,1,9,2,3,9,2,0,0,0,0,3,
  1,6,6,6,6,1,9,1,1,9,4,0,0,0,0,0,0,5,9,1,1,9,1,6,6,6,6,1,
  1,6,6,6,6,1,9,1,1,9,9,9,9,9,9,9,9,9,9,1,1,9,1,6,6,6,6,1,
  1,6,6,6,6,1,9,1,1,9,2,0,0,0,0,0,0,3,9,1,1,9,1,6,6,6,6,1,
  2,0,0,0,0,5,9,4,5,9,4,0,0,3,2,0,0,5,9,4,5,9,4,0,0,0,0,3,
  1,9,9,9,9,9,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,9,9,9,9,9,1,
  1,9,2,0,0,3,9,2,0,0,0,3,9,1,1,9,2,0,0,0,3,9,2,0,0,3,9,1,
  1,9,4,0,3,1,9,4,0,0,0,5,9,4,5,9,4,0,0,0,5,9,1,2,0,5,9,1,
  1,9,9,9,1,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,1,9,9,9,1,
  4,0,3,9,1,1,9,2,3,9,2,0,0,0,0,0,0,3,9,2,3,9,1,1,9,2,0,5,
  2,0,5,9,4,5,9,1,1,9,4,0,0,3,2,0,0,5,9,1,1,9,4,5,9,4,0,3,
  1,9,9,9,9,9,9,1,1,9,9,9,9,1,1,9,9,9,9,1,1,9,9,9,9,9,9,1,
  1,9,2,0,0,0,0,5,4,0,0,3,9,1,1,9,2,0,0,5,4,0,0,0,0,3,9,1,
  1,9,4,0,0,0,0,0,0,0,0,5,9,4,5,9,4,0,0,0,0,0,0,0,0,5,9,1,
  1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,
  4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5
};
// 0 �Mǽ 1 ��ǽ 2 ���Ͻ� 3 ���Ͻ� 4 ���½� 5 ���½� 6 ��ǽ 7 ����� 8 ����� 9 ����
// char* g_wall[ 9 ] = { "һ", "��", "�q", "�r", "�t", "�s", "  ", "  ", "һ"};
char* g_wall[ 9 ] = { "һ", "��", "��", "��", "��", "��", "  ", "  ", "һ"};

// ����ģʽ��������
SINGLE_INSTANCE(CGameUI);

CGameUI::CGameUI()
{
  setWindowSize("pacMan - KevinsBobo" , g_nMapRow , (g_nMapCol + 10) * 2);

  for(int nRow = 0; nRow < g_nMapRow + 1; ++nRow)
  {
    for(int nCol = 0; nCol <= g_nMapCol + 10; ++nCol)
    {
      writeChar( nRow, nCol , "  " , CGameUI::colWhite * 16);
    }
  }

  memcpy_s(m_elementStr , sizeof(m_elementStr) , g_elementStr , sizeof(g_elementStr));
  memcpy_s(m_elementColor , sizeof(m_elementColor) , g_elementColor , sizeof(g_elementColor));
}


CGameUI::~CGameUI()
{
}

void CGameUI::echoMap(int nRow , int nCol , int nType)
{
  echoMapByApi(nRow , nCol , nType);
}

// �����Ϸ��Ϣ
int echoInfoisStatic = 0;
void CGameUI::echoGameInfo(int nScore , int nGhostLevel , int nPlayerLife)
{
  static int nPreScore = nScore;
  static int nPreGhostLevel = nGhostLevel;
  static int nPrePlayerLife = nPlayerLife;
  char szBuff[ 0x20 ] = { 0 };

  int textColor = CGameUI::colWhite * 16 + CGameUI::colBlack;

  if(echoInfoisStatic == 0)
  {
    echoInfoisStatic = 1;

    sprintf_s(szBuff , 0x20 , "������%d    " , nScore);
    writeChar( 1, g_nMapCol + 1 , szBuff , textColor);
    sprintf_s(szBuff , 0x20 , "�Ѷȣ�%d    " , nGhostLevel);
    writeChar( 4, g_nMapCol + 1 , szBuff , textColor);
    sprintf_s(szBuff , 0x20 , "������%d    " , nPlayerLife);
    writeChar( g_nMapRow - 2, g_nMapCol + 1 , szBuff , textColor);
  }
  else
  {
    if(nScore != nPreScore)
    {
      nPreScore = nScore;
      sprintf_s(szBuff , 0x20 , "������%d    " , nScore);
      writeChar( 1, g_nMapCol + 1 , szBuff , textColor);
    }
    if(nGhostLevel != nPreGhostLevel)
    {
      nPreGhostLevel = nGhostLevel;
      sprintf_s(szBuff , 0x20 , "�Ѷȣ�%d    " , nGhostLevel);
      writeChar( 4, g_nMapCol + 1 , szBuff , textColor);
    }
    if(nPlayerLife != nPreGhostLevel)
    {
      nPrePlayerLife = nPlayerLife;
      sprintf_s(szBuff , 0x20 , "������%d    " , nPlayerLife);
      writeChar( g_nMapRow - 2, g_nMapCol + 1 , szBuff , textColor);
    }
  }
}

// ����Ϣ������ʾ��Ϣ
void CGameUI::echoGameMessage(char* szBuff, int nTime)
{
  int textColor = CGameUI::colWhite * 16 + CGameUI::colBlack;
  int nMassageBoxRow = 16;
  int nMassageBoxCol = g_nMapCol + 1;


  writeChar( nMassageBoxRow, nMassageBoxCol , szBuff , textColor);

  Sleep(nTime);

  writeChar( nMassageBoxRow, nMassageBoxCol , "                  " , textColor);

}

void CGameUI::echoMapByPrintf(int nRow , int nCol , int nType)
{
  printf("%s" , m_elementStr[ nType ]);
  if(nCol == g_nMapCol - 1)
  {
    printf("\n");
  }
}

int isInitRefash = 0;
void CGameUI::echoMapByApi(int nRow , int nCol , int nType)
{
  // ֻˢ��һ��
  static int nMoveObjPreRow[ NPLAYER + NGHOST ] = { 0 };
  static int nMoveObjPreCol[ NPLAYER + NGHOST ] = { 0 };
  static int nMoveObjNowRow[ NPLAYER + NGHOST ] = { 0 };
  static int nMoveObjNowCol[ NPLAYER + NGHOST ] = { 0 };
  static int isMoved[ NPLAYER + NGHOST ] = { 0 };
  static int nTemp = 0;

  // ��־�״̬����ǰ����˸
  static int* ghostColor = g_elementColor + CGame::itemGhoRed;
  static clock_t nowTime = 0;
  static clock_t flashTime = 400;
  static clock_t startTime = 2400;
  static clock_t passTime = 0;

  // �Ż�ǽ����ʾ
  char* pWallBuff = NULL;

  static int i = 0;
  // ˢ�¶�����̬Ԫ�أ�ֻˢһ��
  if(isInitRefash < g_nMapRow * g_nMapCol + g_nPlayer + g_nGhost)
  {
    if(nType == CGame::itemWall)
    {
      // ���ǽ�����⴦��
      pWallBuff = g_wall[ g_wallMap[ nRow ][ nCol ] ];
      writeChar(nRow , nCol , pWallBuff , m_elementColor[ nType ]);
    }
    else if(nType == CGame::itemGhoHome)
    {
      // ��Թ��ݵ����⴦��
      pWallBuff = g_wall[ g_wallMap[ nRow ][ nCol ] ];
      writeChar(nRow , nCol , pWallBuff , CGameUI::colWhite * 16 + CGameUI::colLightBlue);
    }
    else
    {
      // ����Ԫ��
      writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
    }
    ++isInitRefash;
  }
  // ��ˢ�¶�̬Ԫ�أ�ֻˢһ��
  else if(isInitRefash < g_nMapRow * g_nMapCol + g_nGhost + g_nPlayer)
  {
    writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
    nMoveObjNowRow[ i ] = nRow;
    nMoveObjNowCol[ i ] = nCol;
    nMoveObjPreRow[ i ] = nRow;
    nMoveObjPreCol[ i ] = nCol;

    ++i;
    ++isInitRefash;
    if(i >= g_nGhost + g_nPlayer)
    {
      i = 0;
    }
  }
  // ֻ��Ա仯����Ԫ�ؽ���ˢ��
  else
  {
    // ��̬Ԫ��
    if(nType >= CGame::itemGhoNormal && nType <= CGame::itemPlayer)
    {
      // ����ƶ��˾ͼ�¼��֮ǰ����������ڵ�����
      if(nMoveObjNowRow[ i ] != nRow || nMoveObjNowCol[ i ] != nCol)
      {
        nTemp = nMoveObjPreRow[i];
        nMoveObjPreRow[i] = nMoveObjNowRow[i];
        nMoveObjNowRow[i] = nTemp;
        
        nTemp = nMoveObjPreCol[i];
        nMoveObjPreCol[i] = nMoveObjNowCol[i];
        nMoveObjNowCol[i] = nTemp;
        
        nMoveObjNowRow[ i ] = nRow;
        nMoveObjNowCol[ i ] = nCol;
        isMoved[ i ] = 1;

        // ��ˢһ�Σ���ֹ����
        writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
      }
      // ���û���ƶ����������Ԫ��
      // Ҳ���ǻᶯ��Ԫ��ֻ�����ƶ����һɲ�ǲ���ˢ�£�
      // ������һɲ��������û���ƶ�����Ԫ�أ��Ͳ���ˢ��������Ļ
      else
      {
        // ��Թ��Ҫ�����־�״̬ǰ������˸����
        if(nType == CGame::itemGhoFear )
        {
          nowTime = clock();
          passTime = nowTime - g_nFearStartTime - g_nGhostFearTime + startTime;
          if(passTime >= 0 && (passTime % (flashTime * 2)) <= flashTime)
          {
            writeChar(nRow , nCol , m_elementStr[ nType ] , ghostColor[i]);
          }
          else
          {
            writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
          }
        }
        // ����Ԫ������ˢ
        else
        {
          writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
        }
        isMoved[ i ] = 0;
      }

      // ����
      ++i;
      if(i >= g_nGhost + g_nPlayer)
      {
        i = 0;
      }
    }
    // ��̬Ԫ��
    else
    {
      for(int j = 0; j < g_nGhost + g_nPlayer; ++j)
      {
        // �����Ƿ�Ϊ��̬Ԫ���Ƿ��ƶ�������ƶ���ˢ�����ƶ�ǰ��λ��Ԫ�еľ�̬Ԫ��
        if(isMoved[ j ] == 1 && nRow == nMoveObjPreRow[ j ] && nCol == nMoveObjPreCol[ j ])
        {
          // ��Թ�����Ĵ���
          if(nType == CGame::itemGhoHome)
          {
            pWallBuff = g_wall[ g_wallMap[ nRow ][ nCol ] ];
            writeChar(nRow , nCol , pWallBuff , CGameUI::colWhite * 16 + CGameUI::colLightBlue);
          }
          // ����Ԫ������ˢ
          else
          {
            writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
          }
          isMoved[ j ] = 0;
          break;
        }
      }
    }
  }

}

void CGameUI::writeChar(int High , int Wide , char* pszChar , WORD wArr){
	CONSOLE_CURSOR_INFO cii;
	cii.dwSize = 1;
	cii.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE) , &cii);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , loc);
	printf(pszChar);
}

bool CGameUI::setWindowSize(char *pszWindowTitle  , int nY, int nX){
	// Title
	SetConsoleTitleA(pszWindowTitle);
	HANDLE hStdin , hStdOut;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// get max console window size
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD BufferSize = { pos.X + 1 , pos.Y + 1 };
	// set console buffer size
	if(!SetConsoleScreenBufferSize(hStdOut , BufferSize)){
		// set console buffer size false
		printf("buffer err(%d,%d)%d\n" , BufferSize.X , BufferSize.Y , GetLastError());
		return false;
	}
	SMALL_RECT srctWindow = { 0 , 0 , nX , nY };
	if(!SetConsoleWindowInfo(hStdOut , true , &srctWindow)){
		// set console window size false
		printf("size err %d\n" , GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1 , nY + 1 };
	// set console buffer size
	if(!SetConsoleScreenBufferSize(hStdOut , Buffer)){
		// set console buffer size false
		printf("buffer err(%d, %d)%d\n" , BufferSize.X , BufferSize.Y , GetLastError());
		return false;
	}
	return true;
}

// �������������
CREATE_SINGLE_OBJ_REALIZE(CGameUI);