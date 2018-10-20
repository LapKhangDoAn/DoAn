#define max 100

struct SanPhamDaBan
{
	char Ten_spdb[max];
	int Sldb;
	int Gia_Bandb;
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

Node* createNode(SanPham x);
NodeSPDB* createNodeSPDB(SanPhamDaBan x);
void addTail(List &DSSP, SanPham x);
void taoDSSPDB(ListSPDB &DSSPDB);
void themSPDB(List &DSSPDB, SanPhamDaBan x);
SanPham nhapSP();
void nhapDS(List &DSSP);
void inDS(List DSSP);
void huyDS(List &DSSP);
void huyDSSPDB(ListSPDB &DSSPDB);
Node* searchNode(struct SanPham x, List myList);
void bosungSP(List &DSSP);
void muaSP(List &DSSP, ListSPDB &DSSPDB, ListSPDB &DSTongSPDB);
void tongDoanhThu(ListSPDB DSTongSPDB);
void InHoaDon(ListSPDB DSSPDB);
void ThongTinHoaDon(ListSPDB DSSPDB);