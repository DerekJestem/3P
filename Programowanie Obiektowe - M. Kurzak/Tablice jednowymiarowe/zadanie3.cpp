#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    int tablica[] = {};
    cout << "Podaj " << n << " elementów tablicy (liczby rzeczywiste):\n";
    for(int i = 0; i < n; i++) {
        cin >> tablica[i];
    }

    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += tablica[i];
    }

    double srednia = suma / n;
    cout << "Średnia wartość elementów tablicy: " << srednia << endl;

    return 0;
}