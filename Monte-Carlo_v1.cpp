/*method of the Monte-Carlo*/

#include <iostream>
#include "math.h"
#include "time.h"
using namespace std;

double func(double x)//задаем саму функцию
{
    double f;
    f=sin(x);
    return f;
}

double sort(double x, double y)//функци€, определ€юща€€, попадает ли точка под график функции
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
    double up=1, down=0, left=0, right=1.57, Ssq, Sfunc;//задаем размеры пр€моугольника и площади пр€моугольника и функции
    int i,j,k=0;
    int n;//количество точек
    cout<<"Please, enter the number of random points:";
    cin>>n;
    double sq[2][n];//массив дл€ рандомных точек
    double h=0.0001;// шаг дл€ поиска максимума
    Ssq=(up-down)*(right-left);//площадь описаного пр€моугольника
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
    Sfunc=Ssq*k/n;//вычиcл€ем значение интеграла
    cout<<"The value of your integral is:"<<Sfunc<<'\n';
    system("PAUSE");
    return 0;
}
