#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int flag=0,x=0,book=0,m=1;// m ��¼���߱��//�����
char zh[13],cod[13],code[13];//����
int number;//�ѽ�������
int choice;
//ͼ����Ϣ����
struct admin
{
	int no;//ͼ����
	char book[30];//����
	char edname[20];//������
	char no1;//�����
	char pub[40];//���浥λ
	char time[20];//����ʱ��
	int num;//�������
	int price;//�۸�
	struct admin *next;
};
//������Ϣ����
struct reader
{
	int num;//���
	char num1[20];//���ĺ�
    char name[20];//����
	int max;//�����Ķ��
	int num2;//�ѽ�������
	char code[12];//��������
	struct reader *next;
};
//����Ա��Ϣ��¼
struct admin_infor
{
	char name[20];
	int year;
	int day;
	int mon;
};
	
//������Ϣ��ѯ
struct brrow
{
	char name[20];//��������
	char edname[20];//��������
	char writer[20];//����
	int year;
	int day;
	int mon;
	struct brrow *next;
};
//������Ϣ��ѯ
struct giveback
{
	char edname[100];//�黹�鼮��
	char name[20];//��������
	char writer[20];//����
	int year;
	int day;
	int mon;
	struct giveback *next;
};

//�洢�˺�
struct zhang
{
	char zh[13];
	char code[13];
	struct zhang *next;
};


/*       ����Ա����--ͼ����Ϣ����     */
void main();//������
struct admin *getNode();//������������ͼ����Ϣ
void getNode1(struct admin *p);//�޸�ͼ������
struct admin * creat();//¼��ͼ����Ϣ
void Save(struct admin * list);//��ͼ�����ݱ��浽�ļ�
struct admin *Initial_list2();//���ļ��ж�ȡ���ݣ��Գ�ʼ����ͷ��������
void add(struct admin *list,struct admin *node);//���ͼ��
void lookup1(struct admin *list,char *book);//��ѯͼ��,��������ѯ
void lookup2(struct admin *list,char *edname);//��ѯͼ��,����������ѯ
void lookup3(struct admin *list,char *pub);//��ѯͼ��,�����浥λ��ѯ
void lookup4(struct admin *list,char *time);//��ѯͼ��,������ʱ���ѯ
void freeList(struct admin *list);//ɾ��ȫ��ͼ��
void display(struct admin *list);//���ͼ��
void mod(struct admin *head);//�޸�ͼ��
void deleteNodeByNo2(struct admin *list,char *name);//ɾ��ͼ��
//������Ϣ��ѯ
void brrowread(struct reader *p,struct admin *p_1,int year,int mon,int day);
struct brrow * brr();
void look_up_1(struct brrow *list,char *book_name);
void look_up_2(struct brrow *list,char *book_name);
void look_up_3(struct brrow *list,char *book_name);
void brrower_menu();
//������Ϣ��ѯ
 void returnread(struct reader *p,struct admin *p_1);
struct giveback * back();
void backlook_up1(struct giveback *list,char *book_name);
void backlook_up2(struct giveback *list,char *book_name);
void backlook_up3(struct giveback *list,char *book_name);
void back_menu();
static void setPos(int x,int y);
void menueadmin1();//����Աҳ��--ͼ��
void menueadmin2();//����Աҳ��--����
void listWithHead();//����Ա--ͼ��ĳ��򣬽��벻ͬ�ĳ���
void listWithHead1();//����Ա--���ߵĳ��򣬽��벻ͬ�ĳ���
void ch();//ѡ��ģ��



	
/*       ����Ա����--������Ϣ����     */
void admincode(int m);//��¼ҳ��
struct zhang * zhang_1(struct zhang *list);//�����˺�
struct reader *getNode2();//�����������������Ϣ
struct reader *  creat1(char *name_1,char *num_1);//¼��ͼ�������Ϣ
void Save2(struct reader *list);//��������Ϣ���浽�ļ�
void Save1(struct reader *p1);
void add1(struct reader *list,struct reader *node);//��Ӷ���
struct reader *Initial_list();//���ļ��ж�ȡ���ݣ��Գ�ʼ����ͷ��������
struct reader * look2(struct reader *list,char *name);//�����߲�ѯ�������
void freeList1(struct reader *list);//ɾ��ȫ��������Ϣ
void display1(struct reader *list);//���������Ϣ
void mod1(struct reader *head);//�޸Ķ�����Ϣ
void deleteNodeByNo(struct reader  *list,char *name);//ɾ��������Ϣ
void freelist2(struct reader *list);//�ͷŶ��������ڴ�
void denji();//ע��ҳ��

/*           ���߹���                 */
void borrow();//����ͼ��
void find();//��ѯͼ��
struct reader * look_1(struct reader *list,char *index);
void find_1();//���ݽ��ĺŲ�ѯͼ��
void  return_book();//�黹ͼ��
void revise_code();//�޸�����
void reader();//����ҳ��
void choice_read(char *nam,char *num);//����ѡ��ģ��
void menu();
/*Ϊ���������ͼ��������ȫ��������ͷ��������*/


/*                            ����Ա����--ͼ����Ϣ����               */
//������������ͼ����Ϣ
struct admin *getNode()
{
	struct admin *p=NULL;
	p=(struct admin *)malloc(sizeof(struct admin));
	memset(p,0,sizeof(struct admin));
	printf("\t\t\t �x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x\n");
	printf("\t\t\t ���ͼ����:");
	scanf("%d",&p->no);
	printf("\t\t\t �������:");
	fflush(stdin);
	gets(p->book);
	printf("\t\t\t �������:");
	fflush(stdin);
	gets(p->edname);
	printf("\t\t\t �������:");
	scanf("%c",&p->no1);
	printf("\t\t\t �����浥λ:");
	fflush(stdin);
	gets(p->pub);
	printf("\t\t\t ������ʱ��:");
	fflush(stdin);
	gets(p->time);
	printf("\t\t\t ������� & �۸�:");
	scanf("%d%d",&p->num,&p->price);
	printf("\t\t\t ������������������������������������������������������\n\n\n");
	return p;
}

//�޸�ͼ������
void getNode1(struct admin *p)
{
	printf("\t\t\t �x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x\n");
	printf("\t\t\t ���tinput new ���:");
	scanf("%d",&p->no);
	printf("\t\t\t ���input new ����:");
	fflush(stdin);
	gets(p->book);
	printf("\t\t\t ���input new ����:");
	fflush(stdin);
	gets(p->edname);
	printf("\t\t\t ���input new �����:");
	scanf("%c",&p->no1);
	printf("\t\t\t ���input new ���浥λ:");
	fflush(stdin);
	gets(p->pub);
	printf("\t\t\t ���input new ����ʱ��:");
	fflush(stdin);
	gets(p->time);
	printf("\t\t\t ���input new ����� & �۸�:");
	scanf("%d%d",&p->num,&p->price);
	printf("\t\t\t ������������������������������������������������������\n\n\n");
}


//����ͷ�巨������ͷ��������
//¼��ͼ����Ϣ
struct admin * creat()
{
	struct admin *head=(struct admin *)malloc(sizeof(struct admin));
	
	struct admin *node=NULL;

	memset(head,0,sizeof(struct admin));//����ڴ����
	printf("\n\n\t\t\t\t��ܰ��ʾ����ȫ������0��ʱ��¼��ͼ�����\n");
	while(1)
	{
		node=getNode();
		if(node->no==0)
			break;//��ͼ����Ϊ0ʱ�������
	    node->next=head->next;
		head->next=node;
	}
	return head;
}

