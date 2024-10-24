#include <iostream>

using namespace std;

bool isSort(int nums[3])
{
    int num = nums[0];

    for(int i = 1; i < 3; i++)
    {
        if(num > nums[i])
        {
            return false;
        }

        num = nums[i];
    }

    return true;
}

int main()
{
    int nums[3];

    for(int i = 0; i < 3; i++)
    {
        cout << "Podaj liczbe: ";
        cin >> nums[i];
    }

    if(isSort(nums))
    {
        cout << "Liczby sa w kolejnosci rosnacej";
    }
    else
    {
         cout << "Liczby nie sa w kolejnosci rosnacej";
    }
}
