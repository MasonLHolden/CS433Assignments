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

void *producer(void *param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
    buffer_item item = *((int *) param);

    while (true) {
        /* sleep for a random period of time */
        usleep(rand()%1000000);
    //    item = rand(); //from project 4 7.10 to initialize the item

        if (buffer.insert_item(item)) {
            cout << "Producer " << item << ": Inserted item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Producer error condition"  << endl;    // shouldn't come here
        }
    }
}

// Consumer thread function

void *consumer(void *param) {
    buffer_item item = *((int *) param); // initializing buffer item

    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000);

        //remove item
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

    //if valid number of arguments, execute
    if (argc == 5) {
        int sleep_time = stoi(argv[1]);
        int num_producers = stoi(argv[2]);
        int num_consumers = stoi(argv[3]);

        if (sleep_time < 0|| num_consumers < 0 || num_producers < 0) {
            cout<<"Values must be positive"<<endl;
            return 1;
        }



            //Buffer initialized as global variable

        //declare pthread and buffer item vectors
        vector<pthread_t> producer_threads(num_producers);
        vector<buffer_item> producer_ids(num_producers);

        //increment and assign producer IDs
        for (int i = 0; i < num_producers; ++i) {
            producer_ids[i] = i+1;
            if (pthread_create(&producer_threads[i], nullptr, producer, &producer_ids[i]) != 0) {
                cout<<"Producer thread creation failed"<<endl;
                return 1;
            }
        }

        vector<pthread_t> consumer_threads(num_consumers);
        vector<buffer_item> consumer_ids(num_consumers);

        //increment and assign consumer IDs
        for (int i = 0; i < num_consumers; ++i) {
            consumer_ids[i] = i+1;

            if (pthread_create(&consumer_threads[i], nullptr, consumer, &consumer_ids[i]) != 0) {
                cout<<"Consumer thread creation failed"<<endl;
                return 1;
            }
        }

        //main thread sleep
        cout << "Main thread sleeping for "<<sleep_time<<" seconds" << endl;
        sleep(sleep_time);

    }

    //Exit
    return 0;
}
