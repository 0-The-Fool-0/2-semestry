#include <iostream>
using namespace std;

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0) return false;
    return true;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "������� ������ ������� (n <= 100): ";
    cin >> n;
    if (n > 100 || n <= 0) {
        cout << "������������ ������!";
        return 1;
    }

    int arr[100];
    cout << "������� " << n << " ��������� �������: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    __asm {
        mov ecx, n        // ���������� ������� �����
        mov esi, 0        // ������ �������� ��������
        mov edi, 0        // ������ ��� ������ �������

        loop_start:
        cmp esi, ecx
            jge loop_end

            mov eax, arr[esi * 4] // ��������� ������� �������
            push eax
            call is_prime
            add esp, 4
            test eax, eax
            jz not_prime

            jmp skip

            not_prime :
        mov eax, arr[esi * 4]  // ��������� �� ������� ����� � ������� eax
            mov arr[edi * 4], eax  // ���������� �� ������� ����� �� �������� eax � ������
            inc edi

            skip :
        inc esi
            jmp loop_start

            loop_end :
        mov n, edi          // �������� ������ �������
    }
    cout << "������ ����� �������� ������� �����: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}