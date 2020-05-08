#include<graphics.h>
#include<time.h>

int main()
{
    int gd=DETECT;
    int gm;

    initgraph(&gd,&gm,"C:\\TC\\BGI");
    int i, color=11;
    while(1)
    {



        struct tm *currentTime;
        time_t rawtime;
        char a[100];

        rawtime=time(NULL);
        currentTime=localtime(&rawtime);

        strftime(a,100,"%I:%M:%S",currentTime);


        setcolor(color);
        settextstyle(3,HORIZ_DIR,8);
        outtextxy(200,100,a);

        strftime(a,100,"%p",currentTime);
        settextstyle(3,HORIZ_DIR,4);
        outtextxy(436,90,a);

        strftime(a,100,"%a, %d %b, %Y",currentTime);
        settextstyle(3,HORIZ_DIR,2);
        outtextxy(230,210,a);


        delay(100);


    }

    getch();
    closegraph();
    return 0;
}
