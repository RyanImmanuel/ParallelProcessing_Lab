#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int recv[world_size],
        send = world_rank;

    MPI_Gather(&send, 1, MPI_INT, recv, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (world_rank == 0)
    {
        printf("gathered data:\n");
        for (int i = 0; i < world_size; i++)
            printf("%d ", recv[i]);
    }

    MPI_Finalize();
    return 0;
}