#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int i = 1;
    do {
        sum += i;
        i++;
    } while (i <= 50);

    cout << "Suma liczb od 1 do 50 wynosi: " << sum << endl;
    return 0;
}