#include <iostream>  // cout - cin
#include <conio.h>   // getch()
#include <windows.h> // Sleep()
#include <thread>    // class thread

#include "random.h"  //rendom()
#include "gotoxy.h"  // gotoxy()

using namespace std;

#define up_key 72
#define down_key 80
#define right_key 77
#define left_key 75
#define Esc_key 27

int score = 0,
    x = 10,
    y = 11;

char face = 2,
    input = 0;

int randx = random(2, 77);
int randy = random(1, 23);

void move_up();
void move_down();
void move_right();
void move_left();
void intro();
void key_press();

int main()
{
    intro();
    thread myThread(key_press);

    while (true)
    {
        switch (input)
        {
            case up_key:
                if(y>1)
                    move_up();
                break;
            case down_key:
                if(y<23)
                    move_down();
                break;
            case right_key:
                if(x<77)
                    move_right();
                break;
            case left_key:
                if(x>2)
                    move_left();
                break;
            case Esc_key:
                goto exit;
                break;
        }
        switch (input)
        {
            case up_key:
            case down_key:
                Sleep(100);
                break;
            case left_key:
            case right_key:
                Sleep(50);
                break;
        }
    }

    exit:
    myThread.detach();
    system("cls");
    return 0;
}
void intro()
{
    system("cls");
    system("title snake");
    system("mode con cols=80 lines=26");
    
    for (int i=0,j=25; i<26 && j>-1 ; i++,j--)
        {gotoxy(0, j);cout << "||";gotoxy(78, i);cout << "||";Sleep(10);}

    for (int i=2,j=77; i<78 && j>1 ;i++,j--)
        {gotoxy(i, 0);cout << "="; gotoxy(j, 24);cout << "=";Sleep(10);}

    gotoxy(2, 0);   cout << " score:" << score << "  ";
    gotoxy(3, 25);  cout << "by:Amir Hamzeh";
    gotoxy(32, 25); cout << "use keys" <<'['<< (char) 24 <<','<<(char) 25 << ',' << (char) 26 << ',' << '<' <<']';
    gotoxy(65, 25); cout << "EXIT = [Esc]";
    gotoxy(randx, randy);cout.put(face);
    gotoxy(x, y); cout.put(26); gotoxy(x, y);

}
void check_place()
{
    if (x == randx && y == randy)
    {
        gotoxy(2, 0); cout << " "<< "score:" << ++score << "  ";

        randx = random(2, 77);
        randy = random(1, 23);

        gotoxy(randx, randy); cout.put(face);
        gotoxy(x, y); cout.put(' ');
        x = 10;
        y = 11;
        gotoxy(x, y); cout.put(26); gotoxy(x, y);
    }
}
void move_up()
{
    cout.put(' ');
    gotoxy(x, --y);
    cout.put(24);//???
    gotoxy(x, y);
    check_place();
}
void move_down()
{
    cout.put(' ');
    gotoxy(x, ++y);
    cout.put(25);//???
    gotoxy(x, y);
    check_place();
}
void move_right()
{
    cout.put(' ');
    gotoxy(++x, y);
    cout.put(26);//???
    gotoxy(x, y);
    check_place();
}
void move_left()
{
    cout.put(' ');
    gotoxy(--x, y);
    cout<<'<';//???
    gotoxy(x, y);
    check_place();
}
void key_press()
{
    while (input = getch());
}