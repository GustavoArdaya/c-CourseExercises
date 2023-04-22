#ifndef _MYMACROS_ 
#define _MYMACROS_

#include <iostream>
using namespace std;

#define ABS(a)  (  (a) >= 0 ? (a) : - (a)) //returns absolute value of val

#define MIN(a,b)  (  (a) <= (b) ? (a) : b ) //return min val between two vals

#define MAX(a,b)  (  (a) >= (b) ? (a) : b ) //return max val between two vals

// MACROS FOR SCREEN:

#define CLS (cout << "\033[2J") // clears screen

#define LOCATE(r, c) (cout << "\033[" << (r)  << ';' << (c) << 'H') // positions the cursor to (row, column). (1,1) is upper left corner.

#define COLOR( f, b) (cout << "\033[1;3" << (f) \ 
                           << ";4" << (b)  << 'm' << flush) //sets foreground and background color

//color values for the macro COLOR to call: ex. COLOR(WHITE,BLUE)

#define BLACK   0
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define WHITE   7

#define INVERS (cout << "\033[7m")// inverts the following output

#define NORMAL (cout << "\033[0m]") //set screen atributes to default values

#endif      // _MYMACROS_