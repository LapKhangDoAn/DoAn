#include "pch.h"
#include "Khang.h"
//#include "Lap.h"

Node* createNode(SanPham x)
{
	Node *p;
	p = new Node;
	if (p == NULL)
	{
		cout << "Khong tao Node thanh cong";
		return NULL;
	}
	p->infor = x;
	p->pnext = NULL;
	return p;
}

void addTail(List &DSSP, SanPham x)
{
	Node *p = createNode(x);
	if (DSSP.pHead == NULL)
	{
		DSSP.pHead = p;
		DSSP.pTail = DSSP.pHead;
	}
	else
	{
		DSSP.pTail->pnext = p;
		p->pnext = NULL;
		DSSP.pTail = p;
	}
}

void nhapDS(List &DSSP)
{
	int n = 0;
	cout << "Nhap so san pham:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin san pham:" << endl;
		SanPham x = nhapSP();
		addTail(DSSP, x);
	}
}

SanPham nhapSP()
{
	SanPham x;
	cin.ignore();
	cout << "Nhap ten san pham:";
	cin.getline(x.Ten_sp, 100);
	cout << "Nhap ma san pham:";
	cin.getline(x.Ma, 100);
	cout << "Nha cung cap san pham:";
	cin.getline(x.Nha_cc, 100);
	cout << "Nhap ngay san xuat san pham:";
	cin.getline(x.Ngay_sx, 100);
	cout << "Nhap han su dung san pham:";
	cin.getline(x.Han_sd, 100);
	cout << "Nhap so luong san pham:";
	cin >> x.Sl;
	cout << "Nhap gia ban san pham:";
	cin >> x.Gia_Ban;
	return x;
}

void huyDS(List &DSSP)
{
	Node *p;
	while (DSSP.pHead != NULL)
	{
		p = DSSP.pHead;
		DSSP.pHead = p->pnext;
		delete p;
	}
	DSSP.pTail = NULL;
}

//Node* searchNode(char x[], List myList) 
//{ 
//	Node* p;  
//	p = myList.pHead->pnext;  
//	while (p != NULL && strcmp(p->infor.Ten_sp, x) == 1)
//		p = p->pnext;  
//	return p; 
//}

void bosungSP(List &DSSP)
{
	Node* p;
	p = DSSP.pHead;
	char x[20];
	cout << "Nhap ten san pham muon bo sung hang:";
	cin.getline(x, 20);
	while (p != NULL && strcmp(p->infor.Ten_sp,x) != 0)
		p = p->pnext;
	if (p != NULL)
	{
		int sl = 0;
		cout << "Nhap so luong san pham muon bo sung:";
		cin >> sl;
		p->infor.Sl = p->infor.Sl + sl;
	}
	else
		cout << "Cua hang chua co mat hang nay!";
}

void timkiemSP(List DSSP)
{
	cout << "Danh muc tim kiem:" << endl;
	cout << "1. Tim kiem theo ten san pham" << endl;
	cout << "2. Tim kiem theo ma san pham" << endl;
	cout << "3. Tim kiem theo khoang gia" << endl;
	int chon = 0;
	cin >> chon;
	if (chon == 1)
	{
		cin.ignore();
		char x[20];
		cout << "Nhap ten san pham can tim:";
		cin.getline(x, 20);
		Node* p;
		p = DSSP.pHead;  
		while (p != NULL && strcmp(p->infor.Ten_sp, x) != 0)
			p = p->pnext;  
		if (p != NULL)
		{
			int w = 130;
			cout << "Thong tin san pham:" << endl;
			cout << setw(w / 7) << left << "Ten san pham";
			cout << setw(w / 7) << "Ma san pham" << setw(w / 7) << "Gia ban san pham" << setw(w / 7) << "So luong" << setw(w / 7) << "Nha cung cap" << setw(w / 7) << "Ngay san xuat" << setw(w / 7) << "Han su dung" << endl;
			cout << setw(w / 7) << left << p->infor.Ten_sp << setw(w / 7) << p->infor.Ma << setw(w / 7) << p->infor.Gia_Ban << setw(w / 7) << p->infor.Sl << setw(w / 7) << p->infor.Nha_cc << setw(w / 7) << p->infor.Ngay_sx << setw(w / 7) << p->infor.Han_sd << endl;
		}
	}
	if (chon == 2)
	{
		cin.ignore();
		char x[20];
		cout << "Nhap ma san pham can tim:";
		cin.getline(x, 20);
		Node* p;
		p = DSSP.pHead;
		while (p != NULL && strcmp(p->infor.Ma, x) != 0)
			p = p->pnext;
		if (p != NULL)
		{
			int w = 130;
			cout << "Thong tin san pham:" << endl;
			cout << setw(w / 7) << left << "Ten san pham";
			cout << setw(w / 7) << "Ma san pham" << setw(w / 7) << "Gia ban san pham" << setw(w / 7) << "So luong" << setw(w / 7) << "Nha cung cap" << setw(w / 7) << "Ngay san xuat" << setw(w / 7) << "Han su dung" << endl;
			cout << setw(w / 7) << left << p->infor.Ten_sp << setw(w / 7) << p->infor.Ma << setw(w / 7) << p->infor.Gia_Ban << setw(w / 7) << p->infor.Sl << setw(w / 7) << p->infor.Nha_cc << setw(w / 7) << p->infor.Ngay_sx << setw(w / 7) << p->infor.Han_sd << endl;
		}
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
		while (p != NULL && (mingia > p->infor.Gia_Ban || p->infor.Gia_Ban > maxgia))
			p = p->pnext;
		if (p != NULL)
		{
			int w = 130;
			cout << "Thong tin san pham:" << endl;
			cout << setw(w / 7) << left << "Ten san pham";
			cout << setw(w / 7) << "Ma san pham" << setw(w / 7) << "Gia ban san pham" << setw(w / 7) << "So luong" << setw(w / 7) << "Nha cung cap" << setw(w / 7) << "Ngay san xuat" << setw(w / 7) << "Han su dung" << endl;
			cout << setw(w / 7) << left << p->infor.Ten_sp << setw(w / 7) << p->infor.Ma << setw(w / 7) << p->infor.Gia_Ban << setw(w / 7) << p->infor.Sl << setw(w / 7) << p->infor.Nha_cc << setw(w / 7) << p->infor.Ngay_sx << setw(w / 7) << p->infor.Han_sd << endl;
		}
	}
}