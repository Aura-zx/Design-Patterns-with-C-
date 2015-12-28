#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include <iostream>
class QuackBehavior
{
public:
	QuackBehavior( ){ };
	~QuackBehavior( ){ };

	virtual void quack( ) = 0;
private:

};

class Quack : public QuackBehavior
{
public:
	void quack( )	{std::cout << "quack! quack! quack! " << std::endl;}
};

class Squack : public QuackBehavior
{
public:
	void quack( ) { std::cout << "squack! squack! squack! " << std::endl; }
};

class MuteQuack : public QuackBehavior
{
public:
	void quack( ) { std::cout << "..." << std::endl; }
};
#endif // !QUACKBEHAVIOR_H
