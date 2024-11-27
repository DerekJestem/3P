#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <windows.h> // Potrzebne do aktywacji kolor�w w konsoli systemu Windows
#include <string>

using namespace std;

// Deklarujemy kontener na tablic�, �eby by� widoczny w poszczeg�lnych funkcjach:
vector<int> tablicaLiczb;

// ==================== WYPISZ TABLIC� ===================
void wypiszTablice(vector<int> tablicaLiczb) {
    string tablicaJakoString = "";

    for (int wartoscLicznika = 0; wartoscLicznika < tablicaLiczb.size(); wartoscLicznika++) {
        tablicaJakoString += to_string(tablicaLiczb[wartoscLicznika]);
        tablicaJakoString += ", ";
    }
    // Wycinamy ze stringa dwa ostatnie znaki (przecinek i spacj�):
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
        // Wstawiamy wybran� liczb� na w�a�ciwe miejsce
        tablicaLiczb[licznikWewnetrzny + 1] = wybranaLiczba;
    }
}

int main() {
    setlocale(LC_ALL, "pl_PL");

    // ================= KOLOROWANIE NAPIS�W ================
    HANDLE konsola = GetStdHandle(STD_OUTPUT_HANDLE);

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING // Je�li nie jest zdefiniowany, to:
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
    // Aby powy�sze dzia�a�o, musimy aktywowa� i to, co poni�ej:
#ifndef ENABLE_PROCESSED_OUTPUT // Je�li nie jest zdefiniowany, to:
#define ENABLE_PROCESSED_OUTPUT 0x0001
#endif
    DWORD dwMode = 0;
    dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(konsola, dwMode);
    string suroweDaneUzytkownika, oczyszczoneDaneUzytkownika;
    cout << "\033[1;36;40m\n===== SORTOWANIE PRZEZ WSTAWIANIE =====\033[0m" << endl;
    cout << "DEFINICJA:" << endl;
    cout << "\033[1;30;40mTablica z liczbami dzielona jest logicznie (w naszym umy�le) na dwie tablice:\n-\033[0m \033[1;37;40mtablic� posortowan�\033[0m \033[1;30;40msk�adaj�c� si� pocz�tkowo z jednej liczby --> pierwszy element w tablicy;\n(nale�y uzmys�owi� sobie, �e ka�dy zbi�r sk�adaj�cy si� z jednego elementu jest zbiorem posortowanym);\n-\033[0m \033[1;37;40mtablic� nieposortowan�\033[0m \033[1;30;40msk�adaj�c� si� z pozosta�ych element�w w tablicy.\n\nSortowanie zaczynamy od wybrania drugiej liczby w tablicy i wstawienia jej w odpowiednie miejsce\nw tablicy posortowanej (tej sk�adaj�cej si� z jednego elementu). Mamy dwie mo�liwo�ci:\n"
        "- wstawimy j� przed pierwszym elementem tablicy uporz�dkowanej (je�li jest mniejsza);\n"
        "- lub wstawimy j� po pierwszym elemencie tablicy uporz�dkowanej (je�li jest wi�ksza).\n"
        "W tej drugiej sytuacji, liczba nadpisze sam� siebie (czyli pozornie nic si� nie zmieni), ale stanie\nsi� ona w tym momencie cz�ci� tablicy posortowanej (tablica posortowana b�dzie ju� mia�a dwa elementy).\n\nW kolejnym przebiegu p�tli FOR, bierzemy nast�pn� liczb�, por�wnujemy j� z elementami w tablicy posortowanej\ni wstawiamy w odpowiednie miejsce. Ka�da kolejna liczba w tablicy przesuwa si� tak d�ugo w lewo,\na� nie napotka liczby mniejszej od siebie lub r�wnej (wtedy zatrzymuje si�) i przemieszczanie zaczyna\nnast�pna liczba. Nadrz�dna p�tla przechodzi wi�c po elementach tylko raz.\033[0m\n\n";
label_wpiszLiczby:

    // Wpisywanie danych u�ytkownika
    while (suroweDaneUzytkownika == "") {
        cout << "\n\nPodaj ci�g liczb ca�kowitych oddzielonych spacj�: ";
        getline(cin, suroweDaneUzytkownika);
    }

    // Oczyszczanie danych u�ytkownika z niepoprawnych znak�w
    oczyszczoneDaneUzytkownika = regex_replace(suroweDaneUzytkownika, regex{ R"([^-\d ])" }, "");

    if (oczyszczoneDaneUzytkownika == "") {
        cout << "\n\033[1;31;40mWprowadzone przez ciebie dane nie zawieraj� ani jednej liczby...\033[0m" << endl;
        suroweDaneUzytkownika = "";
        goto label_wpiszLiczby;
    }

    cout << "\n\033[1;30;40mZawarto�� danych po oczyszczeniu: " << oczyszczoneDaneUzytkownika << ".\033[0m\n" << endl;

    istringstream strumienDanych(oczyszczoneDaneUzytkownika);
    int kolejnaLiczbaZeStrumienia;
    while (strumienDanych >> kolejnaLiczbaZeStrumienia) {
        tablicaLiczb.push_back(kolejnaLiczbaZeStrumienia);
    }

    cout << "\033[1;30;40mDane po zamianie na tablic� (przed sortowaniem): ";
    wypiszTablice(tablicaLiczb);
    cout << "\033[0m" << endl << endl;


    sortowaniePrzezWstawianie(tablicaLiczb);

    cout << "Dane posortowane przez wstawianie: \033[1;32;40m";
    wypiszTablice(tablicaLiczb);
    cout << "\033[0m." << endl << endl;

    cout << "Autor: Kamil Janik" << endl << endl;

    cout << "Naci�nij ENTER, aby zako�czy�..." << endl;
    cin.get();
    return 0;
}
