#include "stdafx.h"
#include "MathRect.h"
#include<math.h>
#include<stdio.h>

MathRect::MathRect(double x1,double x2,double y1,double y2)
{
WXmin=x1;
WXmax=x2;
WYmin=y1;
WYmax=y2;
}
void MathRect::Resize(double x1,double x2,double y1,double y2)
{
WXmin=x1;
WXmax=x2;
WYmin=y1;
WYmax=y2;
}
void MathRect::Header(char* txt,int x,int y=2)
{
TextOut(dc,x,y, txt, (int)strlen(txt));
}
void MathRect::Scale(HDC idc, RECT iR)
{ // Настройка на idc и область
dc=idc;
LM=RM=TM=BM=0; // Стандартный размер полей.
R0=iR;
R.left=R0.left+LM; // Установка полей
R.right=R0.right-RM;
R.top=R0.top+TM;
R.bottom=R0.bottom-BM;
mx=(R.right-R.left)/(WXmax-WXmin);
my=(R.top-R.bottom)/(WYmax-WYmin);
}
void MathRect::MMoveTo(double x,double y)
{ // Функция сдвига пера
	MoveToEx(dc,OutX(x),OutY(y),NULL);	
}
void MathRect::MLineTo(double x,double y)
{ // Функция прорисовки линии
	if(y>=WYmin&&y<=WYmax) LineTo(dc,OutX(x),OutY(y));
}
int MathRect::OutX(double x)
{ // Масштабируемый вывод x
return R.left+Okrug((x-WXmin)*mx);
}
int MathRect::OutY(double y)
{ // Масштабируемый вывод y
return R.bottom+Okrug((y-WYmin)*my);
}
double MathRect::InX(int x)
{
	return (x-R.left)/mx+WXmin;
}
double MathRect::InY(int y)
{
	return (y-R.bottom)/my+WYmin;
}

int MathRect::Okrug(double dd)
{
	if(dd>=0)
	{
		if(dd-int(dd)<0.5) return int(dd);
		else return int(dd)+1;
	}
	else
	{
		if(int(dd)-dd<0.5) return int(dd);
		else return int(dd)-1;
	}
}
