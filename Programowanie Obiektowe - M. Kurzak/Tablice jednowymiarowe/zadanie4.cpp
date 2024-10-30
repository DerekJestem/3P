#include <iostream>

using namespace std;

int main()
{
    int N;

    cout << "Podaj dlugosc tablicy: ";
    cin >> N;

    int arr[N];

    for(int i = 0; i < N; i++)
    {
        cout << "Podaj liczbe: ";
        cin >> arr[i];
    }

    int evenCount = 0;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] % 2 == 0)
        {
            evenCount++;
        }
    }

    cout << "Ilosc liczb parzystych: " << evenCount << endl;
    cout << "Ilosc liczb nie parzystych: " << N - evenCount;

}
