/**
* Assignment 3: CPU Scheduler
 * @file scheduler_rr.cpp
 * @author Mason Lavender Holden, Judah Fisher
 * @brief This Scheduler class implements the RoundRobin (RR) scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
//

#include "scheduler_rr.h"

// TODO: add implementation of SchedulerRR constructor, destrcutor and
// member functions init, print_results, and simulate here
SchedulerRR:: SchedulerRR(int time_quantum) {

}
SchedulerRR::~SchedulerRR() {

}

void SchedulerRR:: init(std::vector<PCB>& process_list){

    //copy of list
    processes = process_list;

    //reset sim time
    current_time = 0;

    //allocate space
    turnaround_times.resize(processes.size());
    waiting_times.resize(processes.size());

    //sort?
    //sort(processes.begin(), processes.end(),[](const PCB& a, const PCB& b){return a.arrival_time < b.arrival_time;});
  }


void SchedulerRR:: print_results(){

  }

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerRR:: simulate() {
    /*

    for i < processes size //outer loop
    {
    while(processes[i] burst Time != 0)
     if(burst_time < quantum)
     {
        current_time = current_time + burst_time
        burst_time = 0;
     }

    else if(burst_time >= quantum)
        {
            burst_time=burst_time - quantum
            current_time = current_time + burst_time
        }

        }
     */

  }

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerRR:: simulate() {

  }
