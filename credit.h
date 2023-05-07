#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QValidator>

class credit : public QWidget
{
	Q_OBJECT
public:
	explicit credit(QWidget* parent = nullptr);
	~credit();

private:
	QButtonGroup* group;
	QLineEdit* sum;
	QLineEdit* deadline;
	QLineEdit* prozent;
	QRadioButton* choiseA;
	QRadioButton* choiseD;
	QPushButton* button;
	QLineEdit* money;
	QLineEdit* allSum;
	QPushButton* b_back;
	QValidator* rxv;
	void annuitetnyu(QString s_sum, QString d_deadline, QString p_prozent);
	void differencirovannyu(QString s_sum, QString d_deadline, QString p_prozent);

private slots:
	void goA();
	void goD();

};

#endif // CREDIT_H
