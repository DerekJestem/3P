#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    int sum = 0;

    do
    {
        sum += i;
        i++;
    }while(i <= 50);

    cout << "Suma: " << sum;
}