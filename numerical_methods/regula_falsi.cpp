#include<stdio.h>
#include<math.h>

#define PI 3.1415926535897932384626433832795
#define ACCURACY 0.0001

double Fx(double x){
    if(x ==0)
        return x*exp(x) - cosf((180/PI));
    else
    return x*exp(x) - cosf(x*(180/PI));
}

int a, b, step=0 ;

void getting_A_B(){

    bool done = false;
    bool pos = false;
    bool neg = false;

    int i=0;

    while (done!=true)
    {
       
        if (Fx(i*1.0) >= 0) pos = true;
        if (Fx(i*1.0) < 0) neg = true;
         if((pos && Fx((i+1)*1.0 < 0)) || (neg && Fx((i+1)*1.0 >=0)))
           done = true;
           
        a = i;
        b=i+1;
        i++;
       
    }
}


double get_X2(double x, double y){

    return x - ((y-x) / (Fx(y) - Fx(x))) * Fx(x);
}

void  regula_falsi(){
    getting_A_B();

    double X0 = a<b ? a*1.0:b*1.0;
    double X1 = b>a ? b*1.0:a*1.0;
 

    while (1)
    {
        double X2 =get_X2(X0,X1);
        double F_X2 = Fx(X2);

        printf(" X0= %lf \t X1= %lf\n",X0,X1);
        if(X1 - X0 < ACCURACY) break;
        if(F_X2 < 0 && Fx(X0) <0)  X0 = X2;
        else X1 = X2;

    }
    
    

} 



int main(){
   regula_falsi();
   printf("root lies between %d and %d\n",a,b);
   
}