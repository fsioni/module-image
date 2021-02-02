#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <fstream>
#include "Pixel.h"

using namespace std;

/*! \class Image
*   \brief classe représentant une image
*   
*   La classe représente une image de dimension dimx et dimy. 
*   La couleur de chaque pixel est stocké dans un tableau de type Pixel. 
*/

class Image
{
private:
    /*// ==== Données membres === //*/

    Pixel *tab; /*!< Tableau 1D de Pixel. */

    unsigned int dimx; /*!< Dimension de l'image sur l'axe x (horizontal). */
    unsigned int dimy; /*!< Dimension de l'image sur l'axe y (vertical). */

public:
    /*// ==== Fonctions membres === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *  Créer une Image de dimensions 0 * 0 (image vide).
    */
    Image();

    /*! \brief Constructeur avec dimensions de l'image en paramètre.
    *   \param [in] dimensionX : entier positif, taille de l'image sur l'axe X (horizontal).
    *   \param [in] dimensionY : entier positif, taille de l'image sur l'axe Y (vertical).
    *   
    *   Créer une Image de dimensions (dimensionX , dimensionY) entièrement noir car 
    *   appel du constructeur par défaut de la classe Pixel qui créer un Pixel noir.
    */
    Image (unsigned int dimensionX, unsigned int dimensionY);
   
   /*! \brief Destructeur.
    *
    *  Destructeur de la classe Image.
    */
    ~Image();


    /*! \brief Teste la validité des fonctions de la classe Image.
    *
    *
    *  Effectue différents tests pour vérifier l'intégrité des fonctions de la classe Image. En manipulant différentes
    * instances d'images, en les modifiant, etc..
    */
    void testRegression();

    /*! \brief Dessine un rectangle plein de la couleur dans l'image.
    *
    *   Tous les pixels se trouvant entre les coordonnées données sont remplis de la couleur du Pixel passé en paramètre.
    * 
    *   \param [in] Xmin : entier positif, coordonnée minimum du rectangle sur l'axe X (horizontal). 
    *   \param [in] Ymin : entier positif, coordonnée minimum du rectangle sur l'axe Y (vertical).
    *   \param [in] Xmax : entier positif, coordonnée maximum du rectangle sur l'axe X (horizontal).
    *   \param [in] Ymax : entier positif, coordonnée maximum du rectangle sur l'axe Y (vertical).
    *   \param [in] couleur : Pixel, désigne le couleur du rectangle dessiné.
    */
    void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel const & couleur);


    /*! \brief Efface l'image en la remplissant de la couleur en paramètre
    *   
    *   Tous les pixels de l'image sont remplacés par la couleur du Pixel passé en paramètre.
    * 
    *   \param [in] couleur : Pixel, désigne la couleur avec laquelle sera remplie l'image.
    */
    void effacer(Pixel const & couleur);



    /*// ==== Accesseurs === //*/

    /*! \brief Retourne un l'addresse d'un Pixel.
    * 
    *   Retourne l'addresse d'un Pixel aux coordonnées (x,y) de l'image.
    * 
    *   \param [in] x : entier positif, coordonnée sur l'axe X (horizontal) du Pixel souhaité.
    *   \param [in] y : entier positif, coordonnée sur l'axe Y (vertical) du Pixel souhaité.
    */
    Pixel& getPix(unsigned int x, unsigned int y) const;

    /*// ==== Mutateurs === //*/

    /*! \brief Modifie un Pixel.
    * 
    *   Modifie la couleur du Pixel aux coordonnées (x,y) par celle passée en paramètre.
    * 
    *   \param [in] x : entier positif, coordonnée sur l'axe X (horizontal) du Pixel à modifier.
    *   \param [in] y : entier positif, coordonnée sur l'axe Y (vertical) du Pixel à modifier.
    *   \param [in] couleur : Pixel, couleur qui va être assigné au Pixel au coordonnée (x, y).
    */
    void setPix (unsigned int x, unsigned int y, Pixel const & couleur);

    /*! \brief Sauvegarde l'image dans un fichier. 
    *
    *  Possibilité de mettre un nom de fichier pour s'enregister dans le répertoire courant ou de mettre un chemin,
    *  relatif ou absolu. L'image est enregisté sous un format .pmm, pouvant s'ouvrir avec la fonction ouvrir().
    * 
    *   \param [in] filename : chaine de charactères (string), nom et chemin du fichier dans lequel on veut sauvegarder l'image.
    */
    void sauver(const string & filename) const;

    /*! \brief Ouvre l'image .pmm sous le nom/chemin 'filename'
    *
    *   Ouvre l'image dans le nom et chemin est passé en paramètre.
    * 
    *   \param [in] filename : chaine de charactères (string), nom et chemin du fichier de l'image à ouvrir.
    */
    void ouvrir(const string & filename);

    /*! \brief Affichage console de l'image.
    *
    *  La console affiche l'image en indiquant tous les pixels sous la forme r g b. Exemple 0 255 40.
    */
    void afficherConsole();

    /*! \brief Affichage dans une fenêtre graphique.
    *
    *   Affichage de l'image dans une fenêtre graphique avec SDL2.
    */
    void afficher();


};



#endif
