#ifndef QUEEN_H
#define QUEEN_H
#include<chessman.h>
class Queen:public Chessman
{
public:
    Queen();
    vector<QString> reachable(vector<Cell>, Cell) ;

};

#endif // QUEEN_H
