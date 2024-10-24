#include <iostream>

using namespace std;

bool isEven(int num)
{
    if(num % 2 == 0)
    {
        return true;
    }

    return false;
}

int main()
{
   int num;

   cout << "Podaj liczbe: ";
   cin >> num;

   if(isEven(num))
   {
        cout << "Liczba " << num << " jest parzysta";
   }
   else
   {
       cout << "Liczba " << num << " jest nie parzysta";
   }
}
