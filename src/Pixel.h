#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
private:
    int r, g, b;
public:
    Pixel();
    Pixel(int const nr, int const ng, int const nb);
    ~Pixel();


    int getRouge() const;
    int getVert() const;
    int getBleu() const;

    void setRouge(int const nr);
    void setVert(int const ng);
    void setBleu(int const nb);
};

#endif



