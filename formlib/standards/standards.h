#ifndef STANDARDS_H
#define STANDARDS_H

#include <QWidget>
#include <QPushButton>
namespace Ui {
class Standards;
}

class Standards : public QWidget
{
    Q_OBJECT

public:
    explicit Standards(QWidget *parent = nullptr);
    ~Standards();
private slots:
    void onNumberClicked();
    void on_btn_lineClearMain_released();
    void on_btn_lineClearAll_released();
    void onOperationClicked();
private:
    Ui::Standards *ui;

    void init();
    inline void EditMain_reset();

    QList<QPushButton*> btnNumbers;
    QList<QPushButton*> btnOperations;
    QChar lastKey;
    double valueNew;
    double valueOld;
};

#endif // STANDARDS_H
