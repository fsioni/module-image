#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"

class Image
{
private:
    Pixel *tab;
    int dimx, dimy;
public:
    Image();
    Image (int const dimensionX, int const dimensionY);

    ~Image();

    Pixel getPix(int const x, int const y);

    void setPix (int const x,int const y, Pixel const couleur);
};

// Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
   void dessinerRectangle (int const Xmin, int const Ymin, int const Xmax, int const Ymax, Pixel const couleur);

   // Efface l'image en la remplissant de la couleur en paramètre
   // (en appelant dessinerRectangle avec le bon rectangle)
   void effacer(Pixel const couleur);

   // Effectue une série de tests vérifiant que le module fonctionne et
   // que les données membres de l'objet sont conformes
   void testRegression ();

#endif