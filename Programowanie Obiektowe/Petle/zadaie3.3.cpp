#include <iostream>

using namespace std;

int main()
{
    string password = "1234";
    string givenPassword;

    do
    {
        cout << "Podaj haslo: ";
        cin >> givenPassword;

        if(password != givenPassword)
        {
            cout << "Podano zle haslo! Sprobuj ponownie" << endl;
        }
    }while(password != givenPassword);

    cout << "Podano prawidlowe haslo";
}
