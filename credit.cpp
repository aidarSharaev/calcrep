#include "credit.h"
#include <QDebug>

credit::credit(QWidget* parent)
		: QWidget{parent}
	{
	QRegularExpression rx("\\d*");
	rxv = new QRegularExpressionValidator(rx, this);
	group = new QButtonGroup(this);
	sum = new QLineEdit(this);
	deadline = new QLineEdit(this);
	prozent = new QLineEdit(this);
	choiseA = new QRadioButton("Аннуитетный", this);
	choiseD = new QRadioButton("Дифференцированный", this);
	group->addButton(choiseD, 0);
	group->addButton(choiseA, 1);
	button = new QPushButton("РАССЧИТАТЬ", this);
	money = new QLineEdit(this);
	allSum = new QLineEdit(this);
	b_back = new QPushButton("НАЗАД", this);
	sum->setPlaceholderText("Сумма кредита");
	deadline->setPlaceholderText("Срок кредита");
	prozent->setPlaceholderText("Процентная ставка");
	money->setPlaceholderText("Ежемесячный платеж");
	allSum->setPlaceholderText("Сумма + долг");
	allSum->setReadOnly(true);
	money->setReadOnly(true);
	sum->setGeometry(QRect(60, 50, 150, 30));
	deadline->setGeometry(QRect(60, 100, 150, 30));
	prozent->setGeometry(QRect(60, 150, 150, 30));
	button->setGeometry(QRect(150, 250, 150, 30));
	money->setGeometry(QRect(150, 300, 150, 30));
	allSum->setGeometry(QRect(150, 350, 150, 30));
	b_back->setGeometry(QRect(380, 370, 50, 30));
	choiseA->setGeometry(QRect(80, 200, 150, 30));
	choiseD->setGeometry(QRect(250, 200, 150, 30));

//	sum->setValidator(rxv);
//	prozent->setValidator(rxv);
//	deadline->setValidator(rxv);

	QObject::connect(this->button,
									 SIGNAL(clicked()),
									 this,
									 SLOT(goA()));
}

credit::~credit()
{
delete rxv;
delete sum;
delete group;
delete deadline;
delete prozent;
delete choiseD;
delete choiseA;
delete button;
delete money;
delete allSum;
delete b_back;
}

void credit::goA()
{
if (sum->text().isEmpty() || deadline->text().isEmpty() || prozent->text().isEmpty())
	return;
emit annuitetnyu(sum->text(), deadline->text(), prozent->text());
}

void credit::goD()
{
if (sum->text().isEmpty() || deadline->text().isEmpty() || prozent->text().isEmpty())
	return;
emit differencirovannyu(sum->text(), deadline->text(), prozent->text());
}

void credit::annuitetnyu(QString s_sum, QString d_deadline, QString p_prozent)
{
if (s_sum.isEmpty() || d_deadline.isEmpty() || p_prozent.isEmpty())
	return;
long long ll_sum = s_sum.toLongLong();
int i_deadline = d_deadline.toInt();
int i_prozent = p_prozent.toInt();

double koef {static_cast<double>(i_prozent * 1.0 / (100.0 * i_prozent))};

double monthlyPayment = ll_sum * (koef) / (1 - pow(1 + (koef), -i_deadline));
qDebug() << i_prozent*1.0/100.0;

money->setText(QString::number(monthlyPayment));
monthlyPayment *= i_deadline;
allSum->setText(QString::number(monthlyPayment));
}

void credit::differencirovannyu(QString s_sum, QString d_deadline, QString p_prozent)
{

}


