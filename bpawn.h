#ifndef BPAWN_H
#define BPAWN_H
#include<chessman.h>

class Bpawn:public Chessman
{
public:
    Bpawn();
    vector<QString> reachable(vector<Cell>, Cell) ;
};

#endif // BPAWN_H
