#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {

  vector<int> liczby;


  int n;
  cout << "Podaj liczbę elementów: ";
  cin >> n;

  cout << "Podaj " << n << " liczb całkowitych oddzielonych spacja: ";
  for (int i = 0; i < n; i++) {
    int liczba;
    cin >> liczba;
    liczby.push_back(liczba);
  }


  if (liczby.empty()) {
    cout << "Wektor jest pusty!" << endl;
    return 0;
  }

  int max = liczby[0];
  int min = liczby[0];
  for (int i = 1; i < n; i++) {
    if (liczby[i] > max) {
      max = liczby[i];
    }
    if (liczby[i] < min) {
      min = liczby[i];
    }
  }


  cout << "Maksymalny element: " << max << endl;
  cout << "Minimalny element: " << min << endl;

  return 0;
}