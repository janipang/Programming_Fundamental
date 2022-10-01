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
//ABd1234@1,a F1#2w3E*,2We3345
#include <stdio.h>
#include <string.h>

int main()
{
    char password[60], pass[3][20];
    char pass_attribute[3][6];
    char name[3][10] ={{"Kob"},{"Romtham"},{"Jojo"}} ;
    printf("input : ");
    scanf("%[^\n]s", password);
    int n = 0 ;
    for(int i = 0 ; i < 3 ; i++){
        int j = 0 ;
        while (password[n] != ',' && password[n] != '\0')
        {
            pass[i][j] = password[n];
            j ++;
            n++;
        }
        pass[i][j] = '\0';
        n++;
    }
    //check pass value
    for(int i = 0 ; i < 3 ; i++){
        int j = 0;
        printf("\npass[%d] : ",i);
        while(pass[i][j] != '\0'){
            printf("%c" ,pass[i][j]);
            j++;
        }
    }

    // check list pass quality
    for(int i = 0 ; i < 3 ; i++){
        // check a-z
        int j = 0;
        char status = 'n' ;
        while(pass[i][j] != '\0'){
            if(pass[i][j] >= 'a' && pass[i][j] <= 'z'){
                status = 'y' ;
            }
            j++;
        }
        if(status == 'n'){
            continue;
        }
        // check A-Z
        j = 0;
        status = 'n' ;
        while(pass[i][j] != '\0'){
            if(pass[i][j] >= 'A' && pass[i][j] <= 'Z'){
                status = 'y' ;
            }
            j++;
        }
        if(status == 'n'){
            continue;
        }
        // check 0-9
        j = 0;
        status = 'n' ;
        while(pass[i][j] != '\0'){
            if(pass[i][j] >= '0' && pass[i][j] <= '9'){
                status = 'y' ;
            }
            j++;
        }
        if(status == 'n'){
            continue;
        }
        // check $ # @
        j = 0;
        status = 'n' ;
        while(pass[i][j] != '\0'){
            if(pass[i][j] == '$' || pass[i][j] == '#' || pass[i][j] == '@'){
                status = 'y' ;
            }
            j++;
        }
        if(status == 'n'){
            continue;
        }
        // check ' '
        j = 0;
        status = 'y' ;
        while(pass[i][j] != '\0'){
            if(pass[i][j] == ' '){
                status = 'n' ;
            }
            j++;
        }
        if(status == 'n'){
            continue;
        }
        // check lenght
        status = 'n' ;
        if(strlen(pass[i]) >= 6 && strlen(pass[i]) <= 12){
            status = 'y' ;
        }
        if(status == 'n'){
            continue;
        }
        
        // finally if it have all requirements >> print 
        printf("\n%s " ,pass[i]);
        printf("(%s)" ,name[i]);
    }
    return 0;
}
