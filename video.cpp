// Video.cpp
// Fong, Madison
// mnfong

#include <iostream>

using namespace std;

#include "video.h"

// Construts the Video
Video::Video(string tl, string address, string cmmnt, float vidlen, int rate)
  : title(tl), url(address), comment(cmmnt), videoLength(vidlen), rating(rate)
{
}

// Sets the number of stars to match the rating
void Video::numberOfStars(int rating)
{
  switch (rating)
  {
    case 1: stars = "*";
            break;
    case 2: stars = "**";
            break;
    case 3: stars = "***";
            break;
    case 4: stars = "****";
            break;
    case 5: stars = "*****";
            break;
    default: break;
  }
}

// Prints out the Video's title, url, comment, video length, and stars corresponding to the rating
void Video::print()
{
  numberOfStars(rating);
  cout << title << ", " << url << ", " << comment << ", " << videoLength << ", " << stars << endl;
}

// Returns the Video's title
string Video::getTitle()
{
  return title;
}

string Video::getURL()
{
  return url;
}

string Video::getComment()
{
  return comment;
}
// Returns the Video's rating
int Video::getRating()
{
  return rating;
}

// Return the Video's length
float Video::getLength()
{
  return videoLength;
}