//��ͼ�����ݱ��浽�ļ�
void Save(struct admin * list)
{
	struct admin *p = list->next;
	FILE * fp = NULL;
    struct admin_infor w;
	time_t time_s;
	struct tm *time_sl;
	time_s=time(&time_s);
	time_sl=localtime(&time_s);
	system("cls");
	memset(w.name,0,sizeof(char)*20);
	if((fp=fopen("worker.txt","w+"))==NULL)
	{
		printf("\t\t\t\t����ʧ�ܣ������ԣ�");
		exit(0) ;
	}
	printf("\n\n\n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��         ����Ա ������           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��                    \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(20,7);
	scanf("%s",w.name);
	w.year=time_sl->tm_year+1900;
	w.mon=time_sl->tm_mon+1;
	w.day=time_sl->tm_mday;
	fwrite(&w,sizeof(struct admin_infor),1,fp);

	
	while( p != NULL)
	{
		fwrite(p,sizeof(struct admin),1,fp);
		p = p->next;
	}
    	system("cls");
	fclose(fp);     
}



//���ļ��ж�ȡ���ݣ��Գ�ʼ����ͷ��������
struct admin *Initial_list2()
{
	FILE *fp;
	struct admin *p = NULL;
	struct admin *list = NULL;
    struct admin_infor w;
	list=(struct admin *)malloc(sizeof(struct admin));
	memset(list,0,sizeof(struct admin));

	if((fp=fopen("worker.txt","r"))==NULL)
	{
		printf("open file failed!\n");
		return NULL;
	}
	  fread(&w,sizeof(struct admin_infor),1,fp);
	while(!feof(fp))
	{
		if((p = (struct admin *)malloc(sizeof(struct admin))) == NULL)
		{
			printf("\t\t\t\t�ڴ治�㣬���ͷ��ڴ�֮�����ԣ�");	
			return NULL;
		}	
		memset(p,0,sizeof(struct admin));
		if(fread(p,sizeof(struct admin),1,fp)!=0)
		{
		
    	   p->next=list->next;
    	   list->next=p;
				
		}
	}
    
	fclose(fp);

	return list;
}

//���ͼ��
void add(struct admin *list,struct admin *node)
{
	struct admin *p=list;
	while(p->next!=NULL&&p->next->no<node->no)
		p=p->next;
	node->next=p->next;
	p->next=node;
}

//��ѯͼ��,��������ѯ
void lookup1(struct admin *list,char *book)
{
	struct admin *p=list->next;
	if(p==NULL)
	{
		printf("���ڻ�û��ͼ�飡\n");
	}
	while(p!=NULL)	
	{
		if(strcmp(p->book,book)==0)
		     break;
		   p=p->next;
	}
	if(p==NULL)
		printf("\n\n\t\t\t\tͼ�������û���Ȿ�飡\n\n");
	else
	{   printf("\t\t\t������������������������\n");
		printf("\t\t\t�����:%d                              ���\n",p->no);
		printf("\t\t\t�������:%s                              ���\n",p->book);
		printf("\t\t\t�������:%s                              ���\n",p->edname);
	    printf("\t\t\t�������:%c                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
	}
	system("pause");
        
}


//��ѯͼ��,����������ѯ
void lookup2(struct admin *list,char *edname)
{
	struct admin *p=list->next;
	if(p==NULL)
		printf("���ڻ�û��ͼ�飡\n");
	while(p!=NULL)	
	{
		if(strcmp(p->edname,edname)==0)
		{
        printf("\t\t\t������������������������\n");
		printf("\t\t\t�����:%d                              ���\n",p->no);
		printf("\t\t\t�������:%s                              ���\n",p->book);
		printf("\t\t\t�������:%s                              ���\n",p->edname);
	    printf("\t\t\t�������:%c                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
	//	break;
		}
		p=p->next;
	}
	/*if(p==NULL)
		printf("\n\n\t\t\t\tͼ�������û���Ȿ�飡\n\n");*/
	system("pause");
        
	    
}

//��ѯͼ��,�����浥λ��ѯ
void lookup3(struct admin *list,char *pub)
{
	struct admin *p=list->next;
	if(p==NULL)
		printf("���ڻ�û��ͼ�飡\n");
	while(p!=NULL)	
	{
		if(strcmp(p->pub,pub)==0)
		{
		printf("\t\t\t������������������������\n");
		printf("\t\t\t�����:%d                              ���\n",p->no);
		printf("\t\t\t�������:%s                              ���\n",p->book);
		printf("\t\t\t�������:%s                              ���\n",p->edname);
	    printf("\t\t\t�������:%c                           ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
		}
		p=p->next;
	}
	if(p==NULL)
		printf("\n\n\t\t\t\tͼ�������û���Ȿ�飡\n\n");
	system("pause");
        
	    
}


//��ѯͼ��,������ʱ���ѯ
void lookup4(struct admin *list,char *time)
{
	struct admin *p=list->next;
	if(p==NULL)
		printf("���ڻ�û��ͼ�飡\n");
	while(p!=NULL)	
	{
		if(strcmp(p->time,time)==0)
		{
		printf("\t\t\t������������������������\n");
		printf("\t\t\t�����:%d                              ���\n",p->no);
		printf("\t\t\t�������:%s                              ���\n",p->book);
		printf("\t\t\t�������:%s                              ���\n",p->edname);
	    printf("\t\t\t�������:%c                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
		}
		p=p->next;
	}
	/*if(p==NULL)
		printf("\n\n\t\t\t\tͼ�������û���Ȿ�飡\n\n");*/
	system("pause");
        
	     
}
void ask_for(struct admin *list)
{
	int i;
	char book_name[20];
	system("color BC");
	printf("\t\t\t �x�x�x�x�x�x�x�x�x�x�x�x�x\n");
	printf("\t\t\t �� 1 ��������ѯͼ��       ��\n\n");
	printf("\t\t\t �� 2 ������������ѯͼ��   ��\n\n");
	printf("\t\t\t �� 3 �����浥λ��ѯͼ��   ��\n\n");
	printf("\t\t\t �� 4 ������ʱ���ѯͼ��   ��\n\n");
	printf("\t\t\t ��������������������������\n\n");
	printf("\t\t\t�����ѡ�����Ϲ��ܣ�\n");
	scanf("%d",&i);
	system("cls");
	switch(i)
	{
	   case 1:setPos(5,10);printf("\t\t\t������ͼ�飺");fflush(stdin);gets(book_name);printf("\n\n");lookup1(list,book_name);break;
	   case 2:setPos(5,10);printf("\t\t\t������ͼ�����ߣ�");fflush(stdin);gets(book_name);printf("\n\n");lookup2(list,book_name);break;
	   case 3:setPos(5,10);printf("\t\t\t��������浥λ��");fflush(stdin);gets(book_name);printf("\n\n");lookup3(list,book_name);break;
       case 4:setPos(5,10);printf("\t\t\t���������ʱ�䣺");fflush(stdin);gets(book_name);printf("\n\n");lookup4(list,book_name);break;
	   default:menu();break;
	}
}

//ɾ��ȫ��ͼ��
void freeList1()
{
	FILE *fp;
	if((fp=fopen("worker.txt","w"))==NULL)
	{
		printf("open file failed!\n");
		exit(0);
	}
	fclose(fp);
	
}

//�ͷ��ڴ�
void freelist(struct admin *list)
{
	struct admin *p=list->next;
	struct admin *temp=NULL;
	while(p!=NULL)
	{
		temp=p->next;
		free(p);
		p=temp;
	}
}
//���ͼ��
void display(struct admin *list)
{
	struct admin *p=list->next;
	FILE *fp;
	system("color B5");
	struct admin_infor w;
	if((fp=fopen("worker.txt","r"))==NULL)
	{
		printf("open file failed!\n");
		exit(0);
	}
	setPos(1,0);
	fread(&w,sizeof(struct admin_infor),1,fp);
	printf("\n\n\n");
	printf("\t\t\t��������������������������������������������������������������������������������������������\n");
	printf("\t\t\t��         ����Ա ������%s           \n",w.name );
	printf("\t\t\t��������������������������������������������������������������������������������������������\n");
	printf("\t\t\t��������������������������������������������������������������������������������������������\n");
	printf("\t\t\t��         ���ڣ�%d.%d.%d           \n",w.year,w.mon,w.day);
	printf("\t\t\t��������������������������������������������������������������������������������������������\n");
	if(p==NULL)
		printf("���ڻ�û��ͼ�飡\n");
	while(p!=NULL)
	{
		printf("\t\t\t������������������������\n");
		printf("\t\t\t�����:%d                              ���\n",p->no);
		printf("\t\t\t�������:%s                              ���\n",p->book);
		printf("\t\t\t�������:%s                              ���\n",p->edname);
	    printf("\t\t\t�������:%c                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
		p=p->next;
	}
	system("pause");
}

//�޸�ͼ��
struct admin * look(struct admin *list,char *edname)//����Ҫ�޸ĵ�ͼ��
{
	struct admin *p=list->next;
	system("color E2");
	if(p==NULL)
		printf("\n\n\t\t\t\t���ڻ�û��ͼ�飡\n");
	while(p!=NULL)	
	{
		if(strcmp(p->book,edname)==0)
		{printf("\n\n\t\t\t��鿴ԭʼ���ݣ�\n");
			printf("\t\t\t������������������������\n");
		   printf("\t\t\t�����:%d                              ���\n",p->no);
	     	printf("\t\t\t�������:%s                              ���\n",p->book);
		   printf("\t\t\t�������:%s                              ���\n",p->edname);
	       printf("\t\t\t�������:%c                            ���\n",p->no1);
		   printf("\t\t\t��������:%s                            ���\n",p->pub);
		   printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		   printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		   printf("\t\t\t������������������������\n\n\n\n");
		   return p;
		}
		p=p->next;
	}
	return NULL;
}

void mod(struct admin *head)
{
	struct admin *newnode=NULL,*list=head;
	char edname[30];
	printf("\n\n\nplease input ����:\n");
	fflush(stdin);
    gets(edname);
	newnode=look(list,edname);
	if(newnode!=NULL)
	     getNode1(newnode);
	else
		printf("\t\t\t\tû���Ȿ��\n\n");
}





//ɾ��ͼ��
void deleteNodeByNo2(struct admin *list,char *name)
{
	struct admin *p=list;
	struct admin *temp;	
    if(p->next==NULL)
		printf("\t\t\t\t���ڻ�û��ͼ�飡\n");
	while(p->next!=NULL)
	{
		if(strcmp(p->next->book,name)==0)
		{
			temp=p->next;
			p->next=p->next->next;
			free(temp);
			printf("\t\t\t\tɾ���ɹ���\n");
			return ;
		}
		p=p->next;
	}
	printf("\t\t\t\tû������飬ɾ��ʧ�ܣ�\n");
}



//������Ϣ��ѯ
//��������Ϣд���ļ�
void brrowread(struct reader *p,struct admin *p_1,int year,int mon,int day)
{
	FILE *fp;
	struct brrow *p1=NULL;
	p1=(struct brrow *)malloc(sizeof(struct brrow ));
	memset(p1,0,sizeof(struct brrow ));
    if((fp=fopen("brrower.txt","a+"))==NULL)
	{
		printf("\t\t\t\tд���ļ�ʧ�ܣ������ԣ�");
		exit(0);
	}
	strcpy(p1->edname,p_1->book);
	strcpy(p1->name,p->name);
	strcpy(p1->writer,p_1->edname);
	p1->year=year;
	p1->day=day;
	p1->mon=mon;
	fwrite(p1,sizeof(struct brrow ),1,fp);
	fclose(fp);
}
//��������Ϣ���ļ��ж���
struct brrow * brr()
{
	struct brrow *p=NULL,*head=NULL;
	FILE *fp;
	head=(struct brrow *)malloc(sizeof(struct brrow));
	memset(head,0,sizeof(struct brrow));
    if((fp=fopen("brrower.txt","r+"))==NULL)
	{
		printf("\t\t\t\t�����ļ�ʧ�ܣ������ԣ�");
		exit(0);
	}
	while(!feof(fp))
	{
		p=(struct brrow *)malloc(sizeof(struct brrow));
		memset(p,0,sizeof(struct brrow));
		if(fread(p,sizeof(struct brrow),1,fp)!=0)
		{
			p->next=head->next;
			head->next=p;
		}
		else
			free(p);
	}
	return head;
	fclose(fp);
}
//�������н�����Ϣ����
//��ͼ���ѯ
void look_up_1(struct brrow *list,char *book_name)
{
	struct brrow *p1=list->next;
	system("color E4");
		system("cls");
	if(p1==NULL)
		printf("���ڻ�û�н�����Ϣ��\n");
	while(p1!=NULL)
	{
		if(strcmp(p1->edname,book_name)==0)
		{
			printf("\t\t\t\t��������������������������\n");
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->name);
			printf("\t\t\t\t      ͼ�飺%s \n\n",p1->edname);
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->writer);
			printf("\t\t\t\t      ����ʱ�䣺%d.%d.%d \n\n",p1->year,p1->mon,p1->day);
			printf("\t\t\t\t��������������������������\n\n\n\n");
		}
		p1=p1->next;
	}
	system("pause");
}
//�����߲�ѯ
void look_up_2(struct brrow *list,char *book_name)
{
	struct brrow *p1=list->next;
		system("cls");
	if(p1==NULL)
		printf("���ڻ�û�н�����Ϣ��\n");
	while(p1!=NULL)
	{
		if(strcmp(p1->writer,book_name)==0)
		{
			printf("\t\t\t\t��������������������������\n");
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->name);
			printf("\t\t\t\t      ͼ�飺%s \n\n",p1->edname);
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->writer);
			printf("\t\t\t\t      ����ʱ�䣺%d.%d.%d \n\n",p1->year,p1->mon,p1->day);
			printf("\t\t\t\t��������������������������\n\n\n\n");
		}
		p1=p1->next;
	}
	system("pause");
}


//�����߲�ѯ
void look_up_3(struct brrow *list,char *book_name)
{
	struct brrow *p1=list->next;
	system("cls");
	if(p1==NULL)
		printf("\t\t\t\t���ڻ�û�н�����Ϣ��\n");
	while(p1!=NULL)
	{
		if(strcmp(p1->name,book_name)==0)
		{
			printf("\t\t\t\t��������������������������\n");
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->name);
			printf("\t\t\t\t      ͼ�飺%s \n\n",p1->edname);
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->writer);
			printf("\t\t\t\t      ����ʱ�䣺%d.%d.%d \n\n",p1->year,p1->mon,p1->day);
			printf("\t\t\t\t��������������������������\n\n\n\n");
		}
		p1=p1->next;
	}
	system("pause");
}	

