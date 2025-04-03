#include <iostream>
using namespace std;

int main() {
    int t;
    cout << "Podaj liczbę pociągów: ";
    cin >> t;
    
    while (t--) {
        int v1, v2;
        cout << "Podaj prędkości pierwszego i drugiego pociągu: ";
        cin >> v1 >> v2;
        cout << "Średnia prędkość: " << (2 * v1 * v2) / (v1 + v2) << endl;
    }
    
    return 0;
}
