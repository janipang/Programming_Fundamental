// จงเขียนโปรแกรมคำนวณเมตริก โดยโปรแกรมจะรับค่าเมตริก A และ B ซึ่งเป็นเมตริกขนาด 3x3 แล้วโปรแกรมจะแสดงผลลัพธ์ต่อไปนี้
// Det A , Det B , Inverse A , Inverse B , A+B , A-B , A . B , A x B (Level 5)
#include <stdio.h>
#include <stdlib.h>
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

    // testing array
    //  int A[3][3] = {{1, 7, 3}, {1, 5, 3}, {1, 2, 4}};
    //  int B[3][3] = {{1, 1, 4}, {2, 7, 2}, {1, 3, 2}};

    int Cross[3][3];
    int add_digit;
    int detA, detB;

    printf("\ndet(A) = ");
    add_digit = 0;
    for (int i = 0; i < 3; i++)
    {
        add_digit += A[0][(i) % 3] * A[1][(i + 1) % 3] * A[2][(i + 2) % 3];
    }
    for (int i = 0; i < 3; i++)
    {
        add_digit -= A[0][(i) % 3] * A[1][(i + 2) % 3] * A[2][(i + 1) % 3];
    }
    printf("%d\n", add_digit);
    detA = add_digit;

    printf("\ndet(B) = ");
    add_digit = 0;
    for (int i = 0; i < 3; i++)
    {
        add_digit += B[0][(i) % 3] * B[1][(i + 1) % 3] * B[2][(i + 2) % 3];
    }
    for (int i = 0; i < 3; i++)
    {
        add_digit -= B[0][(i) % 3] * B[1][(i + 2) % 3] * B[2][(i + 1) % 3];
    }
    printf("%d\n", add_digit);
    detB = add_digit;

    printf("\n(inverse A)\n");
    float Ainv[3][3];
    if (detA == 0)
    {
        printf("cannot get inverse because det = 0\n");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // each number in inverse matrix
                int p = 0, q = 0;
                int Co[2][2];
                for (int n = 0; n < 3; n++) // this is Co matrix[2][2]
                {
                    for (int m = 0; m < 3; m++)
                    {
                        if (n != i && m != j)
                        {
                            Co[p][q] = A[n][m];
                            q++;
                        }
                        if (q > 1)
                        {
                            p = 1;
                            q = 0;
                        }
                    }
                }
                int detCo = (Co[0][0] * Co[1][1] - (Co[0][1] * Co[1][0]));
                Ainv[i][j] = (1.00 / detA) * ((-2 * ((i + j) % 2)) + 1) * detCo;
                printf("%.2f ", Ainv[i][j]);
            }
            printf("\n");
        }
    }

    printf("\n(inverse B)\n");
    float Binv[3][3];
    if (detA == 0)
    {
        printf("cannot get inverse because det = 0\n");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // each number in inverse matrix
                int p = 0, q = 0;
                int Co[2][2];
                for (int n = 0; n < 3; n++) // this is Co matrix[2][2]
                {
                    for (int m = 0; m < 3; m++)
                    {
                        if (n != i && m != j)
                        {
                            Co[p][q] = B[n][m];
                            q++;
                        }
                        if (q > 1)
                        {
                            p = 1;
                            q = 0;
                        }
                    }
                }
                int detCo = (Co[0][0] * Co[1][1] - (Co[0][1] * Co[1][0]));
                Binv[i][j] = (1.00 / detB) * ((-2 * ((i + j) % 2)) + 1) * detCo;
                printf("%.2f ", Binv[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n(A+B)\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }

    printf("\n(A-B)\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j] - B[i][j]);
        }
        printf("\n");
    }

    printf("\n(AxB)\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            add_digit = 0;
            for (int k = 0; k < 3; k++)
            {
                add_digit += A[i][k] * B[k][j];
            }
            printf("%d ", add_digit);
            Cross[i][j] = add_digit;
        }
        printf("\n");
    }

    printf("\n(A.B) = ");
    add_digit = 0;
    for (int i = 0; i < 3; i++)
    {
        add_digit += Cross[0][(i) % 3] * Cross[1][(i + 1) % 3] * Cross[2][(i + 2) % 3];
    }
    for (int i = 0; i < 3; i++)
    {
        add_digit -= Cross[0][(i) % 3] * Cross[1][(i + 2) % 3] * Cross[2][(i + 1) % 3];
    }
    printf("%d\n", add_digit);

    return 0;
}