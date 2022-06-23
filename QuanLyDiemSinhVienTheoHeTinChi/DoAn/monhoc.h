#pragma once
#include <iostream>
#include "khaibao_Struct.h"
#include <string.h>
#include <fstream>
#include "Frame.h"
using namespace std;

void GiaiPhongMonHoc(PTRMH &root);
int check_MH(PTRMH root, char c[]);
bool isEmptyTree_MH(PTRMH root);
void InsertNode_MH(PTRMH &root, monhoc mh);
void DocFileMH(PTRMH &root);
int DemMonHoc(PTRMH root);
void MangTam_MonHoc(PTRMH root, monhoc mh[], int &dem);
void GhiFile_LNR(fstream &file, PTRMH root);
void LuuFileMH(PTRMH root);
void XoaNodeMonHoc(PTRMH &root, char c[]);
void PhanTuTheMang(PTRMH &p, PTRMH &q);
PTRMH FindMaMH(PTRMH &root, char c[]);
void XoaMonHoc(PTRMH &root, DSLOPTC dsltc);
void ThemMonHoc(PTRMH &root, bool );
void XuatMonHoc(PTRMH &root, DSLOPTC dsltc);
void SuaMonHoc(PTRMH &root);
void BubbleSort_TenMH(MONHOC mh[], int n);
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
void GiaiPhongMonHoc(PTRMH &root){
	if (root != NULL){
		GiaiPhongMonHoc(root->left);
		GiaiPhongMonHoc(root->right);
		delete root;
	}
}
void BubbleSort_TenMH(MONHOC mh[], int n){
	MONHOC temp;
	bool flag = TRUE;
	while (flag){
		flag = FALSE;
		for (int i=0; i<n-1; i++){
			if (strcmp(mh[i].TENMH,mh[i+1].TENMH) > 0) {
				temp = mh[i];
				mh[i] = mh[i+1];
				mh[i+1] = temp;
				flag = TRUE;
			}
		}
	}
}
int check_MH(PTRMH root, char c[]) //Tra ve 1 la trung, tra ve 0 la khong trung
{
	PTRMH p;
	p = root;
	while (p!=NULL)
	{
		if (strcmp(c,p->mh.MAMH) < 0) p = p->left;
			else if (strcmp(c,p->mh.MAMH) > 0) p = p->right;
				else return 1;
	}
	return 0;
}
bool isEmptyTree_MH(PTRMH root)
{
	return (root == NULL ? true : false);
}
void InsertNode_MH(PTRMH &root, MONHOC mh){	
	PTRMH p = new nodemonhoc;
	p->mh = mh;
	p->left = p->right = NULL;
	if(isEmptyTree_MH(root))
	{
		root = p;
	}else{
		if(strcmp(mh.MAMH, root->mh.MAMH) < 0) InsertNode_MH(root->left,mh);
			else  InsertNode_MH(root->right,mh); 
	}
}
void DocFileMH(PTRMH &root){
	fstream f;
	char data1[2];
	f.open("DSMONHOC.txt", ios::in);
	f.getline(data1,2,'|');
	if (f.fail()) return;
	while(!f.eof())
	{
		char data2[11], data3[51], data4[3], data5[3];
		MONHOC mh;
		f.getline(data2,11,'|');		strcpy(mh.MAMH,data2);
		f.getline(data3,51,'|');		strcpy(mh.TENMH,data3);
		f.getline(data4,3,'|');		mh.STCLT = atoi(data4);
		f.getline(data5,3,'|');		mh.STCTH = atoi(data5);
		InsertNode_MH(root,mh);
	}
	f.close();
}
int DemMonHoc(PTRMH root)
{
	if(root != NULL)	{return (DemMonHoc(root->left) + DemMonHoc(root->right) + 1);}
}
void MangTam_MonHoc(PTRMH root, MONHOC mh[], int &dem)
{	
	if(root != NULL)
	{
		MangTam_MonHoc(root->left , mh, dem);
		mh[dem++] = root->mh;
		MangTam_MonHoc(root->right, mh, dem);
	}
}
void GhiFile_LNR(fstream &file, PTRMH root)
{
	if(root != NULL)
	{
		GhiFile_LNR(file,root->left);
		file <<'|' << root->mh.MAMH << '|' << root->mh.TENMH << '|' << root->mh.STCLT << '|' << root->mh.STCTH <<endl;
		GhiFile_LNR(file,root->right);
	}
}
void LuuFileMH(PTRMH root)
{
	fstream f;
	f.open("DSMONHOC.txt",ios::out);
	GhiFile_LNR(f,root);
	f.close();
}
void ThemMonHoc(PTRMH &root) {
	int key, vitri = 0, x = 12, y = 14;
	MONHOC mh; mh.MAMH[0] = '\0';	mh.TENMH[0] = '\0';	mh.STCLT=0;	mh.STCTH=0;
	char lt[3], th[3]; lt[0] = '\0'; th[0] = '\0';
	Khung_Them_MonHoc(); gotoXY(x,y);
MAMH:
	while(1)
	{
		TextColor(244);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 10"); TextColor(3); gotoXY(12+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 10))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout<<mh.MAMH[vitri];
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
			mh.MAMH[vitri] = '\0';
			if(check_MH(root,mh.MAMH)==1) {TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!     ");			Sleep(600); goto MAMH;}
			vitri = 0;
			gotoXY(29+vitri, y);
			goto TENMH;
		}
		if(key == ESC || key == INSERT){return;}
	}
TENMH:
	while(1)
	{
		TextColor(244);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 50"); TextColor(3); gotoXY(29+vitri,y); //Ghi ch�
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 50))
		{
			mh.TENMH[vitri] = char(key);
			mh.TENMH[vitri] = toupper(mh.TENMH[vitri]);
			cout<<mh.TENMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(29+vitri, y);
			cout<<" ";
			gotoXY(29+vitri, y);
		}
		if( key == SPACE && mh.TENMH[vitri-1] != ' ' && vitri > 0 && vitri < 50) // ko cho 2 khoang trang && vitri = 0
		{	
			gotoXY(29+vitri , y);
			cout<<" ";
			mh.TENMH[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			if(mh.TENMH[vitri-1] == ' ')	 {vitri--;} //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TENMH[vitri] = '\0';
			vitri = 0;
			gotoXY(81+vitri, y);
			goto STCLT;
		}
		if(key == ESC || key == INSERT){return;}
	}
