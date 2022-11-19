// Даны две строки a и b. Требуется найти максимальную длину
//префикса строки a, который входит как подстрока в строку b. При
//этом считать, что пустая строка является подстрокой любой
//строки. Реализация алгоритмом Кнута-Мориса-Пратта.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

vector<int> prefixFunction(string text) {
    int n = text.length();
    vector<int> pi;
    pi.resize(n);

    // j - индекс первого элемента, i - последующего за ним
    for (int i = 1; i < pi.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && text[j] != text[i]) {
            j = pi[j - 1];              // возвращаем j в начало или туда, где стоят совпадающие значения
                                        // то есть возвращаем j на позицию равную pi[j - 1]
        }
        if (text[i] == text[j]) {
            j++;                        // при совпадающих значениях увеличиваем j на 1, чтобы вствавить значение в массив pi
        }
        pi[i] = j;                      // иначе ставим 0 на i-й элемент массива pi
    }
    return pi;
}

int kmp_search(string a, string b) {
    int j = 0;                          // индекс строки а
    int maximum = 0;                    //максимальная длина префикса строки а
    vector<int> pi = prefixFunction(a);
    for (int i = 0; i < b.size(); i++) {
        while (j > 0 && a[j] != b[i]) {
            j = pi[j - 1];              // возвращаем j в начало или туда, где стоят совпадающие значения
                                        // то есть возвращаем j на позицию равную pi[j - 1]
        }
        if (a[j] == b[i]) {
            j++;                        // при совпадении элементов увеличиваем оба индекса на 1
            if (maximum < j) {
                maximum = j;
            }
        }
    }
    if (maximum == 0) return 1;         // учитываем, что пустая строка является подстрокой любой строки
    return maximum;
}

void ex_2() {
    string a, b;
    cout << "Введите строку а: ";
    cin >> a;
    cout << "Введите строку b: ";
    cin >> b;
    cout << "Максимальная длина префикса строки a, который входит как подстрока в строку b: " << kmp_search(a, b);
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ex_2();
    return 0;
}
