#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int buffer_index = 0;

sem_t empty_count, full_count, mutex;

void* producer(void* arg) {
    int item;

    for (int i = 1; i <= NUM_ITEMS; i++) {
        item = i;

        sem_wait(&empty_count); // Wait for an empty slot in the buffer
        sem_wait(&mutex); // Acquire the mutex for buffer access

        // Produce an item and add it to the buffer
        buffer[buffer_index] = item;
        printf("Producer produced item: %d\n", item);
        buffer_index++;

        sem_post(&mutex); // Release the mutex
        sem_post(&full_count); // Increment the count of full slots in the buffer
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;

    for (int i = 1; i <= NUM_ITEMS; i++) {
        sem_wait(&full_count); // Wait for a full slot in the buffer
        sem_wait(&mutex); // Acquire the mutex for buffer access

        // Consume an item from the buffer
        buffer_index--;
        item = buffer[buffer_index];
        printf("Consumer consumed item: %d\n", item);

        sem_post(&mutex); // Release the mutex
        sem_post(&empty_count); // Increment the count of empty slots in the buffer
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize the semaphores
    sem_init(&empty_count, 0, BUFFER_SIZE);
    sem_init(&full_count, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create the producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for the producer and consumer threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean up the semaphores
    sem_destroy(&empty_count);
    sem_destroy(&full_count);
    sem_destroy(&mutex);

    return 0;
}
