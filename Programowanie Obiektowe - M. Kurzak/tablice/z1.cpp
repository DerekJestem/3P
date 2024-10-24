#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> liczby = {1, 2, 3, 4, 5};
  int suma = 0;

  for (int i = 0; i < liczby.size(); i++) {
    suma += liczby[i];
  }

  cout << "Suma elementów tablicy: " << suma << endl;

  return 0;
}