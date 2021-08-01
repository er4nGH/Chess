#include "bpawn.h"

Bpawn::Bpawn()
{

}

vector<QString> Bpawn::reachable(vector<Cell> cell, Cell tc)
{
    int row=tc.getrow();
    int col=tc.getcol();
    vector<QString> temp;
    vector<pair<int,int>> canreach;
    if(row==7 && cell[(row-3)*8+(col-1)].getpiece()=="")
    {
        canreach.push_back({row-2,col});
    }
    if(cell[(row-2)*8+(col-1)].getpiece()=="")
    {
        canreach.push_back({row-1,col});
    }
    int temprow=row-1;
    int tempcol=col+1;
    if(cell[(temprow-1)*8+(tempcol-1)].getpiece()!=""&&cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
    {
        canreach.push_back({temprow,tempcol});
    }
    temprow=row-1;
    tempcol=col-1;
    if(cell[(temprow-1)*8+(tempcol-1)].getpiece()!=""&&cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
    {
        canreach.push_back({temprow,tempcol});
    }
    for(auto c:cell)
    {
        for(auto r:canreach)
        {
            if(r.first==c.getrow()&&r.second==c.getcol())
            {
                temp.push_back(c.getrelatedbutton());
            }
        }
    }

    return temp;

}
