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
};

#endif // MATHFUNCPLOT_H
