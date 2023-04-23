#include <iostream>
#include <cmath>
using namespace std;

#define CLS         (cout << "\033[2J")
#define LOCATE(z,s) (cout << "\033[" << (z) << ';' << (s) << 'H')
#define DOT(x,y)    (LOCATE(y,x) << '*')

#define PI  3.1416
#define Mx  40          //Punto (Mx, My) es el centro de la elipse
#define My  12
#define A   25          // Largo de eje principal
#define B   10          // Largo de eje secundario

int main() 
{
    int x, y;           //coordenadas

    CLS;

    for ( double t = 0.0; t <= PI/2 ; t += 0.03)
    {
        x = (int)   (A * cos(t) + 0.5);             // 0.5 redondea int casteado hacia arriba
        y = (int)   (B * sin(t) + 0.5);
        DOT( x+Mx, y+My);
        DOT( x+Mx, -y+My);
        DOT( -x+Mx, y+My);
        DOT( -x+Mx, -y+My);
    }
    LOCATE(24,0);
    return 0;
}