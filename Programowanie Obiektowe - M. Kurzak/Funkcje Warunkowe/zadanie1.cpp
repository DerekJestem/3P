#include <iostream>

using namespace std;

int absolute(int num)
{
    if(num < 0)
    {
        num *= -1;
    }

    return num;
}

int main()
{
    int num;

    cout << "Podaj liczbe: ";
    cin >> num;

    cout << "Wartosc bezwgledna liczby " << num << " wynosi: " << absolute(num);
}
