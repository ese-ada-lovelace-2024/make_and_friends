#include "vec_funcs.h"

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <sum|prod> <list of integers>\n";
        return 1;
    } else if (std::string(argv[1]) == "sum") {
        std::vector<int> vec;
        for (int i=2; i<argc; ++i) {
            vec.push_back(std::stoi(argv[i]));
        }
        std::cout << my_sum(vec) << "\n";
        return 0;
    } else if (std::string(argv[1]) == "prod") {
        std::vector<int> vec;
        for (int i=2; i<argc; ++i) {
            vec.push_back(std::stoi(argv[i]));
        }
        std::cout << my_prod(vec) << "\n";
        return 0;
    } else {
        std::cerr << "Usage: " << argv[0] << " <sum|prod> <list of integers>\n";
        return 1;
    }
}