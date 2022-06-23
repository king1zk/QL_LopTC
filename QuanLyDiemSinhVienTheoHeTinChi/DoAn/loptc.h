#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include "khaibao_Struct.h"
#include "sinhvien.h"
#include "monhoc.h"
#include "Frame.h"
using namespace std;

//===========================KHAI BAO NGUYEN MAU HAM==========================
void DocFileLopTC(DSLOPTC &ds);
void LuuFileLopTC(DSLOPTC ds);
int check_MaLTC(DSLOPTC ds, int check);
int check_SVDKLTC(PTRDKLOPTC ds, char MaSV[]);
int DemSV_DKLTC(PTRDKLOPTC ds);
int DemAllSV_DKLTC(PTRDKLOPTC ds);
void Insert_FirstDKLTC(PTRDKLOPTC &ds,  DKLOPTC dk);
void Insert_LastDKLTC(PTRDKLOPTC &ds,  DKLOPTC dk);
void Insert_OrderDKLTC(PTRDKLOPTC &ds, DKLOPTC dk);
void AddSV_DKLTC(LTC *&ds, char MaSV[]);
void MangTam_LTC_NK_HK(DSLOPTC dsltc, DSLOPTC &LopTC, char NK[], int HK);
PTRDKLOPTC FindSV_DKLTC(PTRDKLOPTC &ds, char MaSV[]);
LTC *Find_LTC(DSLOPTC &ds, int MaLTC);
LTC *Find_LTC (DSLOPTC &ds, char NK[], int HK, int Nhom, char MaMH[]);
void DKLTC(DSLOPTC &ds, SINHVIEN sv);
void Selection_SortSV_DKLTC (PTRDKLOPTC &ds);
void Huy_DKLTC(DSLOPTC &ds, SINHVIEN sv);
void XuatDS_DangKyLTC(DSLOPTC &dsltc, SINHVIEN sv, char NK[], int HK, PTRMH root);
void SV_DangKyLTC(DSSV dsSV, DSLOPTC &dsltc, PTRMH root);
void Nhap_NK_HK_Nhom_MH(DSLOPTC &dsltc, DSSV dssv, PTRMH root, int chedo); //che do 1: nhapdiem, chedo 2: Xuatdiem
void MangTam_SVDKLTC(PTRDKLOPTC ds, DKLOPTC p[]);
void XuatDiemLTC(LTC *ltc, DSSV dssv, PTRMH root);
void HuyLopTinChi(DSLOPTC &ds, PTRMH root);
void XuatDS_HuyLTC(DSLOPTC &ds, char NK[], int HocKy, PTRMH root);
void HuyLopTinChi1(DSLOPTC &ds);
void NhapDiem(LTC *ltc, DSSV dssv, PTRMH root);

//============================================================================

//==============================NGUYEN MAU HAM================================
void GiaiPhongMangTamLTC(DSLOPTC &ds){
	for (int i=0; i< ds.soluong_ltc; i++) delete ds.LOPTC[i];
}

int DemSV_DKLTC(PTRDKLOPTC ds){
	PTRDKLOPTC p;
	int dem = 0;
	if (ds == NULL) return 0;
	for(p = ds; p != NULL; p = p->next) 
		if (p->dkltc.TRANGTHAI == 1)
			dem++;
	return dem;
}

int DemAllSV_DKLTC(PTRDKLOPTC ds){
	PTRDKLOPTC p;
	int dem = 0;
	if (ds == NULL) return 0;
	for(p = ds; p != NULL; p = p->next) dem++;
	return dem;
}

void MangTam_LTC_NK_HK(DSLOPTC dsltc, DSLOPTC &LopTC, char NK[], int HK){
	if (dsltc.soluong_ltc == 0) return;
	for (int i=0; i<dsltc.soluong_ltc; i++)
	{
		if(strcmp(dsltc.LOPTC[i]->NIENKHOA, NK) == 0 && dsltc.LOPTC[i]->HOCKY == HK && dsltc.LOPTC[i]->TRANGTHAI == 1)
		{
			LopTC.LOPTC[LopTC.soluong_ltc] = new LTC;
			LopTC.LOPTC[LopTC.soluong_ltc++] = dsltc.LOPTC[i];
		}
	}
}

void MangTamHuyLTC_NK_HK(DSLOPTC dsltc, DSLOPTC &ds, char NK[], int HK){
	if (dsltc.soluong_ltc == 0) return;
	for (int i=0; i<dsltc.soluong_ltc; i++)
	{
		int sv_dkltc = 0;
		sv_dkltc = DemSV_DKLTC(dsltc.LOPTC[i]->DSDK);
		if(strcmp(dsltc.LOPTC[i]->NIENKHOA, NK) == 0 && dsltc.LOPTC[i]->HOCKY == HK && dsltc.LOPTC[i]->TRANGTHAI == 1 && sv_dkltc < dsltc.LOPTC[i]->SOSVMIN)
		{
			ds.LOPTC[ds.soluong_ltc] = new LTC;
			ds.LOPTC[ds.soluong_ltc++] = dsltc.LOPTC[i];
		}
	}
}

PTRDKLOPTC FindSV_DKLTC(PTRDKLOPTC &ds, char MaSV[]){
	for (PTRDKLOPTC p = ds; p != NULL; p = p -> next){
		if(strcmp(MaSV,p->dkltc.MASV) == 0) return p;
	}
	return NULL;
}

LTC *Find_LTC(DSLOPTC &ds, int MaLTC){
	if (ds.soluong_ltc == 0) return NULL;
	int k, left = 0, right = ds.soluong_ltc - 1;
	do
	{
		k = (left + right)/2;
		if (MaLTC < ds.LOPTC[k]->MALOPTC) right = k - 1;
			else left = k + 1;
	}while ((MaLTC != ds.LOPTC[k]->MALOPTC) && (left <= right));
	if (MaLTC == ds.LOPTC[k]->MALOPTC) return ds.LOPTC[k];
		else return NULL;
}

void Insert_LastDKLTC(PTRDKLOPTC &ds,  DKLOPTC dk){
	PTRDKLOPTC p,r;
	p = new nodedkloptc;
	p->dkltc = dk;
	p->next = NULL;
	if (ds==NULL) ds=p;
	else{
		r = ds;
		while (r->next != NULL) r = r->next;
		r->next = p;
	}
}

void Insert_OrderDKLTC(PTRDKLOPTC &ds, DKLOPTC dk){
	PTRDKLOPTC p, t, s;  // t la nut truoc, s la nut sau
   	p = new nodedkloptc;
   	p->dkltc = dk;
   	for(s = ds; s != NULL && strcmp(s->dkltc.MASV, dk.MASV) < 0 ; t = s, s = s->next); //Tim vi tri t va s
	if(s == ds)  // them nut vao dau danh sach lien ket
   	{
      p->next = ds;
      ds = p;
   	}
   	else           // them nut p vao truoc nut s
   	{
      p->next= s;
      t->next= p;
   	}

}

int check_MaLTC(DSLOPTC ds, int MaLTC){
	int k, left = 0, right = ds.soluong_ltc - 1;
	do
	{
		k = (left + right)/2;
		if (MaLTC < ds.LOPTC[k]->MALOPTC) right = k - 1;
			else left = k + 1;
	}while ((MaLTC != ds.LOPTC[k]->MALOPTC) && (left <= right));
	if (MaLTC == ds.LOPTC[k]->MALOPTC) return 1;
		else return 0;
}

