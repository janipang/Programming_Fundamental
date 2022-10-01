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

	int i = 0 ;
	for(int j = strlen(text) - 1 ; j >= 0 ;j--){
		ftext[i] = text[j];
		i++;
	}
	ftext[i]='\0';
	i = 0 ;
	while(ftext[i] != '\0'){
		if(ftext[i] == 'a'){
			printf("0");
		}
		else if(ftext[i] == 'e'){
			printf("1");
		}
		else if(ftext[i] == 'i'){
			printf("2");
		}
		else if(ftext[i] == 'o'){
			printf("3");
		}
		else if(ftext[i] == 'u'){
			printf("4");
		}
		else{
			printf("%c" ,ftext[i]);
		}
		i++;
	}
	printf("aca");
	
	return 0;
}
