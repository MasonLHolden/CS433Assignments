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

  sort(processes.begin(), processes.end(), [](const PCB& a), const PCB& b {return a.priority < b.priority;});
  
}

void SchedulerPriority:: print_results() {
  

}

void SchedulerPriority:: simulate() {
  for(size_t i = 0; i < processes.size();i++)
    {
      waiting_times[i] = current_time;

      current_time += current_process.burst_time;

      turnaround_times[i] = current_time;

    }
  

}
