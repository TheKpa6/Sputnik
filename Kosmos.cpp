#include"stdafx.h"
#include<math.h>
#include <cmath>
#include"Kosmos.h"
//
Kosmos::Kosmos(double v_,double a_)
{
	v=v_;
	alfa=a_;
	vx=v*sin(alfa*3.1415/180);
	vy=v*cos(alfa*3.1415/180);
	G=6.672E-11;
	Mz=5.98E24;
	Rz=6.37E6;
	x0=100000+Rz;
	y0=0;
	m_r0=1000;
	m_c=100;
	u=10;
	c=3500;
	dt=0.1;
	x=x0;
	y=y0;
	G_Mz=G*Mz;
}
void Kosmos::Sbros(double v_,double a_)
{
	v=v_;
	alfa=a_;
	vx=v*sin(alfa*3.1415/180);
	vy=v*cos(alfa*3.1415/180);
	t=0;
	x=x0;
	y=y0;
}

void Kosmos::Next(double T)
{
	double k1x,k2x,k3x,k4x,k1y,k2y,k3y,k4y;
	while(T>t)
	{
		k1x=f(t,x,y,vx,vy)*dt;
		k1y=g(t,x,y,vx,vy)*dt;
		k2x=f(t+dt/2,x+vx*dt/2,y+vy*dt/2,vx+k1x/2,vy+k1y/2)*dt;
		k2y=g(t+dt/2,x+vx*dt/2,y+vy*dt/2,vx+k1x/2,vy+k1y/2)*dt;
		k3x=f(t+dt/2,x+vx*dt/2+k1x/4*dt,y+vy*dt/2+k1y/4*dt,vx+k2x/2,vy+k2y/2)*dt;
		k3y=g(t+dt/2,x+vx*dt/2+k1x/4*dt,y+vy*dt/2+k1y/4*dt,vx+k2x/2,vy+k2y/2)*dt;
		k4x=f(t+dt,x+vx*dt+k2x/2,y+vy*dt+k2y/2,vx+k3x,vy+k3y)*dt;
		k4y=g(t+dt,x+vx*dt+k2x/2,y+vy*dt+k2y/2,vx+k3x,vy+k3y)*dt;
		x+=vx*dt+(k1x+k2x+k3x)/6*dt;
		vx+=(k1x+k2x+k2x+k3x+k3x+k4x)/6;
		y+=vy*dt+(k1y+k2y+k3y)/6*dt;
		vy+=(k1y+k2y+k2y+k3y+k3y+k4y)/6;
		t+=dt;
	}
}
void Kosmos::NextR(double DR)
{
	double k1x,k2x,k3x,k4x,k1y,k2y,k3y,k4y,xnew,ynew,dr=0;
	while(DR>dr)
	{
		k1x=f(t,x,y,vx,vy)*dt;
		k1y=g(t,x,y,vx,vy)*dt;
		k2x=f(t+dt/2,x+vx*dt/2,y+vy*dt/2,vx+k1x/2,vy+k1y/2)*dt;
		k2y=g(t+dt/2,x+vx*dt/2,y+vy*dt/2,vx+k1x/2,vy+k1y/2)*dt;
		k3x=f(t+dt/2,x+vx*dt/2+k1x/4*dt,y+vy*dt/2+k1y/4*dt,vx+k2x/2,vy+k2y/2)*dt;
		k3y=g(t+dt/2,x+vx*dt/2+k1x/4*dt,y+vy*dt/2+k1y/4*dt,vx+k2x/2,vy+k2y/2)*dt;
		k4x=f(t+dt,x+vx*dt+k2x/2,y+vy*dt+k2y/2,vx+k3x,vy+k3y)*dt;
		k4y=g(t+dt,x+vx*dt+k2x/2,y+vy*dt+k2y/2,vx+k3x,vy+k3y)*dt;
		xnew=vx*dt+(k1x+k2x+k3x)/6*dt;
		ynew=vy*dt+(k1y+k2y+k3y)/6*dt;
		dr+=sqrt((xnew)*(xnew)+(ynew)*(ynew));
		x+=xnew; y+=ynew;
		vx+=(k1x+k2x+k2x+k3x+k3x+k4x)/6;
		vy+=(k1y+k2y+k2y+k3y+k3y+k4y)/6;
		t+=dt;
	}
}
void Kosmos::GetAB(double v_,double a_)
{
	error=false;
	double oldt=t,oldx=x,oldy=y,oldvx=vx,oldvy=vy;
	vx=v_*sin(a_*3.1415/180);
	vy=v_*cos(a_*3.1415/180);
	t=0;
	x=x0;
	y=y0;
	double radius,max_radius=0,min_radius,x0=x,y0=y;
	min_radius=sqrt(x*x+y*y);
	while(!(x>=x0-1000000&&x<=x0+1000000&&y>=y0-1000000&&y<=y0+1000000)||t<2000)
	{
		radius=sqrt(x*x+y*y);
		if(radius>100000000||radius<10000||t>1000000)
		{
			A=0;
			B=0;
		t=oldt;x=oldx;y=oldy;vx=oldvx;vy=oldvy;
		return;
		}
		if(max_radius<radius) max_radius=radius;
		if(min_radius>radius) min_radius=radius;
		if(radius<Rz) error=true;
		Next(t+dt);
	}

	A=(max_radius+min_radius)/2;
	C=(max_radius-min_radius)/2;
	B=sqrt(A*A-C*C);
	t=oldt;x=oldx;y=oldy;vx=oldvx;vy=oldvy;

}


