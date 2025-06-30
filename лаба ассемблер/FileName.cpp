#include <iostream>
#include <cmath>
//Y=(5-x^3/b+7*a+10/x^3 )/(13x^2�b/7a )
using namespace std;
extern "C" int _cdecl _SumInt(int num1, int num2, int num3);
extern "C" int _cdecl _SubInt(int num1, int num2);


int main() {
    int a, b, x, result = 0, r = 0;
    int p0, p1, p2, p3, p4, p5, p6;
    cout << "Enter a, b, x: ";
	cin >> a >> b >> x;
    __asm {
        mov eax, x; ��������� x � EAX
        imul x; ��������� x ^ 2
		imul x; ��������� x ^ 3
        mov p0, eax; ��������� ���������

       /* cdq; ����������� EAX � EDX : EAX*/
        cmp b, 0
          je metka
        idiv b; ��������� x ^ 3 / b
        mov p1, eax; ��������� ���������

        mov eax, 10; ��������� 10 � EBX

        cdq;
        cmp p0, 0
            je metka
        idiv p0; 
        
        mov p2, eax; ��������� ���������
            mov eax, a;
		imul eax, 7;
        cmp eax, 0
            je metka
        mov p3, eax; ��������� ���������
			mov eax, p1;
        mov ebx, 5;
        sub ebx, eax;
		add ebx, p2;
        add ebx, p3;
       
        mov p4, ebx; ��������� ���������
            mov eax, x; ��������� a � EAX
        imul  eax, 13;
         imul x; ��������� x ^ 2
        mov p5, eax; ��������� ���������
       mov eax, b; ��������� b � EAX
            cdq;
        idiv p3;
        mov ebx, p5;
        sub ebx, eax;
        mov p6, ebx; ��������� ���������
            cmp ebx, 0
             je metka
       
            
            
            mov eax, p4; ��������� p4 � EAX
			cdq;
		idiv p6;
        mov result, eax;
        jmp end_asm    
            metka:
        mov eax, 666666; ��������� p4 � EAX
        mov r, eax; ��������� ���������
            
end_asm:
    }
    cout << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " "  << p5 << " " << p6 << endl;
    if (r == 666666){
        cout << "Dividing by 0!";
        return 0;
    }
   cout << "Result by assembler: " << result << endl;
       int A, B, X;

      
       A = a; B = b; X=x;

      
       if ((13 * X * X - B / (7 * A)) == 0) {
           cout << "Erorr!" << endl;
           return 0;
       }

       int n = _SumInt(_SubInt(5, (pow(X, 3)/B)), 7*A, (int)(10/pow(X, 3)));
       cout << "result by c++ n = " << n << endl;

       int d = (13 * pow(X, 2) - B / (7 * A));
       cout << "result by c++ d = " << d << endl;

     
       int Y = n / d;

   
       cout << "result by c++ Y = " << Y << endl;

       return 0;
   }
