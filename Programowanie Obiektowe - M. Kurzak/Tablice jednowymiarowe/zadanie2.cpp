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

    int reverseArr[N];
    int j = 0;
    for(int i = N - 1; i >= 0; i--)
    {
        reverseArr[j] = arr[i];

        j++;
    }

    cout << "Odwrocona tablica: " << endl;
    for(int i = 0; i < N; i++)
    {
        cout << reverseArr[i] << " ";
    }
}
