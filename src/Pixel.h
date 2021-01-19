#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
private:
    unsigned char r, g, b;
public:
    Pixel();
    Pixel(unsigned char const nr, unsigned char const ng, unsigned char const nb);
    ~Pixel();


    unsigned char getRouge() const;
    unsigned char getVert() const;
    unsigned char getBleu() const;

    void setRouge(unsigned char const nr);
    void setVert(unsigned char const ng);
    void setBleu(unsigned char const nb);
};

#endif



