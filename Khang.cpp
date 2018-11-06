#include "pch.h"
#include "DoAn.h"

Node* CreateNode(SanPham x)
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

NodeSPDB* CreateNodeSPDB(SanPhamDaBan x)
{
	NodeSPDB *p;
	p = new NodeSPDB;
	if (p == NULL)
	{
		cout << "Khong tao Node thanh cong";
		return NULL;
	}
	p->infor = x;
	p->pnext = NULL;
	return p;
}

NodeTongSPDB* CreateNodeTongSPDB(TongSanPhamDaBan x)
{
	NodeTongSPDB *p;
	p = new NodeTongSPDB;
	if (p == NULL)
	{
		cout << "Khong tao Node thanh cong";
		return NULL;
	}
	p->infor = x;
	p->pnext = NULL;
	return p;
}

void AddTail(List &DSSP, SanPham x)
{
	Node *p = CreateNode(x);
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

void TaoDSSPDB(ListSPDB &DSSPDB)
{
	DSSPDB.pHead = NULL;
	DSSPDB.pTail = NULL;
}

void ThemSPDB(ListSPDB &DSSPDB, SanPhamDaBan x)
{
	NodeSPDB *p = CreateNodeSPDB(x);
	if (DSSPDB.pHead == NULL)
	{
		DSSPDB.pHead = p;
		DSSPDB.pTail = DSSPDB.pHead;
	}
	else
	{
		DSSPDB.pTail->pnext = p;
		p->pnext = NULL;
		DSSPDB.pTail = p;
	}
}

void TaoDSTongSPDB(ListTongSPDB &DSTongSPDB)
{
	DSTongSPDB.pHead = NULL;
	DSTongSPDB.pTail = NULL;
}

void ThemTongSPDB(ListTongSPDB &DSTongSPDB, TongSanPhamDaBan x)
{
	NodeTongSPDB *p = CreateNodeTongSPDB(x);
	if (DSTongSPDB.pHead == NULL)
	{
		DSTongSPDB.pHead = p;
		DSTongSPDB.pTail = DSTongSPDB.pHead;
	}
	else
	{
		DSTongSPDB.pTail->pnext = p;
		p->pnext = NULL;
		DSTongSPDB.pTail = p;
	}
}

void NhapDS(List &DSSP)
{
	int n = 0;
	cout << "Nhap so san pham:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin san pham:" << endl;
		SanPham x = NhapSP();
		AddTail(DSSP, x);
	}
}

SanPham NhapSP()
{
	SanPham x;
	cin.ignore();
	cout << "Nhap ten san pham:";
	cin.getline(x.TenSP, 100);
	cout << "Nhap ma san pham:";
	cin.getline(x.Ma, 100);
	cout << "Nhap gia ban san pham:";
	cin >> x.GiaBan;
	cout << "Nhap so luong san pham:";
	cin >> x.Sl;
	cin.ignore();
	cout << "Nha cung cap san pham:";
	cin.getline(x.NhaCC, 100);
	cout << "Nhap ngay san xuat san pham:";
	cin >> x.NgaySX->Ngay >> x.NgaySX->Thang >> x.NgaySX->Nam;
	cout << "Nhap han su dung san pham:";
	cin >> x.HanSD->Ngay >> x.HanSD->Thang >> x.HanSD->Nam;
	return x;
}

void HuyDS(List &DSSP)
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

