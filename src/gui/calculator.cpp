#include "calculator.h"
#include "ui_calculator.h"
#include "Parser.cpp"

QString host;
QString port;
QString term;


Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    //connect actions with events
    //Test button
    connect (ui->testconButton,SIGNAL(clicked()),this,
    SLOT(testConnection()));
    //Connect button
    connect (ui->makeconButton,SIGNAL(clicked()),this,SLOT(makeConnection()));
    //Submit button
    connect (ui->submitButton,SIGNAL(clicked()),
                this,SLOT(submitTerm()));
    //Input host
    connect (ui->hostInput,SIGNAL(textChanged(QString)),
             this,SLOT(checkConnection()));
    //Input port
    connect (ui->portInput,SIGNAL(valueChanged(int)),
             this,SLOT(checkConnection()));
    //Input term
    connect(ui->termInput,SIGNAL(textChanged(QString)),
            this,SLOT(checkTerm()));

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Calculator::testConnection()
{
    host = ui->hostInput->text();
    port = ui->portInput->value();

    if (host ==""||port =="")
    {
        QMessageBox::information(this,tr("Empty port or hostname"),tr("Please enter a hostname and a port"));
        ui->testconButton->setEnabled(false);
        return;
    }
    else
    {
        //test connection
        //if success set bconnected = true
        ui->makeconButton->setEnabled(true);
    }
}

void Calculator::makeConnection()
{
    //make a connection
    QMessageBox::information(this,tr("Connection success"),tr("Your connection was sucessfull"));
    //switch Tab view to calculator tab
    ui->tabWidget->setCurrentIndex(0);
}
void Calculator::submitTerm()
{
    term = ui->termInput->text();
    Parser* p = new Parser();

    //validate Term
   //string test = term.fromStdString( p->validate(term.toStdString()));
    QString test = term.fromStdString(p->validate(term.toStdString()));
   QMessageBox::information(this,tr("Connection success"),test);
   ui->termInput->setText(test);
    //submit term to server
}

void Calculator::checkConnection()
{
    host = ui->hostInput->text();
    if (!ui->testconButton->isEnabled()==true)
    {
        ui->testconButton->setEnabled(true);
    }
    if (host =="")
    {
        ui->testconButton->setEnabled(false);
    }
}

void Calculator::checkTerm()
{
    term = ui->termInput->text();
    if (! ui->submitButton->isEnabled()==true)
    {
        ui->submitButton->setEnabled(true);
    }
    if (term=="")
    {
        ui->submitButton->setEnabled(false);
    }

}
