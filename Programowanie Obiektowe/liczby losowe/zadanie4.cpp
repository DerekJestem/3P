#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int wylosowanaLiczba = rand() % 100 + 1;
    int zgadywanaLiczba;

    cout << "Zgadnij liczbę (1-100): ";

    do {
        cin >> zgadywanaLiczba;
        if (zgadywanaLiczba > wylosowanaLiczba) {
            cout << "Za duża! Spróbuj ponownie: ";
        } else if (zgadywanaLiczba < wylosowanaLiczba) {
            cout << "Za mała! Spróbuj ponownie: ";
        } else {
            cout << "Brawo! Odgadłeś liczbę!" << endl;
        }
    } while (zgadywanaLiczba != wylosowanaLiczba);

    return 0;
}