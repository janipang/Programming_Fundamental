#include<stdio.h>

//โปรแกรมรับค่าประโยคที่มีแต่ตัวพิมพ์เล็ก แล้วนับจำนวนตัวอักษรแต่ละตัวในประโยค
int main()
{
    char text[100] ;
    int amount[26] ;
    int i = 0 ;
    printf("input your text : ") ;
    scanf("%[^\n]" ,&text) ;
    // ให้จำนวนอักษรทุกตัวเริ่มต้นที่ 0
    for(int j = 0 ; j < 26 ; j++)
    {
        amount[j] = 0 ;
    }
    //นับจำนวนอักษรแล้วค่อยๆเพิ่มค่าเก็บใน amount ทีละตัว
    while(text[i] != '\0')
    {
        if(text[i] >= 'a' || text[i] <= 'z') 
        {
            amount[text[i] - 'a'] += 1 ;
        }
        else if(text[i] == ' ') 
        {
        }
        i++ ;
    }
    // แสดงอักษรที่มีมากกว่า 0 ตัว
    for(int k = 0 ; k < 26 ; k++)
    {
        if(amount[k] != 0)
        {
            printf("%c = %d \t" ,'a' + k ,amount[k]) ;
        }
    }
    return 0;
}