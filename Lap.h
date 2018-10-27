
#define max 100
typedef struct DATE
{
	int ngay;
	int thang;
	int nam;
};

typedef struct SanPham
{
	char Ten_sp[max];
	char Nha_cc[max];
	char Ma[max];
	int Sl;
	int Gia_Ban;
	DATE Ngay_sx[max];
	DATE Han_sd[max];
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

void taoDS(List &DSSP);
void inDS(List DSSP);
void InThongTin(List DSSP);
void TimKiem(List DSSP);
int RemoveX(List&DSSP, char x[]);
void RemoveAfter(List &DSSP);
void RemoveHead(List&DSSP);
void addHead(List&DSSP, Node *p);
Node* searchNode(List &DSSP);
void InsertAfter(List&DSSP, Node *p, Node *q, SanPham x);
void ThemSP(List&DSSP);
void SapXep(List DSSP);
void  ThoiTien(int&tong, int TienKhach);
void KiemTraHanSD(List DSSP);