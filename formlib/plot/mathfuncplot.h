#ifndef MATHFUNCPLOT_H
#define MATHFUNCPLOT_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class Mathfuncplot;
}

class Mathfuncplot : public QWidget
{
    Q_OBJECT

public:
    explicit Mathfuncplot(QWidget *parent = nullptr);
    ~Mathfuncplot();

private:
    Ui::Mathfuncplot *ui;
    void drawLineGraph();
    void updateUI();
    void init();

    QCustomPlot *plot;
    QCPItemLine* m_lineZeroX; // y=0 横线（x轴）
    QCPItemLine* m_lineZeroY; // x=0 竖线（y轴）
    QCPGraph* m_graph = nullptr;
};

#endif // MATHFUNCPLOT_H
