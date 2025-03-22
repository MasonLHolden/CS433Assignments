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
#include <queue>
#include <iomanip>
#include <iostream>
using namespace std;

// member functions init, print_results, and simulate here
SchedulerRR:: SchedulerRR(int time_quantum) {
    quantum = time_quantum;
    this->current_time = 0;
    this->avg_turnaround = 0;
    this->avg_waiting = 0;

}
SchedulerRR::~SchedulerRR() { //nothing happens in destructor

}

void SchedulerRR:: init(std::vector<PCB>& process_list){

    //copy of list
    processes = process_list;
//initializing values
    avg_turnaround = 0;
    avg_waiting = 0;
    //reset sim time
    current_time = 0;



    //allocate space
    turnaround_times.resize(processes.size());
    waiting_times.resize(processes.size());

  }


void SchedulerRR:: print_results(){

    cout<<"RR Results"<<endl<<endl<<"------------------"<<endl<<endl;

    for(int i =0; i< processes.size(); i++) //looping for whole size
    {
        cout<<"Process: "<<processes[i].id<<" "<<"Turnaround Time: "<<turnaround_times[i]<<" "<<"Wait time: "<<waiting_times[i]<<endl<<endl; //seg fault happens here

    }

//outputting
    cout<<"Avg Turnaround Time: "<<avg_turnaround<<endl;
    cout<<"Avg Wait Time: "<<avg_waiting<<endl;


   
  }

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerRR:: simulate() {
   //initializing 
    float total_turnaround = 0;
    float total_waiting = 0;
    queue<int> ready_queue;
    vector<int> remaining_burst(processes.size());
    vector<float> completion_time(processes.size(),0);


    for(size_t i = 0; i < processes.size(); i++) //loop for size
        {
            remaining_burst[i] = processes[i].burst_time; 
        }

    for(size_t i = 0; i < processes.size(); i++) //loop for size
        {
            ready_queue.push(i); //push into vector
        }
while(!ready_queue.empty()) //while empty loop
    {
        int current_process = ready_queue.front(); //current is equal to the front of the vector
    int execution_time = min(quantum, remaining_burst[current_process]); //ET is equal to the min


        ready_queue.pop(); //popping ready queue

        current_time += execution_time; //current time is incremented 

        remaining_burst[current_process] -= execution_time; //remaining burst is decremented

        if(remaining_burst[current_process] == 0) //if remains are 0, skip
        {
            completion_time[current_process] = current_time;

            turnaround_times[current_process] = completion_time[current_process];

            waiting_times[current_process] = turnaround_times[current_process] - processes[current_process].burst_time;
        }
        else{ //if not 0 push for later
            ready_queue.push(current_process); //pushing into queue
        }
    }

    
    for(size_t i = 0;i<processes.size();i++) //loop for size
        {
            //incrementing totals
            total_turnaround += turnaround_times[i]; 
            total_waiting += waiting_times[i];
        }
    //calculations
    avg_turnaround = total_turnaround/processes.size(); 
    avg_waiting = total_waiting/processes.size();

  }

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
