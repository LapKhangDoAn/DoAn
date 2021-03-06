// Ứng dụng quản lý sản phẩm của cửa hàng bằng danh sách liên kết đơn

#include "pch.h"
#include "DoAn.h"

void main()
{
	ListSP DSSP; // Danh sách các sản phẩm đang kinh doanh của cửa hàng
	ListSPDB DSSPDB; // Danh sách các sản phẩm đã bán trong một lần giao dịch
	ListTongSPDB DSTongSPDB; // Danh sách tổng các sản phẩm đã được bán
	int TongDoanhThu = 0;
	int number = 0;
	char a[100];
	TaoDS(DSSP); 
	NhapDSFile(DSSP); // Nhập danh sách các sản phẩm đang kinh doanh của cửa hàng từ file text
	TaoDSSPDB(DSSPDB); 
	TaoDSTongSPDB(DSTongSPDB); 
	textcolor(10);
	cout << "		___~&~|~&~___=================================================___~&~|~&~___==============================================___~&~|~&~___" << endl;
	cout << "		||                                                                                                                                  ||" << endl;
	cout << "		||            ___    _     _   _____      _     _   _____   _      _   _____                                                        ||" << endl;
	cout << "		||          _(___)_ (_)   (_) (_____)    (_)   (_) (_____) (_)    (_) (_____)                                                       ||" << endl;
	cout << "		||         (_)   (_)(_)   (_)(_)___(_)   (_)___(_)(_)___(_)(__)_  (_)(_)  ___                                                       ||" << endl;
	cout << "		||         (_)    _ (_)   (_)(_______)   (_______)(_______)(_) (_)(_)(_) (___)                                                      ||" << endl;
	cout << "		||         (_)___(_)(_)___(_)(_)   (_)   (_)   (_)(_)   (_)(_)   (__)(_)___(_)                                                      ||" << endl;
	cout << "		||           (___)   (_____) (_)   (_)   (_)   (_)(_)   (_)(_)    (_) (_____)                                                       ||" << endl;
	cout << "		||                                                                                                                                  ||" << endl;
	textcolor(11);
	cout << "		||                                                 _____    _____     ___    _     _     _     _   _____    _____                   ||" << endl;
	cout << "		||                                                (_____)  (_____)  _(___)_ (_)   (_)   (_)   (_) (_____)  (_____)                  ||" << endl;
	cout << "		||                                                (_)__(_)(_)___(_)(_)   (_)(_)___(_)   (_)___(_)(_)   (_)(_)___(_)                 ||" << endl;
	cout << "		||                                                (_____) (_______)(_)    _ (_______)   (_______)(_)   (_)(_______)                 ||" << endl;
	cout << "		||                                                (_)__(_)(_)   (_)(_)___(_)(_)   (_)   (_)   (_)(_)___(_)(_)   (_)                 ||" << endl;
	cout << "		||                                                (_____) (_)   (_)  (___)  (_)   (_)   (_)   (_) (_____) (_)   (_)                 ||" << endl;
	cout << "		||                                                                                                                                  ||" << endl;
	cout << "		___~&~|~&~___================================================___~&~|~&~___===============================================___~&~|~&~___" << endl;
	cout << endl << setw(102) << "CUA HANG BACH HOA XIN CHAO QUY KHACH!" << endl << endl << endl;
	char ch;
	textcolor(9);
	int dem = 0;
	do
	{
		dem = 1 - dem;
		textcolor(14);
		int w = 60;
		for (int i = 0; i < w; i++) cout << "=";
		cout << endl;
		cout <<"|"<< setw(22) << left << " " << "MENU CHUC NANG" << setw(22)<<" "<<"|"<< endl;
		for (int i = 0; i < w; i++) cout << "=";
		cout << endl;
		cout << "|" << setw(2) << " " << "STT" << setw(2) << " " << "|";
		cout << setw(18) << " " << " Ten chuc nang" << setw(18) << " " << "|" << endl;
		for (int i = 0; i < w; i++) cout << "=";
		cout << endl;
		cout << "|" << setw(3) << " " << "1" << setw(3) << " " << "|";
		cout << setw(13) << " " << " Xuat danh sach san pham" << setw(13) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "2" << setw(3) << " " << "|";
		cout << setw(16) << " " << " Them san pham moi" << setw(16) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "3" << setw(3) << " " << "|";
		cout << setw(12) << " " << " Bo sung so luong san pham" << setw(12) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "4" << setw(3) << " " << "|";
		cout << setw(11) << " " << " Xoa san pham khoi danh sach" << setw(11) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "5" << setw(3) << " " << "|";
		cout << setw(16) << " " << " Tim kiem san pham" << setw(16) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "6" << setw(3) << " " << "|";
		cout << setw(12) << " " << " Ban san pham va thanh toan" << setw(11) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "7" << setw(3) << " " << "|";
		cout << setw(12) << " " << " Sap xep hang hoa theo gia" << setw(12) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "8" << setw(3) << " " << "|";
		cout << setw(13) << " " << " Tong doanh thu ban hang" << setw(13) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "9" << setw(3) << " " << "|";
		cout << setw(9) << " " << " San pham ban chay nhat cua hang" << setw(9) << " " << "|" << endl;
		cout << "|" << setw(2) << " " << "10" << setw(3) << " " << "|";
		cout << setw(6) << " " << " Kiem tra han su dung cua cac san pham" << setw(6) << " " << "|" << endl;
		cout << "|" << setw(2) << " " << "11" << setw(3) << " " << "|";
		cout << setw(13) << " " << " Loi nhuan cua cua hang" << setw(14) << " " << "|" << endl;
		for (int i = 0; i < w; i++) cout << "=";
		cout << endl;
		textcolor(15);
		cout << "Thuc hien chuc nang:";
		cin >> number;
		cin.ignore();
		switch (number)
		{
		case 1:
			textcolor(11);
			InThongTin(DSSP);
			textcolor(15);
			break;
		case 2:
			ThemSP(DSSP);
			break;
		case 3:
			BoSungSP(DSSP);
			break;
		case 4:
		{
			textcolor(12);
			cout << "Nhap ma san pham:";
			cin.getline(a, 100);
			if (RemoveX(DSSP, a) == 0)
				cout << "San Pham Muon Xoa Khong Co Trong Danh Sach San Pham!!!" << endl;
			else
			{
				textcolor(11);
				InThongTin(DSSP);
				textcolor(15);
			}
			break;
		}
		case 5:
			TimKiem(DSSP);
			break;
		case 6:
			int tong;
			BanSPvaThanhToan(DSSP, DSSPDB, DSTongSPDB, tong, TongDoanhThu);
			textcolor(15);
			break;
		case 7:
			SapXep(DSSP);
			textcolor(11);
			InThongTin(DSSP);
			textcolor(15);
			break;
		case 8:
			textcolor(12);
			cout <<"Tong doanh thu cua hang la:"<< TongDoanhThu <<" VND"<< endl;
			textcolor(15);
			break;
		case 9:
			InThongTinTongSanPhamDB(DSTongSPDB);
			break;
		case 10:
			KiemTraHanSD(DSSP);
			cout << endl;
			break;
		case 11:
			LoiNhuan(DSTongSPDB, TongDoanhThu);
			break;
		}
		cout << "Nhan phim bat ki de tiep tuc, nhan ESC de ket thuc chuong trinh!" << endl;
		if (dem==0)
			cin.ignore();
		ch = _getche();
	} while ( ch!= 27);
	HuyDS(DSSP); 
}