//��ʱ���ѯ
void look_up_4(struct brrow *list)
{
	struct brrow *p1=list->next;
	int year,mon,day,year1,mon1,day1;
	system("cls");
	printf("\n\n\n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        ��������ʼʱ��(��ǰ�������)��           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �꣺           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(31,7);
	scanf("%d",&year);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �£�           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(31,9);
	scanf("%d",&mon);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �գ�           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    setPos(31,11);
	scanf("%d",&day);
	system("cls");
	printf("\n\n\n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        ��������ֹʱ�䣺           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �꣺           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(31,7);
	scanf("%d",&year1);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �£�           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(31,9);
	scanf("%d",&mon1);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �գ�           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    setPos(31,11);
	scanf("%d",&day1);
	system("cls");
	if(p1==NULL)
		printf("\t\t\t\t���ڻ�û�н�����Ϣ��\n");
	while(p1!=NULL)
	{
		if(p1->year>=year&&p1->year<=year1&&p1->mon>=mon&&p1->mon<=mon1&&p1->day>=day&&p1->day<=day1)
		{
			printf("\t\t\t\t��������������������������\n");
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->name);
			printf("\t\t\t\t      ͼ�飺%s \n\n",p1->edname);
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->writer);
			printf("\t\t\t\t      ����ʱ�䣺%d.%d.%d \n\n",p1->year,p1->mon,p1->day);
			printf("\t\t\t\t��������������������������\n\n\n\n");
		}
		p1=p1->next;
	}
	system("pause");
}	

//��ѯ������Ϣ
void brrower_menu()
{
	int i=0;
	char book_name[20];
	struct brrow *list;
	list=brr();
	printf("\n\n\t\t\t\t\t���������������\n");
	printf("\t\t\t\t\t�� 1 ��ͼ���ѯ������Ϣ   ��\n\n");
	printf("\t\t\t\t\t�� 2 �����߲�ѯ������Ϣ   ��\n\n");
	printf("\t\t\t\t\t�� 3 �����߲�ѯ������Ϣ   ��\n\n");
	printf("\t\t\t\t\t�� 4 ��ʱ���ѯ������Ϣ   ��\n\n");
	printf("\t\t\t\t\t���������������\n");
	setPos(10,16);
	printf("��ѡ�����ϲ�ѯ��");
	scanf("%d",&i);
	system("cls");
	switch(i)
	{
	   case 1:printf("\n\n\t\t\t������ͼ�飺\n");fflush(stdin);gets(book_name);look_up_1(list,book_name);break;
	   case 2:printf("\n\n\t\t\t������ͼ�����ߣ�\n");fflush(stdin);gets(book_name);look_up_2(list,book_name);break;
	   case 3:printf("\n\n\t\t\t��������ߣ�\n");fflush(stdin);gets(book_name);look_up_3(list,book_name);break;
	   case 4:look_up_4(list);break;
	   default:menu();break;
	}
   	system("cls");
}

	
//������Ϣ��ѯ
//��������Ϣ�����ļ�
void returnread(struct reader *p,struct admin *p_1)
{
	FILE *fp;
	struct giveback *p1=NULL;
	time_t end;
	struct tm *data;
	end=time(&end);
	p1=(struct giveback *)malloc(sizeof(struct giveback ));
	memset(p1,0,sizeof(struct giveback));
	data=localtime(&end);
    if((fp=fopen("book_back.txt","a+"))==NULL)
	{
		printf("\t\t\t\tд���ļ�ʧ�ܣ������ԣ�");
		exit(0);
	}
	strcpy(p1->name,p->name);
	strcpy(p1->edname,p_1->book);
	strcpy(p1->writer,p_1->edname);
	p1->year=data->tm_year+1900;
	p1->mon=data->tm_mon+1;
	p1->day=data->tm_mday;
	fwrite(p1,sizeof(struct giveback),1,fp);
	fclose(fp);
}
//��������Ϣ���ļ��ж���
struct giveback * back()
{
	struct giveback *p1=NULL,*head_1=NULL;
	FILE *fp;
	head_1=(struct giveback  *)malloc(sizeof(struct giveback));
	memset(head_1,0,sizeof(struct giveback ));
    if((fp=fopen("book_back.txt","r+"))==NULL)
	{
		printf("�����ļ�ʧ�ܣ������ԣ�");
		exit(0);
	}
	while(!feof(fp))
	{
		p1=(struct giveback  *)malloc(sizeof(struct giveback));
		memset(p1,0,sizeof(struct giveback ));
		if(fread(p1,sizeof(struct giveback),1,fp)!=0)
		{
			p1->next=head_1->next;
			head_1->next=p1;
		}
		else
			free(p1);
	}
	return head_1;
	fclose(fp);
}
//�������л�����Ϣ����
//��ͼ���ѯ
void backlook_up1(struct giveback *list,char *book_name)
{
	struct giveback *p1=list->next;
		system("cls");
	if(p1==NULL)
		printf("\t\t\t\t���ڻ�û�л�����Ϣ��\n");
	while(p1!=NULL)
	{
		if(strcmp(p1->edname,book_name)==0)
		{
			printf("\t\t\t\t��������������������������\n");
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->name);
			printf("\t\t\t\t      ͼ�飺%s \n\n",p1->edname);
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->writer);
			printf("\t\t\t\t      ����ʱ�䣺%d.%d.%d \n\n",p1->year,p1->mon,p1->day);
			printf("\t\t\t\t��������������������������\n\n\n\n");
		}
		p1=p1->next;
	}
	system("pause");
}
//�����߲�ѯ
void backlook_up2(struct giveback *list,char *book_name)
{
	struct giveback *p1=list->next;
		system("cls");
	if(p1==NULL)
		printf("\t\t\t\t���ڻ�û�л�����Ϣ��\n");
	while(p1!=NULL)
	{
		if(strcmp(p1->writer,book_name)==0)
		{
			printf("\t\t\t\t��������������������������\n");
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->name);
			printf("\t\t\t\t      ͼ�飺%s \n\n",p1->edname);
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->writer);
			printf("\t\t\t\t      ����ʱ�䣺%d.%d.%d \n\n",p1->year,p1->mon,p1->day);
			printf("\t\t\t\t��������������������������\n\n\n\n");
		}
		p1=p1->next;
	}
	system("pause");
}
//�����߲�ѯ
void backlook_up3(struct giveback *list,char *book_name)
{
	struct giveback *p1=list->next;
		system("cls");
	if(p1==NULL)
		printf("\t\t\t\t���ڻ�û�л�����Ϣ��\n");
	while(p1!=NULL)
	{
		if(strcmp(p1->name,book_name)==0)
		{
			printf("\t\t\t\t��������������������������\n");
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->name);
			printf("\t\t\t\t      ͼ�飺%s \n\n",p1->edname);
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->writer);
			printf("\t\t\t\t      ����ʱ�䣺%d.%d.%d \n\n",p1->year,p1->mon,p1->day);
			printf("\t\t\t\t��������������������������\n\n\n\n");
		}
		p1=p1->next;
	}
	system("pause");
}	

