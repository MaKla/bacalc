#ifndef Calculator_H
#define Calculator_H

#include <QWidget>
#include <QMessageBox>
#include <sstream>
namespace Ui {
    class Calculator;
}

class Calculator : public QWidget {
    Q_OBJECT
public:
    Calculator(QWidget *parent = 0);
    ~Calculator();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Calculator *ui;

//action handler
public slots:
    void testConnection();
    void makeConnection();
    void submitTerm();
    void checkConnection();
    void checkTerm();

};

#endif // Calculator_H
