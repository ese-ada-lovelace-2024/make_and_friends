#include "myheader.h"

Egg::Egg(const char* c1, const char* c2) : colour{c1},
                                           finish{c2} {}

void Egg::mix(Sugar s) {
    this->sweet =true;
    this->sugar = s;
}

void Egg::mix(Flour f) {
    this->flour = f;
}

void Egg::mix(Egg e) {
    this->finish = e.finish;
}

std::ostream& operator<<(std::ostream& os, const Egg& e) {
    os << e.colour << ", " << e.finish;
    if (e.sweet) os << " sweet";
    os << std::endl;
}