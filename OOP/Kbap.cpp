	/* If you are compiling this code command line, be sure to
	   use the "-ml" parameter (large memory model).
	   Otherwise, the program will compile and link, but will
	   lock up your system. */

	#include <conio.h>			   // clrscr(), getch(), kbhit()
	#include <dos.h>  			   // MK_FP, geninterrupt()
	#include <iostream>   	   // cout
	#include <stdio.h>			   // fopen(), fread(), fclose(), FILE
	#include <graphics.h>
	#include <time.h
	#include <string.h>
	#include <stdlib.h>			   // calloc(), free(), exit()

	const XSize = 16;        // the width  of our font
	const YSize = 16;        // the height of our font
	const NumLetters = 62;   // the number of characters in our font
	int ques_no=1;           //for score
	int q_done;
	int life_50_50=0;
	int life_poll=0;
	int life_ask=0;
	int x,y;
	FILE *fp,*fd;
	// MODE SETTING FUNCTIONS
	void SetMCGA();
	void SetText();

	// UTILITY FUNCTIONS
	void Pal(unsigned char ColorNo,unsigned char R,unsigned char G,unsigned char B);
	void LoadPal(char *FileName);
	void Putpixel(int x, int y, unsigned char Col, unsigned char *Where);
	void WaitRetrace();
	int  Exist(char *FileName);

	// MID-LEVEL FUNCTIONS
	void Setup(int a);
	void ScrollMsg (char *Msg, int SizeMsg,int yaxis);

	typedef unsigned char Letter[XSize][YSize];

	// GLOBAL VARIABLE DECLARATIONS
	// pointer to the offset of the VGA memory
	unsigned char *vga = (unsigned char *) MK_FP(0xA000, 0);

	// pointer to our index of font data
	Letter *Font;

	//global structure of the quiz Q & A and options
	struct qna
	{
		char q[200];
		char a1[50];
		char a2[50];
		char a3[50];
		char a4[50];
		int c;
	}qa;

	// Play Game functions
	void game();
	void start();
	void read_q();
	void check();
	void show_q();
	void help(int help_code);

	void main()
	{

		int gd=DETECT,gm,errorcode;
		clrscr();
		cout<< "This game requires the files \"SOFTROCK.FNT\""
			<<" , \"PALLETTE.COL\" and \"QUIZ.DAT\"\nto"
			<< " be in the current directory\n\n"
			<< "All 3 files \"SOFTROCK.FNT\" , \"PALLETTE.COL\" and \"QUIZ.DAT\" come with the GAME.\n\n";
		Setup(1);
		printf("\t\t\t   Version 1.21");
		delay(2000);
		ScrollMsg ("KAUN        ",12,50);
		ScrollMsg ("BANEGA       ",13,100);
		ScrollMsg ("ARAB-PATI     ",14,150);
		delay(5000);
		SetText();
		free(Font);
		initgraph(&gd,&gm,".");
		errorcode = graphresult();
		if (errorcode != grOk)  // an error occurred
		{
			printf("Graphics error: %s\n", grapherrormsg(errorcode));
			printf("Press any key to halt:");
			getch();
			fclose(fd);
			remove("DATA2.DAT");
			fd=fopen("DATA2.DAT","wb+");
			fwrite(&q_done,sizeof(q_done),1,fd);
			fclose(fd);
			exit(1);             // return with error code
		}
		delay(1000);
		setcolor(CYAN);
		ellipse(getmaxx()/2,getmaxy()/2,0,360,200,70);
		setcolor(DARKGRAY);
		outtextxy(250,190,"Copyright (C) 2000");
		setcolor(DARKGRAY);
		moveto(210,235);
		outtext("For any querries contact me : ");
		setcolor(LIGHTRED);
		moveto(235,247);
		outtext("help@jayantgandhi.com");
		setcolor(DARKGRAY);
		moveto(200,262);
		outtext("Visit ME : ");
		setcolor(LIGHTRED);
		outtext("www.jayantgandhi.com");
		setcolor(YELLOW);
		moveto(255,205);
		delay(2000);
		outtext("J"); delay(400); outtext("a"); delay(400);
		outtext("y"); delay(400); outtext("a"); delay(400);
		outtext("n"); delay(400); outtext("t"); delay(400);
		outtext("G"); delay(400); outtext("a"); delay(400);
		outtext("n"); delay(400); outtext("d"); delay(400);
		outtext("h"); delay(400); outtext("i"); delay(400);
		outtext("."); delay(400); outtext("c"); delay(400);
		outtext("o"); delay(400); outtext("m"); delay(4000);
		fflush(stdin);
//		getch();
		closegraph();
		check();
		game();
		Setup(0);
//		ScrollMsg ("ARE YOU SURE ???",16,100);
		fflush(stdin);
//		getch();
		rewind(fd);
		fwrite(&q_done,sizeof(q_done),1,fd);
		fclose(fp);
		fclose(fd);
		SetText();
		free(Font);
		fclose(fd);
		remove("DATA2.DAT");
		fd=fopen("DATA2.DAT","wb+");
		fwrite(&q_done,sizeof(q_done),1,fd);
		fclose(fd);
		cout<< "Hit any key to exit ...";
		fflush(stdin);
		getch();
	}

	void check()
	{
		int num_rec=0;
		q_done=0;
		fd=fopen("DATA2.DAT","rb+");
		if(fd==NULL)
		{
			fd=fopen("DATA2.DAT","wb+");
			if(fd==NULL)
			{
				puts("Cannot open file DATA2.DAT");
				q_done=0;
				getch();
				fclose(fd);
				remove("DATA2.DAT");
				fd=fopen("DATA2.DAT","wb+");
				fwrite(&q_done,sizeof(q_done),1,fd);
				fclose(fd);
				exit(0);
			}
		}
		else
		{
			rewind(fd);
			fread(&q_done,sizeof(q_done),1,fd);
		}
		fp=fopen("DATA.DAT","rb");
		if(fp==NULL)
		{
			puts("Cannot open file DATA.DAT");
			fclose(fd);
			remove("DATA2.DAT");
			fd=fopen("DATA2.DAT","wb+");
			fwrite(&q_done,sizeof(q_done),1,fd);
			fclose(fd);
			exit(0);
		}
		while(fread(&qa,sizeof(qa),1,fp)==1)
			num_rec++;
		if(q_done>=num_rec)
			q_done=0;
		rewind(fp);
		fread(&qa,sizeof(qa),q_done,fp);
	}

	//play game funtion
	void start()
	{
		int poly_a1[14]={51,350,301,350,311,380,301,410,51,410,41,380,51,350};
		int poly_a2[14]={10+302+30+20 ,0+350 ,290+302+30 ,0+350 ,300+302+30 ,30+350 ,290+302+30 ,60+350 ,10+302+30+20 ,60+350 ,0+302+30+20 ,30+350 ,10+302+30+20 ,0+350};
		int poly_a3[14]={10+6+30+5   ,0+412 ,290+6+5   ,0+412 ,300+6+5   ,30+412 ,290+6+5   ,60+412 ,10+6+30+5   ,60+412 ,0+6+30+5   ,30+412 ,10+6+30+5   ,0+412};
		int poly_a4[14]={10+302+30+20 ,0+412 ,290+302+30 ,0+412 ,300+302+30 ,30+412 ,290+302+30 ,60+412 ,10+302+30+20 ,60+412 ,0+302+30+20 ,30+412 ,10+30+302+20 ,0+412};
		int fix_poly1[8]={426,(4-1)*21+30,633,(4-1)*21+30,633,(4-1)*21+48,426,(4-1)*21+48};
		int fix_poly2[8]={426,(9-1)*21+30,633,(9-1)*21+30,633,(9-1)*21+48,426,(9-1)*21+48};
		int q_poly[8]={426,(15-ques_no)*21+30,633,(15-ques_no)*21+30,633,(15-ques_no)*21+48,426,(15-ques_no)*21+48};
		int i;
		char *ch;
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		cleardevice();
		fflush(stdin);
		setcolor(BROWN);
		rectangle(0,0,getmaxx(),getmaxy());
		rectangle(2,2,getmaxx()-2,getmaxy()-2);
		rectangle(424,4,getmaxx()-4,350-4);
		rectangle(4,4,422,350-4);
		rectangle(4,350-2,getmaxx()-4,getmaxy()-4);
		setcolor(YELLOW);
		drawpoly(7,poly_a1);
		drawpoly(7,poly_a2);
		drawpoly(7,poly_a3);
		drawpoly(7,poly_a4);
		settextstyle(0,0,2);
		settextjustify(LEFT_TEXT,CENTER_TEXT);
		setcolor(BROWN);
		outtextxy(11,380,"");
		outtextxy(11,442,"");
		outtextxy(327,380,"");
		outtextxy(327,442,"");
		setcolor(LIGHTGREEN);
		outtextxy(x,y,"");
		setcolor(WHITE);
		line(424+70,4,424+70,31);
		line(424+140,4,424+140,31);
		setcolor(BROWN);
		line(424,31,634,31);
		line(424+141,5,424+141,30);
		line(424+140-1,5,424+140-1,30);
		line(424+69,5,424+69,30);
		line(424+71,5,424+71,30);
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(4,fix_poly1);
		fillpoly(4,fix_poly2);
		setcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		fillpoly(4,q_poly);
		settextstyle(0,0,1);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		if(life_50_50==0)
			setcolor(LIGHTGRAY);
		else
			setcolor(DARKGRAY);
		outtextxy(459,17,"50-50");
		if(life_ask==0)
			setcolor(LIGHTGRAY);
		else
			setcolor(DARKGRAY);
		outtextxy(529,17,"Ask");
		if(life_poll==0)
			setcolor(LIGHTGRAY);
		else
			setcolor(DARKGRAY);
		outtextxy(599,17,"Poll");
		settextjustify(RIGHT_TEXT,TOP_TEXT);
		for(i=1;i<16;i++)
		{
			itoa(16-i,ch,10);
			setcolor(WHITE);
			moveto(483,(i-1)*21+35);
			settextjustify(RIGHT_TEXT,TOP_TEXT);
			outtext(ch);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			outtext(" - ");
		}
		setcolor(WHITE);
		moveto(508,(1-1)*21+35); settextjustify(LEFT_TEXT,TOP_TEXT);
		outtext("1,00,00,00,000"); moveto(508,(2-1)*21+35);
		outtext("10,00,00,000"); moveto(508,(3-1)*21+35);
		outtext("1,00,00,000"); moveto(508,(4-1)*21+35);
/**/	outtext("50,00,000"); moveto(508,(5-1)*21+35);
		outtext("25,00,000"); moveto(508,(6-1)*21+35);
		outtext("12,50,000"); moveto(508,(7-1)*21+35);
		outtext("6,25,000"); moveto(508,(8-1)*21+35);
		outtext("3,20,000"); moveto(508,(9-1)*21+35);
/**/	outtext("1,60,000"); moveto(508,(10-1)*21+35);
		outtext("80,000"); moveto(508,(11-1)*21+35);
		outtext("40,000"); moveto(508,(12-1)*21+35);
		outtext("20,000"); moveto(508,(13-1)*21+35);
		outtext("10,000"); moveto(508,(14-1)*21+35);
		outtext("5,000"); moveto(508,(15-1)*21+35);
		outtext("2,500"); moveto(508,(16-1)*21+35);
		rectangle(6,6,420,31);
		floodfill(8,8,WHITE);
		setcolor(WHITE);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		outtextxy(213,19,"\'F1\':Help \'9\':50-50 \'8\':Ask \'7\':Poll \'Esc\':Quit");
		outtextxy(56,380,"A:");
		outtextxy(367,380,"B:");
		outtextxy(56,442,"C:");
		outtextxy(367,442,"D:");
		settextstyle(0,0,2);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
	}

	void read_q()
	{
		if(fread(&qa,sizeof(qa),1,fp)!=1)
		{
			rewind(fp);
			fread(&qa,sizeof(qa),1,fp);
			q_done++;
		}

	}

	void show_q()
	{
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(0,0,1);
		outtextxy(213,280,qa.q);
		outtextxy(186,380,qa.a1);
		outtextxy(456,380,qa.a2);
		outtextxy(186,442,qa.a3);
		outtextxy(456,442,qa.a4);
		settextstyle(0,0,2);
	}

	//play game funtion
	void game()
	{
		int gd=DETECT,gm,errorcode;
		x=11,y=380;
		char do_exit='n';
		char key;
		initgraph(&gd,&gm,".");
		errorcode = graphresult();
		if (errorcode != grOk)  /* an error occurred */
		{
			printf("Graphics error: %s\n", grapherrormsg(errorcode));
			printf("Press any key to halt:");
			getch();
			fclose(fd);
			remove("DATA2.DAT");
			fd=fopen("DATA2.DAT","wb+");
			fwrite(&q_done,sizeof(q_done),1,fd);
			fclose(fd);
			exit(1);             /* return with error code */
		}

		if(fread(&qa,sizeof(qa),1,fp)!=1)
		{
			rewind(fp);
			fread(&qa,sizeof(qa),1,fp);
			q_done++;
		}
label1:
		start();
		show_q();
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(0,0,1);
		outtextxy(213,280,qa.q);
		outtextxy(186,380,qa.a1);
		outtextxy(456,380,qa.a2);
		outtextxy(186,442,qa.a3);
		outtextxy(456,442,qa.a4);
		settextstyle(0,0,2);
		key=getch();
		settextstyle(0,0,2);

		settextjustify(LEFT_TEXT,CENTER_TEXT);
		while(key!=13&&key!=27&&key!=1)
		{
			if(key==0)
			{
				key=getch();
				switch(key)
				{
					case 72 : case 80 : if(y==380)
											y=442;
										else y=380;
										break;
					case 75 : case 77 : if(x==11)
											x=327;
										else x=11;
										break;
					case 1 :  fclose(fd);
							  remove("DATA2.DAT");
							  fd=fopen("DATA2.DAT","wb+");
							  fwrite(&q_done,sizeof(q_done),1,fd);
							  fclose(fd);
							  exit(0);
							  break;
					case 59 : help(0);
							  break;
				}
			}
			else
			{
				switch(key)
				{
					 case 27: fclose(fd);
							  remove("DATA2.DAT");
							  fd=fopen("DATA2.DAT","wb+");
							  fwrite(&q_done,sizeof(q_done),1,fd);
							  fclose(fd);
							  exit(0);
							  break;
					 case '9': help(9);
							   break;
					 case '8': help(8);
							   break;
					 case '7': help(7);
							   break;
				}
			}
			settextstyle(0,0,2);
			settextjustify(LEFT_TEXT,CENTER_TEXT);
			setcolor(BROWN);
			outtextxy(11,380,"");
			outtextxy(11,442,"");
			outtextxy(327,380,"");
			outtextxy(327,442,"");
			moveto(x,y);
			setcolor(LIGHTGREEN);
			outtext("");
			fflush(stdin);
			fflush(stdin);
			key=getch();
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			settextstyle(0,0,1);
			outtextxy(213,280,qa.q);
			outtextxy(186,380,qa.a1);
			outtextxy(456,380,qa.a2);
			outtextxy(186,442,qa.a3);
			outtextxy(456,442,qa.a4);
			settextstyle(0,0,2);
		}
		show_q();

		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		if(key==13)
		{
			if( (x==11&&y==380&&qa.c==1)||(x==327&&y==380&&qa.c==2)||(x==11&&y==442&&qa.c==3)||(x==327&&y==442&&qa.c==4) )
			{
				ques_no++;
				if(fread(&qa,sizeof(qa),1,fp)!=1)
				{
					rewind(fp);
					fread(&qa,sizeof(qa),1,fp);
					q_done++;
				}
				if(ques_no>15)
				{
					settextstyle(0,0,3);
					outtextxy(320,240,"You Won !!!");
					delay(3000);
					return ;
				}
				goto label1;
			}
			else
			{
				settextstyle(0,0,3);
				outtextxy(320,240,"You Lose !!!");
				delay(3000);
				return ;
			}
			key=14;
			cleardevice();
			fflush(stdin); fflush(stdin);
			fflush(stdin); fflush(stdin);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			settextstyle(0,0,1);
			outtextxy(213,280,qa.q);
			outtextxy(186,380,qa.a1);
			outtextxy(456,380,qa.a2);
			outtextxy(186,442,qa.a3);
			outtextxy(456,442,qa.a4);
			settextstyle(0,0,2);
			fflush(stdin); fflush(stdin);
			fflush(stdin); fflush(stdin);
			cleardevice();
			goto label1;
		}
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		closegraph();
	}

	void help(int help_code)
	{
		char ch2;
		setcolor(WHITE);
		rectangle(6,33,420,73);
		rectangle(6,75,420,215);
		setcolor(GREEN);
		settextstyle(0,0,1);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		if(help_code==0) outtextxy(213,53,"Help !!!");
		if(help_code==7) outtextxy(213,53,"Poll"); fflush(stdin);
		if(help_code==8) outtextxy(213,53,"Ask");
		if(help_code==9) outtextxy(213,53,"50-50");
		if(help_code==7)
		{
			if(life_poll==0)
			{
				life_poll=1;
				int c1=0,c2=0,c3=0,c4=0;
				char *ch1,*ch2,*ch3,*ch4;
				int num,i=0;
				time_t t;
				srand((unsigned) time(&t));
				for(i=0;i<100;i++)
				{
					num=rand()%4+1;
					if(num==1) c1++;
					else if(num==2) c2++;
					else if(num==3) c3++;
					else if(num==4) c4++;
				}
				setcolor(WHITE);
				rectangle(25,187-c1,105,187);
				rectangle(124,187-c2,204,187);
				rectangle(223,187-c3,303,187);
				rectangle(322,187-c4,402,187);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				settextstyle(0,0,2);
				if(c1>2) floodfill(65,186,WHITE);
				if(c2>2) floodfill(164,186,WHITE);
				if(c3>2) floodfill(263,186,WHITE);
				if(c4>2) floodfill(362,186,WHITE);
				setcolor(RED) ;
				outtextxy(65,200,"A");
				outtextxy(164,200,"B");
				outtextxy(263,200,"C");
				outtextxy(362,200,"D");
				settextstyle(0,0,1);
				itoa(c1,ch1,10); itoa(c2,ch2,10);
				itoa(c3,ch3,10); itoa(c4,ch4,10);
				strcat(ch1," %"); strcat(ch2," %");
				strcat(ch3," %"); strcat(ch4," %");
				outtextxy(65,150-c1,ch1);
				outtextxy(164,150-c2,ch2);
				outtextxy(263,150-c3,ch3);
				outtextxy(362,150-c4,ch4);
				settextstyle(0,0,2);
			}
			else
				outtextxy(213,137,"You have already used this life !!!");
		}

		if(help_code==8)
		{
			if(life_ask==0)
			{
				life_ask=1;
				int nu;
				time_t t;
				srand((unsigned) time(&t));
				nu=rand()%4;
				moveto(213,137);
				outtext("I think you go for choice ");
				moveto(273,137);
				if(nu==0) outtext("A");
				else if(nu==1) outtext("B");
				else if(nu==2) outtext("C");
				else if(nu==3) outtext("D");
			}
			else
				outtextxy(213,137,"You have already used this life !!!");

		}

		if(help_code==9)
		{
			if(life_50_50==0)
			{
				life_50_50=1;
			}
			else
				outtextxy(213,137,"You have already used this life !!!");
		}

		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		ch2=getch();
		cleardevice();
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		settextstyle(0,0,2);
		int poly_a1[14]={51,350,301,350,311,380,301,410,51,410,41,380,51,350};
		int poly_a2[14]={10+302+30+20 ,0+350 ,290+302+30 ,0+350 ,300+302+30 ,30+350 ,290+302+30 ,60+350 ,10+302+30+20 ,60+350 ,0+302+30+20 ,30+350 ,10+302+30+20 ,0+350};
		int poly_a3[14]={10+6+30+5   ,0+412 ,290+6+5   ,0+412 ,300+6+5   ,30+412 ,290+6+5   ,60+412 ,10+6+30+5   ,60+412 ,0+6+30+5   ,30+412 ,10+6+30+5   ,0+412};
		int poly_a4[14]={10+302+30+20 ,0+412 ,290+302+30 ,0+412 ,300+302+30 ,30+412 ,290+302+30 ,60+412 ,10+302+30+20 ,60+412 ,0+302+30+20 ,30+412 ,10+30+302+20 ,0+412};
		int fix_poly1[8]={426,(4-1)*21+30,633,(4-1)*21+30,633,(4-1)*21+48,426,(4-1)*21+48};
		int fix_poly2[8]={426,(9-1)*21+30,633,(9-1)*21+30,633,(9-1)*21+48,426,(9-1)*21+48};
		int q_poly[8]={426,(15-ques_no)*21+30,633,(15-ques_no)*21+30,633,(15-ques_no)*21+48,426,(15-ques_no)*21+48};
		int i;
		char *ch;
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		cleardevice();
		fflush(stdin);
		setcolor(BROWN);
		rectangle(0,0,getmaxx(),getmaxy());
		rectangle(2,2,getmaxx()-2,getmaxy()-2);
		rectangle(424,4,getmaxx()-4,350-4);
		rectangle(4,4,422,350-4);
		rectangle(4,350-2,getmaxx()-4,getmaxy()-4);
		setcolor(YELLOW);
		drawpoly(7,poly_a1);
		drawpoly(7,poly_a2);
		drawpoly(7,poly_a3);
		drawpoly(7,poly_a4);
		settextstyle(0,0,2);
		settextjustify(LEFT_TEXT,CENTER_TEXT);
		setcolor(BROWN);
		outtextxy(11,380,"");
		outtextxy(11,442,"");
		outtextxy(327,380,"");
		outtextxy(327,442,"");
		setcolor(LIGHTGREEN);
		outtextxy(x,y,"");
		setcolor(WHITE);
		line(424+70,4,424+70,31);
		line(424+140,4,424+140,31);
		setcolor(BROWN);
		line(424,31,634,31);
		line(424+141,5,424+141,30);
		line(424+140-1,5,424+140-1,30);
		line(424+69,5,424+69,30);
		line(424+71,5,424+71,30);
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(4,fix_poly1);
		fillpoly(4,fix_poly2);
		setcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		fillpoly(4,q_poly);
		settextstyle(0,0,1);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		if(life_50_50==0)
			setcolor(LIGHTGRAY);
		else
			setcolor(DARKGRAY);
		outtextxy(459,17,"50-50");
		if(life_ask==0)
			setcolor(LIGHTGRAY);
		else
			setcolor(DARKGRAY);
		outtextxy(529,17,"Ask");
		if(life_poll==0)
			setcolor(LIGHTGRAY);
		else
			setcolor(DARKGRAY);
		outtextxy(599,17,"Poll");
		settextjustify(RIGHT_TEXT,TOP_TEXT);
		for(i=1;i<16;i++)
		{
			itoa(16-i,ch,10);
			setcolor(WHITE);
			moveto(483,(i-1)*21+35);
			settextjustify(RIGHT_TEXT,TOP_TEXT);
			outtext(ch);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			outtext(" - ");
		}
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(0,0,1);
		outtextxy(213,280,qa.q);
		outtextxy(186,380,qa.a1);
		outtextxy(456,380,qa.a2);
		outtextxy(186,442,qa.a3);
		outtextxy(456,442,qa.a4);
		settextstyle(0,0,2);
		setcolor(WHITE);
		moveto(508,(1-1)*21+35); settextjustify(LEFT_TEXT,TOP_TEXT);
		outtext("1,00,00,00,000"); moveto(508,(2-1)*21+35);
		outtext("10,00,00,000"); moveto(508,(3-1)*21+35);
		outtext("1,00,00,000"); moveto(508,(4-1)*21+35);
/**/	outtext("50,00,000"); moveto(508,(5-1)*21+35);
		outtext("25,00,000"); moveto(508,(6-1)*21+35);
		outtext("12,50,000"); moveto(508,(7-1)*21+35);
		outtext("6,25,000"); moveto(508,(8-1)*21+35);
		outtext("3,20,000"); moveto(508,(9-1)*21+35);
/**/	outtext("1,60,000"); moveto(508,(10-1)*21+35);
		outtext("80,000"); moveto(508,(11-1)*21+35);
		outtext("40,000"); moveto(508,(12-1)*21+35);
		outtext("20,000"); moveto(508,(13-1)*21+35);
		outtext("10,000"); moveto(508,(14-1)*21+35);
		outtext("5,000"); moveto(508,(15-1)*21+35);
		outtext("2,500"); moveto(508,(16-1)*21+35);
		rectangle(6,6,420,31);
		floodfill(8,8,WHITE);
		setcolor(WHITE);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		fflush(stdout); fflush(stdout);
		fflush(stdout); fflush(stdout);
		outtextxy(213,19,"\'F1\':Help \'9\':50-50 \'8\':Ask \'7\':Poll \'Esc\':Quit");
		outtextxy(56,380,"A:");
		outtextxy(367,380,"B:");
		outtextxy(56,442,"C:");
		outtextxy(367,442,"D:");
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		fflush(stdin); fflush(stdin);
		outtextxy(213,19,"\'F1\':Help \'9\':50-50 \'8\':Ask \'7\':Poll \'Esc\':Quit");
		setcolor(WHITE);
		moveto(508,(1-1)*21+35); settextjustify(LEFT_TEXT,TOP_TEXT);
		outtext("1,00,00,00,000"); moveto(508,(2-1)*21+35);
		outtext("10,00,00,000"); moveto(508,(3-1)*21+35);
		outtext("1,00,00,000"); moveto(508,(4-1)*21+35);
/**/	outtext("50,00,000"); moveto(508,(5-1)*21+35);
		outtext("25,00,000"); moveto(508,(6-1)*21+35);
		outtext("12,50,000"); moveto(508,(7-1)*21+35);
		outtext("6,25,000"); moveto(508,(8-1)*21+35);
		outtext("3,20,000"); moveto(508,(9-1)*21+35);
/**/	outtext("1,60,000"); moveto(508,(10-1)*21+35);
		outtext("80,000"); moveto(508,(11-1)*21+35);
		outtext("40,000"); moveto(508,(12-1)*21+35);
		outtext("20,000"); moveto(508,(13-1)*21+35);
		outtext("10,000"); moveto(508,(14-1)*21+35);
		outtext("5,000"); moveto(508,(15-1)*21+35);
		outtext("2,500"); moveto(508,(16-1)*21+35);
		settextstyle(0,0,2);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(0,0,1);
		outtextxy(213,280,qa.q);
		outtextxy(186,380,qa.a1);
		outtextxy(456,380,qa.a2);
		outtextxy(186,442,qa.a3);
		outtextxy(456,442,qa.a4);
		settextstyle(0,0,2);
	}

	// SetMCGA() - This function gets you into 320x200x256 mode.
	void SetMCGA()
	{
		_AX = 0x0013;
		geninterrupt (0x10);
	}

	// SetText() - This function gets you into text mode.
	void SetText()
	{
		_AX = 0x0003;
		geninterrupt (0x10);
	}

	// Pal() - This sets the Red, Green, and Blue values of a certain color.
	void Pal(unsigned char ColorNo,unsigned char R,unsigned char G,unsigned char B)
	{
		outp (0x03C8,ColorNo); // here is the pallette color I want to set
		outp (0x03C9,R);
		outp (0x03C9,G);
		outp (0x03C9,B);
	}

	// LoadPal() - This loads the Pallette file and puts it on screen.
	void LoadPal(char *FileName)
	{
		typedef unsigned char DACType[256][3]; // [256] colors, [3] types (R,G,B)
		DACType DAC;
		FILE *fp;
		int loop1;
		fp = fopen(FileName,"rb");
		fread(DAC,sizeof(DACType),1,fp);
		fclose(fp);
		for (loop1=0; loop1<256; loop1++)
			Pal(loop1, DAC[loop1][0], DAC[loop1][1], DAC[loop1][2]);
	}

	// Putpixel() - This puts a pixel at X,Y using color Col, on VGA or the
	// Virtual Screen;
	void Putpixel (int x,int y,unsigned char Col,unsigned char *Where)
	{
		memset(Where+(x+(y*320)),Col,1);
	}

	// WaitRetrace() - This waits until you are in a Verticle Retrace.
	void WaitRetrace()
	{
		_DX = 0x03DA;
		l1: asm {
			in  al,dx;
			and al,0x08;
			jnz l1;
		}
		l2: asm {
			in  al,dx;
			and al,0x08;
			jz  l2;
		}
	}

	// Exist() - Checks to see if file exists or not.
	int Exist (char *FileName)
	{
		FILE *fp;
		if ((fp = fopen(FileName,"rb")) != NULL)
		{
			fclose(fp);
			return 1;
		}
		else
			return 0;
	}


	// Setup() - This loads the font and the pallette.
	void Setup(int a)
	{
		FILE *fp;
		int loop1, loop2, loop3;
		int error=0;
		Font = (Letter *) calloc(NumLetters,sizeof(Letter));

		if (Font == NULL)
		{ // always check to make sure you have enough memory!
			SetText();
			if(a==1)
				cout << "Not enough memory available, exiting program...";
			error=1;
			fclose(fd);
			remove("DATA2.DAT");
			fd=fopen("DATA2.DAT","wb+");
			fwrite(&q_done,sizeof(q_done),1,fd);
			fclose(fd);
			exit(1);
		}
		if(a==1)
			cout<<"\nDetecting \"SOFTROCK.FNT\"\n";
		if (Exist("SOFTROCK.FNT\0"))
		{ // don't forget the "\0" null terminator
			fp = fopen("SOFTROCK.FNT","rb");
			fread(Font,sizeof(Letter),NumLetters,fp);
			if(a==1)
				cout << "\"SOFTROCK.FNT\" found in current directory. Using.\n";
			fclose(fp);
		}
		else
		{
			if(a==1)
				cout << "\"SOFTROCK.FNT\" not found in current directory.\n";
			for(loop1=0;loop1<NumLetters;loop1++)
				for(loop2=0;loop2<XSize;loop2++)
					for (loop3=0;loop3<YSize;loop3++)
						Font[loop1][loop2][loop3] = loop2;
			error=1;
		}
		if(a==1)
			cout<<"\nDetecting \"PALLETTE.COL\"\n";
		if (Exist("PALLETTE.COL\0")) // don't forget the \0 null terminator
		{
			if(a==1)
				cout << "\"PALLETTE.COL\" found in current directory. Using.\n";
		}
		else
		{
			if(a==1)
				cout << "\"PALLETTE.COL\" not found in current directory.\n";
			error=1;
		}
		SetMCGA();
		if (Exist("PALLETTE.COL\0")) LoadPal("PALLETTE.COL\0");
		if(a==1&&error==1)
			getch();
	}


	// ScrollMsg() - This scrolls the string in Msg across the screen.
	void ScrollMsg (char *Msg, int SizeMsg,int yaxis)
	{
		int loop1, loop2, loop3;
		int Location = yaxis; // specify how far from the top of the screen we want
			  // the scroller to appear
		// MAIN LOOP - do every letter in Msg
		for (loop1 = 0; loop1 < SizeMsg; loop1++)
		{
			// Do this loop <n> number of times where <n> = the width of a letter
			for (loop2 = 0; loop2 < XSize; loop2++)
			{
				// There are two loops here.
				//
				// 1. Copy YSize rows to the left by 1.  In effect, this frees up a
				//    blank column of vertical pixels on the right side of the screen.
				// 2. Replace that new blank column with pixels from our Font[] table.
				WaitRetrace();
				for (loop3=Location; loop3<Location+YSize; loop3++)
					// move each row to the left by 1
					memcpy(vga+(0+(loop3*320)), vga+(1+(loop3*320)), 320);
				for (loop3=Location; loop3<Location+YSize; loop3++)
					// Replace the new column on the right with information from Font[].
					// In the following statement:
					//   (320,         - y location (the rightmost column)
					//   loop3,        - x location (the current row we are working with)
					//   Font[...      - Get information from our Font table.  All of this
					//                   complex indexing really just gives us the pallette
					//                   number we are putting to the screen at a given
					//                   location.
					//    [(Msg[loop1]-32)] - Access the correct letter from our Font
					//                        table.  The (Msg[loop1]) would give us the
					//                        ASCII value of the letter we want to display,
					//                        but we need to subtract 32 to coordinate the
					//                        ASCII value with our Font table.
					//    [loop2]           - the column index of the letter we are using
					//    [loop3-Location]  - the row    index of the letter we are using
					Putpixel (319,loop3,Font[(Msg[loop1]-32)][loop2][loop3-Location],vga);
			} // we have now inserted a new letter on the right side of the screen
			// This next bit scrolls by one pixel after each letter so that there
			// are gaps between the letters
			WaitRetrace();
			for (loop3=Location; loop3<Location+YSize; loop3++)
				// move each row to the left by 1 (same as above)
				memcpy( vga+(loop3*320), vga+(1+(loop3*320)), 320);
			for (loop3 = 100; loop3 < 100 + YSize; loop3++)
				// put a blank column of pixels
				Putpixel(319,loop3,0,vga);
		} // we have now scrolled the entire message once
	}
