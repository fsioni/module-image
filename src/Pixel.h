#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
private:
    /// ==== Données membres ==== ///

    unsigned char r, g, b;
    /// r, g, b => [0...255]


public:
    /// ==== Fonctions membres === ///

    Pixel();
    /// Postcondition : r, g, b initialisés à 0 => couleur noire

    Pixel(unsigned char const nr, unsigned char const ng, unsigned char const nb);
    /// Précondition : nr, ng, nb => [0, 255] sinon convertion automatique
    /// Postcondition : r = nr, g = gb, b = nb

    ~Pixel();
    /// Postcondition : objet détruit


    /// ==== Accesseurs ====
    unsigned char getRouge() const;
    /// Postcondition : retourn r

    unsigned char getVert() const;
    /// Postcondition : retourn g

    unsigned char getBleu() const;
    /// Postcondition : retourn b


    /// ==== Mutateurs ====
    void setRouge(unsigned char const nr);
    /// Précondition : nr  => [0, 255] sinon convertion automatique
    /// Postcondition : r = nr

    void setVert(unsigned char const ng);
    /// Précondition : ng  => [0, 255] sinon convertion automatique
    /// Postcondition : g = ng

    void setBleu(unsigned char const nb);
    /// Précondition : nb  => [0, 255] sinon convertion automatique
    /// Postcondition : b = nb
};

#endif



