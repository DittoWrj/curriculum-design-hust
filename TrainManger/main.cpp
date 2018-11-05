/************************************************************************/
/*   ��Ŀ���ƣ��г�ʱ�̱���Ϣ����ϵͳ
/*   ����޸�ʱ�䣺2016-09-24
/*   ���������� VC6.0;
/*   ���ߣ�������                                                          
/************************************************************************/

#include <stdio.h>
#include "info.H"
#include <malloc.h>
#include <windows.h>

int main()
{
	while(1)
	{
		
		Menu();	
		system("pause");

	}
	
	return 0;
}

/**
*	��������:Menu
*   ��������:��ʾ�˵�
*	�������:��
*	����ֵ:��
**/
void Menu()
{

	int option = 0;

	//�޸Ŀ���̨����
	system("title �г�ʱ�̱���Ϣ����ϵͳ");
	//���ÿ���̨�ߴ�
	system(WIN_SIZE);
	
	//�ѱ�������Ϊ ǳ��ɫ
	system("color 3e");

	//��ʾ���˵�
	showMenu(0);
}
int Scanf(int left,int top)
{
	int option;

	setTop(top);
	setLeft(left);
	printf("��ѡ��:");
	scanf("%d",&option);
	
	return option;
}
/**
*	��������:showMenu
*   ��������:��ʾ�˵�
*	�������:optionѡ��ֵ
*	����ֵ:ѡ�����
**/
int showMenu(int option)
{

	
	//ѡ��item
	int select;
	//���˵�list
	char *title[]={"���ݹ���","���ݲ�ѯ","����ͳ��","�˳�ϵͳ",""};
	//���ݹ���list
	char *title_data[]={"���ι���","��ͣ��վ����","��ͣ��վ��Ϣ����","�������˵�","�˳�ϵͳ",""};
	//���ι���list
	char *title_trains[]={"��������","�޸ĳ���","ɾ������","������һ���˵�","�������˵�","�˳�ϵͳ",""};
	//��ͣ��վlist
	char *title_stops[]={"������ͣ��վ","�޸ľ�ͣ��վ","ɾ����ͣ��վ","������һ���˵�","�������˵�","�˳�ϵͳ",""};
	//��ͣ��վ��Ϣ
	char *title_stops_inf[]={"������ͣ��վ��Ϣ","�޸ľ�ͣ��վ��Ϣ","ɾ����ͣ��վ��Ϣ","������һ���˵�","�������˵�","�˳�ϵͳ",""};
	//��ѯ
	char *query_list[]={"���б�","���ϲ�ѯ","�������˵�","�˳�ϵͳ",""};
	//���б�
	char *query_simple_list[]={"�����б�","���ξ�ͣվ�б�","��ͣվ�б�","������һ���˵�","�������˵�","�˳�ϵͳ",""};
	switch(option) {
	case 0:
		//���˵�
		drawMenu(title,50,10,2,true);

		load();//��������

		select = Scanf(50,0) ;
		
		if(select == 1) showMenu(1);
		if(select == 2) showMenu(3);
		if(select == 3) tongji();
		if(select == 4) exit(0);

		break;
	case 1:
		//���ݹ���
		drawMenu(title_data,50,10,2,true);
		select = Scanf(50,0) ;
		
		if(select == 1) showMenu(2);
		if(select == 2) showMenu(4);
		if(select == 3) showMenu(5);
		
		break;
	case 2:
		//���ι���
		system("cls");
		drawMenu(title_trains,50,10,2,true);
		select = Scanf(50,0) ;
		if(select == 1) add_train();
		if(select == 2) change_train();
		if(select == 3) delete_train();
		if(select == 4) showMenu(1);
		if(select == 5) showMenu(0);
		if(select == 6) exit(0);
		
		break;
	case 3:
		drawMenu(query_list,50,10,2,true);
		select = Scanf(50,0) ;

		if(select == 1) showMenu(6);
		if(select == 2) sigle(1);
		if(select == 3) showMenu(0);
		if(select == 4) exit(0);

		break;
	case 4:
		//��ͣ��վ����
		drawMenu(title_stops,50,10,2,true);
		select = Scanf(50,0) ;

		if(select == 1) add_stop();
		if(select == 2) change_stop();
		if(select == 3) delete_stop();
		if(select == 4) showMenu(1);
		if(select == 5) showMenu(0);
		if(select == 6) exit(0);
		break;
	case 5:
		//��ͣ��վ��Ϣ	
		drawMenu(title_stops_inf,50,10,2,true);
		select = Scanf(50,0) ;

		if(select == 1) add_stop_inf();
		if(select == 2) change_stop_inf();
		if(select == 3) delete_stop_inf();
		if(select == 4) showMenu(1);
		if(select == 5) showMenu(0);
		if(select == 6) exit(0);

		break;
	case 6:
		drawMenu(query_simple_list,50,10,2,true);
		select = Scanf(50,0) ;
		
		if(select == 1) simple_list(1);
		if(select == 2) simple_list(2);
		if(select == 3) simple_list(3);
		if(select == 4) showMenu(3);
		if(select == 5) showMenu(0);
		if(select == 6) exit(0);
		break;
	}
	
	return option;
}
/**
*	��������:drawMenu
*   ��������:����һ���˵�
*	���������
*			str:ѡ������  ���ѡ���ÿո����(�磺"���ݹ���","���ݲ�ѯ","����ͳ��","�˳�ϵͳ","")
*			left(>0): �б�����ߵĿ��  ���ո����  
*			top(>0): �б��붥�˵ĸ߶�   ���м���
*			line_height(>0):�и�
*			line_flag(true|false):�Ƿ���ʾ�б��
*	����ֵ���б���Ŀ����
**/
int drawMenu(char *str[],int left,int top,int line_height,bool line_flag)
{
	int i = 0,j,k,p;
	int count = 1;
	int max=0;
	int maxStrLength = 0;
	int last;

	//
	while(strcmp(str[i],"")!=0)
	{
		max = strlen(str[i]);
		if(max>maxStrLength)
			maxStrLength = max;
		i++;
	}
	i=0;
	system("cls");
	//�����ϼ��
	setTop(top);
	while(strcmp(str[i],"")!=0)
	{
		//��������
		setLeft(left);

		if(i==0 )
			for(k=1;k<=maxStrLength/2+1;k++)
			{
				if(k==1)printf("��");
				printf("����");
				if(k==maxStrLength/2+1)
					printf("��\n\n\n\n");	
			}
		
		if(i==0)
		{
			setLeft(50);
	
		}

		if(line_flag) printf("��     %d.",count);
		
		printf("%s",str[i++]);

		count ++;
		
		
		//�����и�
		setTop(line_height);
	}

	printf("\n\n\n\n");	
	setLeft(50);
	for(k=1;k<=maxStrLength/2+1;k++)
	{
		if(k==1)printf("��");
		printf("����");
		if(k==maxStrLength/2+1)
			printf("��\n");	
	}
	return count-1;
}
/**
*	��������:setLeft
*   ��������:��������
*	�������:left��>0�� ����
*	����ֵ:����
**/

