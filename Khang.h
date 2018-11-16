#define max 100

struct SanPhamDaBan
{
	char TenSPDB[max];
	int Sldb;
	int GiaBanDB;
	double GiamGia = 0;
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
	char TenTongSPDB[max];
	int TongSldb;
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

Node* CreateNode(SanPham x);
NodeSPDB* CreateNodeSPDB(SanPhamDaBan x);
NodeTongSPDB* CreateNodeTongSPDB(TongSanPhamDaBan x);
void AddTail(List &DSSP, SanPham x);
void TaoDSSPDB(ListSPDB &DSSPDB);
void ThemSPDB(List &DSSPDB, SanPhamDaBan x);
void TaoDSTongSPDB(ListTongSPDB &DSTongSPDB);
void ThemTongSPDB(ListTongSPDB &DSTongSPDB, TongSanPhamDaBan x);
SanPham NhapSP();
void NhapDS(List &DSSP);
void InDS(List DSSP);
void HuyDS(List &DSSP);
void HuyDSSPDB(ListSPDB &DSSPDB);
Node* SearchNode(struct SanPham x, List myList);
void BoSungSP(List &DSSP);
void MuaSPvaThanhToan(List &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB, int &tong, int &TongDoanhThu);
//void tongDoanhThu(ListTongSPDB DSTongSPDB);
void InHoaDon(ListSPDB DSSPDB, int &tong);
void ThongTinHoaDon(ListSPDB DSSPDB);
void TraHang(List &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB);
void KhuyenMai(ListSPDB &DSSPDB);
void InThongTinTongSanPhamDB(ListTongSPDB DSTongSPDB);
void InDSTongSanPhamDB(ListTongSPDB DSTongSPDB);
void SanPhamBanChayNhat(ListTongSPDB DSTongSPDB);
void LoiNhuan(ListTongSPDB DSTongSPDB, int TongDoanhThu);
void NhapDSFile(List &DSSP);
void BanSanPham(List &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB, int &tong, int &TongDoanhThu);