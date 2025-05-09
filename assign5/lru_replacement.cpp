/**
* Assignment 5: Page replacement algorithms
 * @file lru_replacement.cpp
  * @author Mason Lavender Holden, Judah Fisher
 * @brief A class implementing the LRU page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "lru_replacement.h"
#include <algorithm>
#include <list>
using namespace std;

// TODO: Add your implementation here
LRUReplacement::LRUReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    //initialize page table entries
     for(int i = 0; i < num_frames; i++) {
      page_table[i].valid = false;
      page_table[i].frame_num = -1;
    }



    //all frames initially free
    //free_frames = num_frames;
}

// TODO: Add your implementations for desctructor, touch_page, load_page, replace_page here
LRUReplacement::~LRUReplacement()
{
    // TODO: Add necessary code here
}

// Accesss a page alreay in physical memory
void LRUReplacement::touch_page(int page_num)
{
    list<int>::iterator it = find(lru_list.begin(), lru_list.end(), page_num);
    if(it != lru_list.end()) {
      lru_list.erase(it);
    }

    lru_list.push_back(page_num);

    page_hits++;
}

// Access an invalid page, but free frames are available
void LRUReplacement::load_page(int page_num) {

  // find first available free frame
      int frame = -1;
      for(int i = 0; i < num_frames; i++) {
        if(page_table[i].frame_num == -1){
          frame = i;
            break;
            }
      }

      //Update page table
      page_table[page_num].valid = true;
      page_table[page_num].frame_num = frame;

      // update page_table to inicate wich page occupies the frame
      page_table[frame].frame_num = page_num;

      // add page to LRU list
      lru_list.push_back(page_num);

      // decrement the count of free frames
      free_frames--;

      // increments page fault counter
      page_faults++;

}

// Access an invalid page and no free frames are available
int LRUReplacement::replace_page(int page_num) {

    //get least recently used page
    int lru_page_num = lru_list.front();
    lru_list.pop_front();

    //get frame occupied by LRU page
    int victim_frame = page_table[lru_page_num].frame_num;

    //mark the LRU page as invalid  in the page table
    page_table[lru_page_num].valid = false;
    page_table[lru_page_num].frame_num = -1;

    //Update page table to show new page is in frame
    page_table[victim_frame].frame_num = page_num;

    //Update page table for new page
    page_table[page_num].valid = true;
    page_table[page_num].frame_num = victim_frame;

    //add new page to lru list
    lru_list.push_back(page_num);

    //Update counters
    page_faults++;
    replacements++;

    return victim_frame;
}
