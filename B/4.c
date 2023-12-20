#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int world_size, world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (world_size < 2)
    {
        printf("We require more that 1 process!\n");
        MPI_Finalize();
        return 0;
    }

    int number = 5;
    MPI_Request request;
    MPI_Status status;

    if (world_rank == 0)
    {
        MPI_Isend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
        MPI_Irecv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
        // MPI_Wait(&request, &status);
        printf("process 0 received number %d from process 1\n", number);
    }
    else if (world_rank == 1)
    {
        MPI_Isend(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        // MPI_Wait(&request, &status);
        MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        // MPI_Wait(&request, &status);
        printf("process 1 sent number %d to process 0\n", number);
    }
    MPI_Finalize();
    return 0;
}