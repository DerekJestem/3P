#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <windows.h>
using namespace std;

float kursEuro = 4.27;
float kursDolara = 3.84;
int wyborUzytkownika;
float iloscWaluty = 0;
string tablicaOdpowiedziTak[] = {"Tak", "tak", "T", "t", "Yes", "yes", "y", "Y", "taa", "yee","ta", "Ta"};
string podpowiedz;

int main() {
    HANDLE konsola = GetStdHandle(STD_OUTPUT_HANDLE);

    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif
    #ifndef ENABLE_PROCESSED_OUTPUT
    #define ENABLE_PROCESSED_OUTPUT 0x0001
    #endif

    DWORD dwMode = 0;
    dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(konsola, dwMode);

    start:
    cout << "\n\033[1;34;40m=== KANTOR WYMIANY WALUT ===\033[0m\n" << endl;

    while(true) {
        cout << "\033[1;30;40mOpcje wymiany:" << endl;
        cout << "1. PLN --> EUR" << endl;
        cout << "2. PLN --> USD" << endl;
        cout << "3. EUR --> PLN" << endl;
        cout << "4. EUR --> USD" << endl;
        cout << "5. USD --> PLN" << endl;
        cout << "6. USD --> EUR\033[0m" << endl;
        cout << "Podaj numer operacji (1-6): ";

        if ((cin >> wyborUzytkownika) && (cin.peek() == '\n')) {
            cout << "\033[1;30;40mNumer operacji wybranej przez użytkownika: " << wyborUzytkownika << ".\033[0m\n" << endl;
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\033[1;31;40mPodana wartość nie jest liczbą całkowitą. Spróbuj jeszcze raz.\033[0m\n" << endl;
        }
    }

    switch(wyborUzytkownika) {
        case 1:
            while(true) {
                cout << "Wpisz, ile euro zamierzasz kupić: ";
                if (cin >> iloscWaluty) {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\033[1;31;40mPodana wartość nie jest poprawną liczbą. Spróbuj jeszcze raz.\033[0m\n" << endl;
                }
            }
            cout << "\nKoszt zakupu takiej ilości euro wynosi: \033[1;32;40m" << fixed << setprecision(2) << (iloscWaluty * kursEuro) << "zł\033[0m." << endl;
            break;
        case 2:
            while(true) {
                cout << "Wpisz, ile dolarów zamierzasz kupić: ";
                if (cin >> iloscWaluty) {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\033[1;31;40mPodana wartość nie jest poprawną liczbą. Spróbuj jeszcze raz.\033[0m\n" << endl;
                }
            }
            cout << "\nKoszt zakupu takiej ilości dolarów wynosi: \033[1;32;40m" << fixed << setprecision(2) << (iloscWaluty * kursDolara) << "zł\033[0m." << endl;
            break;
        case 3:
            while(true) {
                cout << "Wpisz, ile złotych zamierzasz kupić: ";
                if (cin >> iloscWaluty) {
                    break;
                }
                else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\033[1;31;40mPodana wartość nie jest poprawną liczbą. Spróbuj jeszcze raz.\033[0m\n" << endl;
                }
            }
            cout << "\nKoszt zakupu takiej ilości złotych wynosi: \033[1;32;40m" << fixed <<
            setprecision(2) << (iloscWaluty / kursEuro);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"€\033[0m." << endl;
            SetConsoleOutputCP(852);
            break;
        case 4:
            while(true) {
                cout << "Wpisz, ile dolarów zamierzasz kupić: ";
                if (cin >> iloscWaluty) {
                    break;
                }
                else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\033[1;31;40mPodana wartość nie jest poprawną liczbą. Spróbuj jeszcze raz.\033[0m\n" << endl;
                }
            }
            cout << "\nKoszt zakupu takiej ilości dolarów wynosi: \033[1;32;40m" << fixed << setprecision(2) << (iloscWaluty * kursDolara);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"€\033[0m." << endl;
            SetConsoleOutputCP(852);
            break;
        case 5:
            while(true) {
                cout << "Wpisz, ile złotych zamierzasz kupić: ";
                if (cin >> iloscWaluty) {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\033[1;31;40mPodana wartość nie jest poprawną liczbą. Spróbuj jeszcze raz.\033[0m\n" << endl;
                }
            }
            cout << "\nKoszt zakupu takiej ilości złotych wynosi: \033[1;32;40m" << "$" << fixed << setprecision(2) << (iloscWaluty / kursDolara) << "\033[0m." << endl;
            break;
        case 6:
            while(true) {
                cout << "Wpisz, ile euro zamierzasz kupić: ";
                if (cin >> iloscWaluty) {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\033[1;31;40mPodana wartość nie jest poprawną liczbą. Spróbuj jeszcze raz.\033[0m\n" << endl;
                }
            }
            cout << "\nKoszt zakupu takiej ilości euro wynosi: \033[1;32;40m" << "$" << fixed << setprecision(2) << ((iloscWaluty * kursEuro) / kursDolara) << "\033[0m." << endl;;
            break;
        default:
            cout << "\n\033[1;31;40mPodałeś nieprawidłowy numer operacji.\033[0m\n" << endl;
            break;
    }

    cout << "\nCzy chcesz ponownie zakupić walutę? (tak / nie): ";
    cin >> podpowiedz;

    bool jestObecne = find(begin(tablicaOdpowiedziTak), end(tablicaOdpowiedziTak), podpowiedz)!= end(tablicaOdpowiedziTak);
    if (jestObecne) {
        goto start;
    } else {
        cout << "\n\033[1;30;40mNaciśnij ENTER, aby zakończyć...\033[0m" << endl;
        cout << "Wykonał: Oskar Bojanowski"<<endl;
    }

    cin.ignore(256,'\n');
    cin.get();
    return 0;
}
