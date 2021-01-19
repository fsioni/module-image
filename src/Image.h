#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"

class Image
{
private:
    /// ==== Données membres ==== ///

    Pixel *tab;
    /// tab : tableau 1D de pixel

    unsigned int dimx, dimy;
    /// 
public:
    /// ==== Fonctions membres === ///

    Image();
    /// Postcondition : dimx et dimy = 0, tab n'est pas alloué

    Image (unsigned int const dimensionX, unsigned int const dimensionY);
    /// Précondition : dimx et dimy >= 0
    /// Postcondition : dimx = dimensionX et dimy = dimensionY, 
    ///     allocation d'un tableau 1D (taille = dimX*dimY) 
    ///     de pixels noir (constructeur par défaut de pixel)

    ~Image();
    /// Postcondition : tab désalloué et dimX, dimY = 0

    /// ==== Accesseurs ====
    Pixel getPix(unsigned int const x, unsigned int const y);
    /// Précondition : 0 <= x < dimX, 0 <= y < dimY
    /// Postcondition : retourne le pixel à la position (x, y)

    /// ==== Mutateurs ====
    void setPix (unsigned int const x, unsigned int const y, Pixel const couleur);
    /// Précondition : 0 <= x < dimX, 0 <= y < dimY
    /// Postcondition : modifie le pixel à la position (x, y) par le Pixel couleur
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