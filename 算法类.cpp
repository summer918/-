/***********************************/
/*     ʱ�䣺2019.2.10    ���ߣ�����     */
/*     ѧ�ţ�11803990624           */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#define _STDC_WANT_LIB_EXT1_1
#pragma comment(lib, "Winmm.lib")


int x=0;//ͳ������������
int c1=0,c2=0;//ȫ�ֱ�����ͳ�ƴ������ȷ�ĸ���
time_t start=0,end=0;
//time_t calendar_start,calendar_end;
int all=0,k=0;//all-������k-��ķ�Χ
int time_1=0;//��սʱ������
int hour=0,minl=0,sec=0;//��¼ʱ��

struct infortxt
{
	int a;
	char a1;
	int b;
	char a2;
	int c;
	char a3;
	int sum;
	struct infortxt *next;
};


void showmenu();//���˵�
void menu();
int  getchoice();//ѡ��ģ��
void  choice1(int num[]);//�������ظ��������
void  choice_3();//ѡ������
void sysExit();//�˳�ģ��
void wrongtext(int a,char a1,int b,char a2,int c,int sum);//�����Ᵽ�浽�ļ�
void cause(int c1,int c2,int all);//ͳ�Ƴɼ�
int getnode();//���������1��2
void doAdd(int flag_1);//�ӷ�ģ��
void doSub(int flag_1);//����ģ��
void doAdd1(int *num,int all,int a,int b,int sum,char sign1);//�ڶ����ּӷ�ģ��
void doSub1(int *num,int all,int a,int b,int sum1,char sign1);//�ڶ����ּ���ģ��
void caculate(int all,int a,int b,int c,int sum,char sign,char sign1);//����ģ��
struct infortxt * wrongread();//�鿴����ģ��
void challeng();//��սģ��
void jump();//��ս����
void chioce_2(int age);//�Ե�һ���ֵ�ѡ��
void time_jump(int age,double timer);//��սʱ�������
void choice_2(int age);//��ս����--�Ե�һ���ֵ�ѡ��
void timer();


static void setPos(int x,int y)
{

COORD point = {x,y};//���Ҫ���õ�λ��x,y
HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
SetConsoleCursorPosition(HOutput, point);//���ù��λ��
}

void color(short x) //�Զ��庯���ݲ����ı���ɫ   
{  
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //ֻ��һ���������ı�������ɫ   
    else//Ĭ�ϵ���ɫ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
}  

