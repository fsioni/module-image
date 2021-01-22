#include "Image.h"
#include <assert.h> 
#include <iostream>

using namespace std;

Image::Image(){
    dimx = 0;
    dimy = 0;
}

Image::Image(unsigned int dimensionX, unsigned int dimensionY){
    assert(dimensionX > 0);
    assert(dimensionY > 0);
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimx*dimy];
}

Image::~Image(){
    delete[] tab;
    dimx = 0;
    dimy = 0;
}

Pixel& Image::getPix(unsigned int x, unsigned int y) const{
    assert (x<dimx && y<dimy);
    return tab[y*dimx+x];
}

void Image::setPix(unsigned int x, unsigned int y, Pixel const & couleur){
    assert(x<=dimx && y<=dimy);
    tab[y*dimx+x] = couleur;
}


void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel const & couleur){
    assert(Xmin<=Xmax && Ymin<=Ymax);
    assert(Xmin <= dimx && Xmax <= dimx);

    assert(Xmax<=dimx && Ymax<=dimy);
    assert(Ymin <= dimy && Ymax <= dimy);

    for(unsigned int i=Xmin; i<=Xmax; i++)
        for(unsigned int j=Ymin; j<=Ymax; j++)
            setPix(i, j, couleur);
}


void Image::effacer(Pixel const & couleur){
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression(){
    Pixel p(255, 0, 0);
    Pixel x(0, 0, 255);
    Pixel n(0, 255, 0);

    cout << "Premiere image" << endl;
    for(unsigned int i=0; i<dimx; i++){
        for(unsigned int j=0; j<dimy; j++){            
            setPix(i, j, p); //test setPix()

            cout << "(" << (int)getPix(i, j).getRouge() << " ," <<  (int)getPix(i, j).getVert() << " ," << (int)getPix(i, j).getBleu() << ")" << " " << endl; //test getPix()            
            }
    }

    dessinerRectangle(0, 0, dimx, dimy, x); // test dessiner Rectangle
    cout << "Nouvelle image" << endl;
    for(unsigned int i=0; i<dimx; i++){
        for(unsigned int j=0; j<dimy; j++){    
            cout << "(" << (int)getPix(i, j).getRouge() << " ," <<  (int)getPix(i, j).getVert() << " ," << (int)getPix(i, j).getBleu() << ")" << " " << endl; //test getPix()            
            }
    }

    effacer(n);
    cout << "Nouvelle image" << endl;
    for(unsigned int i=0; i<dimx; i++){
        for(unsigned int j=0; j<dimy; j++){    
            cout << "(" << (int)getPix(i, j).getRouge() << " ," <<  (int)getPix(i, j).getVert() << " ," << (int)getPix(i, j).getBleu() << ")" << " " << endl; //test getPix()            
            }
    }

    cout << endl;     

}