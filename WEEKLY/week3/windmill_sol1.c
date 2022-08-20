#include<stdio.h>
#include<math.h>

int main()
{
    int n ;
    char letter ;
    printf("input n :");
    scanf("%d" ,&n);
    for(int i = -(n - 1) ; i <= n - 1 ; i++)
    {
        letter = 65 + fabs(i) ;
        for(int j = -(n - 1) ; j <= n - 1 ; j++)
        {
            if(fabs(j) == fabs(i))
            {
                printf("%c " ,letter) ;
            }
            else
            {
                printf("  ") ;
            }
        }
        printf("\n") ;
    }
    return 0;
}