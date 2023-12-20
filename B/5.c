#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int send_data = world_rank;
    int recv_data;

    int source = (world_rank - 1 + world_size) % world_size;
    int dest = (world_rank + 1) % world_size;

    MPI_Sendrecv(&send_data, 1, MPI_INT, dest, 0, &recv_data, 1, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("process %d sent %d to process %d and it received %d from process %d", world_rank, send_data, dest, recv_data, source);

    MPI_Finalize();
    return 0;
}