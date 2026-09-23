#include "Standards.h"
#include "ui_Standards.h"

Standards::Standards(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Standards)
{
    ui->setupUi(this);
}

Standards::~Standards()
{
    delete ui;
}
