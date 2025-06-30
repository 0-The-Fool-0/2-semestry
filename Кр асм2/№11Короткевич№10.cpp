#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <windows.h>
using namespace std;



typedef unsigned short WORD;


const int SIZE1 = 32;
const int M = 4; // < 10
extern "C" WORD __cdecl   SumHighDigitsCDECL(DWORD value, int m);
extern "C" WORD __stdcall SumHighDigitsSTDCALL(DWORD value, int m);
extern "C" WORD __fastcall SumHighDigitsFASTCALL(DWORD value, int m);

void printArray(const vector<DWORD>& arr) {
    cout << "�������� ������ (DWORD): ";
    for (auto val : arr) {
        cout << val << " ";
    }
    cout << "\n";
}

void printResult(const vector<WORD>& arr, const std::string& label) {
    cout << label << ": ";
    for (auto val : arr) {
        cout << val << " ";
    }
    cout << "\n";
}

int main() {
    srand((unsigned int)std::time(0));
    vector<DWORD> source(SIZE1);
    vector<WORD> result_cdecl, result_stdcall, result_fastcall;

    // ��������� ��������� �����
    for (int i = 0; i < SIZE1; ++i)
        source[i] = rand() % 1000000000; // �� 9 ����

    printArray(source);

    // ������ ��� ����������
    for (DWORD val : source)
        result_cdecl.push_back(SumHighDigitsCDECL(val, M));

    for (DWORD val : source)
        result_stdcall.push_back(SumHighDigitsSTDCALL(val, M));

    for (DWORD val : source)
        result_fastcall.push_back(SumHighDigitsFASTCALL(val, M));

    printResult(result_cdecl, "��������� (cdecl)");
    printResult(result_stdcall, "��������� (stdcall)");
    printResult(result_fastcall, "��������� (fastcall)");

    return 0;
}
