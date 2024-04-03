#include <stdio.h>
#include <stdlib.h>
#include "complex_number.h"


void display_mandelbrot( int width, int height, int max_its)
{

    const float x_start = -3.0f;
    const float x_fin = 1.0f;
    const float y_start = -1.0f;
    const float y_fin = 1.0f;

    double dx = (x_fin - x_start)/(width - 1);
    double dy = (y_fin - y_start)/(height - 1);

    for(int y = 0; y < height; ++y)
    {
        for(int x = 0; x < width; ++x)
        {
            // TODO your code here
            // create complex number z = 0 + 0i
            Complex z = complex_create(0, 0);
            // create complex number c =  x_start+ x*dx + (y_start+y*dy)i
            Complex c = complex_create(x_start + x*dx, y_start + y*dy);
            int iteration = 0;
            // while |z| < 2 and we haven't reach max_its
            
            while(complex_mag(z) < 2 && ++iteration < max_its){
               // apply the rule:  z =  z*z + c
                z = complex_add(complex_multiply(z, z), c);
            }

            // TODO: your code here (modify the code to display the mandelbrot fractal
            if(iteration == max_its){
                printf("\033[34m*\033[0m");
            }else{
                printf("\033[31m-\033[0m");
            }

        }
        printf("\n");
    }
}

int main(void)
{
    display_mandelbrot(100, 25, 100);
    getchar();
    return 0;
}
