#include "myheader.h"
#include <iostream>

Flour::Flour(int x): amount{x} {}

int main(){

    Egg e1 = Egg("black", "speckled");
    Egg e2 = Egg("white", "smooth");

    e1.mix(e2);
    e1.mix(Sugar(200));
    e1.mix(Flour(400));

    std::cout << e1;
    
    

    return 0;
}