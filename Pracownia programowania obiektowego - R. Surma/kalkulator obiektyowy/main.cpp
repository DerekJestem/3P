#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

class Kalkulator {
public:
    double dodaj(double a, double b) {
        return a + b;
    }
    double odejmij(double a, double b) {
        return a - b;
    }
    double pomnoz(double a, double b) {
        return a * b;
    }
    double podziel(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            cout << "\n\n\033[0;37;41mBŁĄD:\033[0m" << endl;
            cout << "\033[1;31;40mW matematyce formalnej nie można dzielić przez (na) zero.\033[0m" << endl;
            return 1;
        }
    }
};

int main() {

    HANDLE konsola = GetStdHandle(STD_OUTPUT_HANDLE);
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif
    #ifndef ENABLE_PROCESSED_OUTPUT
    #define ENABLE_PROCESSED_OUTPUT 0x0001
    #endif
    DWORD dwMode = 10;
    dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(konsola, dwMode);

    Kalkulator kalkulator;
    double liczba1, liczba2, wynik;
    char dzialanie;
    string wartoscUzytkownika;
    bool wprowadzonoLiczbe1 = false;
    bool wprowadzonoLiczbe2 = false;
    bool wprowadzonoDzialanie = false;

    cout << "\n\n\033[1;36;40m=========== KALKULATOR ==========\033[0m\n\n";

    while (!wprowadzonoLiczbe1) {
        cout << "Podaj pierwszą liczbę: ";
        cin >> wartoscUzytkownika;
        try {
            liczba1 = stod(wartoscUzytkownika);
            wprowadzonoLiczbe1 = true;
        } catch (const invalid_argument& exc) {
            cout << "\n\n\033[0;37;41mBŁĄD:\033[0m" << endl;
            cout << "\033[1;31;40mTo nie jest liczba! Spróbuj jeszcze raz.\033[0m\n\n" << endl;
        }
    }

    while (!wprowadzonoDzialanie) {
        char tablicaDzialan[6] = {'+', '-', '*', '/', '\\', '\0'};
        cout << "Wybierz działanie (+, -, *, /): ";
        cin >> dzialanie;
        bool jestObecne = find(begin(tablicaDzialan), end(tablicaDzialan), dzialanie) != end(tablicaDzialan);
        if (jestObecne) {
            wprowadzonoDzialanie = true;
        } else {
            cout << "\n\n\033[0;37;41mBŁĄD:\033[0m" << endl;
            cout << "\033[1;31;40mTo nie jest poprawne działanie! Spróbuj jeszcze raz.\033[0m\n\n" << endl;
        }
    }

    while (!wprowadzonoLiczbe2) {
        cout << "Podaj drugą liczbę: ";
        cin >> wartoscUzytkownika;
        try {
            liczba2 = stod(wartoscUzytkownika);
            wprowadzonoLiczbe2 = true;
        } catch (const invalid_argument& exc) {
            cout << "\n\n\033[0;37;41mBŁĄD:\033[0m" << endl;
            cout << "\033[1;31;40mTo nie jest liczba! Spróbuj jeszcze raz.\033[0m\n\n" << endl;
        }
    }

    switch (dzialanie) {
        case '+':
            wynik = kalkulator.dodaj(liczba1, liczba2);
            cout << "\n\nSuma liczb " << liczba1 << " oraz " << liczba2 << " wynosi \033[1;32;40m" << wynik << "\033[0m.\n\n";
            break;
        case '-':
            wynik = kalkulator.odejmij(liczba1, liczba2);
            cout << "\n\nRóżnica między " << liczba1 << " oraz " << liczba2 << " wynosi \033[1;32;40m" << wynik << "\033[0m.\n\n";
            break;
        case '*':
            wynik = kalkulator.pomnoz(liczba1, liczba2);
            cout << "\n\nIloczyn liczby " << liczba1 << " oraz " << liczba2 << " wynosi \033[1;32;40m" << wynik << "\033[0m.\n\n";
            break;
        case '/':
        case '\\':
            if (liczba2 != 0) {
                wynik = kalkulator.podziel(liczba1, liczba2);
                cout << "\n\nIloraz liczby " << liczba1 << " oraz " << liczba2 << " wynosi \033[1;32;40m" << wynik << "\033[0m.\n\n";
            } else {
                cout << "\n\n\033[0;37;41mBŁĄD:\033[0m" << endl;
                cout << "\033[1;31;40mW matematyce formalnej nie można dzielić przez (na) zero.\033[0m\n\n" << endl;
            }
            break;
        default:
            cout << "\n\n\033[0;37;41mBŁĄD:\033[0m" << endl;
            cout << "\033[1;31;40mNie wybrano prawidłowego działania.\033[0m\n\n" << endl;
            return 1;
    }

    cout << "Naciśnij ENTER, aby zakończyć..." << endl;
    system("pause > nul");
    return 0;
}
