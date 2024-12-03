#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Podaj liczbę: ";
    cin >> num;

    if (num % 2 != 0 && num % 3 != 0 && num & 5 != 0 && num & 7 != 0 || num == 1 || num == 2 || num == 3 || num == 5 || num == 7) {
        cout << "Podana liczba jest liczbą pierwszą.";
    } else {
        cout << "Podana liczba nie jest liczbą pierwszą.";
    }

    return 0;
}