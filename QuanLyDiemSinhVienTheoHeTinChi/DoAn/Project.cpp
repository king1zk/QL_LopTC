#include <iostream>
#include "Frame.h"
#include <string.h>
#include "khaibao_Struct.h"
#include "monhoc.h"
#include "loptc.h"
#include "sinhvien.h"
using namespace std;

void ToMauMenuChinh(int color,char MENU[][30],int vitri){
	TextColor(color);
	gotoXY(45,6+vitri*4); cout<<"                             ";
	gotoXY(45,7+vitri*4); cout<<MENU[vitri];
	gotoXY(45,8+vitri*4); cout<<"                             ";
}
//MENU
char MENU[5][30] = {"  1.Quan Ly Lop Tin Chi      ","  2.Quan Ly Mon Hoc          " ,"  3.Quan Ly Sinh Vien        ","  4.Quan Ly Dang Ky          ", "  5.Thoat                    "};
char MENUlop[5][30] = {"  1.Xem Danh Sach Lop Tin Chi","  2. Huy Lop Tin Chi         ","  3.Xem Diem Lop Tin Chi     ","  4.Nhap Diem                ", "  5.Thoat                    "};
char MENUsv[1][30] = {"  1.Xem Danh Sach SV         "};
char MENUmonhoc[2][30] = {"  1.Xem Danh Sach Mon Hoc    ","  2.Thoat                    "};
char MENUdk[2][30] = {"  1.Dang Ky Lop Tin Chi      ","  2.Thoat                    "};

