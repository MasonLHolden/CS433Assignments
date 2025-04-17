/**
* Assignment 4: Producer Consumer Problem
 * @file buffer.cpp
 * @author Mason Holden, Judah Fisher
 * @brief Implementation file for the buffer class
 * @version 0.1
 */

// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include "buffer.h"
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <vector>

using namespace std;

// TODO: Add your implementation of the buffer class here

Buffer::Buffer(int size)
{

    buffer_size = size;
    buffer_count = 0;
    buffer_array = new buffer_item[buffer_size];
    front = 0;
    rear = 0;
    // Initialize mutex and condition variables
        pthread_mutex_init(&mutex, nullptr);
        pthread_cond_init(&full, nullptr);
        pthread_cond_init(&empty, nullptr);



}

Buffer::~Buffer()
{
   delete[] buffer_array;
    //destroy mutex and cond pthreads
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);
}

bool Buffer::insert_item(buffer_item item)
{
    pthread_mutex_lock(&mutex);
    //wait when full
    while (is_full()) {  //loop a wait if the array is full
        pthread_cond_wait(&full, &mutex);
    }

    buffer_array[rear] = item; //the ream is equal to the item we are inserting

    rear = (rear + 1) % buffer_size; //the place of the rear shifts by one and then mod

    buffer_count ++; //increment counter

    pthread_cond_signal(&empty); //signal to wake up threads

    pthread_mutex_unlock(&mutex); //unlock the mutex

    return true;
}

   
bool Buffer::remove_item(buffer_item *item) {
    pthread_mutex_lock(&mutex);
    //wait when full
    while (is_empty()) { //while the array is empty, loop
        pthread_cond_wait(&empty, &mutex); //wait
    }

    buffer_array[front] = *item; //front of the aray is equal to a pointer at the item

    front = (front + 1) % buffer_size;  //changing the front.

    buffer_count --; //decrementing because we have removed an item

    pthread_cond_signal(&full);

    pthread_mutex_unlock(&mutex);

    return true;
}

int Buffer::get_size()
{
    return buffer_size;
}

int Buffer::get_count()
{
    return buffer_count;
}

bool Buffer::is_empty()
{
    return (buffer_count == 0);
}

bool Buffer::is_full()
{
    return(buffer_count == buffer_size);
}

void Buffer::print_buffer()
{
    pthread_mutex_lock(&mutex);
    cout<<"Buffer: [";
    if (!is_empty()) {
        int index = front;
        for (int i = 0; i < buffer_count; i++) {
            cout<<buffer_array[index];
            if (i<buffer_count - 1) {
                cout<<", ";
            }
            index = (index + 1) % buffer_size;
        }
    }
    cout<<"]"<<endl;
    pthread_mutex_unlock(&mutex);
}