//���ع��
void HideCursor()
{
CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//ʧ������
void pf1()
{
		// ������
    mciSendString("open ʧ��.mp3 alias mymusic", NULL, 0, NULL);

// ��������
    mciSendString("play mymusic", NULL, 0, NULL);

       Sleep(1500);
// ֹͣ���Ų��ر�����
           mciSendString("stop mymusic", NULL, 0, NULL);
           mciSendString("close mymusic", NULL, 0, NULL);
}


//�ɹ�����
void pf2()
{
		// ������
    mciSendString("open ս��ʤ��.mp3 alias mymusic", NULL, 0, NULL);

// ��������
    mciSendString("play mymusic", NULL, 0, NULL);

       Sleep(1500);

// ֹͣ���Ų��ر�����
           mciSendString("stop mymusic", NULL, 0, NULL);
           mciSendString("close mymusic", NULL, 0, NULL);
}

//����ϵͳ����
void pf3()
{
		// ������
    mciSendString("open 3530.mp3 alias mymusic", NULL, 0, NULL);

// ��������
    mciSendString("play mymusic", NULL, 0, NULL);

       Sleep(4000);

// ֹͣ���Ų��ر�����
           mciSendString("stop mymusic", NULL, 0, NULL);
           mciSendString("close mymusic", NULL, 0, NULL);
}

//��¼ʱ��
void time1()
{	
	
	while(sec>60)
	  {
		   minl++;
		   sec=sec-60;
	  }
	   if(minl>60)
	   {
		   hour++;
		   minl=0;
	   }
	   if(hour>24)
		   hour=0;
	   printf("\n\n\n\t\t\t\t��|%02d:%02d:%02d|",hour,minl,sec);
	   printf("\t��������������%d\t����ȷ������%d\n\n",x,c1);
}


/*******************��ӡ����ģ��*************************************/
void cause(int c1,int c2,int all)
{
//	double cpu_time=0.0;
	system("color B4");
	printf("\n\n\n\t\t\t\t�����յ÷֣�%d\t\t",c1*10);
	//printf("��ȷ������%d\t\t",c1);
    printf("���������%d\n",c2);
	if(c1!=0)
	  printf("\t\t\t\t����ȷ�ʣ�%.2f",((c1*10.0)/(all*10))*100);
	else
      printf("\t\t\t\t����ȷ�ʣ�0");
    //calendar_end=time(NULL);
	//end=clock();
	//cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
	//printf("\n\t\t\t\t��CPU��ʱ��%.3lf��\t\t",cpu_time);
	//printf("\n\t\t\t\t�������ʱ��%02d:%02d:%02d\n\n",hour,minl,sec);
	time1();
	if(c1*10==(all*10)&&c1!=0)
		printf("\t\t\t\t�ﱦ��������´μ���Ŭ��Ŷ\n");
	else if(c1*10==0)
		printf("\t\t\t\t�ﱦ��Ӧ��Ŭ����Ŷ\n");
	else
        printf("\t\t\t\t�ﱦ����Ҫ���ģ�����һ����������\n");
	system("pause");
}
//���������1��2
int getnode()
{
	srand(time(NULL));
	return rand()%2+1;
}

//�����ӿ�ʼ
void time_2()
{
	for(sec=1;sec<=3;sec++)
	{
		if(sec==1)
			color(4);
		else if(sec==2)
			color(5);
		else
			color(6);
		printf("\n\n\n\n\t\t\t\t\t\t-*%d",sec);
		Sleep(1000);
		system("cls");
	}
	printf("\n\n\n\n\t\t\t\t\tReady!\n");
	Sleep(800);
	system("cls");
	printf("\n\n\n\n\t\t\t\t\tGo!\n");
	Sleep(800);
	system("cls");
}

//�������ظ�����
void  choice1(int *num)
{
	int w,t;
	int i;
	srand(time(NULL));
	for(i=0;i<k;i++)
		  num[i]=i;
	for(i=0;i<k;i++)
	 {
		  w=rand()%(k-i)+i;
		  t=num[i];
		  num[i]=num[w];
		  num[w]=t;
	}
}

//��¼ʱ��
void timer()
{
	FILE *fp;
	time_t time_str;
	struct tm *time_p;
	time_str=time(&time_str);
	time_p=localtime(&time_str);
	//printf("%d %d %d %d:%d:%d",(time_p->tm_year)+1900,time_p->tm_mon+1,time_p->tm_mday,time_p->tm_hour,time_p->tm_min,time_p->tm_sec);
	if((fp=fopen("time.txt","ab+"))==NULL)
	{
		printf("can't open this file!");
		exit(0);
	}
	 
		fprintf(fp,"%-6d%-4d%-4d%-4d%-4d%-4d%-4d",time_p->tm_year+1900,time_p->tm_mon+1,time_p->tm_mday,time_p->tm_hour,time_p->tm_min,time_p->tm_sec,((c1*10)/(all*10))*100);//��¼��ǰ�û�������ʱ���
	fclose(fp);


}

//����ʱ��
void timer_read()
{
	FILE *fp;
	int t;
	int year=0,mon=0,day=0,hour=0,min=0,sec=0;
	system("color C");
	if((fp=fopen("time.txt","r"))==NULL)
	{
		printf("can't open this file!");
		exit(0);
	}
	color(3);
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��                 �r(���� ��)�q  ��ʷ��¼\n");
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	while(!feof(fp))
	{
		if(fscanf(fp,"%d%d%d%d%d%d%d",&year,&mon,&day,&hour,&min,&sec,&t)!=EOF)
		{
			if(t==100)
				color(1);
			else if(t>=70)
				color(5);
			else if(t>=60)
				color(6);
			else
				color(4);
			  printf("\t\t��������������������������������������������������������������������������������������������\n");
	          printf("\t\t��ʱ�䣺%d.%d.%d %02d:%02d:%02d\t��ȷ�ʣ�%d                                \n",year,mon,day,hour,min,sec,t);  
	          printf("\t\t��������������������������������������������������������������������������������������������\n");
		}
	}
	fclose(fp);
	system("pause");
}




//ѡ������
void choice_3()
{
	
	printf("\n\n\t\t\t\t����������Ҫ��������(1-%d):\n",k);
	setPos(40,7);
    scanf("%d",&all);
	system("cls");
	
}

/******************�ӷ�ģ��*******************************************/
void doAdd(int flag_1)
{
	int a=100,b=1,sum,d,i=1,r;
	int index=0,p=0;
	int num[100],flag=1;
	char sign1='+';
	x=c1=c2=0;
	srand(time(NULL));
	if(flag_1==1)
	   choice_3();
	system("color E4");
	printf("\n\n\t\t\t\t�������ʼ\n\n");
	 time_2();
	start=time(NULL);//��ʼʱ��
	sec=0;
	while(i<=all)
	{
  // ������
    mciSendString("open 3530.mp3 alias mymusic", NULL, 0, NULL);

    // ��������
    mciSendString("play mymusic", NULL, 0, NULL);
		choice1(num);//���������
		p=rand()%(k-1);//�����±������
		a=num[index];
		b=num[p];
       while(a+b>k&&index<k-1)//ʹ�������С��ѡ�����ķ�Χk
	   {
		   	a=num[index];
			p=rand()%(k-1);
		    b=num[p];
		   index++;
		   flag=0;
		   
	   }
	   if(index==k-1&&a+b>k)//����ұ鶼����������¿�ʼѭ��
	   {
		   index=0;
		   continue;
		  
	   }
       d=getnode();
	   sum=a+b;
	    if(!flag_1)//��սʱ������
	   {
		   if(minl==time_1)
		   {
			   color(4);
			    printf("\n\n\t\t\t\t����սʧ�ܣ���\n\n");
			    printf("\n\n\t\t\t\t<1> ����\t<2> �˳�\n");
			    printf("\n\t\t\t\t\t��ѡ��");
		         scanf("%d",&r);
				 if(r==2)
					{
						menu();
						break;
					}
		   }
		}
	   switch(d)
	   {
	      case 1:doAdd1(num,all,a,b,sum,sign1);break;
	      case 2:doSub1(num,all,a,b,sum,sign1);break;
	   }
	  i++;
	  
	  if(flag)
		index++;
	}
	
}
/******************����ģ��*******************************************/
void doSub(int flag_1)
{
	int a=-1,b=0,sum1,d,i=1,r;
	char sign1='-';
	int num[100],index,flag=1,p=0;
	index=0;
	x=c1=c2=0;
	system("color E4");
	start=time(NULL);//��ʼʱ��
	srand(time(NULL));
	if(flag_1==1)
	   choice_3();
	printf("\n\n\t\t\t\t�������ʼ\n\n");
    time_2();
	sec=0;
	start=time(NULL);//��ʼʱ��
	while(i<=all)
	{
			// ������
    mciSendString("open 3530.mp3 alias mymusic", NULL, 0, NULL);

// ��������
    mciSendString("play mymusic", NULL, 0, NULL);
		   choice1(num);
	       a=num[index];
		   	p=rand()%(k-1);
		   b=num[p];	
		while(a<b&&index<k-1)//ʹ���������С��0
		{
			
           a=num[index];
		   p=rand()%(k-1);
		   b=num[p];
		   index++;
		   flag=0;
		}
		 if(index==k-1&&a<b)//����ұ鶼����������¿�ʼѭ��
		 {
			 index=0;
			 continue;
		 }
    sum1=a-b;
	d=getnode();
	if(!flag_1)
	 {
		   if(minl==time_1)
		   {
			    printf("\n\n\t\t\t\t����սʧ��!��(��_��;)�� ��\n\n");
			    printf("\n\n\t\t\t\t<1> ����\t<2> �˳�\n");
			    printf("\n\t\t\t\t\t��ѡ��");
		         scanf("%d",&r);
				 	if(r==2)
					{
						menu();
						break;
					}
		 }
	}
	switch(d)
	{
	   case 1:doAdd1(num,all,a,b,sum1,sign1);break;
	   case 2:doSub1(num,all,a,b,sum1,sign1);break;
	}
	i++;
	if(flag)//����������һ���������������±�index+1
		index++;
	}
	
}
/******************�ڶ����ּӷ�ģ��*******************************************/
void doAdd1(int *num,int all,int a,int b,int sum,char sign1)
{
	int c=0,sum1,i=0;
	char sign='+';
	c=num[i];
	while(sum+c>k)
	{
		if(i==k)//��Ѱ�����е�����û�з������������������������������ͷ��ʼѰ��
		{
			choice1(num);
			i=0;
			continue;
		}
		
      c=num[i++];
	}
	
	sum1=sum+c;
	time1();
	x++;//��������

	printf("\n\t\t\t\t\t<%d> %d%c%d+%d=",x,a,sign1,b,c);
	caculate(all,a,b,c,sum1,sign,sign1);
	
}
/******************�ڶ����ּ���ģ��*******************************************/
void doSub1(int num[],int all,int a,int b,int sum1,char sign1)
{
	int c=0,sum,i=0;
	char sign='-';
	c=num[i];
	while(sum1-c<0)
	{
	
		if(i==k)//��Ѱ�����е�����û�з������������������������������ͷ��ʼѰ��
		 {
			choice1(num);
			i=0;
		}
        c=num[i++];
	}
	sum=sum1-c;
	time1();
	x++;//��������
	printf("\n\t\t\t\t\t<%d> %d%c%d-%d=",x,a,sign1,b,c);//������ʽ
	caculate(all,a,b,c,sum,sign,sign1);
	
}
/*******************�ж�ģ��**********************************************/
void caculate(int all,int a,int b,int c,int sum,char sign,char sign1)
{
	int sum1;
	char i;
	scanf("%d",&sum1);
	if(sum1==0)
	{
		 HideCursor();
		printf("\n\n\t\t\t�Ƿ��˳�����\n");
		printf("\n\t\t\t<1>��\t<2>��\n");
		i=getch();
		if(i==49)
			menu();
	}
	printf("\n");
	
	if(sum==sum1)
	{
	
			// ֹͣ���Ų��ر�����
           mciSendString("stop mymusic", NULL, 0, NULL);
           mciSendString("close mymusic", NULL, 0, NULL);
		   pf2();
		   color(5);
		   printf("\t\t\t\t��ش���ȷ�R��Q\t");
		   Sleep(100);
	
		c1++;
	}
	else 
	{
	
			// ֹͣ���Ų��ر�����
           mciSendString("stop mymusic", NULL, 0, NULL);
           mciSendString("close mymusic", NULL, 0, NULL);
		pf1();
		color(4);
		printf("\t\t\t\t��ش����!(*+�n+*)~@\t");
		 Sleep(100);
	    wrongtext(a,sign1,b,sign,c,sum);
		c2++;
	}
	   end=time(NULL);
	   sec=(int)difftime(end,start);
	system("cls");
	if(all==x)
	cause(c1,c2,all);
	
}
/*******************���Ȿ********************************************/
//���Ᵽ��ģ��
void wrongtext(int a,char a1,int b,char a2,int c,int sum)
{
	FILE *fp;
	char d='=';
	if((fp=fopen("error.txt","a+"))==NULL)
	{
		printf("can't open this file!");
		exit(0);
	}
	fprintf(fp,"%d%c%d%c%d%c%-5d",a,a1,b,a2,c,d,sum);
	fclose(fp);
}

//������ȫ�����浽�ļ���
void wrong_baocun(struct infortxt *head)
{
      FILE *fp;
	struct infortxt *word;
	word=head->next;
	if((fp=fopen("error.txt","w"))==NULL)
	{
		printf("can't open this file!");
		exit(0);
	}
	while(word!=NULL)
	{
			fprintf(fp,"%d%c%d%c%d%c%-5d",word->a,word->a1,word->b,word->a2,word->c,word->a3,word->sum);
			word=word->next;
	}
	fclose(fp);
	system("pause");
	showmenu();
}

//���ļ��ж�������
struct infortxt * wrongread()
{
	 FILE *fp;
	struct infortxt *word,*head=NULL;
   head=(struct infortxt*)malloc(sizeof(struct infortxt));
	memset(head,0,sizeof(struct infortxt));
	if((fp=fopen("error.txt","r"))==NULL)
	{
		printf("can't open this file!");
		exit(0);
	}
	
	while(!feof(fp))
	{	
		word=(struct infortxt*)malloc(sizeof(struct infortxt));
		memset(word,0,sizeof(struct infortxt));
		if(fscanf(fp,"%d%c%d%c%d%c%d",&word->a,&word->a1,&word->b,&word->a2,&word->c,&word->a3,&word->sum)!=EOF)
		{
			word->next=head->next;
			head->next=word;
		}
    	      
	}
	fclose(fp);
	return head;
}
//�鿴����
void wrong_look()
{
     struct infortxt *word,*head=NULL;
	 int i=1;
	 head=wrongread();
	 system("color 5");
	 word=head->next;
	 if(word==NULL)
		 printf("\n\n\t\t\t\t���ڻ�û�д��⣡\n\n");
	 printf("\n\t\t��������������������������������������������������������������������������������������������\n");
	 printf("\t\t��                    ���Ȿ    \n");
	 printf("\t\t��������������������������������������������������������������������������������������������\n");
	 while(word!=NULL)
	 {
		 if(i%2==0)
			 color(3);
		 else
			 color(4);
		 printf("\n\t\t��������������������������������������������������������������������������������������������\n");
	     printf("\t\t��                  <%d> %d%c%d%c%d%c%d      \n",i,word->a,word->a1,word->b,word->a2,word->c,word->a3,word->sum);
	     printf("\t\t��������������������������������������������������������������������������������������������\n");
		 if(i%8==0)
		 {
			 system("pause");
			 system("cls");
			  printf("\n\t\t��������������������������������������������������������������������������������������������\n");
	           printf("\t\t��                    ���Ȿ    \n");
	           printf("\t\t��������������������������������������������������������������������������������������������\n");

			 
		 }
		 i++;
		 word=word->next;
	 }
	 //system("pause");
}

//��ϰ����
void exertise()
{
	system("color 9");
	struct infortxt *word,*head=NULL,*p1;
	int i=1,sum1,row=0;
    head=wrongread();
	word=head;
	start=time(NULL);
	c1=x=0;
	if(word->next==NULL)
		 printf("\n\n\t\t\t\t���ڻ�û�д���!:-P\n\n");
	while(word->next!=NULL)
	 {
		time1();
		x++;
		 printf("\t\t\t\t\t<%d> %d%c%d%c%d%c\n",i,word->next->a,word->next->a1,word->next->b,word->next->a2,word->next->c,word->next->a3);
		 setPos(54,5);
		 //�ƶ����
		 scanf("%d",&sum1);
		 if(sum1==word->next->sum)
		 {
			 color(5);
			 printf("\t\t\t\t\t��ش���ȷ�R��Q\n\n");
			 pf2();
			 //Sleep(1000);
			 c1++; 
			 word=word->next;
		 }
		 else
		 {
			 color(4);
			 printf("\t\t\t\t\t��ش����!(��_��)\n\n");
			 pf1();
			 //Sleep(1000);
			 p1=word->next;
			 word->next=word->next->next;
			 free(p1);
		 }
		end=time(NULL);
	   sec=(int)difftime(end,start);
	   system("cls");
		 i++;//�������
		
	 }
	system("color B5");
	printf("\n\n\n\t\t\t\t��������������������\n");
	printf("\t\t\t\t������������%d\t������������%d      ��\n",c1,x-c1);
	printf("\t\t\t\t��������������������\n");
	wrong_baocun(head);

}




//��ս����
void jump()
{
	if(minl<time_1&&c1==all)
		printf("\t\t\t\t\t��ս�ɹ���\n");
	 else 
         printf("\t\t\t\t\t���ź�����սʧ�ܣ�\n");
}

void tshi_1()
{
	system("color 81");
	printf("\t\t\t\t\t======================\n");
	printf("\t\t\t\t\t[����%d���������%d����]\n\n",time_1,all);
	printf("\t\t\t\t\t======================\n\n");
	Sleep(2000);
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t���Ͽ�ʼ���⣺\n\n");
}


//��ս����--�Ե�һ���ֵ�ѡ��
void choice_2(int age)
{
	int d;
	double timer=0.0;
	d=getnode();
	system("cls");
	switch(d)
	{
	         case 1:
				    tshi_1(); 
				    doAdd(0);
			    //	calendar_end=time(NULL);
			    	//timer=difftime(end,start)/60.0;
				    jump();
					break;
	         case 2:tshi_1();
				    doSub(0);
					//calendar_end=time(NULL);
				    //timer=difftime(end,start)/60.0;
				   jump();
					break;
	}
				  
}
//��սģ��
void challeng()
{
	char age;
	system("color 4");
	printf("                       +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
	printf("                       |��ܰ��ʾ��                                               |\n");
	printf("                       |  ��������ȷ������,Խ�����Ѷ�Խ�ߣ����벻ͬ����սģ��    |\n");
    printf("                       +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n\n\n");
	color(2);
	printf("\t\t\t[     ��ͭ   1         ]\n");
	printf("\n\n");
	color(3);
	printf("\t\t\t[     ����   2         ]\n");
	printf("\n\n");
	color(4);
	printf("\t\t\t[     �ƽ�   3         ]\n");
	printf("\n\n");
	color(5);
	printf("\t\t\t[     ��ʯ   4         ]\n");
	printf("\n\n");
	color(6);
	printf("\t\t\t[     ����   5         ]\n");
	printf("\n\n");
	printf("\t\t\t��ѡ��Ҫ��ս�ĵȼ���\n");
    age=getch();
	switch(age)
	   {
        	case 49:time_1=10;k=20;all=10;choice_2(age);break;
	        case 50:time_1=8;k=40;all=15;choice_2(age);break;
			case 51:time_1=6;k=60;all=20;choice_2(age);break;
			case 52:time_1=4;k=80;all=25;choice_2(age);break;
			case 53:time_1=2;k=100;all=30;choice_2(age);break;
			default:menu();break;
			
	   }
	system("cls");

}

void tshi()
{
	printf("\n\n\n");
	printf("\t\t\t\t==================================================================== \n");
	printf("\t\t\t\t|��ܰ��ʾ��(��(��)��)                                               |\n");
	printf("\t\t\t\t|  �ڲ������������������֣���0�˳�����                              |\n");
    printf("\t\t\t\t|�������룬���ܻ�������벻��������                                 |\n");
    printf("\t\t\t\t====================================================================\n");
	printf("\n\n\n\t\t\t\t\t              ------ָ����ʦ������");
	printf("\n");
	//Sleep(3000);
}

/*******************���˵�********************************************/
void showmenu()
{
	printf("                           ===============================================================\n");
	printf("\n");
	printf("                                      ||||||��ӭ����Сѧ��100������λ�����Ӽ���|||||\n");
    printf("\n");
    printf("                           ===============================================================\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                           �����������������������������������������������\n");
	printf("                                            ����ϰģ��   1 \n");
	printf("\n");
	printf("                                            ������ģ��   2 \n");
	printf("\n");
	printf("                                            ����սģ��   3 \n");
	printf("\n");
	printf("                                            ���޾�ģ��   4 \n");
	printf("\n");
	printf("                                            ����ʷ��¼   5 \n");
	printf("                           �����������������������������������������������\n");
	printf("\n");
	//printf("��ѡ��\n");
}

//�˳�ģ��
void sysExit()
{
	printf("�ټ�����baby\n");
}

//����Ŀ¼
void wrongmenu()
{
	 char i;
     system("color B6");                    
     printf("\n\n\n\t\t\t\t            (oo) \n\n");
     printf("\t\t\t\t   /-------\\/�� 1 �������\n\n"); 
     printf("\t\t\t\t / |         || \n\n"); 
     printf("\t\t\t*    ||----||      �� 2 ��ϰ����\n\n");
     printf("\t\t\t\t     ~~    ~~  \n\n");
	  printf("\t\t\t\t��ѡ��");
	  setPos(35,16);
	i=getch();
	system("cls");
    switch(i)
	 {
        	case 49:wrong_look();
				   break;
	            	
	        case 50:exertise();break;
			default:menu();break;
	}
}

//ѡ��ģ��
int getchoice()
{
	int d;
    scanf("%d",&d);
	fflush(stdin);
	return d;
}


void choose()
{
	
	printf("\n\n\t\t\t\t����������Ҫ����Ĵ�С��Χ(1-100)��\n");
	setPos(40,3);
	scanf("%d",&k);
}

//�߳�����
/* int in_gore(void *pdata)
{
	 int hour = 0, min = 0, sec = 0;
    while (1)
	{
        Sleep(1000);//��ͣ1s
        system("cls");//����
        sec++;
        if (sec == 60){
            min++;
            sec = 0;
        }
        if (min == 60){
            hour++;
            min = 0;
        }
        if (hour == 24){
            hour = 0;
        }
        printf("%02d:%02d:%02d\n", hour, min, sec);
        //%02d�������Ϊ2������2ǰ�油0
    }
    return 0;
}*/



//���˵�
void menu()
{
	int d;
	char choice;
    all=x=0;
	system("color B2");
    system("cls");
	while(1)
	{
		
		//calendar_start=time(NULL);//�û���ʼʱ��
		k=0;
		//start=clock();//����������ʱ��
		system("cls");
		system("color B5");
		showmenu();
	  choice=getch();
	  system("cls");
       switch(choice)
	   {
        	case 49:
				choose();
				d=getnode();
                   switch(d)
				   {
	                    case 1:doAdd(1);break;
	                    case 2:doSub(1);break;
				   };
				   break;
	            	
	        case 50:wrongmenu();break;
			case 51:challeng();break;
			case 52:
				k=100;
				all=10000000;
				d=getnode();
                switch(d)
				 {
	                    case 1:doAdd(4);break;
	                    case 2:doSub(4);break;
				 };
				break;
			case 53:timer_read();break;
			default:menu();break;
			
	   }
     if(choice!=5)
	   timer();//��¼ʱ��
	}


}
void main()
{
	int i;
	tshi();
//	pf();
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
	menu();
	system("pause");
}