//����ʱ���ѯ������Ϣ
void backlook_up_4(struct giveback *list)
{
	int year,mon,day,year1,mon1,day1;
	struct giveback *p1=list->next;
	system("cls");
	printf("\n\n\n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        ��������ʼʱ�䣺           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �꣺           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(31,7);
	scanf("%d",&year);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �£�           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(31,9);
	scanf("%d",&mon);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �գ�           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    setPos(31,11);
	scanf("%d",&day);
	system("cls");
	printf("\n\n\n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        ��������ֹʱ�䣺           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �꣺           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(31,7);
	scanf("%d",&year1);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �£�           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	setPos(31,9);
	scanf("%d",&mon1);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �գ�           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    setPos(31,11);
	scanf("%d",&day1);
	system("cls");
	if(p1==NULL)
		printf("\t\t\t\t���ڻ�û�л�����Ϣ��\n");
	while(p1!=NULL)
	{
		if(p1->year>=year&&p1->year<=year1&&p1->mon>=mon&&p1->mon<=mon1&&p1->day>=day&&p1->day<=day1)
		{
			printf("\t\t\t\t��������������������������\n");
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->name);
			printf("\t\t\t\t      ͼ�飺%s \n\n",p1->edname);
			printf("\t\t\t\t      ���ߣ�%s \n\n",p1->writer);
			printf("\t\t\t\t      ����ʱ�䣺%d.%d.%d \n\n",p1->year,p1->mon,p1->day);
			printf("\t\t\t\t��������������������������\n\n\n\n");
		}
		p1=p1->next;
	}
	system("pause");
}

//��ѯ������Ϣ
void back_menu()
{
	int i=0;
	char book_name[20];
	struct giveback *list;
	list=back();
	printf("\n\n\t\t\t\t\t���������������\n");
	printf("\n\t\t\t\t\t�� 1 ��ͼ���ѯ������Ϣ   ��\n");
	printf("\n\t\t\t\t\t�� 2 �����߲�ѯ������Ϣ   ��\n");
	printf("\n\t\t\t\t\t�� 3 �����߲�ѯ������Ϣ   ��\n");
	printf("\n\t\t\t\t\t�� 4 ��ʱ���ѯ������Ϣ   ��\n");
	printf("\n\t\t\t\t\t���������������\n");
	setPos(10,12);
	printf("��ѡ�����ϲ�ѯ��");
	scanf("%d",&i);
	printf("\n");
	system("cls");
	switch(i)
	{
	   case 1:printf("\n\n\t\t\t\t������ͼ�飺");fflush(stdin);gets(book_name);backlook_up1(list,book_name);break;
	   case 2:printf("\n\n\t\t\t\t������ͼ�����ߣ�");fflush(stdin);gets(book_name);backlook_up2(list,book_name);break;
	   case 3:printf("\n\n\t\t\t\t��������ߣ�");fflush(stdin);gets(book_name);backlook_up3(list,book_name);break;
	   case 4:backlook_up_4(list);break;
	   default:admincode(1);break;
	}
		system("cls");

}






/*                     ����Ա����--������Ϣ����        */
//�����������������Ϣ
/*struct reader *getNode2(char *name_1,char *num_1)
{
	struct reader *p1=NULL;
	p1=(struct reader *)malloc(sizeof(struct reader));
	memset(p1,0,sizeof(struct reader));
	p1->num=m;
	m++;
	strcpy(p1->num1,num_1);
	strcpy(p1->name,name_1);
	p1->max=5;
	p1->num2=book;
	strcpy(p1->code,cod);
	return p1;
}*/

//�޸Ķ�������
void getNode3(struct reader *p1)
{
	printf("\n\n\n\t\t\t\t����input new ��ţ�");
	scanf("%d",&p1->num);
	printf("\t\t\t\t����input new ���ĺ�:");
	scanf("%s",p1->num1);
	printf("\t\t\t\t����input new ����:");
	fflush(stdin);
	gets(p1->name);
	printf("\t\t\t\t����input new �����Ķ��:");
	scanf("%d",&p1->max);
	printf("\t\t\t\t����input new �ѽ�������:");
	scanf("%d",&p1->num2);
	printf("\t\t\t\t����input new ����:");
	fflush(stdin);
	gets(p1->code);
}

struct reader * getNode4()
{
     struct reader *p1=NULL;
	p1=(struct reader *)malloc(sizeof(struct reader));
	memset(p1,0,sizeof(struct reader));
	printf("\n\n\n\t\t\t\t����input  ��ţ�");
	scanf("%d",&p1->num);
    printf("\t\t\t\t����input  ���ĺ�:");
	scanf("%s",p1->num1);
	printf("\t\t\t\t����input  ����:");
	fflush(stdin);
	gets(p1->name);
	printf("\t\t\t\t����input  �����Ķ��:");
	scanf("%d",&p1->max);
	printf("\t\t\t\t����input  �ѽ�������:");
	scanf("%d",&p1->num2);
	printf("\t\t\t\t����input  ����:");
	fflush(stdin);
	gets(p1->code);
	return p1;
}

//����ͷ�巨������ͷ��������
//¼��ͼ�������Ϣ
struct reader * creat1(char *name_1,char *num_1)
{
	struct reader *p1=NULL;
	p1=(struct reader *)malloc(sizeof(struct reader));
	memset(p1,0,sizeof(struct reader));
	p1->num=m;
	m++;
	strcpy(p1->num1,num_1);
	strcpy(p1->name,name_1);
	p1->max=5;
	p1->num2=0;
	strcpy(p1->code,cod);
	return p1;
		
}

//��������Ϣ���浽�ļ�
void Save1(struct reader *p1)
{
	 
	FILE * fp = NULL;

	if((fp=fopen("reader.txt","a+"))==NULL)
	{
		printf("\t\t\t\tд���ļ�ʧ�ܣ������ԣ�");
		return ;
	}
    fwrite(p1,sizeof(struct reader),1,fp);

	fclose(fp);     
}


//�����ж�����Ϣ��������ļ�
void Save2(struct reader *list)
{
	struct reader *p=list->next;
	FILE * fp = NULL;

	if((fp=fopen("reader.txt","w"))==NULL)
	{
		printf("\t\t\t\tд���ļ�ʧ�ܣ������ԣ�");
		return ;
	}
	while(p!=NULL)
	{
		//puts(p->name);
		//Sleep(100);
		fwrite(p,sizeof(struct reader),1,fp);
		p=p->next;
	}
	fclose(fp);
	//system("pause");
}


//��Ӷ���
void add1(struct reader *list,struct reader *node)
{
	struct reader *p1=list;	

	while(p1->next!=NULL)
		p1=p1->next;
		
	node->next=p1->next;
	p1->next=node;
	printf("\t\t\t\t��ӳɹ���\n");
	Sleep(1000);
}



//���ļ��ж�ȡ���ݣ��Գ�ʼ����ͷ��������
struct reader *Initial_list()
{
	FILE *fp = NULL;
	struct reader *p1 = NULL;
	struct reader *list = NULL;

	list=(struct reader *)malloc(sizeof(struct reader));
	memset(list,0,sizeof(struct reader));

	if((fp=fopen("reader.txt","r+"))==NULL)
	{
		printf("open file failed!\n");
		return NULL;
	}

	while(!feof(fp))
	{
	     p1= (struct reader *)malloc(sizeof(struct reader));
		memset(p1,0,sizeof(struct reader));
		if(fread(p1,sizeof(struct reader),1,fp)!=0)
		{
		    p1->next=list->next;
			list->next=p1;
		}
	}
    
	fclose(fp);

	return list;
}

//ɾ��ȫ��������Ϣ
void delta_2()
{
	FILE *fp = NULL;
	if((fp=fopen("reader.txt","w+"))==NULL)
	{
		printf("open file failed!\n");
	    exit(0);
	}
		fclose(fp);
}






//���������Ϣ
void display1(struct reader *list)
{
	struct reader *p1=list->next;
	setPos(1,0);
	if(p1==NULL)
		printf("\t\t\t\t\t������ڻ�û�ж�����Ϣ������\n");
	while(p1!=NULL)
	{
		printf("\n\n\t\t\t\t������ţ�%-5d���ĺţ�%s\n\n",p1->num,p1->num1);
	    printf("\t\t\t\t�����������%s\n\n",p1->name);
	    printf("\t\t\t\t����������Ķ�ȣ�%-5d�ѽ���������%-5d\n\n",p1->max,p1->num2);
		printf("\t\t\t\t��������룺%s\n\n\n\n",p1->code);
		p1=p1->next;
	}
	system("pause");
}

//�޸Ķ�����Ϣ
struct reader  * visit(struct reader  *list,char *name)//����Ҫ�޸ĵĶ���
{
	struct reader *p1=list->next;
	if(p1==NULL)
	{
		printf("���ڻ�û�ж�����Ϣ��\n");
		return NULL;
	}
	while(p1!=NULL)	
	{
		if(strcmp(p1->num1,name)==0)
		{
			printf("\n\n\n\t\t\t\t��鿴֮ǰ�Ķ�����Ϣ��\n");
			printf("\t\t\t\t������ţ�%-5d���ĺţ�%s\n\n",p1->num,p1->num1);
	        printf("\t\t\t\t�����������%s\n\n",p1->name);
	        printf("\t\t\t\t����������Ķ�ȣ�%-5d�ѽ���������%-5d\n\n",p1->max,p1->num2);
		    printf("\t\t\t\t��������룺%s\n\n\n\n",p1->code);
			return p1;
		}
		p1=p1->next;
	}
	if(p1==NULL)
		printf("\t\t\t\tû���������\n\n");
	return NULL;
	
}

void mod1(struct reader *head)
{
	struct reader *newnode=NULL,*list=head;
	FILE *fp;
	struct zhang *p;
	char name[30];
	if((fp=fopen("�˺�.txt","a+"))==NULL)
	{
		printf("can't open this file!\n");
		exit(0);
	}
	printf("\n\n\t\t\t\tplease input ����ѧ��:\n");
	fflush(stdin);
    gets(name);
	printf("\n");
	system("cls");
	newnode=visit(list,name);
	if(newnode!=NULL)
	{
		system("pause");
	    system("cls");
    	getNode3(newnode);
	    p = (struct zhang *)malloc(sizeof(struct zhang));
	    memset(p,0,sizeof(struct zhang));
	    strcpy(p->code,newnode->code);
	    strcpy(p->zh,newnode->num1);
	    fwrite(p,sizeof(struct zhang),1,fp);
	}
	fclose(fp);
}





//ɾ��������Ϣ
void deleteNodeByNo(struct reader  *list,char *name)
{
	struct reader  *p=list;
	struct reader  *temp;
	if(p==NULL)
		printf("\n\n\n\t\t\t���ڻ�û�ж�����Ϣ��\n");

	while(p->next!=NULL)
	{
		if(strcmp(p->next->num1,name)==0)
		{
			temp=p->next;
			p->next=p->next->next;
			free(temp);
			printf("\n\n\n\t\t\tɾ���ɹ���\n");
			system("pause");
			return ;
		}
		p=p->next;
	}
	printf("\n\n\n\t\t\tû��������ߣ�ɾ��ʧ�ܣ�\n");
	system("pause");
}




//���ߵ�¼ҳ����Ϣ
void d_f()
{
	char nam[20],num[20];
	struct reader *list=NULL;
	system("color 74");
	memset(nam,0,sizeof(char)*20);
	memset(num,0,sizeof(char)*20);
	printf("\n\n\t\t\t\t��������������������");
	fflush(stdin);
	gets(nam);
	printf("\n\n\t\t\t\t�������������Ľ��ĺţ�ѧ�ţ���");
	fflush(stdin);
	gets(num);
	system("cls");
	choice_read(nam,num);
		system("pause");
   
}
	

//����--��ѯͼ��
void find()
{
	struct admin *loo=NULL;
	char boo[100];
	loo=Initial_list2();
	system("color B5");
	printf("\n\n\n\n\t\t\t\t�����������Ҫ��ѯ��ͼ��:");
	fflush(stdin);
	gets(boo);
	lookup1(loo,boo);
}

//���ݽ��ĺŲ�ѯ
struct reader * look_1(struct reader *list,char *index)
{
	struct reader *p=list->next;
	while(p!=NULL)	
	{
		if(strcmp(p->num1,index)==0)
		    return  p;
		p=p->next;
	}
	return NULL;
}

void find_1(struct reader *p1)
{
	//struct reader *list=NULL,*p;
	//list=Initial_list();
//	p=look_1(list,zh);
	//p=creat1(nam,num);
	system("color BD");
	printf("\n\n\t\t\t\t������� ��%s                                ���\n",p1->name);
	printf("\n\n\t\t\t\t��������Ķ�ȣ�%d           �ѽ���������%d���\n",p1->max,p1->num2);
	system("pause");
}
	

//����--����ͼ��
void borrow(struct reader *p)
{
	//struct reader *p;//,*br=NULL;
	struct admin *list=NULL,*p_1=NULL;
	int k,i,h,year,mon=0,flag=0;
	time_t time_s;
	struct tm *time_sl;
	time_s=time(&time_s);
	time_sl=localtime(&time_s);
	book=0;
	//br=Initial_list();
	list=Initial_list2();
	//p=creat1(nam,num);
	p_1=list->next;
	/*while(p!=NULL)
	{
	    if(strcmp(p->num1,zh)==0)
			break;
		p=p->next;
	}*/
	system("color E9");
	if(p->max>p->num2)
	{
		printf("\n\n\n\t\t\t\t\t����㻹�ܽ���%d������\n\n",(p->max)-(p->num2));
		printf("\t\t\t\t\t�����������Ҫ���ļ����飺");
		//setPos(15,4);
	    scanf("%d",&h);
		for(k=0;k<h;k++)
		{
	     	system("cls");
			printf("\n\n\n\t\t\t\t\t�����������Ҫ���ĵ�ͼ���ţ�");
			setPos(35,4);
			scanf("%d",&i);
		    while(p_1!=NULL)
			{
	           if(p_1->no==i)
			      break;
		       p_1=p_1->next;
			}
			if(p_1!=NULL)
			{
			  p_1->num=p_1->num-1;//�޸�ͼ����
			  p->num2+=h;//�޸Ķ����ѽ�������
			   brrowread(p,p_1,time_sl->tm_year+1900,time_sl->tm_mon+1,time_sl->tm_mday);//����ı�������µ�����
			   printf("\n\n\n\t\t\t\t\t�����ĳɹ������\n");
			   Sleep(1000);
			   //Save1(p);
			   flag=1;//����ǣ�������ĳɹ��������ʱ��
			}
			else
				printf("\t\t\t\t\t�ܱ�Ǹ������ͼ���û���Ȿ��\n\n\n");
		}
	
	if((time_sl->tm_mon+1)==12)
	{
		year=(time_sl->tm_year)+1900+1;
		mon=1;
	}
	else
	{
		year=time_sl->tm_year+1900;
		mon=time_sl->tm_mon+2;
	}
	if(flag)
	{
		printf("\n\n\t\t\t\t\t========================================\n");
	    printf("\t\t\t\t\t ����ʱ�䣺%d.%d.%d | ����ʱ�䣺%d.%d.%d\n",(time_sl->tm_year+1900),time_sl->tm_mon+1,time_sl->tm_mday,year,mon,time_sl->tm_mday);
    	printf("\t\t\t\t\t========================================\n\n\n");
	}
	}
	else
		printf("\t\t\t\t\t���ܱ�Ǹ���ѵ�������������!���\n");
	system("pause");
}


//�޸Ľ�����Ϣ--����
void brrowrite_1(struct brrow *list)
{
	FILE *fp;
	struct brrow *p=list->next;
    if((fp=fopen("brrower.txt","w+"))==NULL)
	{
		printf("\t\t\t\tд���ļ�ʧ�ܣ������ԣ�");
		exit(0);
	}
	while(p!=NULL)
	{
		fwrite(p,sizeof(struct brrow),1,fp);
		p=p->next;
	}
	fclose(fp);
}


//���㻹��ʱ��Ľ������
void money(int year,int mon,int day)
{
  time_t time_s;
  struct tm *time_sl;
  time_s=time(&time_s);
  time_sl=localtime(&time_s);//����ʱ��
  int n;
  int add_1=0,add_2=0;
  int count[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  for(n=0;n<mon-1;n++)
		add_1+=count[n];
	add_1+=day;//��������
	for(n=0;n<time_sl->tm_mon;n++)
		add_2+=count[n];
	add_2+=(time_sl->tm_mday);//��������
	add_2-=add_1;//���������
	int day1=0;
	for(n=year;n<(time_sl->tm_year+1900);n++)
	{
		if(n%400==0||(n%100!=0)&&(n%4==0))
			add_2++;
		day1++;//��������֮�����������
	}
	add_2+=365*day1;//�����������
	if(abs(add_2)>30)
    {
	printf("\n\n\n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��        �볥����           \n" );
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
    printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��       %.2fԪ           \n",abs(add_2)*0.1);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��       ��ˢ��           \n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	Sleep(2000);
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	printf("\t\t ��      ֧���ɹ�!��*@��@*��           \n");
	printf("\t\t ��������������������������������������������������������������������������������������������\n");
	Sleep(1000);
	}
}


//���鹦��
void  return_book(struct reader *p1)
{
	struct brrow *list=NULL,*p=NULL,*p_2=NULL;
	struct admin *p_1=NULL,*list1=NULL;
	int book1,k=0;
	char book_name[20];
    list=brr();//�ӽ����ļ��ж�����Ϣ
	list1=Initial_list2();//��ͼ���ļ��ж�����Ϣ
	p=list->next;
	p_1=list1->next;
	while(p!=NULL)
	{
	      if(strcmp(p->name,p1->name)==0)
		  {
			  printf("\n\n\t\t\t\t����黹�鼮��%s\n\n",p->edname);
			  k=1;
		  }
		   p=p->next;
	}//�ڽ��ı��ϲ�ѯ
	if(k!=1)
		printf("\n\n\t\t\t\t���ڻ�û�пɹ黹���鼮��\n");
	else
	{
		printf("\n\n\n\t\t\t\t�������������Ҫ�黹��ͼ��������\n");
	scanf("%d",&book1);
	if(book1<0||book1>=5)
		main();
	p1->num2=(p1->num2)-book1;//�޸Ķ����ѽ�������
    for(k=0;k<book1;k++)
	{
	     	system("cls");
			p=list;//���»���ͷ���
			printf("\n\n\t\t\t\t������������%d���黹��������\n",k+1);
			setPos(29,4);
		    scanf("%s",book_name);
			while(p->next!=NULL)
			{
	            if(strcmp(p->next->edname,book_name)==0)
				{
					money(p->next->year,p->next->mon,p->next->day);//������Ҫ���Ľ��
					returnread(p1,p_1);//�����������µ�����
			        printf("\t\t\t\t�����ɹ������\n");
				   //Save1(p1);
				   Sleep(1000);
					p_2=p->next;
				    p->next=p->next->next;//�ӽ��ı���ɾ������
				    free(p_2);
				}
				else
		            p=p->next;
				
			}//�ڽ��ı��ϲ�ѯ,��ɾ��������Ϣ
			while(p_1!=NULL)
			{
				if(strcmp(p_1->book,book_name)==0)
			      break;
		        p_1=p_1->next;
			}
			if(p_1!=NULL)
			{
			    
			    p_1->num=p_1->num+1;//�޸�ͼ����
			}
			printf("\n\n");
	}
	brrowrite_1(list);
	}
	system("pause");
	
}

//�޸�����--����Ա
void revise_code1()
{
	char code_1[13];
	FILE *fp;
	int i=0;
	//struct reader *p=list;
	struct zhang *p1;
	memset(code_1,0,sizeof(char));
	if((fp=fopen("����Ա�˺�.txt","a+"))==NULL)
	{
		printf("Can't open this file!\n");
		exit(0);
	}
	while(1)
	{
		printf("\n\n\n\t\t\t\t�������������֮ǰ������:");
	    scanf("%s",code_1);
    	if(strcmp(code_1,cod)==0)
		{
			printf("\n\t\t\t\t�����������������룺");
			while(!(isspace(code[i]=getch())))
			 {
			      printf("*");
	              i++;
			 }
	 	code[i]='\0';
		printf("\n\n"); 
		printf("\n\t\t\t\t��������ٴ�������������룺");
		i=0;
	  while(!(isspace(cod[i]=getch())))
		{
			printf("*");
	        i++;
		}
	  	cod[i]='\0';
	    if(strcmp(code,cod)==0)
		   {
		        printf("\n\t\t\t\t����޸�����ɹ������\n");
		        break;
		   }
	       else
		   {
			   printf("\n\t\t\t\t���������ǰ��һ�£����������룡���\n");
			   continue;
		   }
		}
	}
	p1=(struct zhang *)malloc(sizeof(struct zhang));
	memset(p1,0,sizeof(struct zhang));
	strcpy(p1->zh,zh);
	strcpy(p1->code,code);
	fwrite(p1,sizeof(struct zhang),1,fp);
	fclose(fp);
}




//�޸�����
void revise_code(struct reader *list)
{
	char code_1[13];
	FILE *fp;
	int i=0,fl=0;
	struct reader *p=list;
	struct zhang *p1;
	memset(code_1,0,sizeof(char));
	if((fp=fopen("�˺�.txt","a+"))==NULL)
	{
		printf("Can't open this file!\n");
		exit(0);
	}
	while(1)
	{
		printf("\n\n\n\t\t\t\t�������������֮ǰ������:");
	    scanf("%s",code_1);
    	if(strcmp(code_1,cod)==0)
		{
			printf("\n\t\t\t\t�����������������룺");
			 while(!(isspace(cod[i]=getch())))
			 {
			      printf("*");
				  if(cod[i]==8)
				  {
					  printf("\n\n\n\t\t\t\t�������������֮ǰ������:%s",code_1);
					  	printf("\n\t\t\t\t�����������������룺");
						for(fl=0;fl<i-1;fl++)
							printf("*");
						i--;
				  }

	            else
	              i++;
			 }
	 	cod[i]='\0';
		printf("\n\n"); 
		printf("\n\t\t\t\t��������ٴ�������������룺");
		i=0;
	  while(!(isspace(code[i]=getch())))
		{
			printf("*");
			if(cod[i]==8)
			{
			printf("\n\n\n\t\t\t\t�������������֮ǰ������:%s",code_1);
			printf("\n\t\t\t\t�����������������룺");
				for(fl=0;fl<i;fl++)
					printf("*");
			printf("\n\t\t\t\t��������ٴ�������������룺");
				for(fl=0;fl<i-1;fl++)
					printf("*");
				i--;
			}
			else
	          i++;
		}
	  	code[i]='\0';
	       if(strcmp(code,cod)==0)
		   {
		        printf("\n\t\t\t\t����޸�����ɹ������\n");
		        break;
		   }
	       else
		   {
			   printf("\n\t\t\t\t���������ǰ��һ�£����������룡���\n");
			   continue;
		   }
		}
	}
	p1=(struct zhang *)malloc(sizeof(struct zhang));
	memset(p1,0,sizeof(struct zhang));
	strcpy(p1->zh,zh);
	strcpy(p1->code,code);
	fwrite(p1,sizeof(struct zhang),1,fp);

	while(p->next!=NULL)
	{
		if(strcpy(p->next->num1,zh)==0)
		{
			 strcpy(p->next->code,cod);
			 break;
		}
		p=p->next;
	}
	fclose(fp);
}



//����ҳ��
void reader()
{
	printf("\n\n\n\t\t\t\t\t��������������\n");
    printf("\t\t\t\t\t��1 ���鹦��              ��\n\n\n");
	printf("\t\t\t\t\t��2 ���鹦��              ��\n\n\n");
	printf("\t\t\t\t\t��3 ��ѯͼ��              ��\n\n\n");
	printf("\t\t\t\t\t��4 �޸�����              ��\n\n\n");
	printf("\t\t\t\t\t��5 ��ѯ�Լ��������Ϣ    ��\n\n\n");
	printf("\t\t\t\t\t��0 �˳�����              ��\n\n\n");
	printf("\t\t\t\t\t��������������\n\n");
	printf("\t\t\t��ѡ��\n");

}

//�ͷŶ��������ڴ�
void freelist2(struct reader *list)
{
	struct reader *p=list->next,*p1;
	while(p!=NULL)
	{
		p1=p->next;
		free(p);
		p=p1;
	}
}

//ѡ��ģ��
void choice_read(char *nam,char *num)
{
	int choice,i=0;
	struct reader *p1=NULL,*list=NULL;
	list=Initial_list();
    p1=list->next;
	while(p1!=NULL)
	{
		if(strcmp(p1->num1,num)==0)//�����Ƿ����������
		{//puts(p1->num1);
		break;}
		p1=p1->next;
	}
	if(p1==NULL)
	{
		i=1;//�����
		p1=creat1(nam,num);//������߱���û�иö��߾����
	}
	while(1)
	{
	reader();
	setPos(20,25);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	  case 1:borrow(p1);break;
	  case 2:return_book(p1);break;
	  case 3:find();break;
	  case 4:revise_code(p1);break;
	  case 5:find_1(p1);break;
	  default:break;//�����ļ����˳�
		 
	}
	if(choice==0)
	{
	   if(i==1)
	      Save1(p1);//���û��������߾ͱ���
        else
		{
			Save2(list);//����У��͸�������
	       freelist2(list);//�ͷ��ڴ�
		}
	    main();
		break;
	}
		system("cls");

	
	
	}
		system("pause");

}

//����Աҳ��--ͼ��
void menueadmin1()
{
	
	printf("\n\n\n\t\t\t\t��������������\n");
	printf("\t\t\t\t��1 ɾ��ͼ��             ��\n\n");
	printf("\t\t\t\t��2 ���ͼ��             ��\n\n");
	printf("\t\t\t\t��3 ��ѯͼ��             ��\n\n");
	printf("\t\t\t\t��4 ���ͼ��             ��\n\n");
	printf("\t\t\t\t��5 �޸�ͼ��             ��\n\n");
	printf("\t\t\t\t��6 ������Ϣ��ѯ         ��\n\n");
	printf("\t\t\t\t��7 ������Ϣ��ѯ         ��\n\n");
	printf("\t\t\t\t��8 ɾ��ȫ��ͼ��         ��\n\n");
	printf("\t\t\t\t��9 �޸�����             ��\n\n");
	printf("\t\t\t\t��0 �˳�����             ��\n\n");
	printf("\t\t\t\t��������������\n");
	printf("��ѡ���ܣ�\n");
}
//����Աҳ��--����
void menueadmin2()
{
	printf("\n\n\n\t\t\t\t\t������������������\n");
	printf("\t\t\t\t\t��1 ɾ��������Ϣ                ��\n\n");
	printf("\t\t\t\t\t��2 ��Ӷ�����Ϣ                ��\n\n");
	printf("\t\t\t\t\t��3 ���������Ϣ                ��\n\n");
	printf("\t\t\t\t\t��4 �޸Ķ�����Ϣ(����������)    ��\n\n");
	printf("\t\t\t\t\t��5 ɾ��ȫ��������Ϣ            ��\n\n");
	printf("\t\t\t\t\t��6 �޸�����                    ��\n\n");
	printf("\t\t\t\t\t��0 �˳�����                    ��\n\n");
	printf("\t\t\t\t\t������������������\n");
	printf("��ѡ���ܣ�\n");
}




//����Ա--ͼ��ĳ��򣬽��벻ͬ�ĳ���
void listWithHead()
{
	int option,i,k;
	char name[20];
    struct admin *node=NULL;
	struct admin *list=NULL;
  /*if(flag==0)
	{
		list=creat();
		Save(list);
		flag++;
	}*/
	
	while(1)
	{    
		list=Initial_list2();//���ļ��ж���ͼ����Ϣ
	    menueadmin1();
		scanf("%d",&option);
		system("cls");
		switch(option)
		{
		 case 1:
			 
			printf("\n\n\t\t\t\t\t��������Ҫɾ��ͼ���������\n");
			setPos(40,3);
			scanf("%d",&i);
			system("cls");
			for(k=0;k<i;k++)
			{
		    	printf("\n\t\t\t\t\t��������Ҫɾ����������\n");
		    	fflush(stdin);
			   gets(name);
			   deleteNodeByNo2(list,name);
			}
			break;
		case 2:
			printf("\n\n\t\t\t\t\t��������Ҫ���ͼ���������\n");
			setPos(40,3);
			scanf("%d",&i);
			system("cls");
			for(k=0;k<i;k++)
			{
		    	node=getNode();
			   add(list,node);
			}
			break;
		case 3:
			ask_for(list);
			break;
		case 4:
			display(list);
			break;
		case 5:
			printf("\n\n\t\t\t\t\t��������Ҫ�޸�ͼ���������\n");
			setPos(40,3);
			scanf("%d",&i);
			system("cls");
			for(k=0;k<i;k++)
			   mod(list);
			break;
		case 6:
			brrower_menu();
			break;
	    case 7:
		    back_menu();
			break;
		case 8:
		    freeList1();
			break;
		case 9:
			revise_code1();
			break;
		default:freelist(list);ch();
			break;

		}
		system("cls");
		Save(list);//���浽�ļ�
	}
		//system("pause");
}


//����Ա--���ߵĳ��򣬽��벻ͬ�ĳ���
void listWithHead1()
{

    char name[30];
	int option,k,i;
    struct reader *node;
	struct reader *list=NULL;
	while(1)
	{
		list=Initial_list();//���ļ�����������Ϣ
		if(list->next==NULL)
		{
			printf("\n\n\n\t\t\t���ڻ�û�ж��ߣ�\n");
			Sleep(1000);
			system("cls");
			i=0;
		
		}
    	menueadmin2();
		scanf("%d",&option);
		system("cls");
		switch(option)
		{
		case 1:
			 
			 printf("\n\n\t\t\t\t\t��������Ҫɾ�����ߵ�������\n");
			 setPos(40,3);
			scanf("%d",&i);
			system("cls");
			for(k=0;k<i;k++)
			{
				
				printf("\n\n\t\t\t\t\t�������%d�����ߵĽ��ĺţ�\n",k+1);
			//	setPos(2,9);
		    	fflush(stdin);
			    gets(name);
			    deleteNodeByNo(list,name);
			}
			break;
		case 2:
			
			printf("\n\n\t\t\t\t\t��������Ҫ��Ӷ��ߵ�������\n");
			setPos(40,3);
			scanf("%d",&i);
				system("cls");
			for(k=0;k<i;k++)
			{
			    node=getNode4();
			    add1(list,node);
			}
			break;
		case 3:
		     display1(list);
			break;
		case 4:
			
			 printf("\n\n\t\t\t\t\t��������Ҫ�޸Ķ��ߵ�������\n");
			 setPos(40,3);
			scanf("%d",&i);
			system("cls");
			for(k=0;k<i;k++)
		    	mod1(list);
			break;
		case 5:
			 freelist2(list);
			break;
		case 6:
			revise_code(list);
			break;
		default: freelist2(list);
			     ch();
			     break;
		
		}
		Save2(list);//�����߱��浽�ļ�
		system("cls");
	}
}

//ѡ��ģ��--����Ա
void ch()
{
	int choice;
	printf("\n\n\n\n\t\t\t\t\t��������������������������\n");
    printf("\t\t\t\t\t��     ��   ͼ����Ϣ���� ��\n");
	printf("\t\t\t\t\t��     ��   ������Ϣ���� ��\n");
	printf("\t\t\t\t\t��������������������������\n");
	printf("\n\n\n\t\t\t\t\t��ѡ��");
	setPos(37,25);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	     case 1:listWithHead();break;
       	case 2:listWithHead1();break;
		default:main();break;
	}
		system("pause");
}

