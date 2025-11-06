#include <stdio.h>
#include <SDL2/SDL.h>

#define height 1000
#define width 1000

//SDL initialization
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void plot(int centerX,int centerY,int x, int y);
void graphLines();

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width,height,0,&window,&renderer);
    // SDL_RenderSetScale(renderer,4,4);

    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,255,255,255,255); //White colored pixel

    graphLines();//draw lines

    //circle properties
    int radius = 300;
    int x=0;
    int y=radius;
    int d= 3- 2*radius;

    //for offset (center of window)
    int centerX = 500;
    int centerY = 500;

    int step =1;

    plot(centerX,centerY,x,y);
    for (;x<=y;x++,step++)
    {
        if (d<0) d=d+4*x+6;
        else y--,d=d+4*(x-y)+10;
        plot(centerX,centerY,x,y);
        printf("Plotting Step: %d\n",step);
    }

    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


//plotting graph
void plot(int centerX,int centerY,int x, int y)
{
    SDL_RenderDrawPoint(renderer,x+centerX,y+centerY);
    SDL_RenderDrawPoint(renderer,y+centerX,x+centerY);
    SDL_RenderDrawPoint(renderer,-x+centerX,-y+centerY);
    SDL_RenderDrawPoint(renderer,-y+centerX,-x+centerY);
    SDL_RenderDrawPoint(renderer,x+centerX,-y+centerY);
    SDL_RenderDrawPoint(renderer,-y+centerX,x+centerY);
    SDL_RenderDrawPoint(renderer,-x+centerX,y+centerY);
    SDL_RenderDrawPoint(renderer,y+centerX,-x+centerY);
    SDL_RenderPresent(renderer);

    // SDL_Event e; //Empty system event queue
    // while (SDL_PollEvent(&e)) {
    //     if (e.type == SDL_QUIT) {
    //         SDL_Quit();
    //         // return;
    //     }
    // }

    SDL_Delay(10);
}

void graphLines()
{
    for (int x=0;x<width;x++) SDL_RenderDrawPoint(renderer,x,height/2);     //Horizontal line
    for (int y=0;y<height;y++) SDL_RenderDrawPoint(renderer,width/2,y);     //Vertical line
    printf("Drawn Lines!\n");
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
}