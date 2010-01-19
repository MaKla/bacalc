#ifndef QTGUICALCULATOR_H
#define QTGUICALCULATOR_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
    class qtGuiCalculator;
}

class qtGuiCalculator : public QWidget {
    Q_OBJECT
public:
    qtGuiCalculator(QWidget *parent = 0);
    ~qtGuiCalculator();

protected:
    void changeEvent(QEvent *e);
     bool connectStatus;
private:
    Ui::qtGuiCalculator *ui;

//action handler
public slots:
    void testConnection();
    void makeConnection();
    void submitTerm();
    void checkConnection();
    void checkTerm();

};

#endif // QTGUICALCULATOR_H
