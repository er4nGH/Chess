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
