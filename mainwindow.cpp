#include "mainwindow.h"
#include "polish.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wgt = new QWidget(this);
    wgt->setGeometry(QRect(240, 60, 240, 360));

    wgt2 = new QWidget(this);
    wgt2->setGeometry(QRect(0, 60, 240, 360));

    qbl = new QGridLayout(wgt);
    qbl->setAlignment(Qt::AlignRight);
    qbl->setSpacing(0);

    qbl2 = new QGridLayout(wgt2);
    qbl2->setAlignment(Qt::AlignLeft);
    qbl2->setSpacing(0);

    font2 = new QFont("Comic Sans MS", 20, 200);
{
    QString number;
    const QSize btnSize = QSize(56, 58);
    for (int i = 0; i < 23; i++) {
        btn[i] = new QPushButton(this);
        btn[i]->setFont(*font2);
        if (i != 22)
            QObject::connect(this->btn[i], SIGNAL(clicked()), this, SLOT(change()));
        if (i < 12) {
            btn2[i] = new QPushButton(this);
            btn2[i]->setFixedSize(btnSize);
            btn2[i]->setFont(QFont("Comic Sans MS", 15, 200));
            if (i < 7)
                QObject::connect(this->btn2[i], SIGNAL(clicked()), this, SLOT(change()));
            if (i == 7 || i == 8)
                QObject::connect(this->btn2[i], SIGNAL(clicked()), this, SLOT(deleteSymbol()));
            number = QString::number(i);
            btn[i]->setText(number);
        }
        btn[i]->setFixedSize(btnSize);
    }
}
    {
        v = new QDoubleValidator(this);
        v->setBottom(-1000000.0);
        v->setTop(1000000.0);
        const QSize txtSize = QSize(110, 58);
        for (int i =0 ; i < 5;i++) {
            text2[i] = new QLineEdit(this);
            if (i != 4)
                text2[i]->setFixedSize(txtSize);
            text2[i]->setFont(QFont("Comic Sans MS", 8, 200));
            text2[i]->setValidator(v);
        }
    }

    btn[0]->setFixedSize(116,58);
    btn2[10]->setFixedSize(110,58);
    text2[4]->setFixedSize(167, 58);

    text2[0]->setPlaceholderText("-D byDef -1000000");
    text2[1]->setPlaceholderText("D byDef 1000000");
    text2[2]->setPlaceholderText("-E byDef -1000000");
    text2[3]->setPlaceholderText("E byDef 1000000");
    text2[4]->setPlaceholderText("XValue");
    text2[4]->setAlignment(Qt::AlignRight);

    qbl->addWidget(btn[19],0,0,1,1);
    qbl->addWidget(btn[20],0,1,1,1);
    qbl->addWidget(btn[21],0,2,1,1);
    qbl->addWidget(btn[18],0,3,1,1);
    qbl->addWidget(btn[16],1,0,1,1);
    qbl->addWidget(btn[17],1,1,1,1);
    qbl->addWidget(btn[15],1,2,1,1);
    qbl->addWidget(btn[14],1,3,1,1);
    qbl->addWidget(btn[7],2,0,1,1);
    qbl->addWidget(btn[8],2,1,1,1);
    qbl->addWidget(btn[9],2,2,1,1);
    qbl->addWidget(btn[13],2,3,1,1);
    qbl->addWidget(btn[4],3,0,1,1);
    qbl->addWidget(btn[5],3,1,1,1);
    qbl->addWidget(btn[6],3,2,1,1);
    qbl->addWidget(btn[12],3,3,1,1);
    qbl->addWidget(btn[1],4,0,1,1);
    qbl->addWidget(btn[2],4,1,1,1);
    qbl->addWidget(btn[3],4,2,1,1);
    qbl->addWidget(btn[11],4,3,1,1);
    qbl->addWidget(btn[0],5,0,1,2);
    qbl->addWidget(btn[10],5,2,1,1);
    qbl->addWidget(btn[22],5,3,1,1);

    btn[10]->setText(".");
    btn[11]->setText("+");
    btn[12]->setText("-");
    btn[13]->setText("*");
    btn[14]->setText("/");
    btn[15]->setText("%");
    btn[16]->setText("(");
    btn[17]->setText(")");
    btn[18]->setText("^(");
    btn[19]->setText("lg(");
    btn[20]->setText("ln(");
    btn[21]->setText("sqrt(");
    btn[22]->setText("=");

    qbl2->addWidget(text2[0], 0,0,1,2);
    qbl2->addWidget(btn2[7], 0,2,1,1);
    qbl2->addWidget(btn2[8], 0,3,1,1);

    qbl2->addWidget(text2[1], 1,0,1,2);
    qbl2->addWidget(btn2[4], 1,2,1,1);
    qbl2->addWidget(btn2[5], 1,3,1,1);

    qbl2->addWidget(text2[2], 2,0,1,2);
    qbl2->addWidget(btn2[2], 2,2,1,1);
    qbl2->addWidget(btn2[3], 2,3,1,1);

    qbl2->addWidget(text2[3], 3,0,1,2);
    qbl2->addWidget(btn2[0], 3,2,1,1);
    qbl2->addWidget(btn2[1], 3,3,1,1);

    qbl2->addWidget(btn2[10], 4,0,1,2);
    qbl2->addWidget(btn2[9], 4,2,1,2);
    qbl2->addWidget(btn2[6], 4,3,1,1);

    qbl2->addWidget(text2[4], 5,0,1,3);
    qbl2->addWidget(btn2[11], 5,3,1,1);

    btn2[0]->setText("sin(");
    btn2[1]->setText("asin(");
    btn2[2]->setText("cos(");
    btn2[3]->setText("acos(");
    btn2[4]->setText("tan(");
    btn2[5]->setText("atan(");
    btn2[6]->setText("x");
    btn2[7]->setText("⎚");
    btn2[8]->setText("⌫");
    btn2[9]->setText("GRP");
    btn2[10]->setText("CRDT");
    btn2[11]->setText("=x");

    font = new QFont("Monospace", 25, 200);

    text = new QLineEdit(this);
    text->setFont(*font);
    text->setGeometry(QRect(0, 0, 480, 60));
    text->setAlignment(Qt::AlignRight);
    text->setReadOnly(true);
    text->setPlaceholderText("i'm waiting..");
    text->setMaxLength(255);

    QObject::connect(this, SIGNAL(set_text(QString)), this->text, SLOT(setText(QString)));
    QObject::connect(this, SIGNAL(deleteText(QString)), this->text, SLOT(setText(QString)));
    QObject::connect(this, SIGNAL(calculator(QString)), this->text, SLOT(setText(QString)));
    QObject::connect(this->btn2[11], SIGNAL(clicked()), this, SLOT(calcX()));
    QObject::connect(this->btn[22], SIGNAL(clicked()), this, SLOT(goToCalc()));
    QObject::connect(this->btn2[9], SIGNAL(clicked()), this, SLOT(windowCreate()));

    wgt->show();
}

