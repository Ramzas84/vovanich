//
//  main.cpp
//  PerfetcNumOptim
//
//  Created by Романыч on 01.10.2021.
//

#include <iostream>
using namespace std;
//#define int long long

void printArray (long long Arr[], int size)
{
    for (int i=0; i<size; i++)
    {cout <<Arr[i] << "\t";
            if (i%10==9)
            {
                cout <<endl;
            }
    }
    cout <<endl;
}

bool isPrime (int x)
{
    if (x%2==0)
        return false;
    else
    {
        for (int i=3; i*i<=x; i+=2)
        {
            if (x%i==0)
            {
                return false;
                break;
            }
        }
    }
    return true;
}

void primeArray (long long x)
{
    long long Arr [x];
    Arr[0]=3;
    for (int i=1; i<x; i++)
    {
        for (long long x=Arr[i-1]+2; true; )
        {
            if (isPrime (x)==true)
            {
                Arr[i]=x;
                break;
            }
            else x+=2;
        }
    }
}

void perfect (long long x)
{
    long long Arr [x]; //не смог вставить через функцию
    Arr[0]=3;
    for (long long i=1; i<x; i++)
    {
        for (long long x=Arr[i-1]+2; true; )
        {
            if (isPrime (x)==true)
            {
                Arr[i]=x;
                break;
            }
            else x+=2;
        }
    }
   // printArray (Arr, x);
    
    for (long long i=0; i<x; i++)
    {
        long long summ =1;
        for (long long j=1; ; )
        {
            summ+=Arr[i]*j+2*j; // сумма j=j*2 а надо в 1 2 4 8 16
            if (summ ==Arr[i]*2*j)
            {
                cout <<summ <<endl;
                break;
            }
            if (summ <Arr[i]*2*j)
            {
                j*=2;
            }
            else break;
        }
    }
        
}

void arrFuller(int Arr[], int size)
{
    for (size_t i=0; i<size; i++)
    {
        Arr[i]=i+1;
    }
    
}


/*
void simpleNumbers ()
{
    cout <<"Enter num of simple numbers: ";
    int numOfNumbers;
    cin >> numOfNumbers;
    int simpleArr[numOfNumbers];
    simpleArr[0]=3;
    for (int i=1; i < numOfNumbers; i++) // все ячейки с простыми числами
    {
        for (int num=simpleArr[i-1]++; ;num+=2)  // поиск простого числа бегу по всем числам
        {
           
            
            }
            
            if (num/simpleArr[i]==0)
            {i++;}
            
                 
        }
    }
}
*/

int main(){

    cout <<"Enter size:";
    int size;
    cin >> size;
    
    perfect (size);
   
    
    return 0;
};
