#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int world_size, world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int data = world_rank;
    int max, min, sum, prod;

    MPI_Reduce(&data, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&data, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&data, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&data, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    if (world_rank == 0)
        printf("Max : %d\nMin : %d\nSum : %d\nProd : %d\n", max, min, sum, prod);

    MPI_Finalize();
    return 0;
}