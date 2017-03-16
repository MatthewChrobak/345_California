//
//

#include "PlayerView.h"

int PlayerView :: observerID =0;

void PlayerView::update(Pawn *pwn, RoleCard *rc, ReferenceCard *refC, vector<PlayerCard *> pc) {

    std :: cout << "\nObserver ID  #" << observerID << " , detected change " << endl;
    std:: cout << " Updated using player setter... " << std :: endl;
}

PlayerView::PlayerView(Subject *playerView) : playerView(playerView) {

    this->observerID++;
    std :: cout << "Observer ID  #" << observerID << endl;

    playerView->registerr(this);

}

