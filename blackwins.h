#ifndef BLACKWINS_H
#define BLACKWINS_H

#include <QWidget>

namespace Ui {
class blackwins;
}

class blackwins : public QWidget
{
    Q_OBJECT

public:
    explicit blackwins(QWidget *parent = nullptr);
    ~blackwins();

private:
    Ui::blackwins *ui;
};

#endif // BLACKWINS_H
