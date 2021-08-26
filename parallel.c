#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
static void work(int n) {
    volatile int s;
    for (int i = 0; i < 100000000 * n; i++)
        s = i;
}
int main(int argc, char** argv) {
    int heavy[999];
    int num_threads = omp_get_max_threads();
    for (int i = 0; i < num_threads; i++) {
        if (argv[i + 1] == NULL) {
            fprintf(stderr, "needs %d arguments\n", num_threads);
            return 2;
        }
	heavy[i] = atoi(argv[i + 1]);
    }
#pragma omp parallel
    {
        int me = omp_get_thread_num();
        work(heavy[me]);
	putchar('a' + me);
    }
    putchar('\n');
}
