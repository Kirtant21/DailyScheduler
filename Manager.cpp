//Name: Manager.h
//Project: CMSC 202 Project 3, Fall 2021
//Author:  Kirtan Thakkar (XS90456)
//Date:    10/14/21
//Desc: This file contains the header details for the Manager class

#include "Manager.h"

// Name: Manager (constructor)
// Desc: Creates a Manager to manage schedules
// Preconditions:  None
// Postconditions: A manager is created to populate m_schedules
Manager::Manager(string fileName){


  m_fileName = fileName;

  ReadFile();

}
// Name:  Manager (destructor)
// Desc: Deallocates all dynamic aspects of a Manager
// Preconditions: There is an existing Schedule
// Postconditions: All schedules are cleared
Manager:: ~Manager(){
  
  for(unsigned int i = 0; i < m_schedules.size(); i++)
    {
      delete m_schedules[i];
    }

  m_schedules.clear();

}
// Name:  DisplaySchedules
// Desc: Displays each schedule in m_schedules
// Preconditions: At least one schedule is in m_schedules
// Postconditions: Displays all items in a schedule for all schedules in m_schedules
void Manager::DisplaySchedules(){

  for(unsigned int i = 0; i < m_schedules.size(); i++)
   {
    cout << "\nSchedule for " << m_schedules[i]->GetName() << endl;
    cout << m_schedules[i]->GetSize() << " activities scheduled" << endl;
    cout << *m_schedules[i] << endl;

  }
  
}
// Name:  ReadFile
// Desc: Reads in a file that has the schedule name then semicolon the starting time then a semicolon
//       then the name of the activity.
//       Input files are an indeterminate length. There are an indeterminate number of schedules in
//       an input file. There are an indeterminate number of items in each file.
//       The vector can hold many schedules.

// Preconditions: Valid file name of schedules
// Postconditions: Populates each schedule and puts in m_schedules

void Manager::ReadFile(){
  
 int totalNodes = 0;
 string name, activity, time; 
 bool taken = false;
 ifstream inputFile;
 Item* item;
 Schedule* newItem;
  
  inputFile.open(m_fileName);

  cout << "Opened File" << endl;

  if(inputFile.is_open())
    {      
      while(getline(inputFile, name, ';'))
	{
	  getline(inputFile, time, ';');
	  getline(inputFile, activity, '\n');

	  
	  for(unsigned int i = 0; i < m_schedules.size(); i++)
	    {
	      if(name == m_schedules[i]->GetName())
		{
		  taken = true;
		  i = m_schedules.size();
		  
		}else{

		taken = false;
	      }
	    }

	  
	  if(!taken)
	    {
	      newItem = new Schedule(name);	      
	      item = new Item(activity, stoi(time));
	      newItem->InsertSorted(item);
	      m_schedules.push_back(newItem);
	      
	    }else{


	    for(unsigned int i = 0; i < m_schedules.size(); i++)
	      {
		if(name == m_schedules[i]->GetName())
		  {
		    item = new Item(activity, stoi(time));
		    m_schedules[i]->InsertSorted(item);
		     i = m_schedules.size();  
		  }

	      }
	    
	  }
 
	}

      inputFile.close();      
    }else {

    cout << "Error: unable to open the file, Please check your input file." << endl;
  }

  for(unsigned int i = 0; i < m_schedules.size(); i++)
    {
      totalNodes += m_schedules[i]->GetSize();
    }

  cout << totalNodes << " nodes loaded across " << m_schedules.size() << " schedules." << endl;   

  MainMenu();

}

// Name: InsertNewItem
// Desc: Asks the user which schedule they would like to insert into (uses FindSchedule)
//       If new schedule, inserts a new schedule and indicates a new schedule was created
//       Prompts user for time and name of item then inserts item into schedule
// Preconditions: Populated m_schedules
// Postconditions: Either inserts into existing schedule or inserts into a new schedule

void Manager::InsertNewItem(){

  string name, activity;
  int time, foundSched = 0;
  Schedule* sched;
  Item* newItem;

  cin.ignore(256, '\n');
  
  cout << "What is the name of the schedule you would like to insert into?" << endl;
  getline(cin,name);
 
    
  cout << "What is the start time of the activity?" << endl;
  cin >> time;

  cin.ignore(256, '\n');
  
  cout << "What is the name of the activity?" << endl;
  getline(cin,activity);

  
  foundSched = FindSchedule(name);
  
    if(foundSched == -1)
      {
	sched = new Schedule(name);
	newItem = new Item(activity, time);
	sched->InsertSorted(newItem);
	m_schedules.push_back(sched);

	cout << "\nNew schedule added for " << name << endl;
	cout << endl;
	
      }else{
      
      newItem = new Item(activity, time);
      m_schedules[foundSched]->InsertSorted(newItem);

      cout << "\nNew activity added to " << name << "'s schedule" << endl;
      cout << endl;
      
    }
}
// Name: FindSchedule
// Desc: Returns the index of the schedule from m_schedules else -1
// Preconditions: Populated m_schedules
// Postconditions: Returns the index of schedule with the matching name or it returns -1

int Manager::FindSchedule(string schedName){

    
  for(unsigned int i = 0; i < m_schedules.size(); i++)
    {      
      if(m_schedules[i]->GetName() == schedName)
	{
	  return int(i);
	}

    }
  return -1;
}
// Name:  MainMenu
// Desc: Displays the main menu and manages exiting
// Preconditions: Populated m_schedules
// Postconditions: None
void Manager::MainMenu(){

  int input;
  bool go = true;

  do{

    do{

      
	cout << "What would you like to do?" << endl;
	cout << "1. Display Schedules" << endl;
	cout << "2. Reverse Schedules" << endl;
	cout << "3. Insert New Item" << endl;
	cout << "4. Exit" << endl;
	cin >> input;
	
    }while(input > 4 && input <= 0); 

    switch(input)
      {
      case 1:

	DisplaySchedules();
	go = false;
	
	break;
      case 2:

	ReverseSchedule();
	go = false;
	
	break;
      case 3:

	InsertNewItem();
	go = false;
	
	break;
      case 4:

	cout << "Thank you for using Daily Scheduler" << endl;
	go = true;
	
	break;
      default:

	go = false;
      }

    
  }while(!go);
  
}
// Name: ReverseSchedule
// Desc: User chooses a schedule and the schedule is reversed
//       If only one schedule in m_schedules, automatically reverses it without prompting the user
// Preconditions: Populated m_schedules
// Postconditions: Reverses a specific schedule replacing in place
void Manager::ReverseSchedule(){

   unsigned int input = 0;
   bool ask = true;
   
  if(m_schedules.size() > 1)
    {

      do{
	  
	  cout << "which schedule would you like to reverse?" << endl;
	  cout << "choose 1 - " << m_schedules.size() << endl;
	  cin >> input;

	  if(input <= 0 || input > m_schedules.size())
	    {
	      ask = false;
	    }else{
	    ask = true;
	  }
	  
      }while(!ask);
   
      m_schedules[input -1]->ReverseSchedule();
      
    }else{

    m_schedules[0]->ReverseSchedule();
  }
  
  cout << "\nReversed a schedule!" << endl;
}
