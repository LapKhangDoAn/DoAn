
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
void inDS(List DSSP);
void InThongTin(List DSSP);
void TimKiem(List DSSP);
int RemoveX(List&DSSP, char x[]);
void RemoveAfter(List &DSSP);
void RemoveHead(List&DSSP);