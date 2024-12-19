#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int SIZE = 20;
    int nums[SIZE];
    int sum = 0;

    srand(static_cast<unsigned int>(time(0)));

    cout << "Wylosowane liczby: ";
    for (int i = 0; i < SIZE; i++) {
        nums[i] = rand() % 100 + 1;
        cout << nums[i] << " ";
        sum += nums[i];
    }

    double avg = static_cast<double>(sum) / SIZE;
    cout << "\nŚrednia wylosowanych liczb: " << avg << endl;

    return 0;
}