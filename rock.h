#ifndef ROCK_H
#define ROCK_H
#include<chessman.h>
class Rock:public Chessman
{
public:
    Rock();
    vector<QString> reachable(vector<Cell>, Cell) ;
};

#endif // ROCK_H
