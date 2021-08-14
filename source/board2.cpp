#include "board2.h"
#include "ui_board2.h"

Board2::Board2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board2)
{
    ui->setupUi(this);
    QPixmap pix(":/new/prefix1/Assets/gwood.jpg");
    ui->Background->setPixmap(pix);
    ui->Background->setScaledContents(true);
    QPixmap pix2(":/new/prefix1/Assets/board.png");
    ui->board->setPixmap(pix2);
    ui->board->setScaledContents(true);
    initBoard2();
}

void Board2::initBoard2()
{
    //fill path structs
    white.Rpath.load(":/new/prefix1/Assets/WR.png");
    white.Hpath.load(":/new/prefix1/Assets/WH.png");
    white.Bpath.load(":/new/prefix1/Assets/WB.png");
    white.Qpath.load(":/new/prefix1/Assets/WQ.png");
    white.Kpath.load(":/new/prefix1/Assets/WK.png");
    white.Ppath.load(":/new/prefix1/Assets/WP.png");

    black.Rpath.load(":/new/prefix1/Assets/BR.png");
    black.Hpath.load(":/new/prefix1/Assets/BH.png");
    black.Bpath.load(":/new/prefix1/Assets/BB.png");
    black.Qpath.load(":/new/prefix1/Assets/BQ.png");
    black.Kpath.load(":/new/prefix1/Assets/BK.png");
    black.Ppath.load(":/new/prefix1/Assets/BP.png");


    //create cells of Board2
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            Cell temp(i,j);
            temp.setpiece("");
            cellstorage.push_back(temp);
        }
    }

    //place pieces
    cellstorage[0].setpiece("WR");
    cellstorage[1].setpiece("WH");
    cellstorage[2].setpiece("WB");
    cellstorage[3].setpiece("WQ");
    cellstorage[4].setpiece("WK");
    cellstorage[5].setpiece("WB");
    cellstorage[6].setpiece("WH");
    cellstorage[7].setpiece("WR");
    for(size_t i=8;i<16;i++)
    {
        cellstorage[i].setpiece("WP");
    }
    for(size_t i=48;i<56;i++)
    {
        cellstorage[i].setpiece("BP");
    }
    cellstorage[56].setpiece("BR");
    cellstorage[57].setpiece("BH");
    cellstorage[58].setpiece("BB");
    cellstorage[59].setpiece("BQ");
    cellstorage[60].setpiece("BK");
    cellstorage[61].setpiece("BB");
    cellstorage[62].setpiece("BH");
    cellstorage[63].setpiece("BR");
    for(auto c:cellstorage)
    {
        if(c.getpiece()=="WR")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(white.Rpath);
            button->setIconSize(QSize(50,50));

        }
        else if(c.getpiece()=="WH")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(white.Hpath);
            button->setIconSize(QSize(50,50));
        }
        else if(c.getpiece()=="WB")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(white.Bpath);
            button->setIconSize(QSize(50,50));
        }
        else if(c.getpiece()=="WQ")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(white.Qpath);
            button->setIconSize(QSize(50,50));
        }
        else if(c.getpiece()=="WK")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(white.Kpath);
            button->setIconSize(QSize(50,50));
        }
        else if(c.getpiece()=="WP")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(white.Ppath);
            button->setIconSize(QSize(50,50));
        }
        if(c.getpiece()=="BR")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(black.Rpath);
            button->setIconSize(QSize(50,50));

        }
        else if(c.getpiece()=="BH")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(black.Hpath);
            button->setIconSize(QSize(50,50));
        }
        else if(c.getpiece()=="BB")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(black.Bpath);
            button->setIconSize(QSize(50,50));
        }
        else if(c.getpiece()=="BQ")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(black.Qpath);
            button->setIconSize(QSize(50,50));
        }
        else if(c.getpiece()=="BK")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(black.Kpath);
            button->setIconSize(QSize(50,50));
        }
        else if(c.getpiece()=="BP")
        {
            QPushButton *button = findChild<QPushButton *>(c.getrelatedbutton());
            button->setIcon(black.Ppath);
            button->setIconSize(QSize(50,50));
        }
    }
}