int MainWindow::bracketCounter = 0;
int MainWindow::xCounter = 0;
short MainWindow::flag = 0;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change()
{
    QPushButton* pbtn = dynamic_cast<QPushButton*>(QObject::sender());
    bool check = checkString(pbtn);
    if (check) { 
        mainStr = text->text() + pbtn->text();
        emit set_text(mainStr);
    }
}

bool MainWindow::checkString(QPushButton* pbtn)
{
    qDebug() << "(" << text2[0]->text() << ")";
    if (argList.isEmpty())
        argList.push_back(-1);

    int back = argList.back();
    int parametr = whatIsIt(pbtn);

    if (mainStr.isEmpty() && (parametr == RtrnVal::OPER || parametr == RtrnVal::CLOSE_BR || parametr == RtrnVal::DOT)) {
        return false;
    }
    if ((back == RtrnVal::OPEN_BR || back == RtrnVal::ODZ) && (parametr == RtrnVal::OPER || parametr == RtrnVal::DOT || parametr == RtrnVal::CLOSE_BR)) {
        return false;
    }
    if (back == RtrnVal::CLOSE_BR) {
        if (parametr == RtrnVal::OPER || parametr == RtrnVal::PM) {
        } else if (bracketCounter > 0){
        } else {
            return false;
        }
    }
    if ((back == RtrnVal::PM && parametr == RtrnVal::OPER) || (back == RtrnVal::OPER && parametr == RtrnVal::PM)) {
        return false;
    }
    if ((back == RtrnVal::IKS && parametr == RtrnVal::NUMBER) || (back == RtrnVal::NUMBER && parametr == RtrnVal::IKS)) {
        return false;
    }
    if ((back == RtrnVal::NUMBER || back == RtrnVal::IKS) && (parametr == RtrnVal::ODZ || parametr == RtrnVal::OPEN_BR)) {
        return false;
    }
    if ((back == RtrnVal::OPER || back == RtrnVal::PM) && (parametr == CLOSE_BR || back == parametr)) {
        return false;
    }
    if ((back == RtrnVal::DOT && parametr != RtrnVal::NUMBER) || (back == RtrnVal::IKS && parametr == RtrnVal::IKS)) {
        return false;
    }

    if (parametr == RtrnVal::DOT && back == RtrnVal::NUMBER && flag < 1) {
        ++flag;
    } else if (parametr == RtrnVal::NUMBER || parametr == RtrnVal::DOT) {
    } else {
        flag = 0;
    }

    if (parametr == RtrnVal::DOT) {
        if (!flag || flag >= 2)
            return false;
        if (back == RtrnVal::DOT){
            return false;
        }
        if (back != RtrnVal::NUMBER) {
            return false;
        }
        ++flag;
    }
    if (back == -1)
        argList.pop_back();
    argList.push_back(parametr);

    if (parametr == RtrnVal::OPEN_BR || parametr == RtrnVal::ODZ || pbtn->text() == "^(")
        bracketUp();
    if (parametr == RtrnVal::CLOSE_BR)
        bracketDown();

    if (bracketCounter < 0) return false;
    if (parametr == RtrnVal::IKS)
        ++xCounter;

    return true;
}

