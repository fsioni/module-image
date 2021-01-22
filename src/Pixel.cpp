#include "Pixel.h"

Pixel::Pixel(){
    r = 0;
    g = 0;
    b = 0;
}

Pixel::Pixel(unsigned char const nr, unsigned char const ng, unsigned char const nb){
    r = nr;
    g = ng;
    b = nb;
}

Pixel::~Pixel(){}

unsigned char Pixel::getRouge() const{return r;}

unsigned char Pixel::getVert() const{return g;}

unsigned char Pixel::getBleu() const{return b;}

void Pixel::setRouge(unsigned char const nr){r = nr;}

void Pixel::setVert(unsigned char const ng){g = ng;}

void Pixel::setBleu(unsigned char const nb){b = nb;}