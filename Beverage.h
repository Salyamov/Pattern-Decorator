#pragma once
#include <string>

using std::string;

//Абстрактный компонент
class Beverage
{
protected:
	string description;
public:
	virtual string getDescription() { return description; }
	virtual double cost() = 0;
	virtual ~Beverage() {}
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
	double cost() { return bev->cost() + 0.20; }
};

class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* b) { bev = b; }
	string getDescription() { return bev->getDescription() + " " + "Soy"; }
	double cost() { return bev->cost() + 0.15; }
};

class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* b) { bev = b; }
	string getDescription() { return bev->getDescription() + " " + "Whip"; }
	double cost() { return bev->cost() + 0.10; }
};

