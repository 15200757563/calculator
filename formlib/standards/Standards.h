#ifndef STANDARDS_H
#define STANDARDS_H

#include <QWidget>

namespace Ui {
class Standards;
}

class Standards : public QWidget
{
    Q_OBJECT

public:
    explicit Standards(QWidget *parent = nullptr);
    ~Standards();

private:
    Ui::Standards *ui;
};

#endif // STANDARDS_H
