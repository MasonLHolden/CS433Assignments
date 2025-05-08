/**
* Assignment 5: Page replacement algorithms
 * @file fifo_replacement.cpp
 * @author Mason Lavender Holden, Judah Fisher
 * @brief A class implementing the FIFO page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "fifo_replacement.h"
#include <iostream>

// TODO: Add your implementation here
FIFOReplacement::FIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
  cout<<"FIFO constructor created"<<endl;
this->num_pages = num_pages;
this->num_frames = num_frames;

    // TODO: Add additional implementation code
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
FIFOReplacement::~FIFOReplacement() {
    //don't think anything needs to be added here.
}

// Access an invalid page, but free frames are available
    /**
     * @brief Access an invalid page, but free frames are available.
     * Assign the page to an available frame, not replacement needed
     * It may be overridden in a subclass 
     * @param page_num The logical page number.
     */
void FIFOReplacement::load_page(int page_num) {
    // TODO: Update your data structure FIFO replacement and pagetable
int i = 0; 
    while(page_table[i].frame_num != -1) //incrementing until we get to a empty slot.
        i++; //incrementing counter
    
    if(page_table[i].frame_num ==-1) //if we have an empty slot
    page_table[i].frame_num = page_num; //changing value

}

  /**
	 * @brief Access an invalid page and no free frame is available.
     * Select a victim page to be replaced.
	 * It is a pure virtual function to be implemented in specific replacement subclasses.
     * @param page_num  The logical page number of the desired page.
	 * @return Selected victim page #
	 */
// Access an invalid page and no free frames are available
int FIFOReplacement::replace_page(int page_num) {
    //find oldest index,
    int victim;
 int oldest = -999;//starting oldest at tiny number
 int oIndex; //the index where the oldest value is
 for(int i = 0; i<0; i++)
 {
    if(page_table[i].age > oldest)
    {
            //replace oldest index
            victim = page_table[i].frame_num;
        oldest = page_table[i].age;
        oIndex = i;
    }
 }

    
    
    //reset the newest that replaced the oldest's age to 0
    page_table[oIndex].age = 0;
    //increment age for everything.
    for (int i = 0; i < page_table.size; i++)
    {
        page_table[i].age++;
    }
    
    //reset the newest that replaced the oldest's age to 0
    //increment age for everything.
    return victim;
}
