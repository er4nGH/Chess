#ifndef CHESSMAN_H
#define CHESSMAN_H
#include<map>
#include<QString>
#include<cell.h>
#include <algorithm>


class Chessman
{
public:
    Chessman();
    virtual vector<QString> reachable(vector<Cell>, Cell)=0;
    virtual ~Chessman(){}
};

#endif // CHESSMAN_H
