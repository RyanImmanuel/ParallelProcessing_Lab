#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int number;

    if (world_rank == 0)
    {
        number = 7;
        printf("root 0 has broadcasted number\n");
    }
    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("process %d has received %d from the broadcast data of process %d", world_rank, number, 0);

    MPI_Finalize();
    return 0;
}