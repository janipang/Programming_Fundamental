// จงเขียนโปรแกรมเพื่อรับข้อมูลความสูงของนักเรียน 10 คน แล้วแสดงผลลัพธ์ความสูงของนักเรียน 10 คน พร้อมหาว่าความสูงเฉลี่ยของนักเรียน 10 คนเป็นเท่าไร (Level 3)
#include <stdio.h>

int main()
{
    float sum = 0;
    for (int i = 0; i < 10; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d " ,a);
        sum += a;
    }
    sum /= 10;
    printf("\naverage = %.2f", sum);
    return 0;
}