STCLT:
	while(1)
	{
		TextColor(244);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 3         ");	TextColor(3); gotoXY(81+vitri,y); // Ghi ch�
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			lt[vitri] = char(key);
			cout<<lt[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(81+vitri, y);
			cout<<" ";
			gotoXY(81+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{	
			lt[vitri] = '\0';
			vitri = 0;
			mh.STCLT = atoi(lt);
			gotoXY(88+vitri, y);
			goto STCTH;
		}
		if(key == ESC || key == INSERT){return;}
	}
STCTH:
	while(1)
	{
		TextColor(244);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 3         ");	TextColor(3); gotoXY(88+vitri,y); // Ghi ch�
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			th[vitri] = char(key);
			cout<<th[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(88+vitri, y);
			cout<<" ";
			gotoXY(88+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			th[vitri] = '\0';
			mh.STCTH = atoi(th);
			InsertNode_MH(root,mh);
			return;
		}
		if(key == ESC || key == INSERT){return;}
	}
}
void XuatMonHoc(PTRMH &root, DSLOPTC dsltc)
{
	int key, trang = 0, tongtrang = 0, soluongmh, dem = 0, demdong = 0;
	while(1)
	{
		soluongmh = DemMonHoc(root);
		if(soluongmh == 0)
 		{
 			char c[50]="Chua co du lieu Mon Hoc";
 			GhiChu(c,35,27,74,500);
		}else{
			if(soluongmh < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((soluongmh-1)/15+1);
			}
		}
		MONHOC MH[soluongmh+1];
		MangTam_MonHoc(root,MH,dem); //Do Cay Nhi Phan ra Mang?
		BubbleSort_TenMH(MH,soluongmh);
		dem = 0; demdong = 0;
		TextColor(9);	system("cls");	Khung_Xuat_MH(); 
		for( int i = trang*15 ; i < 15 + trang*15 && i < soluongmh ; i++)
		{
			TextColor(7);
			gotoXY(6, 8+demdong); cout<< ( i+1 );
			gotoXY(10,8+demdong); cout<<MH[i].MAMH;
			gotoXY(23,8+demdong); cout<<MH[i].TENMH;
			gotoXY(79,8+demdong); cout<<MH[i].STCLT;
			gotoXY(87,8+demdong); cout<<MH[i].STCTH;
			demdong++;
		}
		HienThiTrang(trang+1,tongtrang,73,26);
		key = GetKey();
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)		{trang++;}
		if((key == LEFT || key == UP) && trang > 0)						{trang--;}
		if(key == INSERT)
		{	
			gotoXY(26,24);  TextColor(251);	printf("INSERT");	//T� m�u F1
			ThemMonHoc(root);
		}
		if(key == F2)
		{
			gotoXY(54,24);  TextColor(251);	printf("F2");	//T� m�u F2
			SuaMonHoc(root);
		}
		if(key == DELETE)
		{
			gotoXY(66,24);  TextColor(251);	printf("DELETE");	//T� m�u F3
			XoaMonHoc(root,dsltc);
		}
		if(key == ESC){
			putchar(7);	gotoXY(5,24);  TextColor(251);	printf("ESC"); //T� m�u ESC
			int temp = ThongBao_ESC();
			if(temp == 1)	{char c[50]= "Luu Vao File Thanh Cong!" ;GhiChu(c,35,27,74,2000);LuuFileMH(root);}										
			system("cls");	return;
		}
	}
}
void SuaMonHoc(PTRMH &root)
{
	int key, x = 35, y = 14, vitri = 0;
	Khung_Sua_MonHoc();
	PTRMH temppointer;
	MONHOC mh;	mh.MAMH[0] = '\0';	mh.TENMH[0] = '\0';	mh.STCLT = 0;	mh.STCTH = 0;
	char lt[3], th[3]; lt[0]='\0'; th[0]='\0';
	Khung_Sua_MonHoc();	gotoXY(x,y);
	while(1)
	{
		TextColor(3);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 10))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout<<mh.MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			mh.MAMH[vitri] = '\0';	//Ngat chuoi~
			if(check_MH(root,mh.MAMH)==1)
			{
				vitri = 0;
				temppointer = FindMaMH(root,mh.MAMH);	break;
			}else{
				char c[50]= "Ma Mon Hoc Khong Ton Tai!";GhiChu(c,35,27,78,500);	gotoXY(35+vitri,y);
			}
		}
		if(key == ESC || key == F2){return;}
	}
	Khung_Sua_MonHoc1(); 	
	x = 12, y = 16;		gotoXY(12,y); strcpy(mh.MAMH,temppointer->mh.MAMH);
