#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

#define N 30
#define STEPS 12

int forest[N][N];
int newforest[N][N];

void initialize()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            forest[i][j]=1;

    forest[N/2][N/2]=2;
    forest[N/2+1][N/2]=2;
    forest[N/2-1][N/2]=2;
    forest[N/2][N/2+1]=2;
    forest[N/2][N/2-1]=2;
}

void printforest()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(forest[i][j]==1) printf("T ");
            else if(forest[i][j]==2) printf("F ");
            else printf("B ");
        }
        printf("\n");
    }
}

int main(int argc,char* argv[])
{
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank==0)
    {
        initialize();

        for(int step=0; step<STEPS; step++)
        {
            printf("\nStep %d\n\n",step+1);
            printforest();
            sleep(1);

            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(forest[i][j]==2)
                        newforest[i][j]=3;

                    else if(forest[i][j]==1)
                    {
                        int fire=0;

                        if(i>0 && forest[i-1][j]==2) fire=1;
                        if(i<N-1 && forest[i+1][j]==2) fire=1;
                        if(j>0 && forest[i][j-1]==2) fire=1;
                        if(j<N-1 && forest[i][j+1]==2) fire=1;

                        if(fire)
                            newforest[i][j]=2;
                        else
                            newforest[i][j]=1;
                    }
                    else
                        newforest[i][j]=3;
                }
            }

            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    forest[i][j]=newforest[i][j];
        }
    }

    MPI_Finalize();
    return 0;
}
