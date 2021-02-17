#include <vector>

int my_sum(std::vector<int> *v){
    int total=0;
    for (auto it=v->begin();it != v->end() ; ++it) {
        total = total += *it;
    }
    return total;
}