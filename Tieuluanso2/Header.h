#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ==== CẤU TRÚC DỮ LIỆU ====
typedef struct ngaysinh {
    int day, month, year;
};

typedef struct sinhvien {
    char mssv[10];
    char hoten[50];
    char sdt[15];
    char gioitinh[10];
    ngaysinh ngaysinh;
    char malop[10];
    float dtb;
};

typedef struct node {
    sinhvien data;
    struct node* next;
};

typedef struct list {
    node* pHead, *pTail;
};
extern list L;
extern sinhvien a;

// ==== KHAI BÁO HÀM ====

// Khởi tạo danh sách và node
void Init(list& L);
node* getNode(sinhvien a);

// Thêm node
void addHead(list& L, sinhvien a);
void addBack(list& L, sinhvien a);

// Nhập liệu
void nhapChuoi(char* str, int sizeofstr);
int isValidMSSV(const char* mssv);
// Nhập thêm sinh viên
void ThemsinhvienHead(list &L, sinhvien sv);
void ThemsinhvienBack(list& L, sinhvien sv);

// Xuất sinh viên
void xuat1sinhvien(node* temp);
void xuatdanhsach(list& L);

// Tìm kiếm
node* Timkiemsinhvien(list& L, char inforSearch[]);
list Timkiemtheogioitinh(list& L, char inforsearch[]);

// Xoá
void Xoasinhvien(list& L, char mssvDelete[]);

// Cập nhật
void Capnhatsinhvien(list& L, char mssvUpdate[]);
void Suasinhvien(sinhvien* sv);
// Sắp xếp
void swap(sinhvien* a, sinhvien* b);
void sapxepMSSVtangdan(list& L);
void sapxepMSSVgiamdan(list& L);
void sapxepHotentangdan(list& L);
void sapxepHotengiamdan(list& L);
void sapxepSDTtangdan(list& L);
void sapxepSDTgiamdan(list& L);
void sapxepDTBtangdan(list& L);
void sapxepDTBgiamdan(list& L);

// File I/O
void docFile(list& L, const char* filename);
void ghiFile(list& L, const char* filename);

// Kiểm tra
int isDigit(char str[]);

// Lựa chọn sắp xếp
char up_or_down();
// Giải phóng danh sách
void clearList(list* L);