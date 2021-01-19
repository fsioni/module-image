#include "Image.h"
#include <assert.h> 

Image::Image(){
    dimx = 0;
    dimy = 0;
}

Image::Image(unsigned int const dimensionX, unsigned int const dimensionY){
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimx*dimy];
}

Image::~Image(){
    delete[] tab;
    dimx = 0;
    dimy = 0;
}

Pixel Image::getPix(unsigned int const x, unsigned int const y){
    assert (x<dimx && y<dimy);
        return tab[y*dimx+x];
}

void Image::setPix(unsigned int const x, unsigned int const y, Pixel const couleur){
    tab[y*dimx+x] = couleur;
}