//bouncing ball

#include <iostream>
#include <string>
using namespace std;
#include <conio.h>
#include "myMacros.h"

#define ESC 27 // esc termina el programa
unsigned long delay = 5000000;

int main () 
{
    int x = 2, y = 2, dx = 1, speed = 0;
    bool end = false;
    string floor(80, '-'),
            header = "****  Bouncing Ball ****",
            commands = "[Esc] = Terminate      [+] = Speed up      [-] = Slow down";

    COLOR(WHITE, BLUE);     CLS;
    LOCATE(1,25);       cout << header;
    LOCATE(24,1);       cout << floor;
    LOCATE(25,10);      cout << commands;

    while (!end)
    {
        LOCATE(y,x);    cout << 'o';        //bola
        for (long wait = 0; wait < delay; ++wait)   //Esto espera el delay antes de renderizar nuevamente.
            ;
        if (x == 1 || x == 79) dx = -dx; //Cambio de direccion, rebote
        if (y == 23)
        {
            speed = - speed;
            if (speed == 0) speed = -7; //"patada"
        }
        speed += 1;

        LOCATE(y,x);    cout << ' ';    //"borra" bola
        y += speed; x += dx;            //cambio de posicion

        if (kbhit() != 0)               // Presion de tecla
        {
            switch(getch())             // si hay presion
            {
                case '+':   delay -= delay/5;   //aumenta vel (disminuye latencia!)
                            break;
                case '-':   delay += delay/5;   //reduce vel (aumenta latencia!)
                            break;
                case ESC:   end = true;         //termina
            }                
        }   
    }
    NORMAL; CLS;
    return 0;  
}

