#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Header.h"

sinhvien a;
list L;

// Buoc 2: Ham tao 1 node
node* getNode(sinhvien a)
{
	node* p;
	p = (node*)malloc(sizeof(node));
	if (p == NULL)
	{
		printf("Khong de bo nho!\n");
		return NULL;    // phải return NULL nếu malloc thất bại
	}
	p->data = a;
	p->next = NULL;
	return p;
}
// Buoc 3: Ham tao danh sach rong
void Init(list& L)
{
	L.pHead = L.pTail = NULL;
}

// Buoc 4: Ham them node vao dau danh sach
void addHead(list& L, sinhvien a)
{
	node* p = getNode(a);
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		p->next = L.pHead;
		L.pHead = p;
	}
}
// Buoc 5: Ham them node vao cuoi danh sach
void addBack(list& L, sinhvien a)
{
	node* p = getNode(a);
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		L.pTail->next = p;
		L.pTail = p;
	}
}
// HAM NHAP CHUOI
void nhapChuoi(char* str, int sizeofstr)
{
	fgets(str, sizeofstr, stdin);
	str[strcspn(str, "\n")] = '\0';
}
// HAM KIEM TRA MSSV
int isValidMSSV(const char* mssv) {
	int len = strlen(mssv);
	if (len == 0 || len > 8) return 0; // Không được rỗng và không quá 8 ký tự
	for (int i = 0; i < len; i++) {
		if (!isdigit(mssv[i])) return 0; // Từng ký tự phải là chữ số
	}
	return 1;
}



