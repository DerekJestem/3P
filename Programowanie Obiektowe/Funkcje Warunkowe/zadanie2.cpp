#include <iostream>

using namespace std;

int main()
{
    int num;

    cout << "Podaj liczbe: ";
    cin >> num;

    if(num > 0)
    {
        cout << "Liczba " << num << " jest wieksza od zera";
    }
    else if(num < 0)
    {
        cout << "Liczba " << num << " jest mniejsza od zera";
    }
    else
    {
        cout << "Liczba jest równa zero";
    }
}
