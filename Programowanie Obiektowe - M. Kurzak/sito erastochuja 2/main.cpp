#include <iostream>
#include <cmath>
using namespace std;

/*
 * Program:             Sito Eratostenesa
 * Autor:               Jakub Wieczorek
 * Data:                10.04.2025
 * Opis:                Program znajduje liczby pierwsze w przedziale (2; n) przy użyciu algorytmu Sita Eratostenesa.
 * Wersja:              1.0
 * Środowisko:          Windows
 */

/*
 * nazwa funkcji:       sitoEratostenesa
 * parametry wejściowe: A - tablica logiczna, n - maksymalna liczba
 * wartość zwracana:    brak zwracanej wartości
 * informacje:          Funkcja wykonuje sito Eratostenesa, skreślając wielokrotności liczb pierwszych
 */
void sitoEratostenesa(bool A[], int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (A[i]) {
            for (int j = i * i; j <= n; j += i) {
                A[j] = false;
            }
        }
    }
}

/*
 * nazwa funkcji:       wypelnienie
 * parametry wejściowe: A - tablica logiczna
 * wartość zwracana:    brak zwracanej wartości
 * informacje:          Funkcja wypełnia tablicę A wartościami true (oznacza, że liczba jest potencjalnie pierwsza)
 */

void wypelnienie(bool A[], int n) {
    for (int i = 2; i <= n; ++i) {
        A[i] = true;
    }
}

int main() {
    int n = 100;
    bool A[n + 1];

    wypelnienie(A, n);  // Wypełnienie tablicy wartościami true

    sitoEratostenesa(A, n);  // Uruchomienie algorytmu Sita Eratostenesa

    cout << "Liczby pierwsze w przedziale (2;" << n << ") to: ";
    for (int i = 2; i <= n; ++i) {
        if (A[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
