#include <iostream>

using namespace std;

void printArr (int Arr[], int Size)
{
int i;
for (i=0; i<Size; i++)
    {
        if (Arr[i]!=0)
        break;

    }
for (i=i; i<Size; i++)
    {
    cout <<Arr[i]<< " ";
    }

cout <<endl;
    }

int main ()
{
int x=76488;
int y=53789523;
int Size=70;
int ArrX[Size];
ArrX[Size-1]=x%1000;
for (int i=Size-2; i>-1; i--)
    {
    int a=x;
    ArrX[i]=a/1000%1000;
    x/=1000;
    }
printArr(ArrX, Size);

int ArrY[Size];
ArrY[Size-1]=y%1000;
for (int i=Size-2; i>-1; i--)
    {
    int b=y;
    ArrY[i]=y/1000%1000;
    y/=1000;
    }
printArr(ArrY, Size);

int ArrSum[Size];
ArrSum[Size-1]=ArrX[Size-1]+ArrY[Size-1];
cout <<ArrSum[Size-1];
return 0;

}

