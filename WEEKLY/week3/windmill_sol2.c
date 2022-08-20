#include<stdio.h>

int main()
{
    int n ;
    printf("input n :");
    scanf("%d",&n);
    char act=65 ;
    for( int i = 1 ; i <= (n*2) -1 ; i++)
    {
        for(int j = 1 ; j <= (n*2) -1 ; j++)
        {
            if(i > n)
            {
                if(j==n-(n-i) || j==n+(n-i))
                printf("%c ",act+(i-n));
                else
                {
                printf("  ");
                }
            }
            else if(j==n-(n-i) || j==n+(n-i))
            {
                printf("%c ",act+(n-i));
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}