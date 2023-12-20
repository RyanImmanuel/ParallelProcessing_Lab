#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    printf("Phase 1 , process %d out of %d\n", world_rank, world_size);

    MPI_Barrier(MPI_COMM_WORLD);

    printf("Phase 2 , process %d out of %d\n", world_rank, world_size);

    MPI_Finalize();
    return 0;
}