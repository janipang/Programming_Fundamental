// จงเขียนโปรแกรมคำนวณเมตริก โดยโปรแกรมจะรับค่าเมตริก A และ B ซึ่งเป็นเมตริกขนาด 3x3 แล้วโปรแกรมจะแสดงผลลัพธ์ต่อไปนี้
// Det A , Det B , Inverse A , Inverse B , A+B , A-B , A . B , A x B (Level 5)
#include <stdio.h>
#include <stdlib.h>

int **add(int A[3][3], int B[3][3]);
int **subtract(int A[3][3], int B[3][3]);
int det(int A[3][3]);
int **Co(int h, int k, int A[3][3]);
int detCo(int **C);
int sign(int i, int j);
float **inverse(int A[3][3]);
int **cross(int A[3][3], int B[3][3]);
int dot(int A[3][3], int B[3][3]);

int main()
{
    int A[3][3], B[3][3];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < 3)
            {
                scanf("%d", &A[i][j]);
            }
            else
            {
                scanf("%d", &B[i - 3][j]);
            }
        }
    }

    // int A[3][3] = {{1, 7, 3}, {1, 5, 3}, {1, 2, 4}};
    // int B[3][3] = {{1, 1, 4}, {2, 7, 2}, {1, 3, 2}};

    int value_collector; // use for save and use value from the function ,to prevent error from calling function directly
    value_collector = det(A);
    printf("\ndet(A) = %d\n", value_collector);
    value_collector = det(B);
    printf("\ndet(B) = %d\n", value_collector);

    float **S;
    // INVERSE MATRIX
    printf("\n(inverse A)\n");
    S = inverse(A);
    if (det(A) != 0)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%.2f ", S[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < 3; i++)
    {
        free(S[i]);
    }
    free(S);

    printf("\n(inverse B)\n");
    S = inverse(B);
    if (det(B) != 0)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%.2f ", S[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < 3; i++)
    {
        free(S[i]);
    }
    free(S);

    int **R;
    // ADD MATRIX
    R = add(A, B);
    printf("\n(A+B)\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        free(R[i]);
    }
    free(R);

    // SUBTRACT MATRIX
    R = subtract(A, B);
    printf("\n(A-B)\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        free(R[i]);
    }
    free(R);

    // CROSS MATRIX
    R = cross(A, B);
    printf("\n(AxB)\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        free(R[i]);
    }
    free(R);

    // DOT MATRIX
    value_collector = dot(A, B);
    printf("\n(A.B) = ");
    printf("%d\n", value_collector);

    return 0;
}

int **add(int A[3][3], int B[3][3])
{
    int **C;
    C = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++)
    {
        C[i] = malloc(sizeof(int *) * 3);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

int **subtract(int A[3][3], int B[3][3])
{
    int **C;
    C = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++)
    {
        C[i] = malloc(sizeof(int *) * 3);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

int det(int A[3][3])
{
    int i = 0, cof = 0;
    for (int j = 0; j < 3; j++)
    {
        cof += A[i][j] * sign(i, j) * detCo(Co(i, j, A));
    }
    return cof;
}

int **Co(int h, int k, int A[3][3])
{
    int **C;
    C = malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++)
    {
        C[i] = malloc(sizeof(int *) * 2);
    }
    int n = 0, m = 0; // use to specify index of C[2][2]
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != h && j != k)
            {
                C[n][m] = A[i][j];
                m++;
            }
            if (m > 1)
            {
                n += 1;
                m = 0;
            }
        }
    }
    return C;
}

int detCo(int **C)
{
    int det = (C[0][0] * C[1][1]) - (C[0][1] * C[1][0]);
    return det;
}

int sign(int i, int j)
{
    if ((i + j) % 2 == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

float **inverse(int A[3][3])
{
    float **Ainv;
    Ainv = malloc(sizeof(float *) * 3);
    for (int i = 0; i < 3; i++)
    {
        Ainv[i] = malloc(sizeof(float *) * 3);
    }

    if (det(A) != 0)
    {
        // printf("1/det(A) = %.2f \n" , 1.00/det(A)) ;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Ainv[i][j] = (1.00 / det(A)) * sign(i, j) * detCo(Co(i, j, A));
                // printf("detCo = %d  ",detCo(Co(i,j,A))) ;
            }
            // printf("\n") ;
        }
    }
    else
    {
        printf("cannot get inverse because of det = 0\n");
    }
    return Ainv;
}

int **cross(int A[3][3], int B[3][3])
{
    int **C;
    int add_digit = 0;
    C = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++)
    {
        C[i] = malloc(sizeof(int *) * 3);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                add_digit += A[i][k] * B[k][j];
            }
            C[i][j] = add_digit;
            add_digit = 0;
        }
    }
    return C;
    // ยังไม่ได้เทส
}

int dot(int A[3][3], int B[3][3])
{
    int **C;
    C = cross(A, B);
    int D[3][3];
    // convert pointer to another matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            D[i][j] = C[i][j];
        }
    }
    return det(D);
}