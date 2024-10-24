#include <iostream>
#include <windows.h>
using namespace std;

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

string tekstDoPrzetworzenia, stekstDoOdszyfrowania;

string zaszyfrujOdszyfruj(string przeslanyTekst) {
    string przetworzonyTekst = "";
    for (char &kolejnaLitera : przeslanyTekst) {
        if (isalpha(kolejnaLitera)) {
            char zmienionaLitera;
            if (isupper(kolejnaLitera)) {
                zmienionaLitera = ((kolejnaLitera - 'A' + 13) % 26) + 'A';
            } else {
                zmienionaLitera = ((kolejnaLitera - 'a' + 13) % 26) + 'a';
            }
            przetworzonyTekst += zmienionaLitera;
        } else {
            przetworzonyTekst += kolejnaLitera;
        }
    }
    return przetworzonyTekst;
}

int main() {
    HANDLE konsola = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(konsola, dwMode);

    cout << "\n\033[1;34;40m=== SZYFR CEZARA ===\033[0m\n" << endl;
    cout << "Podaj tekst do zaszyfrowania: ";
    getline(cin, tekstDoPrzetworzenia);
    string zaszyfrowanyTekst = zaszyfrujOdszyfruj(tekstDoPrzetworzenia);
    cout << "Zaszyfrowany tekst: \033[1;33;40m" << zaszyfrowanyTekst << "\033[0m.\n" << endl;

    cout << "Naciśnij ENTER, aby odszyfrować powyższy tekst\nlub wprowadź swój własny: ";
    getline(cin, stekstDoOdszyfrowania);

    if (!stekstDoOdszyfrowania.empty()) {
        cout << "\nOdszyfrowany tekst: \033[1;33;40m" << stekstDoOdszyfrowania << "\033[0m --> \033[1;33;40m" << zaszyfrujOdszyfruj(stekstDoOdszyfrowania) << "\033[0m." << endl;
    }

    cout << "\n\033[1;30;40mNaciśnij ENTER, aby zakończyć...\033[0m" << endl;
    cin.get();
    return 0;
}
