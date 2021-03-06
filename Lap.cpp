﻿#include "pch.h"
#include "DoAn.h"

void TaoDS(ListSP &DSSP)
{
	DSSP.pHead = NULL;
	DSSP.pTail = NULL;
}

void textcolor(int x) // Thay đổi màu chữ
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void KiemTraHanSD(ListSP DSSP)
{
	textcolor(14);
	cout << "1.Kiem tra han su dung mot san pham bat ki:" << endl;
	cout << "2.Kiem tra han su dung cua tat ca cac san pham:" << endl;
	int chon;
	textcolor(12);
	cout << "Thuc hien kiem tra:";
	cin >> chon;
	if (chon == 1)
	{
		cin.ignore();
		KiemTraHanSD1(DSSP);
	}
	if (chon == 2)
	{
		textcolor(13);
		KiemTraHanSD3(DSSP);
	}
	textcolor(15);
}

void KiemTraHanSD3(ListSP DSSP)
{
	NodeSP *p = DSSP.pHead;
	int d, m, y;
	cout << "Nhap ngay hien tai:";
	cin >> d >> m >> y;
	cout << "Nhung san pham da het han su dung:" << endl;
	InDS(DSSP);
	while (p != NULL)
	{
		if (KiemTraHanSD2(DSSP,p,y,m,d) == 0)
		{
			cout << setw(20) << left << p->infor.TenSP << setw(20) << p->infor.Ma << setw(20) << p->infor.GiaBan;
			cout << setw(20) << p->infor.Sl << setw(20) << p->infor.NhaCC;
			cout << p->infor.NgaySX->Ngay << "/" << p->infor.NgaySX->Thang << "/" << setw(18) << p->infor.NgaySX->Nam;
			cout << p->infor.HanSD->Ngay << "/" << p->infor.HanSD->Thang << "/" << p->infor.HanSD->Nam << endl;
		}
		p = p->pnext;
	}
}

int KiemTraHanSD2(ListSP DSSP, NodeSP *p, int &y, int &m, int &d) // Kiểm tra hạn sử dụng của một sản phẩm 
{
	if (p->infor.HanSD->Nam > y)
		return 1;
	else
		if (p->infor.HanSD->Nam < y)
			return 0;
		else
			if (p->infor.HanSD->Thang > m)
					return 1;
			else
				if (p->infor.HanSD->Thang < m)
						return 0;
				else
					if (p->infor.HanSD->Ngay > d)
							return 1;
					else
						if (p->infor.HanSD->Ngay < d)
								return 0;
						else return 1;
}

void KiemTraHanSD1(ListSP DSSP)
{
	textcolor(14);
	NodeSP* p;
	p = DSSP.pHead;
	char a[100];
	cout << "Nhap ten san pham can kiem tra han su dung:";
	cin.getline(a, 100);
	while (p != NULL && strcmp(a, p->infor.TenSP) != 0)
		p = p->pnext;
	int d, m, y;
	cout << "Nhap ngay hien tai:";
	cin >> d >> m >> y;
	textcolor(12);
	int kiemtra = KiemTraHanSD2(DSSP, p, y, m, d);
	if (kiemtra == 1)
		cout << "San Pham Con Han Su Dung";
	else
		cout << "San Pham Da Het Han Su Dung";
	textcolor(15);
}

void SapXep(ListSP DSSP) // Sắp xếp sản phẩm theo giá bán sử dụng thuật toán InterchangeSort
{
	NodeSP *p, *q, *min;
	p = DSSP.pHead;
	SanPham x;
	while (p != DSSP.pTail)
	{
		min = p;
		q = p->pnext;
		while (q != NULL)
		{
			if (q->infor.GiaBan < min->infor.GiaBan)
				min = q;
			q = q->pnext;
		}
		x = p->infor;
		p->infor = min->infor;
		min->infor = x;
		p = p->pnext;
	}
}

