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
//ͼ����Ϣ����
struct admin
{
	int no;//ͼ����
	char book[30];//����
	char edname[20];//������
	int no1;//�����
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


/*       ����Ա����--ͼ����Ϣ����     */
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
void admincode();//��¼ҳ��
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
void admincode();//��¼ҳ��
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
	printf("\t\t\t ���tinput no:");
	scanf("%d",&p->no);
	printf("\t\t\t ���input bookname:");
	fflush(stdin);
	gets(p->book);
	printf("\t\t\t ���input edname:");
	fflush(stdin);
	gets(p->edname);
	printf("\t\t\t ���input no1:");
	scanf("%d",&p->no1);
	printf("\t\t\t ���input pub:");
	fflush(stdin);
	gets(p->pub);
	printf("\t\t\t ���input time:");
	fflush(stdin);
	gets(p->time);
	printf("\t\t\t ���input num & price:");
	scanf("%d%d",&p->num,&p->price);
	printf("\t\t\t ������������������������������������������������������\n\n\n");
	return p;
}

//�޸�ͼ������
void getNode1(struct admin *p)
{
	printf("\t\t\t �x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x\n");
	printf("\t\t\t ���tinput new no:");
	scanf("%d",&p->no);
	printf("\t\t\t ���input new edname:");
	fflush(stdin);
	gets(p->edname);
	printf("\t\t\t ���input new no1:");
	scanf("%d",&p->no1);
	printf("\t\t\t ���input new pub:");
	fflush(stdin);
	gets(p->pub);
	printf("\t\t\t ���input new time:");
	fflush(stdin);
	gets(p->time);
	printf("\t\t\t ���input new num & price:");
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
	printf("\t\t\t\t��ܰ��ʾ��������0��ʱ��¼��ͼ�����\n");
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

	if((fp=fopen("worker.txt","w+"))==NULL)
	{
		printf("\t\t\t\t����ʧ�ܣ������ԣ�");
		return ;
	}
	while( p != NULL)
	{
		fwrite(p,sizeof(struct admin),1,fp);
		p = p->next;
	}

	fclose(fp);     
}



//���ļ��ж�ȡ���ݣ��Գ�ʼ����ͷ��������
struct admin *Initial_list2()
{
	FILE *fp;
	struct admin *p = NULL;
	struct admin *list = NULL;

	list=(struct admin *)malloc(sizeof(struct admin));
	memset(list,0,sizeof(struct admin));

	if((fp=fopen("worker.txt","r"))==NULL)
	{
		printf("open file failed!\n");
		return NULL;
	}
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
	    printf("\t\t\t�������:%d                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
	}
        
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
	    printf("\t\t\t�������:%d                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
	//	break;
		}
		p=p->next;
	}
	if(p==NULL)
		printf("\n\n\t\t\t\tͼ�������û���Ȿ�飡\n\n");
        
	    
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
	    printf("\t\t\t�������:%d                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
		}
		p=p->next;
	}
	if(p==NULL)
		printf("\n\n\t\t\t\tͼ�������û���Ȿ�飡\n\n");
        
	    
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
	    printf("\t\t\t�������:%d                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
		}
		p=p->next;
	}
	if(p==NULL)
		printf("\n\n\t\t\t\tͼ�������û���Ȿ�飡\n\n");
        
	     
}
void ask_for(struct admin *list)
{
	int i;
	char book_name[20];
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
	   case 1:setPos(10,15);printf("\t\t\t������ͼ�飺");fflush(stdin);gets(book_name);printf("\n\n");lookup1(list,book_name);break;
	   case 2:setPos(10,15);printf("\t\t\t������ͼ�����ߣ�");fflush(stdin);gets(book_name);printf("\n\n");lookup2(list,book_name);break;
	   case 3:setPos(10,15);printf("\t\t\t���������ʱ�䣺");fflush(stdin);gets(book_name);printf("\n\n");lookup3(list,book_name);break;
       case 4:setPos(10,15);printf("\t\t\t��������浥λ��");fflush(stdin);gets(book_name);printf("\n\n");lookup4(list,book_name);break;
	   default:menu();break;
	}
}

