// Video.h
// Fong, Madison
// mnfong

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>

using namespace std;

class Video
{
  // Variables used to define a Video
  private:
    string title;
    string url;
    string comment;
    float videoLength;
    int rating;
    string stars;

  public:
    // Video constructor
    Video(string tl, string address, string cmmnt, float vidlen, int rate);
    // Prints the video's title, url, comment, length, and rating in stars
    void print();
    // Returns the video's title
    string getTitle();
    // Returns the video's url
    string getURL();
    // Returns the video's comment
    string getComment();
    // Returns the video's rating
    int getRating();
    // Returns the video's length
    float getLength();
    // Sets number stars based on rating
    void numberOfStars(int rating);
};

#endif
