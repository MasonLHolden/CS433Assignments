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

LIFOReplacement::LIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
  for(int i = 0;i < num_pages; i++)
    {
      page_table[i].age = 0;
    }
}

LIFOReplacement::~LIFOReplacement() {
//don't think anything needs to happen because vector already removes everything.
}

// Access an invalid page, but free frames are available
void LIFOReplacement::load_page(int page_num) {
    
  if(!free_frames.empty())
  {
    int frame = free_frames.front();
    free_frames.pop_front();

    //assign page to free frame
    page_table[page_num].valid = true;
    page_table[page_num].frame_num = frame;

    //set page as the most recent
    int max_age = 0;
    for(int i = 0;i < num_pages; i++)
      {
        if(page_table[i].valid && i != page_num && page_table[i].age > max_age)
        {
          max_age = page_table[i].age;
        }
      }
    page_table[page_num].age = max_age +1;
  }
  
  // int i = 0; 
  //   while(page_table[i].frame_num != -1) //incrementing until we get to a empty slot.
  //       i++; //incrementing counter
    
  //   if(page_table[i].frame_num ==-1) //if we have an empty slot
  //   page_table[i].frame_num = page_num; //changing value


}

// Access an invalid page and no free frames are available
int LIFOReplacement::replace_page(int page_num) {
       //find oldest index,
    int victim = -1;
    int youngest = 999;//starting oldest at big number
    int yIndex = -1; //the index where the oldest value is

  //find the oldest page
   for(int i = 0; i < num_pages; i++)
   {
      if(page_table[i].valid && (youngest == -1 || page_table[i].age < youngest))
      {
          //replace youngest index,
          victim = page_table[i].frame_num;
          youngest = page_table[i].age;
          yIndex = i;
      
      }
 }

 if(yIndex != -1)
 {
    //mark victim page invalid
    page_table[yIndex].valid = false;
    page_table[yIndex].frame_num = -1;

   //update new page
   page_table[page_num].valid = false;
   page_table[page_num].frame_num = victim;

   //make page the newest
   page_table[page_num].age = youngest +1;
   
 }

    //reset the newest that replaced the oldest's age to 0
    // page_table[yIndex].age = 0;
    // //increment age for everything.
    // for (int i = 0; i < page_table.size; i++)
    // {
    //     page_table[i].age++;
    // }
    
    return victim;
}
