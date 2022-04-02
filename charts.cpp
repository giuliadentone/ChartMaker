#include "charts.h"

Chart::Chart(DataMatrix _table)
{
    table = _table;
}
RoundChart::RoundChart(DataMatrix _table) : Chart(_table) {}

PieChart::PieChart(DataMatrix _table) : RoundChart(_table) {}

DonutChart::DonutChart(DataMatrix _table) : RoundChart(_table) {}

BarredChart::BarredChart(DataMatrix _table) : Chart(_table) {}

BarChart::BarChart(DataMatrix _table) : BarredChart(_table) {}

StackedBarChart::StackedBarChart(DataMatrix _table) : BarredChart(_table) {}

HorizontalBarChart::HorizontalBarChart(DataMatrix _table) : BarredChart(_table) {}

HorizontalStackedBarChart::HorizontalStackedBarChart(DataMatrix _table) : BarredChart(_table) {}

PercentBarChart::PercentBarChart(DataMatrix _table) : BarredChart(_table) {}

HorizontalPercentBarChart::HorizontalPercentBarChart(DataMatrix _table) : BarredChart(_table) {}

ContinuousChart::ContinuousChart(DataMatrix _table) : Chart(_table) {}

LineChart::LineChart(DataMatrix _table) : ContinuousChart(_table) {}

SplineChart::SplineChart(DataMatrix _table) : ContinuousChart(_table) {}

ScatterChart::ScatterChart(DataMatrix _table) : Chart(_table) {}

DataMatrix Chart::getTable() const
{
    return table;
}

QPieSeries *RoundChart::toSeries() const
{
    QPieSeries *series = new QPieSeries();
    auto table = getTable();
    auto names = table.getRowLabel();
    auto values = table.getColumnData(0);
    for (unsigned int i = 0; i < names->size(); i++)
    {
        series->append(new QPieSlice(QString::fromStdString((*names)[i]), (*values)[i]));
    }
    return series;
}

