#include<stdio.h>
#include<stdlib.h>//����qsort��system�⺯��
#include<string.h>//�õ�strncpy��strstr����
#include<time.h>//time_����
#include<process.h>
#include<conio.h>//����getch()�⺯��
#define N 100
#define Q "%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",book[i].number,book[i].name,book[i].author,book[i].publish_place,book[i].publish_time,book[i].borrow_condition,book[i].return_condition,book[i].lend_time,book[i].return_time,book[i].students_number
#define P "ͼ����  ����\t\t ����\t   ������\t  ����ʱ��  ���״̬  �黹״̬  ���ʱ��  �黹ʱ�� �����˱��\n"  //�궨�壬���ٴ�����
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
void screen();//��Ļ����������
void menu1();//���˵�����
void menu2();//ͼ����Ϣϵͳ�˵�����
void save();//��ͼ����Ϣд��D���е��ļ�����
void save2();//��������Ϣд���ļ�����
void infor_system(BOOK *);//ͼ����Ϣϵͳ�ܺ���
void borrow_system();//����ϵͳ�ܺ���
void search_system();//��ѯϵͳ�ܺ���
void search_handle(int p);//�жϲ�ѯ����Ƿ���ں���
void number_search();//���Ų�ѯ����
void name_search();//������ѯ����
void author_search();//���߲�ѯ����
void publish_time_search();//����ʱ���ѯ����
void borrow_condition_search();//�Ƿ�����ѯ����
void ifborrow(int a);//�жϽ����Ƿ�ɹ��ж�
int int_search(long int a,long int b);//����ǰ׺ƥ�亯��
int char_search(char a[],char b[]);//�ַ�ǰ׺ƥ�亯��
int money(long int x);//����Ƿ�ѽ���
void bye_bye();//�˳�ϵͳ����
void create(int y);//�½�ͼ�麯��
void delete_();//ɾ��ͼ�麯��
time_t maketime_t(char* date1);//����ʱ�亯��
int day_of_day( char *date1, char *date2);//���������������
int cmp( const void *a ,const void *b);//���������������ݺ���
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
   };//��������Ϣ�ṹ��ĳ�ʼ��
   BOOK book[N]={
    {19800000,"c++primer","Jakson","beijing",19940203,"true", "false",20160315,20160201,20150001},/*����00000000��ʾδ�黹��δ���*/
    {19800050,"c primer","Jakie","shanghai",20160201,"false","true",00000000,20160301,00000000},
    {19700025,"c primer plus","Blackwite","tianjin",19980802,"true","false",20160501,20160104,20150003},
    {19702514,"beautiful c!","Clarkson","xi'andianzi" ,20130205,"true","false",20160506,20160305,20150002},
    {19600254,"translation","Aliceer","nanjing",20090121,"false","true",00000000,20160504,00000000},
    {19625472,"three boys","Moyan","dalian",20030214,"true","false",20160502,20160304,20150002},
    {19502145,"my mom","Moyan","shandong",19980214,"true","false",20160515,20160405,20150004},
    {19951547,"my dad","Er'gen","shanxi",20140421,"true","false",20160524,20160203,20150004},
    {19425014,"my uncle","Zhang wei","beijing",19981104,"true","false",20160524,20160603,20150004},
    {19415487,"my sister","xiejie","hefei",20080901,"true","false",20160421,20160304,20150001}
   };//ͼ����Ϣ�ṹ��ĳ�ʼ��
 int i,count=10,j;//����ȫ�ֱ�����count�ǵ�ǰ����������
  int main(){
        screen();
        save();
        save2();
        menu1();
        return 0;
  }
 void screen(){
    system("title ͼ�����ϵͳ");//���ô��ڱ���
    system("mode con cols=150 ");//���ڿ�ȸ߶�
    system("color 2B");//���ñ�����������ɫ
 }
 void menu1(){
    int x;
    printf("\n\n\t\t\t\t\t\t��ӭ����ͼ�����ϵͳ��\n");
    printf("\n\n\t\t\t\t********************���˵�***********************\n");
    printf("\n\t\t\t\t   1.ͼ����Ϣϵͳ\n");
    printf("\t\t\t\t   2.ͼ�����ϵͳ\n");
    printf("\t\t\t\t   3.ͼ�����ϵͳ\n");
    printf("\t\t\t\t   0.�˳�\n");
    printf("\n\t\t\t\t************************************************\n\n\n");
    printf("����������ָ�");
    scanf("%d",&x);
  switch (x){
    case 0:bye_bye();break;
    case 1:infor_system(book);break;
    case 2:search_system();break;
    case 3:borrow_system();break;
    default:printf("�����������������룡");//switch�����в���ѡ��
            getch();//���ܻس���
            menu1();//�������˵�
    }
 }
