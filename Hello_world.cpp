#include <iostream>
#include <time.h>
#include <math.h>
const int Max_zn=30;
void nom(int* i, int* j){
    do{
        printf("Enter strk, col: ");
        scanf("%d%d",i,j);
       }while(*i<1||*i>Max_zn||*j<0||*j>Max_zn);
}

void ruch(int arr[][Max_zn],int col, int strk){
    for(int i=0;i<strk;i++)
        for(int j=0;j<col;j++)
        {
            printf("enter matr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
}
void autom(int arr[][Max_zn],int col, int strk){
    srand(time(0));
    for(int i=0;i<strk;i++)
        for(int j=0;j<col;j++)
        {
            arr[i][j]=rand()%201-100;
        }
}
void vvod(int arr[][Max_zn],int col, int strk){
    int a;
    printf("enter 0 if ruchn: ");
    scanf("%d",&a);
    if(a==0)
        ruch(arr,col,strk);
    else
        autom(arr,col,strk);
}
void prin_mt(int arr[][Max_zn],int col, int strk){
    printf("Matrix: \n");
    for(int i=0;i<strk;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%4d",arr[i][j]);
        }
        printf("\n");
    }
}
void prin_mt_k(int arr[][Max_zn],int col){
    printf("Matrix: \n");
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%4d",arr[i][j]);
        }
        printf("\n");
    }
}
void summ(int arr[][Max_zn],int mas[], int col, int strk){
    int n=0;
    for(int j=0;j<col;j++)
    {
        mas[n]=0;
        for(int i=0;i<strk;i++)
        {
          mas[n]+=arr[i][j] ;
        }
        n++;
    }
}
void prin_mas(int mas[], int col){
    printf("massive: \n");
    for(int i=0;i<col;i++)
        printf("%d ", mas[i]);
    printf("\n");
}
void zam(int* a, int* b){
    int bn = *a;
    *a=*b;
    *b=bn;
}

void sor_ub(int a[], int k){
    bool f = false;
        do
        {
            f=false;
            for (int i = 0; i<k-1; i++)
            {
                if (a[i]<a[i+1])
                {
                 zam(&a[i],&a[i+1]);
                 f=true;
                }
            }
        }while(f);
}
void nom_k(int* i){
    do{
        printf("Enter nom: ");
        scanf("%d",i);
       }while(*i<1||*i>Max_zn);
}
void ruch_k(int arr[][Max_zn],int col){
    for(int i=0;i<col;i++)
        for(int j=0;j<col;j++)
        {
            printf("enter matr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
}
void autom_k(int arr[][Max_zn],int col){
    srand(time(0));
    for(int i=0;i<col;i++)
        for(int j=0;j<col;j++)
        {
            arr[i][j]=rand()%201-100;
        }
}
void vvod_k(int arr[][Max_zn],int col){
    int a;
    printf("enter 0 if ruchn: ");
    scanf("%d",&a);
    if(a==0)
        ruch_k(arr,col);
    else
        autom_k(arr,col);
}
void zam_k(int arr[][Max_zn],int col){
    int jmin=0;
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<col;j++)
        {
           if(arr[i][jmin]>arr[i][j])
               jmin=j;
        }
        zam(&arr[i][jmin],&arr[i][col-1-i]);
    }
}
void nom1(int* i, int* j,int* n){
    do{
        printf("Enter strk, col, nach: ");
        scanf("%d%d%d",i,j,n);
       }while(*i<1||*i>Max_zn||*j<0||*j>Max_zn);
}
void zapoln(int arr[][Max_zn],int col, int strk,int nach){
    int i=0,j=0,n=0;
    int k=1;
    bool f =true;
    while (f)
    {
        f=false;
        for(int a=0 ;a<col;a+=1){
            arr[i][j]=nach+n;
            j+=k;
            n++;
            f =true;
        }
        j-=k;
        i+=k;
        for(int b = 0; b < strk-1;b+=1){
            arr[i][j]=nach+n;
            i+=k;
            n++;
            f =true;
        }
        i-=k;
        k*=(-1);
        col-=1;
        strk-=1;
        j+=k;
    }
}

int main()
{
    int col,strk,n,col1,strk1,nach;
    int matr[Max_zn][Max_zn];
    int matr_k[Max_zn][Max_zn];
    int matr_1[Max_zn][Max_zn];
    int mas[Max_zn];
    nom(&strk,&col);
    vvod(matr,col,strk);
    prin_mt(matr,col,strk);
    summ(matr,mas,col,strk);
    prin_mas(mas,col);
    sor_ub(mas,col);
    prin_mas(mas,col);
    nom_k(&n);
    vvod_k(matr_k,n);
    prin_mt_k(matr_k,n);
    zam_k(matr_k,n);
    prin_mt_k(matr_k,n);
    nom1(&strk1,&col1,&nach);
    zapoln(matr_1,col1,strk1,nach);
    prin_mt(matr_1,col1,strk1);
    return 0;
}

