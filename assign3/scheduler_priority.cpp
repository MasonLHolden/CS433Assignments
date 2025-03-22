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
}

void SchedulerPriority:: print_results() {
  cout<<"Priority Results"<<endl<<endl<<"------------------"<<endl<<endl;

  //print proceses
  for(int i =0; i< processes.size(); i++)
  {
    cout<<"Process: "<<processes[i].id<<" "<<"Turnaround Time: "<<turnaround_times[i]<<" "<<"Wait time: "<<waiting_times[i]<<endl<<endl; 

  }

  //print AVGs
  cout<<"Avg Turnaround Time: "<<avg_turnaround<<endl;
  cout<<"Avg Wait Time: "<<avg_waiting<<endl;


}

void SchedulerPriority:: simulate() {

  //init TT and WT sums
  float Sum_turnaround_times = 0;
  float Sum_waiting_times = 0;

  //increment through processes vector and update times
  for(size_t i = 0; i < processes.size();i++)
  {
    //update WT at i to be CT
    waiting_times[i] = current_time;
    //increment CT with burst time at process i
    current_time += processes[i].burst_time;
    //set TT at i to CT
    turnaround_times[i] = current_time;

}

  //if TT vector is not empty calculate AVG
   if(!turnaround_times.empty())
    {
      for (int i =0; i<processes.size(); i++){
        Sum_turnaround_times = Sum_turnaround_times + turnaround_times[i];
      }
      avg_turnaround=Sum_turnaround_times/turnaround_times.size();
    }


    //if WT vector is not empty calculate AVG
    if(!waiting_times.empty())
    {
      for (int i =0; i<processes.size(); i++){
        Sum_waiting_times = Sum_waiting_times + waiting_times[i];
      }
      avg_waiting = Sum_waiting_times/waiting_times.size();
    }

  
}
