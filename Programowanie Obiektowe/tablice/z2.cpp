#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> liczby = {1, 2, 3, 4, 5};


  for (int i = 0; i < liczby.size() / 2; i++) {
    swap(liczby[i], liczby[liczby.size() - 1 - i]);
  }


  cout << "Odwrócona tablica: ";
  for (int i = 0; i < liczby.size(); i++) {
    cout << liczby[i] << " ";
  }
  cout << endl;

  return 0;
}