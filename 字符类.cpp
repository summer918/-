#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib") 

int num=20,k=0;
time_t start,end;
int hour = 0, minl = 0, sec = 0,time_1=0;;
int score=0;

void choose();//ѡ������
void getchoice();
//int in_gore(void *pdata);
void tshi();
void look(char *st);//�������
void menu();
void leave();
void read(char *str,int N,int flag);//���ļ��ж�������ģ�鲢��������
void recite(struct studentread *head,int N,int flag);//������ģ��
void display();//��ӡ����ģ��
void ch(char no,int N,int flag);//���ݲ�ͬ�꼶��ѡ��ͬ�ļ�
void ch1(char no);//���ݲ�ͬ�꼶��ѡ��ͬ�ļ����
void jump();
void challeng(int N);//��սģ��
void wrongtxt(struct studentread *head);//���Ᵽ�浽�ļ�
struct studentread * wrongread();//��������
void pf1();//���������ļ�
void pf2();
void tshi_1();//��ʾ��ս��Ϣ
void main();
void wrongmenu();//����Ŀ¼


struct studentread
{
	char word[200];//Ӣ��
	char ch[200];//����
	struct studentread *next;
};

/*struct mydata
{
	thrd_t id;
	int hour;
	int min;
	int sec;
};*/

static void setPos(int x,int y)
{

   COORD point = {x,y};//���Ҫ���õ�λ��x,y
   HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
   SetConsoleCursorPosition(HOutput, point);//���ù��λ��
}

