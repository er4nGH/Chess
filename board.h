#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <vector>
#include "cell.h"
#include <string>
#include <QString>
#include <utility>
#include <map>
#include <QtDebug>
#include <QtWidgets>
#include<QMessageBox>
#include<chessman.h>
#include<qalgorithms.h>
#include<whitewins.h>
#include<blackwins.h>
#include<wpawn.h>
#include<bpawn.h>
#include<bishop.h>
#include <knight.h>
#include <queen.h>
#include <rock.h>

using namespace std;
namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:Ui::Board *ui;
    void initboard();
    void Docommand();
    bool whitecheck=false;
    bool blackcheck=false;
    QMessageBox msg;
    void setcommand(QString);
    void changeicon(QPushButton *,QPushButton *);
    vector<Cell> cellstorage;
    Whitewins w;
    blackwins b;
    struct paths{
        QPixmap Rpath;
        QPixmap Hpath;
        QPixmap Bpath;
        QPixmap Kpath;
        QPixmap Ppath;
        QPixmap Qpath;
    }white,black;

    QString fcell="";
    QString scell="";
    QString command;
    bool whiteturn=true;

private slots:
    void on_A1_clicked();
    void on_A2_clicked();
    void on_A3_clicked();
    void on_A4_clicked();
    void on_A5_clicked();
    void on_A6_clicked();
    void on_A7_clicked();
    void on_A8_clicked();

    void on_B1_clicked();
    void on_B2_clicked();
    void on_B3_clicked();
    void on_B4_clicked();
    void on_B5_clicked();
    void on_B6_clicked();
    void on_B7_clicked();
    void on_B8_clicked();

    void on_C1_clicked();
    void on_C2_clicked();
    void on_C3_clicked();
    void on_C4_clicked();
    void on_C5_clicked();
    void on_C6_clicked();
    void on_C7_clicked();
    void on_C8_clicked();

    void on_D1_clicked();
    void on_D2_clicked();
    void on_D3_clicked();
    void on_D4_clicked();
    void on_D5_clicked();
    void on_D6_clicked();
    void on_D7_clicked();
    void on_D8_clicked();

    void on_E1_clicked();
    void on_E2_clicked();
    void on_E3_clicked();
    void on_E4_clicked();
    void on_E5_clicked();
    void on_E6_clicked();
    void on_E7_clicked();
    void on_E8_clicked();

    void on_F1_clicked();
    void on_F2_clicked();
    void on_F3_clicked();
    void on_F4_clicked();
    void on_F5_clicked();
    void on_F6_clicked();
    void on_F7_clicked();
    void on_F8_clicked();

    void on_G1_clicked();
    void on_G2_clicked();
    void on_G3_clicked();
    void on_G4_clicked();
    void on_G5_clicked();
    void on_G6_clicked();
    void on_G7_clicked();
    void on_G8_clicked();

    void on_H1_clicked();
    void on_H2_clicked();
    void on_H3_clicked();
    void on_H4_clicked();
    void on_H5_clicked();
    void on_H6_clicked();
    void on_H7_clicked();
    void on_H8_clicked();

};

#endif // BOARD_H