//Ѱ��Ŀ���˺�
struct zhang *find_6(struct zhang *list)
{
    struct zhang *p=list->next;
	while(p!=NULL)
	{
		if(strcmp(p->zh,zh)==0&&strcmp(p->code,cod)==0)
		{
				return p;
		}
			p=p->next;
	}
	return NULL;
}

//�����˺�--����
struct zhang *  read_zhang()
{
	//	char zhanghao[13];
	struct zhang *p;
    //int i,r;
	struct zhang *list=NULL;
	FILE *fp;
	list = (struct zhang *)malloc(sizeof(struct zhang));
	memset(list,0,sizeof(struct zhang));
	if((fp=fopen("�˺�.txt","r"))==NULL)
	{
		printf("open file failed!\n");
		exit(0);
	}
	while(!feof(fp))
	{
		p = (struct zhang *)malloc(sizeof(struct zhang));
		memset(p,0,sizeof(struct zhang));
		if(fread(p,sizeof(struct zhang),1,fp)!=0)
		{
    	   p->next=list->next;
    	   list->next=p;
				
		}
		else
			free(p);
	} 
	fclose(fp);
	return list;
	
}

//�����˺�--����Ա
struct zhang *  read_zhang_1()
{
	//	char zhanghao[13];
	struct zhang *p;
	int i=0;
    //int i,r;
	struct zhang *list=NULL;
	FILE *fp;
	list = (struct zhang *)malloc(sizeof(struct zhang));
	memset(list,0,sizeof(struct zhang));
	if((fp=fopen("����Ա�˺�.txt","r"))==NULL)
	{
		printf("open file failed!\n");
		exit(0);
	}

