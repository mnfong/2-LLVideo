// vlist.h
// Fong, Madison
// mnfong

#ifndef VLIST_H
#define VLIST_H

#include "video.h"

using namespace std;

class Vlist
{
  // Public functions
  public:
    Vlist();
    ~Vlist();

    void insert(string title, string url, string comment, float length, int rating);
    void printList();
    void listLength()
    {
      cout << m_length << endl;
    }
    void removeTitle(string title);
    bool findVideo(string title);
    void lookup(string title);

  // Private functions
  private:
    class Node
    {
      public:
        Node(Video *value, Node *next)
        {
          m_value = *value; m_next = next;
        }
        Video m_value{"", "", "", 0.0, 0};
        Node *m_next;
    };
    Node *m_head;
    int m_length;
};

#endif
