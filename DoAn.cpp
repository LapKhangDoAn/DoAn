// DoAn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Khang.h"
//#include "Lap.h"

void main()
{
	List DSSP;
	int start = 0;
	int number = 0;
	char a[100];
	taoDS(DSSP);
	nhapDS(DSSP);
	do
	{
		cout << "MENU CHUC NANG:" << endl;
		cout << "1. Xuat danh sach san pham." << endl;
		cout << "2. Them san pham moi." << endl;
		cout << "3. Bo sung so luong san pham." << endl;
		cout << "4. Xoa san pham khoi danh sach." << endl;
		cout << "5. Tim kiem san pham." << endl;
		cout << "6. Mua san pham." << endl;
		cout << "7. Xuat hoa don mua hang." << endl;
		cout << "8. Tong doanh thu mua hang." << endl;
		cout << "Thuc hien chuc nang:";
		cin >> number;
		switch (number)
		{
		case 1:
			InThongTin(DSSP);
			break;
		case 2:

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
			muaSP(DSSP);
			break;
		case 7:
		
			break;
		case 8:
			break;
	
		}
		cout << "Nhap 1 de tiep tuc, nhap bat ky de ket thuc:";
		cin >> start;
	} while (start == 1);
	huyDS(DSSP);
}