	while(!feof(fp))
	{
		p = (struct zhang *)malloc(sizeof(struct zhang));
		memset(p,0,sizeof(struct zhang));
		if(fread(p,sizeof(struct zhang),1,fp)!=0)
		{
    	   p->next=list->next;
    	   list->next=p;
				
		}
		else
			free(p);
	} 
	fclose(fp);
    return list;
	
}


//��¼ҳ��
void admincode(int m2)
{

    int i,r,fl=0;
    struct zhang *list=NULL,*p=NULL;
	memset(zh,0,sizeof(char)*13);
	if(!m2)
	    list=read_zhang();
	else
		list=read_zhang_1();
	while(1)
	{
		
		printf("\n\n\n\t\t\t\t����������������¼���������������\n\n\n");
		printf("\t\t\t\t��                                                          ��\n");
		setPos(0,8);
		if(fl==1)//ɾ���������
		{
			printf("\n\t\t\t\t\t           �˺�:%s",zh);
			 setPos(0,11);
			printf("\n\n\t\t\t\t\t           ����:");
			for(fl=0;fl<i-1;fl++)
			   printf("*");
			fl=0;
	
			i--;
		
		}
		else
	       {
			   i=0;
			   printf("\n\t\t\t\t\t           �˺�:");
	           scanf("%s",zh);
               setPos(0,11);
	           printf("\n\n\t\t\t\t\t           ����:");
		       fflush(stdin);
		       memset(cod,0,sizeof(char)*13);
		}
	    while(!(isspace(cod[i]=getch())))
		{
			printf("*");
			if(cod[i]==8)
				break;
	        i++;
		}
		if(cod[i]==8)
		{
			system("cls");
			cod[i]='\0';
			fl=1;
			continue;
		}
		cod[i]='\0';
		printf("\n\n\t\t\t\t��                                                           ��\n");
		p=find_6(list);
		if(p!=NULL)
		{
			    printf("                            �����¼�ɹ�������\n");
		        system("cls");
		        menu();
		        break;
		}
	   else
	   {
		 system("cls");
		 r++;
		 printf("\n\n\t\t\t\t�����˺Ż���������󣡡���\n");
		 if(!m2)
		 {
			 printf("\n\n\t\t\t\t����Ƿ��Ѿ�ע�᣿\n\n");
		    printf("\t\t\t\t<1> ��\t<2> ��\n");
	        printf("\t\t\t\t��ѡ��");
	       scanf("%d",&i);
		 
		 //system("pause");
     	 system("cls");
         if(i==2)
		 {
			 denji();//û��ע��
			 system("cls");
			 break;
		 }
		 }
		 if(r==5)
		 {
			 printf("\t\t\t\t��15������µ�¼��\n\n");
			 Sleep(15000);
		 }
		 
	   }
	 
	}
//	fclose(fp);
}

