#include "Observable.h"
#ifdef DEBUG
#include <assert.h>
#endif

void Observable::attach(Observer* observer)
{
#ifdef DEBUG
	// Ensure the given observer is not already null.
	assert(observer != nullptr);
	
	// Make sure the observer is not already contained in the collection, or null.
	for (unsigned int i = 0; i < this->_observers.size(); i++) {
		assert(this->_observers.at(i) != nullptr);
		assert(this->_observers.at(i) != observer);
	}
#endif

	// Add the observer to our collection.
	this->_observers.push_back(observer);
}

void Observable::detatch(Observer* observer)
{
#ifdef DEBUG
	// Ensure the given observer is not already null.
	assert(observer != nullptr);
#endif

	for (unsigned int i = 0; i < this->_observers.size(); i++) {
#ifdef DEBUG
		// Check to see if there are any bad observers in the collection.
		assert(this->_observers.at(i) != nullptr);
#endif
		// Remove the observer if it exists.
		if (this->_observers.at(i) == observer) {
			this->_observers.erase(this->_observers.begin() + i);
			break;
		}
	}

#ifdef DEBUG
	// Make sure the collection does not contain any duplicate observers, or null observers.
	for (unsigned int i = 0; i < this->_observers.size(); i++) {
		assert(this->_observers.at(i) != nullptr);
		assert(this->_observers.at(i) != observer);
	}
#endif
}

void Observable::notify()
{
	for (unsigned int i = 0; i < this->_observers.size(); i++) {
#ifdef DEBUG
		// Make sure the collection does not contain any null observers.
		assert(this->_observers.at(i) != nullptr);
		this->_observers.at(i)->update(this);
#endif
	}
}