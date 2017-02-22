//
//

#ifndef PANDEMIC_1_1_ROLECARD_H
#define PANDEMIC_1_1_ROLECARD_H

#include <iostream>


class RoleCard {

private:
    //only the name of the card...each card will contain its own methods
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

    //helper method to figure out the current roleCard player is given
    int getRoleCardNum();

    void setRoleCardname(const std::string &roleCardname);

    friend std::ostream &operator<<(std::ostream &os, const RoleCard &card);

    //Discription of the current role card
    void roleCardDesc();

    //useRoleCard Calls the methods, according to the role card Value
    void useRoleCard();



    //methods for roleCards
    void useTheContingencyPlanner ();
    void useResearcher();
    void useScientist();
    void useDispatcher();
    void useOperationsExpert();
    void useMedic();
    void useContainmentSpecialist();


};




#endif //PANDEMIC_1_1_ROLECARD_H