// CAC HAM CHUC NANG
// THEM n SINH VIEN VAO DAU DANH SACH
void ThemsinhvienHead(list& L, sinhvien sv) // Pass sinhvien by reference to initialize it properly
{
	int slsv = 0;
	while(true){
		printf("Nhap thong tin sinh vien thu %d\n", slsv + 1);
		do {
			while (getchar() != '\n'); // xóa bỏ ký tự '\n' còn sót lại
			printf("Nhap MSSV (nhap 0 de ket thuc): ");
			nhapChuoi(sv.mssv, sizeof(sv.mssv));
			if (strcmp(sv.mssv, "0") == 0) {
				printf(" Ket thuc thanh cong !\n");
				return;
			}
			if (!isValidMSSV(sv.mssv))
			{
				printf("MSSV khong hop le!\n");
			}
		} while (!isValidMSSV(sv.mssv));
		//printf("DEBUG: MSSV: %s\n", sv.mssv);

		printf("Nhap Ho va Ten: ");
		nhapChuoi(sv.hoten, sizeof(sv.hoten));
		//printf("DEBUG: Hoten: %s\n", sv.hoten);

		printf("Nhap So dien thoai: ");
		nhapChuoi(sv.sdt, sizeof(sv.sdt));
		//printf("DEBUG: Sodienthoai: %s\n", sv.sdt);

		printf("Nhap Gioi tinh (Nam/Nu): ");
		nhapChuoi(sv.gioitinh, sizeof(sv.gioitinh));
		//printf("DEBUG: Gioi tinh: %s\n", sv.gioitinh);

		printf("Nhap ngay thang nam sinh\n");
		printf("Nhap ngay sinh (dd) : ");
		scanf_s("%d", &sv.ngaysinh.day);

		printf("Nhap thang sinh (mm) : ");
		scanf_s("%d", &sv.ngaysinh.month);

		printf("Nhap nam sinh (yyyy) : ");
		scanf_s("%d", &sv.ngaysinh.year);
		while (getchar() != '\n'); // xóa bỏ ký tự '\n' còn sót lại

		printf("Nhap ma lop: ");
		nhapChuoi(sv.malop, sizeof(sv.malop));


		printf("Nhap diem trung binh: ");
		while (scanf_s("%f", &sv.dtb) != 1)
		{
			printf("Nhap diem sai . Vui long nhap lai");
			while (getchar() != '\n');
		}// Change %d to %f for float type
		while (getchar() != '\n'); // xóa '\n'
		addHead(L, sv);
		slsv++;
	} 
}
// THEM n SINH VIEN VAO CUOI DANH SACH
void ThemsinhvienBack(list& L, sinhvien sv) // Pass sinhvien by reference to initialize it properly
{
	int slsv = 0;
	while (true) {
		printf("| Nhap thong tin sinh vien thu %d \n", slsv + 1);
		while (getchar() != '\n'); // xóa bỏ ký tự '\n' còn sót lại
		do {
			printf("| Nhap MSSV (nhap 0 de ket thuc): ");
			nhapChuoi(sv.mssv, sizeof(sv.mssv));
			if (strcmp(sv.mssv, "0") == 0) {
				printf(" Ket thuc thanh cong !\n");
				return;
			}
			if (!isValidMSSV(sv.mssv))
			{
				printf("MSSV khong hop le!\n");
			}
		} while (!isValidMSSV(sv.mssv));
		//printf("DEBUG: MSSV: %s\n", sv.mssv);

		printf("| Nhap Ho va Ten: ");
		nhapChuoi(sv.hoten, sizeof(sv.hoten));
		//printf("DEBUG: Hoten: %s\n", sv.hoten);

		printf("| Nhap So dien thoai: ");
		nhapChuoi(sv.sdt, sizeof(sv.sdt));
		//printf("DEBUG: Sodienthoai: %s\n", sv.sdt);

		printf("| Nhap Gioi tinh (Nam/Nu): ");
		nhapChuoi(sv.gioitinh, sizeof(sv.gioitinh));
		//printf("DEBUG: Gioi tinh: %s\n", sv.gioitinh);

		printf("| Nhap ngay thang nam sinh\n");
		printf("| Nhap ngay sinh (dd) : ");
		scanf_s("%d", &sv.ngaysinh.day);

		printf("| Nhap thang sinh (mm) : ");
		scanf_s("%d", &sv.ngaysinh.month);

		printf("| Nhap nam sinh (yyyy) : ");
		scanf_s("%d", &sv.ngaysinh.year);
		while (getchar() != '\n'); // xóa bỏ ký tự '\n' còn sót lại

		printf("| Nhap ma lop: ");
		nhapChuoi(sv.malop, sizeof(sv.malop));


		printf("| Nhap diem trung binh: ");
		while (scanf_s("%f", &sv.dtb) != 1)
		{
			printf("| Nhap diem sai ! Vui long nhap lai");
			while (getchar() != '\n');
		}// Change %d to %f for float type
		while (getchar() != '\n'); // xóa '\n'
		addBack(L, sv);
		slsv++;
	}
}
// HAM IN RA DANH SACH SINH VIEN
void xuat1sinhvien(node* temp)  // xuat 1 sinh vien
{
	sinhvien a = temp->data;
	printf("\n---------------------------------------------------------------------------------------------------\n");
	printf("\n----------------------------------THONG TIN SINH VIEN ---------------------------------------------\n");
	printf("| %-10s | %-20s | %-12s | %-10s | %02d/%02d/%04d  | %-8s | %-6.2f |\n",
		a.mssv,
		a.hoten,
		a.sdt,
		a.gioitinh,
		a.ngaysinh.day,
		a.ngaysinh.month,
		a.ngaysinh.year,
		a.malop,
		a.dtb);
}
void xuatdanhsach(list& L)  // xuat ca danh sach
{
	node* temp = L.pHead;
	printf("--------------------------------------------------------------------------------------------------\n");
	printf("| %-10s | %-20s | %-12s | %-10s | %-10s | %-8s | %-6s |\n",
		"MSSV", "Ho ten", "SDT", "Gioi tinh", "Ngay sinh", "Ma lop", "DTB");
	printf("--------------------------------------------------------------------------------------------------\n");

	while (temp != NULL)
	{
		sinhvien a = temp->data;
		printf("| %-10s | %-20s | %-12s | %-10s | %02d/%02d/%04d | %-8s | %-6.2f |\n",
			a.mssv,
			a.hoten,
			a.sdt,
			a.gioitinh,
			a.ngaysinh.day,
			a.ngaysinh.month,
			a.ngaysinh.year,
			a.malop,
			a.dtb);
		temp = temp->next;
	}
	printf("--------------------------------------------------------------------------------------------------\n");
}
// HAM TIM KIEM SINH VIEN
node* Timkiemsinhvien(list& L, char inforSearch[])
{
	node* temp = L.pHead;
	while (temp != NULL)
	{
		if (strcmp(temp->data.mssv, inforSearch) == 0 ||
			strcmp(temp->data.hoten, inforSearch) == 0 ||
			strcmp(temp->data.sdt, inforSearch) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	printf("| Khong tim duoc sinh vien !\n");
	return NULL;
}

// Ham tim kiem hoc sinh theo gioi tinh Nam/Nu
list Timkiemtheogioitinh(list& L, char inforsearch[])
{
	list L2;
	Init(L2);
	node* p = L.pHead;
	while (p != NULL)
	{
		if (strcmp(p->data.gioitinh, inforsearch) == 0)
		{
			addHead(L2, p->data);
		}
		p = p->next;
	}
	return L2;
}
// HAM HOAN DOI
void swap(sinhvien* a, sinhvien* b)
{
	sinhvien temp = *a;
	*a = *b;
	*b = temp;
}
// HAM XOA MOT SINH VIEN
void Xoasinhvien(list& L, char mssvDelete[])
{
	node* temp = L.pHead;
	// Tim node can xoa
	// 	while (temp != NULL)
	while (temp != NULL) {
		if (!Timkiemsinhvien(L, mssvDelete)) return;
		else
		{
			printf("| Thong tin sinh vien \n");
			xuat1sinhvien(temp);
			break;
		}
		temp = temp->next;
	}
	// Kiem tra danh sach rong 
	if (L.pHead == NULL || temp == NULL) return;
	// Neu chi co 1 node trong danh sach
	if (L.pHead == temp && temp->next == NULL)
	{
		free(temp);
		L.pHead = L.pTail = NULL;
		printf("| Xoa sinh vien co MSSV [%s] thanh cong!\n", mssvDelete);
		return;
	}
	/* Neu p la node cuoi cung */
	if (L.pTail == temp)
	{
		node* prev = L.pHead;
		while (prev->next != temp)
		{
			prev = prev->next;
		}
		prev->next = NULL;
		L.pTail = prev;
		free(temp);
		printf("| Xoa sinh vien co MSSV [%s] thanh cong!\n", mssvDelete);
		return;
	}
	else
	{
		node* temp1next = temp->next;
		node* temp2next = temp1next->next;
		swap(&temp->data, &temp1next->data);
		temp->next = temp2next;
		temp1next->next = NULL;
		free(temp1next);
		printf("Xoa sinh vien co MSSV [%s] thanh cong!\n", mssvDelete);
		return;
	}
}
// Ham kiem tra chuoi ky tu la chu so
int isDigit(char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}
// Cap nhat thong tin cua mot sinh vien 
void Suasinhvien(sinhvien* sv) {
	while (getchar() != '\n'); // xóa bỏ ký tự '\n' còn sót lại
	do {
		printf("| Nhap MSSV: ");
		nhapChuoi(sv->mssv, sizeof(sv->mssv));
		if (!isValidMSSV(sv->mssv))
		{
			printf("MSSV khong hop le!\n");
		}
	} while (!isValidMSSV(sv->mssv));
	//printf("DEBUG: MSSV: %s\n", sv->mssv);

	printf("| Nhap Ho va Ten: ");
	nhapChuoi(sv->hoten, sizeof(sv->hoten));
	//printf("DEBUG: Hoten: %s\n", sv->hoten);

	printf("| Nhap So dien thoai: ");
	nhapChuoi(sv->sdt, sizeof(sv->sdt));
	//printf("DEBUG: Sodienthoai: %s\n", sv->sdt);

	printf("| Nhap Gioi tinh (Nam/Nu): ");
	nhapChuoi(sv->gioitinh, sizeof(sv->gioitinh));
	//printf("DEBUG: Gioi tinh: %s\n", sv->gioitinh);

	printf("| Nhap ngay thang nam sinh\n");
	printf("| Nhap ngay sinh (dd) : ");
	scanf_s("%d", &sv->ngaysinh.day);

	printf("| Nhap thang sinh (mm) : ");
	scanf_s("%d", &sv->ngaysinh.month);

	printf("| Nhap nam sinh (yyyy) : ");
	scanf_s("%d", &sv->ngaysinh.year);
	while (getchar() != '\n'); // xóa bỏ ký tự '\n' còn sót lại

	printf("| Nhap ma lop: ");
	nhapChuoi(sv->malop, sizeof(sv->malop));


	printf("| Nhap diem trung binh: ");
	while (scanf_s("%f", &sv->dtb) != 1)
	{
		printf("| Nhap diem sai ! Vui long nhap lai");
		while (getchar() != '\n');
	}// Change %d to %f for float type
	while (getchar() != '\n'); // xóa '\n'
}
void Capnhatsinhvien(list& L, char mssvUpdate[])
{
	if (!isDigit(mssvUpdate))
	{
		printf("| MSSV khong hop le!\n");
		return;
	}
	node* p = Timkiemsinhvien(L, mssvUpdate);
	if (p)
	{
		printf("| Tim thay sinh vien co MSSV: %s\n", mssvUpdate);
		xuat1sinhvien(p);
		printf("-----CAP NHAT THONG TIN SINH VIEN (NHAN ENTER DE TIEP TUC)----\n");
		char oldmssv[10];
		strcpy_s(oldmssv, p->data.mssv);
		Suasinhvien(&p->data);
		strcpy_s(p->data.mssv, oldmssv);
		printf("----------------CAP NHAT THONG TIN THANH CONG-----------------\n");
	}
	else
	{
		printf("Khong tim thay sinh vien co MSSV: %s\n", mssvUpdate);
	}
}
/* Sap xep danh sach theo tieu chi(VD: tang / giam theo diem, theo ten)
   Thuat toan sap xep Interchange Sort:
   for( i = 0; i < n; i++ )
	 for (j = i+1 ; j<n; j++)
	   if s[i] > s[j]
		 swap(s[i],s[j])
*/
void sapxepMSSVtangdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		for (node* psau = p->next; psau != NULL; psau = psau->next)
		{
			if (strcmp(p->data.mssv, psau->data.mssv) > 0)
				swap(&p->data, &psau->data);
		}
	}
	printf("----Sap xep sinh vien theo MSSV tang dan thanh cong!----\n");
}
void sapxepMSSVgiamdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		for (node* psau = p->next; psau != NULL; psau = psau->next)
		{
			if (strcmp(p->data.mssv, psau->data.mssv) < 0)
				swap(&p->data, &psau->data);
		}
	}
	printf("----Sap xep sinh vien theo MSSV giam dan thanh cong!----\n");
}
// Sap xep theo Ho ten
/* Thuat toan Bubble Sort:
   for i = 0 -> n ; i++
	  for j = i -> n ; j++
		 if s[j] > s[j+1]
		  swap(s[j], s[j+1])
*/
void sapxepHotentangdan(list& L)
{
	if (L.pHead == NULL || L.pHead->next == NULL)
		return;  // Danh sách rỗng hoặc chỉ có 1 phần tử

	for (node* i = L.pHead; i->next != NULL; i = i->next)
	{
		for (node* j = L.pHead; j->next != NULL; j = j->next)
		{
			if (strcmp(j->data.hoten, j->next->data.hoten) > 0)
			{
				swap(&j->data, &j->next->data);
			}
		}
	}
	printf("----Sap xep sinh vien theo Ho ten tang dan thanh cong!----\n");
}

