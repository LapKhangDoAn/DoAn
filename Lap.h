#include <Windows.h>
#define max 100
typedef struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};

typedef struct SanPham
{
	char TenSP[max];
	char NhaCC[max];
	char Ma[max];
	int Sl;
	int GiaBan;
	Date NgaySX[max];
	Date HanSD[max];
};

struct Node
{
	SanPham infor;
	Node *pnext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

void TaoDS(List &DSSP);
void InDS(List DSSP);
void InThongTin(List DSSP);
void TimKiem(List DSSP);
int RemoveX(List&DSSP, char x[]);
void RemoveAfter(List &DSSP);
void RemoveHead(List&DSSP);
void AddHead(List&DSSP, Node *p);
Node* SearchNode(List &DSSP);
void InsertAfter(List&DSSP, Node *p, Node *q, SanPham x);
void ThemSP(List&DSSP);
void SapXep(List DSSP);
void  ThoiTien(int&tong, int TienKhach);
void KiemTraHanSD1(List DSSP);
int KiemTraHanSD2(List DSSP, Node *p, int &y, int &m, int &d);
void KiemTraHanSD3(List DSSP);
void KiemTraHanSD(List DSSP);
void textcolor(int x);