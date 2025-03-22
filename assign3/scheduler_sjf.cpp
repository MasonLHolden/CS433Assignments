/**
* Assignment 3: CPU Scheduler
 * @file scheduler_sjf.cpp
 * @author Mason Lavender Holden, Judah Fisher
 * @brief This Scheduler class implements the SJF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "scheduler_sjf.h"
#include <algorithm>

// member functions init, print_results, and simulate here
//constructor initilizes CT, AVG tt and WT
SchedulerSJF::SchedulerSJF() : current_time(0), avg_turnaround(0),avg_waiting(0)
{}

//Destructor, nothing happens
SchedulerSJF::~SchedulerSJF()
{}
void SchedulerSJF:: init(std::vector<PCB>& process_list){
//copying over to member variable
    processes=process_list;

//resizing times arrays
    turnaround_times.resize(processes.size()); 
    waiting_times.resize(processes.size());
    sort(processes.begin(), processes.end(),[](const PCB& a, const PCB& b){return a.burst_time < b.burst_time;});

}


void SchedulerSJF:: print_results(){
 cout<<"SJF Results"<<endl<<endl<<"------------------"<<endl<<endl;
    for(int i =0; i< processes.size(); i++) //looping for the whole array
    {
    //outputting    
        cout<<"Process: "<<processes[i].id<<" "<<"Turnaround Time: "<<turnaround_times[i]<<" "<<"Wait time: "<<waiting_times[i]<<endl<<endl; //seg fault happens here

    }
    cout<<"Avg Turnaround Time: "<<avg_turnaround<<endl;
    cout<<"Avg Wait Time: "<<avg_waiting<<endl;
}

/**
 * @brief This function simulates the scheduling of processes in the ready queue.
 *        It stops when all processes are finished.
 */
void SchedulerSJF:: simulate() {
int end = processes.size(); //end of the array for sort





    //initializing sum variables
    float Sum_turnaround_times=0.0;
    float Sum_waiting_times=0.0;

//if the processes array is empty set the current time to the first proceseses AT
    if(!processes.empty())
    {
        current_time = processes[0].arrival_time;
    }
//looping for whole size
    for(size_t i = 0;i < processes.size(); i++)
    {
        if(current_time < processes[i].arrival_time) //if the current time is less than current part of the arrays AT
        {
            current_time = processes[i].arrival_time; //Current time is equal to AT at process i
        }
        // calculate WT
        waiting_times[i] = current_time - processes[i].arrival_time;
        //calculate CT
        current_time += processes[i].burst_time;
        //calculate TT
        turnaround_times[i] = current_time - processes[i].arrival_time;

    }

//checking if TT array is empty
    if(!turnaround_times.empty())
    {
        for (int i =0; i<processes.size(); i++){
            Sum_turnaround_times = Sum_turnaround_times + turnaround_times[i];
        }
        avg_turnaround=Sum_turnaround_times/turnaround_times.size();
    }


// if waiting times is empty
    if(!waiting_times.empty())
    {
        for (int i =0; i<processes.size(); i++){
            Sum_waiting_times = Sum_waiting_times + waiting_times[i];
        }
        avg_waiting = Sum_waiting_times/waiting_times.size();
    }
  }
