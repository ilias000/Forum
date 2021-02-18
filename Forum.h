#ifndef FORUM_H
#define FORUM_H
#include <string>
using namespace std;
#include "Thread.h"
#define THREADSNUMBER 10;


class Forum
{
	const static int threadsNumber = THREADSNUMBER ;
	string forumName ;
	Thread *threads[threadsNumber] ;
public:
	Forum(string) ; // constructor
	~Forum() ; // destructor
	void printForum() const ; // prints the themes of threads
	void printThread(string) const ; // prints the thead with the specific theme 
	int getThreadsNumber() const ; // returns the number of the threads
	void printPost(int) const ; // prints the post with the specific id 
	void printRandomPost() const ; // prints random posts
} ;
#endif