void AddSV_DKLTC(LTC *&ds, char MaSV[]){
	DKLOPTC p;
	strcpy(p.MASV,MaSV); 
	p.DIEM = 0; p.TRANGTHAI = 1;
	Insert_OrderDKLTC(ds->DSDK,p);
	return;
}

int check_SVDKLTC(PTRDKLOPTC ds, char MaSV[]){
	//0: HUY DANG KÝ;	1: DA DANG KY;		-1: CHUA DANG KY
	if(ds == NULL) return -1;
	PTRDKLOPTC p;
	for (p = ds; p != NULL; p = p->next)
	{
		if (strcmp(MaSV,p->dkltc.MASV) == 0) {
			if(p->dkltc.TRANGTHAI == 0) return 0; 
				else return 1;
		}
	}
	return -1;
}

void DocFileLopTC(DSLOPTC &ds)
{
	fstream f;
	int nDSLTC=0, nDKLTC=0;
	f.open("DSLOPTC1.txt", ios::in);
	if(f.fail())	{return;} //Khong tim thay file
	if(f.is_open())
	{
		f >> nDSLTC;	
		for(int i = 0; i < nDSLTC; i++)
		{	
			char data1[6], data2[11], data3[10], data4[5], data5[5], data6[4], data7[4], data8[2], data9[4];
			ds.LOPTC[i] = new LTC; // load thong tin vao LTC
            f.getline(data1,6,'|'); ds.LOPTC[i]->MALOPTC = atoi(data1); 
			f.getline(data2,11,'|'); strcpy(ds.LOPTC[i]->MAMH,data2); 
			f.getline(data3,10,'|'); strcpy(ds.LOPTC[i]->NIENKHOA,data3); 
			f.getline(data4,5,'|'); ds.LOPTC[i]->HOCKY = atoi(data4); 
			f.getline(data5,5,'|'); ds.LOPTC[i]->NHOM = atoi(data5); 
			f.getline(data6,4,'|'); ds.LOPTC[i]->SOSVMIN = atoi(data6); 
			f.getline(data7,4,'|'); ds.LOPTC[i]->SOSVMAX = atoi(data7); 
			f.getline(data8,2,'|'); ds.LOPTC[i]->TRANGTHAI = atoi(data8); 
			//load danh sach sinh vien LTC
			f.getline(data9,4,'|'); nDKLTC = atoi(data9);
			ds.LOPTC[i]->DSDK = NULL;
			if (nDKLTC > 0){
				for(int j = 0; j < nDKLTC; j++)
				{	
					DKLOPTC dk;
					char data10[16], data11[2], data12[5];
					f.getline(data10,16,'|'); strcpy(dk.MASV,data10); 
					f.getline(data11,2,'|'); dk.TRANGTHAI = atoi(data11); 
					f.getline(data12,5,'|'); dk.DIEM = float(atof(data12)); 
					Insert_LastDKLTC(ds.LOPTC[i]->DSDK,dk);
				}	
			}		
			++ds.soluong_ltc;
		}
	}
	f.close();
}

void LuuFileLopTC(DSLOPTC ds){
	fstream f;
	f.open("DSLOPTC1.txt", ios::out);
	f <<ds.soluong_ltc <<endl;
	for (int i=0; i<ds.soluong_ltc; i++){
		int temp = 0;
		temp = DemAllSV_DKLTC(ds.LOPTC[i]->DSDK);
		f <<ds.LOPTC[i]->MALOPTC <<'|' <<ds.LOPTC[i]->MAMH <<'|' <<ds.LOPTC[i]->NIENKHOA <<"|" <<ds.LOPTC[i]->HOCKY <<'|' <<ds.LOPTC[i]->NHOM <<'|' <<ds.LOPTC[i]->SOSVMIN <<'|' <<ds.LOPTC[i]->SOSVMAX <<'|' <<ds.LOPTC[i]->TRANGTHAI <<'|';
		f <<temp <<'|';
		for (PTRDKLOPTC p = ds.LOPTC[i]->DSDK; p!=NULL; p = p ->next){
			f << p->dkltc.MASV <<'|' << p->dkltc.TRANGTHAI <<'|' << p->dkltc.DIEM <<'|';
		}
		f <<endl;	
	}
	f.close();
}

void DKLTC(DSLOPTC &ds, SINHVIEN sv){
	int key, vitri = 0, x= 111, y=3;
	char data[5]; data[0]='\0';
	Khung_DKLTC();
DK_LTC:
	while(1){
		TextColor(244); 
		gotoXY(97,4); printf("     Ki tu: (A-Z). Toi da: 4");
		TextColor(3); gotoXY(111+vitri,y); 
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 4))
			{
				data[vitri] = char(key);
				cout<<data[vitri];
				vitri++;
			}
		if( key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(111+vitri, y);
				cout<<" ";
				gotoXY(111+vitri, y);
			}
		if(key == ENTER && vitri != 0)
			{
				data[vitri] = '\0';
				LTC *ltc = Find_LTC(ds,atoi(data));
				if(ltc == NULL) {
					char c[45]= "Khong ton tai LOP TIN CHI nay trong dot nay!";
					GhiChu(c,97,6,78,600);
					goto DK_LTC;
				}
				if(check_SVDKLTC(ltc->DSDK, sv.MASV) == 1) {
					char c[33]= "Sinh vien da dang ky LTC nay! ";
					GhiChu(c,97,6,78,600);
					goto DK_LTC;
				}
				int soluongSV_DKLTC;
				soluongSV_DKLTC = DemSV_DKLTC(ltc->DSDK);
				if (soluongSV_DKLTC == ltc->SOSVMAX){
					char c[37]= "Lop Tin Chi nay da het slot dang ky!";
					GhiChu(c,97,6,78,600);
					goto DK_LTC;
				}
				if(check_SVDKLTC(ltc->DSDK, sv.MASV) == 0){
					PTRDKLOPTC temp;
					temp = FindSV_DKLTC(ltc->DSDK,sv.MASV);
					temp->dkltc.DIEM = 0; temp->dkltc.TRANGTHAI = 1;
				} else{
					AddSV_DKLTC(ltc,sv.MASV);
				} 
				return;

			}
		if(key == ESC){return;}
	}	
}

void Huy_DKLTC(DSLOPTC &ds, SINHVIEN sv){
	int key, vitri = 0, x= 111, y=3;
	char data[5]; data[0]='\0';
	Khung_Xoa_DKLTC();
HUYDK_LTC:
	while(1)
	{
		TextColor(244); 
		gotoXY(97,4); printf("     Ki tu: (A-Z). Toi da: 4");
		TextColor(3); gotoXY(111+vitri,y); 
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 4))
			{
				data[vitri] = char(key);
				cout<<data[vitri];
				vitri++;
			}
		if( key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(111+vitri, y);
				cout<<" ";
				gotoXY(111+vitri, y);
			}
		if(key == ENTER && vitri != 0)
			{
				
				data[vitri] = '\0';
				LTC *ltc = Find_LTC(ds,atoi(data));
				if(ltc == NULL) {
					char c[45]= "Khong ton tai LOP TIN CHI nay trong dot nay!";
					GhiChu(c,97,6,78,600);
					goto HUYDK_LTC;
				}						
				if(check_SVDKLTC(ltc->DSDK, sv.MASV) == -1 || check_SVDKLTC(ltc->DSDK, sv.MASV) == 0) {
					char c[33]= "Sinh vien chua dang ky LTC nay! ";
					GhiChu(c,97,6,78,600);
					goto HUYDK_LTC;
				}
				if(check_SVDKLTC(ltc->DSDK,sv.MASV) == 1){
					int check = ThongBao_Xoa();
					if (check ==1 ){
						PTRDKLOPTC temp;
						temp = FindSV_DKLTC(ltc->DSDK,sv.MASV);
						temp->dkltc.DIEM = 0; temp->dkltc.TRANGTHAI = 0;
					}
					TextColor(3);
				}
				return;
			}
		if(key == ESC){return;}
	}
}	

