#include "pch.h"
#include "DoAn.h"

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

NodeSPDB* createNodeSPDB(SanPhamDaBan x)
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

void taoDSSPDB(ListSPDB &DSSPDB)
{
	DSSPDB.pHead = NULL;
	DSSPDB.pTail = NULL;
}

void themSPDB(ListSPDB &DSSPDB, SanPhamDaBan x)
{
	NodeSPDB *p = createNodeSPDB(x);
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
	while (p != NULL && strcmp(p->infor.Ten_sp, x) != 0)
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

void muaSP(List &DSSP, ListSPDB &DSSPDB, ListSPDB &DSTongSPDB)
{
	int mua = 1;
	while (mua == 1)
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
			int sl = 0, conlai = 0;
			cout << "Nhap so luong muon mua:";
			cin >> sl;
			conlai = p->infor.Sl - sl;
			if (conlai < 0)
				cout << "Khong du so luong, cua hang chi con lai " << p->infor.Sl << " san pham nay!" << endl;
			else
			{
				cout << "Mua thanh cong!" << endl;
				SanPhamDaBan x, tong;
				NodeSPDB *q;
				q = DSSPDB.pHead;
				while (q != NULL && strcmp(p->infor.Ten_sp, q->infor.Ten_spdb) != 0)
					q = q->pnext;
				NodeSPDB *s;
				s = DSTongSPDB.pHead;
				while (s != NULL && strcmp(p->infor.Ten_sp, s->infor.Ten_spdb) != 0)
					s = s->pnext;
				if (q != NULL)
				{
					q->infor.Sldb = q->infor.Sldb + sl;
					s->infor.Sldb = s->infor.Sldb + sl;
				}
				else
				{
					strcpy_s(x.Ten_spdb, p->infor.Ten_sp);
					x.Sldb = sl;
					x.Gia_Bandb = p->infor.Gia_Ban;
					themSPDB(DSSPDB, x);
					strcpy_s(tong.Ten_spdb, p->infor.Ten_sp);
					tong.Sldb = sl;
					tong.Gia_Bandb = p->infor.Gia_Ban;
					themSPDB(DSTongSPDB, tong);
				}
				p->infor.Sl = conlai;
			}
		}
		else
			cout << "Cua hang chua co mat hang nay!" << endl;
		cout << "Nhap 1 de mua tiep, 0 de ket thuc:";
		cin >> mua;
	}
	trahang(DSSP, DSSPDB, DSTongSPDB);
	cout << endl;
	InHoaDon(DSSPDB);
	huyDSSPDB(DSSPDB);
}

void trahang(List &DSSP, ListSPDB &DSSPDB, ListSPDB &DSTongSPDB)
{
	int tra = 1;
	while (tra == 1)
	{
		cin.ignore();
		char x[20];
		cout << "Nhap ten san pham can tra:";
		cin.getline(x, 20);
		NodeSPDB* q;
		q = DSSPDB.pHead;
		while (q != NULL && strcmp(q->infor.Ten_spdb, x) != 0)
			q = q->pnext;
		if (q != NULL)
		{
			Node* p;
			p = DSSP.pHead;
			while (p != NULL && strcmp(p->infor.Ten_sp, x) != 0)
				p = p->pnext;
			NodeSPDB* s;
			s = DSTongSPDB.pHead;
			while (s != NULL && strcmp(s->infor.Ten_spdb, x) != 0)
				s = s->pnext;
			int sl = 0, hienco = 0;
			cout << "Nhap so luong muon tra lai:";
			cin >> sl;
			hienco = q->infor.Sldb;
			if (sl > hienco)
				cout << "Ban chi mua co " << q->infor.Sldb << " san pham nay!" << endl;
			else
			{
				cout << "Tra lai thanh cong!" << endl;
				q->infor.Sldb = q->infor.Sldb - sl;
				s->infor.Sldb = s->infor.Sldb - sl;
				p->infor.Sl = p->infor.Sl + sl;
			}
		}
		else
			cout << "Ban khong co mua mat hang nay!" << endl;
		cout << "Nhap 1 de tra lai tiep, 0 de ket thuc:";
		cin >> tra;
	}
}

void tongDoanhThu(ListSPDB DSTongSPDB)
{
	double tong = 0;
	NodeSPDB *p;
	p = DSTongSPDB.pHead;
	while (p != NULL)
	{
		tong = tong + (p->infor.Sldb*p->infor.Gia_Bandb);
		p = p->pnext;
	}
	cout << "Tong doanh thu cua hang: " << tong << endl;
}

void huyDSSPDB(ListSPDB &DSSPDB)
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