int MenuCha(){
	int vitri = 0;
	while ( 1 )
	{
		ThongTinChung();
		int key = GetKey();
		if ( key == ENTER ) // vitri!= 4 la ngay tai o Thoï¿½t
		{return vitri + 1 ;}
		switch(key)
			{
			case DOWN :
				{
					if ( vitri ==  4  )
					{
					     ToMauMenuChinh(188,MENU,vitri);
				    	 vitri = 0 ;
					     ToMauMenuChinh(236,MENU,vitri);
					}
					else
					{
						ToMauMenuChinh(188,MENU,vitri);
						vitri++;
						ToMauMenuChinh(236,MENU,vitri);
					}
				}break;
			case UP :
				{
				if ( vitri == 0 )
					{
						ToMauMenuChinh(188,MENU,vitri);
						vitri = ( 5 -1 ) ;
						ToMauMenuChinh(236,MENU,vitri);
					}
					else
					{
						ToMauMenuChinh(188,MENU,vitri);
						vitri--;
						ToMauMenuChinh(236,MENU,vitri);
					}
				}break;
			}
	}
}
int MenuCon(int item, char MENUCON[][30]){
	int key;
	int vitri = 0;
	while ( 1 )
	{
		ThongTinChung();
		key = GetKey();
		if ( key == ENTER)
			return vitri + 1;
		if ( key == ESC || key == LEFT)
			return 0;
		switch ( key )
		{
		case DOWN:
			{
				if ( vitri == (item -1) ) 
				{
					ToMauMenuChinh(188,MENUCON,vitri);
					vitri = 0 ;
					ToMauMenuChinh(236,MENUCON,vitri);
				}
				else
				{
					ToMauMenuChinh(188,MENUCON,vitri);
					vitri++;
					ToMauMenuChinh(236,MENUCON,vitri);
				}
			}break;
		case UP:
			{
				if ( vitri == 0 ) 
				{
					ToMauMenuChinh(188,MENUCON,vitri);
					vitri = item -1  ;
					ToMauMenuChinh(236,MENUCON,vitri);
				}
				else
				{
					ToMauMenuChinh(188,MENUCON,vitri);
					vitri--;
					ToMauMenuChinh(236,MENUCON,vitri);
				}
			}break;
		}	
	}
}
void MenuOngNoi(PTRMH &root, DSLOPTC &dsltc, DSSV &dsSV){
	int chonMenuCon;
	while(1) 
	{
		SetBGColor(0);
		system("cls");
		for(int i = 0; i < 5; i++)
		{
			if(i == 0)	{TextColor(236);}				
			else {TextColor(188);}
			gotoXY(45,6+i*4); cout<<"                             ";
			gotoXY(45,7+i*4); cout<<MENU[i];
			gotoXY(45,8+i*4); cout<<"                             ";
		}
		int chon = MenuCha();
		switch(chon){
			case 1:
			{
				system("cls");
				for(int i = 0; i < 5; i++)
				{
					if(i == 0)	{TextColor(236);}				
					else {TextColor(188);}
					gotoXY(45,6+i*4); cout<<"                             ";
					gotoXY(45,7+i*4); cout<<MENUlop[i];
					gotoXY(45,8+i*4); cout<<"                             ";
				}
				chonMenuCon = MenuCon(5, MENUlop);
				TextColor(0);
				
				switch ( chonMenuCon )
				{
					case 1: 	{	XuatLop(dsltc,root); break;}
					case 2:		{	HuyLopTinChi(dsltc, root);	break;			}
					case 3:		{	Nhap_NK_HK_Nhom_MH(dsltc,dsSV,root,2);break;			}
					case 4: 	{	Nhap_NK_HK_Nhom_MH(dsltc,dsSV,root,1); break; }
					case 5:		{	break;		}
				}
				 break;
			}
			case 2:
			{
				system("cls");
				for(int i = 0; i < 2; i++)
				{
					if(i == 0)	{TextColor(236);}				
					else {TextColor(188);}
					gotoXY(45,6+i*4); cout<<"                             ";
					gotoXY(45,7+i*4); cout<<MENUmonhoc[i];
					gotoXY(45,8+i*4); cout<<"                             ";
				}
				chonMenuCon = MenuCon(2, MENUmonhoc);
				TextColor(0);
				
				 switch ( chonMenuCon )
				 {
				 	case 1:		{	XuatMonHoc(root, dsltc);	break;			}
					case 2: break;
				 }
				break;
			}
			case 3:
			{
				system("cls");
				for(int i = 0; i < 1; i++) 
				{
					if(i == 0)	{TextColor(236);}				
					else {TextColor(188);}
					gotoXY(45,6+i*4); cout<<"                             ";
					gotoXY(45,7+i*4); cout<<MENUsv[i];
					gotoXY(45,8+i*4); cout<<"                             ";
				}
				chonMenuCon = MenuCon(1, MENUsv);
				TextColor(0);
				
				switch ( chonMenuCon )
				{
					case 1:		{	XuatSV(dsSV,root);	break;			}
					
				}
				break;
			}
			case 4:
			{
				system("cls");
				for(int i = 0; i < 2; i++)
				{
					if(i == 0)	{TextColor(236);}				
					else {TextColor(188);}
					gotoXY(45,6+i*4); cout<<"                             ";
					gotoXY(45,7+i*4); cout<<MENUdk[i];
					gotoXY(45,8+i*4); cout<<"                             ";
				}
				chonMenuCon = MenuCon(2, MENUdk);
				TextColor(0);
				
				switch ( chonMenuCon )
				{
					case 1:		{	SV_DangKyLTC(dsSV,dsltc, root); break;			}
					case 2: break;
				}
				break;
			}
			case 5:
				{
					GiaiPhongMangTamLTC(dsltc);
					GiaiPhongMonHoc(root);
					exit(0);
				}
		}
		
	}
}

int main()
{
	resizeConsole(1080,550);
	DSSV dsSV; dsSV.soluong_SV=0;
	PTRMH root = NULL;
	DSLOPTC dsltc; dsltc.soluong_ltc = 0;
	DocFileMH(root);
	DocFileLopTC(dsltc);
	DocFileSV(dsSV);
	MenuOngNoi(root, dsltc, dsSV);	
	return 0;
}
