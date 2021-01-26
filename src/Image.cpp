#include "Image.h"
#include <assert.h> 
#include <iostream>

using namespace std;

Image::Image(){
    dimx = 0;
    dimy = 0;
}

Image::Image(int dimensionX, int dimensionY){
    assert(dimensionX > 0 && dimensionY > 0);
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimx*dimy];
}

Image::~Image(){
    delete[] tab;
    dimx = 0;
    dimy = 0;
}

Pixel Image::getPix(int x, int y) const{
    assert(x >= 0 && y >= 0);
    assert (x<dimx && y<dimy);
    return tab[y*dimx+x];
}

void Image::setPix(int x, int y, Pixel const & couleur){
    assert(x >= 0 && y >= 0);
    assert(x<dimx && y<dimy);
    tab[y*dimx+x] = couleur;
}


void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, Pixel const & couleur){
    assert(Xmin >= 0 && Ymin >= 0);
    assert(Xmin<=Xmax && Ymin<=Ymax);
    assert(Xmax<dimx && Ymax<dimy);
    for(unsigned int i=Xmin; i<=Xmax; i++)
        for(unsigned int j=Ymin; j<=Ymax; j++)
            setPix(i, j, couleur);
}


void Image::effacer(Pixel const & couleur){
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression(){
    for(unsigned int i=0; i<dimx; i++){
        for(unsigned int j=0; j<dimy; j++)
            cout << "(" << (int)getPix(i, j).getRouge() << " ," <<  (int)getPix(i, j).getVert() << " ," << (int)getPix(i, j).getBleu() << ")" << " "; 
        cout << endl;
    }
    cout << endl;     

}
