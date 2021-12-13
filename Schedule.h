//Name: Schedule.h
//Project: CMSC 202 Project 3, Fall 2021
//Author:  Jeremy Dixon
//Date:    10/14/21
//Desc: This file contains the header details for the Schedule class

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Item.h"
using namespace std;

class Schedule {
 public:
  // Name: Schedule() - Default Constructor
  // Desc: Used to build a new Schedule 
  // Preconditions: None
  // Postconditions: Creates a new Schedule where m_head and m_tail point to nullptr and size = 0
  Schedule();
  // Name: Schedule(string) - Overloaded Constructor
  // Desc: Used to build a new Schedule with the schedule name passed
  // Preconditions: None
  // Postconditions: Creates a new Schedule where m_head and m_tail point to nullptr and schedule name is passed
  Schedule(string);
  // Name: ~Schedule() - Destructor
  // Desc: Used to destruct a strand of Schedule
  // Preconditions: There is an existing Schedule strand with at least one node
  // Postconditions: Schedule is deallocated (including all dynamically allocated nodes)
  //                 to have no memory leaks!
 ~Schedule();
  // Name: InsertSorted
  // Desc: Inserts a new item into the schedule. Inserts it from earliest time (0) to highest time (2359) ascending
  //       Does NOT insert at correct location when reversed
  // Preconditions: Takes in an Item pointer. Inserts the node based on time.
  //                Requires a Schedule
  // Postconditions: Adds the new item into the Schedule.
  void InsertSorted(Item*);
  // Name: GetName()
  // Preconditions: Requires a Schedule
  // Postconditions: Returns m_name;
  string GetName();
  // Name: GetSize()
  // Preconditions: Requires a Schedule
  // Postconditions: Returns m_size;
  int GetSize();
  // Name: ReverseSchedule
  // Preconditions: Reverses the Schedule
  // Postconditions: Schedule is reversed in place; nothing returned
  void ReverseSchedule();
  // Name: GetData
  // Desc: Returns the time at a specific location in the Schedule
  //       Pass 
  // Preconditions: Requires a Schedule
  // Postconditions: Returns data from specific item
  // Note: May not be used in project but still required
  Item* GetData(int nodeNum);
  // Name: operator<<
  // Desc: Allows you to cout a Schedule object
  //       Overloaded << operator to return ostream from Schedule
  //       Should not have any cout statements!
  // Preconditions: Requires a Schedule sequence
  // Postconditions: Returns ostream populated for each Item in Schedule
  friend ostream &operator<< (ostream &output, Schedule &mySchedule);

  
 private:
  string m_name; //Name of the Schedule
  Item *m_head; //Front of the Schedule
  Item *m_tail; //End of the Schedule
  int m_size; //Total size of the Schedule
};

#endif