void menu2(){
 int j;//���ֱ�ʾѡ��
  printf("������ȥ���룺\n");
  printf("\n\n\t\t\t\t********************�˵�***********************\n");
  printf("\n\t\t\t\t   1.���ͼ����Ϣ\n");
  printf("\t\t\t\t   2.ɾ��ͼ����Ϣ\n");
  printf("\t\t\t\t   3.�������˵�\n");
  printf("\t\t\t\t   0.�˳�\n");
  printf("\n\t\t\t\t************************************************\n\n\n");
  scanf("%d",&j);
   switch(j){
    case 0:bye_bye();break;//�˳�ϵͳ
    case 1:create(count);break;
    case 2:delete_();break;
    case 3:menu1();break;
    default:printf("\t\t�������󣡰�������������˵��������˵���");
        fflush(stdin);//������뻺����
        getch();//���ⰴһ����
        menu1();//�������˵�
    }
}
void infor_system(BOOK*s){//�β�Ϊָ��ṹ���ָ��
    printf("�ݲ�ͼ�飺\n");
    printf(P);//P,QΪ�궨��
    for(i=0;i<count;i++)
        if(book[i].number!=0)
        printf(Q);//����ݲ�ͼ���Ŀ¼
    menu2();//����ͼ����Ϣϵͳ�˵�
}
void save(){
    qsort(book,count,sizeof(book[0]),cmp);
    FILE *fp;
     if( ( fp = fopen("D://f1.txt", "w") ) == NULL){	/* ���ļ� */
   	    printf("File open error!\n");
   	    exit(0);
     }
   fprintf(fp,P);
     for(i=0;i<count;i++)
        if(book[i].number!=0)//��ͼ����Ϣд��f1.txt�ļ�
        fprintf(fp,"%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",&book[i].number,&book[i].name,&book[i].author,&book[i].publish_place,
                &book[i].publish_time,&book[i].borrow_condition,&book[i].return_condition,&book[i].lend_time,&book[i].return_time,&book[i].students_number);
      if( fclose( fp ) ){			             /* �ر��ļ� */
        printf( "Can not close the file!\n" );
        exit(0);
      }
}
void save2(){
FILE *fp;
    if( ( fp = fopen("D://f2.txt", "w") ) == NULL){	/* ���ļ� */
   	    printf("File open error!\n");
   	    exit(0);
    }
   fprintf(fp,"ѧ��\t  ��ϵ��ʽ   \t ͨѶ��ַ   \t�ѽ�ͼ��  ͼ����  ���ʱ��  Ƿ�ѽ��  \n");
     for(i=0;i<10;i++){
        if(borrow[i].number!=0)//�����˽�����Ϣд��f2.txt�ļ�
        fprintf(fp,"%-10ld%-15s%-15s%-10d%-10ld%-10ld%-10d\n",&borrow[i].students_number,borrow[i].phonenumber,borrow[i].adress,
                &borrow[i].borrow_number,&borrow[i].number[0],&borrow[i].lend_time[0],&borrow[i].owe_money);
      if(borrow[i].number[1]!=0)
        fprintf(fp,"\t\t\t\t\t\t  %-10ld%-10ld\n",&borrow[i].number[1],&borrow[i].lend_time[1]);
         if(borrow[i].number[2]!=0)
        fprintf(fp,"\t\t\t\t\t\t  %-10ld%-10ld\n",&borrow[i].number[2],&borrow[i].lend_time[2]);
     }
       if( fclose( fp ) ){			             /* �ر��ļ� */
        printf( "Can not close the file!\n" );
        exit(0);
       }
}
void create(int y){//yΪ��ǰ�������
    FILE *fp;
  if(y<=100){//�ж�ͼ�����Ƿ�С��100
    if( ( fp = fopen("D://f1.txt", "w") ) == NULL){	/* ���ļ� */
       printf("File open error!\n");
       exit(0);
    }
    printf("���������ͼ�����Ϣ\n");
    scanf("%ld%s%s%s%ld%s%s%ld%ld%ld",&book[count].number,book[count].name,book[count].author,book[count].publish_place,&book[count].publish_time,
          book[count].borrow_condition,
          book[count].return_condition,
          &book[count].lend_time,&book[count].return_time,&book[count].students_number);
          if(book[count].number!=0)
    fprintf(fp,"%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",&book[count].number,&book[count].name,&book[count].author,&book[count].publish_place,
                &book[count].publish_time,&book[count].borrow_condition,&book[count].return_condition,&book[count].lend_time,&book[count].return_time,&book[count].students_number);
    count++;//��Ӻ�ͼ��������1
   }
    save();//���µ�ͼ����Ϣ������ļ�
    printf("�µĹݲ�ͼ��Ŀ¼��\n");
    for(i=0;i<count;i++)
    if(book[i].number!=0)
    printf("%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",book[i].number,book[i].name,book[i].author,book[i].publish_place,
                book[i].publish_time,book[i].borrow_condition,book[i].return_condition,book[i].lend_time,book[i].return_time,book[i].students_number);
  menu2();
}
void delete_(){
    long int z,k;
   printf("\t\t��������Ҫɾ��ͼ��ı�ţ�\n");
   scanf("%ld",&z);
   for(k=0;k<=count;k++)
     if(book[k].number==z)
      book[k].number=0;//�ҵ�����ı��
   save();//��ɾ�����ͼ����Ϣ������ļ�
    printf("�µĹݲ�ͼ��Ŀ¼��\n");//���ɾ�����Ŀ¼
   for(i=0;i<count;i++)
    if(book[i].number!=0)
     printf("%-10ld%-15s%-10s%-15s%-10ld%-10s%-10s%-10ld%-10ld%-10ld\n",book[i].number,book[i].name,book[i].author,book[i].publish_place,
                book[i].publish_time,book[i].borrow_condition,book[i].return_condition,book[i].lend_time,book[i].return_time,book[i].students_number);
   menu2();
}
void search_system(){//��ѯѡ��
      int m;//����ѡ��
    printf("\t\t���������Ժ��ּ�����ʽ������");
    printf("\n\t\t\t\t   1.��Ų�ѯ\n");
    printf("\t\t\t\t   2.������ѯ\n");
    printf("\t\t\t\t   3.���߲�ѯ\n");
    printf("\t\t\t\t   4.����ʱ���ѯ\n");
    printf("\t\t\t\t   5.�Ƿ�����ѯ\n");
    printf("\t\t\t\t   6.�������˵�\n");
    scanf("%d",&m);
 switch(m){
  case 1:number_search();break;
  case 2:name_search();break;
  case 3:author_search();break;
  case 4:publish_time_search();
  case 5:borrow_condition_search();//���ò�ѯ����
  case 6:menu1();
  default:printf("\t\t�������󣡼����������˵�");
        system("pause");
        menu1();
  }
}
void number_search(){
    long int z,p=0;//zΪ��ѯ������
    printf("\t\t����������Ҫ��ѯ��ı��:\n");
    scanf("%ld",&z);
    for(i=0;i<count;i++)
     if(book[i].number!=0)
        if(int_search(book[i].number,z)){
              printf(Q);
             p++;//ͨ���ж�p�Ƿ�Ϊ0����ȷ����ѯ����Ƿ����
        }
    search_handle(p);//�жϲ�ѯ����Ƿ����
}
void publish_time_search(){
    long int z,p=0;
    printf("\t\t����������Ҫ��ѯ��ĳ���ʱ��:\n");
    scanf("%ld",&z);
    for(i=0;i<count;i++)
    if(book[i].number!=0)
      if(int_search(book[i].publish_time,z)){//�ж��Ƿ�����ǰ׺ƥ��
        printf(Q);
        p++;
      }
    search_handle(p);
}
void name_search(){
   int p=0;
   char a[20];
   printf("\t\t����������Ҫ��ѯ�������:\n");
   fflush(stdin);
   gets(a);//��������
   for(i=0;i<count;i++)
      if(book[i].number!=0)
         if(char_search(book[i].name,a)){//�ж��ַ�ƥ�䣨��ǰ׺��ѯ��
            printf(Q);
            p++;//ͨ���ж�p�Ƿ�Ϊ0����ȷ����ѯ����Ƿ����
         }
    search_handle(p);//�жϲ�ѯ����Ƿ����
}
void author_search(){
   int p=0;
   char a[20];
   printf("\t\t����������Ҫ��ѯ�����������:\n");
   fflush(stdin);
   gets(a);
   for(i=0;i<count;i++)
   if(book[i].number!=0)//�ж��Ƿ�Ϊ��Ч��ͼ��
     if(char_search(book[i].author,a)){
        printf(Q);
        p++;
     }
  search_handle(p);//�жϲ�ѯ����Ƿ����
}
void borrow_condition_search(){
   int p=0;
   char a[20];
   printf("\t\t����������Ҫ��ѯ��Ľ��״̬:\n");
   fflush(stdin);//������뻺������Ϊ��ȷ����Ӱ���������ݶ�ȡ
   gets(a);//������״̬
   for(i=0;i<count&&book[i].publish_time!=0;i++)
      if(char_search(book[i].borrow_condition,a)){
      printf(Q);
      p++;
      }
   search_handle(p);
}
void search_handle(int p){
    int q;
    if(p==0){//p=0��ʾδ�鵽
    printf("�Բ���û������Ҫ��ͼ�飡");
    printf("����������һ��\n");
    system("pause");
    search_system();//���ز�ѯ����
    }
 else {
   printf("\t\t���������룺\n");
   printf("\t\t\t\t   1.������ѯ\n");
   printf("\t\t\t\t   2.�������˵�\n");
   scanf("%d",&q);//qΪָ��ѡ��
   switch(q){
        case 1:search_system();break;
        case 2:menu1();break;
        default:printf("\t\t�������󣡼����������˵�");
        system("pause");
        menu1();
   }
 }
}
int int_search(long int a,long int b){
     char astr[20], bstr[20];
     sprintf(astr, "%d", a);
     sprintf(bstr, "%d", b);//��a��b����ַ�������
     return strstr(astr, bstr) == astr;//����strstr�⺯����ѯǰ׺
}
void borrow_system(){
    long int keynumber,key;//keynumberΪ�����ѧ�ţ�keyΪƥ��Ľṹ�������±�
    int d;
    printf("\t\t���������ĸ�����Ϣ��\n");
    printf("\t\t����������ѧ�ţ�\n");
    scanf("%ld",&keynumber);
    fflush(stdin);
    for(i=0;i<N;i++){
        borrow[i].owe_money=0;//��ʼ��Ƿ�ѽ��
         if(keynumber==borrow[i].students_number)
          key=i;
    }
    printf("\t\t������������ϵ��ʽ��\n");//���������Ϣ
    gets(borrow[key].phonenumber);
    fflush(stdin);
    printf("\t\t����������סַ��\n");
    gets(borrow[key].adress);
    for(i=0;i<borrow[key].borrow_number;i++)
        borrow[key].owe_money+=money(borrow[key].lend_time[i]);//����Ƿ�ѽ��
    save2();//���������Ϣ
    printf("���ĸ�����Ϣ��\n");//���������Ϣ
    printf("ѧ��\t  ��ϵ��ʽ   \t ͨѶ��ַ   \t�ѽ�ͼ��  ͼ����  ���ʱ��  Ƿ�ѽ��  \n");//����µĸ�����Ϣ
    printf("%-10ld%-15s%-15s%-10d%-10ld%-10ld%-10d\n",borrow[key].students_number,borrow[key].phonenumber,borrow[key].adress,borrow[key].borrow_number,borrow[key].number[0],borrow[key].lend_time[0],borrow[key].owe_money);
    if(borrow[key].number[1]!=0)
        printf("\t\t\t\t\t\t  %-10ld%-10ld\n",borrow[key].number[1],borrow[key].lend_time[1]);
    if(borrow[key].number[2]!=0)
        printf("\t\t\t\t\t\t  %-10ld%-10ld\n",borrow[key].number[2],borrow[key].lend_time[2]);
    printf("���������룺\n");
    printf("\t\t1.����\n");
    printf("\t\t2.�������˵�\n");
    scanf("%d",&d);
    switch(d){
        case 1:ifborrow(key);break;//�жϽ����Ƿ�ɹ�
        case 2:menu1();break;
        default:printf("\t\t�������󣡰�������������˵��������˵���");
        fflush(stdin);
        getch();
        menu1();
        }
}
void ifborrow(int key){
    long int y;int p;
    char *m="true",*n="false";
    printf("��������Ҫ���ͼ���ţ�\n\t\t");
    scanf("%ld",&y);
    if(borrow[key].owe_money!=0){
       printf("\t\t����ʧ�ܣ������˻���Ƿ�ѣ���������ɷѣ�\n");
       printf("\t\t��������������˵�\n");
       system("pause");
       menu1();
    }
   for(i=0;i<=count;i++)
     if(y==book[i].number){
        if(book[i].borrow_condition=="true"){//�ж���Ľ��״̬
          printf("�Բ��𣬸����ѱ����˽��ģ�\n");
          printf("\t\t��������������˵�");
          system("pause");
          menu1();
         }
      else if(borrow[key].borrow_number==3){//�ж��ѽ�����
             printf("�Բ������Ľ������Ѵ����ޣ�\n");
             printf("\t\t��������������˵�\n");
             system("pause");
             menu1();
            }
           else {
               printf("����ɹ��������ڹ涨ʱ���ڹ黹!\n");
               strcpy(book[i].borrow_condition,"true");//�޸�ͼ����Ϣ
               strcpy(book[i].return_condition,"false");
               book[i].lend_time=20160527;//�޸ĸ�����Ϣ
               book[i].students_number=borrow[key].students_number;
               save();//���Ĺ�����Ϣ�����ļ�
               borrow[key].borrow_number++;
               borrow[key].number[borrow[key].borrow_number-1]=y;
               borrow[key].lend_time[borrow[key].borrow_number-1]=20160527;
            }
           printf("���������룺\n");
           printf("\t\t1.��������\n");
           printf("\t\t2.�鿴������Ϣ\n");
           printf("\t\t3.�������˵�\n");
           scanf("%d",&p);
           switch(p){
                 case 1:ifborrow(key);break;
                 case 2: printf("ѧ��\t  ��ϵ��ʽ   \t ͨѶ��ַ   \t�ѽ�ͼ��  ͼ����  ���ʱ��  Ƿ�ѽ��  \n");
                 printf("%-10ld%-15s%-15s%-10d%-10ld%-10ld%-10d\n",borrow[key].students_number,borrow[key].phonenumber,borrow[key].adress,borrow[key].borrow_number,borrow[key].number[0],borrow[key].lend_time[0],borrow[key].owe_money);
                 if(borrow[key].number[1]!=0)
                     printf("\t\t\t\t\t\t  %-10ld%-10ld\n",borrow[key].number[1],borrow[key].lend_time[1]);
                 if(borrow[key].number[2]!=0)
                     printf("\t\t\t\t\t\t  %-10ld%-10ld\n",borrow[key].number[2],borrow[key].lend_time[2]);
                 printf("\t\t��������������˵�\n");
                 system("pause");//�ȴ��û���һ������Ȼ�󷵻�
                 menu1();break;
                 case 3:menu1();break;
                 defalut:menu1();
           }
          break;
     }
}
int money(long int q ){
    char a[10],b[10],*m,*n;//����ָ��ָ���ַ�����
    m=a;n=b;
    int days,s=0;
    sprintf(a, "%d", 20160527);//��5��27��Ϊ�������Ƿ�ѽ��
    sprintf(b, "%d", q);//�����ڴ����ַ�������
    days=day_of_day(m, n);//��������ʱ�������
    if(days>30&&days<=60)//������
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
//��ָ��aָ��Ľṹ������Ԫ����ͼ����С��ָ��b���򷵻�1����֮����-1
}
void bye_bye(){
  printf("\t\t");
  printf("\n\t\t��л����ʹ�ã��ټ���\n");
}
time_t maketime_t(char* date1)
{
  struct tm tm0;
  char str0[4];
  memset( &tm0, 0, sizeof(tm0));//�ַ������ʼ��
  memset( str0, 0, 4);
  strncpy(str0, date1, 4);//ȡ�����
  tm0.tm_year = atoi(str0) - 1900;  //1900�꿪ʼ
  memset( str0, 0, 4);
  strncpy(str0, &date1[4], 2);//ȡ���·�
  tm0.tm_mon = atoi(str0) - 1;  //0-11�·�
  memset( str0, 0, 4);
  strncpy(str0, &date1[6], 2);//ȡ������
  tm0.tm_mday = atoi(str0);  //1-31��
  return mktime(&tm0);
}

int day_of_day( char *date1, char *date2)
{
  struct tm tm0;
  char str0[4];
  double diff_seconds;//��λΪ��
  time_t time_t1, time_t2;
  time_t1 = maketime_t(date1);
  time_t2 = maketime_t(date2);
  diff_seconds = difftime(time_t1, time_t2);//����
  return diff_seconds>0? (int)(diff_seconds/3600/24):(int)((-1)*diff_seconds/3600/24);//ת��Ϊ����
}
