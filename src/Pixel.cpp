#include "Pixel.h"

Pixel::Pixel(){
    r = 0;
    g = 0;
    b = 0;
}

Pixel::Pixel(int const nr, int const ng, int const nb){
    r = nr;
    g = ng;
    b = nb;
}

Pixel::~Pixel(){}

int Pixel::getRouge() const{return r;}

int Pixel::getVert() const{return g;}

int Pixel::getBleu() const{return b;}

void Pixel::setRouge(int const nr){r = nr;}

void Pixel::setVert(int const ng){g = ng;}

void Pixel::setBleu(int const nb){b = nb;}