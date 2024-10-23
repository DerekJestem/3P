#pragma comment(linker, "/STACK:20000000")
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int liczba = rand() % 100 + 1;

    cout << "Wylosowana liczba: " << liczba << endl;
    if (liczba % 2 == 0) {
        cout << "Liczba jest parzysta." << endl;
    } else {
        cout << "Liczba jest nieparzysta." << endl;
    }

    return 0;
}