// DoAn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Khang.h"
//#include "Lap.h"

void main()
{
	List DSSP;
	int start = 1;
	int number;
	taoDS(DSSP);
	nhapDS(DSSP);
	while (start == 1)
	{
		cout << "MENU CHUC NANG:" << endl;
		cout << "1. Xuat danh sach san pham." << endl;
		cout << "2. Them san pham moi." << endl;
		cout << "3. Bo sung so luong san pham." << endl;
		cout << "4. Xoa san pham khoi danh sach." << endl;
		cout << "5. Tim kiem san pham." << endl;
		cout << "6. Kiem tra trang thai san pham." << endl;
		cout << "7. Mua san pham." << endl;
		cout << "8. Xuat hoa don mua hang." << endl;
		cout << "9. Tong doanh thu mua hang." << endl;
		cout << "Thuc hien chuc nang:";
		cin >> number;
		switch (number)
		{
		case 1:
			inDS(DSSP);
			break;
		case 2:

			break;
		case 3:
			cin.ignore();
			bosungSP(DSSP);
			break;
		case 4:
			break;
		case 5:
			timkiemSP(DSSP);
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}
		cout << "Nhap 1 de tiep tuc, nhap 0 de ket thuc:";
		cin >> start;
	}
	huyDS(DSSP);
}

