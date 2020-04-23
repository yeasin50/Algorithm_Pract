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


double F_invX(double x){
    return 3 + sinf(x);
}

int a, b, step=0 ;

void getting_A_B(){

    bool done = false;
    bool pos = false;
    bool neg = false;

    int i=1;

    while (done!=true)
    {
        if (Fx(i*1.0) >= 0) pos = true;
        if (Fx(i*1.0) < 0) neg = true;
        a = i;

        if((pos && Fx((i+1)*1.0 < 0)) || (neg && Fx((i+1)*1.0 >=0)))
           done = true;

        b=i+1;
        i++;
       
    }
}


double get_Xn_1(double xn){
    
    return xn  - (Fx(xn)/ F_invX(xn));
}
void newtonRaphsa(){

    getting_A_B();

    double C_XN ,prev_Xn;
     int step=1;
    prev_Xn = get_Xn_1(a*1.0);

    int iteraton=1;

    while (1)
    {
         C_XN = get_Xn_1(prev_Xn);
         printf( "Iteration %d: Xn = %lf \n",iteraton++, prev_Xn );
         if(prev_Xn - C_XN < ACCURACY)break;
         printf( "Iteration %d: Xn = %lf \n",iteraton++, C_XN );
         prev_Xn = C_XN;
         step++;

    }
    
    
    
}


int main()
{
    printf("%lf\n", Fx(1.0));
    newtonRaphsa();
}