#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    set<int> uniqueNumbers;
    srand(static_cast<unsigned int>(time(0)));
    while (uniqueNumbers.size() < 6) {
        int number = rand() % 49 + 1;
        uniqueNumbers.insert(number);
    }

    cout << "Wylosowane unikalne liczby: ";
    for (int number : uniqueNumbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}