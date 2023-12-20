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
        printf("World size must be greater than 1\n");
        MPI_Finalize();
        return 0;
    }

    int number;
    if (world_rank == 0)
    {
        number = 0;
        MPI_Ssend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("process %d received number %d from process %d\n", world_rank, number, 1);
    }
    else if (world_rank == 1)
    {
        number = 1;
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Ssend(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("process %d sent number %d to process %d\n", world_rank, number, 0);
    }

    MPI_Finalize();
    return 0;
}