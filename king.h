#ifndef KING_H
#define KING_H
#include<chessman.h>
class King:public Chessman
{
public:
    King();
    vector<QString> reachable(vector<Cell>, Cell) ;
};

#endif // KING_H
