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

    Image (unsigned int dimensionX, unsigned int dimensionY);
    /// Précondition : dimx et dimy >= 0
    /// Postcondition : dimx = dimensionX et dimy = dimensionY, 
    ///     allocation d'un tableau 1D (taille = dimX*dimY) 
    ///     de pixels noir (constructeur par défaut de pixel)

    ~Image();
    /// Postcondition : tab désalloué et dimX, dimY = 0


    void testRegression();
    /// Postcondition : série de test du module

    void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel const & couleur);
    /// Precondition : 0 <= Xmin < Xmax < dimx et 0 <= Xmin < Xmax < dimx
    /// Postcondition : dessine un rectangle plein de la couleur passée en parametre
    ///     entre les coordonnées (Xmin, Ymin) et (Xmax, Ymax)


    void effacer(Pixel const & couleur);
    /// Postcondition : dessine un rectangle de la couleur passée
    ///     en parametre de la taille de l'Image



    /// ==== Accesseurs ====
    Pixel getPix(unsigned int x, unsigned int y) const;
    /// Précondition : 0 <= x < dimX, 0 <= y < dimY
    /// Postcondition : retourne le pixel à la position (x, y)

    /// ==== Mutateurs ====
    void setPix (unsigned int x, unsigned int y, Pixel const & couleur);
    /// Précondition : 0 <= x < dimX, 0 <= y < dimY
    /// Postcondition : modifie le pixel à la position (x, y) par le Pixel couleur

};



#endif