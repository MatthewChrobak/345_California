
#ifndef PANDEMIC_1_1_ROLECARD_H
#define PANDEMIC_1_1_ROLECARD_H

#include <iostream>


class RoleCard {
    ///only the name of the card...each card will contain its own methods

    //change
private:
    std ::string roleCardname;
    int roleCardVal;
    std :: string roleCardColour;
public:
    const std::string &getRoleCardColour() const;

    void setRoleCardColour(const std::string &roleCardColour);


    RoleCard(const std::string &roleCardname);

    virtual ~RoleCard();

    RoleCard();

    int getRoleCardVal() const;

    void setRoleCardVal(int roleCardVal);


    const std::string &getRoleCardname() const;

    ///helper method to figure out the current roleCard player is given
    ///@param
    int getRoleCardNum();

    void setRoleCardname(const std::string &roleCardname);



};




#endif //PANDEMIC_1_1_ROLECARD_H
