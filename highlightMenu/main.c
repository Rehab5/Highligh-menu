#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define null -32

void gotoxy(int x, int y){
    COORD coord = {0,0};
    coord.X= x;
    coord.Y= y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}
int main()
{
    char menu[3][10] ={"New","Display","Exit"};
    char ch;
    int flag = 0;
    int cursor = 0;

    do{
        system("cls");
        for(int i=0; i<3;i++){
            gotoxy(20,3+i);
            if(i == cursor)
                textattr(0x57);
            printf("%s ",menu[i]);
            textattr(0x07);
        }

        ch= getch();
        switch(ch){
        case -32:
            ch = getch();
            switch(ch){
            case 72:
                cursor--;
                if(cursor <0)
                    cursor = 2;
                break;
            case 71:
                cursor=0;
                break;
            case 79:
                cursor = 2;
                break;
            case 80:
                cursor++;
                if(cursor >2)
                    cursor = 0;
                break;
            }
            break;
        case 27:
            flag = 1;
            break;
        case 13:
            system("cls");
            printf("%s is selected",menu[cursor]);
            getch();
            if(cursor == 2)
                flag = 1;
            break;

        }
    }while(flag ==0);



    printf("\n");
    return 0;
}
