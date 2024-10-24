#include <iostream>

using namespace std;

int getSmallest(int nums[3])
{
    int smallest = nums[0];

    for(int i = 1; i < 3; i++)
    {
        if(nums[i] < smallest)
        {
            smallest = nums[i];
        }
    }

    return smallest;
}

int main()
{
    int nums[3];

    for(int i = 0; i < 3; i++)
    {
        cout << "Podaj liczbe: ";
        cin >> nums[i];
    }

    cout << "Najmniejsza liczba jest: " << getSmallest(nums);
}
