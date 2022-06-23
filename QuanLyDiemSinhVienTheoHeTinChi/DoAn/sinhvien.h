#pragma once
#include <iostream>
#include "khaibao_Struct.h"
#include <fstream>
#include <string.h>
#include "Frame.h"
using namespace std;

bool isEmpty(DSSV dsSV)
{     
    if (dsSV.soluong_SV==0) return true;
    return false;
}
void SapXepSVTenHo(DSSV &dssv){
	//Bubble Sort
	bool flag = TRUE;
	if (dssv.soluong_SV == 0) return;
	while (flag){
		flag = FALSE;
		for (int i=0; i<dssv.soluong_SV - 1; i++){
			if (strcmp (dssv.SV[i].TEN,dssv.SV[i+1].TEN) > 0){
				SINHVIEN temp = dssv.SV[i];
				dssv.SV[i] = dssv.SV[i+1];
				dssv.SV[i+1] = temp;
				flag = TRUE;
			}
			else if (strcmp(dssv.SV[i].TEN,dssv.SV[i+1].TEN) == 0){
				if (strcmp(dssv.SV[i].HO,dssv.SV[i+1].HO) > 0) {
					SINHVIEN temp = dssv.SV[i];
					dssv.SV[i] = dssv.SV[i+1];
					dssv.SV[i+1] = temp;
					flag = TRUE;
				}
			}
		}
	}
}
void LuuFileSV(DSSV &dssv){
	fstream f;
	f.open("DSSINHVIEN.txt", ios::out);
	f << dssv.soluong_SV <<endl;
	for (int i=0; i<dssv.soluong_SV; i++){
		f <<'|' <<dssv.SV[i].MASV <<'|' <<dssv.SV[i].HO <<'|' <<dssv.SV[i].TEN <<'|' <<dssv.SV[i].PHAI <<'|' <<dssv.SV[i].SDT <<'|' <<dssv.SV[i].MALOP <<endl;
	}
	f.close();
}
void DocFileSV(DSSV &dsSV)
{
	int n; char data1[4];
	fstream f("DSSINHVIEN.txt", ios::in);
    if (f.fail()) return;
	if(f.is_open()){
        f.getline(data1,4,'|');  n = atoi(data1);
        for (int i=0; i<n; i++){
            char data2[16], data3[50], data4[11], data5[4], data6[12], data7[16];
            f.getline(data2,16,'|'); strcpy(dsSV.SV[i].MASV,data2);
            f.getline(data3,50,'|'); strcpy(dsSV.SV[i].HO,data3);
            f.getline(data4,11,'|'); strcpy(dsSV.SV[i].TEN,data4);
            f.getline(data5,4,'|'); strcpy(dsSV.SV[i].PHAI,data5);
            f.getline(data6,12,'|'); strcpy(dsSV.SV[i].SDT,data6);
            f.getline(data7,16,'|'); strcpy(dsSV.SV[i].MALOP,data7);
            dsSV.soluong_SV++;
        }
       
    }
	f.close();
}
int check_SV(DSSV &dsSV, char c[]){
    if (isEmpty(dsSV)) return 0;
    for(int i=0; i<dsSV.soluong_SV; i++){
        if (strcmp(c,dsSV.SV[i].MASV) == 0) return 1;
    }
    return 0;
}
SINHVIEN FindSV_MSSV(DSSV &dsSV, char c[]){
    SINHVIEN sv;
    for(int i=0; i<dsSV.soluong_SV; i++){
        if (strcmp(c,dsSV.SV[i].MASV) == 0){
            sv = dsSV.SV[i];
            break;
        }
    }
    return sv;
}
void ThongTinSV(SINHVIEN sv){
     gotoXY(0,0);
     TextColor(144); cout <<"     THONG TIN SINH VIEN DANG KY     ";
     TextColor(244);
     cout <<"\n MA LOP:                             ";
     cout <<"\n MSSV  :                             ";
     cout <<"\n HO TEN:                             ";
     cout <<"\n PHAI  :                             ";
     cout <<"\n SDT   :                             ";
     TextColor(241);
     gotoXY(9,1); cout << sv.MALOP;
     gotoXY(9,2); cout << sv.MASV;
     gotoXY(9,3); cout << sv.HO <<' ' <<sv.TEN;
     gotoXY(9,4); cout << sv.PHAI;
     gotoXY(9,5); cout << sv.SDT;
 }

 //Cuong
 int Full_SV(DSSV &dssv)	//tra ve 1: tran bo nho da cap phat
{
	if(dssv.soluong_SV == MAXSINHVIEN-1){GhiChu("Danh sach Sinh Vien Full. Khong the them!",35,27,74,700); return 1;} return 0;
}

