#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <string>
#include <QString>
#include <utility>
#include <map>
#include <QtDebug>
#include <QtWidgets>
#include<QMessageBox>

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

private:
    Ui::Board *ui;
    
};

#endif // BOARD_H
