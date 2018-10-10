#include "pch.h"
#include "Lap.h"

void taoDS(List &DSSP)
{
	DSSP.pHead = NULL;
	DSSP.pTail = NULL;
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