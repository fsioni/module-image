#include "Image.h"
#include <assert.h> 
#include <iostream>

using namespace std;

Image::Image(){
    dimx = 0;
    dimy = 0;
    tab = nullptr;
}

Image::Image(unsigned int dimensionX, unsigned int dimensionY){
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimx*dimy];
}

Image::~Image(){
    delete[] tab;
    dimx = 0;
    dimy = 0;
}

Pixel& Image::getPix(unsigned int x, unsigned int y) const{
    assert (x<dimx && y<dimy);
    return tab[y*dimx+x];
}

void Image::setPix(unsigned int x, unsigned int y, const Pixel& couleur){
    assert(x<dimx && y<dimy);
    tab[y*dimx+x] = couleur;
}


void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, 
unsigned int Xmax, unsigned int Ymax, const Pixel& couleur){
 
    assert(Xmin < Xmax && Ymin < Ymax && 
           Xmax < dimx && Ymax < dimy );

    for(unsigned int i=Xmin; i<=Xmax; i++)
        for(unsigned int j=Ymin; j<=Ymax; j++)
            setPix(i, j, couleur);
}


void Image::effacer(Pixel const & couleur){
    dessinerRectangle(0, 0, dimx-1, dimy-1, couleur);
}

void Image::testRegression(){
    Pixel rouge(255, 0, 0);
    Pixel bleu(0, 0, 255);

    int dimx_ = 10, dimy_ = 10;
    Image im(dimx_, dimy_);
    Image im2(dimx_, dimy_);

    // test si l'image initialisé est bien toute noire
    for(unsigned int i = 0; i < dimx_ ; i++)
        for(unsigned int j = 0; j < dimy_ ; j++){
            Pixel p = im.getPix(i, j);
            assert(p.getRouge() == p.getVert() == p.getBleu() == 0);
        }

    // test du mutateur de Pixel
    im.setPix(0, 0, bleu);
    Pixel p = im.getPix(0, 0);
    assert(p.getRouge() == bleu.getRouge() &&
           p.getVert() == bleu.getVert() && 
           p.getBleu() == bleu.getBleu());
    
    // test si l'image à bien été effacer et remplacer avec la bonne couleur
    im.effacer(rouge);
    for(unsigned int i = 0; i < dimx_ ; i++)
        for(unsigned int j = 0; j < dimy_ ; j++){
            Pixel p = im.getPix(i, j);
            assert(p.getRouge() == rouge.getRouge() &&
                   p.getVert() == rouge.getVert() && 
                   p.getBleu() == rouge.getBleu());
        }

    // test de la fonction dessinerRectangle
    int xmin = 0, ymin = 0, xmax = 4, ymax = 4;
    im.dessinerRectangle(xmin, ymin, xmax, ymax, bleu);

    for(unsigned int i = 0; i < dimx_ ; i++)
        for(unsigned int j = 0; j < dimy_ ; j++){
            Pixel p = im.getPix(i, j);
            if(i >= xmin && i <= xmax && j >= ymin && j <= ymax)
                assert(p.getRouge() == bleu.getRouge() &&
                       p.getVert() == bleu.getVert() && 
                       p.getBleu() == bleu.getBleu());
            else
                assert(p.getRouge() == rouge.getRouge() &&
                       p.getVert() == rouge.getVert() && 
                       p.getBleu() == rouge.getBleu());
        }

    // test de sauver et ouvrir
    string filename("./data/testRegression.ppm");
    im.sauver(filename);
    im2.ouvrir(filename);

    for(unsigned int i = 0; i < dimx_ ; i++)
        for(unsigned int j = 0; j < dimy_ ; j++){
            Pixel p = im.getPix(i, j);
            Pixel p2 = im2.getPix(i, j);
            assert(p.getRouge() == p2.getRouge() &&
                   p.getVert()  == p2.getVert()  && 
                   p.getBleu()  == p2.getBleu()   );
        }
}


void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());

    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;

    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel pix = getPix(x,y);
            // ajouter le + avant converti en int <=> a mettre (int) avant
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " <<
            +pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());

	unsigned int r,g,b;
	string mot;
	dimx = dimy = 0;

	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);

	if (tab != nullptr) delete [] tab;

	tab = new Pixel [dimx*dimy];

    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> g >> b;
            getPix(x,y).setRouge((unsigned char) r);
            getPix(x,y).setVert((unsigned char) g);
            getPix(x,y).setBleu((unsigned char) b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " <<
            +pix.getBleu() << " ";
        }
        cout << endl;
    }
}

void Image::afficher(){
    
}
