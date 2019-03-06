#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>

time_t start,end;
int hour = 0, minl = 0, sec = 0,time_1=0,end_1=0;//ʱ��
int c1=0;

void recite(char word[],int flag);//��ӡ����
void menu();//���˵�
void display();//��ӡ���

static void setPos(int x,int y)
{

   COORD point = {x,y};//���Ҫ���õ�λ��x,y
   HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
   SetConsoleCursorPosition(HOutput, point);//���ù��λ��
}



//��ӡ����
void look(char *st,int flag)
{
	FILE *fp;
	char word[100];
	int i=0;
	memset(word,0,sizeof(char)*100);
	if((fp=fopen(st,"r+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
	while(i<100)
	{
		if(fscanf(fp,"%c",word+i)!=EOF)
		{
			i++;
		}
	}
	fclose(fp);
    recite(word,flag);
}









//����ģ��
void recite(char word[],int flag)
{
    char word_1[100];
	int i=0,row=0,r=0,k,col=0;
	c1=0;
	memset(word_1,0,sizeof(char)*100);
	start=time(NULL);
    for(sec=1;sec<=3;sec++)
	{
		printf("\t\t\t\t%d",sec);
		Sleep(1000);
		system("cls");
	}
   printf("\t\t\t\t�����ڿ�ʼ\n\n");
	system("cls");//����
	sec=start;
	printf("\n\n\t\t\t\t");
	sec=0;
	for(i=0;i<100;i++)
	{
		if(sec==60)
		{
			minl++;
			sec=0;
		}
		if(minl==60)
		{
			minl=0;
			hour++;
		}
		if(hour==24)
			hour=0; 
       printf("\t\t�����ʱ��%02d:%02d:%02d   \t",hour, minl, sec);//%02d�������Ϊ2������2ǰ�油0
	   	printf("�����ȷ��:%.3f\t�������%.3f\n",(c1/100)*100,(i/100)*100);
	   if(!flag)
	   {
		   if(minl==time_1)
		   {
			    printf("\n\n\t\t\t\t��սʧ�ܣ�\n\n");
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
	   printf("\t\t\t\t");
	   for(k=0;k<100;k++)
	   {
	    	printf("%c",word[k]);
		    if(k%25==0)
			  printf("\n\n\t\t\t\t");
	   }
       for(k=0;k<i;k++)
	   {
	    	printf("%c",word_1[k]);
		    if(k%25==0)
			  printf("\n\n\t\t\t\t");
	   }

	   setPos(27+row,4+col);
	   col+=1;
	   scanf("%c",word_1+i);
	   if(i%25==0)
	   {
		   printf("\n");
		   row+=1;
	   }
		if(word[i]==word_1[i])
		{
			c1++;
		}
		end=time(NULL);
		end_1=sec=(int)difftime(end,start);
		system("cls");
	}
	display();
}


	
//��ӡ����ģ��
void display()
{
	
	printf("\t\t\t\t\t�����ȷ��:%.3f\n",(c1/100)*100);
	printf("\t\t\t\t\t�����ʱ��\n");
	printf("\t\t\t\t\t\t__________________\n");
    printf("\t\t\t\t\t\t%02d:%02d:%02d   \n",hour, minl, sec);//%02d�������Ϊ2������2ǰ�油0
    printf("\t\t\t\t\t\t_________________\n\n");
    if(c1==100)
		printf("\t\t\t\t\t������Ѵﵽ10�������");
	else
		printf("\t\t\t\t\t���baby,��Ҫ����Ŭ��Ŷ!���\n");
}

 

//���ֽ���������ļ���
void wrongtxt(char word_2[])
{
	FILE *fp;
	int i=0;
	if((fp=fopen("���ֽ��.txt","a+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
	while(i<100)
	{
		fprintf(fp,"%c",word_2[i]);
		i++;
	}
	fclose(fp);
}


   
//����ѡ��������ĵ����£�ѡ��ͬ�ļ�
void ch_1(int no,int flag)
{
	char *str;
	printf("\t\t\t\t��ս���Ͽ�ʼ��\n\n");
	switch(no)
	{
    	case 1:str="word1.txt";look(str, flag);break;
		case 2:str="word2.txt";look(str, flag);break;
		case 3:str="word3.txt";look(str, flag);break;
		case 4:str="word4.txt";look(str, flag);break;
		case 5:str="word5.txt";look(str, flag);break;
		case 6:str="word6.txt";look(str, flag);break;
	}
	

}

//����ѡ��Ӣ�ĵ����£�ѡ��ͬ�ļ�
void ch_2(int no,int flag)
{
	char *str;
	printf("\t\t\t\t��ս���Ͽ�ʼ��\n\n");
	switch(no)
	{
    	case 1:str="eword1.txt";look(str, flag);break;
		case 2:str="eword2.txt";look(str, flag);break;
		case 3:str="eword3.txt";look(str, flag);break;
		case 4:str="eword4.txt";look(str, flag);break;
		case 5:str="eword5.txt";look(str, flag);break;
		case 6:str="eword6.txt";look(str, flag);break;
	}
	

}

//����Ŀ¼
void chin_menu()
{
	int i;
	printf("\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x\n\n");
	printf("\t\t\t\t��       1 û�бȽŸ�����·           ��\n\n");
	printf("\t\t\t\t��       2 Ե����                   ��\n\n");
	printf("\t\t\t\t��       3 ���;���                   ��\n\n");
	printf("\t\t\t\t��       4 ����,����                  ��\n\n");
	printf("\t\t\t\t��       5 �������������             ��\n\n");
	printf("\t\t\t\t��       6 ��������                   ��\n\n");
	printf("\t\t\t\t��������������������������������������  \n\n");
	printf("\t\t\t\t��ѡ�����£�");
	scanf("%d",&i);
	ch_1(i,1);
}
//Ӣ��Ŀ¼
void eng_menu()
{
	int i;
	printf("\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x\n\n");
	printf("\t\t\t\t��       1 ��ͭ           ��\n\n");
	printf("\t\t\t\t��       2 ����           ��\n\n");
	printf("\t\t\t\t��       3 �ƽ�           ��\n\n");
	printf("\t\t\t\t��       4 ����           ��\n\n");
	printf("\t\t\t\t��       5 ��ʯ           ��\n\n");
	printf("\t\t\t\t��       6 �ƽ�           ��\n\n");
	printf("\t\t\t\t��������������������������\n\n");
	printf("\t\t\t\t��ѡ�����£�");
	scanf("%d",&i);
	ch_2(i,1);
}



//��ս����
void jump()
{
	if(minl<time_1&&c1==100)
				  printf("\t\t\t\t\t�����ս�ɹ����\n");
    else 
                  printf("\t\t\t\t\t������ź�����սʧ�ܣ����\n");
}


//��սģ��
void challeng()
{
	int i,choice1;
    printf("\t\t\t\t_____________________________________________________________________\n");
	printf("\t\t\t\t|   ��ܰ��ʾ����ѡ��ͬ�ĵȼ����ڹ涨��ʱ����ȫ����ӡ�꣬���������� |\n");
	printf("\t\t\t\t|             ���иı����뷨,Խ�����Ѷ�Խ��                          |\n");
	printf("\t\t\t\t|____________________________________________________________________|\n\n\n");
	printf("\t\t\t\t�����ӭ������սģ�飬ף�����!���\n\n");

	printf("\t\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x \n\n");
	printf("\t\t\t\t\t��   1   ƴ������              ��\n\n");
	printf("\t\t\t\t\t��   2   Ӣ�����              ��\n\n");
	printf("\t\t\t\t\t�������������������������������� \n\n");
	printf("\t\t\t\t��ѡ��\n");
	scanf("%d",&choice1);	
	printf("\n\n\t\t\t\t��������Ҫ��ս�ķ�������");
	scanf("%d",&time_1);
	switch(choice1)
	{
    	case 1:chin_menu();break;
		case 2: eng_menu();break;
		default:menu();break;
	}
	switch(choice1)
	{
    	case 1:ch_1(i,0);break;
		case 2:ch_2(i,0);break;
	}
	
    jump();

}


//ѡ��ģ��
void getchoice()
{
	printf("\t\t\t\t\t���������������������\n\n");
	printf("\t\t\t\t\t��   1 ���ģʽ           ��\n\n");
    printf("\t\t\t\t\t��   2 ѡ��ģʽ           ��\n\n");
	printf("\t\t\t\t\t��   3 ��սģʽ           ��\n\n");
	printf("\t\t\t\t\t��   0 �˳�               ��\n\n");
	printf("\t\t\t\t\t���������������������\n\n\n");
	printf("\t\t\t\t\t��ѡ��\n");
}

//ѡ������
void choose(int choice1)
{
	switch(choice1)
		{
		           case 1:chin_menu();break;
		           case 2:eng_menu();break;
	 }
}

//���˵�
void menu()
{
	int choice,choice1,N;
	srand(time(NULL));
	printf("\n\n\n\n\t\t\t������������������������������������������������������������������������������\n");
	printf("\t\t\t��                           ��ӭ������ֳ���                             ��\n");
	printf("\t\t\t������������������������������������������������������������������������������\n\n\n");
	printf("\t\t\t\t���ѧϰʹ����֣�������һ�����ѧϰ�ɣ����                \n\n\n");
	getchoice();//ѡ��ģ��
	scanf("%d",&choice1);
	system("cls");
	printf("\t\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x\n\n");
	printf("\t\t\t\t\t��   1   ƴ������              ��\n\n");
	printf("\t\t\t\t\t��   2   Ӣ�����              ��\n\n");
	printf("\t\t\t\t\t��������������������������������\n\n");
	printf("\t\t\t\t��ѡ��\n");
	scanf("%d",&choice);
	system("cls");
	switch(choice1)
	{
    	case 1:N=rand()%6;
			switch(choice)
			{
            	case 1:ch_1(N,1);break;
	        	case 2:ch_2(N,1);break;
			}
			break;
		case 2:choose(choice);
		case 3:challeng();break;
		default:menu();break;
	}
}

void tshi()
{
	printf("\t\t\t\t_____________________________________________________________________\n");
	printf("\t\t\t\t|   ��ܰ��ʾ���ڲ����а�0�ص����˵���������ȷ�����ֽ�����Ӧ�ĳ���    |\n");
	printf("\t\t\t\t|              ���뵥�ʺ�enter������                               |\n");
	printf("\t\t\t\t|____________________________________________________________________|\n\n\n");
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
	system("color 0C");
	tshi();
	menu();
}


