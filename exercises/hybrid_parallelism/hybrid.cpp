#include "mpi.h"

#include <iostream>


int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::cout << "Hello from rank " << rank << std::endl;

#pragma omp parallel for
    for (int i = 0; i <100; i++)
    {
        std::cout << 100*rank + i << "\n";
    }
    return 0;

    MPI_Finalize();
}