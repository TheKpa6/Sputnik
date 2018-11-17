	KillTimer(hWnd,IDT_TIMER);
	S.Sbros(S.v,S.alfa);
	GetClientRect(hWnd, &rt);
	InvalidateRect(hWnd,&rt,TRUE);
	EndPaint(hWnd, &ps);
	hdc = BeginPaint(hWnd, &ps);
	mr->Scale(hdc, rt);
	Brush=CreateSolidBrush(0x000000);// Цвет Фона
	FillRect(hdc, &rt,Brush);// Фон
	pen=CreatePen(PS_SOLID,10,0x0000ff);//цвет точки старта
	mr->MMoveTo(x,y);//Рисовка точки старта

	pen=CreatePen(PS_SOLID,1,0x00ff00);//цвет земли
	Brush=CreateHatchBrush(HS_DIAGCROSS,0x00ff00);//фон земли
	SelectObject(hdc,pen);
	SelectObject(hdc,Brush);
	Ellipse(hdc,mr->OutX(-Rz),mr->OutY(Rz),mr->OutX(Rz),mr->OutY(-Rz));
	DrawBitmap(hdc,hBitmap,200,183);//рисование картинки земли
	T=0;
	SetTimer(hWnd,IDT_TIMER,UINT(Shag*1000/S_vuvoda),NULL);
	pause=1;
	SendMessage(hDlgGrafic,WM_PAINT,0,0);