#include "blackwins.h"
#include "ui_blackwins.h"

blackwins::blackwins(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::blackwins)
{
    ui->setupUi(this);
    QPixmap pix(":/new/prefix1/Assets/Black wins.jpg");
    ui->label->setPixmap(pix);
    ui->label->setScaledContents(true);
}

blackwins::~blackwins()
{
    delete ui;
}