//#include <iostream>
//#include <cmath>
////Y=(5-x^3/b+7*a+10/x^3 )/(13x^2�b/7a )
//using namespace std;
//
//int main() {
//    short a, b, x, result = 0, r = 0;
//    short p0, p1, p2, p3, p4, p5, p6;
//    cout << "Enter a, b, x: ";
//    cin >> a >> b >> x;
//    __asm {
//        mov ax, x; ��������� x � EAX
//        imul x; ��������� x ^ 2
//        jo perepolnenie
//        imul x; ��������� x ^ 3
//        jo perepolnenie
//        mov p0, ax; ��������� ���������
//
//         
//        cmp b,0
//        je metka
//        idiv b; ��������� x ^ 3 / b
//        mov p1, ax; ��������� ���������
//
//        mov ax, 10; ��������� 10 � EBX
//
//        cwd;
//        cmp p0, 0
//            je metka
//        idiv p0;
//
//        mov p2, ax; ��������� ���������
//            mov ax, a;
//        imul ax, 7;
//        jo perepolnenie
//        mov p3, ax; ��������� ���������
//            mov ax, p1;
//        mov bx, 5;
//        sub bx, ax;
//        jo perepolnenie
//        add bx, p2;
//        jo perepolnenie
//        add bx, p3;
//        jo perepolnenie
//
//        mov p4, bx; ��������� ���������
//            mov ax, x; ��������� a � EAX
//            imul  ax, 13;
//        jo perepolnenie
//        imul x; ��������� x ^ 2
//            jo perepolnenie
//            mov p5, ax; ��������� ���������
//            mov ax, b; ��������� b � EAX
//            cwd;
//        cmp p3, 0
//            je metka
//        idiv p3;
//        mov bx, p5;
//        sub bx, ax;
//        mov p6, bx; ��������� ���������
//            cmp bx, 0
//            je metka
//            mov ax, p4; ��������� p4 � EAX
//            cwd;
//        idiv p6;
//        mov result, ax;
//
//        jmp end_asm
//            
//            perepolnenie :
//        mov ax, -1;
//            mov r, ax;
//
//        jmp end_asm
//            metka :
//        mov ax, 1; ��������� p4 � EAX
//            mov r, ax; ��������� ���������
//
//            end_asm :
//    }
//    cout << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << p6 << " ";
//    if (r == 1) {
//        cout << "divide by 0!";
//        return 0;
//    }
//    if (r == -1) {
//        cout << "Overflow";
//        return 0;
//    }
//    cout << "Result by assembler: " << result << endl;
//    short A, B, X;
//
//
//    A = a; B = b; X = x;
//
//
//    if ((13 * X * X - B / (7 * A)) == 0) {
//        cout << "Erorr!" << endl;
//        return 0;
//    }
//
//    short n = (5 - (short)pow(X, 3) / B + (short)7 * A + (short)(10 / pow(X, 3)));
//    cout << "result by c++ n = " << n << endl;
//
//    short d = (13 * pow(X, 2) - B / (7 * A));
//    cout << "result by c++ d = " << d << endl;
//
//
//    short Y = n / d;
//
//
//    cout << "result by c++ Y = " << Y << endl;
//
//    return 0;
//}   
//#include <iostream>
//#include <cmath>
////Y=(5-x^3/b+7*a+10/x^3 )/(13x^2�b/7a )
//using namespace std;
//
//int main() {
//    int a1, b1, x1, result1 = 0, r1 = 0;
//    int p01=0, p11=0, p21=0, p31=0, p41=0, p51=0, p61=0;
//    cout << "Enter a, b, x: ";
//    cin >> a1 >> b1 >> x1;
//    int8_t a = static_cast<int8_t>(a1);
//    int8_t b = static_cast<int8_t>(b1);
//    int8_t x = static_cast<int8_t>(x1);
//    int8_t result = static_cast<int8_t>(result1);
//    int8_t r = static_cast<int8_t>(r1);
//    int8_t p0 = static_cast<int8_t>(p01);
//    int8_t p1 = static_cast<int8_t>(p11);
//    int8_t p2 = static_cast<int8_t>(p21);
//    int8_t p3 = static_cast<int8_t>(p31);
//    int8_t p4 = static_cast<int8_t>(p41);
//    int8_t p5 = static_cast<int8_t>(p51);
//    int8_t p6 = static_cast<int8_t>(p61);
//    
//    __asm {
//        mov al, x; ��������� x � EAX
//        imul x; ��������� x ^ 2
//        jo perepolnenie
//        imul x; ��������� x ^ 3
//        jo perepolnenie
//        mov p0, al; ��������� ���������
//
//       
//        cmp b, 0
//        je metka
//        idiv b; ��������� x ^ 3 / b
//        mov p1, al; ��������� ���������
//
//        mov al, 10; ��������� 10 � EBX
//
//        cbw;
//        cmp p0, 0
//            je metka
//            idiv p0;
//
//        mov p2, al; ��������� ���������
//            mov al, a;
//        imul al , 7;
//        jo perepolnenie
//            mov p3, al; ��������� ���������
//            cmp p3, 0
//            je metka
//            mov al, p1;
//        mov bl, 5;
//        sub bl, al;
//        jo perepolnenie
//            add bl, p2;
//        jo perepolnenie
//            add bl, p3;
//        jo perepolnenie
//
//            mov p4, bl; ��������� ���������
//            mov al, x; ��������� a � EAX
//            imul al; ��������� x ^ 2
//            jo perepolnenie
//            mov bl, 13;
//            imul  al, bl;
//        jo perepolnenie
//            mov p5, al; ��������� ���������
//            mov al, b;
//            cbw
//            idiv p3;
//        mov bl, p5;
//        sub bl, al;
//        mov p6, bl; ��������� ���������
//            cmp bl, 0
//            je metka
//            mov al, p4; ��������� p4 � EAX
//            cbw;
//        idiv p6;
//        mov result, al;
//
//        jmp end_asm
//
//            perepolnenie :
//        mov al, -1;
//        mov r, al;
//
//        jmp end_asm
//            metka :
//        mov al, 1; ��������� p4 � EAX
//            mov r, al; ��������� ���������
//
//            end_asm :
//    }
//    int a2 = static_cast<int>(a);
//    int b2 = static_cast<int>(b);
//    int x2 = static_cast<int>(x);
//    int result2 = static_cast<int>(result);
//    int r2 = static_cast<int>(r);
//    int p02 = static_cast<int>(p0);
//    int p12 = static_cast<int>(p1);
//    int p22 = static_cast<int>(p2);
//    int p32 = static_cast<int>(p3);
//    int p42 = static_cast<int>(p4);
//    int p52 = static_cast<int>(p5);
//    int p62 = static_cast<int>(p6);
//    cout << p02 << " " << p12 << " " << p22 << " " << p32 << " " << p42 << " " << p52 << " " << p62 << " ";
//    if (r == 1) {
//        cout << "divide by 0!";
//        return 0;
//    }
//    if (r == -1) {
//        cout << "Overflow";
//        return 0;
//    }
//    cout << "Result by assembler: " << result2 << endl;
//    int A, B, X;
//
//
//    A = a1; B = b1; X = x1;
//
//
//    if ((13 * X * X - B / (7 * A)) == 0) {
//        cout << "Erorr!" << endl;
//        return 0;
//    }
//
//    int n = (5 - (int)pow(X, 3) / B + (int)7 * A + (int)(10 / pow(X, 3)));
//    cout << "result by c++ n = " << n << endl;
//
//    int d = (13 * pow(X, 2) - B / (7 * A));
//    cout << "result by c++ d = " << d << endl;
//
//
//    int Y = n / d;
//
//
//    cout << "result by c++ Y = " << Y << endl;
//
//    return 0;
//}