//���ع��
void HideCursor()
{
CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


void color(short x) //�Զ��庯���ݲ����ı���ɫ   
{  
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //ֻ��һ���������ı�������ɫ   
    else//Ĭ�ϵ���ɫ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
}  

void zhuanshi()
{
	printf("\n\n\n\n\t\t\t\t�������ʼ\n\n");
	Sleep(1500);
	system("cls");
	start=time(NULL);
	system("color 4");
	for(sec=1;sec<=3;sec++)
	{
		if(sec==1)
			color(4);
		else if(sec==2)
			color(5);
		else
			color(6);
		 printf("\n\n\n\n\n\t\t\t\t\t\t[%d]",sec);
		Sleep(1000);
		system("cls");
	}
	printf("\n\n\n\n\n\t\t\t\t\t\tReady\n");
	Sleep(600);
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t\t\tGO\n");
	Sleep(600);
	system("cls");
	system("color B4");
	sec=0;
}

//����ʱ��
void time1()
{
	 while(sec>60)
	   {
		   minl++;
		   sec=sec-60;
	   }
	   if(minl==60)
	   {
		   hour++;
		   minl=0;
	   }
	   if(hour==24)
		   hour=0;
}

//ѡ������
void choose()
{
	system("color B1");
	printf("\n\n\n\t\t\t\t\t��������Ҫ���ĵ�����(1-20)��\n");
	setPos(39,5);
	scanf("%d",&num);
	
}


//�������
void look(char *st)
{
	FILE *fp;
	char word[1024];
	int i=0;
	system("color 9");
	memset(word,0,sizeof(char)*1024);
	if((fp=fopen(st,"r+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
      color(4);  
	 printf("\n\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��                    �ʻ���    \n");
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\n\n\n");
	 setPos(0,0);
	while(!feof(fp))
	{
		if(fscanf(fp,"%s",word)!=EOF)
		{
			if(i%2==0)
				 color(6); 
			else
				color(4);
		   printf("\t\t��������������������������������������������������������������������������������������������\n");
	       printf("\t\t��             %s    \n",word);
	       printf("\t\t��������������������������������������������������������������������������������������������\n");
		   i++;
		}
		
		   if(i%8==0)
		   {       system("pause");
			      system("cls");
			   	  printf("\n\t\t��������������������������������������������������������������������������������������������\n");
	               printf("\t\t��                    �ʻ���    \n");
	               printf("\t\t��������������������������������������������������������������������������������������������\n");
	               printf("\n\n\n");
			      
		   }
	}
	fclose(fp);
	system("pause");
}







//���ļ��ж�������ģ�鲢��������
void read(char *str,int N,int flag)
{
	FILE *fp;
	int i=1;
	struct studentread *p1,*head=NULL;
	head=(struct studentread *)malloc(sizeof(struct studentread));
	memset(head,0,sizeof(struct studentread));
	if((fp=fopen(str,"r+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
	while(i<=N)
	{    
		p1=(struct studentread *)malloc(sizeof(struct studentread));
	    memset(p1,0,sizeof(struct studentread));
		if(fscanf(fp,"%s",p1->word)!=EOF&&fscanf(fp,"%s",p1->ch)!=EOF)
		{
		 
			p1->next=head->next;
			head->next=p1;
		}
		  
		i++;
	}
	fclose(fp);	

recite(head,N,flag);
}
//�ͷ��ڴ�
void freelist(struct studentread *head)
{
	struct studentread *p=head->next,*p1;
	while(p!=NULL)
	{
		p1=p->next;
		free(p1);
		p=p1;
	}
}


//������ģ��
void recite(struct studentread *head,int N,int flag)
{
	int i=0,min,n=0,c1=0;
	char r;
	char string[200];
	struct studentread *p=head->next,*h_d=NULL;
	memset(string,0,sizeof(char)*200);
    hour=minl=sec=0;
	if(flag)
	   choose();//ѡ�񵥴���
	zhuanshi();//��ʼǰ����ʾ
	srand(time(NULL));
	i=rand()%(N/2-k)+1;//�����������������ɵ���
	k++;
	if(N==k)
		k=0;//�Է�k>N
	score=num;
	for(min=0;min<i;min++)
	{
		if(p!=NULL)
		  p=p->next;//�ҵ�λ��Ϊi�Ľڵ�
		
	}
	h_d=p;
	for(min=0;min<num;min++)
	{
		time1();
	   printf("\n\n\t\t\t\t��|%02d:%02d:%02d|",hour,minl,sec);
	   printf("\t���ѱ�����������%d\t��ȷ������%d",n,c1);
	   	// ������
    mciSendString("open 3530.mp3 alias mymusic", NULL, 0, NULL);

// ��������
    mciSendString("play mymusic", NULL, 0, NULL);

	   if(!flag)
	   {
		   if(minl==time_1)
		   {
			   color(4);
			    printf("\n\n\n\t\t\t\t:-O��սʧ�ܣ�\n");
			    printf("\n\t\t\t\t<1> ����\t<2> �˳�\n");
			    printf("\n\t\t\t\t\t��ѡ��");
		         scanf("%d",&r);
				 	if(r==2)
					{
						menu();
						break;
					}
		   }
	   }
         color(5);
		printf("\n\n\n\t\t\t\t�����ģ�%s\n\n",p->ch);
		color(10);
		printf("\t\t\t\t��������Ӣ��:");
		scanf("%s",string);
		printf("\n\n");
		// ֹͣ���Ų��ر�����
         mciSendString("stop mymusic", NULL, 0, NULL);
         mciSendString("close mymusic", NULL, 0, NULL);
		if(strcmp(string,"0")==0)
		{
			system("cls");
			printf("\n\n\n\t\t\t\t��������ѧϰ��Ҫ��֣�\n\n");
			Sleep(1000);
			system("cls");
			menu();
			break;
		}
		if(strcmp(string,p->word)==0)
		{
			pf2();
			color(3);
			printf("\t\t\t\t��ش���ȷ�R��Q\n");
			Sleep(100);
			c1++;
		}
		else
		{
			wrongtxt(p);
			pf1();
			color(4);
			printf("\t\t\t\t��ش����T_T\n");
			Sleep(100);
			score-=1;
		}
	//	sec++;
		n++;
		end=time(NULL);
		sec=(int)difftime(end,start);
		memset(string,0,sizeof(char)*20);
		p=p->next;
		system("cls");
	}
	display();
	system("pause");
	system("cls");
	system("color 04");
	if(flag)//��ͨ��ϰģ��Ĳ���
	{
		printf("\n\n\t\t\t\t\t��������������¸�ϰһ��ɣ�\n");
    	for(i=0;i<num;i++)
		{
			color(3);
		printf("\n\t\t\t\t\t________________________________\n");
		printf("\t\t\t\t\t       %s               \t\t\t\n",h_d->word);
		printf("\t\t\t\t\t________________________________\t\t\t\n");
		printf("\t\t\t\t\t<1> ��ʶ\t<2> ����ʶ");
		printf("\n\t\t\t\t\t��ѡ��");
		r=getch();
		if(r==49)
		     h_d=h_d->next;
		else
		{
			color(4);
			printf("\n\t\t\t\t\t�����ģ�%s",h_d->ch);
			//system("pause");
		    h_d=h_d->next;
		}
		
		}
	}
	system("pause");
	system("cls");
		//freelist(head);//�ͷ��ڴ�
	printf("\n\n\n");
	num=0;//�Ա��´δ�0��ʼ
	
}


	
//��ӡ����ģ��
void display()
{
	system("color E4");
	printf("\n\n\t\t\t\t\t����ܷ�:%d\n",score);
	if(score!=0)
	    printf("\t\t\t\t\t�����ȷ��:%.3f\n",(score/num*1.0)*100);
	else
	    printf("\t\t\t\t\t�����ȷ��:0.00\n");
	time1();
	printf("\t\t\t\t\t�����ʱ��\n");
	printf("\t\t\t\t\t\t__________________\n");
    printf("\t\t\t\t\t\t%02d:%02d:%02d   \n",hour, minl, sec);//%02d�������Ϊ2������2ǰ�油0
    printf("\t\t\t\t\t\t_________________\n\n");
    if(num==score)
		printf("\t\t\t\t\t<��baby�����!\n");
	else
		printf("\t\t\t\t\tT_Tbaby,��Ҫ����Ŭ��Ŷ!\n");
}

 

//���Ᵽ�浽�ļ�
void wrongtxt(struct studentread *h)
{
	FILE *fp;
	if((fp=fopen("wrong.txt","a+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
	fwrite(h,sizeof(struct studentread),1,fp);
	fclose(fp);
}


//����ȫ������
void wrong_baocun(struct studentread *head)
{
      FILE *fp;
	   struct studentread *p;
	   p=head->next;
	if((fp=fopen("wrong.txt","w+"))==NULL)
	{
		printf("can't open this file!");
		exit(0);
	}
	while(p!=NULL)
	{
			fwrite(p,sizeof(struct studentread),1,fp);
			p=p->next;
	}
	fclose(fp);
	freelist(head);//�ͷ��ڴ�
	menu();

}

//��������
struct studentread * wrongread()
{
	struct studentread *p,*head=NULL;
	FILE *fp;
	head=(struct studentread *)malloc(sizeof(struct studentread));
	memset(head,0,sizeof(struct studentread));
	if((fp=fopen("wrong.txt","r+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
	while(!feof(fp))
	{
		p=(struct studentread *)malloc(sizeof(struct studentread));
	    memset(p,0,sizeof(struct studentread));
		if(fread(p,sizeof(struct studentread),1,fp)!=0)
		{
			p->next=head->next;
			head->next=p;
		}
	}
	fclose(fp);
	return head;
}

//������д���
void qchu()
{
	FILE *fp;
	if((fp=fopen("wrong.txt","w+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
	fclose(fp);
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��             ����ɹ���\n");
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 Sleep(1000);
}

//�������
void liulan()
{
	struct studentread *p,*head=NULL;
	int i=0;
	char k;
	head=wrongread();
	system("color 2");
	p=head->next;
	
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��            ���Ȿ\n");
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\n\n");
	 if(p==NULL)
     {
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��             ��\n");
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 }
	while(p!=NULL)
	{
		if(i%2==0)
			 color(6); 
		else
			color(4);//�仯������ɫ
     printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��             Ӣ�ģ�%s    \n",p->word);
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��             ���ģ�%s    \n",p->ch);
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 i++;
	 scanf("%c",&k);
	 if(i%8==0)
	 {
	   system("pause"); 
		 system("cls");
     printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��            ���Ȿ\n");
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\n\n");
		
	 }
		p=p->next;
	}
	system("pause");
	freelist(head);//�ͷ��ڴ�
}
//��ϰ����
void lianxi()
{
		struct studentread *p,*head=NULL,*p1;
		char word[20];
		int i=0,l=0;
		head=wrongread();
		p=head;
		sec=0;
		start=time(NULL);
		while(p->next!=NULL)
		{
			 while(sec>60)
			 {
		       minl++;
		        sec=sec-60;
			 }
	       if(minl==60)
		   {
		       hour++;
		      minl=0;
		   }
	   if(hour==24)
		   hour=0;
	   printf("\t\t\t\t��|%02d:%02d:%02d|",hour,minl,sec);
	   printf("\t����������%d\t��ȷ������%d\n\n\n",l,i);
	   color(5);
	   printf("\t\t\t\t  |���ģ�%s\n\n",p->next->ch);
	   color(10);
	   printf("\t\t\t\t  |Ӣ�ģ�");
		gets(word);
			if(strcmp(word,"0")==0)
			{
			printf("\n\n\n\t\t\t\tѧϰ��Ҫ��֣�\n\n");
			menu();
			break;
			}
			if(strcmp(word,p->next->word)==0)
			{
				color(3);
				printf("\n\n\t\t\t\t��ش���ȷ�R��Q\n");
				Sleep(1000);
				p1=p->next;
				p->next=p->next->next;
				free(p1);
				i++;
				p=p->next;
			}
			else
			{
				color(4);
				printf("\n\n\t\t\t\t��ش����T_T\n");
				Sleep(1000);
				
				l++;
			}
			end=time(NULL);
	    	sec=(int)difftime(end,start);
			system("cls");
			
		}
		
		printf("\n\n\t\t\t\t���_____________________________���\n");
		printf("\n\n\t\t\t\t������𵥴ʣ�%d |�����𵥴ʣ�%d ���\n",i,l);
		printf("\n\n\t\t\t\t���_____________________________���\n\n");
		Sleep(2000);
		wrong_baocun(head);
}


   
//���ݲ�ͬ�꼶��ѡ��ͬ�ļ�
void ch(char no,int N,int flag)
{
	char *str;
	
	switch(no)
	{
    	case 49:str="word1.txt";num=15;break;
		case 50:str="word2.txt";num=25;break;
		case 51:str="word3.txt";num=35;break;
		case 52:str="word4.txt";num=45;break;
		case 53:str="word5.txt";num=65;break;
		case 54:str="word6.txt";num=80;break;
	}
   
	if(!flag)
	{
		tshi_1();
		Sleep(3500);//��սģ�����ʾ
	}
	read(str,N,flag);

}

//���ݲ�ͬ�꼶��ѡ��ͬ�ļ����
void ch1(char no)
{
	char *str;
	switch(no)
	{
    	case 49:str="word1.txt";look(str);break;
		case 50:str="word2.txt";look(str);break;
		case 51:str="word3.txt";look(str);break;
		case 52:str="word4.txt";look(str);break;
		case 53:str="word5.txt";look(str);break;
		case 54:str="word6.txt";look(str);break;
	}
}

//��ս����
void jump()
{
	if(minl<time_1&&score==num&&hour==0)
				  printf("\t\t\t\t\t�����ս�ɹ����\n");
    else 
                  printf("\t\t\t\t\t������ź�����սʧ�ܣ����\n");

}


//��սģ��
void challeng(int N)
{
	char i;
	system("color D");
    printf("\t\t\t\t==========================================================================\n");
	printf("\t\t\t\t|   ��ܰ��ʾ����ѡ��ͬ�ĵȼ���Խ�����Ѷ�Խ���ڹ涨��ʱ���н���ȫ�����|\n");
	printf("\t\t\t\t|=========================================================================|\n\n\n");
	printf("\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x\n\n");
	color(3);
	printf("\t\t\t\t��       1 ��ͭ           ��\n\n");
	color(4);
	printf("\t\t\t\t��       2 ����           ��\n\n");
	color(5);
	printf("\t\t\t\t��       3 �ƽ�           ��\n\n");
	color(6);
	printf("\t\t\t\t��       4 ����           ��\n\n");
	color(7);
	printf("\t\t\t\t��       5 ��ʯ           ��\n\n");
	color(8);
	printf("\t\t\t\t��       6 �ƽ�           ��\n\n");
	printf("\t\t\t\t��������������������������\n\n");
	color(9);
	printf("\t\t\t\t�����ӭ������սģ�飬ף�����!���\n\n");
	printf("\t\t\t\t��ѡ��");
    i=getch();
	switch(i)
	{
	  case 49:time_1=7;break;
      case 50:time_1=6;break;
	  case 51:time_1=5;break;
	  case 52:time_1=4;break;
	  case 53:time_1=3;break;
	  case 54:time_1=2;break;
	  default:menu();break;
	}
	system("cls");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\t\t\t\t��ս���Ͽ�ʼ��\n\n");
	ch(i,N,0);
    jump();
	 system("pause");

}

//����Ŀ¼
void wrongmenu()
{
	char i;
	int k;
	system("color B6") ;
	printf("\n\n\t\t\t\t   o__o \n\n");
    printf("\t\t\t\t   | @,@   1 �������\n\n");
    printf("\t\t\t\t��(  )��   2 ������д���\n\n");    
    printf("\t\t\t\t    \\\\��� 3 ��ϰ����\n\n");
    printf("\n");
	printf("\n");
	for(k=0;k<5;k++)
	{
		
			
			system("color 04");	
			Sleep(20);
			system("color 05");
		    Sleep(20);
		    system("color 06");
			Sleep(20);
	

	}//�任��ɫ
	system("color B6") ;
	printf("\t\t\t\t��ѡ��");
	i=getch();
	system("cls");
    switch(i)
	 {
        	case 49:liulan();
				   break;
	            	
	        case 50:lianxi();break;
			case 51:qchu();break;
			default:menu();break;
	}
	//system("cls");
	// system("pause");
}


//ѡ��ģ��
void getchoice()
{
     system("color 1") ;
	 //system("cls");
	printf("\n\n\t\t\t\t\t___������������������\n\n");
	color(4);
	printf("\t\t\t\t\t ���\\\\  1 ������ģʽ         \n\n");
	color(3);
    printf("\t\t\t\t\t @ @ c   2 ����ģʽ           \n\n");
	color(5);
	printf("\t\t\t\t\t\\\\~ /    3 �������         \n\n");
	color(6);
	printf("\t\t\t\t\t         4 ��սģʽ            \n\n");
	color(7);
	printf("\t\t\t\t\t         0 �˳�              \n\n");
	color(8);
	printf("\t\t\t\t\t    ������������������\n\n");
	printf("\t\t\t\t\t��ѡ��\n");
	setPos(46,17);
}

//�˳�ģ��
void leave()
{
	printf("\n\n\n\n\t\t\t\t\t�����С���ˣ������������ӭ�´���ѧϰ�������\n\n\n\n");
}
//���˵�
void menu()
{
	char choice,choice1;
	int N;
	system("color 4");
	system("cls");
	printf("\n\t\t\t\t��������������������������������������������������\n");
	printf("\t\t\t\t��                ��ӭ���뱳���ʳ���            ��\n");
	printf("\t\t\t\t��������������������������������������������������\n\n");
	color(4);
	printf("\t\t\t\t������ѧϰʹ����֣�������һ�����ѧϰ�ɣ�(���� ��)                \n\n");
	color(5);
	printf("\t\t\t\t     /\\`\\  /\\`\\      ��   1   Сѧ              ��   \n\n");
	color(6);
    printf("\t\t\t\t     \\/\\ V /\\/\\      ��   2   ����              ��   \n\n"); 
    printf("\t\t\t\t        /6 6\\        ��                         ��\n\n");
	color(9); 
    printf("\t\t\t\t       (= Y =)       ��   3   ����              �� \n\n");
   	printf("\t\t\t\t      /`'^'` \\       ��   4   �ļ� �R��Q       ��   \n\n");
	color(3);
   	printf("\t\t\t\t     / /      \\ \\    ��                         �� \n\n");
	color(12);
   	printf("\t\t\t\t    (_/        \\_)   ��   5   ����              ��\n\n");
	color(14);
  	printf("\t\t\t\t     /            \\o ��   6   �˼�              ��    \n\n");
  	printf("\t\t\t\t  ___\\           /___  \n");
    printf("\t\t\t\t(((____/^\\____)))  \n\n");
	printf("\t\t\t\t��ѡ������꼶��\n");
	HideCursor();
	setPos(45,26);
	choice1=getch();
	switch(choice1)
	{
    	case 49:N=100;break;
		case 50:N=1300;break;
		case 51:N=3500;break;
		case 52:N=300;break;
		case 53:N=300;break;
		case 54:N=300;break;
		default:menu();break;
	}
	
	while(1)
	{
		system("cls");
       getchoice();
	   choice=getch();
	    system("cls");
	    switch(choice)
		{
           	case 49: ch(choice1,N,1);break;
	       case 50: wrongmenu();break;
           	case 51: ch1(choice1);break;
         	case 52:challeng(N);break;
         	case 48: main();break;
           default:main();break;
		}
		if(choice==48)
			break;
	}
	 system("pause");
}

//��������
void pf1()
{
		// ������
    mciSendString("open ʧ��.mp3 alias mymusic", NULL, 0, NULL);

// ��������
    mciSendString("play mymusic", NULL, 0, NULL);

       Sleep(2000);

// ֹͣ���Ų��ر�����
           mciSendString("stop mymusic", NULL, 0, NULL);
           mciSendString("close mymusic", NULL, 0, NULL);
}

//��������
void pf2()
{
		// ������
    mciSendString("open ս��ʤ��.mp3 alias mymusic", NULL, 0, NULL);

// ��������
    mciSendString("play mymusic", NULL, 0, NULL);

        Sleep(1700);

// ֹͣ���Ų��ر�����
           mciSendString("stop mymusic", NULL, 0, NULL);
           mciSendString("close mymusic", NULL, 0, NULL);
}



void tshi()
{
	printf("\n\n\t\t\t\t_____________________________________________________________________\n");
	printf("\t\t\t\t|   ��ܰ��ʾ���ڲ����а�0�ص����˵���������ȷ�����ֽ�����Ӧ�ĳ���    |\n");
	printf("\t\t\t\t|              ���뵥�ʺ�enter������                               |\n");
	printf("\t\t\t\t|____________________________________________________________________|\n\n");
	printf("\n\n\n\n\n\t\t\t\t\t\t-----ָ����ʦ������\n");
}


void tshi_1()
{
	printf("\n\n\n\n\t\t\t\t\t=========================\n");
	printf("\t\t\t\t\t[����%d���������%d������]\n\n",time_1,num);
	printf("\t\t\t\t\t=========================\n\n");
}

//�߳�����
/*int in_gore(void *pdata)
{
	mydata * pd=(mydata*)pdata;
    while (1)
	{
        Sleep(1000);//��ͣ1s
        system("cls");//����
        pd->sec=pd->sec+1;
        if (pd->sec == 60)
		{
            pd->min=pd->min+1;
            pd->sec = 0;
        }
        if (pd->min == 60)
		{
             pd->hour=pd->hour+1;
            pd->min = 0;
        }
        if (pd->hour == 24){
            pd->hour = 0;
        }
        printf("\t\t\t\t\t\t%02d:%02d:%02d\n", pd->hour, pd->min, pd->sec);
        //%02d�������Ϊ2������2ǰ�油0
    }
    return 0;
}*/

void main()
{
	int i;
	tshi();
	for(i=0;i<5;i++)
	{
		
			
			system("color 04");	
			Sleep(20);
			system("color 05");
		    Sleep(20);
		    system("color 06");
			Sleep(20);
	

	}
	Sleep(3000);
	system("pause");
	//pf();
	menu();
	 system("pause");
}