void BoSungSP(List &DSSP)
{
	Node* p;
	p = DSSP.pHead;
	char x[20];
	cout << "Nhap ten san pham muon bo sung hang:";
	cin.getline(x, 20);
	while (p != NULL && strcmp(p->infor.TenSP, x) != 0)
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

void MuaSP(List &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB, int &tong, int &TongDoanhThu)
{
	cin.ignore();
	do
	{
		char x[20];
		cout << "Nhap ten san pham ban muon mua:";
		cin.getline(x, 20);
		Node* p;
		p = DSSP.pHead;
		while (p != NULL && strcmp(p->infor.TenSP, x) != 0)
			p = p->pnext;
		if (p != NULL)
		{
			int sl = 0, conlai = 0;
			cout << "Nhap so luong muon mua:";
			cin >> sl;
			cin.ignore();
			conlai = p->infor.Sl - sl;
			if (conlai < 0)
				cout << "Khong du so luong, cua hang chi con lai " << p->infor.Sl << " san pham nay!" << endl;
			else
			{
				cout << "Mua thanh cong!" << endl;
				SanPhamDaBan x;
				NodeSPDB *q;
				q = DSSPDB.pHead;
				while (q != NULL && strcmp(p->infor.TenSP, q->infor.TenSPDB) != 0)
					q = q->pnext;
				if (q != NULL)
				{
					q->infor.Sldb = q->infor.Sldb + sl;
				}
				else
				{
					strcpy_s(x.TenSPDB, p->infor.TenSP);
					x.Sldb = sl;
					x.GiaBanDB = p->infor.GiaBan;
					ThemSPDB(DSSPDB, x);
				}
				p->infor.Sl = conlai;
			}
			TongSanPhamDaBan tongsp;
			NodeTongSPDB *s;
			s = DSTongSPDB.pHead;
			while (s != NULL && strcmp(p->infor.TenSP, s->infor.TenTongSPDB) != 0)
				s = s->pnext;
			if (s != NULL)
			{
				s->infor.TongSldb = s->infor.TongSldb + sl;
			}
			else
			{
				strcpy_s(tongsp.TenTongSPDB, p->infor.TenSP);
				tongsp.TongSldb = sl;
				ThemTongSPDB(DSTongSPDB, tongsp);
			}
		}
		else
			cout << "Cua hang chua co mat hang nay!" << endl;
		cout << "Nhan phim bat ki de tiep tuc, nhan ESC de ket thuc mua hang!" << endl;
	} while (_getch() != 27);
	TraHang(DSSP, DSSPDB, DSTongSPDB);
	KhuyenMai(DSSPDB);
	cout << endl;
	InHoaDon(DSSPDB, tong);
	TongDoanhThu = TongDoanhThu + tong;
	int TienKhach = 0;
	ThoiTien(tong, TienKhach);
	HuyDSSPDB(DSSPDB);
}

void TraHang(List &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB)
{
	do
	{
		char x[20];
		cout << "Nhap ten san pham can tra:";
		cin.getline(x, 20);
		NodeSPDB* q;
		q = DSSPDB.pHead;
		while (q != NULL && strcmp(q->infor.TenSPDB, x) != 0)
			q = q->pnext;
		if (q != NULL)
		{
			Node* p;
			p = DSSP.pHead;
			while (p != NULL && strcmp(p->infor.TenSP, x) != 0)
				p = p->pnext;
			NodeTongSPDB* s;
			s = DSTongSPDB.pHead;
			while (s != NULL && strcmp(s->infor.TenTongSPDB, x) != 0)
				s = s->pnext;
			int sl = 0, hienco = 0;
			cout << "Nhap so luong muon tra lai:";
			cin >> sl;
			cin.ignore();
			hienco = q->infor.Sldb;
			if (sl > hienco)
				cout << "Ban chi mua co " << q->infor.Sldb << " san pham nay!" << endl;
			else
			{
				cout << "Tra lai thanh cong!" << endl;
				q->infor.Sldb = q->infor.Sldb - sl;
				s->infor.TongSldb = s->infor.TongSldb - sl;
				p->infor.Sl = p->infor.Sl + sl;
			}
		}
		else
			cout << "Ban khong co mua mat hang nay!" << endl;
		cout << "Nhan phim bat ki de tiep tuc, nhan ESC de dung tra hang!" << endl;
	} while (_getch() != 27);
}

void KhuyenMai(ListSPDB &DSSPDB)
{
	NodeSPDB *q;
	q = DSSPDB.pHead;
	while (q != NULL)
	{
		if (q->infor.Sldb >= 5 && q->infor.Sldb < 10)
		{
			q->infor.GiamGia = q->infor.GiaBanDB*q->infor.Sldb*0.05;
		}
		if (q->infor.Sldb >= 10 && q->infor.Sldb < 20)
		{
			q->infor.GiamGia = q->infor.GiaBanDB*q->infor.Sldb*0.1;
		}
		if (q->infor.Sldb >= 20 && q->infor.Sldb < 50)
		{
			q->infor.GiamGia = q->infor.GiaBanDB*q->infor.Sldb*0.2;
		}
		if (q->infor.Sldb >= 50)
		{
			q->infor.GiamGia = q->infor.GiaBanDB*q->infor.Sldb*0.25;
		}
		q = q->pnext;
	}
}

void HuyDSSPDB(ListSPDB &DSSPDB)
{
	NodeSPDB *p;
	while (DSSPDB.pHead != NULL)
	{
		p = DSSPDB.pHead;
		DSSPDB.pHead = p->pnext;
		delete p;
	}
	DSSPDB.pTail = NULL;
}

void InThongTinTongSanPhamDB(ListTongSPDB DSTongSPDB)
{
	int w = 140;
	InDSTongSanPhamDB(DSTongSPDB);
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	NodeTongSPDB *p = DSTongSPDB.pHead;
	while (p != NULL)
	{
		cout << setw(20) << left << p->infor.TenTongSPDB << setw(20) << p->infor.TongSldb << endl;
		p = p->pnext;
	}
	SanPhamBanChayNhat(DSTongSPDB);
}
void InDSTongSanPhamDB(ListTongSPDB DSTongSPDB)
{
	int w = 140;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw((w - 20) / 2) << left << " " << "THONG TIN CAC SAN PHAM" << endl;
	for (int i = 0; i < w; i++) cout << "=";
	cout << endl;
	cout << setw(20) << "Ten san pham";
	cout << setw(20) << "So luong" << endl;
}

void SanPhamBanChayNhat(ListTongSPDB DSTongSPDB)
{
	NodeTongSPDB *p = DSTongSPDB.pHead;
	int banchay = 0;
	char best[20];
	banchay = p->infor.TongSldb;
	strcpy_s(best, p->infor.TenTongSPDB);
	while (p != NULL)
	{
		if (banchay < p->infor.TongSldb)
		{
			banchay = p->infor.TongSldb;
			strcpy_s(best, p->infor.TenTongSPDB);
		}
		p = p->pnext;
	}
	cout << "San pham ban chay nhat cua hang la " << best << ", ban duoc " << banchay << " san pham!" << endl;
}

void LoiNhuan(ListTongSPDB DSTongSPDB, int TongDoanhThu)
{
	int tong = 0;
	int loinhuan = 0;
	NodeTongSPDB *p = DSTongSPDB.pHead; while (p != NULL)
	{
		int giagoc = 0;
		cout << "Nhap gia goc cua san pham " << p->infor.TenTongSPDB << ":";
		cin >> giagoc;
		tong = tong + p->infor.TongSldb * giagoc;
		p = p->pnext;
	}
	loinhuan = TongDoanhThu - tong;
	cout << "Loi nhuan cua cua hang la: " << loinhuan << endl;
}