int setLeft(int left)
{
	for(int j = 0;j<left;j++)
		printf(" ");
	return left;
}
/**
*	��������:setTop
*   ��������:�����ϼ��
*	�������:top>0�� �ϼ��
*	����ֵ: �ϼ��
**/
int setTop(int top)
{
	for(int j =0 ;j<top;j++)
		printf("\n");
	return top;
}


void add_train()
{
	PTrainInfo head,p1,p2;
	FILE *fp;
	head = p1 = (PTrainInfo)malloc(TRAINSIZE);
	
	if((fp = fopen("train.txt","ab+"))==NULL || p1==NULL)
		Error();

	system("cls");
	setTop(10);
	
	setLeft(50);  printf("        ���α��:");            scanf("%s",p1->trainId);          printf("\n");
	
	//�жϳ��α���Ƿ��ظ�
	
	p2 =findTrain(-1,p1->trainId,-1);
	if(p2!=NULL)
	{
		printf("��¼�ظ�,¼��ʧ��.\n");
		system("pause");
		return;
	}
	

	setLeft(50);  printf("        ��������:");			scanf("%s",p1->trainName);        printf("\n");
	setLeft(50);  printf("        �������ͱ���:");	    scanf("%s",p1->trainCode);        printf("\n");
	setLeft(50);  printf("        ������������:");        scanf("%s",p1->typeName);         printf("\n");
	setLeft(50);  printf("        ����·�ֱ��:");        scanf("%s",p1->rodeId);           printf("\n");
	setLeft(50);  printf("        ����·������:");        scanf("%s",p1->rodeName);         printf("\n");
	setLeft(50);  printf("        ʼ��վ:");              scanf("%s",p1->startStaion);      printf("\n");
	setLeft(50);  printf("        ʼ��ʱ��:");            scanf("%s",p1->startTime);        printf("\n");	
	setLeft(50);  printf("        �յ�վ:");              scanf("%s",p1->endStation);       printf("\n");
	setLeft(50);  printf("        �յ�ʱ��:");            scanf("%s",p1->endTime);          printf("\n");//float f=0.0;//����floating not load
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardLwr);       printf("\n");
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardMid);         printf("\n");
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardUpper);       printf("\n");
	setLeft(50);  printf("        ��������ȫ��Ʊ��:");    scanf("%f",&p1->softLwr);         printf("\n");	
	setLeft(50);  printf("        ��������ȫ��Ʊ��:");    scanf("%f",&p1->softUpper);       printf("\n");
	setLeft(50);  printf("        Ӳ��ȫ��Ʊ��:");        scanf("%f",&p1->hardSit);         printf("\n");
	setLeft(50);  printf("        ȫ������ʱ��:");        scanf("%s",p1->fullTime);         printf("\n");
	setLeft(50);  printf("        ȫ���������:");        scanf("%d",&p1->fullMile);        printf("\n");

	fwrite(p1,TRAINSIZE,1,fp);
	setLeft(50);
	printf("����ɹ���");
	fclose(fp);
}
void change_train()
{
	print_train(true);
	
}
void load()
{
	PTrainInfo p ,p1;
	FILE *fp;
	p = train_info = (PTrainInfo)malloc(TRAINSIZE);
	if((fp=fopen("train.txt","rb"))==NULL)
	Error();
	p1 = (PTrainInfo)malloc(TRAINSIZE);
	p->trainNext = p1;
	p = p1;
	
	  while ((fread(p1,TRAINSIZE,1,fp))==1)
	  {
	  p1 = (PTrainInfo)malloc(TRAINSIZE);
	  p->trainNext = p1;
	  p = p1;
	  }
	  p->trainNext = NULL;
	fclose(fp);

	//////////////////////////////////////////////////////////////////////////
	//���ؾ�ͣ��վ
	PStopStation p2 ,p2_;
	FILE *fp1;
	p2= stop_station = (PStopStation)malloc(STOPSIZE);
	if((fp1=fopen("stoptstaion.txt","rb"))==NULL)
		Error();
	p2_ = (PStopStation)malloc(STOPSIZE);
	p2->stopNext = p2_;
	p2 = p2_;
	
	while ((fread(p2_,STOPSIZE,1,fp))==1)
	{
		p2_ = (PStopStation)malloc(STOPSIZE);
		p2->stopNext = p2_;
		p2 = p2_;
	}
	p2->stopNext = NULL;
	fclose(fp1);

	//////////////////////////////////////////////////////////////////////////
	//���ؾ�ͣվ��Ϣ
	PStopStationInf p3 ,p4;
	FILE *fp2;
	p3 = sotp_station_info = (PStopStationInf)malloc(STOPINFSIZE);
	if((fp2=fopen("stoptstaion_inf.txt","rb"))==NULL)
		Error();
	p4 = (PStopStationInf)malloc(STOPINFSIZE);
	p3->stopTrainNext = p4;
	p3 = p4;
	  while ((fread(p4,STOPINFSIZE,1,fp2))==1)
	  {
		 
		 p4 = (PStopStationInf)malloc(STOPINFSIZE);
		 p3->stopTrainNext = p4;
		 p3 = p4;

	  }
	  p3->stopTrainNext = NULL;
	fclose(fp2);
}

