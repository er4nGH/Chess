#ifndef CELL_H
#define CELL_H

#include<string>
#include<QDebug>
#include <QString>
using namespace std;
class Cell
{
public:
    Cell(int,int);
    QString getpiece();
    void setpiece(QString);
    int getrow();
    int getcol();
    QString getrelatedbutton();
    QString getcolor();
    int getindex();

private:
    QString piece;// "BR" "BQ" "BP" "BB" "BK' "BH" or "WR" "WQ" ...... and "" if empty
    int row;
    int col;
    void setcolor();
    QString color;
    QString relatedbutton;
    void setrelatedbutton(int,int);


};

#endif // CELL_H
