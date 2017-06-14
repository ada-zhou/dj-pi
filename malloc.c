/*
 * File: malloc.c
 * --------------
 * This is the simple "bump" allocator that Pat showed in lecture.
 * An allocation request is serviced by tacking on the requested
 * space to the end of the heap thus far. 
 * It does not recycle memory (free is a no-op) so when all the
 * space set aside for the heap is consumed, it will not be able
 * to service any further requests.
 *
 * This code is given here just to show the very simplest of
 * approaches to dynamic allocation. You are to replace this code
 * with your own heap allocator implementation.
 */

#include "malloc.h"
#include "printf.h"
#include "backtrace.h"
#include <stddef.h> // for NULL

extern int __bss_end__;

struct header {
    size_t payload_size;
    int status;       // 0 if free, 1 if in use
    #ifdef LEAK_DETECTOR
    struct frame f[3];
    #endif
} ;


// Simple function to round up x to multiple of n.
// The efficient but tricky bitwise approach it uses
// works only if n is a power of two -- why?
#define roundup(x,n) (((x)+((n)-1))&(~((n)-1)))


static void *heap, *heap_max, *rover;
static int hdrsize;


/* For the simple bump allocator, "heap" tracks the next location
 * to be allocated and "heap_max" is the location at the end of 
 * the available heap memory. We initialize heap to the first
 * location beyond the data as laid out in memmap (the symbol 
 * __bss_end__ allows us to locate the end), and set heap_max to
 * the location total bytes beyond that.
 */
void malloc_init(size_t total) 
{
    heap = &__bss_end__;
    heap_max = (char *)heap + total;
    
    hdrsize = 8;
#ifdef LEAK_DETECTOR
    hdrsize = 32;
#endif
    
    
    struct header* begin = heap;
   
    begin->payload_size = total-hdrsize;
    begin->status = 0;
   
    rover = heap;
    
    
}



void *malloc(size_t sz)
{
    struct header *index = rover;
    
    sz = roundup(sz, 8);
    

    while ((index->status != 0) || (index->payload_size <= (sz+hdrsize))) {
        index = (struct header*)((char*)index + index->payload_size + hdrsize);
        if ((char*)index == (char *) heap_max) {
            index = heap;
        }
        if (index == rover) {
            return NULL;
        }
    }
    
    
    void *alloc = (char *)index + hdrsize;
    
    
    struct header* first = index;
    struct header block;
    
    block.payload_size = (first->payload_size) - sz - hdrsize;
    block.status = 0;
    
    index = (struct header *)(((char *)index) + hdrsize + sz);
    *index = block;
    
    first->payload_size = sz;
    first->status = 1;
    
    rover = index;
    
#ifdef LEAK_DETECTOR
    backtrace(first->f, 3);
#endif
    
    return alloc;

 }

void free(void *ptr) 
{
    char * hdr = (char*)ptr - hdrsize;
    //hdr -= hdrsize;
    
    ((struct header *)hdr)->status = 0;
    
    struct header * temp = (struct header *) hdr;
    struct header * two;
    
    
    while (1) {
        two = (struct header *)(((char *)temp) + temp->payload_size + hdrsize);
        if (two == (struct header*)heap_max){
            break;
        }
        if (two == rover) {
            rover = hdr;
        }
        if (two->status == 0) {
            ((struct header *)hdr)->payload_size += (hdrsize + two->payload_size);
            temp = two;
        } else {
            break;
        }
    }

}

#ifdef LEAK_DETECTOR

/* This function will only be included if you compile with -DLEAK_DETECTOR. */
void leak_report()
{
    printf("[Leak report] \n \n");
    char * hdr = (char*)heap;
    
    int total = 0;
    int blocks = 0;
    
    
    struct header * ptr;
    while (hdr != heap_max) {
        ptr = (struct header *)hdr;

        if (ptr->status == 1) {
            blocks++;
            printf("%d bytes are lost, allocated by: \n", ptr->payload_size);
            total += (ptr->payload_size);
            print_frames(ptr->f,3);
            printf("\n");
        }
        hdr = hdr + (ptr->payload_size) + hdrsize;
        
    }
    
    printf("Lost %d total bytes in %d blocks", total, blocks);
    
    
}

#endif
