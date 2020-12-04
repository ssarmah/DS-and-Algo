#include <iostream>
using namespace std;

int DtoB(int);

int main()
{
    int d, b;

    cout<<"\n Enter a decimal number: ";
    cin>>d;
    b = DtoB(d);
    cout<<"\n The binary equivalent is :"<<b ;

    return 0;
}

int DtoB(int d)
{
    if (d == 0)
    {
        return 0;
    }
    else
    {
        return (d % 2 + 10 * DtoB(d / 2));
    }
}
