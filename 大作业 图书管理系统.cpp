#include<stdio.h>
#include<stdlib.h>//包含qsort，system库函数
#include<string.h>//用到strncpy，strstr函数
#include<time.h>//time_函数
#include<process.h>
#include<conio.h>//包含getch()库函数
#define N 100
#define Q "%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",book[i].number,book[i].name,book[i].author,book[i].publish_place,book[i].publish_time,book[i].borrow_condition,book[i].return_condition,book[i].lend_time,book[i].return_time,book[i].students_number
#define P "图书编号  书名\t\t 作者\t   出版社\t  出版时间  借出状态  归还状态  借出时间  归还时间 借阅人编号\n"  //宏定义，减少代码量
typedef struct infor1{
 long int number;
 char name[15];
 char author[10];
 char publish_place[15];
 long int publish_time;
 char borrow_condition[6];
 char return_condition[6];
 long int lend_time;
 long int return_time;
 long int students_number;
}BOOK;
typedef struct infor2{
long int students_number;
char phonenumber[13];
char adress[20];
int borrow_number;
long int number[3];
long int lend_time[3];
int owe_money;
}BORROW;
void screen();//屏幕背景处理函数
void menu1();//主菜单函数
void menu2();//图书信息系统菜单函数
void save();//将图书信息写入D盘中的文件函数
void save2();//将个人信息写入文件函数
void infor_system(BOOK *);//图书信息系统总函数
void borrow_system();//借阅系统总函数
void search_system();//查询系统总函数
void search_handle(int p);//判断查询结果是否存在函数
void number_search();//书编号查询函数
void name_search();//书名查询函数
void author_search();//作者查询函数
void publish_time_search();//出版时间查询函数
void borrow_condition_search();//是否借出查询函数
void ifborrow(int a);//判断借书是否成功判断
int int_search(long int a,long int b);//数字前缀匹配函数
int char_search(char a[],char b[]);//字符前缀匹配函数
int money(long int x);//计算欠费金额函数
void bye_bye();//退出系统函数
void create(int y);//新建图书函数
void delete_();//删除图书函数
time_t maketime_t(char* date1);//计算时间函数
int day_of_day( char *date1, char *date2);//计算天数间隔函数
int cmp( const void *a ,const void *b);//排序函数的排序依据函数
   BORROW borrow[N]={
     {20150001,"","",2,{19800000,19415487},{20160315,20160421},},
     {20150002,"","",2,{19702514,19625472,},{20160506,20160502,},},
     {20150003,"","",1,{19700025},{20160501},},
     {20150004,"","",3,{19502145,19951547,19425041},{20160515,20160524,20160524},},
     {20150005,"","",0,{00000000},{00000000},},
     {20150006,"","",0,{00000000},{00000000},},
     {20150007,"","",0,{00000000},{00000000},},
     {20150008,"","",0,{00000000},{00000000},},
     {20150009,"","",0,{00000000},{00000000},},
     {20150010,"","",0,{00000000},{00000000},}
   };//借阅人信息结构体的初始化
   BOOK book[N]={
    {19800000,"c++primer","Jakson","beijing",19940203,"true", "false",20160315,20160201,20150001},/*数字00000000表示未归还或未借出*/
    {19800050,"c primer","Jakie","shanghai",20160201,"false","true",00000000,20160301,00000000},
    {19700025,"c primer plus","Blackwite","tianjin",19980802,"true","false",20160501,20160104,20150003},
    {19702514,"beautiful c!","Clarkson","xi'andianzi" ,20130205,"true","false",20160506,20160305,20150002},
    {19600254,"translation","Aliceer","nanjing",20090121,"false","true",00000000,20160504,00000000},
    {19625472,"three boys","Moyan","dalian",20030214,"true","false",20160502,20160304,20150002},
    {19502145,"my mom","Moyan","shandong",19980214,"true","false",20160515,20160405,20150004},
    {19951547,"my dad","Er'gen","shanxi",20140421,"true","false",20160524,20160203,20150004},
    {19425014,"my uncle","Zhang wei","beijing",19981104,"true","false",20160524,20160603,20150004},
    {19415487,"my sister","xiejie","hefei",20080901,"true","false",20160421,20160304,20150001}
   };//图书信息结构体的初始化
 int i,count=10,j;//定义全局变量，count是当前存放书的数量
  int main(){
        screen();
        save();
        save2();
        menu1();
        return 0;
  }
 void screen(){
    system("title 图书管理系统");//设置窗口标题
    system("mode con cols=150 ");//窗口宽度高度
    system("color 2B");//设置背景和字体颜色
 }
 void menu1(){
    int x;
    printf("\n\n\t\t\t\t\t\t欢迎进入图书管理系统！\n");
    printf("\n\n\t\t\t\t********************主菜单***********************\n");
    printf("\n\t\t\t\t   1.图书信息系统\n");
    printf("\t\t\t\t   2.图书检索系统\n");
    printf("\t\t\t\t   3.图书借阅系统\n");
    printf("\t\t\t\t   0.退出\n");
    printf("\n\t\t\t\t************************************************\n\n\n");
    printf("请输入您的指令：");
    scanf("%d",&x);
  switch (x){
    case 0:bye_bye();break;
    case 1:infor_system(book);break;
    case 2:search_system();break;
    case 3:borrow_system();break;
    default:printf("输入有误！请重新输入！");//switch语句进行操作选择
            getch();//接受回车符
            menu1();//返回主菜单
    }
 }
