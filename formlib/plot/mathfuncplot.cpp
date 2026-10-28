#include "mathfuncplot.h"
#include "ui_mathfuncplot.h"

Mathfuncplot::Mathfuncplot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mathfuncplot)
{
    ui->setupUi(this);
    drawLineGraph();
}

Mathfuncplot::~Mathfuncplot()
{
    delete ui;
}

void Mathfuncplot::drawLineGraph()
{
    QCustomPlot *plot = ui->customPlot;

    // 【1】清空之前所有曲线（避免多次点击叠加多条）
    plot->clearGraphs();

    // 【2】创建一条折线，默认绑定底部xAxis、左侧yAxis
    QCPGraph *graph = plot->addGraph();

    // 【3】准备数据：x单调递增
    QVector<double> x = {0, 1, 2, 3, 4, 5};
    QVector<double> y = {20, 24, 22, 27, 25, 29};

    // 【4】给曲线设置数据，alreadySorted=true：告知x有序，提升性能
    graph->setData(x, y, true);

    // 【5】线条样式
    graph->setLineStyle(QCPGraph::lsLine); // 直线连接（折线）
    graph->setPen(QPen(QColor(0, 110, 200), 2)); // 颜色、线宽

    // 【6】散点标记（拐点圆点）
    graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    // 【7】图例名称
    graph->setName("温度曲线");

    // 【8】开启自适应降采样（大数据量防卡顿，推荐打开）
    graph->setAdaptiveSampling(true);

    // 【9】坐标轴配置
    plot->xAxis->setLabel("时间 (s)");
    plot->yAxis->setLabel("温度 (℃)");
    plot->xAxis->setRange(0, 5);
    plot->yAxis->setRange(18, 32);

    // 网格线
    plot->xAxis->grid()->setVisible(true);
    plot->yAxis->grid()->setVisible(true);
    plot->xAxis->grid()->setPen(QPen(Qt::gray, 1, Qt::DotLine));
    plot->yAxis->grid()->setPen(QPen(Qt::gray, 1, Qt::DotLine));

    // 图例显示
    plot->legend->setVisible(true);
    plot->legend->setFont(QFont("Microsoft YaHei", 9));

    // 【10】鼠标交互：拖拽平移、滚轮缩放
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    // 【11】刷新画面，必须写！
    plot->replot();
}
