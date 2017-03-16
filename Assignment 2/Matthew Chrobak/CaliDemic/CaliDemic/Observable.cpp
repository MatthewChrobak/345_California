#include "Observable.h"
#include <iostream>

void Observable::attach(Observer* observer)
{
	this->_observers.push_back(observer);
}


void Observable::detach(Observer* observer)
{
	// Loop through all observer and check if it's in the vector.
	for (unsigned int i = 0; i < this->_observers.size(); i++) {

		if (this->_observers.at(i) == nullptr) {
			this->_observers.erase(this->_observers.begin() + i--);
			std::cout << "Removed a null observer " << std::endl;
			continue;
		}

		if (this->_observers.at(i) == observer) {
			this->_observers.erase(this->_observers.begin() + i--);
			std::cout << "Removed observer " << observer << std::endl;
		}
	}
}

void Observable::notify()
{
	for (unsigned int i = 0; i < this->_observers.size(); i++) {
		if (this->_observers.at(i) != nullptr) {
			this->_observers.at(i)->update();
		}
	}
}