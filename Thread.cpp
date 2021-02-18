#include "Thread.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std ;

string text[] = {"text1", "text2", "text3", "text4", "text5", "text6", "text7", "text8", "text9", "text10"} ;

Thread::Thread(string t,string g): theme(t),  generator(g) // constructor
{
	srand(time(NULL)) ;
	cout << " Thread with subject : " << this->theme << " has just been created!" << endl ; 
	for(int i = 0 ; i < this->postsNumber ; i++)
	{
		static int idCounter = 0 ; // giving to every post deferent id 
		this->posts[i] = new Post(idCounter, "title", "generator", text[rand()%9] ) ;
		idCounter++ ;
	}
}

Thread::~Thread() // destructor
{
	cout << " Thread with subject : " << this->theme << " is about to be destroyed" << endl ;
	for(int i = 0 ; i < this->postsNumber ; i++)
	{
		delete this->posts[i] ;
	}

}

void Thread::print() const // printing the theme, the generator, the date of creation and the posts of the thread 
{
	cout << " Theme : " << this->theme << endl <<
	" Generator : " << this->generator << endl <<
	" Date of creation : " ;
	this->dateOfCreation.printDate() ; 
	cout << endl ;
	cout << " Post of the thread : " << endl ;
	for(int i = 0 ; i < postsNumber ; i++) // prints all the posts of the thread
	{
		this->posts[i]->print() ; // prints the post
	}
}

string Thread::getTheme() const // returns the theme of the tread
{
	return this->theme ;
}

int Thread::getPostsNumber() const  // returns the number of the posts in that specific thread
{
	return this->postsNumber ; 
}

Post& Thread::getPost(int k) const  // returns reference to the k post of the array posts
{
	return *posts[k] ;
}

void Thread::printPost(int i) const  // prints the post with the specific id 
{
	for( int j = 0 ; j < this->getPostsNumber() ; j++)
	{
		this->posts[j]->findAndPrint(i) ;
	}
}