#include <iostream>

using namespace std;

int main()
{
    int num;

    cout << "Podaj liczbe: ";
    cin >> num;

    if(num >= 1 && num <= 10)
    {
        cout << "Liczba jest w przedziale <1,10>";
    }
    else if(num >= 17 && num <= 21)
    {
        cout << "Liczba jest w przedziale <17,21>";
    }
    else
    {
        cout << "Liczba nie jest w przedziale <1,10> ani <17,21>";
    }

}
