#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

//Gameplay Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* args[] )
{
    //The window rendering to
    SDL_Window* window = NULL;

    //Surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initializing SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Creating window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Getting window surfaces
            screenSurface = SDL_GetWindowSurface( window );

            //Filling the surface with white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //Updating the surface
            SDL_UpdateWindowSurface( window );

            //A trick to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    //Destroying window
    SDL_DestroyWindow( window );

    //Quitting SDL subsystems
    SDL_Quit();

    return 0;
}
