#include"stdafx.h"
#include<math.h>

class Kosmos
{
public:

	double G,Mz,Rz,m_r0,m_c,u,c,x0,y0;
	double t,dt,x,y,v,alfa,vx,vy;
	double A,B,C;
	double G_Mz;
	bool error;
	void GetVAlfa(double a_,double b_);
	void Next(double T);
	void NextR(double DR);
	Kosmos(double v_,double a_);
	void Sbros(double v_,double a_);
	void GetAB(double v_,double a_);

private:

	double f(double t,double x,double y,double vx,double vy);
	double g(double t,double x,double y,double vx,double vy);
};