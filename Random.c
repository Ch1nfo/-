#include <stdio.h>
#include <stdlib.h>//生成伪随机数
#include <time.h>//生成种子
#include <stdbool.h>//分类班干部

void start();
 
typedef struct _student

{
    int num;

    char name[20];

     //非0-班干部，0-非班干部
    int leader;  

}student;
 
student stu[100];

int n=0;

int m=0;

 
int selstu(bool all,bool leader)

{
    //选取种子文件
    srand((unsigned)time(NULL));//利用系统流逝时间获得种子

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
  file_row = count + 1; //加上最后一行

  return file_row;
}
 


int main()

{

    start();
    FILE *fptr;

    int i;
    int sel = 0;
    int chk;

    printf("请输入学生人数：\n");

    scanf("%d",&n);


    if (n<=0)
    {
    
        printf("必须有人才可以点名哦!");

        exit(0);

    }

    

    
        system("cls");//调用系统命令清屏

        printf("        是否需要从文件中读取?\n\n");

        printf("        0.否\n");

        printf("        1.是\n");


        scanf("%d",&sel);

    

    if (sel<0 || sel >1)
    {

        printf("没有这个选项哦！");

        exit(0);
    }

    

    if (sel == 1)
    {

        chk = check();

        if (chk != n)
        {
        printf("Warning:文件中学生数与自定义不匹配，可能造成数据丢失!\n");
        system("pause");

        }

        
    
        if ((fptr = fopen("info.txt", "r")) == NULL)// 文件指针返回 NULL 则退出
        {
    
        printf("无法打开文件");

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
        printf("请输入学生信息:\n");

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

        printf("        请选择需要随机选择的人员范围：\n\n");

        printf("        0、程序结束\n");

        printf("        1、所有同学\n");

        printf("        2、班干部\n");

        printf("        3、非班干部\n");

        printf("        请输入您的选择：");

        scanf("%d",&sel);

        if (sel < 0 || sel > 3)
        
            printf("没有这个选项哦!");
        
    
        else if(sel == 0)

            exit(0);

        else
        {

            int idx = selstu(sel==1,sel==2);

            printf("被选中的同学是：%s\n",stu[idx].name);
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