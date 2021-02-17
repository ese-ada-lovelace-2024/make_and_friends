#include "beetle.h"

Beetle::Beetle(const char* name): Animal{name}{
    this->animalType = "beetle";
}

int main(int argc, char* argv[]) {

    Beetle bob("bob");
    std::cout << bob;

    return 0;
}