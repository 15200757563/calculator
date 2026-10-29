#include "mathfuncplot.h"
#include "ui_mathfuncplot.h"
#include <QTimer>
#include <algorithm>
Mathfuncplot::Mathfuncplot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mathfuncplot)
{
    ui->setupUi(this);
    init();
    QTimer* update = new QTimer();
    connect(update,&QTimer::timeout,this,&Mathfuncplot::updateUI);
    update->start(50);
}

Mathfuncplot::~Mathfuncplot()
{
    delete ui;
}

void Mathfuncplot::init()
{
    plot = ui->customPlot;
    // 【3】准备数据：x单调递增
    // 横线 y=0

    m_lineZeroX = new QCPItemLine(plot);
    m_lineZeroY = new QCPItemLine(plot);

    m_lineZeroX->start->setCoords(-1e12, 0);
    m_lineZeroX->end->setCoords(1e12, 0);
    m_lineZeroX->setPen(QPen(Qt::black, 2));

    // 竖线 x=0
    m_lineZeroY->start->setCoords(0, -1e12);
    m_lineZeroY->end->setCoords(0, 1e12);
    m_lineZeroY->setPen(QPen(Qt::black, 2));

    // 【9】坐标轴配置
    plot->xAxis->setLabel("时间 (s)");
    plot->yAxis->setLabel("温度 (℃)");
    plot->rescaleAxes();

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

    m_graph = plot->addGraph();



    // 【5】线条样式
    m_graph->setLineStyle(QCPGraph::lsLine); // 直线连接（折线）
    m_graph->setPen(QPen(QColor(0, 110, 200), 2)); // 颜色、线宽

    // 【6】散点标记（拐点圆点）
    m_graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 3));

    // 【7】图例名称
    m_graph->setName("温度曲线");

    // 【8】开启自适应降采样（大数据量防卡顿，推荐打开）
    m_graph->setAdaptiveSampling(true);

}

void Mathfuncplot::drawLineGraph()
{
    QCPRange xrange = plot->xAxis->range();
    QVector<double> x,y;
//    if (xrange.size() * xrange.size() >= yrange.size())
//    {
        // 沿X采样 y = x²
        const int sampleCnt = 800;
        double step = xrange.size() / sampleCnt;
        for(double xi = xrange.lower; xi <= xrange.upper; xi += step)
        {
            x.append(xi);
            y.append(std::sin(xi));
        }

//    }
//    else
//    {
//        // 沿Y采样 x = ±√y，y=x²
//        const int sampleCnt = 500;
//        double step = yrange.size() / sampleCnt;
//        for(double yi = yrange.lower; yi <= yrange.upper; yi += step)
//        {
//            if (yi < 0)
//                continue; // sqrt无实数解，跳过
//            double sx = std::sqrt(yi);
//            // 左支
//            x.append(-sx);
//            y.append(yi);
//            // 右支
//            x.append(sx);
//            y.append(yi);
//        }
//    }
    m_graph->setData(x, y, true);
    plot->replot();
}

void Mathfuncplot::updateUI()
{
    drawLineGraph();
}