void  ThoiTien(int&tong, int TienKhach)
{
	while (TienKhach < tong)
	{
		cout << "Nhap so tien cua khach:";
		cin >> TienKhach;
	}
	int tienthoi = TienKhach - tong;
	cout << "Tien thoi: " << tienthoi;
	if (tienthoi == 0)
		cout << "\nKhach da tra du tien!" << endl;
	else // Gợi ý thối tiền
	{
		int dem500d = 0;
		int dem1k = 0;
		int dem2k = 0;
		int dem5k = 0;
		int dem10k = 0;
		int dem20k = 0, dem50k = 0, dem100k = 0, dem200k = 0, dem500k = 0;
		int cuckeo = 0;
		while (tienthoi != 0)
		{
			if (tienthoi >= 500000)
			{
				tienthoi -= 500000;
				dem500k++;
			}
			else if (tienthoi >= 200000)
			{
				tienthoi -= 200000;
				dem200k++;
			}
			else if (tienthoi >= 100000)
			{
				tienthoi -= 100000;
				dem100k++;
			}
			else if (tienthoi >= 50000)
			{
				tienthoi -= 50000;
				dem50k++;
			}
			else if (tienthoi >= 20000)
			{
				tienthoi -= 20000;
				dem20k++;
			}
			else if (tienthoi >= 10000)
			{
				tienthoi -= 10000;
				dem10k++;
			}
			else if (tienthoi >= 5000)
			{
				tienthoi -= 5000;
				dem5k++;
			}
			else if (tienthoi >= 2000)
			{
				tienthoi -= 2000;
				dem2k++;
			}
			else if (tienthoi >= 1000)
			{
				tienthoi -= 1000;
				dem1k++;
			}
			else if (tienthoi >= 500)
			{
				tienthoi -= 500;
				dem500d++;
			}
			else if (tienthoi < 500)
			{
				tienthoi = 0;
				cuckeo = 1;
			}
		}
		cout << endl;
		cout << "Thoi lai gom:" << endl;
		if (dem500k != 0)
		{
			cout << dem500k << " to 500.000d" << endl;
		}
		if (dem200k != 0)
		{
			cout << dem200k << " to 200.000d" << endl;
		}
		if (dem100k != 0)
		{
			cout << dem100k << " to 100.000d" << endl;
		}
		if (dem50k != 0)
		{
			cout << dem50k << " to 50.000d" << endl;
		}
		if (dem20k != 0)
		{
			cout << dem20k << " to 20.000d" << endl;
		}
		if (dem10k != 0)
		{
			cout << dem10k << " to 10.000d" << endl;
		}
		if (dem5k != 0)
		{
			cout << dem5k << " to 5.000d" << endl;
		}
		if (dem2k != 0)
		{
			cout << dem2k << " to 2.000d" << endl;
		}
		if (dem1k != 0)
		{
			cout << dem1k << " to 1.000d" << endl;
		}
		if (dem500d != 0)
		{
			cout << dem500d << " to 500d" << endl;
		}
		if (cuckeo != 0)
		{
			cout << "Cuc keo" << endl;
		}
	}
}

void InHoaDon(ListSPDB DSSPDB, int &tong) // In hóa đơn mua hàng
{
	int w = 140;
	tong = 0;
	ThongTinHoaDon(DSSPDB);
	textcolor(11);
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	NodeSPDB *p = DSSPDB.pHead;
	while (p != NULL)
	{
		cout << setw(30) << left << p->infor.TenSPDB << setw(30) << p->infor.Sldb << setw(30) << p->infor.GiaBanDB;
		cout << setw(30) << p->infor.GiaBanDB*p->infor.Sldb << setw(30) << p->infor.GiamGia << endl;
		tong = tong + p->infor.GiaBanDB*p->infor.Sldb - p->infor.GiamGia;
		p = p->pnext;
	}
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw(30) << " " << "Tong cong:" << tong << " VND" << endl;
}

void ThongTinHoaDon(ListSPDB DSSPDB)
{
	textcolor(11);
	int w = 140;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw((w - 20) / 2) << " " << "Hoa Don Mua Hang" << endl;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw(30) << left << "Ten san pham";
	cout << setw(30) << "So luong" << setw(30) << "Gia ban san pham" << setw(30) << "Thanh tien" << setw(30) << "Tien giam" << endl;
}

void ThemSP(ListSP &DSSP) // Thêm sản phẩm
{
	int them = 1;
	while (them == 1)
	{
		textcolor(14);
		cout << "Nhap thong tin san pham can them:" << endl;
		SanPham x = NhapSP();
		textcolor(12);
		cout << "1.Them san pham vao dau danh sach" << endl;
		cout << "2.Them san pham B vào sau san pham A co trong danh sach" << endl;
		cout << "3.Them san pham vao cuoi danh sach" << endl;
		textcolor(10);
		cout << "Ban chon cach them so:";
		int chon;
		cin >> chon;
		textcolor(15);
		if (chon == 1)
		{
			NodeSP *q = CreateNode(x);
			AddHead(DSSP, q);
		}
		if (chon == 2)
		{
			NodeSP *q = CreateNode(x);
			NodeSP *p = SearchNode(DSSP);
			InsertAfter(DSSP, p, q, x);
		}
		if (chon == 3)
		{
			NodeSP *q = CreateNode(x);
			AddTail(DSSP, x);
		}
		cout << "Nhap 1 de them tiep, 0 de ket thuc:";
		cin >> them;
		cin.ignore();
	}
}

void InsertAfter(ListSP &DSSP, NodeSP *p, NodeSP *q, SanPham x)
{
	if (p != NULL)
	{
		q->pnext = p->pnext;
		p->pnext = q;
		if (DSSP.pTail == p)
			DSSP.pTail = q;
	}
	else
		AddTail(DSSP, x);
}

NodeSP* SearchNode(ListSP &DSSP)
{
	NodeSP* p;
	p = DSSP.pHead;
	cin.ignore();
	char a[100];
	cout << "Nhap ma san pham A de them san pham B vao sau :";
	cin.getline(a, 100);
	while (p != NULL && strcmp(a, p->infor.Ma) != 0)
		p = p->pnext;
	return p;
}

