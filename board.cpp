#include "board.h"
#include "ui_board.h"


Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    QPixmap pix(":/new/prefix1/Assets/gwood.jpg");
    ui->Background->setPixmap(pix);
    ui->Background->setScaledContents(true);
    QPixmap pix2(":/new/prefix1/Assets/board.png");
    ui->board->setPixmap(pix2);
    ui->board->setScaledContents(true);
    initboard();
}

void Board::initboard()
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


    //create cells of board
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

void Board::changeicon(QPushButton *firstbt,QPushButton *secbt)
{
    secbt->setIcon(firstbt->icon());//change icon
    secbt->setIconSize(QSize(50,50));
    firstbt->setIcon(QIcon());//set first cell icon to nothing
}
bool Board::fcellvalidation(QString s)
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
                return false;
            }
        }
    }
    return false;
}

bool Board::scellvalidation(QString s)
{
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
void Board::check()
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
    if(whitecheck==true)
    {
        ui->label2->setText("white checked");
    }
    if(blackcheck==true)
    {
        ui->label2->setText("black checked");
    }
}
void Board::checkmate()
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
            ui->label2->setText("Black wins");
            b.show();
            this->hide();

        }
        if(blackcheck==true)
        {
            ui->label2->setText("white wins");
            w.show();
            this->hide();
        }
    }
}
bool Board::is_safe_for_king(QString btname,QString color)
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
bool Board::will_king_remain_safe(QString fbtname,QString sbtname)
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
void Board::Docommand()
{
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
    check();
    if(whitecheck==true||blackcheck==true)
    {
        checkmate();
    }
}
void Board::setcommand(QString s)
{
    if(fcell=="")
    {
        if(fcellvalidation(s)==true)
        {
            fcell=s;
        }
        else
        {
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
            ui->textBrowser->append(command);
            Docommand();
            scell="";
            fcell="";
            if(whiteturn==true)
            {
                whiteturn=false;
                ui->label->setText("Black turn");
            }
            else
            {
                whiteturn=true;
                ui->label->setText("White turn");
            }
        }
        else
        {
            fcell="";
            msg.setText("invalid Move");
            msg.exec();
        }

    }
}

void Board::on_A1_clicked()
{
    setcommand("A1");
}
void Board::on_A2_clicked()
{
    setcommand("A2");
}
void Board::on_A3_clicked()
{
    setcommand("A3");
}
void Board::on_A4_clicked()
{
    setcommand("A4");
}
void Board::on_A5_clicked()
{
    setcommand("A5");
}
void Board::on_A6_clicked()
{
    setcommand("A6");
}
void Board::on_A7_clicked()
{
    setcommand("A7");
}
void Board::on_A8_clicked()
{
    setcommand("A8");
}


void Board::on_B1_clicked()
{
    setcommand("B1");
}
void Board::on_B2_clicked()
{
    setcommand("B2");
}
void Board::on_B3_clicked()
{
    setcommand("B3");
}
void Board::on_B4_clicked()
{
    setcommand("B4");
}
void Board::on_B5_clicked()
{
    setcommand("B5");
}
void Board::on_B6_clicked()
{
    setcommand("B6");
}
void Board::on_B7_clicked()
{
    setcommand("B7");
}
void Board::on_B8_clicked()
{
    setcommand("B8");
}
void Board::on_C1_clicked()
{
    setcommand("C1");
}
void Board::on_C2_clicked()
{
    setcommand("C2");
}
void Board::on_C3_clicked()
{
    setcommand("C3");
}
void Board::on_C4_clicked()
{
    setcommand("C4");
}
void Board::on_C5_clicked()
{
    setcommand("C5");
}
void Board::on_C6_clicked()
{
    setcommand("C6");
}
void Board::on_C7_clicked()
{
    setcommand("C7");
}
void Board::on_C8_clicked()
{
    setcommand("C8");
}
void Board::on_D1_clicked()
{
    setcommand("D1");
}
void Board::on_D2_clicked()
{
    setcommand("D2");
}
void Board::on_D3_clicked()
{
    setcommand("D3");
}
void Board::on_D4_clicked()
{
    setcommand("D4");
}
void Board::on_D5_clicked()
{
    setcommand("D5");
}
void Board::on_D6_clicked()
{
    setcommand("D6");
}
void Board::on_D7_clicked()
{
    setcommand("D7");
}
void Board::on_D8_clicked()
{
    setcommand("D8");
}
void Board::on_E1_clicked()
{
    setcommand("E1");
}
void Board::on_E2_clicked()
{
    setcommand("E2");
}
void Board::on_E3_clicked()
{
    setcommand("E3");
}
void Board::on_E4_clicked()
{
    setcommand("E4");
}
void Board::on_E5_clicked()
{
    setcommand("E5");
}
void Board::on_E6_clicked()
{
    setcommand("E6");
}
void Board::on_E7_clicked()
{
    setcommand("E7");
}
void Board::on_E8_clicked()
{
    setcommand("E8");
}
void Board::on_F1_clicked()
{
    setcommand("F1");
}
void Board::on_F2_clicked()
{
    setcommand("F2");
}
void Board::on_F3_clicked()
{
    setcommand("F3");
}
void Board::on_F4_clicked()
{
    setcommand("F4");
}
void Board::on_F5_clicked()
{
    setcommand("F5");
}
void Board::on_F6_clicked()
{
    setcommand("F6");
}
void Board::on_F7_clicked()
{
    setcommand("F7");
}
void Board::on_F8_clicked()
{
    setcommand("F8");
}
void Board::on_G1_clicked()
{
    setcommand("G1");
}
void Board::on_G2_clicked()
{
    setcommand("G2");
}
void Board::on_G3_clicked()
{
    setcommand("G3");
}
void Board::on_G4_clicked()
{
    setcommand("G4");
}
void Board::on_G5_clicked()
{
    setcommand("G5");
}
void Board::on_G6_clicked()
{
    setcommand("G6");
}
void Board::on_G7_clicked()
{
    setcommand("G7");
}
void Board::on_G8_clicked()
{
    setcommand("G8");
}
void Board::on_H1_clicked()
{
    setcommand("H1");
}
void Board::on_H2_clicked()
{
    setcommand("H2");
}
void Board::on_H3_clicked()
{
    setcommand("H3");
}
void Board::on_H4_clicked()
{
    setcommand("H4");
}
void Board::on_H5_clicked()
{
    setcommand("H5");
}
void Board::on_H6_clicked()
{
    setcommand("H6");
}
void Board::on_H7_clicked()
{
    setcommand("H7");
}
void Board::on_H8_clicked()
{
    setcommand("H8");
}


Board::~Board()
{
    delete ui;
}
