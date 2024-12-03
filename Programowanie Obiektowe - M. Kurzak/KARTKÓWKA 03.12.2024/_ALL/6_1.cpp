#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int MONTHS = 12;
    int sprzedaz[MONTHS];
    int totalSales = 0;

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < MONTHS; i++) {
        sprzedaz[i] = rand() % 9001 + 1000;
        totalSales += sprzedaz[i];
    }

    double averageSales = static_cast<double>(totalSales) / MONTHS;

    cout << "Wyniki sprzedaży dla 12 miesięcy:" << endl;
    for (int i = 0; i < MONTHS; i++) {
        cout << "Miesiąc " << (i + 1) << ": " << sprzedaz[i] << endl;
    }

    cout << "Łączna sprzedaż roczna: " << totalSales << endl;
    cout << "Średnia miesięczna sprzedaż: " << averageSales << endl;

    cout << "Miesiące z sprzedażą powyżej średniej:" << endl;
    for (int i = 0; i < MONTHS; i++) {
        if (sprzedaz[i] > averageSales) {
            cout << "Miesiąc " << (i + 1) << ": " << sprzedaz[i] << endl;
        }
    }

    return 0;
}