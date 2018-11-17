#include"stdafx.h"
#include"resource.h"
#include"MathRect.h"
#include<math.h>
#include<stdio.h>
#include"Kosmos.h"
#include<sys\types.h>
#include<sys\timeb.h>

#include"Global.h"	// Global Variables:

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_HELLO, szWindowClass, MAX_LOADSTRING);
	hBitmap = LoadBitmap(hInstance, (LPCTSTR)IDB_ZEMLA);
	BitSput = LoadBitmap(hInstance, (LPCTSTR)IDB_SPUTNIC);

	MyRegisterClass(hInstance);

	
	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_HELLO);
	// Main message loop:
	while(GetMessage(&msg, NULL, 0, 0))
	{
		if(hDlgModeless == 0 || !IsDialogMessage(hDlgModeless, &msg))
		{
			if(!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}
	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_HELLO);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_HELLO;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0,0, 600, 600, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

	hDlgGrafic=CreateDialog(hInst,(LPCTSTR) IDD_GRAFIC,hWnd, (DLGPROC)Grafic);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	hDlgModeless = CreateDialog(hInst,(LPCTSTR) IDD_MAIN_DLG,hWnd, (DLGPROC)Main_Dlg);
	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	mhwnd=hWnd;
	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_PUSK:
					KillTimer(hWnd,IDT_TIMER);
					SendMessage(hWnd,WM_PAINT,(WPARAM)0,(LPARAM)0);
					break;
				case ID_PARAM2:
					Shag=10;
					S_vuvoda=100;
					S.u=4;
					S.Sbros(1000,45);
					hBitmap=0;
					KillTimer(hWnd,IDT_TIMER);
					mr->Resize(S.x0-2000000,S.x0+2000000,S.y0-2000000,S.y0+2000000);
					//mr->Resize(S.x0-500000,S.x0+500000,S.y0-500000,S.y0+500000);
					SendMessage(hWnd,WM_PAINT,(WPARAM)0,(LPARAM)0);
					SendMessage(hDlgModeless,WM_INITDIALOG,(WPARAM)0,(LPARAM)0);
					break;
				case ID_PARAM3:
					Shag=100;
					S_vuvoda=100;
					S.u=10;
					S.c=3500;
					S.Sbros(1200,20);
					hBitmap = LoadBitmap(hInst, (LPCTSTR)IDB_ZEMLA);
					KillTimer(hWnd,IDT_TIMER);
					mr->Resize(-20000000,20000000,-20000000,20000000);
					SendMessage(hWnd,WM_PAINT,(WPARAM)0,(LPARAM)0);
					SendMessage(hDlgModeless,WM_INITDIALOG,(WPARAM)0,(LPARAM)0);
					break;
				case ID_PARAM4:
					Shag=100;
					S_vuvoda=10000;
					S.c=0;
					S.Sbros(7850,0);
					hBitmap = LoadBitmap(hInst, (LPCTSTR)IDB_ZEMLA);
					KillTimer(hWnd,IDT_TIMER);
					mr->Resize(-20000000,20000000,-20000000,20000000);
					SendMessage(hWnd,WM_PAINT,(WPARAM)0,(LPARAM)0);
					SendMessage(hDlgModeless,WM_INITDIALOG,(WPARAM)0,(LPARAM)0);
					break;
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_PARAM:
					if(hDlgModeless==0)	hDlgModeless = CreateDialog(hInst,(LPCTSTR) IDD_MAIN_DLG,hWnd, (DLGPROC)Main_Dlg);
					else SendMessage(hDlgModeless,WM_CLOSE,0,0);
					break;
				case IDM_GRAFIC:
					if(hDlgGrafic==0)	hDlgGrafic = CreateDialog(hInst,(LPCTSTR) IDD_GRAFIC,hWnd, (DLGPROC)Grafic);
					else SendMessage(hDlgGrafic,WM_CLOSE,0,0);
					break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_MBUTTONDOWN:
		//	sprintf(Speed,"x= %d; y=%d",LOWORD(lParam), HIWORD(lParam));
			sprintf(Speed,"x= %d; y=%d",mr->InX(LOWORD(lParam)), mr->InY(HIWORD(lParam)));
			MessageBox(hWnd,Speed, "Координаты мыши:", MB_OK);
			break;
		case WM_LBUTTONDOWN:
			mouse_x=LOWORD(lParam);
			mouse_y=HIWORD(lParam);
			break;
		case WM_LBUTTONUP:
			if(mouse_x<LOWORD(lParam)&&mouse_y<HIWORD(lParam))
			{
				mr->Resize(mr->InX(mouse_x),mr->InX(LOWORD(lParam)),mr->InY(HIWORD(lParam)),mr->InY(mouse_y));
				hBitmap=0;
				KillTimer(hWnd,IDT_TIMER);
				SendMessage(hWnd,WM_PAINT,0,0);
			}
			break;
		case WM_RBUTTONDOWN:
			KillTimer(hWnd,IDT_TIMER);
			hBitmap = LoadBitmap(hInst, (LPCTSTR)IDB_ZEMLA);
			mr->Resize(-20000000,20000000,-20000000,20000000);
			SendMessage(hWnd,WM_PAINT,0,0);
			break;
		case WM_PAINT:
			#include"wm_paint.h"
			break;
		case WM_TIMER:
			#include"wm_timer.h"
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;
		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
LRESULT CALLBACK Main_Dlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	BOOL succ;
	switch (message)
	{
		case WM_INITDIALOG:
			SetDlgItemInt(hDlg,IDC_X0,(S.x0-S.Rz)/1000,TRUE);
			SetDlgItemInt(hDlg,IDC_V0,S.v,TRUE);
			SetDlgItemInt(hDlg,IDC_A0,S.alfa,TRUE);
			SetDlgItemInt(hDlg,IDC_VUVOD,S_vuvoda,TRUE);
			SetDlgItemInt(hDlg,IDC_SHAG,Shag,TRUE);
			SetDlgItemInt(hDlg,IDC_M_T,S.m_r0,TRUE);
			SetDlgItemInt(hDlg,IDC_M_S,S.u,TRUE);
			SetDlgItemInt(hDlg,IDC_S_G,S.c,TRUE);
			S.GetAB(S.v,S.alfa);
			SendDlgItemMessage(hDlg,IDC_ERROR,BM_SETCHECK,(WPARAM)S.error,(LPARAM)0);
			SendDlgItemMessage(hDlg,IDC_SHAG_VREMA,BM_SETCHECK,(WPARAM)shag_vrema,(LPARAM)0);
			SetDlgItemInt(hDlg,IDC_A,S.A/1000,TRUE);
			SetDlgItemInt(hDlg,IDC_B,S.B/1000,TRUE);
			return TRUE;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
			case IDC_PAUSE:
				if(pause==0) {SetTimer(mhwnd,IDT_TIMER,Shag*1000/S_vuvoda,NULL); pause=1;}
				else {KillTimer(mhwnd,IDT_TIMER);pause=0;}
				break;
			case IDOK:
				S.v=GetDlgItemInt(hDlg,IDC_V0,&succ,TRUE);
				S.alfa=GetDlgItemInt(hDlg,IDC_A0,&succ,TRUE);
				S.x0=GetDlgItemInt(hDlg,IDC_X0,&succ,TRUE)*1000+S.Rz;
				S_vuvoda=GetDlgItemInt(hDlg,IDC_VUVOD,&succ,TRUE);
				Shag=GetDlgItemInt(hDlg,IDC_SHAG,&succ,TRUE);
				S.m_r0=GetDlgItemInt(hDlg,IDC_M_T,&succ,TRUE);
				S.u=GetDlgItemInt(hDlg,IDC_M_S,&succ,TRUE);
				S.c=GetDlgItemInt(hDlg,IDC_S_G,&succ,TRUE);
				shag_vrema=SendDlgItemMessage(hDlg,IDC_SHAG_VREMA,BM_GETCHECK,(WPARAM)0,(LPARAM)0);
				SendMessage(hDlgModeless,WM_INITDIALOG,0,0);
				SendMessage(mhwnd,WM_PAINT,0,0);
				return TRUE;
				break;
			case IDCANCEL:
				EndDialog(hDlg, LOWORD(wParam));
				hDlgModeless = 0;
				return TRUE;
				break;
			case IDC_ELIP:
				S.GetVAlfa(GetDlgItemInt(hDlg,IDC_A,&succ,TRUE)*1000,GetDlgItemInt(hDlg,IDC_B,&succ,TRUE)*1000);
				SendMessage(hDlgModeless,WM_INITDIALOG,0,0);
				SendMessage(mhwnd,WM_PAINT,0,0);
				return TRUE;
				break;
			}
			break;
		case WM_CLOSE:
			DestroyWindow(hDlg);
			hDlgModeless = 0;
			break;
	}
    return FALSE;
}
LRESULT CALLBACK Grafic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hGraf=GetDlgItem(hDlg, IDC_PAINT);	
	HWND hGrafSpeed=GetDlgItem(hDlg, IDC_PAINT_SPEED);	//Indificator objecta paint
	HWND hGrafEnergy=GetDlgItem(hDlg, IDC_PAINT_ENERGY);	//Indificator objecta paint
	HDC hdc,hdcSpeed,hdcEnergy;
	RECT rt,rtSpeed,rtEnergy;
	PAINTSTRUCT ps,psSpeed,psEnergy;
	HPEN pen,OldPen;
	HBRUSH Brush;
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;
		case WM_PAINT:
			EndPaint(hGraf, &ps);
			EndPaint(hGrafSpeed, &psSpeed);
			EndPaint(hGrafEnergy, &psEnergy);

			GetClientRect(hGraf, &rt);
			InvalidateRect(hGraf,&rt,TRUE);
			hdc = BeginPaint(hGraf, &ps);
			Brush=CreateSolidBrush(0xFFFFFF);
			FillRect(hdc, &rt,Brush);
			mrGrafic->Scale(hdc, rt);
			pen=CreatePen(PS_SOLID,1,0xff0000);
			OldPen=(HPEN)SelectObject(hdc,pen);
			mrGrafic->MMoveTo(0,sqrt(S.y*S.y+S.x*S.x));

			GetClientRect(hGrafSpeed, &rtSpeed);
			InvalidateRect(hGrafSpeed,&rtSpeed,TRUE);
			hdcSpeed = BeginPaint(hGrafSpeed, &psSpeed);
						FillRect(hdcSpeed, &rtSpeed,Brush);

			mrGraficSpeed->Scale(hdcSpeed, rtSpeed);
			SelectObject(hdcSpeed,pen);
			mrGraficSpeed->MMoveTo(0,sqrt(S.vx*S.vx+S.vy*S.vy));
			
			GetClientRect(hGrafEnergy, &rtEnergy);
			InvalidateRect(hGrafEnergy,&rtEnergy,TRUE);
			hdcEnergy = BeginPaint(hGrafEnergy, &psEnergy);
						FillRect(hdcEnergy, &rtEnergy,Brush);

			mrGraficEnergy->Scale(hdcEnergy, rtEnergy);
			SelectObject(hdcEnergy,pen);
			mrGraficEnergy->MMoveTo(0,mrGraficEnergy->WYmin);



			break;
		case WM_TIMER:
			mrGrafic->MLineTo(S.t,sqrt(S.y*S.y+S.x*S.x));
			mrGraficSpeed->MLineTo(S.t,sqrt(S.vx*S.vx+S.vy*S.vy));
			mrGraficEnergy->MLineTo(S.t,(-S.m_c*(S.vx*S.vx+S.vy*S.vy)/2+S.G_Mz*S.m_c/sqrt(S.x*S.x+S.y*S.y)));

			break;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
			case IDOK:
				return TRUE;
				break;
			case IDCANCEL:
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
				break;
			}
			break;
		case WM_CLOSE:
			EndPaint(hGraf, &ps);
			hDlgGrafic=0;
			DestroyWindow(hDlg);
			break;
	}
    return FALSE;
}