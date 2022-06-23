#pragma once
#define MAXLOPTC 10000
#define MAXSINHVIEN	5000
#define STACKSIZE 	1000

//DANH SACH MON HOC - CAY
struct monhoc{
	char MAMH[10];
	char TENMH[50] ;
	int STCLT ;
	int STCTH ;
};
typedef struct monhoc MONHOC;
struct nodemonhoc{
	monhoc mh;
	nodemonhoc *left;
	nodemonhoc *right;
};
typedef struct nodemonhoc* PTRMH;

//DANH SACH SINH VIEN - MANG
struct sinhvien{
	char MASV[15];
	char HO[50];
	char TEN[10];
	char PHAI[4];
	char SDT[11];
	char MALOP[15];
};
typedef struct sinhvien SINHVIEN;
struct danhsachsinhvien{
	int soluong_SV;
	SINHVIEN SV[MAXSINHVIEN];
};
typedef struct danhsachsinhvien DSSV;

//DANH SACH DANG KY LOP TIN CHI - DSLK DON
struct dkloptc{
	char MASV[15];
	int TRANGTHAI;
	float DIEM;
};
typedef struct dkloptc DKLOPTC;
struct nodedkloptc{
	DKLOPTC dkltc;
	nodedkloptc* next;
};
typedef struct nodedkloptc* PTRDKLOPTC;
//DANH SACH LOP TIN CHI - MANG CON TRO
struct loptc{
	int MALOPTC;
	char MAMH[10];
	char NIENKHOA[9];
	int HOCKY;
	int NHOM;
	int SOSVMIN;
	int SOSVMAX;
	int TRANGTHAI;
	//contro
	PTRDKLOPTC DSDK;
};
typedef struct loptc LTC;
struct dsloptc{
	int soluong_ltc;
	LTC *LOPTC[MAXLOPTC];
};
typedef struct dsloptc DSLOPTC;