void AddHead(ListSP &DSSP, NodeSP *p)
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

// Xóa sản phẩm
int RemoveX(ListSP &DSSP, char x[])
{
	NodeSP *p;
	p = DSSP.pHead;
	NodeSP *q = new NodeSP;
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

void RemoveAfter(ListSP &DSSP)
{
	NodeSP *p;
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

void RemoveHead(ListSP &DSSP)
{
	if (DSSP.pHead == NULL)
		return;
	NodeSP *p = DSSP.pHead;
	DSSP.pHead = DSSP.pHead->pnext;
	delete p;
}

void TimKiem(ListSP DSSP) // Tìm kiếm sản phẩm
{
	int w = 130;
	NodeSP *p;
	SanPham x;
	int dem = 0;
	int chon;
	textcolor(10);
	cout << "Danh muc tim kiem:" << endl;
	textcolor(12);
	cout << "1. Tim kiem theo ten san pham" << endl;
	cout << "2. Tim kiem theo ma san pham" << endl;
	cout << "3. Tim kiem theo khoang gia" << endl;
	textcolor(14);
	cout << "Ban chon cach tim kiem so:";
	cin >> chon;
	textcolor(15);
	if (chon == 1)
	{
		cin.ignore();
		cout << "Nhap Ten San Pham Can Tim Kiem:";
		cin.getline(x.TenSP, 100);
		p = DSSP.pHead;
		while (p != NULL)
		{
			if (strcmp(x.TenSP, p->infor.TenSP) == 0)
			{
				dem++;
				if (dem == 1)
					InDS(DSSP);
				cout << setw(20) << left << p->infor.TenSP << setw(20) << p->infor.Ma << setw(20) << p->infor.GiaBan;
				cout << setw(20) << p->infor.Sl << setw(20) << p->infor.NhaCC;
				cout << p->infor.NgaySX->Ngay << "/" << p->infor.NgaySX->Thang << "/" << setw(18) << p->infor.NgaySX->Nam;
				cout << p->infor.HanSD->Ngay << "/" << p->infor.HanSD->Thang << "/" << p->infor.HanSD->Nam << endl;
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
				InDS(DSSP);
				cout << setw(20) << left << p->infor.TenSP << setw(20) << p->infor.Ma << setw(20) << p->infor.GiaBan;
				cout << setw(20) << p->infor.Sl << setw(20) << p->infor.NhaCC;
				cout << p->infor.NgaySX->Ngay << "/" << p->infor.NgaySX->Thang << "/" << setw(18) << p->infor.NgaySX->Nam;
				cout << p->infor.HanSD->Ngay << "/" << p->infor.HanSD->Thang << "/" << p->infor.HanSD->Nam << endl;
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
		NodeSP* p;
		p = DSSP.pHead;
		while (p != NULL)
		{
			if (mingia <= p->infor.GiaBan && p->infor.GiaBan <= maxgia)
			{
				dem++;
				if (dem == 1)
					InDS(DSSP);
				cout << setw(20) << left << p->infor.TenSP << setw(20) << p->infor.Ma << setw(20) << p->infor.GiaBan;
				cout << setw(20) << p->infor.Sl << setw(20) << p->infor.NhaCC;
				cout << p->infor.NgaySX->Ngay << "/" << p->infor.NgaySX->Thang << "/" << setw(18) << p->infor.NgaySX->Nam;
				cout << p->infor.HanSD->Ngay << "/" << p->infor.HanSD->Thang << "/" << p->infor.HanSD->Nam << endl;
			}
			p = p->pnext;
		}
		if (dem == 0)
		{
			textcolor(12);
			cout << "San Pham Can Tim Khong Co Trong Cua Hang" << endl;
			textcolor(15);
		}
	}

}

void InThongTin(ListSP DSSP) // In danh sách các sản phẩm đang kinh doanh của cửa hàng
{
	int w = 140;
	InDS(DSSP);
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	NodeSP *p = DSSP.pHead;
	while (p != NULL)
	{
		cout << setw(20) << left << p->infor.TenSP << setw(20) << p->infor.Ma << setw(20) << p->infor.GiaBan << setw(20) << p->infor.Sl;
		cout << setw(20) << p->infor.NhaCC << p->infor.NgaySX->Ngay << "/" << p->infor.NgaySX->Thang << "/" << setw(18) << p->infor.NgaySX->Nam;
		cout << p->infor.HanSD->Ngay << "/" << p->infor.HanSD->Thang << "/" << p->infor.HanSD->Nam << endl;
		p = p->pnext;
	}
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
}

void InDS(ListSP DSSP)
{
	int w = 140;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw((w - 20) / 2) << left << " " << "THONG TIN CAC SAN PHAM" << endl;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw(20) << "Ten san pham";
	cout << setw(20) << "Ma san pham" << setw(20) << "Gia ban san pham" << setw(20) << "So luong" << setw(20);
	cout << "Nha cung cap" << setw(20) << "Ngay san xuat" << setw(20) << "Han su dung" << endl;
}