TENMH:
	while(1)
	{
		TextColor(3); 
		gotoXY(12,16); cout << mh.MAMH;
		gotoXY(12,14); cout << temppointer->mh.MAMH;
		gotoXY(29,14); cout << temppointer->mh.TENMH;
		gotoXY(81,14); cout << temppointer->mh.STCLT;
		gotoXY(88,14); cout << temppointer->mh.STCTH;
		TextColor(244);	gotoXY(10,17); printf("Ki tu: (A-Z) & (0-9). Toi da: 50"); TextColor(3); gotoXY(29+vitri,y); //Ghi ch�
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 50))
		{
			mh.TENMH[vitri] = char(key);
			mh.TENMH[vitri] = toupper(mh.TENMH[vitri]);
			cout<<mh.TENMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(29+vitri, y);
			cout<<" ";
			gotoXY(29+vitri, y);
		}
		if( key == SPACE && mh.TENMH[vitri-1] != ' ' && vitri > 0 && vitri < 50) // ko cho 2 khoang trang && vitri = 0
		{	
			gotoXY(29+vitri , y);
			cout<<" ";
			mh.TENMH[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			if(mh.TENMH[vitri-1] == ' ')	 {vitri--;} //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TENMH[vitri] = '\0';
			vitri = 0;
			gotoXY(81+vitri, y);
			goto STCLT;
		}
		if(key == ESC || key == F2){return;}
	}
