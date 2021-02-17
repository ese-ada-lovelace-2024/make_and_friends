#include <vector>
#include <iostream>

int my_sum(std::vector<int>*);

int main(int argc, char* argv[]){
    std::vector<int> a = {1,2,3};
    std::vector<int> b = {1,4,10};
    std::vector<int> c = {};

    if (my_sum(&a) == 6 && my_sum(&b) == 15 && my_sum(&c) == 0 ){
        std::cout << "Test my_sum passed\n";
        return 0;
    } else {
        std::cout << "Test my_sum passed\n";
        return 1;
    }
}