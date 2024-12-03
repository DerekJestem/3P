#include <iostream>
using namespace std;

int main() {
    int num = 1;
    cout << "Liczby parzyste od 1 do 50:" << endl;
    while (num <= 50) {
        if (num % 2 == 0) {
            cout << num << " ";
        }
        num++;
    }
    cout << endl;
    return 0;
}