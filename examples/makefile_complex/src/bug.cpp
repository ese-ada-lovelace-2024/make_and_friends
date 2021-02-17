#include "bug.h"

Bug::Bug(const char* name): Animal{name}{
    this->animalType = "bug";
}

int main(int argc, char* argv[]) {

    Bug fred("fred");
    std::cout << fred;

    return 0;
}