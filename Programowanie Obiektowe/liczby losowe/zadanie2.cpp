#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int suma = 0;

    cout << "Wylosowane liczby: ";
    for (int i = 0; i < 10; ++i) {
        int liczba = rand() % 50 + 1;
        cout << liczba << " ";
        suma += liczba;
    }
    cout << "\nSuma: " << suma << endl;

    return 0;
}