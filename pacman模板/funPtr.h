#ifndef FUNPTRHEADER
#define FUNPTRHEADER
#pragma once

/* ����ָ�� */

class IGameElement;
/* ���ഴ������ĺ���ָ�� */
typedef IGameElement* (IGameElement::*creatSelf)(int, int);

class CGameUI;
/* ����̨������� */
typedef void (CGameUI::*echoMapElement)(int , int , int);

#endif // FUNPTRHEADER