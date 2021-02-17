#include "animal.h"

Animal::Animal(const char* name){
    this->name= name;
    this->animalType = "something";
}

std::ostream& operator<<(std::ostream& os, const Animal& animal){
    os << animal.name << " is a " << animal.animalType <<std::endl;
    return os;
} 