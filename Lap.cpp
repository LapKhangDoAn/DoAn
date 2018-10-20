#include "pch.h"
#include "DoAn.h"

void taoDS(List &DSSP)
{
	DSSP.pHead = NULL;
	DSSP.pTail = NULL;
}
void InHoaDon(ListSPDB DSSPDB)
{
	int w = 140;
	int tong = 0;
	ThongTinHoaDon(DSSPDB);
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	NodeSPDB *p = DSSPDB.pHead;
	while (p != NULL)
	{
		cout << setw(40) << left << p->infor.Ten_spdb << setw(40) << p->infor.Sldb << setw(40) << p->infor.Gia_Bandb << setw(40) << p->infor.Gia_Bandb*p->infor.Sldb << endl;
		tong = tong + p->infor.Gia_Bandb*p->infor.Sldb;
		p = p->pnext;
	}
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw((w - 20) / 2) << " " << "Tong cong:" << tong << " VND" << endl;
}
void ThongTinHoaDon(ListSPDB DSSPDB)
{
	int w = 140;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw((w - 20) / 2) << " " << "Hoa Don Mua Hang" << endl;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw(40) << left << "Ten san pham";
	cout << setw(40) << "So luong" << setw(40) << "Gia ban san pham" << setw(40) << "Thanh tien" << endl;
}
void ThemSP(List&DSSP)
{
	int them = 1;
	while (them == 1)
	{
		cout << "Nhap thong tin san pham can them:" << endl;
		SanPham x = nhapSP();
		cout << "1.Them san pham vao dau danh sach" << endl;
		cout << "2.Them san pham B vào sau san pham A co trong danh sach" << endl;
		cout << "3.Them san pham vao cuoi danh sach" << endl;
		int chon;
		cin >> chon;
		if (chon == 1)
		{
			Node *q = createNode(x);
			addHead(DSSP, x, q);
		}
		if (chon == 2)
		{
			Node *q = createNode(x);
			Node *p = searchNode(DSSP);
			InsertAfter(DSSP, p, q, x);
		}
		if (chon == 3)
		{
			Node *q = createNode(x);
			addTail(DSSP, x);
		}
		cout << "Nhap 1 de them tiep,0 de ket thuc:";
		cin >> them;
	}
}
void InsertAfter(List&DSSP, Node *p, Node *q, SanPham x)
{
	if (p != NULL)
	{
		q->pnext = p->pnext;
		p->pnext = q;
		if (DSSP.pTail == p)
			DSSP.pTail = q;
	}
	else
		addHead(DSSP, x, q);
}
Node* searchNode(List &DSSP)
{
	Node* p;
	p = DSSP.pHead->pnext;
	cin.ignore();
	char a[100];
	cout << "Nhap ma san pham A de them san pham B vao sau :";
	cin.getline(a, 100);
	while (p != NULL && strcmp(a, p->infor.Ma) != 0)
		p = p->pnext;
	return p;
}
void addHead(List&DSSP, SanPham x, Node *p)
{
	if (DSSP.pHead == NULL)
	{
		DSSP.pHead = p;
		DSSP.pTail = p;
	}
	else
	{
		p->pnext = DSSP.pHead;
		DSSP.pHead = p;
	}
}
// Xóa Sản Phẩm
int RemoveX(List&DSSP, char x[])
{
	Node *p;
	p = DSSP.pHead;
	Node *q = new Node;
	int dem = 0;
	if (DSSP.pHead == NULL)
		return 0;
	if (strcmp(x, DSSP.pHead->infor.Ma) == 0)
	{
		RemoveHead(DSSP);
		return 1;
	}
	if (strcmp(x, DSSP.pTail->infor.Ma) == 0)
	{
		RemoveAfter(DSSP);
		return 1;
	}
	while (p != NULL)
	{
		if (strcmp(x, p->infor.Ma) == 0)
		{
			q->pnext = p->pnext;
			delete p;
			return 1;
		}
		q = p;
		p = p->pnext;
	}
	return 0;
}
void RemoveAfter(List &DSSP)
{
	Node *p;
	p = DSSP.pHead;
	if (DSSP.pHead == NULL)
		return;
	if (DSSP.pHead->pnext == NULL)
	{
		RemoveHead(DSSP);
		return;
	}
	while (p != NULL)
	{
		if (p->pnext == DSSP.pTail)
		{
			delete DSSP.pTail;
			p->pnext = NULL;
			DSSP.pTail = p;
			return;
		}
		p = p->pnext;
	}
}
void RemoveHead(List&DSSP)
{
	if (DSSP.pHead == NULL)
		return;
	Node *p = DSSP.pHead;
	DSSP.pHead = DSSP.pHead->pnext;
	delete p;
}
void TimKiem(List DSSP)
{
	int w = 130;
	Node *p;
	SanPham x;
	int dem = 0;
	int chon;
	cout << "Danh muc tim kiem:" << endl;
	cout << "1. Tim kiem theo ten san pham" << endl;
	cout << "2. Tim kiem theo ma san pham" << endl;
	cout << "3. Tim kiem theo khoang gia" << endl;
	cin >> chon;
	if (chon == 1)
	{
		cin.ignore();
		cout << "Nhap Ten San Pham Can Tim Kiem:";
		cin.getline(x.Ten_sp, 100);
		p = DSSP.pHead;
		while (p != NULL)
		{
			if (strcmp(x.Ten_sp, p->infor.Ten_sp) == 0)
			{
				dem++;
				if (dem == 1)
					inDS(DSSP);
				cout << setw(20) << left << p->infor.Ten_sp << setw(20) << p->infor.Ma << setw(20) << p->infor.Gia_Ban << setw(20) << p->infor.Sl << setw(20) << p->infor.Nha_cc << setw(20) << p->infor.Ngay_sx << setw(20) << p->infor.Han_sd << endl;
			}
			p = p->pnext;
		}
		if (dem == 0)
			cout << "San Pham Can Tim Khong Co Trong Cua Hang";
	}
	if (chon == 2)
	{
		cin.ignore();
		cout << "Nhap Ma San Pham Can Tim Kiem:";
		cin.getline(x.Ma, 100);
		p = p = DSSP.pHead;
		while (p != NULL)
		{
			if (strcmp(x.Ma, p->infor.Ma) == 0)
			{
				dem++;
				if (dem == 1)
					inDS(DSSP);
				cout << setw(20) << left << p->infor.Ten_sp << setw(20) << p->infor.Ma << setw(20) << p->infor.Gia_Ban << setw(20) << p->infor.Sl << setw(20) << p->infor.Nha_cc << setw(20) << p->infor.Ngay_sx << setw(20) << p->infor.Han_sd << endl;
			}
			p = p->pnext;
		}
		if (dem == 0)
			cout << "San Pham Can Tim Khong Co Trong Cua Hang";
	}
	if (chon == 3)
	{
		cin.ignore();
		double mingia, maxgia;
		cout << "Nhap gia thap nhat:";
		cin >> mingia;
		cout << "Nhap gia cao nhat:";
		cin >> maxgia;
		Node* p;
		p = DSSP.pHead;
		while (p != NULL && (mingia <= p->infor.Gia_Ban && p->infor.Gia_Ban <= maxgia))
		{
			dem++;
			if (dem == 1)
				inDS(DSSP);
			cout << setw(20) << left << p->infor.Ten_sp << setw(20) << p->infor.Ma << setw(20) << p->infor.Gia_Ban << setw(20) << p->infor.Sl << setw(20) << p->infor.Nha_cc << setw(20) << p->infor.Ngay_sx << setw(20) << p->infor.Han_sd << endl;
			p = p->pnext;
		}
		if (dem == 0)
			cout << "San Pham Can Tim Khong Co Trong Cua Hang" << endl;
	}

}
void InThongTin(List DSSP)
{
	int w = 140;
	inDS(DSSP);
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	Node *p = DSSP.pHead;
	while (p != NULL)
	{
		cout << setw(20) << left << p->infor.Ten_sp << setw(20) << p->infor.Ma << setw(20) << p->infor.Gia_Ban << setw(20) << p->infor.Sl << setw(20) << p->infor.Nha_cc << setw(20) << p->infor.Ngay_sx << setw(20) << p->infor.Han_sd << endl;
		p = p->pnext;
	}
}
void inDS(List DSSP)
{
	int w = 140;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw((w - 20) / 2) << left << " " << "THONG TIN CAC SAN PHAM" << endl;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw(20) << "Ten san pham";
	cout << setw(20) << "Ma san pham" << setw(20) << "Gia ban san pham" << setw(20) << "So luong" << setw(20) << "Nha cung cap" << setw(20) << "Ngay san xuat" << setw(20) << "Han su dung" << endl;
}
