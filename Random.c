#include <stdio.h>
#include <stdlib.h>//����α�����
#include <time.h>//��������
#include <stdbool.h>//�����ɲ�

void start();
 
typedef struct _student

{
    int num;

    char name[20];

     //��0-��ɲ���0-�ǰ�ɲ�
    int leader;  

}student;
 
student stu[100];

int n=0;

int m=0;

 
int selstu(bool all,bool leader)

{
    //ѡȡ�����ļ�
    srand((unsigned)time(NULL));//����ϵͳ����ʱ��������

    int i=0,idx = 0,num = 0;

    if(all)

        num = n;

    else if(leader)

        num = m;

    else

        num = m-n; 

    idx = rand()%num+1;

    while(1)

    {
        if(all)

            idx--;

        else if(leader && stu[i].leader)

            idx--;

        else if(!leader && !stu[i].leader)

            idx--; 

        if(idx == 0)

            break;

        i++;
    } 

    return i;

}



int check()
{
  FILE *fp;

  int flag = 0, file_row = 0, count = 0;

  if((fp = fopen("info.txt", "r")) == NULL)

    return -1;

  while(!feof(fp))
  {

    flag = fgetc(fp);

    if(flag == '\n')

      count++;
  }
  file_row = count + 1; //�������һ��

  return file_row;
}
 


int main()

{

    start();
    FILE *fptr;

    int i;
    int sel = 0;
    int chk;

    printf("������ѧ��������\n");

    scanf("%d",&n);


    if (n<=0)
    {
    
        printf("�������˲ſ��Ե���Ŷ!");

        exit(0);

    }

    

    
        system("cls");//����ϵͳ��������

        printf("        �Ƿ���Ҫ���ļ��ж�ȡ?\n\n");

        printf("        0.��\n");

        printf("        1.��\n");


        scanf("%d",&sel);

    

    if (sel<0 || sel >1)
    {

        printf("û�����ѡ��Ŷ��");

        exit(0);
    }

    

    if (sel == 1)
    {

        chk = check();

        if (chk != n)
        {
        printf("Warning:�ļ���ѧ�������Զ��岻ƥ�䣬����������ݶ�ʧ!\n");
        system("pause");

        }

        
    
        if ((fptr = fopen("info.txt", "r")) == NULL)// �ļ�ָ�뷵�� NULL ���˳�
        {
    
        printf("�޷����ļ�");

        exit(1); 

        
        }  
        
        
        
        else
        {
            
        for(i=0;i<n;i++)
        {

        fscanf(fptr,"%d %s %d",&stu[i].num,stu[i].name,&stu[i].leader);

        if(stu[i].leader)

            m++;

        }

        }

        

    }   

    else
    {
        printf("������ѧ����Ϣ:\n");

        for(i=0;i<n;i++)
        {
        scanf("%d %s %d",&stu[i].num,stu[i].name,&stu[i].leader);

        if(stu[i].leader)

            m++;
        }
        
    }

    

    

      

    while(1)
    {
        system("cls");

        printf("        ��ѡ����Ҫ���ѡ�����Ա��Χ��\n\n");

        printf("        0���������\n");

        printf("        1������ͬѧ\n");

        printf("        2����ɲ�\n");

        printf("        3���ǰ�ɲ�\n");

        printf("        ����������ѡ��");

        scanf("%d",&sel);

        if (sel < 0 || sel > 3)
        
            printf("û�����ѡ��Ŷ!");
        
    
        else if(sel == 0)

            exit(0);

        else
        {

            int idx = selstu(sel==1,sel==2);

            printf("��ѡ�е�ͬѧ�ǣ�%s\n",stu[idx].name);
        }

        system("pause");
    }
 
    return 0;

}


void start(){

    printf( "      ___ \n");
	printf( "    //   ) )\n");
	printf( "   //___/ /      ___         __        ___   /      ___        _   __\n");
	printf( "  / ___ (      //   ) )   //   ) )   //   ) /     //   ) )   // ) )  ) )\n");
	printf( " //   | |     //   / /   //   / /   //   / /     //   / /   // / /  / /\n");
	printf( "//    | |    ((___( (   //   / /   ((___/ /     ((___/ /   // / /  / /\n");
    printf( "			Welcome to use random call-- (version 1.0)	   \n");
	printf( "				                     by Ch1nfo	\n");

}