// main.cpp
// Fong, Madison
// mnfong

#include <iostream>
#include "video.h"
#include "vlist.h"

using namespace std;

int main()
{
  // Variables used in the program
  Vlist list;
  string command;
  string title;
  string url;
  string comment;
  float videoLen;
  int rating;

  // Asks for user/file input
  while (cin.peek() != EOF)
  {
    // Gets the command
    getline(cin, command);

    // Checks if the command is insert then adds the videos to the list if it is
    if (command == "insert")
    {
      getline(cin, title);
      getline(cin, url);
      getline(cin, comment);
      cin >> videoLen;
      cin >> rating;
      cin.ignore();
      list.insert(title, url, comment, videoLen, rating);
    }

    // Checks if the command is length and prints the length if it is
    else if (command == "length")
    {
      list.listLength();
    }

    // Checks if the command is print and prints the list if it is
    else if (command == "print")
    {
      list.printList();
    }

    // Checks if the command is lookup and looks up the title if it is
    else if (command == "lookup")
    {
      string tl;
      getline(cin, tl);
      list.lookup(tl);
    }

    // Checks if the command is remove and deletes the video from the list if it is
    else if (command == "remove")
    {
      string tl;
      getline(cin, tl);
      list.removeTitle(tl);
    }

    // If not any of the valid commands then gives error message
    else
    {
      cerr << "<" << command << "> is not a legal command, giving up." << endl;
      return 1;
    }
  }
  return 0;
}
