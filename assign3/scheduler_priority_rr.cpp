/**
* Assignment 3: CPU Scheduler
 * @file scheduler_priority.cpp
 * @author Mason Lavender Holden
 * @brief This Scheduler class implements the Priority scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code


#include "scheduler_priority.h"
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

// TODO: add implementation of SchedulerPriority constructor, destrcutor and
// member functions init, print_results, and simulate here


SchedulerPriority:: SchedulerPriority(): current_time(0), avg_turnaround(0),avg_waiting(0)
{

}

SchedulerPriority::~SchedulerPriority() {

}
void SchedulerPriority:: init(std::vector<PCB>& process_list) {
  processes = process_list;


  turnaround_times.resize(processes.size(),0);
  waiting_times.resize(processes.size(),0);


  sort(processes.begin(), processes.end(),[](const PCB& a, const PCB& b){return a.priority > b.priority;});
  //sort(processes.begin(), processes.end(), (const PCB& a), (const PCB& b), {return a.priority < b.priority;});
}

void SchedulerPriority:: print_results() {
  cout<<"Priority Results"<<endl<<endl<<"------------------"<<endl<<endl;

  for(int i =0; i< processes.size(); i++)
  {
    cout<<"Process: "<<processes[i].id<<" "<<"Turnaround Time: "<<turnaround_times[i]<<" "<<"Wait time: "<<waiting_times[i]<<endl<<endl; //seg fault happens here

  }


  cout<<"Avg Turnaround Time: "<<avg_turnaround<<endl;
  cout<<"Avg Wait Time: "<<avg_waiting<<endl;


}

void SchedulerPriority:: simulate() {
  float Sum_turnaround_times = 0;
  float Sum_waiting_times = 0;
  for(size_t i = 0; i < processes.size();i++)
  {

    waiting_times[i] = current_time;

    current_time += processes[i].burst_time;

    turnaround_times[i] = current_time;

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

