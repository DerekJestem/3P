#include <iostream>
#include <string>
using namespace std;

int main() {
    string dayName[] = {"Niedziela", "Poniedziałek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota"};
    int dayIndex;

    cout << "Podaj numer dnia tygodnia (1-7): ";
    cin >> dayIndex;

    if (dayIndex >= 1 && dayIndex <= 7) {
        cout << "Dzień tygodnia: " << dayName[dayIndex - 1] << endl;
    } else {
        cout << "Nieprawidłowy numer dnia tygodnia. Podaj liczbę od 1 do 7." << endl;
    }

    return 0;
}