void XuatDS_DangKyLTC(DSLOPTC &dsltc, SINHVIEN sv, char NK[], int HK, PTRMH root){
	int key, demdong = 0, STT = 1, demdongdk = 0, soluongltc, trang=0, tongtrang = 0;
	while (1)
	{
		DSLOPTC temp_ltc; temp_ltc.soluong_ltc = 0;
		MangTam_LTC_NK_HK(dsltc, temp_ltc, NK, HK);
		if(temp_ltc.soluong_ltc == 0)
 		{
 			char c[30]="Chua co du lieu Lop Tin Chi!";
 			GhiChu(c,50,20,78,1500);
			return;
		}else{
			if(temp_ltc.soluong_ltc < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((temp_ltc.soluong_ltc-1)/15+1);
			}
		}	
		system("cls"); Khung_DSDKLTC(); ThongTinSV(sv);
		TextColor(236);
		gotoXY(50,5); cout <<"        NIEN KHOA:                  ";
		gotoXY(50,6); cout <<"        HOC KY   :                  " ;
		gotoXY(69,5); cout <<NK; gotoXY(69,6); cout <<HK;
		for (int i = trang*15 ; i < 15 + trang*15 && i < temp_ltc.soluong_ltc ; i++)
		{			
			int soluong_dkltc;
			soluong_dkltc = DemSV_DKLTC(temp_ltc.LOPTC[i]->DSDK);
			if(check_SVDKLTC(temp_ltc.LOPTC[i]->DSDK,sv.MASV) == 1)
			{
				TextColor(7);
				gotoXY(116,13+demdongdk); cout<< STT;
				gotoXY(127,13+demdongdk); cout <<temp_ltc.LOPTC[i]->MALOPTC;
				TextColor(225);
				gotoXY(3,11+demdong);
				cout <<"|     |        |            |                                                    |      |         |          |";
				STT++; demdongdk++;
			}
			else TextColor(7);
			PTRMH temp = FindMaMH(root, temp_ltc.LOPTC[i]->MAMH);
			gotoXY(6,11+demdong); cout <<(i+1);
			gotoXY(13,11+demdong); cout << temp_ltc.LOPTC[i]->MALOPTC;
			gotoXY(20,11+demdong); cout << temp_ltc.LOPTC[i]->MAMH;
			gotoXY(32,11+demdong); cout <<temp->mh.TENMH;
			gotoXY(87,11+demdong); cout << temp_ltc.LOPTC[i]->NHOM;
			gotoXY(96,11+demdong); cout <<soluong_dkltc;
			gotoXY(106,11+demdong); cout << temp_ltc.LOPTC[i]->SOSVMAX - soluong_dkltc;
			demdong++;		
		}
		demdong = 0; demdongdk = 0; STT = 1;
		HienThiTrang(trang+1,tongtrang,60,29);
		key = GetKey();
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)		{trang++;}
		if((key == LEFT || key == UP) && trang > 0)						{trang--;}
		if(key == INSERT)
		{
			gotoXY(66,27);  TextColor(251);	printf("Insert");
			DKLTC(temp_ltc, sv);	
		}
		if (key == DELETE)
		{
			gotoXY(115,27);  TextColor(251);	printf("Delete");
			Huy_DKLTC(temp_ltc,sv);		
		}
		if (key == ESC) {
			putchar(7);	gotoXY(4,27);  TextColor(251);	printf(" ESC"); //T� m�u ESC
			int temp = ThongBao_ESC();
			if(temp == -1)	{continue;}
			if(temp == 1)	{char c[50]= "Luu Vao File Thanh Cong!" ;GhiChu(c,35,27,74,2000);LuuFileLopTC(dsltc);}
			if(temp == 0)	{char c[50]= "Luu Vao File Khong Thanh Cong!";GhiChu(c,35,27,74,2000);}								
			system("cls"); return;
		}
	}	
}