void ThemSV(DSSV &dssv)
{	
	//Khoi tao rong~
	//dssv.soluong_SV++;
	dssv.SV[dssv.soluong_SV].MASV[0] = '\0';
	dssv.SV[dssv.soluong_SV].HO[0] = '\0';
	dssv.SV[dssv.soluong_SV].TEN[0] = '\0';
	dssv.SV[dssv.soluong_SV].SDT[0] = '\0';
	dssv.SV[dssv.soluong_SV].PHAI[0] = '\0';
	dssv.SV[dssv.soluong_SV].MALOP[0] = '\0';
	int key, vitri = 0, x = 12, y = 14;
	Khung_Them_SV();	
	TextColor(3); gotoXY(12,y); 
MASV:
	while(1)
	{
		TextColor(244);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 10      "); TextColor(3); gotoXY(12+vitri,y);
		key = GetKey(); //Bat phim
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			dssv.SV[dssv.soluong_SV].MASV[vitri] = char(key);
			dssv.SV[dssv.soluong_SV].MASV[vitri] = toupper( dssv.SV[dssv.soluong_SV].MASV[vitri]);
			cout<<dssv.SV[dssv.soluong_SV].MASV[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12+vitri, y);
			cout<<" ";
			gotoXY(12+vitri, y);
		}	
		if(key == ENTER && vitri != 0)
		{
			dssv.SV[dssv.soluong_SV].MASV[vitri] = '\0';
			if (check_SV(dssv,dssv.SV[dssv.soluong_SV].MASV) == 1){TextColor(78);	gotoXY(10,15); printf("MA SINH VIEN DA TON TAI. Nhap Lai!");			Sleep(600); goto MASV;}
			vitri = 0;
			gotoXY(29+vitri,y);
			goto HO;
		}
		if(key == ESC)	{   return;}
	}
