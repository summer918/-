#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>

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
void ch(int no,int N,int flag);//���ݲ�ͬ�꼶��ѡ��ͬ�ļ�
void ch1(int no);//���ݲ�ͬ�꼶��ѡ��ͬ�ļ����
void jump();
void challeng(int choice,int N);//��սģ��
void wrongtxt(struct studentread *head);//���Ᵽ�浽�ļ�
struct studentread * wrongread();//��������


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


//ѡ������
void choose()
{
	
	printf("\t\t\t\t\t\n\n\n��������Ҫ���ĵ�����(1-20)��\n");
	setPos(20,10);
	scanf("%d",&num);
	
}

//�������
void look(char *st)
{
	FILE *fp;
	char word[1024];
	memset(word,0,sizeof(char)*1024);
	if((fp=fopen(st,"r+"))==NULL)
	{
		printf("can't open this file\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fscanf(fp,"%s",word)!=EOF)
		        printf("\t\t\t\t��%s\n",word);
	}
	fclose(fp);
}







//���ļ��ж�������ģ�鲢��������
void read(char *str,int N,int flag)
{
	FILE *fp;
	int i=1;
//	thrd_t p_id;
//	struct mydata data={.hour=0,.min=0,.sec=0};
	struct studentread *p1,*head=(struct studentread *)malloc(sizeof(struct studentread));
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



//������ģ��
void recite(struct studentread *head,int N,int flag)
{
	int i=0,min,n=0,max;
	//mydata *pd=(mydata*)pdata;
	int r=0,c1=0;
	//double cpu_time;
	char string[200];
	struct studentread *p=head->next,*h_d=NULL;
	memset(string,0,sizeof(char)*200);
    hour=minl=sec=0;
	//thrd_join(pd->id,&result);
	if(flag)
	   choose();
	srand(time(NULL));
	i=rand()%(N/2-k)+1;
	k++;
	if(N==k)
		k=0;//�Է�k>N
	score=num;
	for(min=0;min<N-i;min++)
	{
		if(p!=NULL)
		  p=p->next;
		
	}
	h_d=p;
	max=strlen(p->word);
	printf("\n\n\t\t\t\t�������ʼ\n\n");
	start=time(NULL);
    Sleep(3000);
   printf("\t\t\t\t�����ڿ�ʼ\n\n");
	system("cls");//����
	sec=3;
//	thrd_join(id,NULL);
	for(min=N-i;min<N-i+num;min++)
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
	   printf("\t\t\t\t��|%02d:%02d:%02d|",hour,minl,sec);
	   printf("\t���ѱ�����������%d\t��ȷ������%d",n,c1);
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

		printf("\n\n\n\t\t\t\t�����ģ�%s\n",p->ch);
		printf("\t\t\t\t��������Ӣ��:");
		scanf("%s",string);
		if(strcmp(string,"0")==0)
		{
			printf("\n\n\n\t\t\t\tѧϰ��Ҫ��֣�\n\n");
			menu();
			//break;
		}
		if(strcmp(string,p->word)==0)
		{
			printf("\t\t\t\t��ش���ȷ��\n");
			c1++;
		}
		else
		{
			wrongtxt(p);
			printf("\t\t\t\t��ش����!\n");
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
	if(flag)//��ͨ��ϰģ��Ĳ���
	{
		printf("\t\t\t\t\t��������������¸�ϰһ��ɣ�\n");
    	for(i=0;i<num;i++)
		{
		printf("\t\t\t\t\t________________________________\n");
		printf("\t\t\t\t\t       %s               \t\t\t\n",h_d->word);
		printf("\t\t\t\t\t________________________________\t\t\t\n");
		printf("\t\t\t\t\t<1> ��ʶ\t<2> ����ʶ");
		printf("\n\t\t\t\t\t��ѡ��");
		scanf("%d",&r);
		if(r==1)
		     h_d=h_d->next;
		else
		{
			printf("\t\t\t\t\t�����ģ�%s",h_d->ch);
		    h_d=h_d->next;
		}
		
		}
	}
	printf("\n\n\n");
	num=0;//�Ա��´δ�0��ʼ
	
}


	
//��ӡ����ģ��
void display()
{
	printf("\t\t\t\t\t����ܷ�:%.0f\n",score);
	if(score!=0)
	    printf("\t\t\t\t\t�����ȷ��:%.3f\n",(score/num*1.0)*100);
	else
	    printf("\t\t\t\t\t�����ȷ��:0.00\n");
	printf("\t\t\t\t\t�����ʱ��\n");
	printf("\t\t\t\t\t\t__________________\n");
    printf("\t\t\t\t\t\t%02d:%02d:%02d   \n",hour, minl, sec);//%02d�������Ϊ2������2ǰ�油0
    printf("\t\t\t\t\t\t_________________\n\n");
    if(num==score)
		printf("\t\t\t\t\t���baby�����!���\n");
	else
		printf("\t\t\t\t\t���baby,��Ҫ����Ŭ��Ŷ!���\n");
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
	if((fp=fopen("wrong.txt","w"))==NULL)
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

//�������
void liulan()
{
	struct studentread *p,*head=NULL;
	head=wrongread();
	p=head->next;
	while(p!=NULL)
	{
		printf("\t\t\t\t\t���������������������\n");
		printf("\t\t\t\t\t���Ӣ�ģ�%s                        ���\n",p->word);
		printf("\t\t\t\t\t������ģ�%s                        ���\n",p->ch);
		printf("\t\t\t\t\t���������������������\n\n\n");
		p=p->next;
	}
}

//��ϰ����
void lianxi()
{
		struct studentread *p,*head=NULL,*p1;
		char word[20];
		int i=0,l=0;
		head=wrongread();
		p=head->next->next;
		while(p!=NULL)
		{
			printf("\t\t\t\t|���ģ�%s\n\n",p->ch);
			printf("\t\t\t\t|Ӣ�ģ�");
			gets(word);
			if(strcmp(word,"0")==0)
			{
			printf("\n\n\n\t\t\t\tѧϰ��Ҫ��֣�\n\n");
			menu();
			break;
			}
			if(strcmp(word,p->word)==0)
			{
				printf("\n\n\t\t\t\t��ش���ȷ��\n");
				i++;
			}
			else
			{
				printf("\n\n\t\t\t\t��ش����\n");
				p1=p->next;
				free(p);
				p=p1;
				l++;
			}
			p=p->next;
		}
		
		printf("\n\n\t\t\t\t���_____________________________���\n");
		printf("\n\n\t\t\t\t������𵥴ʣ�%d |�����𵥴ʣ�%d ���\n",i,l);
		printf("\n\n\t\t\t\t���_____________________________���\n\n");
		wrong_baocun(head);
}


   
//���ݲ�ͬ�꼶��ѡ��ͬ�ļ�
void ch(int no,int N,int flag)
{
	char *str;
	switch(no)
	{
    	case 1:str="word1.txt";num=20;read(str,N,flag);break;
		case 2:str="word2.txt";num=30;read(str,N,flag);break;
		case 3:str="word3.txt";num=40;read(str,N,flag);break;
		case 4:str="word4.txt";num=60;read(str,N,flag);break;
		case 5:str="word5.txt";num=80;read(str,N,flag);break;
		case 6:str="word6.txt";num=100;read(str,N,flag);break;
	}
	

}

//���ݲ�ͬ�꼶��ѡ��ͬ�ļ����
void ch1(int no)
{
	char *str;
	switch(no)
	{
    	case 1:str="word1.txt";look(str);break;
		case 2:str="word2.txt";look(str);break;
		case 3:str="word3.txt";look(str);break;
		case 4:str="word4.txt";look(str);break;
		case 5:str="word5.txt";look(str);break;
		case 6:str="word6.txt";look(str);break;
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
void challeng(int choice1,int N)
{
	int i;
    printf("\t\t\t\t_____________________________________________________________________\n");
	printf("\t\t\t\t|   ��ܰ��ʾ����ѡ��ͬ�ĵȼ����ڹ涨��ʱ���н���ȫ�����           |\n");
	printf("\t\t\t\t|____________________________________________________________________|\n\n\n");
	printf("\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x\n\n");
	printf("\t\t\t\t��       1 ��ͭ           ��\n\n");
	printf("\t\t\t\t��       2 ����           ��\n\n");
	printf("\t\t\t\t��       3 �ƽ�           ��\n\n");
	printf("\t\t\t\t��       4 ����           ��\n\n");
	printf("\t\t\t\t��       5 ��ʯ           ��\n\n");
	printf("\t\t\t\t��       6 �ƽ�           ��\n\n");
	printf("\t\t\t\t��������������������������\n\n");
	printf("\t\t\t\t�����ӭ������սģ�飬ף�����!���\n\n");
	printf("\t\t\t\t��ѡ��");
	scanf("%d",&i);
	switch(i)
	{
	  case 1:time_1=7;break;
      case 2:time_1=6;break;
	  case 3:time_1=5;break;
	  case 4:time_1=4;break;
	  case 5:time_1=3;break;
	  case 6:time_1=2;break;
	  default:printf("\t\t\t\t��������ȷ����ţ�\n\n");
	}
	printf("\t\t\t\t��ս���Ͽ�ʼ��\n\n");
	ch(choice1,i,0);
    jump();

}

//����Ŀ¼
void wrongmenu()
{
	int i;
	printf("\t\t\t\t\t                          --------------------\n");
	printf("\t\t\t\t\t                              1 �������\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t                              2 ��ϰ����\n");
	printf("\t\t\t\t\t                          --------------------\n\n\n");
	printf("\t\t\t\t��ѡ��");
	scanf("%d",&i);
	system("cls");
    switch(i)
	 {
        	case 1:liulan();
				   break;
	            	
	        case 2:lianxi();break;
			default:menu();break;
	}
}


//ѡ��ģ��
void getchoice()
{
	printf("\t\t\t\t\t������������������\n");
	printf("\t\t\t\t\t��1 ������ģʽ        ��\n\n");
    printf("\t\t\t\t\t��2 ����ģʽ          ��\n\n");
	printf("\t\t\t\t\t��3 �������          ��\n\n");
	printf("\t\t\t\t\t��4 ��սģʽ          ��\n\n");
	printf("\t\t\t\t\t��0 �˳�              ��\n\n");
	printf("\t\t\t\t\t������������������\n\n\n");
	printf("\t\t\t\t\t��ѡ��\n");
}

//�˳�ģ��
void leave()
{
	printf("\t\t\t\t\t�����С���ˣ������������ӭ�´���ѧϰ�������\n\n\n\n");
}
//���˵�
void menu()
{
	int choice,choice1,N;
	printf("\n\n\n\n\t\t\t������������������������������������������������������������������������������\n");
	printf("\t\t\t��                           ��ӭ���뱳���ʳ���                             ��\n");
	printf("\t\t\t������������������������������������������������������������������������������\n\n\n");
	printf("\t\t\t\t���ѧϰʹ����֣�������һ�����ѧϰ�ɣ����                \n");
	printf("\t\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x\n\n");
	printf("\t\t\t\t\t��   1   Сѧ              ��\n\n");
	printf("\t\t\t\t\t��   2   ����              ��\n\n");
	printf("\t\t\t\t\t��   3   ����              ��\n\n");
	printf("\t\t\t\t\t��   4   �ļ�              ��\n\n");
	printf("\t\t\t\t\t��   5   ����              ��\n\n");
	printf("\t\t\t\t\t��   6   �˼�              ��\n\n");
	printf("\t\t\t\t\t��������������������������\n\n");
	printf("\t\t\t\t��ѡ������꼶��\n");
	setPos(34,33);
	scanf("%d",&choice1);
	switch(choice1)
	{
    	case 1:N=100;break;
		case 2:N=1300;break;
		case 3:N=3500;break;
		case 4:N=350;break;
		case 5:N=350;break;
		case 6:N=350;break;
		default:menu();break;
	}
	system("cls");
	while(1)
	{
    getchoice();
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	case 1: ch(choice1,N,1);break;
	case 2: wrongmenu();break;
	case 3: ch1(choice1);break;
	case 4:challeng(choice1,N);break;
	case 0: leave();break;
    default:menu();break;
	}
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