void SV_DangKyLTC(DSSV dsSV, DSLOPTC &dsltc, PTRMH root){
	int key, HocKy, vitri = 0, x = 46, y = 3;
	char HK[2], NK[10]; HK[0]='\0'; NK[0]='\0';
	SINHVIEN sv; sv.MASV[0]='\0';
	system("cls"); Khung_NhapSVDK(); gotoXY(x,y);
MASV: 
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: (A-Z) & (0-9). Toi da: 15");
		TextColor(3); gotoXY(46+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			sv.MASV[vitri] = char(key);
			sv.MASV[vitri] = toupper(sv.MASV[vitri]);
			cout<<sv.MASV[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(46+vitri, y);
			cout<<" ";
			gotoXY(46+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			sv.MASV[vitri] = '\0';
			if(check_SV(dsSV,sv.MASV) == 0) {TextColor(78);	gotoXY(40,4); printf("Khong ton tai SINH VIEN nay!    ");			Sleep(600); goto MASV;}
			vitri = 0;
			gotoXY(67+vitri, y);
			goto NIENKHOA;
		}
		if(key == ESC){return;}
	}
NIENKHOA:
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: (0-9) & \"-\". Toi da: 9   ");
		TextColor(3); gotoXY(67+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && vitri < 9 && vitri != 4)
		{
			NK[vitri] = char(key);
			cout<<NK[vitri];
			vitri++;
		}
		if((key == '-') && vitri == 4)
		{
			NK[vitri] = char(key);
			cout<<NK[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(67+vitri, y);
			cout<<" ";
			gotoXY(67+vitri, y);
		}
		if(key == ENTER && vitri != 0 && vitri ==9)
		{
			NK[vitri] = '\0';
			vitri = 0;
			gotoXY(85+vitri, y);
			goto HOCKY;
		}
		if(key == ESC){return;}
	}
HOCKY:
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: 1 -> 3. Toi da: 1        ");
		TextColor(3); gotoXY(85+vitri,y);
		key = GetKey();
		if(( key <= '3' && key >= '1') && (vitri < 1))
		{
			HK[vitri] = char(key);
			cout<<HK[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(85+vitri, y);
			cout<<" ";
			gotoXY(85+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			HK[vitri] = '\0';
			HocKy = atoi(HK);
			sv = FindSV_MSSV(dsSV,sv.MASV);
			XuatDS_DangKyLTC(dsltc,sv,NK,HocKy, root);
			return;
		}
		if(key == ESC){return;}
	}
}

void Nhap_NK_HK_Nhom_MH(DSLOPTC &dsltc, DSSV dssv, PTRMH root, int chedo){
	int key, trang = 0, tongtrang = 0, demdong = 0, HK, Nhom, x = 46, y = 3 , vitri = 0;
	char NK[10], MaMH[11], data[2]; LTC *temp;
	NK[0] = '\0', MaMH[0] = '\0' , data[0] = '\0';
	system("cls"); KhungNhap_NK_HK_N_MH();
NIENKHOA:
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: (0-9) & \"-\". Toi da: 9   ");
		TextColor(3); gotoXY(46+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && vitri < 9 && vitri != 4)
		{
			NK[vitri] = char(key);
			cout<<NK[vitri];
			vitri++;
		}
		if((key == '-') && vitri == 4)
		{
			NK[vitri] = char(key);
			cout<<NK[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(46+vitri, y);
			cout<<" ";
			gotoXY(46+vitri, y);
		}
		if(key == ENTER && vitri != 0 && vitri ==9)
		{
			NK[vitri] = '\0';
			vitri = 0;
			goto HOCKY;
		}
		if(key == ESC){return;}
	}
HOCKY:
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: 1 -> 3. Toi da: 1        ");
		TextColor(3); gotoXY(64+vitri,y);
		key = GetKey();
		if(( key <= '3' && key >= '1') && (vitri < 1))
		{
			data[vitri] = char(key);
			cout<<data[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(64+vitri, y);
			cout<<" ";
			gotoXY(64+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			data[vitri] = '\0';
			HK = atoi(data);
			vitri = 0;
			goto NHOM;
		}
		if(key == ESC){return;}
	}
NHOM:
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: (0 - 9). Toi da: 3        ");
		TextColor(3); gotoXY(77+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			data[vitri] = char(key);
			cout<<data[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(77+vitri, y);
			cout<<" ";
			gotoXY(77+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			data[vitri] = '\0';
			Nhom = atoi(data);
			vitri = 0;
			goto MAMONHOC;
		}
		if(key == ESC){return;}
	}
MAMONHOC: 
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: (A-Z) & (0-9). Toi da: 10");
		TextColor(3); gotoXY(84+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 10))
		{
			MaMH[vitri] = char(key);
			MaMH[vitri] = toupper(MaMH[vitri]);
			cout<<MaMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(84+vitri, y);
			cout<<" ";
			gotoXY(84+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			MaMH[vitri] = '\0';
			temp = Find_LTC(dsltc,NK,HK,Nhom,MaMH);
			if (temp == NULL)  {
				TextColor(78);	
				gotoXY(40,4); printf("Khong ton tai LOP TIN CHI nay!");			
				Sleep(600); vitri = 0; KhungNhap_NK_HK_N_MH(); goto NIENKHOA;
			}
			if (chedo ==1) NhapDiem(temp,dssv,root);
			if (chedo ==2) XuatDiemLTC(temp,dssv,root);
			return;
		}
		if (key == ESC){return;}
	}
}

void XuatDiemLTC(LTC *ltc, DSSV dssv, PTRMH root){
	int key, trang = 0, tongtrang = 0, soluongSV=0, demdong = 0;
	while(1){
		soluongSV = DemSV_DKLTC(ltc->DSDK);
		if(soluongSV == 0)
 		{
 			char c[50]="Chua co du lieu Mon Hoc";
 			GhiChu(c,35,27,74,500);
		}else{
			if(soluongSV < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((soluongSV-1)/15+1);
			}
		}
		DKLOPTC p[soluongSV+1];
		MangTam_SVDKLTC(ltc->DSDK, p);
		PTRMH mh; mh = FindMaMH(root,ltc->MAMH);
		system("cls");	Khung_Xuat_Diem(); 
		TextColor(241);	
		gotoXY(36,2); cout <<mh->mh.TENMH;
		gotoXY(41,3); cout <<ltc->NIENKHOA;
		gotoXY(61,3); cout <<ltc->HOCKY;
		gotoXY(72,3); cout <<ltc->NHOM;
		for( int i = trang*15 ; i < 15 + trang*15 && i < soluongSV ; i++)
		{
			SINHVIEN sv; sv = FindSV_MSSV(dssv,p[i].MASV);
			TextColor(7);
			gotoXY(6, 9+demdong); cout<< ( i+1 );
			gotoXY(11,9+demdong); cout<< p[i].MASV;
			gotoXY(27,9+demdong); cout<< sv.HO;
			gotoXY(77,9+demdong); cout<< sv.TEN;
			gotoXY(90,9+demdong); cout<< p[i].DIEM;
			demdong++;
		}
		demdong = 0;
		HienThiTrang(trang+1, tongtrang, 50, 27);
		key = GetKey();
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)		{trang++;}
		if((key == LEFT || key == UP) && trang > 0)						{trang--;}
		if(key == ESC) return;
	}
}

LTC *Find_LTC (DSLOPTC &ds, char NK[], int HK, int Nhom, char MaMH[]){
	if (ds.soluong_ltc == 0) return NULL;
	for (int i=0; i<ds.soluong_ltc; i++){
		if (strcmp(ds.LOPTC[i]->NIENKHOA,NK) == 0 && ds.LOPTC[i]->HOCKY == HK && ds.LOPTC[i]->NHOM == Nhom && ds.LOPTC[i]->TRANGTHAI == 1 && strcmp(ds.LOPTC[i]->MAMH,MaMH) == 0)
			return ds.LOPTC[i];
	}
	return NULL;
}

void MangTam_SVDKLTC(PTRDKLOPTC ds, DKLOPTC p[]){
	int dem=0; PTRDKLOPTC r;
	for (r = ds; r!= NULL; r = r->next){
		if(r->dkltc.TRANGTHAI == 1)
			p[dem++] = r->dkltc;
	}
}

void HuyLopTinChi(DSLOPTC &ds, PTRMH root){
	int key, HocKy, vitri = 0, x = 46, y = 3;
	char HK[2], NK[10]; HK[0]='\0'; NK[0]='\0';
	system("cls"); Khung_Nhap_NK_HK();
NIENKHOA:
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: (0-9) & \"-\". Toi da: 9   ");
		TextColor(3); gotoXY(51+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && vitri < 9 && vitri != 4)
		{
			NK[vitri] = char(key);
			cout<<NK[vitri];
			vitri++;
		}
		if((key == '-') && vitri == 4)
		{
			NK[vitri] = char(key);
			cout<<NK[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(51+vitri, y);
			cout<<" ";
			gotoXY(51+vitri, y);
		}
		if(key == ENTER && vitri != 0 && vitri ==9)
		{
			NK[vitri] = '\0';
			vitri = strlen(HK);
			gotoXY(77+vitri, y);
			goto HOCKY;
		}
		if(key == ESC){return;}
	}
