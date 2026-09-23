#include "standards.h"
#include "ui_standards.h"

Standards::Standards(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::Standards)
{
    ui->setupUi(this);
}

Standards::~Standards()
{
    delete ui;
}
