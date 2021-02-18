#include "Forum.h"
#include <iostream>
#include <string>
#include "Post.h"
#include <ctime>
#include <cstdlib>
using namespace std ;

Forum::Forum(string n):forumName(n) // constructor
{
	cout << " Forum with title: " << this->forumName << " has just been created! " << endl << endl ;
	this->threads[0] = new Thread("Κανόνες και χρήσιμες πληροϕορίες", "generator") ; // creation of thread Κανόνες και χρήσιμες πληροϕορίες
	for(int i = 1 ; i < this->threadsNumber ; i++)
	{
		this->threads[i] = new Thread("theme", "generator") ;
	}
}

Forum::~Forum() // destructor
{
	cout << " Forum with title: " << this->forumName << " is about to be destroyed! " << endl ;
	for(int i = 0 ; i < this->threadsNumber ; i++)
	{
		delete this->threads[i] ;
	}
}

void Forum::printForum() const // prints the themes of threads
{
	for(int i=0 ; i < this->threadsNumber ; i++)
	{
		cout << " The " << i << " thread, has the title " << this->threads[i]->getTheme() << endl ;
	}
}

void Forum::printThread(string n) const // prints the thread with the specific theme 
{
	int i=0 ;
	while(this->threads[i]->getTheme() != n) // finding the thread with the specific theme 
		i++ ;
	this->threads[i]->print() ; // printing the thread
}

int  Forum::getThreadsNumber() const  // returns the number of the threads
{
	return this->threadsNumber ; 
}

void Forum::printPost(int i) const // prints the post with the specific id 
{
	for( int j = 0 ; j < this->getThreadsNumber() ; j++ )
	{
		this->threads[j]->printPost(i) ;
	}
}

void Forum::printRandomPost() const  // prints random posts
{
	srand(time(NULL)) ;
	int total = 0; // total number of posts
	int randomIdOfPost = 0 ;
	for (int i = 0; i < this->getThreadsNumber() ; i++) // calculating the total number of posts we have
	{
			total += threads[i]->getPostsNumber() ;
	}
	cout << " TOTAL NUMBER OF POSTS = " << total << endl ;
	int numberOfPosts = rand()%total; // random number of posts that we are going to print
	cout << " RANDOM NUMBER OF POSTS THAT WE ARE GOING TO PRINT = " << numberOfPosts << endl ;
	for(int j = 0 ; j < numberOfPosts ; j++ )
	{
		randomIdOfPost = rand()%total ; // random id of post we want to print
		cout << j << ") random id = " << randomIdOfPost << endl ;
		printPost(randomIdOfPost) ;
	}
}
