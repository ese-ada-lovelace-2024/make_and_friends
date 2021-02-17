#pragma once

#include <string>
#include <iostream>

class Animal
    {
        public:
        Animal(const char*);
        friend std::ostream& operator<<(std::ostream&,
                                        const Animal&);
        std::string name;
        std::string animalType;
    };