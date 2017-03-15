for (int i=0; i < City::cubeMaxSize; i++){

//find any index with a value more than 0, indicating a disease
if (tempCity->cube[i] >= 0){

//if found make the slot to -1 indicating removal of cube
tempCity->cube[i] = -1;
//increment the board disease counter


int findColor = tempCity->color;
switch(findColor) {
case 0  :
cout << "Incrementing red cubes count of the game" << endl;
Game::numOfRedCube++;

break;
case 1 :
cout << "Incrementing blue cubes count of the game" << endl;
Game::numOfBlueCube++;

break;
case 2 :
cout << "Incrementing black cubes count of the game" << endl;
Game::numOfBlackCube++;

break;
case 3 :
cout << "Incrementing yellow cubes count of the game" << endl;
Game::numOfYellowCube++;

break;

}
cout << " A disease cube has been removed" << endl;
tempCity = nullptr;
break;
}
