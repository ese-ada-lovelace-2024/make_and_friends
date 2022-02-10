#pragma once

#include <string>
#include <iostream>

struct Sugar{
    int amount;
    Sugar(int);
};

struct Flour{
    int amount;
    Flour(int);
};

class Egg{
    std::string colour="";
    std::string finish="";
    bool sweet=false;
    Sugar sugar=Sugar(0);
    Flour flour=Flour(0);
    public:
    Egg(const char*, const char*);
    void mix(Egg);
    void mix(Flour);
    void mix(Sugar);

    friend std::ostream& operator<<(std::ostream&, const Egg&);
};