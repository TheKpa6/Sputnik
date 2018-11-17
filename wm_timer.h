if(T<=Time_poleta)
{
	old_x=S.x; old_y=S.y;//запомнить старые координаты
	pen=CreatePen(PS_SOLID,5,0x000000);
	SelectObject(hdc,pen);
	mr->MLineTo(S.x,S.y);//закрасить старую точку
	if(shag_vrema==TRUE) S.Next(T);
	else S.NextR(Shag*10000);
	pen=CreatePen(PS_SOLID,1,0xFFFFFF);// цвет траектории
	if(S.t<S.m_r0/S.u) 	pen=CreatePen(PS_SOLID,1,0x000000);// цвет траектории во время работы двигателя
	SelectObject(hdc,pen);
	mr->MMoveTo(old_x,old_y);//рисование траектории
	mr->MLineTo(S.x,S.y);
	pen=CreatePen(PS_SOLID,5,0x0000ffff);//рисование спутника
	SelectObject(hdc,pen);
	mr->MLineTo(S.x,S.y);

//	DrawBitmap(hdc,BitSput,mr->OutX(S.x)-3,mr->OutY(S.y)-3);
	//заполнение полей в диалоге
	sprintf(Speed,"%d",int(sqrt(S.x*S.x+S.y*S.y)/1000));
	SetDlgItemTextA(hDlgModeless,IDC_RADIUS,Speed);
	sprintf(Speed,"%d",int(sqrt(S.vx*S.vx+S.vy*S.vy)));
	SetDlgItemTextA(hDlgModeless,IDC_V,Speed);
	sprintf(Speed,"%f",(-S.m_c*(S.vx*S.vx+S.vy*S.vy)/2+S.G_Mz*S.m_c/sqrt(S.x*S.x+S.y*S.y)));
	SetDlgItemTextA(hDlgModeless,IDC_ENERGY,Speed);
	SendMessage(hDlgGrafic,WM_TIMER,0,0);
	/*	ftime(&Vrema);
	if(Vrema.millitm-OVrema.millitm>maxt) maxt=Vrema.millitm-OVrema.millitm;
	sprintf(Speed,"%d",Vrema.millitm-OVrema.millitm);
	mr->Header(Speed,290,50);
	ftime(&OVrema);
	*/
	T+=Shag;
}
else
{
/*	S.GetAB(S.v,S.alfa);
	sprintf(Speed,"%d",int(S.A));
	mr->Header(Speed,200,2);
	sprintf(Speed,"%d",int(S.B));
	mr->Header(Speed,290,2);
	sprintf(Speed,"%d",maxt);
	mr->Header(Speed,290,50);
*/
	/*Beep(800, 2000);
	KillTimer(hWnd,IDT_TIMER);
	pause=0;
	DeleteObject(pen);
	EndPaint(hWnd, &ps);
	*/
}