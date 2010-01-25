#include "calculator.h"
#include "ui_calculator.h"
#include "parser.cpp"
#include "client.cpp"
#include <sstream>

QString host;
int port;
QString term;

const int gui_debug = 0;

Calculator::Calculator(QWidget *parent) :
	QWidget(parent), ui(new Ui::Calculator) {
	ui->setupUi(this);

	//connect actions with events
	//Test button
	connect(ui->testconButton, SIGNAL(clicked()), this, SLOT(testConnection()));
	//Connect button
	connect(ui->makeconButton, SIGNAL(clicked()), this, SLOT(makeConnection()));
	//Submit button
	connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submitTerm()));
	//Input host
	connect(ui->hostInput, SIGNAL(textChanged(QString)), this, SLOT(
			checkConnection()));
	//Input port
	connect (ui->portInput,SIGNAL(valueChanged(int)),
			this,SLOT(checkConnection()));
	//Input term
	connect(ui->termInput, SIGNAL(textChanged(QString)), this,
			SLOT(checkTerm()));

}

Calculator::~Calculator() {
	delete ui;
}

void Calculator::changeEvent(QEvent *e) {
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void Calculator::testConnection() {
	QString testhost = ui->hostInput->text();
	int testport = ui->portInput->value();

	if (testhost.length() <= 0 || testport <= 0) {
		QMessageBox::information(this, tr("Empty port or hostname"), tr(
				"Please enter a hostname and a port"));
		ui->testconButton->setEnabled(false);
		return;
	} else {
		cout << testport << endl;
		char* result = remote_calc("3+4",
				(char*) testhost.toStdString().c_str(), testport);

		//test connection
		//if success set bconnected = true

		if (atoi(result) == 7) {
			if (gui_debug) {
				cout << "show information box: connection test success" << endl;
			}
			QMessageBox::information(this, tr("Connection test success"), tr(
					"Test sucessfull"));

			ui->makeconButton->setEnabled(true);

			host = testhost;
			port = testport;
		} else {
			if (gui_debug) {
				cout << "show critical message box: connection failed" << endl;
			}
			QMessageBox::critical(this, tr("Connection failed"), tr(
					"Connection failed, please verify host and port"));
		}

	}
	if (gui_debug) {
		cout << "Leaving function Calculator::testConnection()" << endl;
	}
}

void Calculator::makeConnection() {
	ui->tabWidget->setCurrentIndex(0);
}
void Calculator::submitTerm() {
	if (gui_debug) {
		cout << "Entering function Calculator::submitTerm()" << endl;
	}
	term = ui->termInput->text();
	if (gui_debug) {
		cout << "Got term: " << term.toStdString() << endl;
	}
	Parser* p = new Parser();
	ostringstream result;
	QString qstringResult;

	//validate Term
	QString validterm = term.fromStdString(p->validate(term.toStdString()));
	if (gui_debug) {
		cout << "Validated term: " << term.toStdString() << endl;
	}
	cout << (char*) host.toStdString().c_str() << endl;
	cout << port << endl;
	//send term to server
	char* tempresult = remote_calc((char*) validterm.toStdString().c_str(),
			(char*) host.toStdString().c_str(), port);

	if (gui_debug) {
		cout << "Tempresult: " << tempresult << endl;
	}

	//cast char to QString
	result << tempresult;

	string casted_result = result.str();

	if (gui_debug) {
		cout << "casted_result: " << casted_result << endl;
	}
	qstringResult = QString::fromStdString(casted_result);
	if (gui_debug) {
		cout << "qstringResult: " << qstringResult.toStdString() << endl;
	}

	//show result
	ui->termInput->setText(qstringResult);
	//ui->termInput->insert(qstringResult);
	if (gui_debug) {
		cout << "termInput->text: " << ui->termInput->text().toStdString()
				<< endl;
	}

	//submit term to server
	if (gui_debug) {
		cout << "Leaving function Calculator::submitTerm()" << endl;
	}

}

void Calculator::checkConnection() {
	host = ui->hostInput->text();
	if (!ui->testconButton->isEnabled() == true) {
		ui->testconButton->setEnabled(true);
	}
	if (host.length() <= 0) {
		ui->testconButton->setEnabled(false);
	}
}

void Calculator::checkTerm() {
	term = ui->termInput->text();
	if (gui_debug) {
		cout << "Calculator::checkTerm() -> " << term.toStdString() << endl;
	}

	if (!ui->submitButton->isEnabled() == true) {
		ui->submitButton->setEnabled(true);
	}
	if (term == "") {
		ui->submitButton->setEnabled(false);
	}

}
