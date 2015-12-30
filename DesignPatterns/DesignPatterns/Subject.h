#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
class Subject
{
public:
	Subject( );
	~Subject( );

	Observer *ob;

	virtual void registerObserver(Observer *ob) = 0;
	virtual void removeObserver(Observer *ob) = 0;
	virtual void notifyObserver( ) = 0;
private:

};

Subject::Subject( )
{

}

Subject::~Subject( )
{
}
#endif // !SUBJECT_H
