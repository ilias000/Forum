#ifndef POST_H
#define POST_H
#include <string>
#include "Date.h"
using namespace std ;

class Post
{
	int id  ;
	Date dateOfCreation ;
	string title, generator, text ;
public:
	Post(int, string, string, string) ; // constructor
	~Post() ; // destructor
	void print() const ; // prints the id, the title, the generator, the date of creation and the text of the post
	int getId() const ; // returns the id of the specific post
	void findAndPrint(int) const ; // prints the post with the specific id 
};
#endif