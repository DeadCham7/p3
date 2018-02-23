#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "queue.h"
#include "sem.h"
#include "thread.h"

struct semaphore {
    int count;
};

sem_t sem_create(size_t count)
{
    sem_t sem = malloc(sizeof(struct semaphore));

    sem->count = count;
    return sem;
}

int sem_destroy(sem_t sem)
{
    free(sem);
    return 0;
}

int sem_down(sem_t sem)
{
    if (sem == NULL){
        return -1;
    }

    enter_critical_section();
    if (sem->count == 0){
        thread_block();
    } else {
        sem->count--;
    }
    exit_critical_section();

    return 0;
}

int sem_up(sem_t sem)
{
    if (sem == NULL){
        return -1;
    }

    enter_critical_section();
        pthread_t tid;
        thread_unblock(tid);
        sem->count++;
    exit_critical_section();

    return 0;
}