//ע��ҳ��
void denji()
{
	int i=0,fl=0,j=0;
	FILE *fp;
	struct zhang *p;
    if((fp=fopen("�˺�.txt","a+"))==NULL)
	{
		printf("open file failed!\n");
		exit(0);
	}
	while(1)
	{
		printf("\n\n\n\n\n\t\t\t\t    ���������������ע��������������������\n");
	    printf("\t\t\t\t\t��                                                          ��\n");
		fflush(stdin);
		if(fl==1)//ɾ���������
		{
			printf("\n\t\t\t\t\t           �˺�:%s",zh);
			 setPos(0,11);
			printf("\n\n\t\t\t\t\t           ����:");
			for(fl=0;fl<i-1;fl++)
			   printf("*");
		    fl=0;
	        i--;
		}
		else
		{
		memset(zh,0,sizeof(char)*13);
		printf("\t\t\t\t\t\t\t    �˺�:");
		gets(zh);
		i=0;
		printf("\n\n\t\t\t\t\t\t\t    ����:");
		memset(code,0,sizeof(char)*13);
		}
	 while(!(isspace(code[i]=getch())))
		{
		  if(code[i]==8)//����ɾ�������˳�ѭ��
			 break;
			printf("*");
	        i++;
		}
	    if(code[i]==8)//����ɾ��������
		{
			fl=1;
			system("cls");
			cod[i]='\0';
			continue;
		}
		
	 	code[i]='\0';
	    printf("\n\n");
	    j=0;
	    printf("\t\t\t\t\t\t\t    �ٴ������������:");
	    fflush(stdin);
		memset(cod,0,sizeof(char)*13);
	  while(!(isspace(cod[j]=getch())))
		{
		    printf("*");
		  if(cod[j]==8)
		  {
			  system("cls");
			  	printf("\n\n\n\n\n\t\t\t\t    ���������������ע��������������������\n");
	            printf("\t\t\t\t\t��                                                          ��\n");
		        fflush(stdin);
			    printf("\n\t\t\t\t\t           �˺�:%s",zh);
			    setPos(0,11);
		    	printf("\n\n\t\t\t\t\t         ����:");
		    	for(fl=0;fl<i;fl++)
			         printf("*");
			 printf("\n\n\t\t\t\t\t\t\t       �ٴ������������:");
			 for(fl=0;fl<j-1;fl++)
			    printf("*");
		      j--;
		  }
			  
		else
	        j++;
		}
	 
	  	cod[j]='\0';
	   printf("\t\t\t\t\t��                                                               ��\n");
	    if(strcmp(code,cod)==0)
		{	
			p = (struct zhang *)malloc(sizeof(struct zhang));
		     memset(p,0,sizeof(struct zhang));
			 strcpy(p->code,cod);
			 strcpy(p->zh,zh);
			 fwrite(p,sizeof(struct zhang),1,fp);
			fclose(fp);
			printf("\t\t\t\t\t\t����ע��ɹ�����\n\n");
	        printf("\t\t\t\t\t\t�������¼  ���� \n\n");
			system("cls");
		
			admincode(0);
			break;
		}
		
		else
		{
			system("cls");
			printf("\t\t\t\t\t\t�������벻һ��!����ע�����\n\n");
		}
		
	} 
	
}

