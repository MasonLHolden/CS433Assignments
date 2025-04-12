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

// TODO: Add your implementation of the buffer class here

Buffer::Buffer(int size)
{

    buffer_size = size;
    buffer_count = 0;
    buffer_array = new buffer_item[buffer_size];
    front = 0;
    rear = 0;

    // Initialize mutex and condition variables
    /*
        pthread_mutex(mutex)
        pthread_cond(not full)
        pthread_cond(not empty)
    */


}

Buffer::~Buffer()
{
    delete[] buffer_array;

    //destroy mutex and cond pthreads
}

bool Buffer::insert_item(buffer_item item)
{

}

   
bool Buffer::remove_item(buffer_item *item)
{

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

}
