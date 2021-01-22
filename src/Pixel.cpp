#include "Pixel.h"
#include <cassert>

Pixel::Pixel() : r(0), g(0), b(0){}

Pixel::Pixel(unsigned char const nr, unsigned char const ng, unsigned char const nb){
    assert(nr >= 0 && nr <= 255);
    assert(ng >= 0 && ng <= 255);
    assert(nb >= 0 && nb <= 255);
    r = nr;
    g = ng;
    b = nb;
}

Pixel::~Pixel(){}

unsigned char Pixel::getRouge() const{return r;}

unsigned char Pixel::getVert() const{return g;}

unsigned char Pixel::getBleu() const{return b;}

void Pixel::setRouge(unsigned char const nr){    
    assert(nr >= 0 && nr <= 255);
    r = nr;
    }

void Pixel::setVert(unsigned char const ng){
    assert(ng >= 0 && ng <= 255);
    g = ng;
}

void Pixel::setBleu(unsigned char const nb){
    assert(nb >= 0 && nb <= 255);
    b = nb;
    }