/*Password ของใครปลอดภัยที่สุดให้หาว่าใครตั้ง Password ที่ยากที่จะถูก hack จากผู้ไม่ประสงค์ดีมากที่สุด ระหว่าง Kob, Romtham และ Jojo ตามลำดับ
โดยมีเกณฑ์ในการตั้ง Password ที่ดีดังนี้(Level 5)
-ตัวอักษร a-z อย่างน้อย 1 ตัว
-ตัวเลข 0-9 อย่างน้อย 1 ตัว
-ตัวอักษร A-Z อย่างน้อย 1 ตัว
-ตัวอักษรพิเศษ $ หรือ # หรือ @ อย่างน้อย 1 ตัว
-ความยาวไม่น้อยกว่า 6 ตัว และ ไม่มากกว่า 12 ตัว
รูปแบบ Input : Password ของทั้งสามคน Kob, Romtham , และ Jojoตามลำดับ(คั่นด้วยลูกน้ำ)
รูปแบบ Output : Password ที่ตรงตามเกณฑ์ และ เจ้าของ Password นั้น
ข้อจำกัด : มีแค่คนเดียวที่ตั้ง Password ตรงตามเกณฑ์ที่กำหนด*/

#include <stdio.h>
#include <string.h>

int main()
{
    char password[60], pass[3][20];
    char pass_attribute[3][6];
    char name[3][10] ={{"Kob"},{"Romtham"},{"Jojo"}} ;
    printf("input : ");
    scanf("%[^\n]s", password);
    int n = 0 ,i = 0;
    while (password[n] != ',')
    {
        pass[0][i] = password[n];
        i ++;
        n++;
    }
    pass[0][i] = '\0';
    n++;
    i = 0;
    while (password[n] != ',')
    {
        pass[1][i] = password[n];
        i ++;
        n++;
    }
    pass[1][i] = '\0';
    n++;
    i = 0;
    while (password[n] != '\0')
    {
        pass[2][i] = password[n];
        i ++;
        n++;
    }
    pass[2][i] = '\0';
    //check pass value
    for(int i = 0 ; i < 3 ; i++){
        int j = 0;
        printf("\npass[%d] : ",i);
        while(pass[i][j] != '\0'){
            printf("%c" ,pass[i][j]);
            j++;
        }
    }
    //check list pass quality
    for(int i = 0 ; i < 3 ; i++){
        int j = 0;
        pass_attribute[i][5] = 'y' ;//use for check space bar >> if don't check it will have 2 answers
        if(strlen(pass[i]) >= 6 && strlen(pass[i]) <= 12){
            pass_attribute[i][4] = 'y' ;
        }

        while(pass[i][j] != '\0'){

            if(pass[i][j] == ' '){
                pass_attribute[i][5] = 'n' ;//if space appear >> make it lack of qualifications
            }
            else if(pass[i][j] >= 'a' && pass[i][j] <= 'z'){
                pass_attribute[i][0] = 'y' ;
            }
            else if(pass[i][j] >= 'A' && pass[i][j] <= 'Z'){
                pass_attribute[i][1] = 'y' ;
            }
            else if(pass[i][j] >= '0' && pass[i][j] <= '9'){
                pass_attribute[i][2] = 'y' ;
            }
            else if(pass[i][j] == '$' || pass[i][j] == '#' || pass[i][j] == '@'){
                pass_attribute[i][3] = 'y' ;
            }
            j++ ;
        }
    }
    for(int i = 0 ; i < 3 ; i++){
        int check = 0 ;
        for(int j = 0 ; j < 6 ; j++){
            if(pass_attribute[i][j] == 'y'){
                check++ ;
            }
            else{
                pass ;
            }
        }
        if(check == 6){
            printf("\n%s " ,pass[i]);
            printf("(%s)" ,name[i]);
        }
    }
    return 0;
}
