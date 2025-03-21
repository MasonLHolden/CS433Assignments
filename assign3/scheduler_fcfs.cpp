/*
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Mason Lavender Holden, Judah Fisher
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "scheduler_fcfs.h"
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
// TODO: add implementation of SchedulerFCFS constructor, destrcutor and 
// member functions init, print_results, and simulate here

//initialization
SchedulerFCFS::SchedulerFCFS() : current_time(0), avg_turnaround(0),avg_waiting(0)
{}

//Destructor
SchedulerFCFS::~SchedulerFCFS()
{}

//initialize scheduler with process list
void SchedulerFCFS::init(vector<PCB>& process_list)
{
  //copy of list
  processes = process_list;

  //reset sim time
   current_time = 0;

  //allocate space

  turnaround_times.resize(processes.size());
  waiting_times.resize(processes.size());

  //sort for FCFS
  sort(processes.begin(), processes.end(),[](const PCB& a, const PCB& b){return a.arrival_time < b.arrival_time;});
}

//print
void SchedulerFCFS::print_results()
{
  cout<<"FCFS Results"<<endl<<endl<<"------------------"<<endl<<endl;

  for(int i =0; i< processes.size(); i++)
    {
      //cout<< "in da loop"<<endl;
        cout<<"Process: "<<processes[i].id<<" "<<"Turnaround Time: "<<turnaround_times[i]<<" "<<"Wait time: "<<waiting_times[i]<<endl<<endl; //seg fault happens here

    }
    //cout<<"HERE"<<endl;
   //avg_turnaround = accumulate(turnaround_times.begin(), turnaround_times.end(),0.0)/turnaround_times.size();
   //avg_waiting = accumulate(waiting_times.begin(), waiting_times.end(),0.0)/waiting_times.size();

  cout<<"Avg Turnaround Time: "<<avg_turnaround<<endl;
  cout<<"Avg Wait Time: "<<avg_waiting<<endl;

}

//simulation
void SchedulerFCFS::simulate()
{

  
    float Sum_turnaround_times=0.0;
    float Sum_waiting_times=0.0;
  

    if(!processes.empty())
    {
      current_time = processes[0].arrival_time;
    }

    for(size_t i = 0;i < processes.size(); i++)
    {
      if(current_time < processes[i].arrival_time)
      {
        current_time = processes[i].arrival_time;
      }
      // calculate WT
      waiting_times[i] = current_time - processes[i].arrival_time;
      //calculate CT
      current_time += processes[i].burst_time;
      //calculate TT
      turnaround_times[i] = current_time - processes[i].arrival_time;

    }


    if(!turnaround_times.empty())
    {
      for (int i =0; i<processes.size(); i++){
        Sum_turnaround_times = Sum_turnaround_times + turnaround_times[i];
      }
      avg_turnaround=Sum_turnaround_times/turnaround_times.size();
    }



    if(!waiting_times.empty())
    {
      for (int i =0; i<processes.size(); i++){
        Sum_waiting_times = Sum_waiting_times + waiting_times[i];
      }
      avg_waiting = Sum_waiting_times/waiting_times.size();
    }
}
