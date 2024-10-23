#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int suma = 0;
    const int liczbaElementow = 20;

    cout << "Wylosowane liczby: ";
    for (int i = 0; i < liczbaElementow; ++i) {
        int liczba = rand() % 100 + 1;
        cout << liczba << " ";
        suma += liczba;
    }
    
    double srednia = static_cast<double>(suma) / liczbaElementow;
    cout << "\nSuma: " << suma << endl;
    cout << "Średnia: " << srednia << endl;

    return 0;
}