void sapxepHotengiamdan(list& L)
{
	if (L.pHead == NULL || L.pHead->next == NULL)
		return;  // Danh sách rỗng hoặc chỉ có 1 phần tử

	for (node* i = L.pHead; i->next != NULL; i = i->next)
	{
		for (node* j = L.pHead; j->next != NULL; j = j->next)
		{
			if (strcmp(j->data.hoten, j->next->data.hoten) < 0)
			{
				swap(&j->data, &j->next->data);
			}
		}
	}
	printf("----Sap xep sinh vien theo Ho ten giam dan thanh cong!----\n");
}

/* Sap xep theo SDT
   Thuat toan Insertion Sort:
   -> Phai tim p truoc cua p -> phai duyet lai mang -> Khong hieu qua

Thuat toan Selection Sort:
	for i = 0, i<n , i++{
	  min = i
	  for j=i+1, j<n, j++{
		 if (s[j] < s[min])
			min = j;
	  }
	  swap(s[i],s[min]);
	 }
*/
void sapxepSDTtangdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		node* min = p;
		for (node* q = p->next; q != NULL; q = q->next)
		{
			if (strcmp(q->data.sdt, min->data.sdt) < 0)
				min = q;
		}
		swap(&p->data, &min->data);
	}
	printf("----Sap xep sinh vien theo SDT tang dan thanh cong!----\n");
}
void sapxepSDTgiamdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		node* max = p;
		for (node* q = p->next; q != NULL; q = q->next)
		{
			if (strcmp(q->data.sdt, max->data.sdt) > 0)
				max = q;
		}
		swap(&p->data, &max->data);
	}
	printf("----Sap xep sinh vien theo SDT giam dan thanh cong!----\n");
}
// Sap xep theo diem trung binh
void sapxepDTBtangdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		node* min = p;
		for (node* q = p->next; q != NULL; q = q->next)
		{
			if (q->data.dtb < min->data.dtb)
				min = q;
		}
		if (p != min)
			swap(&p->data, &min->data);
	}
	printf("----Sap xep sinh vien theo DTB tang dan thanh cong!----\n");
}
void sapxepDTBgiamdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		node* max = p;
		for (node* q = p->next; q != NULL; q = q->next)
		{
			if (q->data.dtb > max->data.dtb)
				max = q;
		}
		if (p != max)
			swap(&p->data, &max->data);
	}
	printf("----Sap xep sinh vien theo DTB giam dan thanh cong!----\n");
}
// Ghi du lieu ra tep va doc du lieu tu tep
// HAM DOC DU LIEU TU TEP
void docFile(list& L, const char* filename)
{
	FILE* f = fopen(filename, "r");  // dùng fopen thay vì fopen_s

	if (f == NULL)
	{
		printf("Khong mo duoc file %s de doc!\n", filename);
		return;
	}

	sinhvien sv;
	int count = 0;

	while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d|%[^|]|%f\n",
		sv.mssv,
		sv.hoten,
		sv.sdt,
		sv.gioitinh,
		&sv.ngaysinh.day,
		&sv.ngaysinh.month,
		&sv.ngaysinh.year,
		sv.malop,
		&sv.dtb) == 9)
	{
		addBack(L, sv);
		count++;
	}
	fclose(f);
	printf("| Doc file thanh cong! Da them %d sinh vien vao danh sach.\n", count);
}

