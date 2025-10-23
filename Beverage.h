#pragma once
#include <string>

using std::string;

//Абстрактный компонент
class Beverage
{
public:
	enum SIZE { SMALL, MEDIUM, LARGE };
protected:
	string description;
	SIZE size = SMALL;
public:
	
	virtual string getDescription() { return description; }
	virtual double cost() = 0;
	virtual ~Beverage() {}

	void setSize(SIZE sz) { size = sz; }
	SIZE getSize() { return size; }

};

//Абстрактный декоратор
class CondimentDecorator : public Beverage
{
protected:
	Beverage* bev;
public:
	virtual string getDescription() = 0;
	virtual ~CondimentDecorator() {}
};

//Конкретные напитки

class Espresso : public Beverage
{
public:
	Espresso() { description = "Espresso"; }
	double cost() { return 1.99; }
};

class HouseBlend : public Beverage
{
public:
	HouseBlend() { description = "HouseBlend"; }
	double cost() { return 0.89; }
};

//Конкретные декораторы

class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* b) { bev = b; }
	string getDescription() { return bev->getDescription() + " " + "Mocha"; }
	double cost() {
		double price = 0;
		switch (size)
		{
		case Beverage::SMALL:
			price = 0.20;
			break;
		case Beverage::MEDIUM:
			price = 0.40;
			break;
		case Beverage::LARGE:
			price = 0.55;
			break;
		}
		return bev->cost() + price; 
	}
};

class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* b) { bev = b; }
	string getDescription() { return bev->getDescription() + " " + "Soy"; }
	double cost() {
		double price = 0;
		switch (size)
		{
		case Beverage::SMALL:
			price = 0.15;
			break;
		case Beverage::MEDIUM:
			price = 0.30;
			break;
		case Beverage::LARGE:
			price = 0.45;
			break;
		}
		return bev->cost() + price; 
	}
};

class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* b) { bev = b; }
	string getDescription() { return bev->getDescription() + " " + "Whip"; }
	double cost() { 
		double price = 0;
		switch (size)
		{
		case Beverage::SMALL:
			price = 0.10;
			break;
		case Beverage::MEDIUM:
			price = 0.15;
			break;
		case Beverage::LARGE:
			price = 0.20;
			break;
		}
		return bev->cost() + price; 
	}
};

