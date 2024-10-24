#include <iostream>

using namespace std;

int main()
{
    int array[5] = {5, 3, 2, 9, 6};
    int sum = 0;

    for(auto i : array)
    {
        sum += i;
    }

    cout << "Suma: " << sum;
}
