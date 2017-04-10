#include "Subject.h"
#include "Observer.h"
#include <iostream>


Subject::Subject() {

}
Subject::~Subject() {
	
}
void Subject::attach(Observer* o) {
	_observers.push_back(o);
}
void Subject::detach(Observer* o) {
	for (unsigned int i = 0; i < this->_observers.size(); i++)
	{
		if ((this->_observers.at(i)) == o)
		{
			cout << "Observer " << this->_observers.at(i) << " deleted" << endl;
			this->_observers.erase(this->_observers.begin() + i);
		}
	}
}
void Subject::notify() {
	vector<Observer *>::iterator i = _observers.begin();
	for (; i != _observers.end(); ++i)
		(*i)->update();
}