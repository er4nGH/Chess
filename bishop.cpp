#include "bishop.h"

Bishop::Bishop()
{

}
vector<QString> Bishop::reachable(vector<Cell> cell, Cell tc)
{

   int row=tc.getrow();
   int col=tc.getcol();
   vector<QString> temp;
   vector<pair<int,int>> canreach;
   bool con=true;
   //up right row+1 col+1
   for(int i=row+1,j=col+1;i<9 &&j<9 &&con==true ;i++,j++)
   {
       if((i-1)*8+(j-1)>-1&&(i-1)*8+(j-1)<65)
       {
           if(cell[(i-1)*8+(j-1)].getpiece()=="")
           {
               canreach.push_back({i,j});
           }
           else
           {
               if(cell[(i-1)*8+(j-1)].getcolor()!=tc.getcolor())
               {
                   canreach.push_back({i,j});
                   con=false;
               }
               else
               {
                   con=false;
               }
           }
       }
   }
   //up left row+1 col-1
   con=true;
   for(int i=row+1,j=col-1;i<9 &&j>0 &&con==true ;i++,j--)
   {
       if((i-1)*8+(j-1)>-1&&(i-1)*8+(j-1)<65)
       {
           if(cell[(i-1)*8+(j-1)].getpiece()=="")
           {
               canreach.push_back({i,j});
           }
           else
           {
               if(cell[(i-1)*8+(j-1)].getcolor()!=tc.getcolor())
               {
                   canreach.push_back({i,j});
                   con=false;
               }
               else
               {
                   con=false;
               }
           }
       }
   }
   //down right row-1 col+1
   con=true;
   for(int i=row-1,j=col+1;i>0 &&j<9 &&con==true ;i--,j++)
   {
       if((i-1)*8+(j-1)>-1&&(i-1)*8+(j-1)<65)
       {
           if(cell[(i-1)*8+(j-1)].getpiece()=="")
           {
               canreach.push_back({i,j});
           }
           else
           {
               if(cell[(i-1)*8+(j-1)].getcolor()!=tc.getcolor())
               {
                   canreach.push_back({i,j});
                   con=false;
               }
               else
               {
                   con=false;
               }
           }
       }
   }
   //down left row-1 col-1
   con=true;
   for(int i=row-1,j=col-1;i>0 &&j>0 &&con==true ;i--,j--)
   {
       if((i-1)*8+(j-1)>-1&&(i-1)*8+(j-1)<65)
       {
           if(cell[(i-1)*8+(j-1)].getpiece()=="")
           {
               canreach.push_back({i,j});
           }
           else
           {
               if(cell[(i-1)*8+(j-1)].getcolor()!=tc.getcolor())
               {
                   canreach.push_back({i,j});
                   con=false;
               }
               else
               {
                   con=false;
               }
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
