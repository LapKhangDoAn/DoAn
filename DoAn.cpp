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
	TaoDS(DSSP); //Danh sach cac mat hang cua cua hang
	NhapDSFile(DSSP);
	TaoDSSPDB(DSSPDB); //Danh sach cac san pham da ban trong 1 lan mua
	TaoDSTongSPDB(DSTongSPDB); //Danh sach tong cac san pham da duoc ban
	textcolor(12);
	cout << "___~&~|~&~___============================================___~&~|~&~___==========================================___~&~|~&~___" << endl;
	
	cout <<"||"<<"                                                                                                                         ||" <<endl;

	cout<<"||" << "	.| '''',  ||   ||      /.\         ||  ||      /.\      ||\   ||  .|'''''| " << "                                           ||" << endl;
	cout<<"||" << "	||        ||   ||     // \\        ||  ||     // \\     ||\\  ||  || .     " << "                                           ||" << endl;
	cout<<"||" << "	||        ||   ||    //...\\       ||''||    //...\\    || \\ ||  || |''|| " << "                                           ||" << endl;
	cout<<"||" << "	||        ||   ||   //     \\      ||  ||   //     \\   ||  \\||  ||    ||" << "                                            ||" << endl;
	cout<<"||" << "	`|....'   `|...|'  //       \\     ||  ||  //       \\  ||   \||  `|....|' " << "                                           ||" << endl;
	cout <<"||" <<"                                                                                                                         ||" << endl;
	cout << "||" << "						||''' |     /.\      .| '''', ||  ||      ||  ||  .|''''|,     /.\ " << "          || "<<endl;
	cout << "||" << "						||   ||    // \\     ||       ||  ||      ||  ||  ||    ||    // \\" << "          ||" << endl;
	cout << "||" << "						||;;;;    //...\\    ||       ||''||      ||''||  ||    ||   //...\\" << "         ||" << endl;
	cout << "||" << "						||   ||  //     \\   ||       ||  ||      ||  ||  ||    ||  //     \\" << "        ||" << endl;
	cout << "||" << "						||... | //       \\  `|....' .||  ||      ||  ||  `|....|' //       \\" << "       ||" << endl;
	cout << "||" << "                                                                                                                         ||"<<endl;
	cout<<"___~&~|~&~___===========================================___~&~|~&~___===========================================___~&~|~&~___"<<endl;

	textcolor(9);
	do
	{
		textcolor(9);
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
		cout << setw(18) << " " << " Mua san pham" << setw(19) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "7" << setw(3) << " " << "|";
		cout << setw(12) << " " << " Sap xep hang hoa theo gia" << setw(12) << " " << "|" << endl;
		cout << "|" << setw(3) << " " << "8" << setw(3) << " " << "|";
		cout << setw(13) << " " << " Tong doanh thu mua hang" << setw(13) << " " << "|" << endl;
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
			cin.ignore();
			BoSungSP(DSSP);
			break;
		case 4:
		{
			textcolor(12);
			cin.ignore();
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
			MuaSP(DSSP, DSSPDB, DSTongSPDB, tong, TongDoanhThu);
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
	} while (_getch() != 27);
	HuyDS(DSSP);
}

