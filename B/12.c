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

    MPI_Allreduce(&data, &max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    MPI_Allreduce(&data, &min, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
    MPI_Allreduce(&data, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(&data, &prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);

    printf("Process :%d\nMax : %d\nMin : %d\nSum : %d\nProd : %d\n", world_rank, max, min, sum, prod);

    MPI_Finalize();
    return 0;
}