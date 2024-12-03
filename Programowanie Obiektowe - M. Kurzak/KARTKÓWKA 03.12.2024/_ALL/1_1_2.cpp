#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Podaj liczbę: ";
    cin >> num;

    if (num % 2 == 0) {
        cout << num << " jest podzielna przez 2." << endl;
    } else if (num % 3 == 0) {
        cout << num << " jest podzielna przez 3." << endl;
    } else if (num % 5 == 0) {
        cout << num << " jest podzielna przez 5." << endl;
    } else {
        cout << num << " nie jest podzielna przez 2, 3 ani 5." << endl;
    }

    return 0;
}