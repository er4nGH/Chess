#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/new/prefix1/Assets/Backgroundmenu.jpg");
    ui->Background->setPixmap(pix);
    ui->Background->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button1_clicked()
{
    Board.show();
    this->hide();
}

void MainWindow::on_Button2_clicked()
{
    Board2.show();
    this->hide();
}
