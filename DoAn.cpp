// BTLỚN.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <iostream>
using namespace std;
#define max 100
#define printstr(w)
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
void Thong_Tin(SanPham&s);
void nhap_so_san_pham(SanPham s[], int n);
void In_Thong_Tin(SanPham s);
void Bang_Thong_Tin(SanPham s[], int n);
int main()
{
	SanPham s[max];
	int n;
	cout << "Nhap so san pham:";
	cin >> n;
	nhap_so_san_pham(s, n);
	Bang_Thong_Tin(s, n);
    return 0;
}
void Thong_Tin(SanPham&s)
{
	cin.ignore();
	cout << "Nhap ten san pham:";
	cin.getline(s.Ten_sp, 100);
	cout << "Nhap ma san pham:";
	cin.getline(s.Ma, 100);
	cout << "Nha cung cap san pham:";
	cin.getline(s.Nha_cc, 100);
	cout << "Nhap ngay san xuat san pham:";
	cin.getline(s.Ngay_sx, 100);
	cout << "Nhap han su dung san pham:";
	cin.getline(s.Han_sd, 100);
	cout << "Nhap so luong san pham:";
	cin >> s.Sl;
	cout << "Nhap gia ban san pham:";
	cin >> s.Gia_Ban;
}
void nhap_so_san_pham(SanPham s[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "nhap thong tin san pham thu" << " " << i << ":" << endl;
		Thong_Tin(s[i]);
	}
}
void In_Thong_Tin(SanPham s)
{
	int w = 130;
	cout << setw(w / 7) << left << s.Ten_sp << setw(w / 7) << s.Ma << setw(w / 7) << s.Gia_Ban << setw(w / 7) << s.Sl << setw(w / 7)  << s.Nha_cc << setw(w / 7) << s.Ngay_sx<< setw(w / 7) << s.Han_sd << endl;
}
void Bang_Thong_Tin(SanPham s[], int n)
{
	int w = 130;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw((w - 20) / 2) << left << " " << "THONG TIN CAC SAN PHAM" << endl;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw(w / 7) << left << "Ten san pham";
	cout << setw(w / 7) << "Ma san pham" << setw(w / 7) << "Gia ban san pham" << setw(w / 7) << "So luong" << setw(w / 7) << "Nha cung cap" << setw(w / 7) << "Ngay san xuat"<< setw(w / 7) << "Han su dung" << endl;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;

	for (int i = 1; i <= n; i++)
	{
		In_Thong_Tin(s[i]);
	}
	cout << endl;
}