bool Board2::top_right_casteling()
{
    if(cellstorage[60].getpiece()=="BK"&&cellstorage[63].getpiece()=="BR"&&cellstorage[62].getpiece()==""&&cellstorage[61].getpiece()=="")
    {
        if(is_safe_for_king("G8","B")==true && is_safe_for_king("F8","B")==true&&black_king_moved==false&&black_right_rock_moved==false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}
bool Board2::top_left_casteling()
{
    if(cellstorage[60].getpiece()=="BK"&&cellstorage[56].getpiece()=="BR"&&cellstorage[57].getpiece()==""&&cellstorage[58].getpiece()==""&&cellstorage[59].getpiece()=="")
    {
        if(is_safe_for_king("D8","B")==true && is_safe_for_king("C8","B")==true&&black_king_moved==false&&black_left_rock_moved==false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}
bool Board2::down_right_casteling()
{
    if(cellstorage[4].getpiece()=="WK"&&cellstorage[7].getpiece()=="WR"&&cellstorage[6].getpiece()==""&&cellstorage[5].getpiece()=="")
    {
        if(is_safe_for_king("F1","W")==true && is_safe_for_king("G1","W")==true&&white_king_moved==false&&white_right_rock_moved==false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}
bool Board2::down_left_casteling()
{
    if(cellstorage[4].getpiece()=="WK"&&cellstorage[0].getpiece()=="WR"&&cellstorage[1].getpiece()==""&&cellstorage[2].getpiece()==""&&cellstorage[3].getpiece()=="")
    {
        if(is_safe_for_king("C1","W")==true && is_safe_for_king("D1","W")==true&&white_king_moved==false&&white_left_rock_moved==false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}

void Board2::changeicon(QPushButton *firstbt,QPushButton *secbt)
{
    secbt->setIcon(firstbt->icon());//change icon
    secbt->setIconSize(QSize(50,50));
    firstbt->setIcon(QIcon());//set first cell icon to nothing
}
bool Board2::fcellvalidation(QString s)
{
    for(auto c:cellstorage)
    {
        if(c.getrelatedbutton()==s)
        {
            if(whiteturn==true&&c.getcolor()=="W")
            {
                return true;
            }
            else if(whiteturn==false&&c.getcolor()=="B")
            {
                return true;
            }
            else
            {
                qDebug()<<"here"<<c.getcolor()<<whiteturn;
                return false;
            }
        }
    }
    return false;
}

bool Board2::scellvalidation(QString s)
{
    if(fcell=="E8"&&s=="G8")//top right casteling check
    {
        if(top_right_casteling()==true)
        {
            QPushButton *button1 = findChild<QPushButton *>("H8");//move rock
            QPushButton *button2 = findChild<QPushButton *>("F8");
            changeicon(button1,button2);
            cellstorage[63].setpiece("");
            cellstorage[61].setpiece("BR");
            return true;//king will be moved in Docommand
        }
        else
        {
            return false;
        }
    }
    if(fcell=="E8"&&s=="C8")//top left casteling check
    {
        if(top_left_casteling()==true)
        {
            QPushButton *button1 = findChild<QPushButton *>("A8");//move rock
            QPushButton *button2 = findChild<QPushButton *>("D8");
            changeicon(button1,button2);
            cellstorage[56].setpiece("");
            cellstorage[59].setpiece("BR");
            return true;//king will be moved in Docommand
        }
        else
        {
            return false;
        }
    }
    if(fcell=="E1"&&s=="G1")//Down right casteling check
    {
        if(down_right_casteling()==true)
        {
            QPushButton *button1 = findChild<QPushButton *>("H1");//move rock
            QPushButton *button2 = findChild<QPushButton *>("F1");
            changeicon(button1,button2);
            cellstorage[7].setpiece("");
            cellstorage[5].setpiece("WR");
            return true;//king will be moved in Docommand
        }
        else
        {
            return false;
        }
    }
    if(fcell=="E1"&&s=="C1")//Down left casteling check
    {
        if(down_left_casteling()==true)
        {
            QPushButton *button1 = findChild<QPushButton *>("A1");//move rock
            QPushButton *button2 = findChild<QPushButton *>("D1");
            changeicon(button1,button2);
            cellstorage[0].setpiece("");
            cellstorage[3].setpiece("WR");
            return true;//king will be moved in Docommand
        }
        else
        {
            return false;
        }
    }
    vector<QString>pos;
    QString temp;
    QString color;
    for(auto c:cellstorage)
    {
        if(c.getrelatedbutton()==fcell)
        {
            temp=c.getpiece();
            color=c.getcolor();
            if(temp=="WR"||temp=="BR")
            {
                Rock r;
                pos=r.reachable(cellstorage,c);
            }
            else if(temp=="WH"||temp=="BH")
            {
                Knight k;
                pos=k.reachable(cellstorage,c);
            }
            else if(temp=="WB"||temp=="BB")
            {
                Bishop b;
                pos=b.reachable(cellstorage,c);
            }
            else if(temp=="WQ"||temp=="BQ")
            {
                Queen q;
                pos=q.reachable(cellstorage,c);
            }
            else if(temp=="WK"||temp=="BK")
            {
                King q;
                pos=q.reachable(cellstorage,c);
            }
            else if(temp=="BP")
            {
                Bpawn q;
                pos=q.reachable(cellstorage,c);
            }
            else if(temp=="WP")
            {
                Wpawn q;
                pos=q.reachable(cellstorage,c);
            }
        }
    }
    bool con=true;
    if(temp!="WK"&&whitecheck==true)
    {
        if(will_king_remain_safe(fcell,s)==true)
        {
            con=true;
        }
        else
        {
            con=false;
        }
    }
    if(temp!="BK"&&blackcheck==true)
    {
        if(will_king_remain_safe(fcell,s)==true)
        {
            con=true;
        }
        else
        {
            con=false;
        }
    }
    auto c=std::find(pos.begin(),pos.end(),s);
    if(c !=pos.end()&&con==true)
    {
        if((temp=="WK"||temp=="BK"))
        {
            if(is_safe_for_king(s,color)==true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(will_king_remain_safe(fcell,s)==true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}
void Board2::check()
{
    QString wkingbt;
    QString bkingbt;
    for(auto c:cellstorage)
    {
        if(c.getpiece()=="WK")
        {
            wkingbt=c.getrelatedbutton();
        }
        if(c.getpiece()=="BK")
        {
            bkingbt=c.getrelatedbutton();
        }
    }
    if(is_safe_for_king(wkingbt,"W")==true)
    {
        whitecheck=false;
        ui->label2->setText("ongoing");
    }
    else
    {
        whitecheck=true;
    }
    if(is_safe_for_king(bkingbt,"B")==true)
    {
        blackcheck=false;
        ui->label2->setText("ongoing");
    }
    else
    {
        blackcheck=true;
    }
    checkmate();//new
    if(whitecheck==true)
    {
        ui->label2->setText("white checked");
        blackpoint+=10;//new
        ui->BP->setText(QString::number(blackpoint));//new
    }
    if(blackcheck==true)
    {
        ui->label2->setText("black checked");
        whitepoint+=10;//new
        ui->WP->setText(QString::number(whitepoint));//new
    }
}
void Board2::checkmate()
{
    QString color;
    map<QString,vector<QString>>pieces_and_moves;
    bool con=true;
    QString wkingbt;
    QString bkingbt;
    for(auto c:cellstorage)
    {
        if(c.getpiece()=="WK")
        {
            wkingbt=c.getrelatedbutton();
        }
        if(c.getpiece()=="BK")
        {
            bkingbt=c.getrelatedbutton();
        }
    }
    if(whitecheck==true)
    {
        color="W";
    }
    if(blackcheck==true)
    {
        color="B";
    }
    for(auto c:cellstorage)
    {
        if(c.getcolor()==color)
        {
            QString temp=c.getpiece();
            vector<QString>pos;
            QString rb=c.getrelatedbutton();
            if(temp=="WR"||temp=="BR")
            {
                Rock r;
                pos=r.reachable(cellstorage,c);
            }
            else if(temp=="WH"||temp=="BH")
            {
                Knight k;
                pos=k.reachable(cellstorage,c);
            }
            else if(temp=="WB"||temp=="BB")
            {
                Bishop b;
                pos=b.reachable(cellstorage,c);
            }
            else if(temp=="WQ"||temp=="BQ")
            {
                Queen q;
                pos=q.reachable(cellstorage,c);
            }
            else if(temp=="WK"||temp=="BK")
            {
                King q;
                pos=q.reachable(cellstorage,c);
            }
            else if(temp=="BP")
            {
                Bpawn q;
                pos=q.reachable(cellstorage,c);
            }
            else if(temp=="WP")
            {
                Wpawn q;
                pos=q.reachable(cellstorage,c);
            }
            pieces_and_moves.insert({rb,pos});
        }
    }
    for(auto m:pieces_and_moves)
    {
        for(auto s:m.second)
        {
            if(m.first==wkingbt)
            {
                if(is_safe_for_king(s,"W")==true)
                {
                    con=false;
                }
            }
            else if(m.first==bkingbt)
            {
                if(is_safe_for_king(s,"B")==true)
                {
                    con=false;
                }
            }
            else
            {
                if(will_king_remain_safe(m.first,s)==true)
                {
                    con=false;
                }
            }
        }
    }
    if(con==true)
    {
        if(whitecheck==true)
        {
            blackpoint+=50;//new
            if(whitepoint<blackpoint)//new
            {
                ui->label2->setText("Black wins");
                b.show();
                this->hide();
            }
            else if(blackpoint<whitepoint)//new
            {
                ui->label2->setText("white wins");
                w.show();
                this->hide();
            }
            else//new
            {
                msg.setText("Draw");
                msg.exec();
                this->hide();
            }
        }
        if(blackcheck==true)
        {
            whitepoint+=50;//new
            if(whitepoint<blackpoint)//new
            {
                ui->label2->setText("Black wins");
                b.show();
                this->hide();
            }
            else if(blackpoint<whitepoint)//new
            {
                ui->label2->setText("white wins");
                w.show();
                this->hide();
            }
            else//new
            {
                msg.setText("Draw");
                msg.exec();
                this->hide();
            }
        }
    }
}
bool Board2::is_safe_for_king(QString btname,QString color)
{
    vector<QString> underattack;
    int index=0;
    QString primarypiece;
    for(int i=0;i<64;i++)
    {
        if(cellstorage[i].getrelatedbutton()==btname)
        {
            if(color=="B")
            {
                primarypiece=cellstorage[i].getpiece();
                cellstorage[i].setpiece("BK");
                index=i;
            }
            if(color=="W")
            {
                primarypiece=cellstorage[i].getpiece();
                cellstorage[i].setpiece("WK");
                index=i;
            }
        }
    }
    for(auto c:cellstorage)
    {
        if(c.getpiece()!=""&&c.getcolor()!=color)
        {
            vector<QString> pos;
            QString piece=c.getpiece();
            if(piece=="WR"||piece=="BR")
            {
                Rock r;
                pos=r.reachable(cellstorage,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());

            }
            else if(piece=="WH"||piece=="BH")
            {
                Knight k;
                pos=k.reachable(cellstorage,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="WB"||piece=="BB")
            {
                Bishop b;
                pos=b.reachable(cellstorage,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="WQ"||piece=="BQ")
            {
                Queen q;
                pos=q.reachable(cellstorage,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="WK"||piece=="BK")
            {
                King q;
                pos=q.reachable(cellstorage,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="BP")
            {
                Bpawn q;
                pos=q.reachable(cellstorage,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="WP")
            {
                Wpawn q;
                pos=q.reachable(cellstorage,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
        }
    }
    cellstorage[index].setpiece(primarypiece);
    auto f=std::find(underattack.begin(),underattack.end(),btname);
    if(f==underattack.end())
    {
        return true;
    }
    else
    {

        return false;
    }
}
bool Board2::will_king_remain_safe(QString fbtname,QString sbtname)
{
    QString orginalpiece;
    QString color;
    QString kingbt;
    int firstindex=0;
    int secondindex=0;
    for(auto c: cellstorage)
    {
        if(c.getrelatedbutton()==fbtname)
        {
            orginalpiece=c.getrelatedbutton();
            color=c.getcolor();
            firstindex=c.getindex();
        }
        if(c.getrelatedbutton()==sbtname)
        {
            secondindex=c.getindex();
        }
    }
    vector<Cell> copy;
    for(auto c:cellstorage)
    {
        copy.push_back(c);
    }
    copy[firstindex].setpiece("");
    copy[secondindex].setpiece(orginalpiece);
    for(auto c:copy)
    {
        if(c.getpiece()=="WK"&&color=="W")
        {
            kingbt=c.getrelatedbutton();
        }
        if(c.getpiece()=="BK"&&color=="B")
        {
            kingbt=c.getrelatedbutton();
        }
    }
    vector<QString> underattack;
    for(auto c:copy)
    {
        if(c.getpiece()!=""&&c.getcolor()!=color)
        {
            vector<QString> pos;
            QString piece=c.getpiece();
            if(piece=="WR"||piece=="BR")
            {
                Rock r;
                pos=r.reachable(copy,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());

            }
            else if(piece=="WH"||piece=="BH")
            {
                Knight k;
                pos=k.reachable(copy,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="WB"||piece=="BB")
            {
                Bishop b;
                pos=b.reachable(copy,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="WQ"||piece=="BQ")
            {
                Queen q;
                pos=q.reachable(copy,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="WK"||piece=="BK")
            {
                King q;
                pos=q.reachable(copy,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="BP")
            {
                Bpawn q;
                pos=q.reachable(copy,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
            else if(piece=="WP")
            {
                Wpawn q;
                pos=q.reachable(copy,c);
                underattack.insert(underattack.end(), pos.begin(), pos.end());
            }
        }
    }
    auto f=std::find(underattack.begin(),underattack.end(),kingbt);
    if(f==underattack.end())
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Board2::draw()
{
    bool white_enough_power=false;
    bool black_enough_power=false;
    int white_bishop_knight_count=0; //impossible to win with 1 knight or 1 bishop and possible with
    int black_bishop_knight_count=0; // 2 knights or 2 bishops or (1 knight and 1 bishop)
    for(auto c:cellstorage)
    {
        if(c.getpiece()=="WB"||c.getpiece()=="WH")
        {
            white_bishop_knight_count++;
        }
        if(c.getpiece()=="BB"||c.getpiece()=="BH")
        {
            black_bishop_knight_count++;
        }
        if(c.getpiece()=="BR"||c.getpiece()=="BP"||c.getpiece()=="BQ")
        {
            black_enough_power=true;
        }
        if(c.getpiece()=="WR"||c.getpiece()=="WP"||c.getpiece()=="WQ")
        {
            white_enough_power=true;
        }
        if(c.getpiece()=="BR"||c.getpiece()=="BP"||c.getpiece()=="BQ")
        {
            black_enough_power=true;
        }
    }
    if(white_enough_power==false&&white_bishop_knight_count>1)
    {
        white_enough_power=true;
    }
    if(black_enough_power==false&&black_bishop_knight_count>1)
    {
        black_enough_power=true;
    }
    if(white_enough_power==false&&black_enough_power==false)
    {
        msg.setText("Draw");
        msg.exec();
        this->hide();
    }
}
void Board2::stalemate_draw()
{
    vector<QString>possible;
    vector<QString>kingmoves;
    if(whiteturn==false)
    {
        for(auto c:cellstorage)
        {
            QString temp=c.getpiece();
            vector<QString>pos;
            if(temp=="WR")
            {
                Rock r;
                pos=r.reachable(cellstorage,c);
            }
            else if(temp=="WH")
            {
                Knight k;
                pos=k.reachable(cellstorage,c);
            }
            else if(temp=="WB")
            {
                Bishop b;
                pos=b.reachable(cellstorage,c);
            }
            else if(temp=="WQ")
            {
                Queen q;
                pos=q.reachable(cellstorage,c);
            }
            else if(temp=="WP")
            {
                Wpawn q;
                pos=q.reachable(cellstorage,c);
            }
            possible.insert(possible.end(), pos.begin(), pos.end());
            if(temp=="WK")
            {
                King k;
                kingmoves=k.reachable(cellstorage,c);
                for(auto x:kingmoves)
                {
                    if(is_safe_for_king(x,"W")==true)
                    {
                        possible.push_back(x);
                    }
                }
            }
        }
    }
    else
    {
        for(auto c:cellstorage)
        {
            QString temp=c.getpiece();
            vector<QString>pos;
            QString rb=c.getrelatedbutton();
            if(temp=="BR")
            {
                Rock r;
                pos=r.reachable(cellstorage,c);
            }
            else if(temp=="BH")
            {
                Knight k;
                pos=k.reachable(cellstorage,c);
            }
            else if(temp=="BB")
            {
                Bishop b;
                pos=b.reachable(cellstorage,c);
            }
            else if(temp=="BQ")
            {
                Queen q;
                pos=q.reachable(cellstorage,c);
            }
            else if(temp=="BP")
            {
                Bpawn q;
                pos=q.reachable(cellstorage,c);
            }
            possible.insert(possible.end(), pos.begin(), pos.end());
            if(temp=="BK")
            {
                King k;
                kingmoves=k.reachable(cellstorage,c);
                for(auto x:kingmoves)
                {
                    if(is_safe_for_king(x,"B")==true)
                    {
                        possible.push_back(x);
                    }
                }
            }
        }
    }
    if(possible.size()==0)
    {
        msg.setText("Stalemate Draw");
        msg.exec();
        this->hide();
    }
}
void Board2::threat()
{
    vector<Cell> copy;
    QString piece;
    unsigned int index=0;
    unsigned int point=0;
    for(auto c:cellstorage)
    {
        copy.push_back(c);
    }
    for(int i=0;i<64;i++)
    {
            if(copy[i].getrelatedbutton()==fcell)
            {
                piece=copy[i].getpiece();
                copy[i].setpiece("");
            }
    }
    for(int i=0;i<64;i++)
    {
            if(copy[i].getrelatedbutton()==scell)
            {
                index=copy[i].getindex();
                copy[i].setpiece(piece);
            }
    }
    vector<QString>pos;
    if(copy[index].getpiece()=="BR"||copy[index].getpiece()=="WR")
    {
        Rock r;
        pos=r.reachable(copy,copy[index]);
    }
    else if(copy[index].getpiece()=="BH"||copy[index].getpiece()=="WH")
    {
        Knight k;
        pos=k.reachable(copy,copy[index]);
    }
    else if(copy[index].getpiece()=="BB"||copy[index].getpiece()=="WB")
    {
        Bishop b;
        pos=b.reachable(copy,copy[index]);
    }
    else if(copy[index].getpiece()=="BQ"||copy[index].getpiece()=="WQ")
    {
        Queen q;
        pos=q.reachable(copy,copy[index]);
    }
    else if(copy[index].getpiece()=="BP")
    {
        Bpawn q;
        pos=q.reachable(copy,copy[index]);
    }
    else if(copy[index].getpiece()=="WP")
    {
        Wpawn q;
        pos=q.reachable(copy,copy[index]);
    }
    for(auto s:pos)
    {
        for(auto c:copy)
        {
            if(c.getrelatedbutton()==s)
            {
                if(c.getpiece()=="")
                {

                }
                else if(c.getpiece()=="BK"||c.getpiece()=="WK")
                {

                }
                else if(c.getpiece()=="WP"||c.getpiece()=="BP")
                {
                    point+=1;
                }
                else if(c.getpiece()=="BQ"||c.getpiece()=="WQ")
                {
                    point+=5;
                }
                else
                {
                    point+=2;
                }
            }
        }
    }
    if(copy[index].getcolor()=="W")
    {
        whitepoint+=point;
        ui->WP->setText(QString::number(whitepoint));
    }
    else
    {
        blackpoint+=point;
        ui->BP->setText(QString::number(blackpoint));
    }

}
void Board2::killchessman()
{
    for(auto c:cellstorage)//kill enemy chessman point(new)
    {
        if(c.getrelatedbutton()==scell)
        {
            lastpiece=c.getpiece();
            if(c.getpiece()=="")
            {

            }
            else if(c.getpiece()=="WP"||c.getpiece()=="BP")
            {
                if(c.getcolor()=="B")
                {
                    whitepoint+=3;
                }
                else
                {
                    blackpoint+=3;
                }
            }
            else if(c.getpiece()=="WQ"||c.getpiece()=="BQ")
            {
                if(c.getcolor()=="B")
                {
                    whitepoint+=15;
                }
                else
                {
                    blackpoint+=15;
                }
            }
            else // piece = bishop or knight
            {
                if(c.getcolor()=="B")
                {
                    whitepoint+=8;
                }
                else
                {
                    blackpoint+=8;
                }
            }

        }
    }
    ui->BP->setText(QString::number(blackpoint));
    ui->WP->setText(QString::number(whitepoint));
}
void Board2::pawnpush()
{
    for(auto c:cellstorage)//Pawn push point (new)
    {
        if(c.getrelatedbutton()==fcell&&c.getpiece()=="WP")
        {
            for(auto s:cellstorage)
            {
                if(s.getrelatedbutton()==scell)
                {
                    if(s.getrow()>=5)
                    {
                        whitepoint+=3;
                        ui->WP->setText(QString::number(whitepoint));
                    }
                }
            }
        }
        if(c.getrelatedbutton()==fcell&&c.getpiece()=="BP")
        {
            for(auto s:cellstorage)
            {
                if(s.getrelatedbutton()==scell)
                {
                    if(s.getrow()<=4)
                    {
                        blackpoint+=3;
                        ui->BP->setText(QString::number(blackpoint));
                    }
                }
            }
        }
    }
}
void Board2::repeat()
{
    if(whiteturn==true&&whitecommands.empty()!=true)
    {
        QString lastfcell=command.mid(0,2);
        QString lastscell=command.mid(2,2);
        if(lastfcell==whitecommands.back().mid(2,2)&&lastscell==whitecommands.back().mid(0,2))
        {
            add_negative_point(2,'W');
        }
    }
    if(whiteturn==false&&blackcommands.empty()!=true)
    {
        QString lastfcell=command.mid(0,2);
        QString lastscell=command.mid(2,2);
        if(lastfcell==blackcommands.back().mid(2,2)&&lastscell==blackcommands.back().mid(0,2))
        {
            add_negative_point(2,'B');
        }
    }

}
void Board2::Docommand()
{
    if(fcell=="A1")
    {
        white_left_rock_moved=true;
    }
    if(fcell=="H1")
    {
        white_right_rock_moved=true;
    }
    if(fcell=="E1")
    {
        white_king_moved=true;
    }
    if(fcell=="A8")
    {
        black_left_rock_moved=true;
    }
    if(fcell=="H8")
    {
        black_right_rock_moved=true;
    }
    if(fcell=="E8")
    {
        black_king_moved=true;
    }
    killchessman();//new
    pawnpush();//new
    threat();//new
    QString piece;
    for(int i=0;i<64;i++)
    {
            if(cellstorage[i].getrelatedbutton()==fcell)
            {
                piece=cellstorage[i].getpiece();
                cellstorage[i].setpiece("");
            }
    }
    for(int i=0;i<64;i++)
    {
            if(cellstorage[i].getrelatedbutton()==scell)
            {
                cellstorage[i].setpiece(piece);
            }
    }
    QPushButton *button1 = findChild<QPushButton *>(fcell);
    QPushButton *button2 = findChild<QPushButton *>(scell);
    changeicon(button1,button2);
    for(int i=0;i<64;i++)
    {
            if(cellstorage[i].getrow()==1 && cellstorage[i].getpiece()=="BP")
            {
                cellstorage[i].setpiece("BQ");
                QPushButton *button = findChild<QPushButton *>(cellstorage[i].getrelatedbutton());
                button->setIcon(black.Qpath);
                button->setIconSize(QSize(50,50));
            }
            if(cellstorage[i].getrow()==8 && cellstorage[i].getpiece()=="WP")
            {
                cellstorage[i].setpiece("WQ");
                QPushButton *button = findChild<QPushButton *>(cellstorage[i].getrelatedbutton());
                button->setIcon(white.Qpath);
                button->setIconSize(QSize(50,50));
            }
    }
    scell="";//new
    fcell="";//new
    check();
   // if(whitecheck==true||blackcheck==true)
   // {
        //checkmate();
  //  }
    draw();
    stalemate_draw();
    repeat();//new
}
void Board2::setcommand(QString s)
{
    if(fcell=="")
    {
        if(fcellvalidation(s)==true)
        {
            fcell=s;
        }
        else
        {
            qDebug()<<"fcell error";
            msg.setText("invalid Move");
            msg.exec();
        }
    }
    else
    {
        if(scellvalidation(s)==true)
        {
            scell=s;
            command=fcell+scell;
            lastcommand=command;//new
            ui->textBrowser->append(command);
            Docommand();
            if(whiteturn==true)//new
            {
                whitecommands.push_back(command);//new
            }
            else
            {
                blackcommands.push_back(command);//new
            }
            //scell="";
            //fcell="";
            if(whiteturn==true)
            {
                whiteturn=false;
                ui->BSmove->setEnabled(true);//new
                ui->BUNDO->setEnabled(true);//new
                ui->WUndo->setEnabled(true);//new
                ui->label->setText("Black turn");
            }
            else
            {
                whiteturn=true;
                ui->WSmove->setEnabled(true);//new
                ui->BUNDO->setEnabled(true);//new
                ui->WUndo->setEnabled(true);//new
                ui->label->setText("White turn");
            }
        }
        else
        {
            fcell="";
            if(whiteturn==true)//new
            {
                add_negative_point(1,'W');
            }
            else//new
            {
                add_negative_point(1,'B');
            }
            msg.setText("invalid Move");
            msg.exec();
        }

    }
}
void Board2::add_negative_point(int p, char c)
{
    if(c=='W')
    {
        white_n_point+=p;
        ui->WN->setText(QString::number(white_n_point));
    }
    else if(c=='B')
    {
        black_n_point+=p;
        ui->BN->setText(QString::number(black_n_point));
    }
    random_move();
}
void Board2::random_move()
{
    if(white_n_point>=15)
    {
        add_negative_point(-15,'W');
        vector<QString>keys;
        vector<vector<QString>>reach;
        for(auto c:cellstorage)
        {
            vector<QString> pos;
            QString temp=c.getpiece();
            if(temp=="")
            {

            }
            else if(temp=="WR")
            {
                Rock r;
                pos=r.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
            else if(temp=="WH")
            {
                Knight k;
                pos=k.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
            else if(temp=="WB")
            {
                Bishop b;
                pos=b.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
            else if(temp=="WQ")
            {
                Queen q;
                pos=q.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
            else if(temp=="WP")
            {
                Wpawn q;
                pos=q.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
        }
        loop:
        int keyindex=random(0,keys.size()-1);
        int reachindex;
        if(reach[keyindex].size()!=0)
        {
            reachindex=random(0,reach[keyindex].size()-1);
        }
        else
        {
            goto loop;
        }
        setcommand(keys[keyindex]);
        setcommand(reach[keyindex][reachindex]);
    }
    if(black_n_point>=15)
    {
        add_negative_point(-15,'B');
        vector<QString>keys;
        vector<vector<QString>>reach;
        for(auto c:cellstorage)
        {
            vector<QString> pos;
            QString temp=c.getpiece();
            if(temp=="")
            {

            }
            else if(temp=="BR")
            {
                Rock r;
                pos=r.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
            else if(temp=="BH")
            {
                Knight k;
                pos=k.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
            else if(temp=="BB")
            {
                Bishop b;
                pos=b.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
            else if(temp=="BQ")
            {
                Queen q;
                pos=q.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
            else if(temp=="BP")
            {
                Bpawn q;
                pos=q.reachable(cellstorage,c);
                keys.push_back(c.getrelatedbutton());
                reach.push_back(pos);
            }
        }
        loop2:
        int keyindex=random(0,keys.size()-1);
        int reachindex;
        if(reach[keyindex].size()!=0)
        {
            reachindex=random(0,reach[keyindex].size()-1);
        }
        else
        {
            goto loop2;
        }
        QString temp;
        temp=keys[keyindex]+reach[keyindex][reachindex];
        setcommand(keys[keyindex]);
        setcommand(reach[keyindex][reachindex]);
    }

}
int Board2::random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}
void Board2::on_A1_clicked()
{
    setcommand("A1");
}
void Board2::on_A2_clicked()
{
    setcommand("A2");
}
void Board2::on_A3_clicked()
{
    setcommand("A3");
}
void Board2::on_A4_clicked()
{
    setcommand("A4");
}
void Board2::on_A5_clicked()
{
    setcommand("A5");
}
void Board2::on_A6_clicked()
{
    setcommand("A6");
}
void Board2::on_A7_clicked()
{
    setcommand("A7");
}
void Board2::on_A8_clicked()
{
    setcommand("A8");
}


void Board2::on_B1_clicked()
{
    setcommand("B1");
}
void Board2::on_B2_clicked()
{
    setcommand("B2");
}
void Board2::on_B3_clicked()
{
    setcommand("B3");
}
void Board2::on_B4_clicked()
{
    setcommand("B4");
}
void Board2::on_B5_clicked()
{
    setcommand("B5");
}
void Board2::on_B6_clicked()
{
    setcommand("B6");
}
void Board2::on_B7_clicked()
{
    setcommand("B7");
}
void Board2::on_B8_clicked()
{
    setcommand("B8");
}
void Board2::on_C1_clicked()
{
    setcommand("C1");
}
void Board2::on_C2_clicked()
{
    setcommand("C2");
}
void Board2::on_C3_clicked()
{
    setcommand("C3");
}
void Board2::on_C4_clicked()
{
    setcommand("C4");
}
void Board2::on_C5_clicked()
{
    setcommand("C5");
}
void Board2::on_C6_clicked()
{
    setcommand("C6");
}
void Board2::on_C7_clicked()
{
    setcommand("C7");
}
void Board2::on_C8_clicked()
{
    setcommand("C8");
}
void Board2::on_D1_clicked()
{
    setcommand("D1");
}
void Board2::on_D2_clicked()
{
    setcommand("D2");
}
void Board2::on_D3_clicked()
{
    setcommand("D3");
}
void Board2::on_D4_clicked()
{
    setcommand("D4");
}
void Board2::on_D5_clicked()
{
    setcommand("D5");
}
void Board2::on_D6_clicked()
{
    setcommand("D6");
}
void Board2::on_D7_clicked()
{
    setcommand("D7");
}
void Board2::on_D8_clicked()
{
    setcommand("D8");
}
void Board2::on_E1_clicked()
{
    setcommand("E1");
}
void Board2::on_E2_clicked()
{
    setcommand("E2");
}
void Board2::on_E3_clicked()
{
    setcommand("E3");
}
void Board2::on_E4_clicked()
{
    setcommand("E4");
}
void Board2::on_E5_clicked()
{
    setcommand("E5");
}
void Board2::on_E6_clicked()
{
    setcommand("E6");
}
void Board2::on_E7_clicked()
{
    setcommand("E7");
}
void Board2::on_E8_clicked()
{
    setcommand("E8");
}
void Board2::on_F1_clicked()
{
    setcommand("F1");
}
void Board2::on_F2_clicked()
{
    setcommand("F2");
}
void Board2::on_F3_clicked()
{
    setcommand("F3");
}
void Board2::on_F4_clicked()
{
    setcommand("F4");
}
void Board2::on_F5_clicked()
{
    setcommand("F5");
}
void Board2::on_F6_clicked()
{
    setcommand("F6");
}
void Board2::on_F7_clicked()
{
    setcommand("F7");
}
void Board2::on_F8_clicked()
{
    setcommand("F8");
}
void Board2::on_G1_clicked()
{
    setcommand("G1");
}
void Board2::on_G2_clicked()
{
    setcommand("G2");
}
void Board2::on_G3_clicked()
{
    setcommand("G3");
}
void Board2::on_G4_clicked()
{
    setcommand("G4");
}
void Board2::on_G5_clicked()
{
    setcommand("G5");
}
void Board2::on_G6_clicked()
{
    setcommand("G6");
}
void Board2::on_G7_clicked()
{
    setcommand("G7");
}
void Board2::on_G8_clicked()
{
    setcommand("G8");
}
void Board2::on_H1_clicked()
{
    setcommand("H1");
}
void Board2::on_H2_clicked()
{
    setcommand("H2");
}
void Board2::on_H3_clicked()
{
    setcommand("H3");
}
void Board2::on_H4_clicked()
{
    setcommand("H4");
}
void Board2::on_H5_clicked()
{
    setcommand("H5");
}
void Board2::on_H6_clicked()
{
    setcommand("H6");
}
void Board2::on_H7_clicked()
{
    setcommand("H7");
}
void Board2::on_H8_clicked()
{
    setcommand("H8");
}


Board2::~Board2()
{
    delete ui;
}



void Board2::on_WSmove_clicked()
{
    if(blackcheck==false&&whiteturn==false&&whitepoint>=15)
    {
        whitepoint-=15;
        whiteturn=true;
        ui->WP->setText(QString::number(whitepoint));
        ui->label->setText("white turn");
        ui->WSmove->setEnabled(false);
    }
    else
    {
        msg.setText("you cant do this");
        msg.exec();
    }
}

void Board2::on_BSmove_clicked()
{
    if(whitecheck==false&&whiteturn==true&&blackpoint>=15)
    {
        blackpoint-=15;
        whiteturn=false;
        ui->BP->setText(QString::number(blackpoint));
        ui->label->setText("black turn");
        ui->BSmove->setEnabled(false);
    }
    else
    {
        msg.setText("you cant do this");
        msg.exec();
    }
}

void Board2::on_BUNDO_clicked()
{
    if(whiteturn==true)
    {
        if(lastpiece=="F")
        {
            msg.setText("nothing moved yet");
            msg.exec();
        }
        else
        {
            QString lastfcell=blackcommands.back().mid(0,2);
            QString lastscell=blackcommands.back().mid(2,2);
            QString piece;
            for(int i=0;i<64;i++)
            {
                    if(cellstorage[i].getrelatedbutton()==lastscell)
                    {
                        piece=cellstorage[i].getpiece();
                        cellstorage[i].setpiece(lastpiece);
                    }
            }
            for(int i=0;i<64;i++)
            {
                    if(cellstorage[i].getrelatedbutton()==lastfcell)
                    {
                        cellstorage[i].setpiece(piece);
                    }
            }
            QPushButton *button1 = findChild<QPushButton *>(lastscell);
            QPushButton *button2 = findChild<QPushButton *>(lastfcell);
            changeicon(button1,button2);
            if(lastpiece=="WR")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(white.Rpath);
                button->setIconSize(QSize(50,50));
            }
            else if(lastpiece=="WH")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(white.Hpath);
                button->setIconSize(QSize(50,50));
            }
            else if(lastpiece=="WB")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(white.Bpath);
                button->setIconSize(QSize(50,50));
            }
            else if(lastpiece=="WQ")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(white.Qpath);
                button->setIconSize(QSize(50,50));
            }
            else if(lastpiece=="WP")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(white.Ppath);
                button->setIconSize(QSize(50,50));
            }
            whiteturn=false;
            ui->label->setText("Black turn");
            add_negative_point(5,'B');
            ui->BUNDO->setEnabled(false);
            ui->WUndo->setEnabled(false);
            ui->WSmove->setEnabled(false);
            fcell="";
            scell="";
        }
    }
    else
    {
        msg.setText("you cant do this now");
        msg.exec();
    }
}

void Board2::on_WUndo_clicked()
{
    if(whiteturn==false)
    {
        if(lastpiece=="F")
        {
            msg.setText("nothing moved yet");
            msg.exec();
        }
        else
        {
            QString lastfcell=whitecommands.back().mid(0,2);
            QString lastscell=whitecommands.back().mid(2,2);
            QString piece;
            for(int i=0;i<64;i++)
            {
                    if(cellstorage[i].getrelatedbutton()==lastscell)
                    {
                        piece=cellstorage[i].getpiece();
                        cellstorage[i].setpiece(lastpiece);
                    }
            }
            for(int i=0;i<64;i++)
            {
                    if(cellstorage[i].getrelatedbutton()==lastfcell)
                    {
                        cellstorage[i].setpiece(piece);
                    }
            }
            QPushButton *button1 = findChild<QPushButton *>(lastscell);
            QPushButton *button2 = findChild<QPushButton *>(lastfcell);
            changeicon(button1,button2);
            if(lastpiece=="BR")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(black.Rpath);
                button->setIconSize(QSize(50,50));
            }
            else if(lastpiece=="BH")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(black.Hpath);
                button->setIconSize(QSize(50,50));
            }
            else if(lastpiece=="BB")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(black.Bpath);
                button->setIconSize(QSize(50,50));
            }
            else if(lastpiece=="BQ")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(black.Qpath);
                button->setIconSize(QSize(50,50));
            }
            else if(lastpiece=="BP")
            {
                QPushButton *button = findChild<QPushButton *>(lastscell);
                button->setIcon(black.Ppath);
                button->setIconSize(QSize(50,50));
            }
            whiteturn=true;
            ui->label->setText("white turn");
            add_negative_point(5,'W'); 
            ui->WUndo->setEnabled(false);
            ui->BUNDO->setEnabled(false);
            ui->BSmove->setEnabled(false);
            fcell="";
            scell="";
        }
    }
    else
    {
        msg.setText("you cant do this now");
        msg.exec();
    }
}
