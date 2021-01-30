#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <fstream> 
#include "Pixel.h"

using namespace std;


class Image
{
private:
    /*// ==== Données membres === //*/

    Pixel *tab;//!< Tableau 1D de pixels

    unsigned int dimx;//!< Dimension x de l'image
    unsigned int dimy;//!< Dimension y de l'image

public:
    /*// ==== Fonctions membres === //*/

    /*! \brief Créer une image vide.
    *
    *
    *  Créer une image de dimensions 0x0 sans pixel
    */
    Image();

    /*! \brief Créer une image noire de dimension XxY
    *
    *
    */
    Image (unsigned int dimensionX, unsigned int dimensionY);
   
   /*! \brief Supprime l'image
    *
    *
    */
    ~Image();


    /*! \brief Teste la validité des fonctions de la classe Image
    *
    *
    *  Effectue différents tests pour vérifier l'intégrité des fonctions de la classe Image. En manipulant différentes
    * instances d'images, en les modifiant, etc..
    */
    void testRegression();

    /*! \brief Dessine un rectangle plein de la couleur dans l'image.
    *
    *
    *  Tous les pixels se trouvant entre les coordonnées sont remplis de la couleur.
    */
    void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel const & couleur);


    /*! \brief Efface l'image en la remplissant de la couleur en paramètre
    *
    *
    *  Tous les pixels de l'image sont remplacés par la couleur
    */
    void effacer(Pixel const & couleur);



    /*// ==== Accesseurs === //*/

    /*! \brief Récupère le pixel original aux coordonnées (x,y) de l'image.
    *
    *
    */
    Pixel& getPix(unsigned int x, unsigned int y) const;

    /*// ==== Mutateurs === //*/

    /*! \brief Remplace le pixel aux coordonnées (x,y) par la couleur.
    *
    *
    */
    void setPix (unsigned int x, unsigned int y, Pixel const & couleur);

    /*! \brief Sauvegarde l'image dans le fichier 'filename'
    *
    *
    *  Possibilité de mettre un nom de fichier pour s'enregister dans le répertoire courant ou de mettre un chemin,
    *  relatif ou absolu. L'image est enregisté sous un format .pmm, pouvant s'ouvrir avec la fonction ouvrir().
    */
    void sauver(const string & filename) const;

    /*! \brief Ouvre l'image .pmm sous le nom/chemin 'filename'
    *
    *
    *  L'image sur laquelle la fonction est appellée devient celle ouverte.
    */
    void ouvrir(const string & filename);

    /*! \brief L'image est affiché dans la console.
    *
    *
    *  La console affiche l'image en indiquant tous les pixels sous la forme r g b. Exemple 0 255 40
    */
    void afficherConsole();

    /*! \brief L'image est affiché dans une fenêtre SDL2.
    *
    *
    */
    void afficher();


};



#endif