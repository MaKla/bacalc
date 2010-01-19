#include "qtguicalculator.h"
#include "ui_qtguicalculator.h"


QString host;
QString port;
QString term;


qtGuiCalculator::qtGuiCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qtGuiCalculator)
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

qtGuiCalculator::~qtGuiCalculator()
{
    delete ui;
}

void qtGuiCalculator::changeEvent(QEvent *e)
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

void qtGuiCalculator::testConnection()
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
        //if success set enable connection button

    }

}

void qtGuiCalculator::makeConnection()
{
    //make a connection
}

void qtGuiCalculator::submitTerm()
{
//submit term to server
}


void qtGuiCalculator::checkConnection()
{
    host = ui->hostInput->text();
    if (!ui->testconButton->isEnabled()==true)
    {
        ui->testconButton->setEnabled(true);
    }
    if (host=="")
    {
        ui->testconButton->setEnabled(false);
    }

}

void qtGuiCalculator::checkTerm()
{
    term =ui->termInput->text();
    if (! ui->submitButton->isEnabled()==true ||  term > "")
    {
        ui->submitButton->setEnabled(true);
    }
    if (term =="")
    {
        ui->submitButton->setEnabled(false);
    }

}
