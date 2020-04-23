#include<stdio.h>

#define ACCURACY 0.001


int a, b, step=0 ;

double fun1(double x){
    return x*x*x + 3.0*x -5.0;
}

void getting_A_B(){

    bool done = false;
    bool pos = false;
    bool neg = false;

    int i=0;

    while (done!=true)
    {
         if((pos && fun1((i+1)*1.0 < 0)) || (neg && fun1((i+1)*1.0 >=0)))
           done = true;

        if (fun1(i*1.0) >= 0) pos = true;
        if (fun1(i*1.0) < 0) neg = true;

        a = i;
        b=i+1;
        i++;
       
    }
    printf("\n Root lies between %d and %d\n",a,b);
}


// geting c
double GetC(double x, double y){

    return (x + y)/2.0;
}


double Get_FoC(double x, double y){


    return fun1(GetC(x,y));
}


// Bisection MEthode
double root_by_bisection_Law()
{

    getting_A_B();
    
    double x0, x1;
    x0 = a<b? a : b;
    x1 = a<b? b : a;

    while((x1-x0)>ACCURACY){

        double x_0= x0, x_1 = x1;
        double Fc_val = Get_FoC(x_0, x_1);
        double c_val =GetC(x0,x1);
           //     printf(" x0 = %lf   x1=%lf  C = %lf  b-a= %lf\n",x0, x1, c_val ,x_1-x_0);

        if (Get_FoC(x_0, x_1)<0) x0 = GetC(x0, x1);
        else  x1=GetC(x0, x1);
         step++;
        printf(" x0 = %lf   x1=%lf  C = %lf  F(c)=  %lf  b-a= %lf\n",x0, x1,c_val ,Fc_val,x1-x0);

    }
    return Get_FoC(x0,x1);
}

int main(){

    
    double v = root_by_bisection_Law();
    printf("root = %lf   step= %d\n",v,step);
}
