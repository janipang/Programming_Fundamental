// จงเขียนโปรแกรมเพื่อรับข้อมูลความสูงของนักเรียน 10 คน แล้วแสดงผลลัพธ์ความสูงของนักเรียน 10 คน พร้อมหาว่าความสูงเฉลี่ยของนักเรียน 10 คนเป็นเท่าไร (Level 3)
#include <stdio.h>

int main()
{
    int high[10];
    float sum = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &high[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        sum += high[i];
        printf("%d ", high[i]);
        if (i == 9)
        {
            sum /= 10;
            printf("\naverage = %.2f", sum);
        }
    }
    return 0;
}