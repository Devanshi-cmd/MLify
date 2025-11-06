#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define height 1000
#define width 1000


void plot(int centerX,int centerY,int x, int y);
void graphLines();

int main()
{

    //initialize glfw
    if (!glfwInit())
    {
        printf("Failed to initialize GLFW!\n");
        return -1;
    }

    //create Window
    GLFWwindow* window = glfwCreateWindow(width,height,"CIRCLE using openGL",NULL,NULL);
    if (!window)
    {
        printf("Failed to create Window!\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); //select our window

    //setting up viewport and co-ordinate system
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,width,0,height,-1,0);
    glMatrixMode(GL_MODELVIEW);

    //clear
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    graphLines();//draw lines

    //circle in white
    glColor3f(1.0f,1.0f,1.0f);

    //circle properties
    int radius = 300;
    int x=0;
    int y=radius;
    int d= 3- 2*radius;

    //for offset (center of window)
    int centerX = 500;
    int centerY = 500;

    int step =1;

    glBegin(GL_POINTS); //start drawing batch

    plot(centerX,centerY,x,y);
    for (;x<=y;x++,step++)
    {
        if (d<0) d=d+4*x+6;
        else y--,d=d+4*(x-y)+10;
        plot(centerX,centerY,x,y);
        printf("Plotting Step: %d\n",step);
    }
    glEnd(); //end drawing batch

    glfwSwapBuffers(window); //flip buffer to draw everything

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


//plotting graph
void plot(int centerX,int centerY,int x, int y)
{
    glVertex2i(x+centerX,y+centerY);
    glVertex2i(y+centerX,x+centerY);
    glVertex2i(-x+centerX,-y+centerY);
    glVertex2i(-y+centerX,-x+centerY);
    glVertex2i(x+centerX,-y+centerY);
    glVertex2i(-y+centerX,x+centerY);
    glVertex2i(-x+centerX,y+centerY);
    glVertex2i(y+centerX,-x+centerY);
}

void graphLines()
{
    glColor3f(0.0f,1.0f,0.0f); //green

    glBegin(GL_POINTS);
    for (int x=0;x<width;x++) glVertex2i(x,height/2);     //Horizontal line
    glEnd();

    glBegin(GL_POINTS);
    for (int y=0;y<height;y++) glVertex2i(width/2,y);     //Vertical line
    glEnd();

    printf("Drawn Lines!\n");
}