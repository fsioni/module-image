# Module Image

## Contributeurs

SIONI Farès p1907037
BAGNOL Stanislas p1909886
CHOUGAR Lyes p1925126

## But

Réalisation du module Image dans le cadre du TD Outils ayant pour but
de prendre en main des outils indispensables à la programmation
comme GDB pour débugger, Valgrind pour gérer les fuites mémoires,
Doxygen pour générer de la documentation ou encore Git qui est un outil de
versioning.

Le module Image permet de representer et stocker une image. On peut
l'enregistrer sous format .ppm qui peut être visionner à l'aide d'une
visioneuse d'image ou alors l'afficher dans une fenetre avec la librairie
SDL, on peut égaler zoomer/dezoomer l'image.

## Réalisation

Une image (classe Image) est composé de pixels (classe Pixel). 
La classe Image est la seule à être manipulée directement. Elle alloue les pixels
sur le tas et peut manipuler des images de tailles variables. 
Les différentes fonctions sont accessibles via la documentation. (doc/html/index.html)

## Compilation

Dans le dossier racine du projet : utliser la commande 'make' pour compiler tous les executables.

## Autres commandes 

'clean' : Supprime les fichiers objets et exécutables
'doc' : Génère/regénère la documentation.


## Dépendances 

Compilateur : g++, gdb, make
Documentation : Doxygen
Librairies : SDL2 et STL

## Installer les dépendances (LINUX)

Suivre la procédure habituelle avec votre package manager pour : g++, gdb, make, doxygen, libsdl2-2.0-0

## Les exécutables

bin/test : Lancer la fonction TestRegression() de la classe Image. Effectue une série de tests pour vérifier l'intégrité du module.
bin/exemple : Effectue différentes modifications sur des images. (data/image1.ppm et data/image2.ppm)
bin/affichage : Dessine une image avant de l'afficher dans une fenêtre SDL2. Utilisez la touche T pour zoomer et G pour dezoomer. Q pour quitter.

## Lancer un exécutables

A la racine du dossier, entrer la commande './bin/test' ou './bin/exemple' ou './bin/affichage'.
