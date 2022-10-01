/*เขียนโปรแกรมการเข้ารหัสของKaraca ซึ่งการเข้ารหัสมีวิธีดังนี้ (Level 3)
1. รับค่าเข้ามาเช่น suratan
2. กลับด้านตัวอักษรเป็น natarus
3. แปลงสระเป็นตัวเลขโดยเปลี่ยนดังนี้
	a => 0
	e => 1
	i => 2
	o => 3
	u => 4
	จากข้อความด้านบนจะได้ว่า n0t0r4s
4. เติมคำว่า aca เข้าไปด้านหลัง เป็น n0t0r4saca
	ปล.ตัวอักษรมีแต่พิมพ์เล็ก ไม่มีช่องว่าง ไม่มีเลข*/

#include<stdio.h>
#include<string.h>

int main()
{
	
	char text[100] ,ftext[100] ;
	printf("input : ");
	scanf("%s" ,text);

	for(int i = strlen(text) - 1 ; i >= 0 ;i--){
		ftext[strlen(text) -i -1] = text[i];
	}
	for(int i = 0 ; i < strlen(ftext) ; i++){
		if(ftext[i] == 'a'){ftext[i] ='0' ;}
		if(ftext[i] == 'e'){ftext[i] ='1' ;}
		if(ftext[i] == 'i'){ftext[i] ='2' ;}
		if(ftext[i] == 'o'){ftext[i] ='3' ;}
		if(ftext[i] == 'u'){ftext[i] ='4' ;}
	}

	printf("%saca" ,ftext);

	return 0;
}
