#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int array[5] = {5, 3, 2, 9, 6};
    reverse(begin(array), end(array));

    for(auto i : array)
    {
        cout << i << endl;
    }
}
