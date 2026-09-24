#include "standards.h"
#include "ui_standards.h"

#include <QRegularExpression>
#include <QDebug>
Standards::Standards(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::Standards)
{
    ui->setupUi(this);
    init();
}

Standards::~Standards()
{
    delete ui;
}

void Standards::init()
{
    EditMain_reset();
    btnNumbers = this->findChildren<QPushButton *>(QRegularExpression("^btn_number_.+$"));
    for (QPushButton *btn : btnNumbers)
        connect(btn, &QPushButton::released, this, &Standards::onNumberClicked);
    btnOperations = this->findChildren<QPushButton *>(QRegularExpression("^btn_operation_.+$"));
    for (QPushButton *btn : btnOperations)
        connect(btn, &QPushButton::released, this, &Standards::onOperationClicked);
}

void Standards::onNumberClicked()
{
    QString line = ui->Edit_Main->text();
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    if (btn)
    {
        QChar num = btn->property("number").toChar();
        if(num == '.')
        {
            if(!line.contains('.'))
                line += num;
        }
        else if(lastKey >= '0' || lastKey == '.')
        {
            if (line == "0")
                line = num;
            else
                line += num;
        }
        else
            line = num;
        ui->Edit_Main->setText(line);
        lastKey = num;
    }

}
void Standards::onOperationClicked()
{
    QString subLineNew;
    valueNew = ui->Edit_Main->text().toDouble();
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    QString subLineOld = ui->Edit_sub->text();
    if(!subLineOld.isEmpty())
    {
        QChar ch = subLineOld.back();
        ushort code = ch.unicode();
        switch (code)
        {
            case '+':
                valueOld += valueNew;
                break;
            case '-':
                valueOld -= valueNew;
                break;
            case '*':
                valueOld *= valueNew;
                break;
            case '/':
                valueOld /= valueNew;
                break;
            default:
                return;
        }

    }
    else
        valueOld = valueNew;

    lastKey = btn->property("operation").toChar();

    if(lastKey == '=')
    {
        subLineNew = subLineOld + QString::number(valueNew) + lastKey + QString::number(valueOld);
    }
    else
    {
        subLineNew = QString::number(valueOld) + lastKey;
    }

    ui->Edit_sub->setText(subLineNew);
    ui->Edit_Main->setText(QString::number(valueOld));

}
void Standards::on_btn_lineClearMain_released()
{
    EditMain_reset();
}

void Standards::on_btn_lineClearAll_released()
{
    EditMain_reset();
    ui->Edit_sub->clear();
    valueOld = 0;
}

inline void Standards::EditMain_reset()
{
    ui->Edit_Main->setText("0");
}

