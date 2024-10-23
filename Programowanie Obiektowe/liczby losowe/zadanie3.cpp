#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

int main() {
    srand(time(0));
    set<int> unikalneLiczby;

    while (unikalneLiczby.size() < 6) {
        int liczba = rand() % 49 + 1;
        unikalneLiczby.insert(liczba);
    }

    cout << "Wylosowane unikalne liczby: ";
    for (int liczba : unikalneLiczby) {
        cout << liczba << " ";
    }
    cout << endl;

    return 0;
}