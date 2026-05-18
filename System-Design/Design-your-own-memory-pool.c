
#include <stdio.h>
#include <stdint.h>

#define NUM_BLOCKS 4 
#define BLOCK_SIZE 16 

// Actual memory Pool 
uint8_t memory_pool[NUM_BLOCKS][BLOCK_SIZE];

//SToring Address of free blocks in an array
void *free_list[NUM_BLOCKS];
// we use void pointer as the type of address can be anything 

//Count number of free blocks 
int free_count;

//Initialise memory pool 
void pool_init()
{
    for(int i =0; i<NUM_BLOCKS; i++)
    {
        free_list[i]=memory_pool[i];
    }
    free_count = NUM_BLOCKS;
}

//Allocating a new block 
void *my_alloc()
{
    if(free_count == 0)
    {
        return NULL;
    }
    free_count--;
    return free_list[free_count];
}

//Return block back to pool: add the address of the array into the pool
void my_free(void *ptr)
{
    if(free_count<NUM_BLOCKS)
    {
        free_list[free_count] = ptr;
        free_count++;
    }
}

//Print current pool state
void print_pool_state()
{
    printf("\n----- Pool State -----\n");

    printf("Free Count = %d\n", free_count);

    printf("Free Blocks:\n");

    for(int i = 0; i < free_count; i++)
    {
        printf("free_list[%d] = %p\n", i, free_list[i]);
    }

    printf("----------------------\n");
}

int main()
{
    pool_init();
    print_pool_state();
    
    /* Allocate blocks */
    void *p1 = my_alloc(); // whenever we need to allocate address we use function pointers 
    void *p2 = my_alloc();
    
    printf("\nAllocated p1 = %p\n", p1);
    printf("Allocated p2 = %p\n", p2);
    print_pool_state();
    //Use allocated memory 
    if(p1==NULL)
    {
        uint8_t *data = (uint8_t*)p1;
        data[0] = 10;
        data[1] = 20;
        printf("\np1 data : %d %d\n", data[0], data[1]);
    }
        /* Free memory */
    my_free(p1);

    printf("\nFreed p1\n");

    print_pool_state();

    my_free(p2);

    printf("\nFreed p2\n");

    print_pool_state();

    return 0;
}













