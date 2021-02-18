#ifndef THREAD_H
#define THREAD_H
#include <string>
#include "Post.h"
#include "Date.h"
using namespace std ;
#define POSTSNUMBER 10 ;


class Thread
{
	const static int postsNumber = POSTSNUMBER ;
	string theme, generator ;
	Date dateOfCreation ;
	Post *posts[postsNumber] ;
public:
	Thread(string, string) ; // constructor
	~Thread() ; // destructor
	void print() const ; // printing the theme, the generator, the date of creation and the posts of the thread 
	string getTheme() const ; // returns the theme of the thread
	int getPostsNumber() const ; // returns the number of the posts in that specific thread
	Post& getPost(int) const ; // returns reference to the k post of the array posts
	void printPost(int) const ; // prints the post with the specific id 
} ;
#endif