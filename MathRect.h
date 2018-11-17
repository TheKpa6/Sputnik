class MathRect  
{
public:

	HDC dc;
	RECT R0,R;
	double mx,my;
	int LM,RM,TM,BM;
	double WXmin,WXmax,WYmin,WYmax;

	MathRect(double x1,double x2,double y1,double y2);
	void Resize(double x1,double x2,double y1,double y2);
	void Header(char* txt,int x,int y);
	void Scale(HDC idc,RECT ir);
	void MMoveTo(double x,double y);
	void MLineTo(double x,double y);
	int OutX(double x);
	int OutY(double y);
	double InX(int x);
	double InY(int y);
	int Okrug(double dd);
};