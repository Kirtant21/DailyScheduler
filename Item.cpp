//Name: Item.h
//Project: CMSC 202 Project 3, Fall 2021
//Author:  Kirtan Thakkar
//Date:    10/14/21
//Desc: This file contains the header details for the Item class

#include "Item.h"

  // Name: Item (default constructor)
  // Desc: Sets default values of a new Item (an item is a node in a linked list)
  // Preconditions: None
  // Postconditions: Creates a new node with a generic time and name with a pointer to nullptr
  // Note: May not be used in project 3 but still implement
Item:: Item(){

  m_name = "";
  m_time = 0;
  m_next = nullptr;

 }
  // Name: Item (overloaded constructor)
  // Desc: Sets values of a new Item (an item is a node in a linked list)
  // Preconditions: None
  // Postconditions: Creates a new node using the passed name and time with a pointer to nullptr
Item::Item(string name, int time){

  m_name = name;
  m_time = time;
  m_next = nullptr;
  
}
  // Name: GetName
  // Desc: Returns the name of the item
  // Preconditions: Item must exist
  // Postconditions: Returns the name of the item
  // Note: May not be used in project 3 but still implement
string Item::GetName(){

  return m_name; 

}
  // Name: GetTime
  // Desc: Returns the time of the item
  // Preconditions: Item must exist
  // Postconditions: Returns the time of the item
  // Note: May not be used in project 3 but still implement
int Item::GetTime(){

  return m_time;

}
  // Name: GetNext
  // Desc: Returns the pointer to the next item
  // Preconditions: Item must exist
  // Postconditions: Returns the pointer to the next item
  // Note: May not be used in project 3 but still implement
Item* Item::GetNext(){

  return m_next;

}
  // Name: SetName
  // Desc: Sets the name of the item
  // Preconditions: Item must exist
  // Postconditions: Sets the name of the item
  // Note: May not be used in project 3 but still implement
void Item::SetName(string name){

  m_name = name;

}
  // Name: SetTime
  // Desc: Sets the time of the item
  // Preconditions: Item must exist
  // Postconditions: Sets the time of the item
  // Note: May not be used in project 3 but still implement
void Item::SetTime(int time){

  m_time = time;

}
  // Name: SetNext
  // Desc: Sets the next item
  // Preconditions: Item must exist
  // Postconditions: Sets the next item
  // Note: May not be used in project 3 but still implement
void Item::SetNext(Item* next){
  
  m_next = next;

}
