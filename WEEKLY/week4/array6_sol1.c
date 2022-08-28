#include<stdio.h>
#include<string.h>

//โปรแกรมรับค่าประโยคที่มีแต่ตัวพิมพ์เล็ก แล้วนับจำนวนตัวอักษรแต่ละตัวในประโยค
int main()
{
    char text[100] ;
    int amount[27] ;
    printf("input text :");
    scanf("%[^\n]",&text);
    //ไล่ a b c d 
    //พิจารณาว่า มีอักษรไหรตรงกับ a ไหม ถ้ามีก็ + ค่าเพิ่มใส่ amount
    for(int i = 0 ; i < 26 ; i++)
    {
        amount[i] = 0 ;
        for(int j = 0 ; j < strlen(text) ; j++)
        {
            if(text[j] == 'a' + i)
            {
                amount[i]++ ;
            }
        }
        if(amount[i] != 0)
        {
            printf("%c = %d \t" ,'a' + i ,amount[i]) ;
        }
    }
    return 0 ;
}