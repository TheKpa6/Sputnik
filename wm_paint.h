	KillTimer(hWnd,IDT_TIMER);
	S.Sbros(S.v,S.alfa);
	GetClientRect(hWnd, &rt);
	InvalidateRect(hWnd,&rt,TRUE);
	EndPaint(hWnd, &ps);
	hdc = BeginPaint(hWnd, &ps);
	mr->Scale(hdc, rt);
	Brush=CreateSolidBrush(0x000000);// ���� ����
	FillRect(hdc, &rt,Brush);// ���
	pen=CreatePen(PS_SOLID,10,0x0000ff);//���� ����� ������
	mr->MMoveTo(x,y);//������� ����� ������

	pen=CreatePen(PS_SOLID,1,0x00ff00);//���� �����
	Brush=CreateHatchBrush(HS_DIAGCROSS,0x00ff00);//��� �����
	SelectObject(hdc,pen);
	SelectObject(hdc,Brush);
	Ellipse(hdc,mr->OutX(-Rz),mr->OutY(Rz),mr->OutX(Rz),mr->OutY(-Rz));
	DrawBitmap(hdc,hBitmap,200,183);//��������� �������� �����
	T=0;
	SetTimer(hWnd,IDT_TIMER,UINT(Shag*1000/S_vuvoda),NULL);
	pause=1;
	SendMessage(hDlgGrafic,WM_PAINT,0,0);