QChart *PieChart::draw() const
{
    QChart *RoundChart = new QChart();
    RoundChart->setTitle("This is your Pie Chart");

    auto series = RoundChart::toSeries();
    QPieSlice *slice = series->slices().at(0);
    RoundChart->addSeries(series);
    RoundChart->legend()->setVisible(true);
    RoundChart->legend()->setAlignment(Qt::AlignBottom);
    slice->setPen(QPen(Qt::black, 2));
    RoundChart->setAnimationOptions(QChart::SeriesAnimations);
    RoundChart->setTheme(QChart::ChartThemeBlueIcy);

    QChartView *chartView = new QChartView(RoundChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    series->setHoleSize(0);
    return RoundChart;
}

QChart *DonutChart::draw() const
{
    QChart *RoundChart = new QChart();
    RoundChart->setTitle("This is your Donut Chart");
    auto series = RoundChart::toSeries();
    QPieSlice *slice = series->slices().at(0);
    RoundChart->addSeries(series);
    RoundChart->legend()->setVisible(true);
    RoundChart->legend()->setAlignment(Qt::AlignBottom);
    slice->setPen(QPen(Qt::black, 2));
    slice->setLabelPosition(QPieSlice::LabelOutside);
    RoundChart->setAnimationOptions(QChart::SeriesAnimations);
    RoundChart->setTheme(QChart::ChartThemeBlueIcy);

    QChartView *chartView = new QChartView(RoundChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    series->setHoleSize(0.5);
    return RoundChart;
}

template <class T, class T2>
T *BarredChart::toSeries() const
{
    T *series = new T();
    auto table = getTable();
    auto names = table.getRowLabel();
    for (unsigned int i = 0; i < names->size(); i++)
    {
        T2 *set = new T2(QString::fromStdString((*names)[i]));
        for (auto& tmp: (*(table.getData()))[i])
        {
            *set << tmp;
        }
        series->append(set);
    }
    return series;
}

QChart *BarChart::draw() const
{
    QChart *BarChart = new QChart();
    BarChart->setTitle("This is your Bar Chart");
    auto series = BarredChart::toSeries<QBarSeries, QBarSet>();
    BarChart->addSeries(series);
    BarChart->setAnimationOptions(QChart::SeriesAnimations);
    auto table = getTable();
    QStringList categories;
    for (auto& tmp: *table.getColumnLabel())
    {
        categories << QString::fromStdString(tmp);
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    BarChart->createDefaultAxes();
    BarChart->setAxisX(axis, series);
    BarChart->legend()->setVisible(true);
    BarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(BarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    BarChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return BarChart;
}

QChart *StackedBarChart::draw() const
{
    QChart *StackedBarChart = new QChart();
    StackedBarChart->setTitle("This is your Stacked Bar Chart");
    auto series = BarredChart::toSeries<QStackedBarSeries, QBarSet>();
    StackedBarChart->addSeries(series);
    StackedBarChart->setAnimationOptions(QChart::SeriesAnimations);
    auto table = getTable();
    QStringList categories;
    for (auto& tmp: *table.getColumnLabel())
    {
        categories << QString::fromStdString(tmp);
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    StackedBarChart->createDefaultAxes();
    StackedBarChart->setAxisX(axis, series);
    StackedBarChart->legend()->setVisible(true);
    StackedBarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(StackedBarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    StackedBarChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return StackedBarChart;
}

QChart *HorizontalBarChart::draw() const
{
    QChart *HorizontalBarChart = new QChart();
    HorizontalBarChart->setTitle("This is your Horizontal Bar Chart");
    auto series = BarredChart::toSeries<QHorizontalBarSeries, QBarSet>();
    HorizontalBarChart->addSeries(series);
    HorizontalBarChart->setAnimationOptions(QChart::SeriesAnimations);
    auto table = getTable();
    QStringList categories;
    for (auto& tmp: *table.getColumnLabel())
    {
        categories << QString::fromStdString(tmp);
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    HorizontalBarChart->createDefaultAxes();
    HorizontalBarChart->setAxisY(axis, series);
    HorizontalBarChart->legend()->setVisible(true);
    HorizontalBarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(HorizontalBarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    HorizontalBarChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return HorizontalBarChart;
}

QChart *HorizontalStackedBarChart::draw() const
{
    QChart *HorizontalStackedBarChart = new QChart();
    HorizontalStackedBarChart->setTitle("This is your Horizontal Stacked Bar Chart");
    auto series = BarredChart::toSeries<QHorizontalStackedBarSeries, QBarSet>();
    HorizontalStackedBarChart->addSeries(series);
    HorizontalStackedBarChart->setAnimationOptions(QChart::SeriesAnimations);
    auto table = getTable();
    QStringList categories;
    for (auto& tmp: *table.getColumnLabel())
    {
        categories << QString::fromStdString(tmp);
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    HorizontalStackedBarChart->createDefaultAxes();
    HorizontalStackedBarChart->setAxisY(axis, series);
    HorizontalStackedBarChart->legend()->setVisible(true);
    HorizontalStackedBarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(HorizontalStackedBarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    HorizontalStackedBarChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return HorizontalStackedBarChart;
}

QChart *PercentBarChart::draw() const
{
    QChart *PercentBarChart = new QChart();
    PercentBarChart->setTitle("This is your Percent Bar Chart");
    auto series = BarredChart::toSeries<QPercentBarSeries, QBarSet>();
    PercentBarChart->addSeries(series);
    PercentBarChart->setAnimationOptions(QChart::SeriesAnimations);
    auto table = getTable();
    QStringList categories;
    for (auto& tmp: *table.getColumnLabel())
    {
        categories << QString::fromStdString(tmp);
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    PercentBarChart->createDefaultAxes();
    PercentBarChart->setAxisX(axis, series);
    PercentBarChart->legend()->setVisible(true);
    PercentBarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(PercentBarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    PercentBarChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return PercentBarChart;
}

QChart *HorizontalPercentBarChart::draw() const
{
    QChart *HorizontalPercentBarChart = new QChart();
    HorizontalPercentBarChart->setTitle("This is your Horizontal Percent Bar Chart");
    auto series = BarredChart::toSeries<QHorizontalPercentBarSeries, QBarSet>();
    HorizontalPercentBarChart->addSeries(series);
    HorizontalPercentBarChart->setAnimationOptions(QChart::SeriesAnimations);
    auto table = getTable();
    QStringList categories;
    for (auto& tmp: *table.getColumnLabel())
    {
        categories << QString::fromStdString(tmp);
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    HorizontalPercentBarChart->createDefaultAxes();
    HorizontalPercentBarChart->setAxisY(axis, series);
    HorizontalPercentBarChart->legend()->setVisible(true);
    HorizontalPercentBarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(HorizontalPercentBarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    HorizontalPercentBarChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return HorizontalPercentBarChart;
}


template <class T>
T *ContinuousChart::toSeries(unsigned int i) const
{
    auto table = getTable();
    T *series = new T();
    for(unsigned int j = 0; j < table.getColumnCount(); j++)
    {
        series->append(j, table.getData()->at(i).at(j));
    }
    return series;
}

QChart *LineChart::draw() const
{
    QChart *LineChart = new QChart();
    LineChart->setTitle("This is your Line chart");
    auto table = getTable();
    auto names = table.getRowLabel();
    for(unsigned int j = 0; j < table.getRowCount(); j++)
    {
        auto series = ContinuousChart::toSeries<QLineSeries>(j);
        series->setName(QString::fromStdString((*names)[j]));
        LineChart->addSeries(series);
        LineChart->createDefaultAxes();
        QCategoryAxis *axisX = new QCategoryAxis();
        QCategoryAxis *axisY = new QCategoryAxis();
        for(unsigned int i = 0; i < table.getColumnCount(); i++)
        {
            axisX->append(QString::fromStdString(table.getColumnLabel()->at(i)), i + 0.5);
        }
        LineChart->addAxis(axisX, Qt::AlignBottom);
        LineChart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisX);
    }
    LineChart->legend()->setVisible(true);
    LineChart->legend()->setAlignment(Qt::AlignBottom);
    LineChart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(LineChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    LineChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return LineChart;
}

QChart *SplineChart::draw() const
{
    QChart *SplineChart = new QChart();
    SplineChart->setTitle("This is your Spline Chart");
    auto table = getTable();
    auto names = table.getRowLabel();
    for(unsigned int j = 0; j < table.getRowCount(); j++)
    {
        auto series = ContinuousChart::toSeries<QSplineSeries>(j);
        SplineChart->addSeries(series);
        SplineChart->createDefaultAxes();
        QCategoryAxis *axisX = new QCategoryAxis();
        QCategoryAxis *axisY = new QCategoryAxis();
        for(unsigned int i = 0; i < table.getColumnCount(); i++)
        {
            axisX->append(QString::fromStdString(table.getColumnLabel()->at(i)), i + 0.5);
            series->setName(QString::fromStdString((*names)[j]));
        }
        SplineChart->addAxis(axisX, Qt::AlignBottom);
        SplineChart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisX);
    }
    QChartView *chartView = new QChartView(SplineChart);
    SplineChart->legend()->setVisible(true);
    SplineChart->legend()->setAlignment(Qt::AlignBottom);
    chartView->setRenderHint(QPainter::Antialiasing);
    SplineChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return SplineChart;
}

QScatterSeries *ScatterChart::toSeries(unsigned int i) const
{
    auto table = getTable();
    QScatterSeries *series = new QScatterSeries();
    for(unsigned int j = 0; j < table.getColumnCount(); j++)
    {
        series->append(j, table.getData()->at(i).at(j));
        series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        series->setMarkerSize(15.0);
    }
    return series;
}

QChart *ScatterChart::draw() const
{
    QChart *ScatterChart = new QChart();
    ScatterChart->setTitle("This is your Scatter Chart");
    auto table = getTable();
    auto names = table.getRowLabel();
    for(unsigned int j = 0; j < table.getRowCount(); j++)
    {
        auto series = ScatterChart::toSeries(j);
        ScatterChart->addSeries(series);
        ScatterChart->createDefaultAxes();
        QCategoryAxis *axisX = new QCategoryAxis();
        QCategoryAxis *axisY = new QCategoryAxis();
        for(unsigned int i = 0; i < table.getColumnCount(); i++)
        {
            axisX->append(QString::fromStdString(table.getColumnLabel()->at(i)), i + 0.5);
            series->setName(QString::fromStdString((*names)[j]));
        }
        ScatterChart->addAxis(axisX, Qt::AlignBottom);
        ScatterChart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisX);
    }
        QChartView *chartView = new QChartView(ScatterChart);
        ScatterChart->legend()->setVisible(true);
        ScatterChart->legend()->setAlignment(Qt::AlignBottom);
        chartView->setRenderHint(QPainter::Antialiasing);
        ScatterChart->setTheme(QChart::ChartThemeBlueIcy);
        QPalette pale = qApp->palette();
        pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
        qApp->setPalette(pale);

        return ScatterChart;
};

Chart *PieChart::clone(const DataMatrix &table) const
{
    return new PieChart(table);
}

Chart *DonutChart::clone(const DataMatrix &table) const
{
    return new DonutChart(table);
}

Chart *BarChart::clone(const DataMatrix &table) const
{
    return new BarChart(table);
}

Chart *StackedBarChart::clone(const DataMatrix &table) const
{
    return new StackedBarChart(table);
}

Chart *HorizontalBarChart::clone(const DataMatrix &table) const
{
    return new HorizontalBarChart(table);
}

Chart *HorizontalStackedBarChart::clone(const DataMatrix &table) const
{
    return new HorizontalStackedBarChart(table);
}

Chart *PercentBarChart::clone(const DataMatrix &table) const
{
    return new PercentBarChart(table);
}

Chart *HorizontalPercentBarChart::clone(const DataMatrix &table) const
{
    return new HorizontalPercentBarChart(table);
}

Chart *LineChart::clone(const DataMatrix &table) const
{
    return new LineChart(table);
}

Chart *SplineChart::clone(const DataMatrix &table) const
{
    return new SplineChart(table);
}

Chart *ScatterChart::clone(const DataMatrix &table) const
{
    return new ScatterChart(table);
}
