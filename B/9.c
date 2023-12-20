#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int send[world_size], recv;

    if (world_rank == 0)
    {
        for (int i = 0; i < world_size; i++)
        {
            send[i] = i;
        }
    }

    MPI_Scatter(send, 1, MPI_INT, &recv, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("process %d received %d from root 0", world_rank, recv);

    MPI_Finalize();
    return 0;
}