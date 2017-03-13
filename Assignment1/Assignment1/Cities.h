#pragma once
#include <string>

class Cities{
private:
	int cube[3];
	bool research;
	std::string cityName;
	

public:
	Cities(std::string cityName);
	~Cities();
	int getCube();
	void infectCube();
	std::string display();
	std::string getCityName();
	bool getResearch();
	void setResearch(bool setting);
	
};
