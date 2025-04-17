/**
* Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author Mason Holden, Judah Fisher
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "buffer.h"
#include <unistd.h>
#include <pthread.h>

using namespace std;

// global buffer object
Buffer buffer;

// Producer thread function
// TODO: Add your implementation of the producer thread here
void *producer(void *param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
    buffer_item item = *((int *) param);

    while (true) {
        /* sleep for a random period of time */
        usleep(rand()%1000000);
    //    item = rand(); //from project 4 7.10 to initialize the item
        // TODO: Add synchronization code here
        if (buffer.insert_item(item)) {
            cout << "Producer " << item << ": Inserted item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Producer error condition"  << endl;    // shouldn't come here
        }
    }
}

// Consumer thread function
// TODO: Add your implementation of the consumer thread here
void *consumer(void *param) {
    buffer_item item;

    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000);
        // TODO: Add synchronization code here
        if (buffer.remove_item(&item)) {
            cout << "Consumer " << item << ": Removed item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Consumer error condition" << endl;    // shouldn't come here
        }
    }
}

int main(int argc, char *argv[]) {

    /* 1.Get command line arguments argv[1],argv[2],argv[3] */
    if (argc == 5) {
        int sleep_time = stoi(argv[1]);
        int num_producers = stoi(argv[2]);
        int num_consumers = stoi(argv[3]);

        if (sleep_time < 0|| num_consumers < 0 || num_producers < 0) {
            cout<<"Values must be positive"<<endl;
            return 1;
        }
        /*
        cout<<"Number of sleep_time: "<<sleep_time<<endl;
        cout<<"Number of producers: " << num_producers<<endl;
        cout<<"Number of consumers: " << num_consumers<<endl;
        */

        /* TODO: 2. Initialize buffer and synchronization primitives */

        Buffer(5);

        /* TODO: 3. Create producer thread(s).
         * You should pass an unique int ID to each producer thread, starting from 1 to number of threads */
        vector<pthread_t> producer_threads(num_producers);
        vector<buffer_item> producer_ids(num_producers);
        //pthread_t proThread;
        //void *thread_param=NULL;

        //int test = pthread_create(&proThread, NULL, producer, thread_param);


        for (int i = 0; i < num_producers; ++i) {
            producer_ids[i] = i+1;
            if (pthread_create(&producer_threads[i], NULL, producer, &producer_threads[i]) != 0) {
                cout<<"Producer thread creation failed"<<endl;
                return 1;
            }
        }
        /* TODO: 4. Create consumer thread(s) */
        vector<pthread_t> consumer_threads(num_consumers);
        vector<buffer_item> consumer_ids(num_consumers);
        for (int i = 0; i < num_consumers; ++i) {
            consumer_ids[i] = i+1;
            if (pthread_create(&producer_threads[i], NULL, producer, &consumer_threads[i]) != 0) {
                cout<<"Consumer thread creation failed"<<endl;
                return 1;
            }
        }

        /* TODO: 5. Main thread sleep */
        cout << "Main thread sleeping for "<<sleep_time<<" seconds" << endl;
        sleep(sleep_time);


    }

    /* TODO: 6. Exit */
    return 0;
}