void Error()
{
	setLeft(40);
	printf("����ʧ�ܣ�");
	system("pause");
	showMenu(0);
}
void print_train(bool div)
{
	PTrainInfo p = train_info;
	int option;

	system("cls");
	setTop(10);
	lists(1,1,true);

	printf("Tips:����0�������˵�"); 
	option = Scanf(0,0);
	if(option == 0) showMenu(0);

	else  
	{
		tail = findTrain(option,"",-1);
		p = tail->trainNext;
		system("cls");
		lists(1,-1,false);
		
		option = Scanf(0,0);

		//���޸���Ŀ
		if(option == 1)printf("       ���α�Ų����޸ġ�\n\n");
		if(option == 2) {setLeft(50);  printf("2.��������:");					scanf("%s",p->trainName);printf("\n");}
		if(option == 3) {setLeft(50);  printf("3.�������ͱ���:");				scanf("%s",p->trainCode);printf("\n");}
		if(option == 4) {setLeft(50);  printf("4.������������:");				scanf("%s",p->typeName);printf("\n");}
		if(option == 5) {setLeft(50);  printf("5.����·�ֱ��:");				scanf("%s",p->rodeId);printf("\n");}
		if(option == 6) {setLeft(50);  printf("6.����·������:");				scanf("%s",p->rodeName);printf("\n");}
		if(option == 7) {setLeft(50);  printf("7.ʼ��վ:");						scanf("%s",p->startStaion);printf("\n");}
		if(option == 8) {setLeft(50);  printf("8.ʼ��ʱ��:");					scanf("%s",p->startTime);printf("\n");}
		if(option == 9) {setLeft(50);  printf("9.�յ�վ:");						scanf("%s",p->endStation);printf("\n");}
		if(option == 10) {setLeft(50);  printf("10.�յ�ʱ��:");					scanf("%s",p->endTime);printf("\n");}
		if(option == 11) {setLeft(50);  printf("11.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardLwr);printf("\n");}
		if(option == 12) {setLeft(50);  printf("12.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardMid);printf("\n");}
		if(option == 13) {setLeft(50);  printf("13.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardUpper);printf("\n");}
		if(option == 14) {setLeft(50);  printf("14.��������ȫ��Ʊ��:");			scanf("%f",&p->softLwr);printf("\n");}
		if(option == 15) {setLeft(50);  printf("15.��������ȫ��Ʊ��:");			scanf("%f",&p->softUpper);printf("\n");}
		if(option == 16) {setLeft(50);  printf("16.Ӳ��ȫ��Ʊ��:");				scanf("%f",&p->hardSit);printf("\n");}
		if(option == 17) {setLeft(50);  printf("17.ȫ������ʱ��:");				scanf("%s",p->fullTime);printf("\n");}
		if(option == 18) {setLeft(50);  printf("18.ȫ���������:");				scanf("%d",&p->fullMile);printf("\n");}

		Write(1,0,p->trainId);
	}
}
PTrainInfo findTrain(int n,char *str,int rhs)
{
	int i=1;
	post = n;
	int flag=0;
	PTrainInfo p = train_info;
	if(n==10)
	{
		//��ʼ��վ
		//��ID��
		while(p->trainNext->trainNext!=NULL)
		{
			p = p->trainNext;
			if(rhs==1 && strcmp(p->startStaion,strs)==0 )flag =1;
			else if(rhs==2 && strcmp(p->startTime,strs)==0) flag = 1;
			else if(rhs == 3 && strcmp(p->endStation,strs)==0)flag = 1;
			else if(rhs==4 && strcmp( p->fullTime,strs)==0)flag = 1;
			else if(rhs== 5 &&  p->fullMile==atoi(strs))flag = 1;
			else if(rhs== 6 &&  p->hardLwr-atoi(strs)<1e-10)flag = 1;
			else if(rhs== 7 &&  strcmp( p->endTime,strs)==0)flag = 1;
			else if(rhs==8 && strcmp( p->trainId,strs)==0)return p;
			else if(rhs==9 && strcmp( p->startTime,strs)==0) flag = 1;
			else 
				flag = 0;
			
			if(flag)
			{
				
				p11 = p;
				
				setLeft(40);  printf("------------------------------------------------------------------------------\n");
				setLeft(48);  printf("���α��:%s\n\n",p11->trainId);
				setLeft(50);  printf("��������:%s\n\n",p11->trainName);		
				setLeft(50);  printf("�������ͱ���:%s\n\n",p11->trainCode);
				setLeft(50);  printf("������������:%s\n\n",p11->typeName);
				setLeft(50); printf("����·�ֱ��:%s",p11->rodeId);
				
				printf("\n\n");
				setLeft(50);  printf("����·������:%s\n\n",p11->rodeName);
				setLeft(50); printf("ʼ��վ:%s\n\n",p11->startStaion);
				setLeft(50);  printf("ʼ��ʱ��:%s\n\n",p11->startTime);
				setLeft(50);  printf("�յ�վ:%s\n\n",p11->endStation);
				setLeft(50);  printf("�յ�ʱ��:%s\n\n",p11->endTime);
				setLeft(50);  printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p11->hardLwr);
				setLeft(50);  printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p11->hardMid);
				setLeft(50);  printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p11->hardUpper);
				setLeft(50); printf("��������ȫ��Ʊ��:%0.2f\n\n",p11->softLwr);
				setLeft(50);  printf("��������ȫ��Ʊ��:%0.2f\n\n",p11->softUpper);
				setLeft(50);  printf("Ӳ��ȫ��Ʊ��:%0.2f\n\n",p11->hardSit);
				setLeft(50);  printf("ȫ������ʱ��:%s\n\n",p11->fullTime);
				setLeft(50);  printf("ȫ���������:%d\n\n",p11->fullMile); 

				if(rhs == 8) break;
				i++;
				if(rhs == 9 && i>3) break;
			}
		}
		return p11;

	}
	if(n!=0 && n>0)
		//���ڵ�λ�ò�
		for( i =1;i<n;i++)
			p = p->trainNext;
		//n==-1��ʾ ��ѯ�Ƿ����str��ID���ֶ�
	else if(n==-1)
	{
		while(p->trainNext!=NULL)
		{
			p = p->trainNext;
			if(strcmp(p->trainId,str)==0)
				return p;
		}
		return NULL;
		
	}
	else
	{

		//��ID��
		while(p->trainNext!=NULL)
		{
			p = p->trainNext;
			if(strcmp(p->trainId,str)==0)
				break;
		}
	}




	return p;
}
void Write(int n,int pos,char *str)
{
	FILE *fp,*fp1,*fp3;
	int count = 0;//�ڵ������
	//n==1  ���λ�����Ϣ����  
	if(n==1)
	{
		fp = fopen("train.txt","wb");
		PTrainInfo p1,p = train_info;
	

		while(p->trainNext->trainNext!=NULL)
		{
			p = p->trainNext;
			count++;
			
			if(pos==0)
				fwrite(p,TRAINSIZE,1,fp);
			//pos == -1 ɾ��ָ���ڵ�

			if(strcmp(str,"del")==0)
			{
				p1 = findTrain(pos,"",-1)->trainNext;
				if(count != post) 
					fwrite(p,TRAINSIZE,1,fp);	
			}					
		}
		fclose(fp);
	}
	else if(n==2)
	{
		count=0;
		//ͣ��վ
		fp1 = fopen("stoptstaion.txt","wb");
		PStopStation p1,p=stop_station;
		while(p->stopNext->stopNext!=NULL)
		{
			p = p->stopNext;
			count++;
			//pos == 0д��������
			if(pos == 0)
				fwrite(p,STOPSIZE,1,fp1);
			//pos == -1 ɾ��ָ���ڵ�
			if(strcmp(str,"del")==0)
			{
				p1 = findStop(pos,"")->stopNext;
				if(count != post) 
					fwrite(p,STOPSIZE,1,fp1);	
			}			
		}
		fclose(fp1);
	}
	else if(n==3)
	{
		count=0;
		//ͣ��վ
		fp3 = fopen("stoptstaion_inf.txt","wb");
		PStopStationInf p1,p=sotp_station_info;
		while(p->stopTrainNext->stopTrainNext!=NULL)
		{
			p = p->stopTrainNext;
			count++;
			//pos == 0д��������
			if(pos == 0)
				fwrite(p,STOPINFSIZE,1,fp3);
			//pos == -1 ɾ��ָ���ڵ�
			if(strcmp(str,"del")==0)
			{
				p1 = findStopInf(pos,"")->stopTrainNext;
				if(count != post) 
					fwrite(p,STOPINFSIZE,1,fp3);	
			}			
		}
		fclose(fp3);

}

	
}
void lists(int n,int many,bool ul)
{
	//n == 1���λ�����Ϣ�б�
	PTrainInfo p = train_info;
	PStopStation p1 = stop_station;
	PStopStationInf p2 = sotp_station_info;
	int i=1;
	if(n==1)
	{
		
		int page = 7;

		if(tail!=NULL && many<0) p = tail;
		while(p->trainNext->trainNext!=NULL)
		{
			p = p->trainNext;
			
			setLeft(40);  printf("------------------------------------------------------------------------------\n");
			setLeft(48);  if(ul) printf("%d.",i);else printf("1.");printf("���α��:%s\n\n",p->trainId);
			setLeft(50);  if(!ul)printf("2.");printf("��������:%s\n\n",p->trainName);		
			setLeft(50);  if(!ul)printf("3.");printf("�������ͱ���:%s\n\n",p->trainCode);
			setLeft(50);  if(!ul)printf("4.");printf("������������:%s\n\n",p->typeName);
			setLeft(50);  if(!ul)printf("5.");printf("����·�ֱ��:%s",p->rodeId);
			
				printf("\n\n");
				setLeft(50);  if(!ul)printf("6.");printf("����·������:%s\n\n",p->rodeName);
				setLeft(50);  if(!ul)printf("7.");printf("ʼ��վ:%s\n\n",p->startStaion);
				setLeft(50);  if(!ul)printf("8.");printf("ʼ��ʱ��:%s\n\n",p->startTime);
				setLeft(50);  if(!ul)printf("9.");printf("�յ�վ:%s\n\n",p->endStation);
				setLeft(50);  if(!ul)printf("10.");printf("�յ�ʱ��:%s\n\n",p->endTime);
				setLeft(50);  if(!ul)printf("11.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p->hardLwr);
				setLeft(50);  if(!ul)printf("12.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p->hardMid);
				setLeft(50);  if(!ul)printf("13.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p->hardUpper);
				setLeft(50);  if(!ul)printf("14.");printf("��������ȫ��Ʊ��:%0.2f\n\n",p->softLwr);
				setLeft(50);  if(!ul)printf("15.");printf("��������ȫ��Ʊ��:%0.2f\n\n",p->softUpper);
				setLeft(50);  if(!ul)printf("16.");printf("Ӳ��ȫ��Ʊ��:%0.2f\n\n",p->hardSit);
				setLeft(50);  if(!ul)printf("17.");printf("ȫ������ʱ��:%s\n\n",p->fullTime);
				setLeft(50);  if(!ul)printf("18.");printf("ȫ���������:%d\n\n",p->fullMile); 
				i++;

				if(many<0) break;
		}
	}
	else if(n==2)
	{
		//�б�ͣ��վ
		if(tail2!=NULL && many<0) p1 = tail2;
		
		while(p1->stopNext->stopNext!=NULL)
		{
			p1 = p1 ->stopNext;
			setLeft(40);  printf("------------------------------------------------------------------------------\n");
			setLeft(50);if(ul)printf("%d.",i);else printf("1.");printf("��վ���:%s\n\n",p1->stationId);
			setLeft(50);if(!ul)printf("2.");printf("��ͣ���α��:%s\n\n",p1->stopid);
			setLeft(50);if(!ul)printf("3.");printf("��ͣ��������:%s\n\n",p1->soptTrainName);
			setLeft(50);if(!ul)printf("4.");printf("·�ֱ��:%s\n\n",p1->rodeId);
			setLeft(50);if(!ul)printf("5.");printf("��������:%s\n\n",p1->trainType);
			setLeft(50);if(!ul)printf("6.");printf("��վʱ��:%s\n\n",p1->atTime);
			setLeft(50);if(!ul)printf("7.");printf("����ʱ��:%s\n\n",p1->leaveTime);
			setLeft(50);if(!ul)printf("8.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p1->hardLwr);
			setLeft(50);if(!ul)printf("9.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p1->hardMid);
			setLeft(50);if(!ul)printf("10.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p1->hardUpper);
			setLeft(50);if(!ul)printf("11.");printf("��������ȫ��Ʊ��:%0.2f\n\n",p1->softLwr);
			setLeft(50);if(!ul)printf("12.");printf("��������ȫ��Ʊ��:%0.2f\n\n",p1->softUpper);
			setLeft(50);if(!ul)printf("13.");printf("Ӳ��ȫ��Ʊ��:%0.2f\n\n",p1->hardSit);
			setLeft(50);if(!ul)printf("14.");printf("��Ʊ��������:%d\n\n\n",p1->leftTicket);
			i++;
			
			if(many<0) break;
		}
		
	}
	else if(n==11)
	{
		//n==11����ӡ���κ�
		p = train_info;
		while(p->trainNext->trainNext!=NULL)
		{
			p = p->trainNext;
			setLeft(70);
			printf("%d.%s\n",i,p->trainId);
			i++;

		}

	}
	else if(n==21)
	{
		//��ȡ��ͣ��վ����б�
		p1 = stop_station;
		while(p1->stopNext->stopNext!=NULL)
		{
			p1 = p1->stopNext;
			setLeft(70);
			printf("%d.%s\n",i,p1->stationId);
			i++;
			
		}

	}
	else if(n==31)
	{
		//��ͣ��վ
	
		if(tail3!=NULL && many<0) p2 = tail3;
		if(p33!=NULL ) p2 = p33;
		while(p2->stopTrainNext->stopTrainNext!=NULL)
		{
			p2 = p2 ->stopTrainNext;
			setLeft(40);  printf("------------------------------------------------------------------------------\n");
			setLeft(50);if(ul)printf("%d.",i);else printf("1.");printf("��վ���:%s\n\n",p2->stationidI);
			setLeft(50);if(!ul)printf("2.");printf("���α��:%s\n\n",p2->trainType);
			setLeft(50);if(!ul)printf("3.");printf("��վ����:%s\n\n",p2->stopName);
			setLeft(50);if(!ul)printf("4.");printf("����·�ֱ��:%s\n\n",p2->stopRodeId);
			setLeft(50);if(!ul)printf("5.");printf("��վʱ��:%s\n\n",p2->atStation);
			setLeft(50);if(!ul)printf("6.");printf("����ʱ��:%s\n\n",p2->driveTime);
			setLeft(50);if(!ul)printf("7.");printf("����ʱ��:%s\n\n",p2->runTime);
			setLeft(50);if(!ul)printf("8.");printf("�������:%d\n\n",p2->runMile);
			setLeft(50);if(!ul)printf("9.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p2->hardLwr);
			setLeft(50);if(!ul)printf("10.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p2->hardMid);
			setLeft(50);if(!ul)printf("11.");printf("Ӳ������ȫ��Ʊ��:%0.2f\n\n",p2->hardUpper);
			setLeft(50);if(!ul)printf("12.");printf("��������ȫ��Ʊ��:%0.2f\n\n",p2->softLwr);
			setLeft(50);if(!ul)printf("13.");printf("��������ȫ��Ʊ��:%0.2f\n\n",p2->softUpper);
			setLeft(50);if(!ul)printf("14.");printf("Ӳ��ȫ��Ʊ��:%0.2f\n\n",p2->hardSit);
			setLeft(50);if(!ul)printf("15.");printf("��Ʊ��������:%d\n\n\n",p2->leftTicket);
			i++;

			if(many<0) break;
		}


	}
}
void delete_train()
{
	int option;
	system("cls");
	lists(1,1,true);
	setLeft(50);
	printf("����0�������˵�\n");
	option = Scanf(50,0);
	if(option ==0) return;
	Write(1,option,"del");
}


int getLength(int li)
{
	int i = 0;
	if(li==1)
	{
		//���㳵������
		PTrainInfo p=train_info;
		while(p->trainNext->trainNext!=NULL)
		{
			p = p->trainNext;
			i++;
		}
	}
	else if(li==2)
	{
		//����ͣ��վ����
		PStopStation p=stop_station;
		while(p->stopNext->stopNext!=NULL)
		{
			p = p->stopNext;
			i++;
		}
	}
	else if(li==3)
	{
		//����ͣ��վ��Ϣ�ڵ�����
		PStopStationInf p=sotp_station_info;
		while(p->stopTrainNext->stopTrainNext!=NULL)
		{
			p = p->stopTrainNext;
			i++;
		}
	}
	else if(li==4)
	{
		//��ѯ��������
		i=0;
		PTrainInfo p=train_info;
		while(p->trainNext->trainNext!=NULL)
		{
			p = p->trainNext;
			if(strcmp(p->trainCode,"D")==0)
				i++;
		}
	}
	else if(li==5)
	{
		//Z
		i=0;
		PTrainInfo p=train_info;
		while(p->trainNext->trainNext!=NULL)
		{
			p = p->trainNext;
			if(strcmp(p->trainCode,"Z")==0)
				i++;
		}
	}
	else if(li == 6)
	{
		//��ѯ��ƱΪ0�ĳ�վ��
		PStopStation p=stop_station;
		while(p->stopNext->stopNext!=NULL)
		{
			p = p->stopNext;
			if(p->leftTicket==0)
				i++;
		}
	}
	else if(li == 7)
	{
		PStopStation p=stop_station;
		while(p->stopNext->stopNext!=NULL)
		{
			p = p->stopNext;

			PTrainInfo p1=train_info;
			while(p1->trainNext->trainNext!=NULL)
			{
				p1 = p1->trainNext;
				if(strcmp(p1->trainId,p->stopid)==0 && p->leftTicket!=0)
					i++;
			}
		}
	}
	
	return i;
	
}
////////////////////////////
//��ͣ��վ
void add_stop()
{
	PStopStation head,p1,p2;
	PTrainInfo pt = NULL;
	FILE *fp;
	int option;
	head = p1 = (PStopStation)malloc(STOPSIZE);
	
	if((fp = fopen("stoptstaion.txt","ab+"))==NULL || p1==NULL)
		Error();
	
	system("cls");
	setTop(10);
	
	setLeft(50);  printf("        ��վ���:");            scanf("%s",p1->stationId);          printf("\n");
	
	//�жϳ��α���Ƿ��ظ�
	
	p2 =findStop(-1,p1->stopid);
	if(p2!=NULL)
	{
		printf("��¼�ظ�,¼��ʧ��.\n");
		system("pause");
		return;
	}
	setLeft(50);  printf("        ��ͣ���α��:\n");
	
	//�б��Ѵ��ڵĳ��κ�
	lists(11,0,false);
	option=Scanf(60,0);
	if(option >getLength(1))
	{
		printf("��������");
		system("pause");
		return;
	}
	pt = findTrain(option,"",-1);
	if(pt==NULL) Error();
	setLeft(60);
	printf("��ѡ���Σ�%s\n\n",pt->trainNext->trainId);
	strcpy(p1->stopid,pt->trainNext->trainId);

	
	setLeft(50);  printf("        ��ͣ��������:");        scanf("%s",p1->soptTrainName);         printf("\n");
	setLeft(50);  printf("        ·�ֱ��:");        scanf("%s",p1->rodeId);           printf("\n");
	setLeft(50);  printf("        ��������:");        scanf("%s",p1->trainType);         printf("\n");
	setLeft(50);  printf("        ��վʱ��:");              scanf("%s",p1->atTime);      printf("\n");
	setLeft(50);  printf("        ����ʱ��:");            scanf("%s",p1->leaveTime);        printf("\n");	
    //float f=0.0;//����floating not load
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardLwr);       printf("\n");
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardMid);         printf("\n");
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardUpper);       printf("\n");
	setLeft(50);  printf("        ��������ȫ��Ʊ��:");    scanf("%f",&p1->softLwr);         printf("\n");	
	setLeft(50);  printf("        ��������ȫ��Ʊ��:");    scanf("%f",&p1->softUpper);       printf("\n");
	setLeft(50);  printf("        Ӳ��ȫ��Ʊ��:");        scanf("%f",&p1->hardSit);         printf("\n");
	setLeft(50);  printf("        ��Ʊ��������:");        scanf("%d",&p1->leftTicket);         printf("\n");

	
	fwrite(p1,STOPSIZE,1,fp);
	setLeft(50);
	printf("����ɹ���");
	fclose(fp);
	
}
PStopStation findStop(int n,char *str)
{
	int i=1;
	post = n;
	int max=0;
	PStopStation p = stop_station;
	if(n!=0 && n>0)
		//���ڵ�λ�ò�
		for( i =1;i<n;i++)
			p = p->stopNext;
		
		//n==-1��ʾ ��ѯ�Ƿ����str��ID���ֶ�
		else if(n==-1)
		{
			while(p->stopNext!=NULL)
			{
				p = p->stopNext;
				if(strcmp(p->stopid,str)==0)
					return p;
			}
			return NULL;
			
		}
		else
		{
			//��ID��
			while(p->stopNext!=NULL)
			{
				p = p->stopNext;
				if(strcmp(p->stopid,str)==0)
					break;
			}
		}
		
	return p;
}
void change_stop()
{

	system("cls");
	setTop(10);
	lists(2,1,true);
    print_stop();
}
void print_stop()
{
	PStopStation p=stop_station;
	int option;
	
	system("cls");
	setTop(10);
	lists(2,1,true);
	
	printf("Tips:����0�������˵�"); 
	option = Scanf(0,0);
	if(option == 0) showMenu(0);
	
	else  
	{
		
		if(option>getLength(2))
			Error();
		tail2 = findStop(option,"");
		printf("%s\n",tail2->stopNext);
		p = tail2->stopNext;

		system("cls");
		lists(2,-1,false);

		option = Scanf(0,0);
		
		
		
		//���޸���Ŀ
		if(option == 1)printf("       ��վ��Ų����޸ġ�\n\n");
		if(option == 2) {setLeft(50);  printf("2.��ͣ���α��:");				scanf("%s",p->stopid);printf("\n");}
		if(option == 3) {setLeft(50);  printf("3.��ͣ��������:");				scanf("%s",p->soptTrainName);printf("\n");}
		if(option == 4) {setLeft(50);  printf("4.·�ֱ��:");				    scanf("%s",p->rodeId);printf("\n");}
		if(option == 5) {setLeft(50);  printf("5.��������:");				    scanf("%s",p->rodeId);printf("\n");}

		if(option == 6) {setLeft(50);  printf("6.��վʱ��:");					scanf("%s",p->atTime);printf("\n");}
		if(option == 7) {setLeft(50);  printf("7.����ʱ��:");					scanf("%s",p->leaveTime);printf("\n");}
		if(option == 8) {setLeft(50);  printf("8.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardLwr);printf("\n");}
		if(option == 9) {setLeft(50);  printf("9.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardMid);printf("\n");}
		if(option == 10) {setLeft(50);  printf("10.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardUpper);printf("\n");}
		if(option == 11) {setLeft(50);  printf("11.��������ȫ��Ʊ��:");			scanf("%f",&p->softLwr);printf("\n");}
		if(option == 12) {setLeft(50);  printf("12.��������ȫ��Ʊ��:");			scanf("%f",&p->softUpper);printf("\n");}
		if(option == 13) {setLeft(50);  printf("13.Ӳ��ȫ��Ʊ��:");				scanf("%f",&p->hardSit);printf("\n");}
		if(option == 14) {setLeft(50);  printf("14.��Ʊ��������:");				scanf("%d",&p->leftTicket);printf("\n");}
		Write(2,0,p->stationId);
	}
}
void delete_stop()
{

	int option;

	system("cls");
	lists(2,1,true);
	setLeft(50);
	printf("����0�������˵�\n");
	option = Scanf(50,0);
	if(option ==0) return;
	Write(2,option,"del");
}
void add_stop_inf()
{
	PStopStationInf head,p1,p2,p3;
	PStopStation pt = NULL;
	FILE *fp;
	int option;
	head = p1 = (PStopStationInf)malloc(STOPINFSIZE);
	
	if((fp = fopen("stoptstaion_inf.txt","ab+"))==NULL || p1==NULL)
		Error();
	
	system("cls");
	setTop(10);
	
	p2 = (PStopStationInf)malloc(STOPINFSIZE);
	p1->stopTrainNext = p2;
	p2->stopTrainNext = NULL;
	setLeft(50);  printf("        ��վ����б�:\n");
	lists(21,-1,false);
	option = Scanf(60,0);
	if(option >getLength(2))
	{
		printf("��������");
		system("pause");
		return;
	}
	
	pt = findStop(option+1,"");
	if(pt==NULL) Error();
	setLeft(60);
	printf("��ѡ��վ��%s\n",pt->stationId);
	strcpy(p1->stationidI,pt->stationId);
	
	setLeft(50);  printf("        ���α��:");        scanf("%s",p1->trainType);           printf("\n");
	setLeft(50);  printf("        ��վ����:");        scanf("%s",p1->stopName);           printf("\n");
	setLeft(50);  printf("        ����·�ֱ��:");        scanf("%s",p1->stopRodeId);         printf("\n");
	setLeft(50);  printf("        ��վʱ��:");            scanf("%s",p1->atStation);        printf("\n");	

	setLeft(50);  printf("        ����ʱ��:");            scanf("%s",p1->driveTime);        printf("\n");	
	setLeft(50);  printf("        ����ʱ��:");            scanf("%s",p1->runTime);        printf("\n");	
	setLeft(50);  printf("        �������:");            scanf("%d",&p1->runMile);        printf("\n");	

    //float f=0.0;//����floating not load
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardLwr);       printf("\n");
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardMid);         printf("\n");
	setLeft(50);  printf("        Ӳ������ȫ��Ʊ��:");    scanf("%f",&p1->hardUpper);       printf("\n");
	setLeft(50);  printf("        ��������ȫ��Ʊ��:");    scanf("%f",&p1->softLwr);         printf("\n");	
	setLeft(50);  printf("        ��������ȫ��Ʊ��:");    scanf("%f",&p1->softUpper);       printf("\n");
	setLeft(50);  printf("        Ӳ��ȫ��Ʊ��:");        scanf("%f",&p1->hardSit);         printf("\n");
	setLeft(50);  printf("        ��Ʊ��������:");        scanf("%d",&p1->leftTicket);         printf("\n");
	
	
	fwrite(p1,STOPINFSIZE,1,fp);
	setLeft(50);
	printf("����ɹ���");
	fclose(fp);
	
}
PStopStationInf findStopInf(int n,char *str)
{
	int i=1;
	post = n;
	PStopStationInf p = sotp_station_info;

	if(n==10)
	{
		//����վ��Ų�ѯ
			while(p->stopTrainNext!=NULL)
			{
			//	printf("\n%s\n",str);
				p = p->stopTrainNext;
				if(strcmp(p->stationidI,str)==0)
				{
				//	printf("\n%s\n",p->stationidI);
					return p;
				}
					
			}
			return NULL;

	}

	if(n!=0 && n>0)
		//���ڵ�λ�ò�
		for( i =1;i<n;i++)
			p = p->stopTrainNext;
		//n==-1��ʾ ��ѯ�Ƿ����str��ID���ֶ�
		else if(n==-1)
		{
			while(p->stopTrainNext!=NULL)
			{
				
				p = p->stopTrainNext;
				if(strcmp(p->stationidI,str)==0)
					return p;
					
			}
			return NULL;
			
		}
		else
		{
			//��ID��
			while(p->stopTrainNext!=NULL)
			{
				p = p->stopTrainNext;
				if(strcmp(p->stationidI,str)==0)
					break;
			}
		}
		
	return p;
}

void change_stop_inf()
{
	PStopStationInf p = sotp_station_info;
	int option;
	
	system("cls");
	setTop(10);
	lists(31,1,true);

	///////////////////////////////////

	setLeft(50);
	printf("Tips:����0�������˵�\n"); 
	option = Scanf(50,0);
	if(option == 0) showMenu(0);
	
	else  
	{
		
		if(option>getLength(3))
			Error();
		
		
		tail3 = findStopInf(option,"");
    	p = tail3->stopTrainNext;
		
		system("cls");
		lists(31,-1,false);
		
		option = Scanf(50,0);
		option++;
	
		
		
		//���޸���Ŀ
		if(option == 1)printf("       ��վ��Ų����޸�!\n\n");
		if(option == 2) {setLeft(50);  printf("1.���α��:");				scanf("%s",p->trainType);printf("\n");}
		if(option == 3) {setLeft(50);  printf("2.��վ���:");				scanf("%s",p->stopId);printf("\n");}
		if(option == 4) {setLeft(50);  printf("3.��վ����:");				    scanf("%s",p->stopName);printf("\n");}
		if(option == 5) {setLeft(50);  printf("4.����·�ֱ��:");				    scanf("%s",p->stopRodeId);printf("\n");}
		if(option == 6) {setLeft(50);  printf("5.��վʱ��:");					scanf("%s",p->atStation);printf("\n");}
		if(option == 7) {setLeft(50);  printf("6.����ʱ��:");					scanf("%s",p->driveTime);printf("\n");}
		if(option == 8) {setLeft(50);  printf("7.����ʱ��:");					scanf("%s",p->runTime);printf("\n");}
		if(option == 9) {setLeft(50);  printf("8.�������:");					scanf("%d",p->runMile);printf("\n");}
		if(option == 10) {setLeft(50);  printf("9.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardLwr);printf("\n");}
		if(option == 11) {setLeft(50);  printf("10.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardMid);printf("\n");}
		if(option == 12) {setLeft(50);  printf("11.Ӳ������ȫ��Ʊ��:");			scanf("%f",&p->hardUpper);printf("\n");}
		if(option == 13) {setLeft(50);  printf("12.��������ȫ��Ʊ��:");			scanf("%f",&p->softLwr);printf("\n");}
		if(option == 14) {setLeft(50);  printf("13.��������ȫ��Ʊ��:");			scanf("%f",&p->softUpper);printf("\n");}
		if(option == 15) {setLeft(50);  printf("14.Ӳ��ȫ��Ʊ��:");				scanf("%f",&p->hardSit);printf("\n");}
		if(option == 16) {setLeft(50);  printf("15.��Ʊ��������:");				scanf("%d",&p->leftTicket);printf("\n");}
		Write(3,0,p->stopId);
	}
}
void delete_stop_inf()
{
	int option;
	
	system("cls");
	lists(31,1,true);
	setLeft(50);
	printf("����0�������˵�\n");
	option = Scanf(50,0);
	if(option ==0) return;
	Write(3,option,"del");
	
}
void simple_list(int type)
{
	int option;
	if(type==1)
	{
		system("cls");
		//�����б�
		lists(1,1,true);
		setLeft(50);
		printf("Tip:����0�˳�ϵͳ������1������һ���˵�������2�������˵�.\n");
		option = Scanf(50,0);
		if(option == 0) exit(0);
		if(option == 1) showMenu(6);
		if(option == 2) showMenu(0);
	}
	else if(type==2)
	{
		system("cls");
		//��ͣվ�б�
		lists(2,1,true);
		setLeft(50);
		printf("Tip:����0�˳�ϵͳ������1������һ���˵�������2�������˵�.\n");
		option = Scanf(50,0);
		if(option == 0) exit(0);
		if(option == 1) showMenu(6);
		if(option == 2) showMenu(0);
	}
	else if(type == 3)
	{
		system("cls");
		//��վ��Ϣ�б�
		lists(31,1,true);
		setLeft(50);
		printf("Tip:����0�˳�ϵͳ������1������һ���˵�������2�������˵�.\n");
		option = Scanf(50,0);
		if(option == 0) exit(0);
		if(option == 1) showMenu(6);
		if(option == 2) showMenu(0);
	}
}
void tongji()
{
	system("cls");
	setTop(10);
	setLeft(50);printf("���ٶ����ĳ�������:%d\n\n",getLength(1));
	
	setLeft(50);printf("�����ĳ�������:%d\n\n",getLength(4));

	setLeft(50);printf("ֱ���ؿ�ĳ�������:%d\n\n",getLength(5));
	setLeft(50);printf("��Ʊ��������Ϊ0�ĳ�վ��:%d\n\n",getLength(6));
	setLeft(50);printf("����Ʊ�ĳ�����:%d\n\n",getLength(7));
	

}
void sigle(int i)
{
	int option;
	char str[20];
	system("cls");


	char *title[]={"ָ�����ε�ʼ��վ","ָ�����ε�ʼ��ʱ��","ָ�����ε��յ�վ","ָ�����ε�ȫ������ʱ��","ָ�����ε�ȫ���������",
		"ָ�����ε�Ӳ������Ʊ��","��ѯĳ����ĳ��ͣ��վ�ĵ�վʱ��","��ѯָ��������ָ����ͣ��վ�е�ָ����ͣ���ε������Ϣ",
		"ָ��ʱ�䷢������Ϊǰ�����ĳ�վ����","������һ���˵�","�˳�ϵͳ",""};
	drawMenu(title,50,10,2,true);

	option = Scanf(50,0);

	if(option == 1) FScanf(1);
		
	else if(option == 2) FScanf(2);
	else if(option == 3) FScanf(3);
	else if(option == 4) FScanf(4);
	else if(option == 5) FScanf(5);
	else if(option == 6) FScanf(6);
	else if(option == 7) FScanf(7);
	else if(option == 8)
	{
		system("cls");
		setTop(10);
		printf("������:");
		scanf("%s",strs);
		p11 =findTrain(10,strs,8);
		findTrain(10,strs,-8);
		p22=findStop(-1,p11->trainId);
		p33=findStopInf(10,p22->stationId);
		lists(31,-1,false );
		p33 = NULL ;
	}
	else if(option ==9)  FScanf(9);
	else if(option ==10) showMenu(3);
	else if(option ==11) exit(0);



}
int FScanf(int n)
{
	system("cls");
	setTop(10);
	printf("������:");
	scanf("%s",strs);
	findTrain(10,strs,n);

	return 0;
}