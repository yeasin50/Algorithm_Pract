#include<bits/stdc++.h>

#define ACCURACY 0.0001

double Fx(double y, double z){
//      20x +y -2z = 0
    return (1/20.0)*(17.0 - y+ 2.0*z);
    }


double Fy(double x, double z){
//      3x +20y -z = -18 
    return (1/20.0)*(- 18.0- 3.0*x +z);
    }


double Fz(double x, double y){
//      2x -3y +20z = 25
    return (1/20.0)*(25.0 - 2*x+ 3.0*y);
    }


void Gauss_method(){
    
// First Approx, Let
    int Approx_no =1;
    double X0 = 0.0, Y0 =0.0, Z0 = 0.0;

    while (1)
    {
        
        double X1 = Fx(Y0, Z0);
        
        double Y1 = Fy(X1, Z0);
        double Z1 = Fz(X1, Y1);

        printf("Approx No: %d\n", Approx_no);
        printf("\t X%d = %lf\n",Approx_no, X1);
        printf("\t Y%d = %lf\n",Approx_no, Y1);
        printf("\t Z%d = %lf\n",Approx_no++, Z1);

        if(X0 - X1 < ACCURACY && Y0 - Y1< ACCURACY && Z0 -Z1< ACCURACY)break;
        X0 = X1;
        Y0 = Y1;
        Z0 = Z1;
        
    }
    

}


int main()
{
    Gauss_method();
}