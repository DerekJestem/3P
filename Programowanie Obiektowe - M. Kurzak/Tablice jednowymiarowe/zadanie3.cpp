#include <iostream>

using namespace std;

int main()
{
    int N;

    cout << "Podaj dlugosc tablicy: ";
    cin >> N;

    double arr[N];

    double avg = 0;
    for(int i = 0; i < N; i++)
    {
        cout << "Podaj liczbe: ";
        cin >> arr[i];

        avg += arr[i];
    }

    avg /= N;

    cout << "Srednia wynosi: " << avg;

}
