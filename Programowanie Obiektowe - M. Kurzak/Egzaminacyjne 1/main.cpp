#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

vector<int> rzutKoscmi(int liczbaKostek) {
    vector<int> wyniki;
    for (int i = 0; i < liczbaKostek; ++i) {
        wyniki.push_back(rand() % 6 + 1);
    }
    return wyniki;
}

int obliczPunkty(const vector<int>& wyniki) {
    map<int, int> wystapienia;
    int suma = 0;

    for (int liczba : wyniki) {
        wystapienia[liczba]++;
    }

    for (auto& para : wystapienia) {
        if (para.second == 1) {
            continue;
        }
        suma += para.first * para.second; 
    }

    return suma;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    int liczbaKostek;
    char decyzja;

    do {
        do {
            cout << "Ile kostek chcesz rzucić? (3 - 10): ";
            cin >> liczbaKostek;
        } while (liczbaKostek < 3 || liczbaKostek > 10);

        vector<int> wyniki = rzutKoscmi(liczbaKostek);

        cout << "Wyniki rzutów:" << endl;
        for (size_t i = 0; i < wyniki.size(); ++i) {
            cout << "Kostka " << i + 1 << ": " << wyniki[i] << endl;
        }

        int punkty = obliczPunkty(wyniki);
        cout << "Liczba uzyskanych punktów: " << punkty << endl;
        
        cout << "Jeszcze raz? (t/n): ";
        cin >> decyzja;

    } while (decyzja == 't' || decyzja == 'T');

    cout << "Dziękuję za grę!" << endl;
    return 0;
}
