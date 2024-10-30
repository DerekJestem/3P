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

    cout << "Tablica przed odwróceniem:\n";
    for(int i = 0; i < n; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n/2; i++) {
        int temp = tablica[i];
        tablica[i] = tablica[n-1-i];
        tablica[n-1-i] = temp;
    }

    cout << "Tablica po odwróceniu:\n";
    for(int i = 0; i < n; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    return 0;
}