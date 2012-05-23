/*method of the Monte-Carlo*/

#include <iostream>
#include "math.h"
#include "time.h"
using namespace std;

double func(double x)
{
    double f;
    f=sin(x);
    return f;
}

double sort(double x, double y)
{
    if((0<=y)&&(y<=func(x)))
    {
                       return 1;
    }
    else
    {
                       return 0;         
    }
}

int main()
{
    time_t t;
    srand(time(&t));
    double up=1, down=0, left=0, right=1.57, Ssq, Sfunc;
    int i,j,k=0;
    int n;
    cout<<"Please, enter the number of random points:";
    cin>>n;
    double sq[2][n];
    double h=0.0001;
    Ssq=(up-down)*(right-left);
    for(i=0;i<n;i++)
    {
                       sq[0][i]=rand()%157;
                       sq[1][i]=rand()%100;
                       sq[0][i]=sq[0][i]/100;
                       sq[1][i]=sq[1][i]/100;                       
    }
    for(i=0;i<n;i++)
    {
                       if(sort(sq[0][i],sq[1][i]))
                       {
                                   k++;
                       }
    }
    Sfunc=Ssq*k/n;
    cout<<"The value of your integral is:"<<Sfunc<<'\n';
    system("PAUSE");
    return 0;
}