int MainWindow::whatIsIt(QPushButton* pbtn)
{
    QString arg = pbtn->text();
    if (arg.back() >= '0' && arg.back() <= '9')
        return RtrnVal::NUMBER;
    if (arg == "+" || arg == "-")
        return RtrnVal::PM;
    if (arg == "*" || arg == "/" || arg == "%" || arg == "^(")
        return RtrnVal::OPER;
    if (arg == "lg(" || arg == "ln(" || arg == "sqrt(")
        return RtrnVal::ODZ;
    if (arg == "sin(" || arg == "asin(" || arg == "cos(" || arg == "acos(" || arg == "tan(" || arg == "atan(")
        return RtrnVal::ODZ;
    if (arg == "(")
        return RtrnVal::OPEN_BR;
    if (arg == ")")
        return RtrnVal::CLOSE_BR;
    if (arg == ".")
        return RtrnVal::DOT;
    if (arg == "x")
        return RtrnVal::IKS;
    return RtrnVal::NUMBER;
}

void MainWindow::deleteSymbol()
{
    QPushButton* pbtn = dynamic_cast<QPushButton*>(QObject::sender());
    if (mainStr.isEmpty()) return;
    if (pbtn == btn2[8]) {
        if (argList.back() == RtrnVal::ODZ) {
            mainStr.chop(1);
            bracketDown();
            while (mainStr.back() >= 'a' && mainStr.back() <= 'z')
                mainStr.chop(1);
        } else if (argList.back() == RtrnVal::IKS) {
            --xCounter;
            mainStr.chop(1);
        } else if (argList.back() == RtrnVal::DOT) {
            --flag;
        argList.pop_back(); 
        }
    } else {
        bracketCounter = xCounter = 0;
        mainStr.clear();
        argList.clear();
        flag = 0;
    }
    emit deleteText(mainStr);
}

void MainWindow::goToCalc()
{
    if (bracketCounter) {;return;}
    if (xCounter > 0) {QMessageBox box; box.setText("enter the value x and press \'=x\'"); box.exec();return;}
}

void MainWindow::calcX()
{
    QString XString = "x";
    QString replaseString = text2[4]->text();
    qDebug() << text2[4]->text();
    if (!xCounter) {return;}
    else {
        mainStr = text->text();
        mainStr.replace(XString, replaseString);
        mainStr.replace(QString(","), QString("."));
        text->setText(mainStr);
        text2[4]->clear();
        emit goToCalc();
    }
}

void MainWindow::operator<<(QVector<int> vec)
{
    for(int &x:vec) {
        qDebug() << x << " ";
    }
}

void MainWindow::windowCreate()
{
   if (bracketCounter > 0)
       return;
   graphWindow = new GraphWindow();
   values = new QString[4];
   for (int i = 0; i < 4;i++) {
       values[i] = text2[i]->text();
   }
   graphWindow->setWindowModality(Qt::ApplicationModal);
   graphWindow->plot(values, xCounter, mainStr);
   graphWindow->show();
}
