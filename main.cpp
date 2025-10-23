#include <iostream>
#include "Beverage.h"

using std::cout;
using std::endl;

int main()
{
	Beverage* b1 = new Espresso();
	b1 = new Whip(b1);
	b1->setSize(Beverage::LARGE);

	cout << b1->getDescription() << " " << b1->cost() << endl;


	return 0;
}