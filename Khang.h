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

NodeSP* CreateNode(SanPham x);
NodeSPDB* CreateNodeSPDB(SanPhamDaBan x);
NodeTongSPDB* CreateNodeTongSPDB(TongSanPhamDaBan x);
void AddTail(ListSP &DSSP, SanPham x);
void TaoDSSPDB(ListSPDB &DSSPDB);
void ThemSPDB(ListSP &DSSPDB, SanPhamDaBan x);
void TaoDSTongSPDB(ListTongSPDB &DSTongSPDB);
void ThemTongSPDB(ListTongSPDB &DSTongSPDB, TongSanPhamDaBan x);
SanPham NhapSP();
void InDS(ListSP DSSP);
void HuyDS(ListSP &DSSP);
void HuyDSSPDB(ListSPDB &DSSPDB);
NodeSP* SearchNode(struct SanPham x, ListSP myList);
void BoSungSP(ListSP &DSSP);
void BanSPvaThanhToan(ListSP &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB, int &tong, int &TongDoanhThu);
void InHoaDon(ListSPDB DSSPDB, int &tong);
void ThongTinHoaDon(ListSPDB DSSPDB);
void TraHang(ListSP &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB);
void KhuyenMai(ListSPDB &DSSPDB);
void InThongTinTongSanPhamDB(ListTongSPDB DSTongSPDB);
void InDSTongSanPhamDB(ListTongSPDB DSTongSPDB);
void SanPhamBanChayNhat(ListTongSPDB DSTongSPDB);
void LoiNhuan(ListTongSPDB DSTongSPDB, int TongDoanhThu);
void NhapDSFile(ListSP &DSSP);
void BanSanPham(ListSP &DSSP, ListSPDB &DSSPDB, ListTongSPDB &DSTongSPDB, int &tong, int &TongDoanhThu);