//ɾ��ȫ��ͼ��
void freeList(struct admin *list)
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
	if(p==NULL)
		printf("���ڻ�û��ͼ�飡\n");
	while(p!=NULL)
	{
		printf("\t\t\t������������������������\n");
		printf("\t\t\t�����:%d                              ���\n",p->no);
		printf("\t\t\t�������:%s                              ���\n",p->book);
		printf("\t\t\t�������:%s                              ���\n",p->edname);
	    printf("\t\t\t�������:%d                            ���\n",p->no1);
		printf("\t\t\t��������:%s                            ���\n",p->pub);
		printf("\t\t\t������ʱ��:%s                          ���\n",p->time);
		printf("\t\t\t���������%d   �۸�%d                ���\n",p->num,p->price);
		printf("\t\t\t������������������������\n\n\n\n");
		p=p->next;
	}
}

//�޸�ͼ��
struct admin * look(struct admin *list,char *edname)//����Ҫ�޸ĵ�ͼ��
{
	struct admin *p=list->next;
	if(p==NULL)
		printf("\t\t\t\t���ڻ�û��ͼ�飡\n");
	while(p!=NULL)	
	{
		if(strcmp(p->book,edname)==0)
			return p;
		p=p->next;
	}
	return NULL;
}

void mod(struct admin *head)
{
	struct admin *newnode=NULL,*list=head;
	char edname[30];
	printf("please input book:\n");
	fflush(stdin);
    gets(edname);
	newnode=look(list,edname);
	getNode1(newnode);
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
}
//�����߲�ѯ
void look_up_2(struct brrow *list,char *book_name)
{
	struct brrow *p1=list->next;
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
}
//�����߲�ѯ
void look_up_3(struct brrow *list,char *book_name)
{
	struct brrow *p1=list->next;
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
}	

//��ѯ������Ϣ
void brrower_menu()
{
	int i=0;
	char book_name[20];
	struct brrow *list;
	list=brr();
	printf("\t\t\t\t\t���������������\n");
	printf("\t\t\t\t\t�� 1 ��ͼ���ѯ������Ϣ   ��\n\n");
	printf("\t\t\t\t\t�� 2 �����߲�ѯ������Ϣ   ��\n\n");
	printf("\t\t\t\t\t�� 3 �����߲�ѯ������Ϣ   ��\n\n");
	printf("\t\t\t\t\t���������������\n");
	setPos(10,14);
	printf("��ѡ�����ϲ�ѯ��");
	scanf("%d",&i);
	system("cls");
	switch(i)
	{
	   case 1:setPos(10,13);printf("\t\t\t������ͼ�飺\n");fflush(stdin);gets(book_name);look_up_1(list,book_name);break;
	   case 2:setPos(10,13);printf("\t\t\t������ͼ�����ߣ�\n");fflush(stdin);gets(book_name);look_up_2(list,book_name);break;
	   case 3:setPos(10,13);printf("\t\t\t��������ߣ�\n");fflush(stdin);gets(book_name);look_up_3(list,book_name);break;
	   default:menu();break;
	}

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
}
//�����߲�ѯ
void backlook_up2(struct giveback *list,char *book_name)
{
	struct giveback *p1=list->next;
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
}
//�����߲�ѯ
void backlook_up3(struct giveback *list,char *book_name)
{
	struct giveback *p1=list->next;
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
	printf("\n\t\t\t\t\t���������������\n");
	setPos(10,12);
	printf("��ѡ�����ϲ�ѯ��");
	scanf("%d",&i);
	printf("\n");
	switch(i)
	{
	   case 1:setPos(10,16);printf("\t\t\t\t������ͼ�飺");fflush(stdin);gets(book_name);backlook_up1(list,book_name);break;
	   case 2:setPos(10,16);printf("\t\t\t\t������ͼ�����ߣ�");fflush(stdin);gets(book_name);backlook_up2(list,book_name);break;
	   case 3:setPos(10,16);printf("\t\t\t\t��������ߣ�");fflush(stdin);gets(book_name);backlook_up3(list,book_name);break;
	   default:admincode();break;
	}

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
	
	printf("\t\t\t\t����input  borrowing number:");
	scanf("%s",p1->num1);
	printf("\t\t\t\t����input  name:");
	fflush(stdin);
	gets(p1->name);
	printf("\t\t\t\t����input  max:");
	scanf("%d",&p1->max);
	printf("\t\t\t\t����input  number of borrowed books:");
	scanf("%d",&p1->num2);
	printf("\t\t\t\t����input  code:");
	fflush(stdin);
	gets(p1->code);
}

