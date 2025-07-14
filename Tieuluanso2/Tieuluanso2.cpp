// Tieuluanso2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
// Tieu luan 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"

// MENU CHUONG TRINH
int main()
{
	Init(L);
	char username[20];
	    printf("|================ DANH SACH QUAN LY THONG TIN SINH VIEN ==================|\n");
	printf("| Nhap ten cua ban:");
	nhapChuoi(username, sizeof(username));
	printf("\n| CHAO MUNG ! %s\n", username);
	int choice;
	do
	{
		printf("\n|=========================================================================|\n");
		printf("|                                Ban muon:                                |\n");
		printf("|=========================================================================|\n");
		printf("|  [1].Them sinh vien  | [2].Hien thi danh sach  | [3].Tim kiem sinh vien |\n");
		printf("|______________________|_________________________|________________________|\n");
		printf("|                      |                         |                        |\n");
		printf("|  [4].Xoa sinh vien   | [5].Chinh sua thong tin | [6].Sap xep danh sach  |\n");
		printf("|______________________|_________________________|________________________|\n");
		printf("|                      |                         |                        |\n");
		printf("|  [7].Ghi ds ra tep   | [8].Doc ds tu tep       | [9].Thoat danh sach    |\n");
		printf("|______________________|_________________________|________________________|\n");
		printf("| Nhap lua chon cua ban [1-9]:");
		scanf_s("%d", &choice);
		while (getchar() != '\n');
		switch (choice)
		{
		case 1:
		{
			char searchchoice;
			printf("| Ban muon them sinh vien:\n");
			printf("| [A].Vao dau danh sach\n");
			printf("| [B].Vao cuoi danh sach\n");
			printf("| Lua chon cua ban [A-B]:");
			scanf_s("%c", &searchchoice, (unsigned int)sizeof(searchchoice));
			while (getchar() != '\n');
			{

			}
			switch (searchchoice)
			{
			case 'A':
				ThemsinhvienHead(L,a); break;
			case 'B':
				ThemsinhvienBack(L,a); break;
			}
		}break;
		case 2:
		{
			xuatdanhsach(L);
		}break;
		case 3:
		{
			char  inforSearch[50];
			printf("| Nhap thong tin cua sinh vien can tim [ MSSV , Hoten , SDT, Diem , Gioitinh ( Nhap gioi tinh ) ]:");
			while (getchar() != '\n');
			nhapChuoi(inforSearch , sizeof(inforSearch));
			if (strcmp(inforSearch, "Nam") == 0 || strcmp(inforSearch, "Nu") == 0) 
			{
				list L2 = Timkiemtheogioitinh(L, inforSearch);
				if (L.pHead == NULL)
				{
					printf("Khong tim duoc sinh vien !");
				}
				else {
					printf("---------------------------------- Tim kiem thanh cong !------------------------------------------\n");
					xuatdanhsach(L2);
				}

			}
			else 
			{
				node* p = Timkiemsinhvien(L, inforSearch);
				if (p)
				{
					printf("Da tim thay sinh vien co MSSV: %s", p->data.mssv);
					xuat1sinhvien(p);
				}
			}
		}break;
		case 4:
		{
			char mssvDelete[10];
			printf("| Nhap MSSV can xoa:");
			while (getchar() != '\n');
			nhapChuoi(mssvDelete, sizeof(mssvDelete));
			Xoasinhvien(L, mssvDelete);
		}break;
		case 5:
		{
			char mssvUpdate[10];
			printf("| Nhap MSSV can cap nhat:");
			while (getchar() != '\n');
			nhapChuoi(mssvUpdate, sizeof(mssvUpdate));
			Capnhatsinhvien(L, mssvUpdate);
		}break;
		case 6:
		{
			int sortchoice;
			printf("| Ban muon sap xep danh sach theo:\n");
			printf("| [1].Ma so sinh vien\n");
			printf("| [2].Ho va ten\n");
			printf("| [3].So dien thoai\n");
			printf("| [4].Diem trung binh\n");
			printf("| Nhap lua chon cua ban [1-4]:");
			scanf_s("%d", &sortchoice);
			switch (sortchoice)
			{
			case 1:
			{
				switch (up_or_down())
				{
				case 'A': sapxepMSSVtangdan(L); break;

				case 'B':sapxepMSSVgiamdan(L); break;
				}
			}break;
			case 2:
			{
				switch (up_or_down())
				{
				case 'A':
					sapxepHotentangdan(L); break;

				case 'B':
					sapxepHotengiamdan(L); break;
				}
			}break;
			case 3:
			{
				switch (up_or_down())
				{
				case 'A':
					sapxepSDTtangdan(L); break;

				case 'B':
					sapxepSDTgiamdan(L); break;
				}
			}break;
			case 4:
			{
				switch (up_or_down())
				{
				case 'A':
					sapxepDTBtangdan(L); break;
				case 'B':
					sapxepDTBgiamdan(L); break;
				}
			}break;
			}
		}break;
		case 7:
		{
			char filename[100];
			printf("| Nhap ten file de ghi du lieu: ");
			while (getchar() != '\n');
			nhapChuoi(filename, sizeof(filename)); // Use the existing `nhapChuoi` function to input the filename.
			ghiFile(L, filename); // Pass the list `L` and the filename to the `ghiFile` function.
		}
		break;
		case 8:
		{
			char filename[100];
			printf("| Nhap ten file de doc du lieu: ");
			while (getchar() != '\n');
			nhapChuoi(filename, sizeof(filename));
			docFile(L, filename);
		}
		case 9: break;
		default: printf("Lenh khong hop le!\n");
		}
	} while (choice != 9);
	clearList(&L);
	printf("================================= TAM BIET %s =================================\n", username);
	return 0;
}

