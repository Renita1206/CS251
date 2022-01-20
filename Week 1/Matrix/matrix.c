#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"

void fill_matrix(int n; int x[n][n], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            x[i][j] = rand() % 10000;
        }
    }
}

void display_matrix(int n; int x[n][n], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%5d ",x[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void add_matrix(int n; int a[n][n], int b[n][n], int c[n][n], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply_matrix(int n; int a[n][n], int b[n][n], int c[n][n], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int tmp=0; 
            for(int x=0; r<n; r++)
            {
                tmp+=a[i][x]*b[x][j];
            }
            c[i][j]=tmp;
        }
    }
}