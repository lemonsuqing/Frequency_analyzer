#ifndef FREQUENCY_ANALYZER_H
#define FREQUENCY_ANALYZER_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class Frequency_analyzer; }
QT_END_NAMESPACE

class Frequency_analyzer : public QMainWindow
{
    Q_OBJECT

public:
    Frequency_analyzer(QWidget *parent = nullptr);
    ~Frequency_analyzer();

private slots:
    void on_openPortButton_clicked();
    void on_closePortButton_clicked();
    void on_refreshPortsButton_clicked();  // 新增的刷新按钮槽函数
    void readData();
    void handleError(QSerialPort::SerialPortError error);

private:
    Ui::Frequency_analyzer *ui;
    QSerialPort *serialPort;
    void populatePorts();
    void populateBaudRates();
};
#endif // FREQUENCY_ANALYZER_H