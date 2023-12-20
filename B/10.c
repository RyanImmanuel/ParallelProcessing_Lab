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
            // printf("data has been scattered across all ranks %d\n", send[i]);
        }
        printf("data has been scattered across all ranks \n");
    }

    MPI_Scatter(send, 1, MPI_INT, &recv, 1, MPI_INT, 0, MPI_COMM_WORLD);
    recv += 10; // modify recv in each rank
    // int send2[world_size];
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Gather(&recv, 1, MPI_INT, send, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (world_rank == 0)
    {
        printf("gathered data : \n");
        for (int i = 0; i < world_size; i++)
        {
            printf("%d  ", send[i]);
        }
    }

    MPI_Finalize();
    return 0;
}