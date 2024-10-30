#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    int tablica[] = {};
    cout << "Podaj " << n << " elementów tablicy:\n";
    for(int i = 0; i < n; i++) {
        cin >> tablica[i];
    }

    int max = INT_MIN;
    int min = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(tablica[i] > max) {
            max = tablica[i];
        }
        if(tablica[i] < min) {
            min = tablica[i];
        }
    }

    cout << "Maksymalny element: " << max << endl;
    cout << "Minimalny element: " << min << endl;

    return 0;
}