struct reader * getNode4()
{
     struct reader *p1=NULL;
	p1=(struct reader *)malloc(sizeof(struct reader));
	memset(p1,0,sizeof(struct reader));
     printf("\t\t\t\t����input  borrowing number:");
	scanf("%s",p1->num1);
	printf("\t\t\t\t����input  name:");
	fflush(stdin);
	gets(p1->name);
	printf("\t\t\t\t����input  max:");
	scanf("%d",&p1->max);
	printf("\t\t\t\t����input  num2:");
	scanf("%d",&p1->num2);
	printf("\t\t\t\t����input  code:");
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

	if((fp=fopen("reader.txt","a"))==NULL)
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
		fwrite(p,sizeof(struct reader),1,fp);
		p=p->next;
	}
	fclose(fp);
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
void freeList1(struct reader *list)
{
	struct reader *p1=list->next;
	struct reader *temp=NULL;
	while(p1!=NULL)
	{
		temp=p1->next;
		free(p1);
		p1=temp;
	}
}

//���������Ϣ
void display1(struct reader *list)
{
	struct reader *p1=list->next;
	if(p1==NULL)
		printf("\t\t\t\t\t������ڻ�û�ж�����Ϣ������\n");
	while(p1!=NULL)
	{
		printf("\t\t\t\t������ţ�%-5d���ĺţ�%s\n\n",p1->num,p1->num1);
	    printf("\t\t\t\t�����������%s\n\n",p1->name);
	    printf("\t\t\t\t����������Ķ�ȣ�%-5d�ѽ���������%-5d\n\n",p1->max,p1->num2);
		printf("\t\t\t\t��������룺%s\n\n\n\n",p1->code);
		p1=p1->next;
	}
}

//�޸Ķ�����Ϣ
struct reader  * visit(struct reader  *list,char *name)//����Ҫ�޸ĵ�ͼ��
{
	struct reader *p1=list->next;
	if(p1==NULL)
		printf("���ڻ�û�ж�����Ϣ��\n");
	while(p1!=NULL)	
	{
		if(strcmp(p1->name,name)==0)
			return p1;
		p1=p1->next;
	}
	return NULL;
}

void mod1(struct reader *head)
{
	struct reader *newnode=NULL,*list=head;
	char name[30];
	printf("please input name:\n");
	fflush(stdin);
    gets(name);
	newnode=visit(list,name);
	getNode3(newnode);
}





//ɾ��������Ϣ
void deleteNodeByNo(struct reader  *list,char *name)
{
	struct reader  *p=list;
	struct reader  *temp;
	if(p==NULL)
		printf("\t\t\t���ڻ�û�ж�����Ϣ��\n");

	while(p->next!=NULL)
	{
		if(strcmp(p->next->name,name)==0)
		{
			temp=p->next;
			p->next=p->next->next;
			free(temp);
			printf("\t\t\tɾ���ɹ���\n");
			return ;
		}
		p=p->next;
	}
	printf("\t\t\tû��������ߣ�ɾ��ʧ�ܣ�\n");
}




//���ߵ�¼ҳ����Ϣ
void d_f()
{
	char nam[20],num[20];
	struct reader *list=NULL;
	memset(nam,0,sizeof(char)*20);
	memset(num,0,sizeof(char)*20);
	printf("\n\n\t\t\t\t��������������������");
	fflush(stdin);
	gets(nam);
	printf("\n\n\t\t\t\t�������������Ľ��ĺţ�ѧ�ţ���");
	fflush(stdin);
	gets(num);
	choice_read(nam,num);
   
}
	

