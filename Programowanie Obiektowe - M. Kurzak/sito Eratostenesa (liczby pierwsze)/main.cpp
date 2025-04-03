#include <iostream>
#include <cmath>
using namespace std;

void sitoEratostenesa(bool A[], int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (A[i]) {
            for (int j = i * i; j <= n; j += i) {
                A[j] = false;
            }
        }
    }
}

int main() {
    int n = 100;
    bool A[n + 1];
    
    for (int i = 2; i <= n; ++i) {
        A[i] = true;
    }
    
    sitoEratostenesa(A, n);
    
    cout << "Liczby pierwsze w przedziale (2;" << n << ") to: ";
    for (int i = 2; i <= n; ++i) {
        if (A[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}
