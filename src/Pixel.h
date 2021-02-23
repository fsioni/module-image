#ifndef PIXEL_H
#define PIXEL_H


/*! \class Pixel
*   \brief Classe représentant un Pixel.
*   
*  La classe représente un pixel, un composant prennant des composants 
*  r, g et b prennant valeur entre 0 et 255.
*/
class Pixel
{
private:
    /*// ==== Données membres privées === //*/

    unsigned char r; /*! \brief Quantité de rouge comprise entre 0 et 255. */
    unsigned char g; /*! \brief Quantité de vert comprise entre 0 et 255. */
    unsigned char b; /*! \brief Quantité de bleu comprise entre 0 et 255. */


public:
    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Constructeur par défaut.
    *
    *
    *  Initialise un pixel avec une couleur noir, r, g et b valent 0.
    */
    Pixel();

    /*! \brief Constructeur avec choix de la couleur.
    *
    *   Initialise un pixel avec comme valeur r = nr, g = ng et b = nb.
    *   
    *   \param [in] nr : valeur comprise entre 0 et 255 assigné à r.
    *   \param [in] ng : valeur comprise entre 0 et 255 assigné à g.
    *   \param [in] nb : valeur comprise entre 0 et 255 assigné à b.
    */
    Pixel(unsigned char const nr, unsigned char const ng, unsigned char const nb);

    /*! \brief Destructeur
    *   
    *   Le pixel est détruit.
    */
    ~Pixel();


    /*// ==== Accesseurs === //*/

    /*! \brief Retourne r.
    *   
    *   Retourne la quantité r comprise entre 0 et 255 de rouge du pixel.
    */
    unsigned char getRouge() const;

    /*! \brief Retourne g.
    *   
    *   Retourne la quantité g comprise entre 0 et 255 de vert du pixel.
    */
    unsigned char getVert() const;

    /*! \brief Retourne b.
    *   
    *   Retourne la quantité b comprise entre 0 et 255 de bleu du pixel.
    */
    unsigned char getBleu() const;


    /*// ==== Mutateurs === //*/

    /*! \brief Mutateur de r.
    *   
    *   Modifie la valeur de r, quantité de rouge du Pixel,
    *   en faisant les vérifications nécessaires.
    * 
    *   \param [in] nr : Nouvelle valeur assigné à r.
    */
    void setRouge(unsigned char const nr);

    /*! \brief Mutateur de g.
    *   
    *   Modifie la valeur de g, quantité de vert du Pixel,
    *   en faisant les vérifications nécessaires.
    * 
    *   \param [in] ng : Nouvelle valeur assigné à r.
    */
    void setVert(unsigned char const ng);

    /*! \brief Mutateur de b.
    *   
    *   Modifie la valeur de b, quantité de bleu du Pixel,
    *   en faisant les vérifications nécessaires.
    * 
    *   \param [in] nb : Nouvelle valeur assigné à b.
    */
    void setBleu(unsigned char const nb);
};

#endif



