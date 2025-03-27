#include <iostream>
using namespace std;

class Sort {
private:
    int t[10];

    int findMax(int i) {
        int maxIndex = i; 
        for (int j = i + 1; j < 10; j++) {
            if (t[j] > t[maxIndex]) {
                maxIndex = j; 
            }
        }
        return maxIndex;
    }

public:
    void loadT() {
        cout << "Podaj 10 liczb calkowitych do posortowania:" << endl;
        for (int i = 0; i < 10; i++) {
            cin >> t[i];
        }
    }

    void sort() {
        for (int i = 0; i < 9; i++) { 
            int maxIndex = findMax(i); 
            if (maxIndex != i) {
                int temp = t[i];
                t[i] = t[maxIndex];
                t[maxIndex] = temp;
            }
        }
    }

    void displayT() {
        cout << "Posortowana tablica (malejąco):" << endl;
        for (int i = 0; i < 10; i++) {
            cout << t[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Sort sort;

    sort.loadT();
    sort.sort();
    sort.displayT();

    return 0;
}
