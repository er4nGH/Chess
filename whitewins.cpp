#include "whitewins.h"
#include "ui_whitewins.h"

Whitewins::Whitewins(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Whitewins)
{
    ui->setupUi(this);
    QPixmap pix(":/new/prefix1/Assets/White wins.jpg");
    ui->label->setPixmap(pix);
    ui->label->setScaledContents(true);
}

Whitewins::~Whitewins()
{
    delete ui;
}
