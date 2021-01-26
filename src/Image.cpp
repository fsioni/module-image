#include "Image.h"
#include <assert.h> 
#include <iostream>

using namespace std;

Image::Image(){
    dimx = 0;
    dimy = 0;
}

Image::Image(unsigned int dimensionX, unsigned int dimensionY){
    assert(dimensionX > 0);
    assert(dimensionY > 0);
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

void Image::setPix(unsigned int x, unsigned int y, Pixel const & couleur){
    assert(x<=dimx && y<=dimy);
    tab[y*dimx+x] = couleur;
}


void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel const & couleur){
    assert(Xmin<=Xmax && Ymin<=Ymax);
    assert(Xmin <= dimx && Xmax <= dimx);

    assert(Xmax<=dimx && Ymax<=dimy);
    assert(Ymin <= dimy && Ymax <= dimy);

    for(unsigned int i=Xmin; i<=Xmax; i++)
        for(unsigned int j=Ymin; j<=Ymax; j++)
            setPix(i, j, couleur);
}


void Image::effacer(Pixel const & couleur){
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression(){
    Pixel p(255, 0, 0);
    Pixel x(0, 0, 255);
    Pixel n(0, 255, 0);

    cout << "Premiere image" << endl;
    for(unsigned int i=0; i<dimx; i++){
        for(unsigned int j=0; j<dimy; j++){            
            setPix(i, j, p); //test setPix()

            cout << "(" << (int)getPix(i, j).getRouge() << " ," <<  (int)getPix(i, j).getVert() << " ," << (int)getPix(i, j).getBleu() << ")" << " " << endl; //test getPix()            
            }
    }

    dessinerRectangle(0, 0, dimx, dimy, x); // test dessiner Rectangle
    cout << "Nouvelle image" << endl;
    for(unsigned int i=0; i<dimx; i++){
        for(unsigned int j=0; j<dimy; j++){    
            cout << "(" << (int)getPix(i, j).getRouge() << " ," <<  (int)getPix(i, j).getVert() << " ," << (int)getPix(i, j).getBleu() << ")" << " " << endl; //test getPix()            
            }
    }

    effacer(n);
    cout << "Nouvelle image" << endl;
    for(unsigned int i=0; i<dimx; i++){
        for(unsigned int j=0; j<dimy; j++){    
            cout << "(" << (int)getPix(i, j).getRouge() << " ," <<  (int)getPix(i, j).getVert() << " ," << (int)getPix(i, j).getBleu() << ")" << " " << endl; //test getPix()            
            }
    }

    cout << endl;
}


void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            // ajouter le + avant converti en int <=> a mettre (int) avant
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	char r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> b >> g;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}
