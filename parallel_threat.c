#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define DATA_SIZE 100

int data[DATA_SIZE]; // Array to be processed
int result[DATA_SIZE]; // Array to store results
pthread_mutex_t mutex; // Mutex for synchronizing access to result array

// Function to be executed by each thread
void* process_data(void* arg) {
    int thread_id = *((int*)arg);
    int start = thread_id * (DATA_SIZE / NUM_THREADS);
    int end = start + (DATA_SIZE / NUM_THREADS);

    for (int i = start; i < end; i++) {
        // Perform some computation on data[i]
        // For this example, let's just double the value
        result[i] = data[i] * 2;
    }

    // Synchronize access to the result array
    pthread_mutex_lock(&mutex);
    printf("Thread %d finished processing\n", thread_id);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the data array
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = i;
    }

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, process_data, &thread_ids[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the processed data
    printf("Processed Data:\n");
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