//����--��ѯͼ��
void find()
{
	struct admin *loo=NULL;
	char boo[100];
	loo=Initial_list2();
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
	printf("\t\t\t\t������� ��%s                                ���\n",p1->name);
	printf("\t\t\t\t��������Ķ�ȣ�%d           �ѽ���������%d���",p1->max,p1->num2);
}
	

//����--����ͼ��
void borrow(struct reader *p)
{
	//struct reader *p;//,*br=NULL;
	struct admin *list=NULL,*p_1=NULL;
	int k,i,h,year,mon=0;
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
	if(p->max>p->num2)
	{
		printf("\t\t\t\t\t����㻹�ܽ���%d������\n\n",(p->max)-(p->num2));
		printf("\t\t\t\t\t�����������Ҫ���ļ����飺");
		setPos(15,4);
	    scanf("%d",&h);
		p->num2+=h;//�޸Ķ����ѽ�������
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
			{ p_1->num=p_1->num-1;//�޸�ͼ����
			   brrowread(p,p_1,time_sl->tm_year+1900,time_sl->tm_mon+1,time_sl->tm_mday);//����ı�������µ�����
			   printf("\n\n\n\t\t\t\t\t�����ĳɹ������\n");
			   //Save1(p);
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
	printf("\n\n\t\t\t\t\t_________________________________________\n");
	printf("\t\t\t\t\t| ����ʱ�䣺%d.%d.%d | ����ʱ�䣺%d.%d.%d|\n",(time_sl->tm_year+1900),time_sl->tm_mon+1,time_sl->tm_mday,year,mon,time_sl->tm_mday);
	printf("\t\t\t\t\t_________________________________________\n\n\n");
	}
	else
		printf("\t\t\t\t\t���ܱ�Ǹ���ѵ�������������!���\n");
}

//���鹦��
void  return_book(struct reader *p1)
{
	struct brrow *list=NULL,*p=NULL;
//	struct reader *p1=NULL,*br=NULL;
	struct admin *p_1=NULL,*list1=NULL;
	int book1,k;
	char book_name[20];
//	list=brr();//�ӽ����ļ��ж�����Ϣ
	//br=Initial_list();//�Ӷ����ļ��ж�����Ϣ
	list1=Initial_list2();//��ͼ���ļ��ж�����Ϣ
	//p1=creat1(nam,num);
	//p=list->next;
	p_1=list1->next;
	/*while(p1!=NULL)
	{
	    if(strcmp(p1->num1,zh)==0)
			break;
		p1=p1->next;
	}*/
	printf("\n\n\n\t\t\t\t�������������Ҫ�黹��ͼ��������\n");
	setPos(21,5);
	scanf("%d",&book1);
	p1->num2=p1->num2-book1;//�޸Ķ����ѽ�������
    for(k=0;k<book1;k++)
	{
		system("cls");
			printf("\t\t\t\t�������������Ҫ�黹��ͼ������\n");
			setPos(21,5);
		       scanf("%s",book_name);
		/*	while(p!=NULL)
			{
	           if(strcmp(p->edname,book_name)==0)
			      break;
		        p=p->next;
			}*/
			while(p_1!=NULL)
			{
				if(strcmp(p_1->book,book_name)==0)
			      break;
		        p_1=p_1->next;
			}
			if(p_1!=NULL)
			{
			    returnread(p1,p_1);//�����������µ�����
			    p_1->num=p_1->num+1;//�޸�ͼ����
			    printf("\t\t\t\t�����ɹ������\n");
				//Save1(p1);
			}
			else
				printf("\t\t\t\t����û����ɻ�\n\n");
	}
	
}

//�޸�����
void revise_code()
{
	char code_1[13];
	memset(code_1,0,sizeof(char));
	while(1)
	{
		printf("\n\n\n\t\t\t\t�������������֮ǰ������:");
	    scanf("%s",code_1);
    	if(strcmp(code_1,code)==0)
		{
			printf("\n\t\t\t\t�����������������룺");
            scanf("%s",code);
	        printf("\n\t\t\t\t��������ٴ�������������룺");
	        scanf("%s",cod);
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

//ѡ��ģ��
void choice_read(char *nam,char *num)
{
	int choice;
	struct reader *p1=NULL;
    p1=creat1(nam,num);
	while(1)
	{
	reader();
	setPos(25,33);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	  case 1:borrow(p1);break;
	  case 2:return_book(p1);break;
	  case 3:find();break;
	  case 4:revise_code();break;
	  case 5:find_1(p1);break;
	  default:admincode();break;
	}
	//creat1(nam,num);
	
	}
}

//����Աҳ��--ͼ��
void menueadmin1()
{
	
	printf("\t\t\t\t��������������\n");
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
	printf("\t\t\t\t\t������������\n");
	printf("\t\t\t\t\t��1 ɾ��������Ϣ    ��\n\n");
	printf("\t\t\t\t\t��2 ��Ӷ�����Ϣ    ��\n\n");
	printf("\t\t\t\t\t��3 ���������Ϣ    ��\n\n");
	printf("\t\t\t\t\t��4 �޸Ķ�����Ϣ    ��\n\n");
	printf("\t\t\t\t\t��5 ɾ��ȫ��������Ϣ��\n\n");
	printf("\t\t\t\t\t��6 �޸�����        ��\n\n");
	printf("\t\t\t\t\t��0 �˳�����        ��\n\n");
	printf("\t\t\t\t\t������������\n");
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
			 setPos(30,20);
			printf("\t\t\t\t\t��������Ҫɾ��ͼ���������\n");
			scanf("%d",&i);
			for(k=0;k<i;k++)
			{
		    	printf("\t\t\t\t\t��������Ҫɾ����������\n");
		    	fflush(stdin);
			   gets(name);
			   deleteNodeByNo2(list,name);
			}
			break;
		case 2:
			setPos(30,20);
			printf("\t\t\t\t\t��������Ҫ���ͼ���������\n");
			scanf("%d",&i);
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
			setPos(30,20);
			printf("\t\t\t\t\t��������Ҫ�޸�ͼ���������\n");
			scanf("%d",&i);
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
		    freeList(list);
			break;
		case 9:
			revise_code();
			break;
		default:admincode();
			break;

		}
		Save(list);//���浽�ļ�
	}
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
		menueadmin2();
		scanf("%d",&option);
		system("cls");
		switch(option)
		{
		case 1:
			 
			 printf("\t\t\t\t\t��������Ҫɾ�����ߵ�������\n");
			 setPos(2,6);
			scanf("%d",&i);
			for(k=0;k<i;k++)
			{
				
				printf("\t\t\t\t\t�������%d�����ߵ����֣�\n",k+1);
				setPos(2,9);
		    	fflush(stdin);
			    gets(name);
			    deleteNodeByNo(list,name);
			}
			break;
		case 2:
			
			printf("\t\t\t\t\t��������Ҫ��Ӷ��ߵ�������\n");
			setPos(2,6);
			scanf("%d",&i);
			for(k=0;k<i;k++)
			{
			    node=getNode4();
			    add1(list,node);
			}
			break;
		case 3:
		     display1(list);
			 system("pause");
			break;
		case 4:
			
			 printf("\t\t\t\t\t��������Ҫ�޸Ķ��ߵ�������\n");
			 setPos(2,6);
			scanf("%d",&i);
			for(k=0;k<i;k++)
		    	mod1(list);
			break;
		case 5:
			list=Initial_list();
		    freeList1(list);
			break;
		case 6:
			revise_code();
			break;
		default:admincode();
			break;
		
		}
		Save2(list);//�����߱��浽�ļ�
	}
}

