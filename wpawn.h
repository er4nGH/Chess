#ifndef WPAWN_H
#define WPAWN_H
#include<chessman.h>

class Wpawn:public Chessman
{
public:
    Wpawn();
    vector<QString> reachable(vector<Cell>, Cell) ;
};

#endif // WPAWN_H
