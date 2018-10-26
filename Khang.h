#define max 100

struct SanPhamDaBan
{
	char Ten_spdb[max];
	int Sldb;
	int Gia_Bandb;
	double Giamgia = 0;
};

struct NodeSPDB
{
	SanPhamDaBan infor;
	NodeSPDB *pnext;
};

struct ListSPDB
{
	NodeSPDB *pHead;
	NodeSPDB *pTail;
};

struct TongSanPhamDaBan
{
	char Ten_tongspdb[max];
	int tongSldb;
};

struct NodeTongSPDB
{
	TongSanPhamDaBan infor;
	NodeTongSPDB *pnext;
};

struct ListTongSPDB
{
	NodeTongSPDB *pHead;
	NodeTongSPDB *pTail;
};

Node* createNode(SanPham x);
NodeSPDB* createNodeSPDB(SanPhamDaBan x);
NodeTongSPDB* createNodeTongSPDB(TongSanPhamDaBan x);
void addTail(List &DSSP, SanPham x);
void taoDSSPDB(ListSPDB &DSSPDB);
void themSPDB(List &DSSPDB, SanPhamDaBan x);
void taoDSTongSPDB(ListTongSPDB &DSTongSPDB);
void themTongSPDB(ListTongSPDB &DSTongSPDB, TongSanPhamDaBan x);
SanPham nhapSP();
void nhapDS(List &DSSP);
void inDS(List DSSP);
void huyDS(List &DSSP);
void huyDSSPDB(ListSPDB &DSSPDB);
Node* searchNode(struct SanPham x, List myList);
void bosungSP(List &DSSP);
void muaSP(List &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB, int &tong, int &TongDoanhThu);
//void tongDoanhThu(ListTongSPDB DSTongSPDB);
void InHoaDon(ListSPDB DSSPDB, int &tong);
void ThongTinHoaDon(ListSPDB DSSPDB);
void trahang(List &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB);
void khuyenmai(ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB);
void inThongTinTongSanPhamDB(ListTongSPDB DSTongSPDB);
void inDSTongSanPhamDB(ListTongSPDB DSTongSPDB);