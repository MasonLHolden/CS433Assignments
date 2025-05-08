/**
* Assignment 5: Page replacement algorithms
 * @file lifo_replacement.cpp
  * @author Mason Lavender Holden, Judah Fisher
 * @brief A class implementing the Last in First Out (LIFO) page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "lifo_replacement.h"

// TODO: Add your implementation here
LIFOReplacement::LIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Add additional implementation code
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
LIFOReplacement::~LIFOReplacement() {
//don't think anything needs to happen because vector already removes everything.
}

// Access an invalid page, but free frames are available
void LIFOReplacement::load_page(int page_num) {
    int i = 0; 
    while(page_table[i].frame_num != -1) //incrementing until we get to a empty slot.
        i++; //incrementing counter
    
    if(page_table[i].frame_num ==-1) //if we have an empty slot
    page_table[i].frame_num = page_num; //changing value


}

// Access an invalid page and no free frames are available
int LIFOReplacement::replace_page(int page_num) {
    // TODO: Add necessary code here
       //find oldest index,
    int victim;
 int youngest = 999;//starting oldest at big number
 int yIndex; //the index where the oldest value is
 for(int i = 0; i<0; i++)
 {
    if(page_table[i].age < youngest)
    {
        //replace youngest index,
        victim = page_table[i].frame_num;
        youngest = page_table[i].age;
        yIndex = i;
    }
 }

 

    //reset the newest that replaced the oldest's age to 0
    page_table[yIndex].age = 0;
    //increment age for everything.
    for (int i = 0; i < page_table.size; i++)
    {
        page_table[i].age++;
    }
    
    return victim;
}
