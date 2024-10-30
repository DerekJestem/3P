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

    int parzyste = 0, nieparzyste = 0;
    for(int i = 0; i < n; i++) {
        if(tablica[i] % 2 == 0) {
            parzyste++;
        } else {
            nieparzyste++;
        }
    }

    cout << "Liczba elementów parzystych: " << parzyste << endl;
    cout << "Liczba elementów nieparzystych: " << nieparzyste << endl;

    return 0;
}