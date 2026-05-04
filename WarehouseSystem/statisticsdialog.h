#ifndef STATISTICSDIALOG_H
#define STATISTICSDIALOG_H

#include <QDialog>
#include "databasemanager.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

namespace Ui {
class StatisticsDialog;
}

class StatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsDialog(QWidget *parent = nullptr);
    ~StatisticsDialog();

    void setStats(const InventoryStats& stats);
    void drawChart();

private slots:
    void on_closePushButton_clicked();

private:
    Ui::StatisticsDialog *ui;
};

#endif // STATISTICSDIALOG_H
