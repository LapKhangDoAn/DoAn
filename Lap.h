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

struct NodeSP
{
	SanPham infor;
	NodeSP *pnext;
};

struct ListSP
{
	NodeSP *pHead;
	NodeSP *pTail;
};

void TaoDS(ListSP &DSSP);
void InDS(ListSP DSSP);
void InThongTin(ListSP DSSP);
void TimKiem(ListSP DSSP);
int RemoveX(ListSP &DSSP, char x[]);
void RemoveAfter(ListSP &DSSP);
void RemoveHead(ListSP &DSSP);
void AddHead(ListSP &DSSP, NodeSP *p);
NodeSP* SearchNode(ListSP &DSSP);
void InsertAfter(ListSP &DSSP, NodeSP *p, NodeSP *q, SanPham x);
void ThemSP(ListSP &DSSP);
void SapXep(ListSP DSSP);
void  ThoiTien(int&tong, int TienKhach);
void KiemTraHanSD1(ListSP DSSP);
int KiemTraHanSD2(ListSP DSSP, NodeSP *p, int &y, int &m, int &d);
void KiemTraHanSD3(ListSP DSSP);
void KiemTraHanSD(ListSP DSSP);
void textcolor(int x);