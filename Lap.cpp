#include "pch.h"
#include "Lap.h"

void taoDS(List &DSSP)
{
	DSSP.pHead = NULL;
	DSSP.pTail = NULL;
}

//void inDS(List DSSP)
//{
//	int w = 130;
//	for (int i = 0; i < w; i++) cout << "=";
//	cout << endl;
//	cout << setw((w - 20) / 2) << left << " " << "THONG TIN CAC SAN PHAM" << endl;
//	for (int i = 0; i < w; i++) cout << "=";
//	cout << endl;
//	cout << setw(w / 7) << left << "Ten san pham";
//	cout << setw(w / 7) << "Ma san pham" << setw(w / 7) << "Gia ban san pham" << setw(w / 7) << "So luong" << setw(w / 7) << "Nha cung cap" << setw(w / 7) << "Ngay san xuat" << setw(w / 7) << "Han su dung" << endl;
//	for (int i = 0; i < w; i++) cout << "=";
//	cout << endl;
//	Node *p = DSSP.pHead;
//	while (p != NULL)
//	{
//		cout << setw(w / 7) << left << p->infor.Ten_sp << setw(w / 7) << p->infor.Ma << setw(w / 7) << p->infor.Gia_Ban << setw(w / 7) << p->infor.Sl << setw(w / 7) << p->infor.Nha_cc << setw(w / 7) << p->infor.Ngay_sx << setw(w / 7) << p->infor.Han_sd << endl;
//		p = p->pnext;
//	}
//}
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
// Kiem Tra Trang Thai San Pham
void KiemTra(List DSSP)
{
	int w = 130;
	Node *p;
	SanPham x;
	int dem = 0;
	int chon = 0;
	cout << "1.Kiem Tra San Pham Theo Ten " << endl;
	cout << "2.Kiem Tra San Pham Theo Ma" << endl;
	cin >> chon;
	if (chon == 1)
	{
		cin.ignore();
		cout << "Nhap Ten San Pham Can Kiem Tra:";
		cin.getline(x.Ten_sp, 100);
		p = DSSP.pHead;
		while (p != NULL)
		{
			if (strcmp(x.Ten_sp, p->infor.Ten_sp) == 0)
			{
				inDS(DSSP);
				cout << setw(w / 7) << left << p->infor.Ten_sp << setw(w / 7) << p->infor.Ma << setw(w / 7) << p->infor.Gia_Ban << setw(w / 7) << p->infor.Sl << setw(w / 7) << p->infor.Nha_cc << setw(w / 7) << p->infor.Ngay_sx << setw(w / 7) << p->infor.Han_sd << endl;
				dem++;
			}
			p = p->pnext;
		}
		if (dem == 0)
			cout << "Khong Co San Pham Nao";
	}
	if (chon == 2)
	{
		cin.ignore();
		cout << "Nhap Ma San Pham Can Kiem Tra:";
		cin.getline(x.Ma, 100);
		p = p = DSSP.pHead;
		while (p != NULL)
		{
			if (strcmp(x.Ma, p->infor.Ma) == 0)
			{
				inDS(DSSP);
				cout << setw(w / 7) << left << p->infor.Ten_sp << setw(w / 7) << p->infor.Ma << setw(w / 7) << p->infor.Gia_Ban << setw(w / 7) << p->infor.Sl << setw(w / 7) << p->infor.Nha_cc << setw(w / 7) << p->infor.Ngay_sx << setw(w / 7) << p->infor.Han_sd << endl;
				dem++;
			}
			p = p->pnext;
		}
		if (dem == 0)
			cout << "Khong Co San Pham Nao";
	}
}
void InThongTin(List DSSP)
{
	int w = 130;
	inDS(DSSP);
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	Node *p = DSSP.pHead;
	while (p != NULL)
	{
		cout << setw(w / 7) << left << p->infor.Ten_sp << setw(w / 7) << p->infor.Ma << setw(w / 7) << p->infor.Gia_Ban << setw(w / 7) << p->infor.Sl << setw(w / 7) << p->infor.Nha_cc << setw(w / 7) << p->infor.Ngay_sx << setw(w / 7) << p->infor.Han_sd << endl;
		p = p->pnext;
	}
}
void inDS(List DSSP)
{
	int w = 130;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw((w - 20) / 2) << left << " " << "THONG TIN CAC SAN PHAM" << endl;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw(w / 7) << left << "Ten san pham";
	cout << setw(w / 7) << "Ma san pham" << setw(w / 7) << "Gia ban san pham" << setw(w / 7) << "So luong" << setw(w / 7) << "Nha cung cap" << setw(w / 7) << "Ngay san xuat" << setw(w / 7) << "Han su dung" << endl;
}
