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


// member functions init, print_results, and simulate here

SchedulerSJF::SchedulerSJF() : current_time(0), avg_turnaround(0),avg_waiting(0)
{}

//Destructor
SchedulerSJF::~SchedulerSJF()
{}
void SchedulerSJF:: init(std::vector<PCB>& process_list){
//copying over to member variable
    processes=process_list;

//resizing times arrays
    turnaround_times.resize(processes.size()); 
    waiting_times.resize(processes.size());


}


void SchedulerSJF:: print_results(){
 cout<<"SJF Results"<<endl<<endl<<"------------------"<<endl<<endl;
    for(int i =0; i< processes.size(); i++)
    {

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
int end = processes.size();
    sort(processes[0].burst_time, processes[end].burst_time); //sorting by burst time 

  }

  }