// HAM GHI DU LIEU VAO TEP
void ghiFile(list& L, const char* filename)
{
	FILE* f = NULL;
	fopen_s(&f, filename, "w");
	if (f == NULL)
	{
		printf("| Khong mo duoc file %s de ghi!\n", filename);
		return;
	}
	node* p = L.pHead;
	while (p != NULL)
	{
		sinhvien sv = p->data;
		fprintf(f, "%s|%s|%s|%s|%02d|%02d|%04d|%s|%.2f\n",
			sv.mssv,
			sv.hoten,
			sv.sdt,
			sv.gioitinh,
			sv.ngaysinh.day,
			sv.ngaysinh.month,
			sv.ngaysinh.year,
			sv.malop,
			sv.dtb
		);
		p = p->next;
	}
	fclose(f);
	printf("| Ghi file thanh cong vao %s:\n", filename);
}
// Ham lua chon sap xep tang dan hoac giam dan
char up_or_down()
{
	char updownchoice;
	printf("Ban muon sap xep theo chieu:\n");
	printf("[A].Tang dan\n");
	printf("[B].Giam dan\n");
	printf("Lua chon cua ban [A-B]:");
	scanf_s(" %c", &updownchoice, (unsigned int)sizeof(updownchoice));
	return updownchoice;
}
// Ham giai phong ham
void clearList(list*L) {
	node* current = L->pHead;
	while (current != NULL) {
		node* temp = current;
		current = current->next;
		free(temp); // Giải phóng từng node
	}

	// Cập nhật lại danh sách về rỗng
	L->pHead = NULL;
	L->pTail = NULL;

	printf("| Danh sach da duoc giai phong bo nho hoan toan.\n");
}