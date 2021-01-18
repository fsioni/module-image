#include "Image.h"
#include <assert.h> 

Image::Image(){
    dimx = 0;
    dimy = 0;
}

Image::Image(int const dimensionX, int const dimensionY){
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimx*dimy];
}

Image::~Image(){
    delete[] tab;
    dimx = 0;
    dimy = 0;
}

Pixel Image::getPix(int const x, int const y){
    assert (x<dimx && y<dimy);
        return tab[y*dimx+x];
}

void Image::setPix(int const x,int const y, Pixel const couleur){
    tab[y*dimx+x] = couleur;
}