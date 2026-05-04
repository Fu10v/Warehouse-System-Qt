#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"
#include <QMap>
#include <QDateTime>

StatisticsDialog::StatisticsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StatisticsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Warehouse statistics");
    this->resize(800, 600);
}

StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

void StatisticsDialog::setStats(const InventoryStats &stats)
{
    // Виводимо дані в лейбли
    ui->positionsLabel->setText(QString::number(stats.totalPositions));
    ui->quantityLabel->setText(QString::number(stats.totalQuantity, 'f', 2));

    // Форматуємо гроші
    ui->valueLabel->setText(QString::number(stats.totalValue, 'f', 2) + " UAH");
    drawChart();
}
//Малюємо chart
void StatisticsDialog::drawChart()
{
    // Отримуємо всі товари
    QVector<Item> items = DatabaseManager::instance().getAllItems();

    // Групуємо дані: Дата -> Сумарна кількість
    // QMap автоматично сортує за датою (ключем)
    QMap<QDateTime, double> timeSeries;

    for (const Item& item : items) {
        // Перетворюємо рядок "2025-11-21" у QDateTime
        QDate date = QDate::fromString(item.date, "yyyy-MM-dd");
        QDateTime dt(date.startOfDay()); // Початок дня

        if (timeSeries.contains(dt)) {
            timeSeries[dt] += item.quantity; // Додаємо до існуючої дати
        } else {
            timeSeries[dt] = item.quantity;  // Нова дата
        }
    }

    // Створюємо серію даних для графіка
    QLineSeries *series = new QLineSeries();
    series->setName("Revenue dynamics");

    // Знаходимо мін/макс для осей
    double maxQty = 0;
    for (auto it = timeSeries.begin(); it != timeSeries.end(); ++it) {
        // Графік приймає (Час у мілісекундах, Значення)
        series->append(it.key().toMSecsSinceEpoch(), it.value());

        if (it.value() > maxQty) maxQty = it.value();
    }

    // Створюємо сам графік
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Number of items by day");
    chart->setAnimationOptions(QChart::SeriesAnimations); // Красива анімація появи

    // Налаштовуємо вісь X (Час)
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10); // Скільки дат показувати
    axisX->setFormat("dd.MM"); // Формат підпису: "21.11"
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Налаштовуємо вісь Y (Кількість)
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i"); // Цілі числа
    axisY->setTitleText("Quantity (pcs)");
    axisY->setRange(0, maxQty * 1.1); // Трохи вище максимуму, щоб було гарно
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Відображаємо
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); // Згладжування ліній

    // Додаємо графік у наш layout, який ми створили в Designer
    ui->chartLayout->addWidget(chartView);
}

void StatisticsDialog::on_closePushButton_clicked()
{
    this->close();
}

