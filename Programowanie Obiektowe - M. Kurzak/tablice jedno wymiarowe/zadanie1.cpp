#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    int tablica[n];
    cout << "Podaj " << n << " elementów tablicy:\n";
    for(int i = 0; i < n; i++) {
        cin >> tablica[i];
    }

    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma += tablica[i];
    }

    cout << "Suma elementów tablicy: " << suma << endl;

    return 0;
}