//���˵�
void menu()
{
    system("color BC");
	printf("\n\n\n\n\n\t\t\t\t����������������������������������������������������������������\n\n");
	printf("\t\t\t\t           ��ӭ������������ѧͼ�����ϵͳ\n\n");
	printf("\t\t\t\t����������������������������������������������������������������\n");
	switch(choice)
	{
	case 1:ch();break;
	case 2:d_f();break;
    default:main();break;
	}
	system("pause");

}


//��꺯��
static void setPos(int x,int y)
{

COORD point = {x,y};//���Ҫ���õ�λ��x,y
HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
SetConsoleCursorPosition(HOutput, point);//���ù��λ��
}

void tshi()
{
	printf("\n\n\n\n\t\t\t\t ___________________________________________________________________\n");
	printf("\t\t\t\t|    ��ܰ��ʾ���ڲ��������а�0�˳�����,������ȷ�����ֽ�����Ӧ����   |\n");
	printf("\t\t\t\t|               ע���˺�Ϊѧ�Ż��߹���,����Ա�˺źͳ�ʶ�����Ѷ�     |\n");
	printf("\t\t\t\t|___________________________________________________________________|\n\n");
	printf("\n\n\n\n\t\t\t\t\t\t-------ָ����ʦ������");
}




void main()
{
     int i;
    system("color B6");	
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
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t��������������������������\n");
    printf("\t\t\t\t\t��     ��  ����Ա        ��\n");
	printf("\t\t\t\t\t��     ��  ����          ��\n");
	printf("\t\t\t\t\t��������������������������\n");
	printf("\n\n\n\t\t\t��ѡ�������ݣ�");
	setPos(49,12);
	scanf("%d",&choice);
	if(choice!=1)
	{
	system("cls");
	system("color B1");
     printf("\n\n\t\t\t\t�Ƿ��Ѿ�ע�᣿\n\n");
	printf("\t\t\t\t<1> ��\t<2> ��\n");
	printf("\t\t\t\t��ѡ��");
	scanf("%d",&i);
	system("cls");
     if(i==2)
		 denji();
	 else
         admincode(0);
	}
	else
	{   system("cls");
		admincode(1);
	}
	
system("pause");
	
}







