// Sine function

#include <iostream>
#include <cmath>
using namespace std;

#define CLS         (cout << "\033[2J")
#define LOCATE(z,s) (cout << "\033[" << (z) << ';' << (s) << 'H')
#define PI      3.1415926536
#define START   0.0                     // limite inferior
#define END     (2.0 * PI)              // limite superior
#define PNT         64                  //numero de puntos en la curva
#define STEP        ((END-START/PNT))
#define xA      14                      // fila de eje x
#define yA      10                      // columna de eje y

int main() 
{
    int row, column;

    CLS;
    LOCATE(2,25);
    cout << "------- The Sine Function -------";

    // dibuja sistema de coordenadas:

    LOCATE(xA,1);                               //eje x
    for (column = 1 ; column < 78 ; ++column)
    {
        cout << ((column - yA) % 8 ? '\304' : '\305');
    }
    cout << '\020';                             // top
    LOCATE(xA-1, yA+64); cout << "2PI   x";

    for ( row = 5 ; row < 24 ; ++row)           // eje y
    {
        LOCATE(row, yA);    cout << '\305';
    }
    LOCATE( 4, yA); cout << "\036 sin(x)";     // top

    LOCATE( xA-8, yA+1);    cout << "  1";
    LOCATE (xA+8, yA+1);    cout << "  -1";

    //      Muestra la funcion seno

    int begpt = yA,
        endpt = begpt + PNT;

    for (column = begpt ; column <= endpt ; ++column)
    {
        double x = (column-yA) * STEP;
        row = (int) (xA - 8 * sin(x) + 0.5);
        LOCATE (row, column);   cout << '*';
    }

    LOCATE(25,1);            // Cursor a la ultima fila
    
    return 0;
}