void ch()
{
	int choice;
	printf("\n\n\n\n\t\t\t\t\t��������������������������\n");
    printf("\t\t\t\t\t��     ��   ͼ����Ϣ���� ��\n");
	printf("\t\t\t\t\t��     ��   ������Ϣ���� ��\n");
	printf("\t\t\t\t\t��������������������������\n");
	printf("\n\n\n\t\t\t\t\t��ѡ��");
	setPos(33,12);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	     case 1:listWithHead();break;
       	case 2:listWithHead1();break;
		default:admincode();break;
	}
}
//��¼ҳ��
void admincode()
{
	char zhanghao[13];
    int i;
	while(1)
	{	i=0;
		printf("\n\n\n\t\t\t\t\t����������������¼���������������\n\n\n");
		printf("\t\t\t\t\t��                                                          ��\n");
		setPos(0,8);
	    printf("\t\t\t\t\t\t           �˺�:");
	    scanf("%s",zhanghao);
		setPos(0,11);
	    printf("\n\n\t\t\t\t\t\t           ����:");
		fflush(stdin);
		memset(cod,0,sizeof(char)*12);
	    while(!(isspace(cod[i]=getch())))
		{
			printf("*");
	        i++;
		}
		cod[i]='\0';
		printf("\n\n\t\t\t\t\t��                                                           ��\n");
	   if(strcmp(code,cod)==0&&strcmp(zh,zhanghao)==0)
	   {
		   printf("                            �����¼�ɹ�������\n");
		   system("cls");
		   menu();
		   break;
	   }
	 else 
	 {
		 system("cls");
		 printf("                               �����˺Ż���������󣡡���\n");
	 }
	 
	}
}

