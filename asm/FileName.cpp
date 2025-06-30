#include <iostream>
#include <cmath>
//Y=(5-x^3/b+7*a+10/x^3 )/(13x^2–b/7a )
using namespace std;
extern "C" __int64 _cdecl _SumInt(__int64 num1, __int64 num2);
extern "C" __int64 _cdecl _SubInt(__int64 num1, __int64 num2);


int main() {
   __int64 A, B, X;
    __int64  result = 0, r = 0;
    
    cout << "Enter a, b, x: ";
    cin >> A >> B >> X;
    if ((13 * X * X - B / (7 * A)) == 0) {
        cout << "Erorr!" << endl;
        return 0;
    }

    __int64 n = _SumInt(_SumInt(_SubInt(5, (pow(X, 3) / B)), 7 * A), (int)(10 / pow(X, 3)));
    cout << "result by c++ n = " << n << endl;

    __int64 d = (13 * pow(X, 2) - B / (7 * A));
    cout << "result by c++ d = " << d << endl;


    __int64 Y = n / d;


    cout << "result by c++ Y = " << Y << endl;

    return 0;
}