STCLT:
	while(1)
	{
		TextColor(3);
		gotoXY(12,16); cout << mh.MAMH;
		gotoXY(12,14); cout << temppointer->mh.MAMH;
		gotoXY(29,14); cout << temppointer->mh.TENMH;
		gotoXY(81,14); cout << temppointer->mh.STCLT;
		gotoXY(88,14); cout << temppointer->mh.STCTH;
		TextColor(244);	gotoXY(10,17); printf("Ki tu: (0-9). Toi da: 3         ");	TextColor(3); gotoXY(81+vitri,y); // Ghi ch�
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			lt[vitri] = char(key);
			cout<<lt[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(81+vitri, y);
			cout<<" ";
			gotoXY(81+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{	
			lt[vitri] = '\0';
			vitri = 0;
			mh.STCLT = atoi(lt);
			gotoXY(88+vitri, y);
			goto STCTH;
		}
		if(key == ESC || key == F2){return;}
	}
STCTH:
	while(1)
	{
		TextColor(3);
		gotoXY(12,16); cout << mh.MAMH;
		gotoXY(12,14); cout << temppointer->mh.MAMH;
		gotoXY(29,14); cout << temppointer->mh.TENMH;
		gotoXY(81,14); cout << temppointer->mh.STCLT;
		gotoXY(88,14); cout << temppointer->mh.STCTH;
		TextColor(244);	gotoXY(10,17); printf("Ki tu: (0-9). Toi da: 3         ");	TextColor(3); gotoXY(88+vitri,y); // Ghi ch�
		key = GetKey();
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			th[vitri] = char(key);
			cout<<th[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(88+vitri, y);
			cout<<" ";
			gotoXY(88+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			th[vitri] = '\0';
			mh.STCTH = atoi(th);
			temppointer->mh=mh;
			return;
		}
		if(key == ESC || key == F2){return;}
	}	
}
PTRMH FindMaMH(PTRMH &root, char c[])
{
	PTRMH p;
	p = root;
	while (p!=NULL && strcmp(c,p->mh.MAMH) != 0)
	{
		if (strcmp(c,p->mh.MAMH) < 0) p = p->left;
			else p = p->right;			
	}
	return p;
}
void XoaMonHoc(PTRMH &root, DSLOPTC dsltc)
{
	int key, x = 35, y = 14, vitri = 0;
	MONHOC mh;	mh.MAMH[0] = '\0';
	Khung_Xoa_MonHoc();	gotoXY(x,y);
Reset:
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout<<mh.MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			mh.MAMH[vitri] = '\0';	//Ngat chuoi~
			if(check_MH(root,mh.MAMH) == 1)
			{
				for(int i = 0; i < dsltc.soluong_ltc ; i++)
				{
					if(strcmp(mh.MAMH,dsltc.LOPTC[i]->MAMH)==0){
						char c[60]= "Mon Hoc da co trong danh sach Lop Tin Chi. Khong the Xoa!";
						GhiChu(c,20,27,78,500); 
						TextColor(3); gotoXY(35+vitri,y); 
						goto Reset;
					}
				}
				int check = ThongBao_Xoa();
				if(check == 1) {
					XoaNodeMonHoc(root,mh.MAMH);
					char c[50]= "Xoa Mon Hoc Thanh Cong!!!" ;GhiChu(c,35,27,78,500); TextColor(3);
				}
				return;
			}else{
				char c[50]= "Ma Mon Hoc Khong Ton Tai!" ;GhiChu(c,35,27,78,500); TextColor(3); gotoXY(35+vitri,y);
			}
		}
		if(key == ESC || key == DELETE){return;}
	}
}
void XoaNodeMonHoc(PTRMH &root, char c[])
{
	if(root == NULL)	{return;}
	if(strcmp(c,root->mh.MAMH) < 0)
	{
		XoaNodeMonHoc(root->left,c);
	}
	else if(strcmp(c,root->mh.MAMH) > 0)
	{
		XoaNodeMonHoc(root->right,c);
	}
	else{
		PTRMH p = root;		
		if(root->left == NULL && root->right == NULL)
		{
			delete p; return;
		}
		if(root->left == NULL && root->right != NULL)	
		{
			root = root->right;
		}
		else if(root->right == NULL && root->left != NULL) 
		{
			root = root->left;
		}
		else{
			PhanTuTheMang(p,root->right);
		}
		delete p;
	}
}
void PhanTuTheMang(PTRMH &x, PTRMH &y)
{
	if(y->left != NULL)
	{
		PhanTuTheMang(x, y->left);
	}
	else{
		x->mh = y->mh;				
		x = y;						
		y = y->right;			
	}
}

