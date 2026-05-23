#include <stdio.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "queue.h"

#define NUM_BLOCKS 4
#define BLOCK_SIZE 16

/* Actual memory pool */
uint8_t memory_pool[NUM_BLOCKS][BLOCK_SIZE];

/* Queue handle */
QueueHandle_t free_queue;

/* Initialize pool */
void pool_init()
{
    /* Create queue */

    free_queue = xQueueCreate(
                        NUM_BLOCKS,
                        sizeof(void *)
                    );

    /* Add all block addresses into queue */

    for(int i = 0; i < NUM_BLOCKS; i++)
    {
        void *ptr = memory_pool[i];

        xQueueSend(free_queue, &ptr, 0);
    }
}

/* Allocate memory block */
void* my_alloc()
{
    void *ptr;

    if(xQueueReceive(free_queue, &ptr, 0) == pdPASS)
    {
        return ptr;
    }

    return NULL;
}

/* Return block back to pool */
void my_free(void *ptr)
{
    xQueueSend(free_queue, &ptr, 0);
}

int main()
{
    pool_init();

    void *p1 = my_alloc();
    void *p2 = my_alloc();

    printf("Allocated p1 = %p\n", p1);
    printf("Allocated p2 = %p\n", p2);

    /* Use memory */

    if(p1 != NULL)
    {
        uint8_t *data = (uint8_t *)p1;

        data[0] = 10;
        data[1] = 20;

        printf("Data = %d %d\n", data[0], data[1]);
    }

    /* Free memory */

    my_free(p1);
    my_free(p2);

    return 0;
}
