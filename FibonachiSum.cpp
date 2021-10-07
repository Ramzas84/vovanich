#include <iostream>

using namespace std;

int main ()
{
int Num;
cin >> Num;
int a=1;
int b=0;
int summ=1;
for (int i=2; i<=Num; i++)
    {
    a=a+b;
    b=a-b;
    summ+=a;
    //cout <<a <<"\t";
    }

cout <<endl <<summ<< endl;


return 0;
}
