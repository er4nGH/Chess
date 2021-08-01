#ifndef WHITEWINS_H
#define WHITEWINS_H

#include <QWidget>

namespace Ui {
class Whitewins;
}

class Whitewins : public QWidget
{
    Q_OBJECT

public:
    explicit Whitewins(QWidget *parent = nullptr);
    ~Whitewins();

private:
    Ui::Whitewins *ui;
};

#endif // WHITEWINS_H
