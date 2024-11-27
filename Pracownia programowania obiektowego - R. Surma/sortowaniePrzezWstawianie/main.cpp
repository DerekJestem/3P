#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <windows.h> // Potrzebne do aktywacji kolorów w konsoli systemu Windows
#include <string>

using namespace std;

// Deklarujemy kontener na tablicę, żeby był widoczny w poszczególnych funkcjach:
vector<int> tablicaLiczb;

// ==================== WYPISZ TABLICĘ ===================
void wypiszTablice(vector<int> tablicaLiczb) {
    string tablicaJakoString = "";

    for (int wartoscLicznika = 0; wartoscLicznika < tablicaLiczb.size(); wartoscLicznika++) {
        tablicaJakoString += to_string(tablicaLiczb[wartoscLicznika]);
        tablicaJakoString += ", ";
    }
    // Wycinamy ze stringa dwa ostatnie znaki (przecinek i spację):
    tablicaJakoString.pop_back();
    tablicaJakoString.pop_back();
    cout << tablicaJakoString;

}

// ================ SORTOWANIE PRZEZ WSTAWIANIE ===============
void sortowaniePrzezWstawianie(vector<int>& tablicaLiczb) {

    for (int licznikGlowny = 1; licznikGlowny < tablicaLiczb.size(); licznikGlowny++) {
        int wybranaLiczba = tablicaLiczb[licznikGlowny];
        int licznikWewnetrzny = licznikGlowny - 1;

        // Szukamy miejsca dla wybranej liczby
        while (licznikWewnetrzny >= 0 && tablicaLiczb[licznikWewnetrzny] > wybranaLiczba) {
            tablicaLiczb[licznikWewnetrzny + 1] = tablicaLiczb[licznikWewnetrzny];
            licznikWewnetrzny--;
        }
        // Wstawiamy wybraną liczbę na właściwe miejsce
        tablicaLiczb[licznikWewnetrzny + 1] = wybranaLiczba;
    }
}

int main() {
    cout << "Autor: Jakub Wieczorek";
    // ================= KOLOROWANIE NAPISÓW ================
    HANDLE konsola = GetStdHandle(STD_OUTPUT_HANDLE);

    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING // Jeśli nie jest zdefiniowany, to:
     #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
     #endif
     // Aby powyższe działało, musimy aktywować i to, co poniżej:
     #ifndef ENABLE_PROCESSED_OUTPUT // Jeśli nie jest zdefiniowany, to:
     #define ENABLE_PROCESSED_OUTPUT 0x0001
     #endif
    DWORD dwMode = 0;
    dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(konsola, dwMode);
    string suroweDaneUzytkownika, oczyszczoneDaneUzytkownika;
    cout << "\033[1;36;40m\n===== SORTOWANIE PRZEZ WSTAWIANIE =====\033[0m" << endl;
    cout << "DEFINICJA:" << endl;
    cout << "\033[1;30;40mTablica z liczbami dzielona jest logicznie (w naszym umyśle) na dwie tablice:\n-\033[0m \033[1;37;40mtablicę posortowaną\033[0m \033[1;30;40mskładającą się początkowo z jednej liczby --> pierwszy element w tablicy;\n(należy uzmysłowić sobie, że każdy zbiór składający się z jednego elementu jest zbiorem posortowanym);\n-\033[0m \033[1;37;40mtablicę nieposortowaną\033[0m \033[1;30;40mskładającą się z pozostałych elementów w tablicy.\n\nSortowanie zaczynamy od wybrania drugiej liczby w tablicy i wstawienia jej w odpowiednie miejsce\nw tablicy posortowanej (tej składającej się z jednego elementu). Mamy dwie możliwości:\n"
        "- wstawimy ją przed pierwszym elementem tablicy uporządkowanej (jeśli jest mniejsza);\n"
        "- lub wstawimy ją po pierwszym elemencie tablicy uporządkowanej (jeśli jest większa).\n"
        "W tej drugiej sytuacji, liczba nadpisze samą siebie (czyli pozornie nic się nie zmieni), ale stanie\nsię ona w tym momencie częścią tablicy posortowanej (tablica posortowana będzie już miała dwa elementy).\n\nW kolejnym przebiegu pętli FOR, bierzemy następną liczbę, porównujemy ją z elementami w tablicy posortowanej\ni wstawiamy w odpowiednie miejsce. Każda kolejna liczba w tablicy przesuwa się tak długo w lewo,\naż nie napotka liczby mniejszej od siebie lub równej (wtedy zatrzymuje się) i przemieszczanie zaczyna\nnastępna liczba. Nadrzędna pętla przechodzi więc po elementach tylko raz.\033[0m\n\n";
label_wpiszLiczby:

    // Wpisywanie danych użytkownika
    while (suroweDaneUzytkownika == "") {
        cout << "\n\nPodaj ciąg liczb całkowitych oddzielonych spacją: ";
        getline(cin, suroweDaneUzytkownika);
    }

    // Oczyszczanie danych użytkownika z niepoprawnych znaków
    oczyszczoneDaneUzytkownika = regex_replace(suroweDaneUzytkownika, regex{ R"([^-\d ])" }, "");

    if (oczyszczoneDaneUzytkownika == "") {
        cout << "\n\033[1;31;40mWprowadzone przez ciebie dane nie zawierają ani jednej liczby...\033[0m" << endl;
        suroweDaneUzytkownika = "";
        goto label_wpiszLiczby;
    }

    cout << "\n\033[1;30;40mZawartość danych po oczyszczeniu: " << oczyszczoneDaneUzytkownika << ".\033[0m\n" << endl;

    istringstream strumienDanych(oczyszczoneDaneUzytkownika);
    int kolejnaLiczbaZeStrumienia;
    while (strumienDanych >> kolejnaLiczbaZeStrumienia) {
        tablicaLiczb.push_back(kolejnaLiczbaZeStrumienia);
    }

    cout << "\033[1;30;40mDane po zamianie na tablicę (przed sortowaniem): ";
    wypiszTablice(tablicaLiczb);
    cout << "\033[0m" << endl << endl;


    sortowaniePrzezWstawianie(tablicaLiczb);

    cout << "Dane posortowane przez wstawianie: \033[1;32;40m";
    wypiszTablice(tablicaLiczb);
    cout << "\033[0m." << endl << endl;

    cout << "Naciśnij ENTER, aby zakończyć..." << endl;
     cin.get();
    return 0;
}
