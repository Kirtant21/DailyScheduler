//Name: Manager.h
//Project: CMSC 202 Project 3, Fall 2021
//Author:  Jeremy Dixon
//Date:    10/14/21
//Desc: This file contains the header details for the Manager class

#ifndef MANAGER_H
#define MANAGER_H

#include "Item.h"
#include "Schedule.h"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Manager {
 public:
  // Name: Manager (constructor)
  // Desc: Creates a Manager to manage schedules 
  // Preconditions:  None
  // Postconditions: A manager is created to populate m_schedules
  Manager(string fileName);
  // Name:  Manager (destructor)
  // Desc: Deallocates all dynamic aspects of a Manager
  // Preconditions: There is an existing Schedule
  // Postconditions: All schedules are cleared
  ~Manager();
  // Name:  DisplaySchedules
  // Desc: Displays each schedule in m_schedules
  // Preconditions: At least one schedule is in m_schedules
  // Postconditions: Displays all items in a schedule for all schedules in m_schedules
  void DisplaySchedules();
  // Name:  ReadFile
  // Desc: Reads in a file that has the schedule name then semicolon the starting time then a semicolon
  //       then the name of the activity.
  //       Input files are an indeterminate length. There are an indeterminate number of schedules in
  //       an input file. There are an indeterminate number of items in each file.
  //       The vector can hold many schedules.
  // Preconditions: Valid file name of schedules
  // Postconditions: Populates each schedule and puts in m_schedules
  void ReadFile();
  // Name: InsertNewItem
  // Desc: Asks the user which schedule they would like to insert into (uses FindSchedule)
  //       If new schedule, inserts a new schedule and indicates a new schedule was created
  //       Prompts user for time and name of item then inserts item into schedule
  // Preconditions: Populated m_schedules
  // Postconditions: Either inserts into existing schedule or inserts into a new schedule
  void InsertNewItem();
  // Name: FindSchedule
  // Desc: Returns the index of the schedule from m_schedules else -1
  // Preconditions: Populated m_schedules
  // Postconditions: Returns the index of schedule with the matching name or it returns -1
  int FindSchedule(string schedName);
  // Name:  MainMenu
  // Desc: Displays the main menu and manages exiting
  // Preconditions: Populated m_schedules
  // Postconditions: None
  void MainMenu();
  // Name: ReverseSchedule
  // Desc: User chooses a schedule and the schedule is reversed
  //       If only one schedule in m_schedules, automatically reverses it without prompting the user
  // Preconditions: Populated m_schedules
  // Postconditions: Reverses a specific schedule replacing in place
  void ReverseSchedule();
private:
  vector<Schedule*> m_schedules; //Vector of all schedules
  string m_fileName; //File to read in
};

#endif
