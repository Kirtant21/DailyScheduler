//Name: Schedule.h
//Project: CMSC 202 Project 3, Fall 2021
//Author:  Kirtan Thakkar (XS90456)
//Date:    10/14/21
//Desc: This file contains the header details for the Schedule class

#include "Schedule.h"

  // Name: Schedule() - Default Constructor
  // Desc: Used to build a new Schedule
  // Preconditions: None
  // Postconditions: Creates a new Schedule where m_head and m_tail point to nullptr\ and size = 0

Schedule:: Schedule(){

  m_name = "";
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
  
}
  // Name: Schedule(string) - Overloaded Constructor
  // Desc: Used to build a new Schedule with the schedule name passed
  // Preconditions: None
  // Postconditions: Creates a new Schedule where m_head and m_tail point to nullptr\ and schedule name is passed
  
Schedule::Schedule(string name){

  m_name = name;
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;

}
  // Name: ~Schedule() - Destructor
  // Desc: Used to destruct a strand of Schedule
  // Preconditions: There is an existing Schedule strand with at least one node
  // Postconditions: Schedule is deallocated (including all dynamically allocated no\des)
  // to have no memory leaks!
Schedule:: ~Schedule(){
  
Item* curr = m_head;

  while(curr != nullptr)
    {
      m_head = curr;
      curr = curr->GetNext();
      delete m_head;
      m_head = nullptr;

    }

  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
  
}
  // Name: InsertSorted
  // Desc: Inserts a new item into the schedule. Inserts it from earliest time (0) t\o  highest time (2359) ascending
  //       Does NOT insert at correct location when reversed
  // Preconditions: Takes in an Item pointer. Inserts the node based on time.
  //                Requires a Schedule
  // Postconditions: Adds the new item into the Schedule.
void Schedule::InsertSorted(Item* drop){  
 
 Item* temp = m_head;
 Item* curr;
 Item* temporary;

 if(m_head == nullptr)// creates HEAD
    {
       m_head = drop;
       m_tail = m_head;
      
    }else{

    if(drop->GetTime() < m_head->GetTime()) // checks if new node needs to be added before m_head or not! (adds BEFORE HEAD)
      {	
	drop->SetNext(temp);
	m_head = drop;
	
      }else{

      for(curr = m_head; curr != nullptr; curr = curr->GetNext()) // goes through the linkedList and checks for the right position to add a node to!
	{
	  m_tail = curr;
	  
	  if(drop->GetTime() > curr->GetTime()) // skips the nodes that have greater values than new node
	    {      
	      if(curr->GetNext() == nullptr) // checks if the next points at nullptr or not (adds AT THE END)
		{
		  curr->SetNext(drop);

		}else{ // adds in between two nodes (somewhere in the middle of the LinkedList)

		temporary = curr->GetNext();

		if(drop->GetTime() < (temporary->GetTime()) && drop->GetTime() > curr->GetTime()) // adds IN THE MIDDLE
		  {
		     drop->SetNext(temporary);
		     curr->SetNext(drop);
		    
		  }		
	      }
	    }
	} 
    }     
  }

  m_size++;

}
  // Name: GetName()
  // Preconditions: Requires a Schedule
  // Postconditions: Returns m_name;
string Schedule::GetName(){

  return m_name;

}
  // Name: GetSize()
  // Preconditions: Requires a Schedule
  // Postconditions: Returns m_size;
int Schedule::GetSize(){

  return m_size;

}

  // Name: ReverseSchedule
  // Preconditions: Reverses the Schedule
  // Postconditions: Schedule is reversed in place; nothing returned
void Schedule::ReverseSchedule(){


  Item *curr = m_head;
  Item *temp;
  Item *prev = nullptr;

  while(curr != nullptr)
    {
      temp = curr->GetNext();
      curr->SetNext(prev);
      prev = curr;
      curr = temp;
    }

  m_head = prev;


}
  // Name: GetData
  // Desc: Returns the time at a specific location in the Schedule
  //       Pass
  // Preconditions: Requires a Schedule
  // Postconditions: Returns data from specific item
  // Note: May not be used in project but still required
Item* Schedule::GetData(int nodeNum){

  Item* curr = m_head;

  if(m_head != nullptr)
    {
      for(int i = 0; i < m_size; i++)
	{
   
	  if(i == nodeNum-1)
	    {
	      return curr;

	    }
	  curr = curr->GetNext();

	}
    }else{

    cout << "No data found!" << endl;
  }
  
   return curr;

}

ostream &operator<< (ostream &output, Schedule &mySchedule){
 
Item* iter;

  for(iter = mySchedule.m_head; iter != nullptr; iter = iter->GetNext())
    {
      output << *iter << endl;
    }

  return output;
}
