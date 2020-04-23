#include<stdio.h>
#include<math.h>

#define ACCURACY 0.000001

double Fx(double x){
 return x*x*x - 3*x +1; 
}

double Fx_Phi(double x){
    return  pow((3*x -1), (1/3.0));
}
int a, b, step=0 ;

void getting_A_B(){

    bool done = false;
    bool pos = false;
    bool neg = false;
    

    int i=0;

    while (done!=true)
    {
       
        if((pos && Fx((i+1.0) < 0)) || (neg && Fx((i+1.0)>=0)))done = true;
        
        if (Fx(i*1.0) >= 0) pos = true;
        else if(Fx(i*1.0) < 0) neg = true;
        a = i;
        b=i+1;
        i++;
         
       
    }
     printf("root lies between %d and %d\n",a,b);
}


void iteration_method(){

    getting_A_B();

    double X0 = a<b ? a*1.0:b*1.0;
    double prev_xn , current_Xn;
    int Iteration_NO=1;

    while (1)
    {
       current_Xn = Fx_Phi(X0);
       printf("Iterarion No : %d  = %lf\n", Iteration_NO++, current_Xn);
       if( current_Xn- X0 < ACCURACY) break;
        else X0 = current_Xn;
       
    }
    
}

int main()
{
    
    iteration_method();

}