HOCKY:
	while(1){
		TextColor(244);
		gotoXY(40,4); printf("Ki tu: 1 -> 3. Toi da: 1        ");
		TextColor(3); gotoXY(77+vitri,y);
		key = GetKey();
		if(( key <= '3' && key >= '1') && (vitri < 1))
		{
			HK[vitri] = char(key);
			cout<<HK[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(77+vitri, y);
			cout<<" ";
			gotoXY(77+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			HK[vitri] = '\0';
			HocKy = atoi(HK);
			XuatDS_HuyLTC(ds, NK, HocKy, root);
			return;
		}
		if(key == ESC){return;}
	}
}

void XuatDS_HuyLTC(DSLOPTC &ds, char NK[], int HocKy, PTRMH root){
	int key, demdong = 0, soluongltc, trang=0, tongtrang = 0;
	bool check_change = false;
	while (1)
	{
		DSLOPTC temp_ltc; temp_ltc.soluong_ltc = 0;
		MangTamHuyLTC_NK_HK(ds, temp_ltc, NK, HocKy);
		if(temp_ltc.soluong_ltc == 0)
 		{
 			char c[30]="Chua co du lieu Lop Tin Chi!";
 			GhiChu(c,50,20,78,1500);
			return;
		}else{
			if(temp_ltc.soluong_ltc < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((temp_ltc.soluong_ltc-1)/15+1);
			}
		}	
		system("cls"); Khung_HuyLTC();
		TextColor(236);
		gotoXY(43,3); cout <<NK; gotoXY(63,3); cout <<HocKy;
		for (int i = trang*15 ; i < 15 + trang*15 && i < temp_ltc.soluong_ltc ; i++)
		{			
			TextColor(7);
			int soluong_dkltc;
			soluong_dkltc = DemSV_DKLTC(temp_ltc.LOPTC[i]->DSDK);
			PTRMH temp = FindMaMH(root, temp_ltc.LOPTC[i]->MAMH);
			gotoXY(6,8+demdong); cout <<(i+1);
			gotoXY(13,8+demdong); cout << temp_ltc.LOPTC[i]->MALOPTC;
			gotoXY(20,8+demdong); cout << temp_ltc.LOPTC[i]->MAMH;
			gotoXY(32,8+demdong); cout <<temp->mh.TENMH;
			gotoXY(87,8+demdong); cout << temp_ltc.LOPTC[i]->NHOM;
			gotoXY(96,8+demdong); cout <<soluong_dkltc;
			gotoXY(105,8+demdong); cout << temp_ltc.LOPTC[i]->SOSVMIN;
			demdong++;		
		}
		demdong = 0;
		HienThiTrang(trang+1,tongtrang,60,29);
		key = GetKey();
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)		{trang++;}
		if((key == LEFT || key == UP) && trang > 0)						{trang--;}
		if (key == DELETE)
		{
			gotoXY(50,24);  TextColor(251);	printf("Delete");
			HuyLopTinChi1(temp_ltc);		
		}
		if (key == ESC) 
		{	
			putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //T� m�u ESC
			int temp = ThongBao_ESC();
			if(temp == -1)	{continue;}
			if(temp == 1)	{char c[50]= "Luu Vao File Thanh Cong!" ;GhiChu(c,35,27,74,2000);LuuFileLopTC(ds);}
			if(temp == 0)	{char c[50]= "Luu Vao File Khong Thanh Cong!";GhiChu(c,35,27,74,2000);}						
			system("cls");	return;
		}
	}
}	

void HuyLopTinChi1(DSLOPTC &ds){
	int key, vitri = 0, x= 111, y=3;
	char data[5]; data[0]='\0';
	Khung_HuyLTC1();
HUY_LTC:
	while(1)
	{
		TextColor(244); 
		gotoXY(97,4); printf("     Ki tu: (A-Z). Toi da: 4");
		TextColor(3); gotoXY(111+vitri,y); 
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 4))
			{
				data[vitri] = char(key);
				cout<<data[vitri];
				vitri++;
			}
		if( key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(111+vitri, y);
				cout<<" ";
				gotoXY(111+vitri, y);
			}
		if(key == ENTER && vitri != 0)
			{
				
				data[vitri] = '\0';
				LTC *ltc = Find_LTC(ds,atoi(data));
				if(ltc == NULL) {
					char c[32]= "Khong ton tai LOP TIN CHI nay!";
					GhiChu(c,97,6,78,600);
					goto HUY_LTC;
				}						
				int temp = ThongBao_Xoa();
				if (temp == 1) {
					ltc->TRANGTHAI = 0;
					char c[30] = "Huy Lop Tin Chi Thanh Cong!"; GhiChu(c,35,27,74,2000);					
				}
				TextColor(3);
				return;
			}
		if(key == ESC){return;}
	}
}

//-----------------LE MANH CUONG - N18DCAT009----------------------------
int Full_Lop(DSLOPTC &dsltc)	//tra ve 1: tran bo nho da cap phat
{
		if(dsltc.soluong_ltc == MAXLOPTC-1) {GhiChu("Danh sach Lop TC Full. Khong the them!",35,27,74,700); return 1;} return 0;
}

int checkLTC_MH_NK_HK_Nhom (DSLOPTC ds, LTC *temp){
	if (ds.soluong_ltc == 0) return 0;
	for (int i=0; i<ds.soluong_ltc ; i++){
		if (strcmp(ds.LOPTC[i]->MAMH,temp->MAMH) == 0 && strcmp(ds.LOPTC[i]->NIENKHOA,temp->NIENKHOA) == 0 && ds.LOPTC[i]->HOCKY == temp->HOCKY && ds.LOPTC[i]->NHOM == temp->NHOM)
			return 1;
	}
	return 0;
}

int KTMaLop(DSLOPTC dsltc, char c[], int demkhongdoi)
{
	int check = atoi(c);
	for(int i = 0; i <= demkhongdoi; i++)
	{
		if(dsltc.soluong_ltc == i){continue;}
		if(dsltc.LOPTC[i]->MALOPTC == check && i == 0)
		{
			return -1;	// neu kiem tra ptu dau tien trung thi tra ve -1
		}
		if(dsltc.LOPTC[i]->MALOPTC == check)
		{
			return i;	// neu khong phai ptu dau tien trung thi tra ve 1 s�' > 0
		}
	}
	return 0;			// khong tim thay ptu tra 0
}

void ThemLopTC(DSLOPTC &dsltc, PTRMH &root)
{	
	//Khoi tao rong~
	//dsltc.soluong_ltc++;
	dsltc.LOPTC[dsltc.soluong_ltc] = new LTC;
	dsltc.LOPTC[dsltc.soluong_ltc]->MALOPTC = dsltc.soluong_ltc + 1;
	dsltc.LOPTC[dsltc.soluong_ltc]->MAMH[0] = '\0';
	dsltc.LOPTC[dsltc.soluong_ltc]->NIENKHOA[0] = '\0';
	dsltc.LOPTC[dsltc.soluong_ltc]->TRANGTHAI = 1;
	dsltc.LOPTC[dsltc.soluong_ltc]->DSDK = NULL;
	int key, vitri = 0, x = 12, y = 14;
	char Hocky[2], Nhom[3], svmin[4], svmax[4];
	Hocky[0] = '\0'; Nhom[0]='\0'; svmax[0]='\0'; svmin[0]='\0';
	Khung_Them_Lop();	
	TextColor(3); gotoXY(14,y); cout <<dsltc.LOPTC[dsltc.soluong_ltc]->MALOPTC;
MAMH:
	while(1)
	{
		TextColor(244);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 10      "); TextColor(3); gotoXY(24+vitri,y);
		key = GetKey(); //Bat phim
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			dsltc.LOPTC[dsltc.soluong_ltc]->MAMH[vitri] = char(key);
			dsltc.LOPTC[dsltc.soluong_ltc]->MAMH[vitri] = toupper( dsltc.LOPTC[dsltc.soluong_ltc]->MAMH[vitri]);
			cout<<dsltc.LOPTC[dsltc.soluong_ltc]->MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(24+vitri, y);
			cout<<" ";
			gotoXY(24+vitri, y);
		}	
		if(key == ENTER && vitri != 0)
		{
			dsltc.LOPTC[dsltc.soluong_ltc]->MAMH[vitri] = '\0';
			if (check_MH(root,dsltc.LOPTC[dsltc.soluong_ltc]->MAMH) == 0){TextColor(78);	gotoXY(10,15); printf("KHONG TON TAI MAMH nay. Nhap Lai!");			Sleep(600); goto MAMH;}
			vitri = 0;
			gotoXY(39+vitri,y);
			goto NIENKHOA;
		}
		if(key == ESC)	{ delete dsltc.LOPTC[dsltc.soluong_ltc];  return;}
	}
