#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<double> liczby = {1.0, 2.5, 3.7, 4.2, 5.1};
  double suma = 0.0;

  for (int i = 0; i < liczby.size(); i++) {
    suma += liczby[i];
  }

  double srednia = suma / liczby.size();


  cout << "Średnia elementów tablicy: " << srednia << endl;

  return 0;
}