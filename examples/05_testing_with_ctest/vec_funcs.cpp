#include <stdexcept>

#include "vec_funcs.h"

int my_sum(std::vector<int> &vec){
    int total=0;
    for (auto ele: vec) {
        total = total += ele;
    }
    return total;
}

int my_prod(std::vector<int> &vec){
    if (vec.size() == 0) {
        throw std::invalid_argument("my_prod: vector must have at least one element");
    }
    int total=1;
    for (auto ele: vec) {
        total = total *= ele;
    }
    return total;
}