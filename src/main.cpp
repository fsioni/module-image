#include "Image.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Pixel p(1, 1, 1);
   
    cout << (int)p.getBleu() << endl;
    return 0;
}
