#include <iostream>
#include <vector>

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


  int parzyste = 0;
  int nieparzyste = 0;
  for (int liczba : liczby) {
    if (liczba % 2 == 0) {
      parzyste++;
    } else {
      nieparzyste++;
    }
  }


  cout << "Liczba elementów parzystych: " << parzyste << endl;
  cout << "Liczba elementów nieparzystych: " << nieparzyste << endl;

  return 0;
}