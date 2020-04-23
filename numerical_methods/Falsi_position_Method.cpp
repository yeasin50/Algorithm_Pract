#include<stdio.h>
#include<math.h>

#define ACCURACY 0.0000001

double Fx(double x){

    return x*x*x - 9.0*x +1;
}


int a, b, step=0 ;


void getting_A_B(){

    bool done = false;
    bool pos = false;
    bool neg = false;


    int i=0;

    while (done!=true)
    {
        if((Fx(i*1.0) < 0)){
            if(Fx(i+1.0) >=0) done= true;

        }
        printf("F(%d) = %lf \n",i,Fx(i));
        i++;
    }
    printf("F(%d) = %lf \n",i,Fx(i));

    a=i-1, b=i;
     printf("\nroot lies between %d and %d\n\n",a,b);
}

double get_X3 (double x1, double x2){

    return x1 - (Fx(x1) * (x2- x1))/ (Fx(x2) - Fx(x1));
}

void falsi_poss()
{
    getting_A_B();

    double X0 = a*1.0;
    double X1 = b*1.0 ;
    double prev_Xn, current_Xn1;

    int irritation_NO=1;
    while (1){
        current_Xn1 = get_X3(X0, X1);
        double F_x3 = Fx(current_Xn1);

        if(current_Xn1 -prev_Xn <ACCURACY)break;
        if(F_x3 <0)
            X0 =current_Xn1;
        else
            X1 = current_Xn1;

        printf("Irretation %d: \t  X(%.2lf) = %lf\n",irritation_NO++, X0, current_Xn1);

        prev_Xn = current_Xn1;

    }

}

int main()
{
  // getting_A_B();
   falsi_poss();
}
