#include "Post.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std ;

Post::Post(int i, string t, string g, string tex): id(i), title(t), generator(g), text(tex) // constructor
{
	cout << "\t" << " Just created post with:" << endl << endl << 
	 "\t\t" << " id: " << this->id << endl << 
	 "\t\t" << " title: " << this->title << endl << 
	 "\t\t" << " generator: " << this->generator << endl << 
	 "\t\t" << " date of creation: " ;
	 this->dateOfCreation.printDate() ; 
	 cout << "\t\t" << " and text: " << this->text << endl << endl ;
}

Post::~Post() // destructor
{
	cout << "Post number: " << this->id << " is about to be destroyed" << endl ;
}

void Post::print() const // prints the id, the title, the generator, the date of creation and the text of the post
{
	cout << "\t\t" << " id: " << this->id << endl << 
	 "\t\t" << " title: " << this->title << endl << 
	 "\t\t" << " generator: " << this->generator << endl << 
	 "\t\t" << " date of creation: " ;
	 this->dateOfCreation.printDate() ; 
	 cout << "\t\t" << " and text: " << this->text << endl << endl ;   
}

int Post::getId() const // returns the id of the specific post
{
	return this->id ;
}
void Post::findAndPrint(int i) const  // prints the post with the specific id 
{
	if(this->getId() == i)
	{
		this->print() ;
	}
}