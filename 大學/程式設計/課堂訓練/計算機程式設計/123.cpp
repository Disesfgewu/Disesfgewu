#include <stdio.h>
#include <string.h>

void down1(int begin)
{
    int i , a=0;
    for ( i=1 ; i<begin ; )
    {
            i=i*10; 
    }
    i=i/10; 
   
    while (begin%10>=1)
    {
        printf("%d\n" , begin);
        begin = begin%i ; 
        i=i/10;
    }

}

void left3(int begin , int n , int i){ 

    while (i<=begin){
        printf("%d" , i);
        i++;
    }
    i=1;
    while (begin>1){
        printf("%d" , begin-1);
        begin--;
    }
    printf ("\n");
}

void baseline2(char a , int n ,int quantity ){

   /* int p=0;
    while (p<=quantity){
        if (a[p]=='0'){
            a[p]='_';
        } 
        p++;
    }*/
}

void down2 (char a , int quantity){


}

void f1(int n)
{
    int begin=1 , s=0 ,answer=0 , beginpron=0;
    printf ("1\n");
    while (begin%10<n)
    {
        begin = begin*10+(begin%10)+1;
        printf("%d\n" , begin);
    }
    while (begin!=0){ 

        beginpron = beginpron*10 +begin%10;
        begin =begin/10;
    }
    begin =beginpron;
    down1(begin);

} 
void f2(int n) 
{
    int quantity;
    quantity =(n-1)*2-1;
    char a[quantity];
    int m=0;
	while(m<quantity)
	{
        a[m] = '_';
        m++;
    }
    int middle=((n-1)*2-2)/2; 
    int i=0;
    int x=n-1;
    while (i<x){
        
        a[middle+i]= (char)(i+49);
        a[middle-i]=(char)(i+49);
        i++;
        printf("%s\n" , a );
    }
    i-- ;
    while ( i >= 0 )
    {
    	printf( "%s\n" , a ) ;
    	a[middle+i]= '_' ;
        a[middle-i]= '_';
        i--;
	}
    /*down2( a[quantity] ,quantity);*/
}

void f3(int n)
{

    int begin=1 , a,i=1 ;
    while (begin<=n){ 
        left3(begin , n ,i);
        begin ++;
    }

}

/*void up1(int *begin,int *n, int *answer)
{

    while (*begin%10<=*n)
    {

        begin = *begin*10+begin+1;
        printf("%d\n" , *begin);
    }
    //?’å…¥down1?½æ•¸
   
}*/

int main()
{
    int i ;
    int n;
    scanf ("%d" , &i);
    scanf("%d" , &n);
    if (i==1){
        f1(n);
    }else if (i==2){
        f2(n);
    }else if (i==3){
        f3(n);
    }else {
        printf("ERROR");
    }

    return 0;
}
