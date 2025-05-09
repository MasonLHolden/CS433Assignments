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

      int frame = -1;
      for(int i = 0; i < num_frames; i++) {
        if(frame_table[i] == -1)
          frame = i;
            break;
      }
}

// Access an invalid page and no free frames are available
int LRUReplacement::replace_page(int page_num) {
    // TODO: Update your data structure LRU replacement and pagetable
    return 0;
}
