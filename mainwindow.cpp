#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initForm();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initForm()
{
    m_pStandards = new Standards(this);
    m_pMathfuncplot = new Mathfuncplot(this);

    ui->stkWidget_Main->addWidget(m_pStandards);
    ui->stkWidget_Main->addWidget(m_pMathfuncplot);
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->stkWidget_Main->currentIndex())
        ui->stkWidget_Main->setCurrentIndex(0);
    else
        ui->stkWidget_Main->setCurrentIndex(1);
}


