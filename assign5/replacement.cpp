/**
* Assignment 5: Page replacement algorithms
 * @file replacement.cpp
* @author Mason Lavender Holden, Judah Fisher
 * @brief A base class for different page replacement algorithms.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "replacement.h"

// TODO: Add your implementation of the Replacement member functions here

// Constructor
Replacement::Replacement(int num_pages, int num_frames)
: page_table(num_pages)
{
	//TODO: Add your implementation here
	for (int i=0; i<num_pages; i++) {
		page_table[i].frame_num = -1;
		page_table[i].valid = false;
		page_table[i].dirty = false;
	}

	//initialize variables
	this->num_frames = num_frames;
	this->num_pages = num_pages;
	this->num_replacements = 0;
	this->num_page_faults = 0;
	this->num_references = 0;

	//Initialize free frames list
	for (int i = 0; i< num_frames; i++) {
		free_frames.push_back(i);
	}
}

// Destructor
Replacement::~Replacement()
{
    // TOOD: Add your code here
}

// Simulate a single page access 
// @return true if it's a page fault
bool Replacement::access_page(int page_num, bool is_write)
{
    // TODO: Add your implementation here

    num_references++;

    // If the page is valid, it calls the touch_page function.
	if (page_table[page_num].valid) { //valid so call touch_page

        if(is_write) {
       		page_table[page_num].dirty = true;
        }
        touch_page(page_num);
        return false;
	}
	// If the page is not valid but free frames are available, it calls the load_page function.
		else { // not valid but free frames

		// If the page is not valid and there is no free frame, it calls the replace_page function.
          if(!free_frames.empty()) {
            int frame = free_frames.front();
            free_frames.pop_front();

            page_table[page_num].frame_num = frame;
            page_table[page_num].valid = true;

            load_page(page_num);
          }
          else
            {
            	//no free frames so replace a page
            	int victim_page = replace_page(page_num);

                //mark the victim page as invalid
                int victim_frame = page_table[victim_page].frame_num;
                page_table[victim_page].valid = false;


            }













    return false;
}

// Print out statistics of simulation
void Replacement::print_statistics() const {
        // TODO: print out the number of references, number of page faults and number of page replacements
		std::cout << "Number of references: \t\t"  << std::endl;
		std::cout << "Number of page faults: \t\t" << std::endl;
		std::cout << "Number of page replacements: \t"  << std::endl;
}


}
