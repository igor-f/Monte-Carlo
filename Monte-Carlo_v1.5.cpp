/*method of the Monte-Carlo*/

#include <iostream>
#include "math.h"
#include "time.h"
using namespace std;

double func(double num, double x)
{
    double f;
    if(num==1) f=cos(x);
    if(num==2) f=sin(x);
    if(num==3) f=exp(x);
    if(num==4) f=pow(x,2)-1;
    if(num==5) f=sin(pow(x,2));
    if(num==6) f=tan(x); 
    return f;
}

int sort_up(double f,double x, double y)
{
    if((0<=y)&&(y<=func(f,x)))
    {
                       return 1;
    }
    else
    {
                       return 0;         
    }
}

int sort_down(double f,double x, double y)
{
    if((y>=func(f,x))&&(y<=0))
    {
                       return 1;
    }
    else
    {
                       return 0;         
    }
}

double find_top(double f,double h, double left, double right)
{
    double i, max=0;
    for(i=left;i<=right;i=i+h)
    {
                       if(max<func(f,i))
                       {
                                    max=func(f,i);
                       }
    }
    return max;
}

double find_down(double f,double h, double left, double right)
{
    double i, min=0;
    for(i=left;i<=right;i=i+h)
    {
                       if(min>func(f,i))
                       {
                                    min=func(f,i);
                       }
    }
    if(min>=0)
    {
               min=0;
    }
    return min;
}

void list_func()
{
    cout<<"Please, choose any function:\n";
    cout<< "1. cos(x);\n";
    cout<< "2. sin(x);\n";
    cout<< "3. exp(x);\n";
    cout<< "4. x^2-1;\n";
    cout<< "5. sin(x^2);\n";
    cout<< "6. tg(x) (Input values must belong to the interval (-pi/2;pi/2)).\n";
    cout<< "Number ot your function is:";
}

void rand_point(double right, double left, double max, double down, int n, double *sq)
{
    srand(time(NULL));
    int i;
    for(i=0;i<n;i++)
    {
                  sq[i]=rand()%(int)(right*100)+(int)(left*100);
                  sq[n+i]=rand()%(int)(max*100)+(int)(down*100);
                  sq[i]=sq[i]/100;
                  sq[n+i]=sq[n+i]/100;
    }
}

int main()
{
    double max, min, down=0, left, right, Ssqup, Sfuncup, Ssqdw, Sfuncdw, S;
    int i,j,k=0;
    int f;
    list_func();
    cin>>f;
    int n;
    cout<<"Please, enter the number of random points:";
    cin>>n;
    double sq[2][n];
    double h=0.0001;
    cout<<"Please, enter the ends of your interval through the space:";
    cin>>left>>right;
    i=1;
    if(f==6)
    {
            while(i!=0)
            {
                       if((left<=-1.57)||(left>=1.57)||(right<=-1.57)||(right>=1.57))
                       {
                             cout<<"Please, enter the ends of your interval from interval (-pi/2;pi/2):";
                             cin>>left>>right;
                       }
                       if((left>-1.57)&&(left<1.57)&&(right>-1.57)&&(right<1.57))
                       { 
                             i=0;
                       }
            }
    }
    max=find_top(f,h,left,right);
    cout<<"Top of your function is:"<<max<<'\n';
    min=find_down(f,h,left,right);
    cout<<"Minimum of your function is:"<<min<<'\n';
    Ssqup=(max-down)*(right-left);
    rand_point(right, left, max, down, n, sq[0]);                 
    for(i=0;i<n;i++)
    {
                       if(sort_up(f,sq[0][i],sq[1][i]))
                       {
                                   k++;
                       }
    }
    Sfuncup=Ssqup*k/n;
    if(min>=0)
    {
              Ssqdw=0;
    }
    else
    {
              k=0;
              Ssqdw=(down-min)*(right-left);
              rand_point(right, left, min, down, n, sq[0]);
              for(i=0;i<n;i++)
              {
                              sq[0][i]=-sq[0][i];
                              sq[1][i]=-sq[1][i];
              }
              for(i=0;i<n;i++)
              {
                              if(sort_down(f,sq[0][i],sq[1][i]))
                              {
                                                 k++;
                              }
              }
    }
    Sfuncdw=Ssqdw*k/n;
    S=Sfuncup-Sfuncdw;
    cout<<"The value of your integral is:"<<S<<'\n';
    system("PAUSE");
    return 0;
}
