#include <iostream>
#include <fstream>

#include "mpi.h"

int main(int argc, char* argv[]){

    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    std::cout << "Hello from rank " << rank <<std::endl;

    std::ofstream file;

    // Simple io by opening one file per rank
    // This is not the best way to do things, but it is simple
    // and it works for this example.

    // It will work best in a scratch environment
    // where each rank could have its own filespace
    // and not interfere with each other.

    char filename[100];
    sprintf(filename, "output_%d.txt", rank);

    file.open(filename, std::ios::out | std::ios::app);

    if (file.is_open()) {
        file << "File write from rank " << rank << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    file.close();
    
    MPI_Finalize();

}