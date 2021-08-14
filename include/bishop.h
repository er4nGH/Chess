#ifndef BISHOP_H
#define BISHOP_H

#include<chessman.h>
class Bishop :public Chessman
{
public:
    Bishop();
    vector<QString> reachable(vector<Cell>, Cell) ;
};

#endif // BISHOP_H