double Kosmos::f(double t,double x,double y,double vx,double vy)
{
	if(t>=m_r0/u) return -G_Mz*x/(x*x+y*y)/sqrt(x*x+y*y);
	else return -G_Mz*x/(x*x+y*y)/sqrt(x*x+y*y)+u*c*vx/sqrt(vx*vx+vy*vy)/(m_r0-u*t+m_c);
}
double Kosmos::g(double t,double x,double y,double vx,double vy)
{
	if(t>=m_r0/u) return -G_Mz*y/(x*x+y*y)/sqrt(x*x+y*y);
	else return -G_Mz*y/(x*x+y*y)/sqrt(x*x+y*y)+u*c*vy/sqrt(vx*vx+vy*vy)/(m_r0-u*t+m_c);
}
void Kosmos::GetVAlfa(double a_, double b_)
{
	struct radius
	{
		double v;
		double al;
	};
	radius r0 = { 1000, 10 }, r1 = { 1800, 25 }, r2 = { 1200, 35 }, rr = { 0, 0 };
	double g0, g1, g2, gg, ras0, ras1, ras2;
	double f10, f11, f12, f20, f21, f22;
	while (abs(A - a_) + abs(B - b_)>10000)
	{
		GetAB(r0.v, r0.al);
		f10 = A - a_;
		f20 = B - b_;
		GetAB(r1.v, r1.al);
		f11 = A - a_;
		f21 = B - b_;
		GetAB(r2.v, r2.al);
		f12 = A - a_;
		f22 = B - b_;
		g0 = f11*f22 - f12*f21;
		g1 = -f10*f22 + f12*f20;
		g2 = -f11*f20 + f10*f21;
		gg = g0 + g1 + g2;
		rr.v = (g0*r0.v + g1*r1.v + g2*r2.v) / gg;
		rr.al = (g0*r0.al + g1*r1.al + g2*r2.al) / gg;
		GetAB(rr.v, rr.al);
		ras0 = sqrt((rr.v - r0.v)*(rr.v - r0.v) + (rr.al - r0.al)*(rr.al - r0.al));
		ras1 = sqrt((rr.v - r1.v)*(rr.v - r1.v) + (rr.al - r1.al)*(rr.al - r1.al));
		ras2 = sqrt((rr.v - r2.v)*(rr.v - r2.v) + (rr.al - r2.al)*(rr.al - r2.al));
		if (ras0>ras1)
		{
			if (ras0>ras2) r0 = rr;
			else r2 = rr;
		}
		else
		{
			if (ras1>ras2) r1 = rr;
			else r2 = rr;
		}
	}
	if (rr.v != 0) Sbros(rr.v, rr.al);
	else Sbros(v, alfa);
}