// DoAn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "DoAn.h"

void main()
{
	List DSSP;
	ListSPDB DSSPDB;
	ListTongSPDB DSTongSPDB;
	int TongDoanhThu = 0;
	/*char start[20];*/
	int number = 0;
	char a[100];
	taoDS(DSSP); //Danh sach cac mat hang cua cua hang
	nhapDS(DSSP);
	taoDSSPDB(DSSPDB); //Danh sach cac san pham da ban trong 1 lan mua
	taoDSTongSPDB(DSTongSPDB); //Danh sach tong cac san pham da duoc ban
	do
	{
		cout << "MENU CHUC NANG:" << endl;
		cout << "1. Xuat danh sach san pham." << endl;
		cout << "2. Them san pham moi." << endl;
		cout << "3. Bo sung so luong san pham." << endl;
		cout << "4. Xoa san pham khoi danh sach." << endl;
		cout << "5. Tim kiem san pham." << endl;
		cout << "6. Mua san pham." << endl;
		cout << "7. Sap xep hang hoa theo gia." << endl;
		cout << "8. Tong doanh thu mua hang." << endl;
		cout << "9. Ban chay nhat cua hang." << endl;
		cout << "Thuc hien chuc nang:";
		cin >> number;
		switch (number)
		{
		case 1:
			InThongTin(DSSP);
			break;
		case 2:
			ThemSP(DSSP);
			break;
		case 3:
			cin.ignore();
			bosungSP(DSSP);
			break;
		case 4:
		{
			cin.ignore();
			cout << "Nhap ma san pham:";
			cin.getline(a, 100);
			if (RemoveX(DSSP, a) == 0)
				cout << "San Pham Muon Xoa Khong Co Trong Danh Sach San Pham!!!" << endl;
			else
				InThongTin(DSSP);
			break;
		}
		case 5:
			TimKiem(DSSP);
			break;
		case 6:
			int tong;
			muaSP(DSSP, DSSPDB, DSTongSPDB,tong, TongDoanhThu);
			break;
		case 7:
			SapXep(DSSP);
			InThongTin(DSSP);
			break;
		case 8:
			cout << TongDoanhThu << endl;
			break;
		case 9:
			inThongTinTongSanPhamDB(DSTongSPDB);
			break;
		}
		cout << "Nhan phim bat ki de tiep tuc, nhan ESC de ket thuc chuong trinh!" << endl;
	} while (_getch() != 27);
	huyDS(DSSP);
}

