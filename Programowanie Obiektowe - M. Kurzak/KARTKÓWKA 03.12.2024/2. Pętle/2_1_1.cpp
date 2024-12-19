#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 1; i <= 50; i++) {
        sum += i;
    }
    cout << "Suma liczb od 1 do 50 wynosi: " << sum << endl;
    return 0;
}