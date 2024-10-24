#include <iostream>

using namespace std;

bool hasDuplicate(int nums[3])
{
    for(int i = 0; i < 3; i++)
    {
         for(int j = 0; j < 3; j++)
        {
            if(nums[i] == nums[j] && i != j)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int nums[3];

    for(int i = 0; i < 3; i++)
    {
        cout << "Podaj liczbe: ";
        cin >> nums[i];
    }

    if(hasDuplicate(nums))
    {
        cout << "W tablicy sa przynajmniej 2 takie same liczby";
    }
    else
    {
         cout << "W tablicy zadne liczby sie nie powtarzaja";
    }
}
