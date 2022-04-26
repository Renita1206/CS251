//Name: Renita Kurian
//SRN: PES1UG20CS331

#include "heap.h"
#include <stdlib.h>

void init_heap(heap_t *heap, int max_size) 
{
    heap->size = 0;
    heap->max_size = max_size;
    heap->arr = (int*)malloc(sizeof(int)*max_size);
}

void heapify(heap_t *heap, int *count_ptr)
{
    int i,c,p,elt;
    for(i=1;i<heap->size;i++)
    {
        elt=heap->arr[i];
        c=i;
        p=(c-1)/2;
        while(c>0 && heap->arr[p]<elt)
        {
            *count_ptr = *count_ptr+1;
            heap->arr[c]=heap->arr[p];
            c=p;
            p=(c-1)/2;
        }
        heap->arr[c]=elt;
    }    
}

void insert(heap_t *heap, int key, int *count_ptr) {
    if(heap->size == heap->max_size)
    {
        return;
    }
    heap->size++;
    heap->arr[heap->size-1] = key ;
    heapify(heap , count_ptr);
}

int extract_max(heap_t *heap, int *count_ptr) 
{
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size];
    heap->size--;
    heapify(heap,count_ptr);
    return max;
}

int search(const heap_t *heap, int key, int *count_ptr) 
{
    int res=-1;
    for(int i=0;i<heap->size;i++)
    {
        if(heap->arr[i]==key)
        {
            res = heap->arr[i];
        }   
        *count_ptr=*count_ptr+1;
    }
    return res;
}

int find_max(const heap_t *heap, int *count_ptr) 
{
    return heap->arr[0];

int find_min(const heap_t *heap, int *count_ptr) 
{
    int min = 999999;
    for(int i=(heap->size)/2 ; i < (heap->size) ; i++)
    {
        if(heap->arr[i]<min)
        {
            min = heap->arr[i];
        }
    *count_ptr = *count_ptr + 1;
    }
    return min;
}

void clear_heap(heap_t *heap) 
{
    heap->size=0;
}

void free_heap(heap_t *heap) 
{
    free(heap);
}