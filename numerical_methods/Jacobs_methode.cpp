#include<stdio.h>

#define ACCURACY 0.00001


double Fx(double y, double z){
//      20x +y -2z = 0
    return (1/20.0)*(17.0 - y+ 2.0*z);
    }


double Fy(double x, double z){
//      3x +20y -z = -18 
    return (1/20.0)*(z - 18.0+ 3.0*x);
    }


double Fz(double x, double y){
//      2x -3y +20z = 25
    return (1/20.0)*(25.0 - 2*x+ 3.0*y);
    }


void jacobi_s_Methode(){
// letting First time;
    double X0 = 0.0, Y0 =0.0, Z0 = 0.0;

    int approx_No =1;
  
    while (1)
    {
        printf("Approx %d:\n",approx_No++);
         double X1 = Fx(Y0, Z0);
         double Y1 = Fy(X0, Z0);
         double Z1 = Fz(X0, Y0);
         printf("\tX%d = %lf\n",approx_No, X1);
         printf("\tY%d = %lf\n",approx_No, Y1);
         printf("\tZ%d = %lf\n",approx_No, Z1);
        if(X0 - X1 < ACCURACY && Y0 - Y1< ACCURACY && Z0 -Z1< ACCURACY)break;
        
        X0 = X1;
        Y0 = Y1;
        Z0 = Z1;
      
    }
}

int main()
{
    jacobi_s_Methode();
}