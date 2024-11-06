#include <iostream>

using namespace std;

int main() {
  
    int n;


    cout << "Podaj wartosc n: ";
    cin >> n;


    int size = 2 * n - 1;

    
    int** array = new int* [size];
    for (int i = 0; i < size; i++) {
        array[i] = new int[size];
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = 0;
        }
    }
    for (int i = 0; i < size; i++) {
        array[0][i] = 1;
        array[size - 1][i] = 1;
        array[i][0] = 1;
        array[i][size - 1] = 1;
    }


    cout << "Tablica z obramowaniem z jedynek o wymiarach " << size << " x " << size << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

   

    return 0;
}