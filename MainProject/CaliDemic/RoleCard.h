
#ifndef PANDEMIC_1_1_ROLECARD_H
#define PANDEMIC_1_1_ROLECARD_H

#include <iostream>

enum RoleCardColors : int
{
	RCC_Teel,
	RCC_Brown,
	RCC_White,
	RCC_Pink,
	RCC_LightGreen,
	RCC_Orange,
	RCC_DarkGreen,
	RoleCardColors_Length
};


class RoleCard
{
private:
    std ::string roleCardname;
    int roleCardVal;
    RoleCardColors roleCardColour;
public:
	static std::string roleCardNames[7];

	RoleCard();
	RoleCard(const std::string &roleCardname);
	virtual ~RoleCard();


	///helper method to figure out the current roleCard player is given
	int getRoleCardNum();

    RoleCardColors getRoleCardColour() const;
	void setRoleCardColour(const RoleCardColors &roleCardColour);

    int getRoleCardVal() const;
    void setRoleCardVal(int roleCardVal);

    const std::string &getRoleCardname() const;
	void setRoleCardname(const std::string &roleCardname);
};

#endif //PANDEMIC_1_1_ROLECARD_H
