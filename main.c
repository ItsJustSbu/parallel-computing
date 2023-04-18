#include <stdio.h>
#include <omp.h>

int main(){

    int b, a = 10, c = 5;
    int n = omp_get_num_procs();

    #pragma omp parallel num_threads(8) shared(n) private(a) firstprivate(c) default(none)
    {

        printf("n = (%d)",n);
    }

}