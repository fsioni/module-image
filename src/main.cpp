#include "Image.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Image im(5, 5);
    Pixel p(255, 0, 0);
    im.dessinerRectangle(2, 1, 3, 2, p);
    im.testRegression();    

    return 0;
}
