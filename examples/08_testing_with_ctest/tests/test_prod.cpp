#include <vector>
#include <iostream>
#include <stdexcept>

#include "vec_funcs.h"

int main(int argc, char* argv[]){
    std::vector<int> a = {1,2,3};
    std::vector<int> b = {1,4,10};
    std::vector<int> c = {};

    if (my_prod(a) == 6 && my_prod(b) == 40 ){
        try {
            my_prod(c);
            std::cerr << "Test my_prod failed, ran on empty list.\n";
            return 1;
        } catch (std::invalid_argument& e) {
            std::cout << "Test my_prod passed\n";
            return 0;
        }
    } else {
        std::cerr << "Test my_prod failed, value error.\n";
        return 1;
    }
}