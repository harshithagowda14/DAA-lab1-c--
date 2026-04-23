#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 256

void shiftTable(char pattern[], int m, int table[]) {
    for (int i = 0; i < SIZE; i++)
        table[i] = m;

    for (int j = 0; j < m - 1; j++)
        table[(int)pattern[j]] = m - 1 - j;
}

int horspool(char text[], char pattern[]) {
    int m = strlen(pattern);
    int n = strlen(text);
    int table[SIZE];

    shiftTable(pattern, m, table);

    int i = m - 1;

    while (i < n) {
        int k = 0;

        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        if (k == m)
            return i - m + 1;
        else
            i += table[(int)text[i]];
    }

    return -1;
}

int main() {
    char text[100], pattern[100];

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    int pos = horspool(text, pattern);

    if (pos >= 0)
        cout << "Pattern found at position: " << pos + 1;
    else
        cout << "Pattern not found";

    return 0;
}