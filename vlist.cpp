// Vlist.cpp
// Fong, Madison
// mnfong

#include <iostream>
#include "video.h"
#include "vlist.h"

using namespace std;

// Default constructor
Vlist::Vlist()
{
  m_head = NULL;
  m_length = 0;
}

// Deconstructor
Vlist::~Vlist()
{
  while (m_head)
  {
    Node *tmp = m_head;
    m_head = m_head -> m_next;
    delete tmp;
  }
}

// Creates the video and inserts it into the list
void Vlist::insert(string title, string url, string comment, float length, int rating)
{
  Video *video = new Video(title, url, comment, length, rating);
  if (!m_head || title < m_head -> m_value.getTitle())
  {
    m_head = new Node(video, m_head);
    m_length++;
  }
  else
  {
    if (findVideo(title) == false)
    {
      Node *ptr = m_head;
      while (ptr -> m_next != NULL && title > ptr -> m_next -> m_value.getTitle())
      {
        ptr = ptr -> m_next;
      }
      ptr -> m_next = new Node(video, ptr -> m_next);
      m_length++;
    }
    else
    {
      cerr << "Could not insert video <" << title << ">, already in list." << endl;
      delete video;
    }
  }
}

// Returns true if the video title can be found in the list
bool Vlist::findVideo(string title)
{
  for (Node *ptr = m_head; ptr; ptr = ptr -> m_next)
  {
    if (ptr == NULL)
      return false;
    else
    {
      if (ptr -> m_value.getTitle() == title) 
        return true;
    }
  }
  return false;
}

// Prints out the entire list
void Vlist::printList()
{
  if (m_head == NULL)
    return;
  for (Node *ptr = m_head; ptr; ptr = ptr -> m_next)
  {
    ptr -> m_value.print();
  }
}

// Deletes the video if it is in the list
void Vlist::removeTitle(string title)
{
  bool isRemoved = false;
  if (m_head == NULL)
  {
    cerr << "Title <" << title << "> not in list, could not delete." << endl;
  }
  else
  {
    Node *prev;

    for (Node *ptr = m_head; ptr; ptr = ptr -> m_next)
    {
      if (ptr -> m_value.getTitle() == title)
      {
        Video *holder = new Video(ptr -> m_value.getTitle(), ptr -> m_value.getURL(), ptr -> m_value.getComment(), ptr -> m_value.getLength(), ptr -> m_value.getRating());
        Node *temp = new Node(holder, ptr);
        if (ptr == m_head)
        {
          m_head = ptr -> m_next;
        }
        else if (ptr -> m_next != NULL)
        {
          prev -> m_next = ptr -> m_next;
        }
        else
        {
          prev -> m_next = NULL;
        }
        delete temp;
        delete holder;
        isRemoved = true;
      }
      prev = ptr;
    }
    if (isRemoved == false)
    {
      cerr << "Title <" << title << "> not in list, could not delete." << endl;
    }
  }
}

// Finds the video in the list, if it is there it prints out it's information
void Vlist::lookup(string title)
{
  if (m_head == NULL)
  {
    cerr << "Title <" << title << "> not in list." << endl;
  }
  else
  {
    bool isIn = false;
    for (Node *ptr = m_head; ptr; ptr = ptr -> m_next)
    {
      if (ptr -> m_value.getTitle() == title)
      {
        ptr -> m_value.print();
        isIn = true;
      }
    }
    if (isIn == false)
    {
      cerr << "Title <" << title << "> not in list." << endl;
    }
  }
}
