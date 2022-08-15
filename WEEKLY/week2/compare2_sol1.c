// เปรียบเทียบตัวเลข 2
#include<stdio.h>
int main()
{
    int a , b ;
    scanf("%d\n%d" ,&a ,&b) ;
    if(a > b){
        printf("%d" ,a - b) ;
    }
    else if(b > a){
        printf("%d" ,b - a) ;
    }
    else{
        printf("=") ;
    }
    return 0;
}