NIENKHOA:
	while(1){
		TextColor(244); gotoXY(10,15); printf("Ki tu: (0-9) & \"-\". Toi da: 9   ");
		TextColor(3); gotoXY(39+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && vitri < 9 && vitri != 4)
		{
			dsltc.LOPTC[dsltc.soluong_ltc]->NIENKHOA[vitri] = char(key);
			cout<<dsltc.LOPTC[dsltc.soluong_ltc]->NIENKHOA[vitri];
			vitri++;
		}
		if((key == '-') && vitri == 4)
		{
			dsltc.LOPTC[dsltc.soluong_ltc]->NIENKHOA[vitri] = char(key);
			cout<<dsltc.LOPTC[dsltc.soluong_ltc]->NIENKHOA[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(39+vitri, y);
			cout<<" ";
			gotoXY(39+vitri, y);
		}
		if(key == ENTER && vitri != 0 && vitri ==9)
		{
			dsltc.LOPTC[dsltc.soluong_ltc]->NIENKHOA[vitri] = '\0';
			vitri = 0;
			gotoXY(56+vitri, y);
			goto HOCKY;
		}
		if(key == ESC){delete dsltc.LOPTC[dsltc.soluong_ltc]; return;}
	}
HOCKY:
	while(1){
		TextColor(244); gotoXY(10,15); printf("Ki tu: 1 -> 3. Toi da: 1        ");
		TextColor(3); gotoXY(56+vitri,y);
		key = GetKey();
		if(( key <= '3' && key >= '1') && (vitri < 1))
		{
			Hocky[vitri] = char(key);
			cout<<Hocky[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(56+vitri, y);
			cout<<" ";
			gotoXY(56+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			Hocky[vitri] = '\0';
			dsltc.LOPTC[dsltc.soluong_ltc]->HOCKY = atoi(Hocky);
			vitri = 0;
			gotoXY(67+vitri,y);
			goto NHOM;
		}
		if(key == ESC){delete dsltc.LOPTC[dsltc.soluong_ltc]; return;}
	}
NHOM:
	while(1)
	{
		TextColor(244); gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 3         ");
		TextColor(3); gotoXY(67+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			Nhom[vitri] = char(key);
			cout<<Nhom[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(67+vitri, y);
			cout<<" ";
			gotoXY(67+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			Nhom[vitri] = '\0';
			dsltc.LOPTC[dsltc.soluong_ltc]->NHOM = atoi(Nhom);
			vitri = 0;
			gotoXY(79+vitri,y);
			goto SOSVMIN;
		}
		if(key == ESC){delete dsltc.LOPTC[dsltc.soluong_ltc]; return;}
	}	
SOSVMIN:
	while(1)
	{
		TextColor(244); gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 4                    ");
		TextColor(3); gotoXY(79+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 4))
		{
			svmin[vitri] = char(key);
			cout<<svmin[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(79+vitri, y);
			cout<<" ";
			gotoXY(79+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			svmin[vitri] = '\0';
			dsltc.LOPTC[dsltc.soluong_ltc]->SOSVMIN = atoi(svmin);
			vitri = 0;
			gotoXY(94+vitri,y);
			goto SOSVMAX;
		}
		if(key == ESC){delete dsltc.LOPTC[dsltc.soluong_ltc]; return;}
	}	
SOSVMAX:
	while(1)
	{
		TextColor(244); gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 4                              ");
		TextColor(3); gotoXY(94+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 4))
		{
			svmax[vitri] = char(key);
			cout<<svmax[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(94+vitri, y);
			cout<<" ";
			gotoXY(94+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			svmax[vitri] = '\0';
			dsltc.LOPTC[dsltc.soluong_ltc]->SOSVMAX = atoi(svmax);
			if(dsltc.LOPTC[dsltc.soluong_ltc]->SOSVMIN > dsltc.LOPTC[dsltc.soluong_ltc]->SOSVMAX){
				TextColor(78);	
				gotoXY(10,15); printf("SOSVMIN khong duoc lon hon SOSVMAX!");			
				Sleep(600); goto SOSVMAX;
			}
			int temp = checkLTC_MH_NK_HK_Nhom(dsltc,dsltc.LOPTC[dsltc.soluong_ltc]);
			if (temp == 1) { 
				TextColor(78);	
				gotoXY(10,15); printf("Trung LOP TIN CHI!");			
				Sleep(600); delete dsltc.LOPTC[dsltc.soluong_ltc]; TextColor(3);
				return;
			}
			dsltc.soluong_ltc++;
			return;
		}
		if(key == ESC){delete dsltc.LOPTC[dsltc.soluong_ltc]; return;}
	}	
}

void SuaLopTC(DSLOPTC &dsltc, PTRMH root, LTC *&temp){
	int key, vitri = 0, x = 12, y = 16;
	char Hocky[2], Nhom[3], svmin[4], svmax[4];
	Hocky[0] = '\0'; Nhom[0]='\0'; svmax[0]='\0'; svmin[0]='\0';
	LTC *check = new LTC;
	//check->MAMH[0]= '\0'; check->NIENKHOA[0]='\0';
	Khung_Sua_Lop();
	TextColor(3);
	gotoXY(12,14); cout <<temp->MALOPTC;
	gotoXY(24,14); cout <<temp->MAMH;
	gotoXY(39,14); cout <<temp->NIENKHOA;
	gotoXY(54,14); cout <<temp->HOCKY;
	gotoXY(66,14); cout <<temp->NHOM;
	gotoXY(75,14); cout <<temp->SOSVMIN;
	gotoXY(89,14); cout <<temp->SOSVMAX;
	gotoXY(12,16); cout <<temp->MALOPTC;
MAMH:
	while(1)
	{
		TextColor(244);	gotoXY(10,17); printf("Ki tu: (A-Z) & (0-9). Toi da: 10      "); TextColor(3); gotoXY(24+vitri,y);
		key = GetKey(); //Bat phim
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 10))
		{
			check->MAMH[vitri] = char(key);
			check->MAMH[vitri] = toupper(check->MAMH[vitri]);
			cout<<check->MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(24+vitri, y);
			cout<<" ";
			gotoXY(24+vitri, y);
		}	
		if(key == ENTER && vitri != 0)
		{
			check->MAMH[vitri] = '\0';
			if (check_MH(root,check->MAMH) == 0){TextColor(78);	gotoXY(10,17); printf("KHONG TON TAI MAMH nay. Nhap Lai!");			Sleep(600); goto MAMH;}
			vitri = 0;
			gotoXY(39+vitri,y);
			goto NIENKHOA;
		}
		if(key == ESC)	{ return;}
	}
NIENKHOA:
	while(1){
		TextColor(244); gotoXY(10,17); printf("Ki tu: (0-9) & \"-\". Toi da: 9   ");
		TextColor(3); gotoXY(39+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && vitri < 9 && vitri != 4)
		{
			check->NIENKHOA[vitri] = char(key);
			cout<<check->NIENKHOA[vitri];
			vitri++;
		}
		if((key == '-') && vitri == 4)
		{
			check->NIENKHOA[vitri] = char(key);
			cout<<check->NIENKHOA[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(39+vitri, y);
			cout<<" ";
			gotoXY(39+vitri, y);
		}
		if(key == ENTER && vitri != 0 && vitri ==9)
		{
			check->NIENKHOA[vitri] = '\0';
			vitri = 0;
			gotoXY(56+vitri, y);
			goto HOCKY;
		}
		if(key == ESC){return;}
	}
HOCKY:
	while(1){
		TextColor(244); gotoXY(10,17); printf("Ki tu: 1 -> 3. Toi da: 1        ");
		TextColor(3); gotoXY(56+vitri,y);
		key = GetKey();
		if(( key <= '3' && key >= '1') && (vitri < 1))
		{
			Hocky[vitri] = char(key);
			cout<<Hocky[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(56+vitri, y);
			cout<<" ";
			gotoXY(56+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			Hocky[vitri] = '\0';
			check->HOCKY = atoi(Hocky);
			vitri = 0;
			gotoXY(67+vitri,y);
			goto NHOM;
		}
		if(key == ESC){return;}
	}
NHOM:
	while(1)
	{
		TextColor(244); gotoXY(10,17); printf("Ki tu: (0-9). Toi da: 3         ");
		TextColor(3); gotoXY(67+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			Nhom[vitri] = char(key);
			cout<<Nhom[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(67+vitri, y);
			cout<<" ";
			gotoXY(67+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			Nhom[vitri] = '\0';
			check->NHOM = atoi(Nhom);
			vitri = 0;
			gotoXY(79+vitri,y);
			goto SOSVMIN;
		}
		if(key == ESC){return;}
	}	
SOSVMIN:
	while(1)
	{
		TextColor(244); gotoXY(10,17); printf("Ki tu: (0-9). Toi da: 4                    ");
		TextColor(3); gotoXY(79+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 4))
		{
			svmin[vitri] = char(key);
			cout<<svmin[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(79+vitri, y);
			cout<<" ";
			gotoXY(79+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			svmin[vitri] = '\0';
			check->SOSVMIN = atoi(svmin);
			vitri = 0;
			gotoXY(94+vitri,y);
			goto SOSVMAX;
		}
		if(key == ESC){return;}
	}	
SOSVMAX:
	while(1)
	{
		TextColor(244); gotoXY(10,17); printf("Ki tu: (0-9). Toi da: 4                              ");
		TextColor(3); gotoXY(94+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 4))
		{
			svmax[vitri] = char(key);
			cout<<svmax[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(94+vitri, y);
			cout<<" ";
			gotoXY(94+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			svmax[vitri] = '\0';
			check->SOSVMAX = atoi(svmax);
			if(check->SOSVMIN > check->SOSVMAX){
				TextColor(78);	
				gotoXY(10,17); printf("SOSVMIN khong duoc lon hon SOSVMAX!");			
				Sleep(600); goto SOSVMAX;
			}
			if(check->SOSVMAX < DemSV_DKLTC(temp->DSDK)){
				TextColor(78);	
				gotoXY(10,17); printf("SOSVMAX khong duoc nho hon so SV Dang KY LTC!");			
				Sleep(600); goto SOSVMAX;
			}
			if(strcmp(temp->MAMH,check->MAMH) != 0 || strcmp(temp->NIENKHOA,check->NIENKHOA) != 0 || temp->HOCKY != check->HOCKY || temp->NHOM != check->NHOM){
				if (checkLTC_MH_NK_HK_Nhom(dsltc,check)) { 
					TextColor(78);	
					gotoXY(10,17); printf("Trung LOP TIN CHI!");			
					Sleep(600); TextColor(3);
					return;
				}
			}
			strcpy(temp->MAMH,check->MAMH); strcpy (temp->NIENKHOA,check->NIENKHOA);
			temp->HOCKY = check->HOCKY; temp->NHOM = check->NHOM; temp->SOSVMIN = check->SOSVMIN; temp->SOSVMAX = check->SOSVMAX;
			delete check; return;
		}
		if(key == ESC){ delete check; return;}
	}	

}

void SuaLopTC1(DSLOPTC &dsltc, PTRMH root) {
	int key, vitri = 0, y = 13;
	char malop[4]; malop[0]='\0';
	LTC *temp;
	Khung_Sua_Lop1();
Reset:
	while(1){
		TextColor(244);	gotoXY(10,14); printf("Ki tu:(0-9). Toi da: 4"); TextColor(3); gotoXY(36+vitri,y);
		key = GetKey(); //Bat phim
		if(( key <= '9' && key >= '0') && (vitri < 4))
		{
			malop[vitri] = char(key);
			cout<<malop[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(36+vitri, y);
			cout<<" ";
			gotoXY(36+vitri, y);
		}	
		if(key == ENTER && vitri != 0)
		{
			malop[vitri] = '\0';
			temp = Find_LTC(dsltc,atoi(malop));
			if (temp == NULL){TextColor(78);	gotoXY(10,15); printf("KHONG TON TAI LTC nay. Nhap Lai!");			Sleep(600); goto Reset;}
			SuaLopTC(dsltc,root,temp);
			return;
		}
		if(key == ESC)	{return;}
	}
}

void XoaLopTC(DSLOPTC &dsltc)
{
	int key, x = 36, y = 13, vitri = 0, vitriMang, temp;
	char malop[4]; malop[0] = '\0';
	Khung_Xoa_Lop();	gotoXY(x,y);
Reset:	
	while(1)
	{
		key = GetKey();
		TextColor(3);
		if(( key >='0' && key <= '9' ) && (vitri < 4))
		{
			malop[vitri] = char(key);
			malop[vitri] = toupper(malop[vitri]);
			cout<<malop[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(36+vitri, y);
			cout<<" ";
			gotoXY(36+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			malop[vitri] = '\0';
			temp = KTMaLop(dsltc, malop, dsltc.soluong_ltc);
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;
				}else{
					vitriMang = temp;
				}
				if(dsltc.LOPTC[vitriMang]->DSDK != NULL)
				{
					TextColor(78);	gotoXY(10,15); printf("LTC nay da co SV Dang Ky");		Sleep(600); gotoXY(36+vitri, y); goto Reset;
				}
				for(int i = vitriMang; i < dsltc.soluong_ltc; i++){	dsltc.LOPTC[i] = dsltc.LOPTC[i+1];	}
				dsltc.soluong_ltc--;
				return;
			}else{
				TextColor(78);	gotoXY(10,15); printf("KHONG TON TAI LTC nay. Nhap Lai!");		Sleep(600); gotoXY(36+vitri, y); goto Reset;;
			}
		}
		
		if(key == ESC)		{return;}
	}
}

void XuatLop(DSLOPTC &dsltc, PTRMH root)
{
 	int key, dem = 0, trang = 0, tongtrang = 0;
	while(1)
	{		
		if(dsltc.soluong_ltc == 0)
 		{
 			GhiChu("Chua co Danh Sach Lop TC",35,27,74,1000);
		}else{
			if(dsltc.soluong_ltc < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((dsltc.soluong_ltc-1)/15+1);
			}
		}
		system("cls");	Khung_Xuat_Lop();
		dem = 0;
		for( int i = trang*15 ; i < 15 + trang*15 && i < dsltc.soluong_ltc ; i++)
		{
			TextColor(7);
			PTRMH temp = FindMaMH(root,dsltc.LOPTC[i]->MAMH);
			gotoXY(6, 7+dem); cout<< ( i+1 );
			gotoXY(14,7+dem); cout<<dsltc.LOPTC[i]->MALOPTC ;
			gotoXY(20,7+dem); cout<<temp->mh.TENMH;
			gotoXY(33,7+dem); cout<<dsltc.LOPTC[i]->NIENKHOA ;
			gotoXY(48,7+dem); cout<<dsltc.LOPTC[i]->HOCKY;
			gotoXY(56,7+dem); cout<<dsltc.LOPTC[i]->NHOM ;
			gotoXY(65,7+dem); cout<<dsltc.LOPTC[i]->SOSVMIN ;
			gotoXY(77,7+dem); cout<<dsltc.LOPTC[i]->SOSVMAX ;
			gotoXY(86,7+dem);
			if (dsltc.LOPTC[i]->TRANGTHAI == 1) cout<<"DUOC MO"; else cout <<"BI HUY"; 	
			dem++;
		}
		HienThiTrang(trang+1,tongtrang,73,26);
		
		key = GetKey(); //Bat Phim
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)	{trang++;}
		if((key == LEFT || key == UP) && trang > 0) 				{trang--;}
		if(key == INSERT)
		{	
			if(Full_Lop(dsltc)) {continue;} 
			else {
				gotoXY(18,23);  TextColor(251);	printf("Insert"); //To mau Insert
				ThemLopTC(dsltc,root);
			}	
		}
		if(key == F2)
		{
			gotoXY(46,23);	TextColor(251);	printf("F2"); //To mau` F2
			SuaLopTC1(dsltc,root);
		}
		if(key == DELETE)
		{
			gotoXY(58,23);	TextColor(251);	printf("Delete"); //To mau` F3 
			XoaLopTC(dsltc);
		}
		if(key == ESC)
		{
			putchar(7);	gotoXY(4,24); TextColor(251);printf("ESC"); //To mau` ESC
			int temp = ThongBao_ESC();
			if(temp == 1)	{char c[50]= "Luu Vao File Thanh Cong!" ;GhiChu(c,35,27,74,2000);LuuFileLopTC(dsltc);}
			system("cls");
			return;
		}
	}
}

void NhapDiem(LTC *ltc, DSSV dssv, PTRMH root){
	int key, x = 90, y = 9, trang = 0, tongtrang = 0, soluongSV=0, vitri =0, dem = 0,  demdong = 0;
	char diem[5]; diem[0] = '\0';
	soluongSV = DemSV_DKLTC(ltc->DSDK);
	if(soluongSV == 0)
	{
		char c[50]="Lop hoc chua co sinh vien dang ki";
		GhiChu(c,35,27,74,500);
	}else{
		if(soluongSV < 15)
		{
			tongtrang = 1;
			trang = 0;	
		}else{
			tongtrang = ((soluongSV-1)/15+1);
		}
	}
	DKLOPTC p[soluongSV+1];
	MangTam_SVDKLTC(ltc->DSDK, p);
	PTRMH mh; mh = FindMaMH(root,ltc->MAMH);
Reset:
	system("cls"); 
	TextColor(241); 	Khung_Xuat_Diem(); ;	
	gotoXY(36,2); cout <<mh->mh.TENMH;
	gotoXY(41,3); cout <<ltc->NIENKHOA;
	gotoXY(61,3); cout <<ltc->HOCKY;
	gotoXY(72,3); cout <<ltc->NHOM;
	for( int i = trang*15 ; i < 15 + trang*15 && i < soluongSV ; i++)
	{
		if(p[i].TRANGTHAI == 1){
			SINHVIEN sv; sv = FindSV_MSSV(dssv,p[i].MASV);
			TextColor(7);
			gotoXY(6, 9+demdong); cout<< ( i+1 );
			gotoXY(11,9+demdong); cout<< p[i].MASV;
			gotoXY(27,9+demdong); cout<< sv.HO;
			gotoXY(77,9+demdong); cout<< sv.TEN;
			//gotoXY(90,9+demdong); cout<< p[i].DIEM;
			demdong++;
		}	
	}
	demdong = 0;
	HienThiTrang(trang+1, tongtrang, 50, 27);
	vitri = 0;
	gotoXY(x+vitri,y);	
while(1)
	{
		TextColor(241);				//Chu thich
		gotoXY(15,29); printf("                                                 ");
		gotoXY(15,30); printf("     DIEM SINH VIEN: Nhap tu 0.00 den 10.00.     ");
		gotoXY(15,31); printf("                                                 "); 
		TextColor(3);gotoXY(x+vitri,y);
		key = GetKey();
		if( ((key <= '9' && key >= '0') || key == '.') && (vitri < 4))
		{
			diem[vitri]=char(key);
			cout<<diem[vitri];
			vitri++;
		}
		if(key == ENTER )
		{
			diem[vitri] = '\0';
			if(atof(diem) > 10 || diem[0] == '.' || diem[2] == '.' )
			{
				GhiChu("Diem khong hop le : DIEM > = 0   &&   DIEM <= 10 && Chua mot chu so thap phan ",20,27,74,500);	continue;
			}
			p[dem].DIEM= atof(diem);
			if(vitri > 0){GhiChu("Save Thanh Cong!",35,27,74,300); TextColor(241);}
			dem++;
			vitri = 0;
			// if(dem % 15 == 0)
			// {
			// 	trang++;
			// 	y = 8;
			// 	goto Reset;
			// }
			gotoXY(x+vitri, ++y);
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(x+vitri, y);
			cout<<" ";
			gotoXY(x+vitri, y);
		}
		// if((key == RIGHT) && trang < tongtrang - 1)
		// {
		// 	diem[vitri] = '\0';
		// 	if(atof(diem) > 10 || diem[0] == '.' || diem[2] == '.' )
		// 	{
		// 		GhiChu("Diem khong hop le : DIEM > = 0   &&   DIEM <= 10 && Chua mot chu so thap phan",20,27,74,500);	continue;
		// 	}
		// 	trang++;
		// 	dem += 15;
		// 	if(dem > soluongSV) //Neu lat qua trang va vuot qua so luong sinh vien
		// 	{
		// 		dem = soluongSV-1;
		// 		y = dem%15 + 8;
		// 	}
		// 	vitri = 0;
		// 	goto Reset;
		// }
		// if((key == LEFT) && trang > 0)
		// {
		// 	diem[vitri] = '\0';
		// 	if(atof(diem) > 10 || diem[0] == '.' || diem[2] == '.' )
		// 	{GhiChu("Diem khong hop le : DIEM > = 0   &&   DIEM <= 10 && Chua mot chu so thap phan",20,27,74,500);	continue;
		// 	}
		// 	trang--;
		// 	dem -= 15;
		// 	vitri = 0;
		// 	goto Reset;
		// }
		if(key == ESC)
		{
			// diem[vitri] = '\0';
			// putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
			// int i = 0;
			// LTC *temp;
			// int err = ThongBao_ESC();
			// if(err == -1)	//TH bat duoc them 1 phim' ESC
			// {
			// 	gotoXY(4,24);  TextColor(252);	printf("ESC"); TextColor(91); //Tô màu ESC
			// 	goto Reset;
			// }
			// if(err == 1)
			// {
			// 	GhiChu("Luu Vao File Thanh Cong!",30,27,74,2000); 
			// 	system("cls");	return;
			// }	
			// if(err == 0)
			// {
			// 	system("cls");	return;
			// }
			return;
		}
	}
}