#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>

time_t start,end;
int hour = 0, minl = 0, sec = 0,time_1=0,end_1=0;//ʱ��
int c1=0;

void recite(char word[4][26],int flag);//��ӡ����
void menu();//���˵�
void display1();//��ӡ���
void main();

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


void time1()
{
		while(sec>60)
		{
			minl++;
			sec=sec-60;
		}
		if(minl==60)
		{
			minl=0;
			hour++;
		}
		if(hour==24)
			hour=0; 
}
//��ӡ����
void look(char *st,int flag)
{
	FILE *fp;
	char word[4][26];
	int col=0,row=0;
	memset(word,0,sizeof(char)*4*26);
	if((fp=fopen(st,"r+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
	while(row<4)
	{
		for(col=0;col<25;col++)
		{
			if(fscanf(fp,"%c",&word[row][col])!=EOF)
			{}
		}
		row++;
	}
	fclose(fp);
    recite(word,flag);
}
//ģ����ʽ
void zuanshi(char word[][26])
{
	int i=0;
	printf("\n\n\n");
	printf("\t\t\t       ������������������������������������������������������������������������������\n");
	printf("\t\t\t       ��      ��ɽ����ͨ                     �� \n");
	printf("\t\t\t       ������������������������������������������������������������������������������\n");
	for(i=0;i<4;i++)
	{
	printf("\t\t\t       ������������������������������������������������������������������������������\n");
	printf("\t\t\t       ��%s                          \n",word[i]);
	printf("\t\t\t       ������������������������������������������������������������������������������\n");
	printf("\t\t\t       ������������������������������������������������������������������������������\n");
	printf("\t\t\t       ��                            \n");
	printf("\t\t\t       ������������������������������������������������������������������������������\n");
	}
	
	
	

	
	
	
}







//����ģ��
void recite(char word[4][26],int flag)
{
    char word_1[25][26];
	int k=0,row=0,r=1,col=0,h=0;
	c1=0;
	memset(word_1,0,sizeof(char)*100);
	for(sec=1;sec<=3;sec++)
	{
		printf("\t\t\t\t%d",sec);
		Sleep(1000);
		system("cls");
	}
   printf("\t\t\t\t�����ڿ�ʼ\n\n");
	system("cls");//����	
	start=time(NULL);
	sec=hour=minl=0;
	col=0;
	zuanshi(word);
	for(k=0;k<4;k++)
	{
			setPos(20,9+h);
			h+=6;
	   if(!flag)
	   {
		   if(minl==time_1)
		   {
			   system("cls");
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
	   printf("\n\t\t\t\t");
		        
	   for(col=0;col<25;col++,row++)
	   {
		 
		   scanf("%c",&word_1[k][col]);
		   if(word[k][col]==word_1[k][col])
		   {   color(2);
			   c1++;
		   }
		   else
			   color(4);
	   }
		
		end=time(NULL);
	    sec=(int)difftime(end,start);
		
	}
	system("cls");
	display1();

}


	
//��ӡ����ģ��
void display1()
{
	
	printf("\n\n\n\t\t\t\t\t�����ȷ��:%.3f\n",(c1/100.0)*100);
	printf("\t\t\t\t\t�����ʱ��\n");
	time1();
	printf("\t\t\t\t\t\t__________________\n");
    printf("\t\t\t\t\t\t%02d:%02d:%02d   \n",hour, minl, sec);//%02d�������Ϊ2������2ǰ�油0
    printf("\t\t\t\t\t\t_________________\n\n");
    if(c1==100)
		printf("\t\t\t\t\t������Ѵﵽ10�������");
	else
		printf("\t\t\t\t\t���baby,��Ҫ����Ŭ��Ŷ!���\n");
	system("pause");
    //system("cls");
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
	case 1:{str="word_1.txt";look(str,flag);break;}
	case 2:{str="word2.txt";look(str,flag);break;}
	case 3:{str="word3.txt";look(str,flag);break;}
	case 4:{str="word4.txt";look(str,flag);break;}
	case 5:{str="word5.txt";look(str,flag);break;}
	case 6:{str="word6.txt";look(str,flag);break;}
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

void tshi_2()
{
	printf("\t\t\t\t_____________________________________________________________________\n");
	printf("\t\t\t\t|   ��ܰ��ʾ������������                                             |\n");
	printf("\t\t\t\t|             ���иı����뷨,Խ�����Ѷ�Խ��                          |\n");
	printf("\t\t\t\t|____________________________________________________________________|\n\n\n");
}
//����Ŀ¼
void chin_menu()
{
	int i;
	tshi_2();
	Sleep(3000);
	system("cls");
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
	printf("\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x\n\n");
	printf("\t\t\t\t��       1  Success                     ��\n\n");
	printf("\t\t\t\t��       2  Love                        ��\n\n");
	printf("\t\t\t\t��       3  A Beautiful Flower          ��\n\n");
	printf("\t\t\t\t��       4  Spirit                      ��\n\n");
	printf("\t\t\t\t��       5  A Wild Guess                ��\n\n");
	printf("\t\t\t\t��       6  TO Borrow an Ox             ��\n\n");
	printf("\t\t\t\t����������������������������������������\n\n");
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
	int choice1;
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
	fflush(stdin);
	scanf("%d",&choice1);
	system("cls");
	printf("\n\n\t\t\t\t��������Ҫ��ս�ķ�����(����)��");
	scanf("%d",&time_1);
	system("cls");
	switch(choice1)
	{
    	case 1:chin_menu();break;
		case 2: eng_menu();break;
		default:menu();break;
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
	fflush(stdin);
}

//ѡ������
void choose(int  choice1)
{
	switch(choice1)
	{
		           case 1:chin_menu();break;
		           case 2:eng_menu();break;
				   default:menu();break;
	}
}

//���˵�
void menu()
{
	int N;
	int  choice,choice1;
	srand(time(NULL));
	while(1)
	{
	printf("\n\n\n\n\t\t\t������������������������������������������������������������������������������\n");
	printf("\t\t\t��                           ��ӭ������ֳ���                               ��\n");
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
	fflush(stdin);
	scanf("%d",&choice);
	system("cls");
	switch(choice1)
	{
	      case 1:{
		           N=rand()%6;
			     switch(choice)
				 {
            	      case 1:ch_1(N,1);break;
	        	      case 2:ch_2(N,1);break;
				 };
			        
				   }break;
		case 2:choose(choice);break;
		case 3:challeng();break;
		default:main();break;
	}
	system("cls");
	}
		
	
	
}

void tshi()
{
	printf("\n\n\n\n\t\t\t\t_____________________________________________________________________\n");
	printf("\t\t\t\t|   ��ܰ��ʾ���ڲ����а�0�ص����˵���������ȷ�����ֽ�����Ӧ�ĳ���    |\n");
	printf("\t\t\t\t|              ���뵥�ʺ�enter������                               |\n");
	printf("\t\t\t\t|____________________________________________________________________|\n");
	printf("\n\n\n\n\t\t\t\t\t\t----------ָ����ʦ������");
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
	
	Sleep(1000);
	system("cls");
	menu();
}


