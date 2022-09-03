#include<stdio.h>

int main()
{
    int m , n ;
    scanf("%d %d" ,&m ,&n) ;
    int matrix1[m][n] , matrix2[m][n];
    for(int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            scanf("%d" ,&matrix1[i][j]) ;
        }
    }
    for(int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            scanf("%d" ,&matrix2[i][j]) ;
            matrix2[i][j] = matrix1[i][j] + matrix2[i][j] ;
            printf("%d " ,matrix2[i][j]) ;
        }
        printf("\n") ;
    }

    return 0;
}
//matrix1[][3]={{1,2,3},{1,2,3}} 2D array sometimes doesn't need to define row but it always need to define column.