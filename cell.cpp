#include "cell.h"

Cell::Cell(int a,int b)
{
    if((a>0&&b>0)&&(a<9&&b<9))
    {
        row=a;
        col=b;
        setrelatedbutton(row,col);
    }
}
void Cell::setcolor()
{
    if(piece=="")
    {
        color="none";
    }
    color = piece[0];
}
int Cell::getindex()
{
    int a= (row-1)*8;
    int b= col-1;
    return a+b;
}
QString Cell::getcolor()
{
    return color;
}
void Cell::setpiece(QString p)
{
    piece=p;
    setcolor();
}

QString Cell::getpiece()
{
    return piece;
}
int Cell::getrow()
{
    return row;
}
int Cell::getcol()
{
    return col;
}

void Cell::setrelatedbutton(int r,int c)
{
    QString temp="";
    switch (c) {
    case 1:
        temp+="A";
        break;
    case 2:
        temp+="B";
        break;
    case 3:
        temp+="C";
        break;
    case 4:
        temp+="D";
        break;
    case 5:
        temp+="E";
        break;
    case 6:
        temp+="F";
        break;
    case 7:
        temp+="G";
        break;
    case 8:
        temp+="H";
        break;
    }
    temp+=QString::number(r);
    relatedbutton =temp;
}

QString Cell::getrelatedbutton()
{
    return relatedbutton;
}



