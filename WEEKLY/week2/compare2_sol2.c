// เปรียบเทียบตัวเลข 2
#include<stdio.h>
#include<math.h>
int main()
{
    int a , b , ans ;
    scanf("%d\n%d" ,&a ,&b) ;
    ans = fabs(a - b) ;
    if(ans == 0){
        printf("=") ;
    }
    else{
        printf("%d" ,ans) ;
    }
    return 0;
}