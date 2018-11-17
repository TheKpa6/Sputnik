#define MAX_LOADSTRING 100

HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// The title bar text
BOOL pause, shag_vrema=TRUE;
const double PI=3.14159;

MathRect *mr=new MathRect(-20000000,20000000,-20000000,20000000);
HWND mhwnd; // ** Дескриптор окна вывода
HWND hDlgModeless=0,hDlgModeless2=0,hDlgGrafic=0;
double T=0,Time_poleta=200000,S_vuvoda=1000,Shag=100,old_x,old_y;
Kosmos S(1200,20);
RECT rt;
PAINTSTRUCT ps;
HDC hdc;
HPEN pen; // Новое и старое перо
HBRUSH Brush,OldBrush;
double Rz=6.37E6,x=S.x0,y=S.y0;
char Speed[20];
timeb Vrema,OVrema;
int maxt=0;
int mouse_x,mouse_y;
HBITMAP hBitmap,BitSput;

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	Main_Dlg(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	Grafic(HWND, UINT, WPARAM, LPARAM);

MathRect *mrGrafic=new MathRect(0,200000,0,30000000);
MathRect *mrGraficSpeed=new MathRect(0,200000,0,20000);
MathRect *mrGraficEnergy=new MathRect(0,200000,0,2000000000);
void DrawBitmap(HDC hdc, HBITMAP hBitmap, int xStart, int yStart)
{
BITMAP bm;
HDC hdcMem;
POINT ptSize, ptOrg;
hdcMem = CreateCompatibleDC(hdc);
SelectObject(hdcMem, hBitmap);
SetMapMode(hdcMem, GetMapMode(hdc));
GetObject(hBitmap, sizeof(BITMAP),(LPVOID) &bm);
ptSize.x = bm.bmWidth;
ptSize.y = bm.bmHeight;
DPtoLP(hdc, &ptSize, 1);
ptOrg.x = 0;
ptOrg.y = 0;
DPtoLP(hdcMem, &ptOrg, 1);
BitBlt(hdc, xStart, yStart, ptSize.x, ptSize.y,hdcMem, ptOrg.x, ptOrg.y, SRCCOPY);
DeleteDC(hdcMem);
}