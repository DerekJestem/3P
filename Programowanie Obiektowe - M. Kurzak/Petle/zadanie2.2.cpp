#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    int sum = 0;

    while(i <= 50)
    {
        sum += i;
        i++;
    }

    cout << "Suma: " << sum;
}
