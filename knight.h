#ifndef KNIGHT_H
#define KNIGHT_H
#include<chessman.h>

class Knight: public Chessman
{
public:
    Knight();
    vector<QString> reachable(vector<Cell>, Cell) ;

};

#endif // KNIGHT_H