void menu2(){
 int j;//数字表示选项
  printf("接下来去您想：\n");
  printf("\n\n\t\t\t\t********************菜单***********************\n");
  printf("\n\t\t\t\t   1.添加图书信息\n");
  printf("\t\t\t\t   2.删除图书信息\n");
  printf("\t\t\t\t   3.返回主菜单\n");
  printf("\t\t\t\t   0.退出\n");
  printf("\n\t\t\t\t************************************************\n\n\n");
  scanf("%d",&j);
   switch(j){
    case 0:bye_bye();break;//退出系统
    case 1:create(count);break;
    case 2:delete_();break;
    case 3:menu1();break;
    default:printf("\t\t输入有误！按任意键返回主菜单返回主菜单。");
        fflush(stdin);//清空输入缓冲区
        getch();//随意按一个键
        menu1();//返回主菜单
    }
}
void infor_system(BOOK*s){//形参为指向结构体的指针
    printf("馆藏图书：\n");
    printf(P);//P,Q为宏定义
    for(i=0;i<count;i++)
        if(book[i].number!=0)
        printf(Q);//输出馆藏图书的目录
    menu2();//返回图书信息系统菜单
}
void save(){
    qsort(book,count,sizeof(book[0]),cmp);
    FILE *fp;
     if( ( fp = fopen("D://f1.txt", "w") ) == NULL){	/* 打开文件 */
   	    printf("File open error!\n");
   	    exit(0);
     }
   fprintf(fp,P);
     for(i=0;i<count;i++)
        if(book[i].number!=0)//将图书信息写入f1.txt文件
        fprintf(fp,"%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",&book[i].number,&book[i].name,&book[i].author,&book[i].publish_place,
                &book[i].publish_time,&book[i].borrow_condition,&book[i].return_condition,&book[i].lend_time,&book[i].return_time,&book[i].students_number);
      if( fclose( fp ) ){			             /* 关闭文件 */
        printf( "Can not close the file!\n" );
        exit(0);
      }
}
void save2(){
FILE *fp;
    if( ( fp = fopen("D://f2.txt", "w") ) == NULL){	/* 打开文件 */
   	    printf("File open error!\n");
   	    exit(0);
    }
   fprintf(fp,"学号\t  联系方式   \t 通讯地址   \t已借图书  图书编号  借出时间  欠费金额  \n");
     for(i=0;i<10;i++){
        if(borrow[i].number!=0)//将个人借阅信息写入f2.txt文件
        fprintf(fp,"%-10ld%-15s%-15s%-10d%-10ld%-10ld%-10d\n",&borrow[i].students_number,borrow[i].phonenumber,borrow[i].adress,
                &borrow[i].borrow_number,&borrow[i].number[0],&borrow[i].lend_time[0],&borrow[i].owe_money);
      if(borrow[i].number[1]!=0)
        fprintf(fp,"\t\t\t\t\t\t  %-10ld%-10ld\n",&borrow[i].number[1],&borrow[i].lend_time[1]);
         if(borrow[i].number[2]!=0)
        fprintf(fp,"\t\t\t\t\t\t  %-10ld%-10ld\n",&borrow[i].number[2],&borrow[i].lend_time[2]);
     }
       if( fclose( fp ) ){			             /* 关闭文件 */
        printf( "Can not close the file!\n" );
        exit(0);
       }
}
void create(int y){//y为当前书的数量
    FILE *fp;
  if(y<=100){//判断图书数是否小于100
    if( ( fp = fopen("D://f1.txt", "w") ) == NULL){	/* 打开文件 */
       printf("File open error!\n");
       exit(0);
    }
    printf("请输入添加图书的信息\n");
    scanf("%ld%s%s%s%ld%s%s%ld%ld%ld",&book[count].number,book[count].name,book[count].author,book[count].publish_place,&book[count].publish_time,
          book[count].borrow_condition,
          book[count].return_condition,
          &book[count].lend_time,&book[count].return_time,&book[count].students_number);
          if(book[count].number!=0)
    fprintf(fp,"%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",&book[count].number,&book[count].name,&book[count].author,&book[count].publish_place,
                &book[count].publish_time,&book[count].borrow_condition,&book[count].return_condition,&book[count].lend_time,&book[count].return_time,&book[count].students_number);
    count++;//添加后图书数量加1
   }
    save();//将新的图书信息保存进文件
    printf("新的馆藏图书目录：\n");
    for(i=0;i<count;i++)
    if(book[i].number!=0)
    printf("%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",book[i].number,book[i].name,book[i].author,book[i].publish_place,
                book[i].publish_time,book[i].borrow_condition,book[i].return_condition,book[i].lend_time,book[i].return_time,book[i].students_number);
  menu2();
}
void delete_(){
    long int z,k;
   printf("\t\t请输入您要删除图书的编号：\n");
   scanf("%ld",&z);
   for(k=0;k<=count;k++)
     if(book[k].number==z)
      book[k].number=0;//找到输入的编号
   save();//将删除后的图书信息保存进文件
    printf("新的馆藏图书目录：\n");//输出删除后的目录
   for(i=0;i<count;i++)
    if(book[i].number!=0)
     printf("%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",book[i].number,book[i].name,book[i].author,book[i].publish_place,
                book[i].publish_time,book[i].borrow_condition,book[i].return_condition,book[i].lend_time,book[i].return_time,book[i].students_number);
   menu2();
}
void search_system(){//查询选项
      int m;//数字选项
    printf("\t\t请问您想以何种检索方式检索：");
    printf("\n\t\t\t\t   1.编号查询\n");
    printf("\t\t\t\t   2.书名查询\n");
    printf("\t\t\t\t   3.作者查询\n");
    printf("\t\t\t\t   4.出版时间查询\n");
    printf("\t\t\t\t   5.是否借出查询\n");
    printf("\t\t\t\t   6.返回主菜单\n");
    scanf("%d",&m);
 switch(m){
  case 1:number_search();break;
  case 2:name_search();break;
  case 3:author_search();break;
  case 4:publish_time_search();
  case 5:borrow_condition_search();//调用查询函数
  case 6:menu1();
  default:printf("\t\t输入有误！即将返回主菜单");
        system("pause");
        menu1();
  }
}
void number_search(){
    long int z,p=0;//z为查询的书编号
    printf("\t\t请输入您想要查询书的编号:\n");
    scanf("%ld",&z);
    for(i=0;i<count;i++)
     if(book[i].number!=0)
        if(int_search(book[i].number,z)){
              printf(Q);
             p++;//通过判断p是否为0进而确定查询结果是否存在
        }
    search_handle(p);//判断查询结果是否存在
}
void publish_time_search(){
    long int z,p=0;
    printf("\t\t请输入您想要查询书的出版时间:\n");
    scanf("%ld",&z);
    for(i=0;i<count;i++)
    if(book[i].number!=0)
      if(int_search(book[i].publish_time,z)){//判断是否数字前缀匹配
        printf(Q);
        p++;
      }
    search_handle(p);
}
void name_search(){
   int p=0;
   char a[20];
   printf("\t\t请输入您想要查询书的名字:\n");
   fflush(stdin);
   gets(a);//输入书名
   for(i=0;i<count;i++)
      if(book[i].number!=0)
         if(char_search(book[i].name,a)){//判断字符匹配（可前缀查询）
            printf(Q);
            p++;//通过判断p是否为0进而确定查询结果是否存在
         }
    search_handle(p);//判断查询结果是否存在
}
void author_search(){
   int p=0;
   char a[20];
   printf("\t\t请输入您想要查询书的作者名字:\n");
   fflush(stdin);
   gets(a);
   for(i=0;i<count;i++)
   if(book[i].number!=0)//判断是否为有效的图书
     if(char_search(book[i].author,a)){
        printf(Q);
        p++;
     }
  search_handle(p);//判断查询结果是否存在
}
void borrow_condition_search(){
   int p=0;
   char a[20];
   printf("\t\t请输入您想要查询书的借出状态:\n");
   fflush(stdin);//清空输入缓冲区，为了确保不影响后面的数据读取
   gets(a);//输入借出状态
   for(i=0;i<count&&book[i].publish_time!=0;i++)
      if(char_search(book[i].borrow_condition,a)){
      printf(Q);
      p++;
      }
   search_handle(p);
}
void search_handle(int p){
    int q;
    if(p==0){//p=0表示未查到
    printf("对不起，没有您想要的图书！");
    printf("即将返回上一层\n");
    system("pause");
    search_system();//返回查询界面
    }
 else {
   printf("\t\t接下来您想：\n");
   printf("\t\t\t\t   1.继续查询\n");
   printf("\t\t\t\t   2.返回主菜单\n");
   scanf("%d",&q);//q为指令选项
   switch(q){
        case 1:search_system();break;
        case 2:menu1();break;
        default:printf("\t\t输入有误！即将返回主菜单");
        system("pause");
        menu1();
   }
 }
}
int int_search(long int a,long int b){
     char astr[20], bstr[20];
     sprintf(astr, "%d", a);
     sprintf(bstr, "%d", b);//将a，b存进字符串数组
     return strstr(astr, bstr) == astr;//利用strstr库函数查询前缀
}
void borrow_system(){
    long int keynumber,key;//keynumber为输入的学号，key为匹配的结构体数组下标
    int d;
    printf("\t\t请输入您的个人信息：\n");
    printf("\t\t请输入您的学号：\n");
    scanf("%ld",&keynumber);
    fflush(stdin);
    for(i=0;i<N;i++){
        borrow[i].owe_money=0;//初始化欠费金额
         if(keynumber==borrow[i].students_number)
          key=i;
    }
    printf("\t\t请输入您的联系方式：\n");//输入个人信息
    gets(borrow[key].phonenumber);
    fflush(stdin);
    printf("\t\t请输入您的住址：\n");
    gets(borrow[key].adress);
    for(i=0;i<borrow[key].borrow_number;i++)
        borrow[key].owe_money+=money(borrow[key].lend_time[i]);//计算欠费金额
    save2();//保存个人信息
    printf("您的个人信息：\n");//输出个人信息
    printf("学号\t  联系方式   \t 通讯地址   \t已借图书  图书编号  借出时间  欠费金额  \n");//输出新的个人信息
    printf("%-10ld%-15s%-15s%-10d%-10ld%-10ld%-10d\n",borrow[key].students_number,borrow[key].phonenumber,borrow[key].adress,borrow[key].borrow_number,borrow[key].number[0],borrow[key].lend_time[0],borrow[key].owe_money);
    if(borrow[key].number[1]!=0)
        printf("\t\t\t\t\t\t  %-10ld%-10ld\n",borrow[key].number[1],borrow[key].lend_time[1]);
    if(borrow[key].number[2]!=0)
        printf("\t\t\t\t\t\t  %-10ld%-10ld\n",borrow[key].number[2],borrow[key].lend_time[2]);
    printf("接下来您想：\n");
    printf("\t\t1.借书\n");
    printf("\t\t2.返回主菜单\n");
    scanf("%d",&d);
    switch(d){
        case 1:ifborrow(key);break;//判断借书是否成功
        case 2:menu1();break;
        default:printf("\t\t输入有误！按任意键返回主菜单返回主菜单。");
        fflush(stdin);
        getch();
        menu1();
        }
}
void ifborrow(int key){
    long int y;int p;
    char *m="true",*n="false";
    printf("请输入您要借的图书编号；\n\t\t");
    scanf("%ld",&y);
    if(borrow[key].owe_money!=0){
       printf("\t\t借阅失败：您的账户已欠费，请您尽快缴费！\n");
       printf("\t\t按任意键返回主菜单\n");
       system("pause");
       menu1();
    }
   for(i=0;i<=count;i++)
     if(y==book[i].number){
        if(book[i].borrow_condition=="true"){//判断书的借出状态
          printf("对不起，该书已被他人借阅！\n");
          printf("\t\t按任意键返回主菜单");
          system("pause");
          menu1();
         }
      else if(borrow[key].borrow_number==3){//判断已借书数
             printf("对不起，您的借书数已达上限！\n");
             printf("\t\t按任意键返回主菜单\n");
             system("pause");
             menu1();
            }
           else {
               printf("借书成功，请您在规定时间内归还!\n");
               strcpy(book[i].borrow_condition,"true");//修改图书信息
               strcpy(book[i].return_condition,"false");
               book[i].lend_time=20160527;//修改个人信息
               book[i].students_number=borrow[key].students_number;
               save();//将改过的信息存入文件
               borrow[key].borrow_number++;
               borrow[key].number[borrow[key].borrow_number-1]=y;
               borrow[key].lend_time[borrow[key].borrow_number-1]=20160527;
            }
           printf("接下来您想：\n");
           printf("\t\t1.继续借阅\n");
           printf("\t\t2.查看个人信息\n");
           printf("\t\t3.返回主菜单\n");
           scanf("%d",&p);
           switch(p){
                 case 1:ifborrow(key);break;
                 case 2: printf("学号\t  联系方式   \t 通讯地址   \t已借图书  图书编号  借出时间  欠费金额  \n");
                 printf("%-10ld%-15s%-15s%-10d%-10ld%-10ld%-10d\n",borrow[key].students_number,borrow[key].phonenumber,borrow[key].adress,borrow[key].borrow_number,borrow[key].number[0],borrow[key].lend_time[0],borrow[key].owe_money);
                 if(borrow[key].number[1]!=0)
                     printf("\t\t\t\t\t\t  %-10ld%-10ld\n",borrow[key].number[1],borrow[key].lend_time[1]);
                 if(borrow[key].number[2]!=0)
                     printf("\t\t\t\t\t\t  %-10ld%-10ld\n",borrow[key].number[2],borrow[key].lend_time[2]);
                 printf("\t\t按任意键返回主菜单\n");
                 system("pause");//等待用户按一个键，然后返回
                 menu1();break;
                 case 3:menu1();break;
                 defalut:menu1();
           }
          break;
     }
}
int money(long int q ){
    char a[10],b[10],*m,*n;//定义指针指向字符数组
    m=a;n=b;
    int days,s=0;
    sprintf(a, "%d", 20160527);//以5月27日为今天计算欠费金额
    sprintf(b, "%d", q);//将日期存入字符数组中
    days=day_of_day(m, n);//计算两个时间的天数
    if(days>30&&days<=60)//计算金额
      s=days-30;
    if(days>60)
      s=30+2*(days-60);
return s;
}
int char_search(char astr[],char bstr[]){

     return strstr(astr, bstr) == astr;
}
int cmp( const void *a ,const void *b)
{
return (*(BOOK *)a).number > (*(BOOK *)b).number ? 1 : -1;
//若指针a指向的结构体数组元素中图书编号小于指针b，则返回1，反之返回-1
}
void bye_bye(){
  printf("\t\t");
  printf("\n\t\t感谢您的使用，再见！\n");
}
time_t maketime_t(char* date1)
{
  struct tm tm0;
  char str0[4];
  memset( &tm0, 0, sizeof(tm0));//字符数组初始化
  memset( str0, 0, 4);
  strncpy(str0, date1, 4);//取出年份
  tm0.tm_year = atoi(str0) - 1900;  //1900年开始
  memset( str0, 0, 4);
  strncpy(str0, &date1[4], 2);//取出月份
  tm0.tm_mon = atoi(str0) - 1;  //0-11月份
  memset( str0, 0, 4);
  strncpy(str0, &date1[6], 2);//取出天数
  tm0.tm_mday = atoi(str0);  //1-31天
  return mktime(&tm0);
}

int day_of_day( char *date1, char *date2)
{
  struct tm tm0;
  char str0[4];
  double diff_seconds;//单位为秒
  time_t time_t1, time_t2;
  time_t1 = maketime_t(date1);
  time_t2 = maketime_t(date2);
  diff_seconds = difftime(time_t1, time_t2);//秒数
  return diff_seconds>0? (int)(diff_seconds/3600/24):(int)((-1)*diff_seconds/3600/24);//转化为天数
}