HO:
	while(1){
		TextColor(244); gotoXY(10,15); printf("Ki tu: (A-Z) & \"-\". Toi da: 50   ");
		TextColor(3); gotoXY(29+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z')  || ( key >='a' && key <= 'z' )) && (vitri < 50))
		{
			dssv.SV[dssv.soluong_SV].HO[vitri] = char(key);
			dssv.SV[dssv.soluong_SV].HO[vitri] = toupper( dssv.SV[dssv.soluong_SV].HO[vitri]);
			cout<<dssv.SV[dssv.soluong_SV].HO[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(29+vitri, y);
			cout<<" ";
			gotoXY(29+vitri, y);
		}
		if( key == SPACE && dssv.SV[dssv.soluong_SV].HO[vitri-1] != ' ' && vitri > 0 && vitri < 50) // ko cho 2 khoang trang && vitri = 0
		{	
			gotoXY(29+vitri , y);
			cout<<" ";
			dssv.SV[dssv.soluong_SV].HO[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			dssv.SV[dssv.soluong_SV].HO[vitri] = '\0';
			vitri = 0;
			gotoXY(51+vitri, y);
			goto TEN;
		}
		if(key == ESC){ return;}
	}
TEN:
	while(1){
		TextColor(244); gotoXY(10,15); printf("Ki tu:  (A-Z). Toi da: 10        ");
		TextColor(3); gotoXY(51+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z')  || ( key >='a' && key <= 'z' )) && (vitri < 10))
		{
			dssv.SV[dssv.soluong_SV].TEN[vitri] = char(key);
			dssv.SV[dssv.soluong_SV].TEN[vitri] = toupper( dssv.SV[dssv.soluong_SV].TEN[vitri]);
			cout<<dssv.SV[dssv.soluong_SV].TEN[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(51+vitri, y);
			cout<<" ";
			gotoXY(51+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			dssv.SV[dssv.soluong_SV].TEN[vitri] = '\0';
			vitri = 0;
			gotoXY(63+vitri,y);
			goto PHAI;
		}
		if(key == ESC){ return;}
	}
PHAI:
	while(1)
	{
		TextColor(244); gotoXY(10,15); printf("Ki tu: (A-Z). Toi da: 4                    ");
		TextColor(3); gotoXY(63+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z')  || ( key >='a' && key <= 'z' )) && (vitri < 4))
		{
			dssv.SV[dssv.soluong_SV].PHAI[vitri] = char(key);
			dssv.SV[dssv.soluong_SV].PHAI[vitri] = toupper( dssv.SV[dssv.soluong_SV].PHAI[vitri]);
			cout<<dssv.SV[dssv.soluong_SV].PHAI[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(63+vitri, y);
			cout<<" ";
			gotoXY(63+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			dssv.SV[dssv.soluong_SV].PHAI[vitri] = '\0';
			if (strcmp(dssv.SV[dssv.soluong_SV].PHAI,"NAM") != 0 && strcmp(dssv.SV[dssv.soluong_SV].PHAI,"NU") != 0){
				TextColor(78);	gotoXY(10,15); printf("PHAI CHI NHAN NAM HOAC NU!     ");			Sleep(600); goto PHAI;
			}
			vitri = 0;
			gotoXY(68+vitri,y);
			goto SDT;
		}
		if(key == ESC){ return;}
	}
	
SDT:
	while(1)
	{
		TextColor(244); gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 10         ");
		TextColor(3); gotoXY(68+vitri,y);
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 10))
		{
			dssv.SV[dssv.soluong_SV].SDT[vitri] = char(key);
			cout<<dssv.SV[dssv.soluong_SV].SDT[vitri];
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
			dssv.SV[dssv.soluong_SV].SDT[vitri] = '\0';
			vitri = 0;
			gotoXY(80+vitri,y);
			goto MALOP;
		}
		if(key == ESC){ return;}
	}	
	
MALOP:
	while(1)
	{
		TextColor(244); gotoXY(10,15); printf("Ki tu: (A-Z) $ (0-9). Toi da: 15                              ");
		TextColor(3); gotoXY(80+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) || (key == '-') && (vitri < 15))
		{
			dssv.SV[dssv.soluong_SV].MALOP[vitri] = char(key);
			dssv.SV[dssv.soluong_SV].MALOP[vitri] = toupper( dssv.SV[dssv.soluong_SV].MALOP[vitri]);
			cout<<dssv.SV[dssv.soluong_SV].MALOP[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(80+vitri, y);
			cout<<" ";
			gotoXY(80+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			dssv.SV[dssv.soluong_SV].MALOP[vitri] = '\0';
			dssv.soluong_SV++;
			return;
		}
		if(key == ESC){ return;}
	}	
}

// void SuaSV(DSSV &dssv, PTRMH root, SINHVIEN *&temp){
// 	int key, vitri = 0, x = 12, y = 16;
// 	SINHVIEN *check = new SINHVIEN;
// 	Khung_Sua_SV();
// 	TextColor(3);
// 	gotoXY(12,14); cout <<temp->MASV;
// 	gotoXY(24,14); cout <<temp->HO;
// 	gotoXY(39,14); cout <<temp->TEN;
// 	gotoXY(54,14); cout <<temp->SDT;
// 	gotoXY(66,14); cout <<temp->PHAI;
// 	gotoXY(75,14); cout <<temp->MALOP;
// MASV:
// 	while(1)
// 	{
// 		TextColor(244);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 10      "); TextColor(3); gotoXY(24+vitri,y);
// 		key = GetKey(); //Bat phim
// 		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
// 		{
// 			check->MASV[vitri] = char(key);
// 			check->MASV[vitri] = toupper( check->MASV[vitri]);
// 			cout<<check->MASV[vitri];
// 			vitri++;
// 		}
// 		if( key == BACKSPACE && vitri > 0)
// 		{
// 			vitri--;
// 			gotoXY(24+vitri, y);
// 			cout<<" ";
// 			gotoXY(24+vitri, y);
// 		}	
// 		if(key == ENTER && vitri != 0)
// 		{
// 			check->MASV[vitri] = '\0';
// 			if (check_SV(dssv,check->MASV) == 0){TextColor(78);	gotoXY(10,15); printf("MA SINH VIEN DA TON TAI. Nhap Lai!");			Sleep(600); goto MASV;}
// 			vitri = 0;
// 			gotoXY(39+vitri,y);
// 			goto HO;
// 		}
// 		if(key == ESC)	{ return;}
// 	}
// HO:
// 	while(1){
// 		TextColor(244); gotoXY(10,15); printf("Ki tu: (A-Z) & \"-\". Toi da: 50   ");
// 		TextColor(3); gotoXY(39+vitri,y);
// 		key = GetKey();
// 		if((( key >= 'A' && key <= 'Z')  || ( key >='a' && key <= 'z' )) && (vitri < 50))
// 		{
// 			check->HO[vitri] = char(key);
// 			cout<<check->HO[vitri];
// 			vitri++;
// 		}
// 		if( key == BACKSPACE && vitri > 0)
// 		{
// 			vitri--;
// 			gotoXY(39+vitri, y);
// 			cout<<" ";
// 			gotoXY(39+vitri, y);
// 		}
// 		if(key == ENTER && vitri != 0 && vitri ==9)
// 		{
// 			check->HO[vitri] = '\0';
// 			vitri = 0;
// 			gotoXY(56+vitri, y);
// 			goto TEN;
// 		}
// 		if(key == ESC){return;}
// 	}
// TEN:
// 	while(1){
// 		TextColor(244); gotoXY(10,15); printf("Ki tu:  (A-Z). Toi da: 10        ");
// 		TextColor(3); gotoXY(56+vitri,y);
// 		key = GetKey();
// 		if((( key >= 'A' && key <= 'Z')  || ( key >='a' && key <= 'z' )) && (vitri < 10))
// 		{
// 			check->TEN[vitri] = char(key);
// 			cout<<check->TEN[vitri];
// 			vitri++;
// 		}
// 		if( key == BACKSPACE && vitri > 0)
// 		{
// 			vitri--;
// 			gotoXY(56+vitri, y);
// 			cout<<" ";
// 			gotoXY(56+vitri, y);
// 		}
// 		if(key == ENTER && vitri != 0)
// 		{
// 			check->HO[vitri] = '\0';
// 			vitri = 0;
// 			gotoXY(67+vitri,y);
// 			goto SDT;
// 		}
// 		if(key == ESC){return;}
// 	}
// SDT:
// 	while(1)
// 	{
// 		TextColor(244); gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 10         ");
// 		TextColor(3); gotoXY(67+vitri,y);
// 		key = GetKey();
// 		if(( key <= '9' && key >= '0') && (vitri < 10))
// 		{
// 			check->SDT[vitri] = char(key);
// 			cout<<check->SDT[vitri];
// 			vitri++;
// 		}
// 		if( key == BACKSPACE && vitri > 0)
// 		{
// 			vitri--;
// 			gotoXY(67+vitri, y);
// 			cout<<" ";
// 			gotoXY(67+vitri, y);
// 		}
// 		if(key == ENTER && vitri != 0)
// 		{
// 			check->SDT[vitri] = '\0';
// 			vitri = 0;
// 			gotoXY(79+vitri,y);
// 			goto PHAI;
// 		}
// 		if(key == ESC){return;}
// 	}	
// PHAI:
// 	while(1)
// 	{
// 		TextColor(244); gotoXY(10,15); printf("Ki tu: (A-Z). Toi da: 4                    ");
// 		TextColor(3); gotoXY(79+vitri,y);
// 		key = GetKey();
// 		if((( key >= 'A' && key <= 'Z')  || ( key >='a' && key <= 'z' )) && (vitri < 4))
// 		{
// 			check->PHAI[vitri] = char(key);
// 			cout<<check->PHAI[vitri];
// 			vitri++;
// 		}
// 		if( key == BACKSPACE && vitri > 0)
// 		{
// 			vitri--;
// 			gotoXY(79+vitri, y);
// 			cout<<" ";
// 			gotoXY(79+vitri, y);
// 		}
// 		if(key == ENTER && vitri != 0)
// 		{
// 			check->PHAI[vitri] = '\0';
// 			vitri = 0;
// 			gotoXY(94+vitri,y);
// 			goto MALOP;
// 		}
// 		if(key == ESC){return;}
// 	}	
// MALOP:
// 	while(1)
// 	{
// 		TextColor(244); gotoXY(10,15); printf("Ki tu: (A-Z) $ (0-9). Toi da: 15                              ");
// 		TextColor(3); gotoXY(94+vitri,y);
// 		key = GetKey();
// 		if((( key >= 'A' && key <= 'Z')  || ( key >='a' && key <= 'z' )) && (vitri < 15))
// 		{
// 			check->MALOP[vitri] = char(key);
// 			cout<<check->MALOP[vitri];
// 			vitri++;
// 		}
// 		if( key == BACKSPACE && vitri > 0)
// 		{
// 			vitri--;
// 			gotoXY(94+vitri, y);
// 			cout<<" ";
// 			gotoXY(94+vitri, y);
// 		}
// 		if(key == ENTER && vitri != 0)
// 		{
// 			check->MALOP[vitri] = '\0';
// 			strcpy(temp->MASV,check->MASV); strcpy (temp->HO,check->HO);
// 			strcpy(temp->TEN,check->TEN); strcpy (temp->SDT,check->SDT);
// 			strcpy(temp->PHAI,check->PHAI); strcpy (temp->MALOP,check->MALOP);
// 			delete check; 
// 			return;
// 		}
// 		if(key == ESC){delete check;return;}
// 	}	
// }
// void SuaSV1(DSSV &dssv, PTRMH root) {
// 	int key, t, vitri = 0, y = 13;
// 	char maSV[15]; maSV[0]='\0';
// 	SINHVIEN *temp;
// 	//Khung_Sua_SV1();
// Reset:
// 	while(1){
// 		TextColor(244);	gotoXY(10,14); printf("Ki tu: (A-Z) & (0-9). Toi da: 15"); TextColor(3); gotoXY(36+vitri,y);
// 		key = GetKey(); //Bat phim
// 		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
// 		{
// 			maSV[vitri] = char(key);
// 			cout<<maSV[vitri];
// 			vitri++;
// 		}
// 		if( key == BACKSPACE && vitri > 0)
// 		{
// 			vitri--;
// 			gotoXY(36+vitri, y);
// 			cout<<" ";
// 			gotoXY(36+vitri, y);
// 		}	
// 		if(key == ENTER && vitri != 0)
// 		{
// 			maSV[vitri] = '\0';
// 			t = check_SV(dssv,maSV);
// 			if (t == 1){TextColor(78);	gotoXY(10,15); printf("KHONG TON TAI SINH VIEN NAY. Nhap Lai!");			Sleep(600); goto Reset;}
// 			SuaSV(dssv,root,temp);
// 			return;
// 		}
// 		if(key == ESC)	{return;}
// 	}
// }

// void XoaSV(DSSV &dssv)
// {
// 	int key, x = 36, y = 13, vitri = 0, vitriMang, temp;
// 	char maSV[4]; maSV[0] = '\0';
// 	Khung_Xoa_SV();	gotoXY(x,y);
// Reset:	
// 	while(1)
// 	{
// 		TextColor(244);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 15      "); TextColor(3); gotoXY(36+vitri,y);
// 		key = GetKey();
// 		TextColor(3);
// 		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
// 		{
// 			maSV[vitri] = char(key);
// 			maSV[vitri] = toupper(maSV[vitri]);
// 			cout<<maSV[vitri];
// 			vitri++;
// 		}
// 		if( key == BACKSPACE && vitri > 0)
// 		{
// 			vitri--;
// 			gotoXY(36+vitri, y);
// 			cout<<" ";
// 			gotoXY(36+vitri, y);
// 		}
// 		if(key == ENTER && vitri!=0)
// 		{
// 			maSV[vitri] = '\0';
// 			temp = check_SV(dssv, maSV);
// 			if( temp != 0)
// 			{
// 				if(temp == -1)
// 				{
// 					vitriMang = 0;
// 				}else{
// 					vitriMang = temp;
// 				}
// 				for(int i = vitriMang; i < dssv.soluong_SV; i++){	dssv.SV[i] = dssv.SV[i+1];	} //d�n` l�n giam? di 1 don vi
// 				dssv.soluong_SV--;
// 				return;
// 			}else
// 				TextColor(78);	gotoXY(10,15); printf("KHONG TON TAI MA SINH VIEN TRONG DANH SACH. Nhap Lai!");		Sleep(600); gotoXY(36+vitri, y); goto Reset;
// 		}		
// 		if(key == ESC)		{return;}
// 	}
// }

void XuatSV(DSSV &dsSV, PTRMH root)	
{
 	int key, dem = 0, trang = 0, tongtrang = 0; bool check_change = false;
	while(1)
	{		
		if(dsSV.soluong_SV == 0)
 		{
 			GhiChu("Chua co Danh Sach Sinh vien",35,27,74,1000);
		}else{
			if(dsSV.soluong_SV < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((dsSV.soluong_SV-1)/15+1);
			}
		}
		system("cls");	Khung_Xuat_SV(); SapXepSVTenHo(dsSV);
		dem = 0;
		for( int i = trang*15 ; i < 15 + trang*15 && i < dsSV.soluong_SV ; i++)
		{
			TextColor(7);
			gotoXY(6, 8+dem); cout<< ( i+1 );
			gotoXY(11,8+dem); cout<<dsSV.SV[i].MASV ;
			gotoXY(26,8+dem); cout<<dsSV.SV[i].HO;
			gotoXY(61,8+dem); cout<<dsSV.SV[i].TEN ;
			gotoXY(72,8+dem); cout<<dsSV.SV[i].PHAI ;
			gotoXY(79,8+dem); cout<<dsSV.SV[i].SDT ;
            gotoXY(93,8+dem); cout <<dsSV.SV[i].MALOP;
			dem++;
		}
		HienThiTrang(trang+1,tongtrang,73,26);
		key = GetKey(); //Bat Phim
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)	{trang++;}
		if((key == LEFT || key == UP) && trang > 0) 				{trang--;}
		if(key == INSERT)
		{	
			if(Full_SV(dsSV) == 1) {continue;} else {
				gotoXY(18,23);  TextColor(251);	printf("Insert"); //To mau Insert
				ThemSV(dsSV);
			}	
		}
		if(key == F2)
		{
			gotoXY(46,23);	TextColor(251);	printf("F2"); //To mau` F2
			//SuaSV1(dsSV,root);
		}
		if(key == DELETE)
		{
			gotoXY(58,23);	TextColor(251);	printf("Delete"); //To mau` F3 
			//XoaSV(dsSV);
		}
		if(key == ESC)
		{

			putchar(7);	gotoXY(4,24); TextColor(251);printf("ESC"); //To mau` ESC
			int temp = ThongBao_ESC();
			if(temp ==1) {GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileSV(dsSV);}
			system("cls");
			return;
		}
	}
}
