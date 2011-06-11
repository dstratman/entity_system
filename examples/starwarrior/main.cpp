 #include "SDL/SDL.h"
 
int main( int argc, char* argv[])
{
   // Fire up SDL, this starts all subsystems; audio video etc.
   SDL_Init(SDL_INIT_EVERYTHING);

   SDL_Surface *screen;
   screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

   if ( screen == NULL )
   {
      printf("Unable to set 640x480 video: %s\n", SDL_GetError());
      return 1;
   }

   // Now Shut it down
   SDL_Quit();
   return 0;
}
