#pragma once
#include "Cities.h"
#include <iostream>
using namespace std;

/*
getting the number of cube infected in the selected city
*/
int Cities::getCube(){
	int counter = 0;
	for (int i = 0; i < 3; i++){
		if (cube[i] == 1){
			counter++;
		}
	}

	return counter;
	
}
/*
function to infect city
*/
void Cities::infectCube(){
	for (int i = 0; i < 3; i++){
		if (cube[i] == 0){
			cube[i] = 1;
			break;
		}
	}
}
/*
This will display if the city is infected or not
*/
std::string Cities::display(){

	for (int i = 0; i < 3; i++){
		if (cube[i] == 1)
			return this->cityName + " is infected ";	
	}
	return this->cityName + " is not infected";
}
/*
Constructor
*/
Cities::Cities(std::string cityName){
	this->cityName = cityName;
	this->research = false;
	for (int i = 0; i < 3; i++){
		this->cube[i] = 0;
	}
}
/*
return the name of the city
*/
std::string Cities::getCityName(){
	return this->cityName;
}
/*
return if the city has a research center
*/
bool Cities::getResearch(){
	return this->research;
}
/*
set the city's research center
*/
void Cities::setResearch(bool setting){
	this->research = setting;
}

