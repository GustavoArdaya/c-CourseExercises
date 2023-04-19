#include <iostream>
#include <string>
using namespace std;

#define DELAY   10000000L
#define CLS     (cout << "\033[2J")
#define LOCATE(z, s) (cout << "\033[" << z << ';' << s << 'H') //posiciona el cursor en la fila z y columna s

int main() { // un main void!!!

    int x = 2, y = 3, dx = 1, speed = 0;
    string floor(79, '-'),
        header = "****  Jumping Ball  ****";

    CLS;
    LOCATE(1,25); cout << header;
    LOCATE(15,1); cout << floor;

    while(true)     // let the ball "always" bounce
    {                // terminate by interrupt key (^C)
        LOCATE(y, x);   cout << 'o' << endl; // Show the ball
        for( long wait = 0; wait < DELAY; ++wait) 
            ;
        if (x == 1 || x == 79) dx = -dx;        // bounce off
                                                // a wall?
        if ( y == 24 )                          // on the floor
        {
            speed = - speed;
            if (speed == 0) {
                speed = -7;
                }         // restart
        }
        speed += 1;                             // acceleration = 1
        LOCATE(y,x);    cout << ' ';            // clear output
        y += speed;     x += dx;                // New Position
    }
}