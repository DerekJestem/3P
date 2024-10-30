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

    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i < N; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "Minimalna wartosc: " << min << endl;
    cout << "Maksymalna wartosc element: " << max << endl;
}
