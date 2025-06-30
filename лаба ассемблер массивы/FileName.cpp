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
    cout << "Введите размер массива (n <= 100): ";
    cin >> n;
    if (n > 100 || n <= 0) {
        cout << "Некорректный размер!";
        return 1;
    }

    int arr[100];
    cout << "Введите " << n << " элементов массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    __asm {
        mov ecx, n        // Установить счетчик цикла
        mov esi, 0        // Индекс текущего элемента
        mov edi, 0        // Индекс для нового массива

        loop_start:
        cmp esi, ecx
            jge loop_end

            mov eax, arr[esi * 4] // Загрузить элемент массива
            push eax
            call is_prime
            add esp, 4
            test eax, eax
            jz not_prime

            jmp skip

            not_prime :
        mov eax, arr[esi * 4]  // Загрузить не простое число в регистр eax
            mov arr[edi * 4], eax  // Копировать не простое число из регистра eax в массив
            inc edi

            skip :
        inc esi
            jmp loop_start

            loop_end :
        mov n, edi          // Обновить размер массива
    }
    cout << "Массив после удаления простых чисел: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}