//ע��ҳ��
void denji()
{
	int i=0;
	while(1)
	{printf("\n\n\n\n\n\t\t\t\t    ���������������ע��������������������\n");
	    printf("\t\t\t\t\t��                                                          ��\n");
		fflush(stdin);
		setPos(0,18);
		printf("\t\t\t\t\t\t\t    �˺�:");
		gets(zh);
		i=0;
		printf("\t\t\t\t\t\t\t    ����:");
	 while(!(isspace(code[i]=getch())))
		{
			printf("*");
	        i++;
		}
	 	code[i]='\0';
		printf("\n");
		i=0;
		setPos(0,20);
	    printf("\t\t\t\t\t\t\t    �ٴ������������:");
		fflush(stdin);
	  while(!(isspace(cod[i]=getch())))
		{
			printf("*");
	        i++;
		}
	  	cod[i]='\0';
	   printf("\t\t\t\t\t��                                                               ��\n");
	    if(strcmp(code,cod)==0)
		{	printf("\t\t\t\t\t\t����ע��ɹ�����\n\n");
	        printf("\t\t\t\t\t\t�������¼  ���� \n\n");
			system("cls");
			admincode();
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
	int choice;
	printf("\n\n\n\t\t\t\t����������������������������������������������������������������\n\n");
	printf("\t\t\t\t           ��ӭ������������ѧͼ�����ϵͳ\n\n");
	printf("\t\t\t\t����������������������������������������������������������������\n");
	printf("\n\n\n\n\t\t\t\t\t��������������������������\n");
    printf("\t\t\t\t\t��     ��  ����Ա        ��\n");
	printf("\t\t\t\t\t��     ��  ����          ��\n");
	printf("\t\t\t\t\t��������������������������\n");
	printf("\n\n\n\t\t\t��ѡ�������ݣ�");
	setPos(49,25);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	case 1:ch();break;
	case 2:d_f();break;
    default:admincode();break;
	}
}

static void setPos(int x,int y)
{

COORD point = {x,y};//���Ҫ���õ�λ��x,y
HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
SetConsoleCursorPosition(HOutput, point);//���ù��λ��
}

void tshi()
{
	printf("\t\t\t\t ___________________________________________________________________\n");
	printf("\t\t\t\t|    ��ܰ��ʾ���ڲ��������а�0�˳�����,������ȷ�����ֽ�����Ӧ����   |\n");
	printf("\t\t\t\t|               ע���˺�Ϊѧ�Ż��߹���                                      |\n");
	printf("\t\t\t\t|___________________________________________________________________|\n\n");
}


void main()
{

	system("color 0C");	
	tshi();

denji();
		
	menu();

	
}





