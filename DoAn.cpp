// DoAn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <iostream>
#define max 100
#define printstr(w)

using namespace std;

typedef struct SanPham
{
	char Ten_sp[max];
	char Nha_cc[max];
	char Ma[max];
	int Sl;
	int Gia_Ban;
	char Ngay_sx[max];
	char Han_sd[max];
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
Node* createNode(SanPham x);
void addTail(List &DSSP, SanPham x);
SanPham nhapSP();
void nhapDS(List &DSSP);
void inDS(List DSSP);
void huyDS(List &DSSP);

void main()
{
	List DSSP;
	int start = 1;
	int number;
	taoDS(DSSP);
	nhapDS(DSSP);
	while (start == 1)
	{
		cout << "MENU CHUC NANG:" << endl;
		cout << "1. Xuat danh sach san pham." << endl;
		cout << "2. Them san pham moi." << endl;
		cout << "3. Bo sung so luong san pham." << endl;
		cout << "4. Xoa san pham khoi danh sach." << endl;
		cout << "5. Tim kiem san pham." << endl;
		cout << "6. Kiem tra trang thai san pham." << endl;
		cout << "7. Mua san pham." << endl;
		cout << "8. Xuat hoa don mua hang." << endl;
		cout << "9. Tong doanh thu mua hang." << endl;
		cout << "Thuc hien chuc nang:";
		cin >> number;
		switch (number)
		{
		case 1:
			inDS(DSSP);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}
		cout << "Nhap 1 de tiep tuc, nhap 0 de ket thuc:";
		cin >> start;
	}
	huyDS(DSSP);
}

void taoDS(List &DSSP)
{
	DSSP.pHead = NULL;
	DSSP.pTail = NULL;
}

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
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	Node *p = DSSP.pHead;
	while (p != NULL)
	{
		cout << setw(w / 7) << left << p->infor.Ten_sp << setw(w / 7) << p->infor.Ma << setw(w / 7) << p->infor.Gia_Ban << setw(w / 7) << p->infor.Sl << setw(w / 7) << p->infor.Nha_cc << setw(w / 7) << p->infor.Ngay_sx << setw(w / 7) << p->infor.Han_sd << endl;
		p = p->pnext;
	}
}

