#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a,b,c,delta,R1,R2;
    cin>> a>>b>>c;
    delta = (b*b)-(4*a*c);
    if (delta<0)
        cout<<"Impossivel calcular" << endl;
    R1=((-b) + sqrt(delta))/(2*a);
    R2=((-b) - sqrt(delta))/(2*a);
        cout<< setprecision(5) << R1 << endl << setprecision(6) << R2; // 5 dígitos depois do ponto ====== (10.0/20.1/5.1)=== (10.3/203.0/5.0)
    return 0;
}
