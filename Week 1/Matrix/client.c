#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "matrix.h"

double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);
    t+=( end.tv_nsec - start.tv_nsec) * 0.000000001;
    return t;
}

int main()
{
    int n;
    
    struct timespec start;
    struct timespec end;

    printf("Enter the size of the matrix: ");
    scanf("%d",&n);

    int a[n][n]; //int a[n][n] -> Variable Length Array (use with forward declaration in funcs)
    int b[n][n];
    int c[n][n];

    srand(time(0));
    
    //clock_gettime(CLOCK_REALTIME, &start); // time to fill matrix
    fill_matrix(a,n);
    //clock_gettime(CLOCK_REALTIME, &end);
    fill_matrix(b,n);

    clock_gettime(CLOCK_REALTIME, &start); // time to add 2 matrices
    add_matrix(a,b,c,n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Time Elapsed: %lf\n", time_elapsed(start,end));

    clock_gettime(CLOCK_REALTIME, &start); // time to multiply 2 matrices
    multiply_matrix(a,b,c,n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Time Elapsed: %lf\n", time_elapsed(start,end));

    display_matrix(a,n);
    display_matrix(b,n);
    display_matrix(c,n);
}