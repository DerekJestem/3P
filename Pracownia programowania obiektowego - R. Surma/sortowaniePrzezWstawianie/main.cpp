#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <windows.h> // Potrzebne do aktywacji kolorów w konsoli systemu Windows
#include <string>

using namespace std;

// Deklarujemy kontener na tablicê, ¿eby by³ widoczny w poszczególnych funkcjach:
vector<int> tablicaLiczb;

// ==================== WYPISZ TABLICÊ ===================
void wypiszTablice(vector<int> tablicaLiczb) {
    string tablicaJakoString = "";

    for (int wartoscLicznika = 0; wartoscLicznika < tablicaLiczb.size(); wartoscLicznika++) {
        tablicaJakoString += to_string(tablicaLiczb[wartoscLicznika]);
        tablicaJakoString += ", ";
    }
    // Wycinamy ze stringa dwa ostatnie znaki (przecinek i spacjê):
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
        // Wstawiamy wybran¹ liczbê na w³aœciwe miejsce
        tablicaLiczb[licznikWewnetrzny + 1] = wybranaLiczba;
    }
}

int main() {
    setlocale(LC_ALL, "pl_PL");

    // ================= KOLOROWANIE NAPISÓW ================
    HANDLE konsola = GetStdHandle(STD_OUTPUT_HANDLE);

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING // Jeœli nie jest zdefiniowany, to:
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
    // Aby powy¿sze dzia³a³o, musimy aktywowaæ i to, co poni¿ej:
#ifndef ENABLE_PROCESSED_OUTPUT // Jeœli nie jest zdefiniowany, to:
#define ENABLE_PROCESSED_OUTPUT 0x0001
#endif
    DWORD dwMode = 0;
    dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(konsola, dwMode);
    string suroweDaneUzytkownika, oczyszczoneDaneUzytkownika;
    cout << "\033[1;36;40m\n===== SORTOWANIE PRZEZ WSTAWIANIE =====\033[0m" << endl;
    cout << "DEFINICJA:" << endl;
    cout << "\033[1;30;40mTablica z liczbami dzielona jest logicznie (w naszym umyœle) na dwie tablice:\n-\033[0m \033[1;37;40mtablicê posortowan¹\033[0m \033[1;30;40msk³adaj¹c¹ siê pocz¹tkowo z jednej liczby --> pierwszy element w tablicy;\n(nale¿y uzmys³owiæ sobie, ¿e ka¿dy zbiór sk³adaj¹cy siê z jednego elementu jest zbiorem posortowanym);\n-\033[0m \033[1;37;40mtablicê nieposortowan¹\033[0m \033[1;30;40msk³adaj¹c¹ siê z pozosta³ych elementów w tablicy.\n\nSortowanie zaczynamy od wybrania drugiej liczby w tablicy i wstawienia jej w odpowiednie miejsce\nw tablicy posortowanej (tej sk³adaj¹cej siê z jednego elementu). Mamy dwie mo¿liwoœci:\n"
        "- wstawimy j¹ przed pierwszym elementem tablicy uporz¹dkowanej (jeœli jest mniejsza);\n"
        "- lub wstawimy j¹ po pierwszym elemencie tablicy uporz¹dkowanej (jeœli jest wiêksza).\n"
        "W tej drugiej sytuacji, liczba nadpisze sam¹ siebie (czyli pozornie nic siê nie zmieni), ale stanie\nsiê ona w tym momencie czêœci¹ tablicy posortowanej (tablica posortowana bêdzie ju¿ mia³a dwa elementy).\n\nW kolejnym przebiegu pêtli FOR, bierzemy nastêpn¹ liczbê, porównujemy j¹ z elementami w tablicy posortowanej\ni wstawiamy w odpowiednie miejsce. Ka¿da kolejna liczba w tablicy przesuwa siê tak d³ugo w lewo,\na¿ nie napotka liczby mniejszej od siebie lub równej (wtedy zatrzymuje siê) i przemieszczanie zaczyna\nnastêpna liczba. Nadrzêdna pêtla przechodzi wiêc po elementach tylko raz.\033[0m\n\n";
label_wpiszLiczby:

    // Wpisywanie danych u¿ytkownika
    while (suroweDaneUzytkownika == "") {
        cout << "\n\nPodaj ci¹g liczb ca³kowitych oddzielonych spacj¹: ";
        getline(cin, suroweDaneUzytkownika);
    }

    // Oczyszczanie danych u¿ytkownika z niepoprawnych znaków
    oczyszczoneDaneUzytkownika = regex_replace(suroweDaneUzytkownika, regex{ R"([^-\d ])" }, "");

    if (oczyszczoneDaneUzytkownika == "") {
        cout << "\n\033[1;31;40mWprowadzone przez ciebie dane nie zawieraj¹ ani jednej liczby...\033[0m" << endl;
        suroweDaneUzytkownika = "";
        goto label_wpiszLiczby;
    }

    cout << "\n\033[1;30;40mZawartoœæ danych po oczyszczeniu: " << oczyszczoneDaneUzytkownika << ".\033[0m\n" << endl;

    istringstream strumienDanych(oczyszczoneDaneUzytkownika);
    int kolejnaLiczbaZeStrumienia;
    while (strumienDanych >> kolejnaLiczbaZeStrumienia) {
        tablicaLiczb.push_back(kolejnaLiczbaZeStrumienia);
    }

    cout << "\033[1;30;40mDane po zamianie na tablicê (przed sortowaniem): ";
    wypiszTablice(tablicaLiczb);
    cout << "\033[0m" << endl << endl;


    sortowaniePrzezWstawianie(tablicaLiczb);

    cout << "Dane posortowane przez wstawianie: \033[1;32;40m";
    wypiszTablice(tablicaLiczb);
    cout << "\033[0m." << endl << endl;

    cout << "Autor: Kamil Janik" << endl << endl;

    cout << "Naciœnij ENTER, aby zakoñczyæ..." << endl;
    cin.get();
    return 0;
}
