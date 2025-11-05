#include <stdio.h>

#define height 300
#define width 300

int image[height][width];

void plot(int centerX,int centerY,int x, int y)
{
    image[x+centerX][y+centerY] = 1;
    image[y+centerX][x+centerY] = 1;
    image[-x+centerX][-y+centerY] = 1;
    image[-y+centerX][-x+centerY] = 1;
    image[x+centerX][-y+centerY] = 1;
    image[-y+centerX][x+centerY] = 1;
    image[-x+centerX][y+centerY] = 1;
    image[y+centerX][-x+centerY] = 1;
}

void drawStep(int stepNo)
{
    char fileName[50];
    sprintf(fileName,"steps/step_%d.ppm",stepNo);
    FILE *f = fopen(fileName,"w");
    fprintf(f,"P3\n%d %d\n255\n",width,height);
    for (int i=0;i<height;i++) //catches row
    {
        for (int j=0; j<width;j++) //catches column
        {

            if (image[i][j]==1) fprintf(f,"%d %d %d ",255,0,0); //our circle
            else if (j == height/2 || i == width/2)fprintf(f, "%d %d %d ", 0, 0, 0); //graphing lines
            else fprintf(f,"%d %d %d ",255,255,255); //white space
        }
        fprintf(f,"\n");
    }

}

int main()
{
    int radius = 50;
    int x=0;
    int y=radius;
    int d= 3- 2*radius;
    int centerX = 150;
    int centerY = 150;
    int step =1;

    plot(centerX,centerY,x,y);
    drawStep(step);
    for (;x<=y;x++,step++)
    {
        if (d<0) d=d+4*x+6;
        else y--,d=d+4*(x-y)+10;
        plot(centerX,centerY,x,y);
        drawStep(step);
    }

    FILE *f = fopen("output.ppm","w");

    fprintf(f,"P3\n%d %d\n255\n",width,height);
    for (int i=0;i<height;i++) //catches row
    {
        for (int j=0; j<width;j++) //catches column
        {

            if (image[i][j]==1) fprintf(f,"%d %d %d ",255,0,0); //our circle
            else if (j == height/2 || i == width/2)fprintf(f, "%d %d %d ", 0, 0, 0); //graphing lines
            else fprintf(f,"%d %d %d ",255,255,255); //white space
        }
        fprintf(f,"\n");
    }
    fclose(f);
}