#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
private:
    /*// ==== Données membres privées === //*/

    unsigned char r;//!< Quantité de couleur rouge du pixel => [0...255]
    unsigned char g;//!< Quantité de couleur verte du pixel => [0...255]
    unsigned char b;//!< Quantité de couleur bleue du pixel => [0...255]


public:
    /*// ==== Fonctions membres publiques === //*/

    /*! \brief Créer un pixel de couleur noir
    *
    *
    *  Un pixel est intialisé avec une quantité de rouge, vert et bleu à 0
    */
    Pixel();

    /*! \brief Créer un pixel avec la quantité de rouge, vert et bleu désiré
    *
    *
    *  nr, ng, nb => [0, 255] sinon conversion automatique.
    * La quantité de rouge du pixel devient : nr, de vert : ng et de bleu : nb.
    */
    Pixel(unsigned char const nr, unsigned char const ng, unsigned char const nb);

    /*! \brief Le pixel est détruit
    *
    */
    ~Pixel();


    /*// ==== Accesseurs === //*/

    /*! \brief Retourne une valeur entre 0 et 255, correspondant à la quantité de rouge du pixel
    *
    * 
    */
    unsigned char getRouge() const;

    /*! \brief Retourne une valeur entre 0 et 255, correspondant à la quantité de vert du pixel
    *
    * 
    */
    unsigned char getVert() const;

    /*! \brief Retourne une valeur entre 0 et 255, correspondant à la quantité de bleu du pixel
    *
    * 
    */
    unsigned char getBleu() const;


    /*// ==== Mutateurs === //*/

    /*! \brief Modifie la quantité de rouge du pixel. nr doit être entre 0 et 255.
    *
    * 
    */
    void setRouge(unsigned char const nr);

    /*! \brief Modifie la quantité de vert du pixel. ng doit être entre 0 et 255.
    *
    * 
    */
    void setVert(unsigned char const ng);

     /*! \brief Modifie la quantité de bleu du pixel. nb doit être entre 0 et 255.
    *
    * 
    */
    void setBleu(unsigned char const nb);
};

#endif



