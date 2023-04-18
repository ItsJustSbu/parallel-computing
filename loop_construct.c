#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char **argv){
     int i, j, n;
     n = 13;
     printf("\t Iterations \t Thread \n");

     #pragma omp parallel num_threads(4) default(none) private(i,j) shared(n)
     {
        #pragma omp for schedule(runtime) ordered
        for (i=0; i < n; i++){
            #pragma omp ordered
            printf("\t %d \t\t %d \n", i, omp_get_thread_num());
            for(j=0; j < i; j++)
                system("sleep 1");
        } //end of parallel for

        
     } //end of parallel region
    
}