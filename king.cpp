#include "king.h"

King::King()
{

}
vector<QString> King::reachable(vector<Cell> cell, Cell tc)
{
    int row=tc.getrow();
    int col=tc.getcol();
    vector<QString> temp;
    vector<pair<int,int>> canreach;
    //row+1 col
    int temprow=row+1;
    int tempcol=col;
    if((temprow>0&&tempcol>0)&&(temprow<9&&tempcol<9))
    {
        if(cell[(temprow-1)*8+(tempcol-1)].getpiece()=="")
        {
            canreach.push_back({temprow,tempcol});
        }
        else
        {
            if(cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
            {
                canreach.push_back({temprow,tempcol});
            }
        }
    }

    //row+1 col+1
    temprow=row+1;
    tempcol=col+1;
    if((temprow>0&&tempcol>0)&&(temprow<9&&tempcol<9))
    {
        if(cell[(temprow-1)*8+(tempcol-1)].getpiece()=="")
        {
            canreach.push_back({temprow,tempcol});
        }
        else
        {
            if(cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
            {
                canreach.push_back({temprow,tempcol});
            }
        }
    }
    //row+1 col-1
    temprow=row+1;
    tempcol=col-1;
    if((temprow>0&&tempcol>0)&&(temprow<9&&tempcol<9))
    {
        if(cell[(temprow-1)*8+(tempcol-1)].getpiece()=="")
        {
            canreach.push_back({temprow,tempcol});
        }
        else
        {
            if(cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
            {
                canreach.push_back({temprow,tempcol});
            }
        }
    }
    //row col+1
    temprow=row;
    tempcol=col+1;
    if((temprow>0&&tempcol>0)&&(temprow<9&&tempcol<9))
    {
        if(cell[(temprow-1)*8+(tempcol-1)].getpiece()=="")
        {
            canreach.push_back({temprow,tempcol});
        }
        else
        {
            if(cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
            {
                canreach.push_back({temprow,tempcol});
            }
        }
    }
    //row col-1
    temprow=row;
    tempcol=col-1;
    if((temprow>0&&tempcol>0)&&(temprow<9&&tempcol<9))
    {
        if(cell[(temprow-1)*8+(tempcol-1)].getpiece()=="")
        {
            canreach.push_back({temprow,tempcol});
        }
        else
        {
            if(cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
            {
                canreach.push_back({temprow,tempcol});
            }
        }
    }
    //row-1 col
    temprow=row-1;
    tempcol=col;
    if((temprow>0&&tempcol>0)&&(temprow<9&&tempcol<9))
    {
        if(cell[(temprow-1)*8+(tempcol-1)].getpiece()=="")
        {
            canreach.push_back({temprow,tempcol});
        }
        else
        {
            if(cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
            {
                canreach.push_back({temprow,tempcol});
            }
        }
    }
    //row-1 col+1
    temprow=row-1;
    tempcol=col+1;
    if((temprow>0&&tempcol>0)&&(temprow<9&&tempcol<9))
    {
        if(cell[(temprow-1)*8+(tempcol-1)].getpiece()=="")
        {
            canreach.push_back({temprow,tempcol});
        }
        else
        {
            if(cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
            {
                canreach.push_back({temprow,tempcol});
            }
        }
    }
    //row-1 col-1
    temprow=row-1;
    tempcol=col-1;
    if((temprow>0&&tempcol>0)&&(temprow<9&&tempcol<9))
    {
        if(cell[(temprow-1)*8+(tempcol-1)].getpiece()=="")
        {
            canreach.push_back({temprow,tempcol});
        }
        else
        {
            if(cell[(temprow-1)*8+(tempcol-1)].getcolor()!=tc.getcolor())
            {
                canreach.push_back({temprow,tempcol});
            }
        }
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


