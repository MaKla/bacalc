#include "calculator.h"
#include "ui_calculator.h"
#include "Parser.cpp"
#include "../client/client.cpp"

QString *host;
int *port;
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
    QString testhost = ui->hostInput->text();
    int testport = ui->portInput->value();

    if (testhost.length() <= 0 || testport <= 0)
    {
        QMessageBox::information(this,tr("Empty port or hostname"),tr("Please enter a hostname and a port"));
        ui->testconButton->setEnabled(false);
        return;
    }
    else
    {
        cout << port << endl;
        char* result = calc("3+4", (char*) testhost.toStdString().c_str(), testport);
        //test connection
        //if success set bconnected = true

        if (atoi(result) == 7)
        {
            QMessageBox::information(this,tr("Connection test success"),tr("Test sucessfull"));
            ui->makeconButton->setEnabled(true);
            *host = testhost;
            *port = testport;
        }
        else
        {
            QMessageBox::critical(this,tr("Connection failed"),tr("Connection failed, please verify host and port"));
        }


    }
}

void Calculator::makeConnection()
{
    ui->tabWidget->setCurrentIndex(0);
}
void Calculator::submitTerm()
{
    term = ui->termInput->text();
    Parser* p = new Parser();
    ostringstream result ;
    QString qstringResult ;
    //validate Term
   //string test = term.fromStdString( p->validate(term.toStdString()));
   QString validterm = term.fromStdString(p->validate(term.toStdString()));
   //send term to server
   char* tempresult = calc(
        (char*) validterm.toStdString().c_str(),
        (char*) (*host).toStdString().c_str(),
        *port
   );

   //cast char to QString
   result << tempresult ;

   qstringResult.fromStdString(result.str());
   //show result
   ui->termInput->setText(qstringResult);
    //submit term to server
}

void Calculator::checkConnection()
{
    *host = ui->hostInput->text();
    if (!ui->testconButton->isEnabled()==true)
    {
        ui->testconButton->setEnabled(true);
    }
    if (host->length() <= 0)
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
