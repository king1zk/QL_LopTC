#pragma once
#include <iostream>
#include <windows.h>
#include<stdio.h>	
#include<conio.h>
#include <iomanip>
#define DOWN -80
#define UP -72
#define LEFT -75
#define RIGHT -77
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define SPACE 32
#define F2 -60
#define F5 -63
#define INSERT -82
#define DELETE -83
using namespace std;

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoXY (int column, int line){	
	COORD coord; 	
	coord.X = column;  	
	coord.Y = line; 	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void TextColor (int color){	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
int GetKey(){	
	char key;key = getch();
	if(key==-32 || key==0)
	return -getch();
	else return key;
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void Khung_Nhap_Lop(){
	gotoXY(0,0);
	TextColor(90);
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");	
	printf("\n   |     |		      |					       |	       |");	
	printf("\n   |-----+--------------------+----------------------------------------+---------------|");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |    	       |");	
	printf("\n   | 	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |-----------------------------------------------------------------------------------|");	
	printf("\n   |                                            				       |");	
	printf("\n   +-----------------------------------------------------------------------------------+");	
	TextColor(236);	gotoXY(33,1);	printf("                              ");
	gotoXY(33,2);	
	printf("      NHAP DANH SACH LOP      ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(94);		gotoXY(5,6);    	printf("STT");	
	gotoXY(17,6);		printf("MA LOP");	
	gotoXY(48,6);		printf("TEN LOP");	
	gotoXY(75,6);		printf("NIEN KHOA");	
	gotoXY(4,24);		TextColor(252);		printf("ESC");	
	TextColor(91);		printf(": Exit");		
	gotoXY(20,24);		TextColor(252);		printf("ENTER");	
	TextColor(91);		printf(": OK");		
	gotoXY(36,24);		TextColor(252);		printf("CONTROL");	
	TextColor(91);		printf(": LEFT - RIGHT - UP - DOWN");	
	gotoXY(0,27); 
}
void Khung_Xuat_Lop(){
	gotoXY(0,0);
	TextColor(236);	
	gotoXY(33,1);	printf("                              ");
	gotoXY(33,2);	printf("      XUAT DANH SACH LOP      ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(9);
	printf("\n   +-------------------------------------------------------------------------------------------+");	
	printf("\n   | STT | MA LTC | MA MON HOC | NIEN KHOA | HOC KY | NHOM | SO SV MIN | SO SV MAX | TRANG THAI| ");	
	printf("\n   |-----+--------+----------- +-----------+--------+------+-----------+-----------+-----------|");	
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |     |        |            |           |        |      |           |           |           |");
	printf("\n   |-------------------------------------------------------------------------------------------|");	
	printf("\n   |     : ESC		: Insert		: Edit		: Delete		       |");	
	printf("\n   +-------------------------------------------------------------------------------------------+");	
	 
	TextColor(252);
	gotoXY(6,23); printf("ESC");	
	gotoXY(18,23); printf("Insert");	
	gotoXY(46,23); printf("F2");
	gotoXY(58,23); printf("Delete");	
	TextColor(252);	gotoXY(105,9); printf("^"); 
	gotoXY(101,11); printf("<"); 
	gotoXY(109,11); printf(">"); 
	gotoXY(105,13); printf("v");	
	gotoXY(100,15); printf("UP");
	gotoXY(100,17); printf("DOWN");
	gotoXY(100,19); printf("LEFT");
	gotoXY(100,21); printf("RIGHT");	
	TextColor(7);
	gotoXY(105,15);printf(": LEN");
	gotoXY(105,17); printf(": XUONG");
	gotoXY(105,19); printf(": TRAI");
	gotoXY(105,21); printf(": PHAI");
}
void Khung_Nhap_SV(){
	gotoXY(0,0);
	TextColor(90);	
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");	
	printf("\n   |     |		 |		      |          |	    |	               |");	
	printf("\n   |-----+---------------+--------------------+----------+----------+------------------|");	
	printf("\n   |	 |               |       	      |          |          |                  |");	
	printf("\n   |	 |         	 |		      |	         |	    |                  |");	
	printf("\n   | 	 |	         |		      |		 |	    |                  |");	
	printf("\n   |	 |	         |		      | 	 |          |                  |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |-----------------------------------------------------------------------------------|");	
	printf("\n   |                                                                                   |");	
	printf("\n   +-----------------------------------------------------------------------------------+");
	TextColor(236);	gotoXY(33,1);	printf("                              ");	
	gotoXY(33,2);	printf("   NHAP DANH SACH SINH VIEN   ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(12,6);	printf("MA SINH VIEN");	
	gotoXY(35,6);	printf("HO");	
	gotoXY(51,6);	printf("TEN");	
	gotoXY(61,6);	printf("PHAI");	
	gotoXY(72,6);	printf("SO DIEN THOAI");	
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(91);	printf(": OK");		
	gotoXY(36,24);	
	TextColor(252);	printf("CONTROL");	
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");	
	gotoXY(0,27);
}
void Khung_Xuat_SV(){
	gotoXY(0,0);
	TextColor(236);
	gotoXY(33,1);	printf("                              ");	
	gotoXY(33,2);	printf("   XUAT DANH SACH SINH VIEN   ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(9);	gotoXY(0,4);
	printf("\n   +-----------------------------------------------------------------------------------------------------+");	
	printf("\n   | STT | MA SINH VIEN |                HO                |   TEN    | PHAI |     SDT     |     LOP     |");	
	printf("\n   |-----+--------------+----------------------------------+----------+------+-------------+-------------+");	
	printf("\n   |	 |		|				   |	      |      |		   |		 |");	
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |	 |		|				   |	      |      |		   |		 |");
	printf("\n   |-----------------------------------------------------------------------------------------------------|");	
	printf("\n   |      : ECS               : INSERT                   : EDIT                  : DELETE                |");	
	printf("\n   +-----------------------------------------------------------------------------------------------------+");
	
	TextColor(252);
	gotoXY(7,24);		printf("ESC");	
	gotoXY(24,24);		printf("Insert");	
	gotoXY(55,24);	printf("F2");
	gotoXY(75,24);		printf("Delete");	
	gotoXY(120,9); printf("^"); 
	gotoXY(116,11); printf("<"); 
	gotoXY(124,11); printf(">"); 
	gotoXY(120,13); printf("v");	
	gotoXY(115,15);printf("UP");
	gotoXY(115,17);printf("DOWN");
	gotoXY(115,19);printf("LEFT");
	gotoXY(115,21);printf("RIGHT");	
	TextColor(91);gotoXY(120,15);printf(": LEN");
	gotoXY(120,17);printf(": XUONG");
	gotoXY(120,19);printf(": TRAI");
	gotoXY(120,21);printf(": PHAI");	
}

void Khung_Xuat_MH(){
	TextColor(9);
	gotoXY(0,4);	
	printf("\n   +---------------------------------------------------------------------------------------+");	
	printf("\n   | STT | MA MON HOC |			TEN MON HOC			   | STCLT | STCTH |");	
	printf("\n   |-----+------------+----------------------------------------------------+-------+-------|");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |	 |	      |							   |	   |	   |");	
	printf("\n   |---------------------------------------------------------------------------------------|");	
	printf("\n   |     : THOAT		: INSERT		: EDIT		: DELETE           |");	
	printf("\n   +---------------------------------------------------------------------------------------+");	
	TextColor(236);	
	gotoXY(33,1);	printf("                              ");	
	gotoXY(33,2);	printf("    XUAT DANH SACH MON HOC    ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(252);	
	gotoXY(5,24);	printf("ESC");		
	gotoXY(26,24);	printf("INSERT");		
	gotoXY(54,24);	printf("F2");			
	gotoXY(66,24);	printf("DELETE");	
	gotoXY(95,3);printf("UP");
	gotoXY(95,5);printf("DOWN");
	gotoXY(95,7);printf("LEFT");
	gotoXY(95,9);printf("RIGHT");	
	TextColor(7);
	gotoXY(100,3);printf(": LEN");
	gotoXY(100,5);printf(": XUONG");
	gotoXY(100,7);printf(": TRAI");
	gotoXY(100,9);printf(": PHAI");	
	gotoXY(0,27); 
}
void Khung_Nhap_Diem(){
	gotoXY(0,0);TextColor(90);
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------+");	
	printf("\n   |     |		 |		      |          |	    |      |");	
	printf("\n   |-----+---------------+--------------------+----------+----------+------|");	
	printf("\n   |	 |               |       	      |          |          |      |");	
	printf("\n   |	 |         	 |		      |	         |	    |      |");	
	printf("\n   | 	 |	         |		      |		 |	    |      |");	
	printf("\n   |	 |	         |		      | 	 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |-----------------------------------------------------------------------|");	
	printf("\n   |              		                         	  	   |");	
	printf("\n   +-----------------------------------------------------------------------+");		
	TextColor(236);	gotoXY(25,1);	printf("                              ");	
	gotoXY(25,2);	printf("      NHAP DANH SACH DIEM     ");		
	gotoXY(25,3);	printf("                              ");		
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(12,6);	printf("MA SINH VIEN");	
	gotoXY(35,6);	printf("HO");	
	gotoXY(50,6);	printf("TEN");	
	gotoXY(61,6);	printf("PHAI");	
	gotoXY(70,6);	printf("DIEM");		
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(91);	printf(": OK");		
	gotoXY(36,24);	TextColor(252);	printf("CONTROL");	
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");	
	gotoXY(0,27); 
}
void GhiChu(char c[], int x, int y, int color, int sleep)
{
	gotoXY(x,y);
	TextColor(color);
	printf("%s",c);
	Sleep(sleep);
	gotoXY(x,y);
	TextColor(0);
	printf("                                                                                    ");
}
int ThongBao_ESC(){
	int key,count = 0;
	TextColor(206);gotoXY(25,12);	
	printf("     Ban Co Muon Luu Vao File!   ");	
	gotoXY(25,13);	printf("   ");	
	gotoXY(55,13);	printf("   ");	
	gotoXY(25,14);	printf("   ");	
	gotoXY(55,14);	printf("   ");	
	gotoXY(25,15);	printf("   ");	
	gotoXY(55,15);	printf("   ");	
	gotoXY(25,16);	printf("                                 ");	
	TextColor(238);gotoXY(28,13); printf("                           ");	
	gotoXY(28,14); printf("                           ");	
	gotoXY(28,15); printf("                           ");	
	TextColor(252);	gotoXY(33,14);	printf(" YES ");	
	TextColor(233);	gotoXY(45,14);	printf(" NO ");	
	gotoXY(34,14);	
	while(1){		
		key = GetKey();	
		if(key == LEFT || key == RIGHT)	{			
			count++;			
			if(count % 2 == 1){					
				TextColor(233);		gotoXY(33,14); printf(" YES ");				
				TextColor(252);		gotoXY(45,14); printf(" NO ");				
				gotoXY(46,14);		
			}else{				
				TextColor(252);		gotoXY(33,14); printf(" YES ");				
				TextColor(233);		gotoXY(45,14); printf(" NO ");			
				gotoXY(34,14);		
			}		
		}		
		if(key == ENTER){			
			if(count == 0){				
				return 1;			
			}else{								
				if(count % 2 == 1){					
					return 0;				
				}else{					
					return 1;				
				}			
			}		
		}		
		if(key == ESC){			
			return -1;		
		}	
	}
}
int ThongBao_Thoat(){
	int key,count = 0;TextColor(206);
	gotoXY(25,12);	printf("  Ban Co Chac Chan Muon Thoat!   ");	
	gotoXY(25,13);	printf("   ");	gotoXY(55,13);	printf("   ");	
	gotoXY(25,14);	printf("   ");	gotoXY(55,14);	printf("   ");	
	gotoXY(25,15);	printf("   ");	gotoXY(55,15);	printf("   ");	
	gotoXY(25,16);	printf("                                 ");	
	TextColor(238);	gotoXY(28,13); printf("                           ");	
	gotoXY(28,14); printf("                           ");	
	gotoXY(28,15); printf("                           ");
	TextColor(252);	gotoXY(33,14);	printf(" YES ");	
	TextColor(233);	gotoXY(45,14);	printf(" NO ");	
	gotoXY(34,14);	
	while(1){		
		key = GetKey();		
		if(key == LEFT || key == RIGHT)	{
			count++;			
			if(count % 2 == 1){					
				TextColor(233);				
				gotoXY(33,14); printf(" YES ");				
				TextColor(252);				
				gotoXY(45,14); printf(" NO ");				
				gotoXY(46,14);			
			}else{				
				TextColor(252);			gotoXY(33,14); printf(" YES ");				
				TextColor(233);			gotoXY(45,14); printf(" NO ");				
				gotoXY(34,14);			
			}		
		}		
		if(key == ENTER){			
			if(count == 0){				
				return 1;			
			}else{								
				if(count % 2 == 1){	
					return 0;
				}else{					
					return 1;				
				}			
			}		
		}		
		if(key == ESC){			
			return -1;		
		}	
	}
}
int ThongBao_Xoa(){	
	int key,count = 0;TextColor(206);
	gotoXY(25,12);	printf("   Ban Co Chac Chan Muon Xoa!    ");	
	gotoXY(25,13);	printf("   ");	gotoXY(55,13);	printf("   ");	
	gotoXY(25,14);	printf("   ");	gotoXY(55,14);	printf("   ");	
	gotoXY(25,15);	printf("   ");	gotoXY(55,15);	printf("   ");	
	gotoXY(25,16);	printf("                                 ");	
	TextColor(238);	gotoXY(28,13); printf("                           ");	
	gotoXY(28,14); printf("                           ");	
	gotoXY(28,15); printf("                           ");
	TextColor(252);	gotoXY(33,14);	printf(" YES ");	
	TextColor(233);	gotoXY(45,14);	printf(" NO ");	
	gotoXY(34,14);	
	while(1){		
		key = GetKey();		
		if(key == LEFT || key == RIGHT)	{			
			count++;			
			if(count % 2 == 1){					
				TextColor(233);				gotoXY(33,14); printf(" YES ");				
				TextColor(252);				gotoXY(45,14); printf(" NO ");				
				gotoXY(46,14);			
			}else{				
				TextColor(252);				gotoXY(33,14); printf(" YES ");				
				TextColor(233);				gotoXY(45,14); printf(" NO ");				
				gotoXY(34,14);			
			}		
		}		
		if(key == ENTER){			
			if(count == 0){				
				return 1;			
			}else{								
				if(count % 2 == 1){					
					return 0;				
				}else{					
					return 1;				
				}			
			}		
		}		
		if(key == ESC || key == DELETE)	{			
			return -1;		
		}	
	}
}

void HienThiTrang(int trang, int tongtrang, int x, int y){
	TextColor(175);	gotoXY(x,y);printf(" Trang:        ");	
	gotoXY(x+8,y);printf("%d / %d",trang,tongtrang);	
	TextColor(3);
}
void Khung_Them_Lop(){
	TextColor(144);
	gotoXY(10,12); printf("                                    THEM LOP TIN CHI                                     ");
	TextColor(249);
	gotoXY(10,13); printf("  MA LTC      MA MON HOC     NIEN KHOA      HOC KY      NHOM     SO SV MIN     SO SV MAX ");	
	gotoXY(10,14); printf("                                                                                         ");	
	gotoXY(10,15); printf("                                                                                         ");	
	TextColor(244);	gotoXY(72,15); printf("Enter:"); 
	gotoXY(84,15);printf("ESC:");	
	TextColor(249);	gotoXY(79,15);printf("OK"); 
	gotoXY(89,15);printf("Exit");	
	TextColor(3);	
	gotoXY(12,14); printf ("      ");
	gotoXY(24,14); printf ("          ");
	gotoXY(39,14); printf ("         ");
	gotoXY(54,14); printf ("      ");
	gotoXY(66,14); printf ("    ");
	gotoXY(75,14); printf ("         ");
	gotoXY(89,14); printf ("         ");
}
void Khung_Them_MonHoc(){
	TextColor(144);
	gotoXY(10,12); printf("                                    THEM MON HOC                                     ");
	TextColor(249);
	gotoXY(10,13); printf("     MA MON HOC                         TEN MON HOC                    STCLT  STCTH  ");	
	gotoXY(10,14); printf("                                                                                     ");	
	gotoXY(10,15); printf("                                                                                     ");	
	TextColor(244);	gotoXY(72,15); printf("Enter:"); 
	gotoXY(84,15);printf("ESC:");	
	TextColor(249);	gotoXY(79,15);printf("OK"); 
	gotoXY(89,15);printf("Exit");	
	TextColor(3);	
	gotoXY(12,14);printf("               ");	
	gotoXY(29,14);printf("                                                  ");	
	gotoXY(81,14);printf("     ");	
	gotoXY(88,14);printf("     ");
}
void Khung_Them_SV(){
	TextColor(144);
	gotoXY(10,12); printf("                                    THEM SINH VIEN                                    ");
	TextColor(249);
	gotoXY(10,13); printf("   MA SINH VIEN              HO              TEN     PHAI     SDT         LOP         ");	
	gotoXY(10,14); printf("                                                                                      ");
	gotoXY(10,15); printf("                                                                                      ");
	
	TextColor(244);	gotoXY(72,15); printf("Enter:"); 
	gotoXY(84,15);printf("ESC:");	
	TextColor(249);	gotoXY(79,15);printf("OK"); 
	gotoXY(89,15);printf("Exit");	
	TextColor(3);	
	gotoXY(12,14);printf("               ");	
	gotoXY(29,14); printf("                    ");	
	gotoXY(51,14); printf("          ");	
	gotoXY(63,14);printf("    ");	
	gotoXY(68,14);printf("           ");
	gotoXY(80,14);printf ("               ");
}
void Khung_Sua_Lop(){
	TextColor(144);
	gotoXY(10,12); printf("                                    SUA LOP TIN CHI                                      ");
	TextColor(249);
	gotoXY(10,13); printf("  MA LTC      MA MON HOC     NIEN KHOA      HOC KY      NHOM     SO SV MIN     SO SV MAX ");	
	gotoXY(10,14); printf("                                                                                         ");	
	gotoXY(10,15); printf("                                                                                         ");	
    gotoXY(10,16); printf("                                                                                         ");	
	gotoXY(10,17); printf("                                                                                         ");	
    TextColor(244);	
    gotoXY(76,17); printf("Enter:"); 
	gotoXY(90,17);printf("ESC:");	
	TextColor(249);	
    gotoXY(83,17);printf("OK"); 
	gotoXY(93,17);printf("Exit");	
	TextColor(3);	
	gotoXY(12,14); printf ("      ");
	gotoXY(24,14); printf ("          ");
	gotoXY(39,14); printf ("         ");
	gotoXY(54,14); printf ("      ");
	gotoXY(66,14); printf ("    ");
	gotoXY(75,14); printf ("         ");
	gotoXY(89,14); printf ("         ");	
	gotoXY(12,16); printf ("      ");
	gotoXY(24,16); printf ("          ");
	gotoXY(39,16); printf ("         ");
	gotoXY(54,16); printf ("      ");
	gotoXY(66,16); printf ("    ");
	gotoXY(75,16); printf ("         ");
	gotoXY(89,16); printf ("         ");
	
}
void Khung_Sua_Lop1(){
	TextColor(144);
	gotoXY(10,12); printf("         NHAP MA LOP TIN CHI CAN CHINH SUA         ");
	TextColor(249);
	gotoXY(10,13); printf("              MA LTC                               ");	
	gotoXY(10,14); printf("                                                   ");	
	TextColor(3); 
	gotoXY(32,13); printf ("           ");
    TextColor(244);	
	gotoXY(36,14); printf("Enter:"); 
	gotoXY(50,14);printf("ESC:");	
	TextColor(249);	
    gotoXY(43,14);printf("OK"); 
	gotoXY(55,14);printf("Exit");	
}
void Khung_Sua_SV(){
	TextColor(111);	gotoXY(30,13);printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(30,13); printf("Nhap Ma Sinh Vien Can Sua");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Sua_MonHoc(){
	TextColor(249);
	gotoXY(30,13); printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(144);gotoXY(30,13); printf(" Nhap Ma Mon Hoc Can Sua ");		
	TextColor(244);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(249);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(3);	gotoXY(35,14);printf("               ");
}
void Khung_Sua_MonHoc1(){
	TextColor(144);
	gotoXY(10,12); printf("                                    SUA MON HOC                                     ");
	TextColor(249);
	gotoXY(10,13); printf("     MA MON HOC                         TEN MON HOC                    STCLT  STCTH  ");	
	gotoXY(10,14); printf("                                                                                     ");	
	gotoXY(10,15); printf("                                                                                     ");	
    gotoXY(10,16); printf("                                                                                     ");	
	gotoXY(10,17); printf("                                                                                     ");	
    TextColor(244);	
    gotoXY(72,17); printf("Enter:"); 
	gotoXY(84,17);printf("ESC:");	
	TextColor(249);	
    gotoXY(79,17);printf("OK"); 
	gotoXY(89,17);printf("Exit");	
	TextColor(3);	
	gotoXY(12,14);printf("               ");	
	gotoXY(29,14);printf("                                                  ");	
	gotoXY(81,14);printf("     ");	
	gotoXY(88,14);printf("     ");
    TextColor(3);	
	gotoXY(12,16);printf("               ");	
	gotoXY(29,16);printf("                                                  ");	
	gotoXY(81,16);printf("     ");	
	gotoXY(88,16);printf("     ");
}
void Khung_Nhap_MaSV(){
	TextColor(158);	
	gotoXY(23,8);printf("                                      ");	
	gotoXY(23,9);printf("  NHAP MA SINH VIEN DE XEM THONG TIN  ");	
	gotoXY(23,10);printf("                                      ");
	TextColor(111);
	gotoXY(30,13); printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(30,13); printf("    Nhap Ma Sinh Vien  ");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Nhap_MaLop_MonHoc(){	
	TextColor(173);gotoXY(28,2); printf("                                              ");	
	gotoXY(28,3); printf("                                              ");	
	gotoXY(28,4); printf("                                              ");	
	gotoXY(28,1); printf("                                              ");	
	TextColor(202);	gotoXY(28,0); printf("--------------------******--------------------");	
	TextColor(299);gotoXY(28,1); printf("    NHAP MA LOP       NHAP MA MON HOC     LAN ");	
	TextColor(169);gotoXY(35,3); printf("Enter:"); 
	gotoXY(59,3);printf("ESC:");
	gotoXY(55,4);	TextColor(172);gotoXY(42,3);printf("OK"); 
	gotoXY(64,3);printf("Exit");	
	TextColor(12);	gotoXY(30,2);printf("               ");
	gotoXY(50,2);printf("               ");
	gotoXY(71,2);printf(" ");	TextColor(91);
}
void Khung_Xoa_SV(){
	TextColor(111);	gotoXY(30,13); printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(30,13); printf("Nhap Ma Sinh Vien Can Xoa");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Xoa_MonHoc(){
	TextColor(249);
	gotoXY(30,13); printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(144);gotoXY(30,13); printf(" Nhap Ma Mon Hoc Can Xoa ");		
	TextColor(249);
	gotoXY(31,15);printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(244);
	gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(3); gotoXY(35,14);printf("               ");
}
void Khung_Xoa_Lop(){
	TextColor(144);
	gotoXY(10,12); printf("            NHAP MA LOP TIN CHI CAN XOA            ");
	TextColor(249);
	gotoXY(10,13); printf("              MA LTC                               ");	
	gotoXY(10,14); printf("                                                   ");	
	TextColor(3); 
	gotoXY(32,13); printf ("           ");
    TextColor(244);	
	gotoXY(36,14); printf("Enter:"); 
	gotoXY(50,14);printf("ESC:");	
	TextColor(249);	
    gotoXY(43,14);printf("OK"); 
	gotoXY(55,14);printf("Exit");	
}
void Khung_Xuat_NK(){
	TextColor(158);	gotoXY(23,8);printf("                                     ");	
	gotoXY(23,9);printf("  XUAT DANH SACH LOP THEO NIEN KHOA  ");	
	gotoXY(23,10);printf("                                     ");
	TextColor(111);gotoXY(30,13);printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(36,13); printf("Nhap Nien Khoa");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(41,14);printf("    ");
}
void Khung_Nhap_MaLop(){
	TextColor(173);gotoXY(33,2);printf("                              ");	
	gotoXY(33,3); printf("                              ");	
	gotoXY(33,4); printf("                              ");	
	gotoXY(33,1); printf("                              ");	
	TextColor(202);	gotoXY(33,0); printf("------------������------------");	
	TextColor(192);	TextColor(299);gotoXY(33,1); printf("          NHAP MA LOP         ");		
	TextColor(169);gotoXY(36,3); printf("Enter:"); 
	gotoXY(50,3);printf("ESC:");
	gotoXY(38,4);printf("F5:");	
	TextColor(172);gotoXY(43,3);printf("OK"); 
	gotoXY(55,3);printf("Exit");
	gotoXY(42,4);printf("XEM DANH SACH LOP");	
	TextColor(12);	gotoXY(40,2);printf("               ");
	}
void ThongTinChung(){
	TextColor(225);gotoXY(35,1);printf("                                                  ");	
	gotoXY(35,2); printf("          CHUONG TRINH QUAN LY SINH VIEN          ");	
	gotoXY(35,3); printf("                                                  ");	
	TextColor(158);	gotoXY(35,0); printf("   NHOM 85: LENH HA BAO LONG - MSSV: N18DCAT043   ");	
	gotoXY(35,4); printf("                                                  ");	
	gotoXY(35,4); printf("   NHOM 85: LE MANH CUONG    - MSSV: N18DCAT009   ");
	gotoXY(35,1);printf("  ");gotoXY(83,1);printf("  ");	
	gotoXY(35,2);printf("  ");gotoXY(83,2);printf("  ");
	gotoXY(35,3);printf("  ");gotoXY(83,3);printf("  ");	
	TextColor(0);
}
void Khung_NhapSVDK(){
	TextColor(144);
	gotoXY(40,1); printf ("          NHAP THONG TIN DE TIEN HANH DANG KI         ");
	TextColor(249);
	gotoXY(40,2); printf ("      MA SO SINH VIEN      NIEN KHOA      HOC KY      ");
	gotoXY(40,3); printf ("                                                      ");
	gotoXY(40,4); printf ("                                                      ");
	TextColor(244);	gotoXY(75,4); printf("Enter: "); 
	gotoXY(85,4);printf("ESC: ");	
	TextColor(249);	gotoXY(81,4);printf("OK"); 
	gotoXY(89,4);printf("Exit");
	TextColor(3);
	gotoXY(46,3); printf ("               ");
	gotoXY(67,3); printf ("         ");
	gotoXY(82,3); printf ("      ");
}
void Khung_DSDKLTC(){
	TextColor(236);	
	gotoXY(50,1); printf("                                    ");	
	gotoXY(50,2); printf("        DANG KY LOP TIN CHI         ");		
	gotoXY(50,3); printf("                                    ");
	TextColor(9); gotoXY(0,7);
	printf ("\n   +------------------------------------------------------------------------------------------------------------------------------------+");
	printf ("\n   | STT | MA LOP | MA MON HOC |			TEN MON HOC		    | NHOM | SL SVDK | SL TRONG ||     LOP DA DANG KY   |");
	printf ("\n   +-----+--------+------------+----------------------------------------------------+------+---------+----------++----------------------+");
	printf ("\n   |	 |	  |	       |						    |      |	     |		|| STT | MA LOP TIN CHI |");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||----------------------|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |	 |	  |	       |						    |      |	     |		||     |		|");
	printf ("\n   |------------------------------------------------------------------------------------------------------------||----------------------|");
	printf ("\n   |    : Exit				      				: Dang KY LTC				||       : DELETE       |");
	printf ("\n   +------------------------------------------------------------------------------------------------------------------------------------+");
	TextColor(252);
	gotoXY(5,27); printf ("ESC");
	gotoXY(115,27); printf ("Delete");
	gotoXY(66,27); printf ("Insert");
}
void Khung_DKLTC(){
	TextColor(144);
	gotoXY(97,1); printf ("   NHAP MA LOP TIN CHI MUON DANG KY    ");
	TextColor(249);
	gotoXY(97,2); printf ("                                       ");
	gotoXY(97,3); printf ("     MA LTC                            ");
	gotoXY(97,4); printf ("                                       ");
	gotoXY(97,5); printf ("                        OK        Exit ");
	TextColor(3) ; gotoXY(110,3); printf ("                     ");
	TextColor(244);
	gotoXY(114,5); printf ("Enter:");
	gotoXY(126,5); printf ("Esc:");
}
void Khung_Xoa_DKLTC(){
	TextColor(144);
	gotoXY(97,1); printf (" NHAP MA LOP TIN CHI MUON HUY DANG KY  ");
	TextColor(249);
	gotoXY(97,2); printf ("                                       ");
	gotoXY(97,3); printf ("     MA LTC                            ");
	gotoXY(97,4); printf ("                                       ");
	gotoXY(97,5); printf ("                        OK        Exit ");
	TextColor(3) ; gotoXY(110,3); printf ("                     ");
	TextColor(244);
	gotoXY(114,5); printf ("Enter:");
	gotoXY(126,5); printf ("Esc:");
}
void KhungNhap_NK_HK_N_MH(){
	TextColor(144);
	gotoXY(40,1); printf ("          NHAP THONG TIN LOP TIN CHI CAN XEM DIEM           ");
	TextColor(249);
	gotoXY(40,2); printf ("      NIEN KHOA       HOC KY       NHOM      MON HOC        ");
	gotoXY(40,3); printf ("                                                            ");
	gotoXY(40,4); printf ("                                                            ");
	TextColor(244);	gotoXY(80,4); printf("Enter: "); 
	gotoXY(91,4);printf("ESC: ");	
	TextColor(249);	gotoXY(86,4);printf("OK"); 
	gotoXY(95,4);printf("Exit");
	TextColor(3);
	gotoXY(46,3); printf ("         ");
	gotoXY(62,3); printf ("      ");
	gotoXY(75,3); printf ("    ");
	gotoXY(84,3); printf ("          ");
}
void Khung_Xuat_Diem(){	
	TextColor(236);	
	gotoXY(25,1);	printf("                 BANG DIEM MON HOC                 ");		
	gotoXY(25,2);	printf("                                                   ");
	gotoXY(25,3);	printf("     NIEN KHOA:             HOC KY:      NHOM:     ");
	TextColor(9);
	gotoXY(0,5);
	printf("\n   +-------------------------------------------------------------------------------------------+");	
	printf("\n   | STT |	MSSV	|			HO			   |   TEN    |  DIEM  |");	
	printf("\n   |-----+--------------+--------------------------------------------------+----------+--------|");	
	printf("\n   |	 |		|						   |	      |	       |");	
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |	 |		|						   |	      |	       |");
	printf("\n   |-------------------------------------------------------------------------------------------|");	
	printf("\n   |         : Exit                : OK                       : LEFT - RIGHT - UP - DOWN       |");	
	printf("\n   +-------------------------------------------------------------------------------------------+");	
	TextColor(252);
	gotoXY(10,25); printf ("ESC");
	gotoXY(30,25); printf ("ENTER");
	gotoXY(55,25); printf ("CONTROL");
}
void Khung_Nhap_NK_HK(){
	TextColor(144);
	gotoXY(40,1); printf ("               NHAP NIEN KHOA - HOC KY                ");
	TextColor(249);
	gotoXY(40,2); printf ("           NIEN KHOA                 HOC KY           ");
	gotoXY(40,3); printf ("                                                      ");
	gotoXY(40,4); printf ("                                                      ");
	TextColor(244);	gotoXY(75,4); printf("Enter: "); 
	gotoXY(85,4);printf("ESC: ");	
	TextColor(249);	gotoXY(81,4);printf("OK"); 
	gotoXY(89,4);printf("Exit");
	TextColor(3);
	gotoXY(51,3); printf ("         ");
	gotoXY(77,3); printf ("      ");
}
void Khung_HuyLTC(){
	TextColor(236);	
	gotoXY(30,2); printf("                                    ");	
	gotoXY(30,1); printf("          HUY LOP TIN CHI           ");		
	gotoXY(30,3); printf("  NIEN KHOA:             HOC KY:    ");
	TextColor(9); gotoXY(0,4);
	printf ("\n   +----------------------------------------------------------------------------------------------------------+");
	printf ("\n   | STT | MA LOP | MA MON HOC |			TEN MON HOC		    | NHOM | SL SVDK | SL MIN |");
	printf ("\n   |-----+--------+------------+----------------------------------------------------+------+---------+--------|");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |	 |	  |	       |						    |      |	     |	      |");
	printf ("\n   |-----+--------+------------+----------------------------------------------------+------+---------+--------|");
	printf ("\n   |    : Exit						: Huy Lop Tin Chi				      |");
	printf ("\n   +----------------------------------------------------------------------------------------------------------+");
	TextColor(252);
	gotoXY(5,24); printf ("ESC");
	gotoXY(50,24); printf ("Delete");
}

void Khung_HuyLTC1(){
	TextColor(144);
	gotoXY(97,1); printf ("     NHAP MA LOP TIN CHI MUON HUY      ");
	TextColor(249);
	gotoXY(97,2); printf ("                                       ");
	gotoXY(97,3); printf ("     MA LTC                            ");
	gotoXY(97,4); printf ("                                       ");
	gotoXY(97,5); printf ("                        OK        Exit ");
	TextColor(3) ; gotoXY(110,3); printf ("                     ");
	TextColor(244);
	gotoXY(114,5); printf ("Enter:");
	gotoXY(126,5); printf ("Esc:");
}