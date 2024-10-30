#include <iostream>

using namespace std;

int main()
{
    int N;

    cout << "Podaj dlugosc tablicy: ";
    cin >> N;

    int arr[N];

    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        cout << "Podaj liczbe: ";
        cin >> arr[i];

        sum += arr[i];
    }

    cout << "Suma elementow tablicy wynosi: " << sum;

}
