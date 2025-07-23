#include "Frequency_analyzer.h"
#include "ui_Frequency_analyzer.h"

Frequency_analyzer::Frequency_analyzer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Frequency_analyzer)
    , serialPort(new QSerialPort(this))
{
    ui->setupUi(this);
    
    // 设置窗口标题
    setWindowTitle("串口数据接收工具");
    
    // 初始化串口和UI
    populatePorts();
    populateBaudRates();
    
    // 连接信号和槽
    connect(serialPort, &QSerialPort::readyRead, this, &Frequency_analyzer::readData);
    connect(serialPort, &QSerialPort::errorOccurred, this, &Frequency_analyzer::handleError);
    
    // 初始状态
    ui->closePortButton->setEnabled(false);
}

Frequency_analyzer::~Frequency_analyzer()
{
    if (serialPort->isOpen())
        serialPort->close();
    delete ui;
}

void Frequency_analyzer::populatePorts()
{
    // 保存当前选中的串口
    QString currentPort = ui->portComboBox->currentData().toString();
    
    ui->portComboBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QString portInfo = QString("%1 - %2").arg(info.portName()).arg(info.description());
        ui->portComboBox->addItem(portInfo, info.portName());
    }
    
    // 尝试恢复之前选中的串口
    int index = ui->portComboBox->findData(currentPort);
    if (index >= 0) {
        ui->portComboBox->setCurrentIndex(index);
    }
}

void Frequency_analyzer::populateBaudRates()
{
    ui->baudRateComboBox->clear();
    QList<qint32> baudRates = QSerialPortInfo::standardBaudRates();
    for (const qint32 &rate : baudRates) {
        ui->baudRateComboBox->addItem(QString::number(rate), rate);
    }
    ui->baudRateComboBox->setCurrentText("9600"); // 默认波特率
}

void Frequency_analyzer::on_openPortButton_clicked()
{
    QString portName = ui->portComboBox->currentData().toString();
    qint32 baudRate = ui->baudRateComboBox->currentText().toInt();
    
    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    
    if (serialPort->open(QIODevice::ReadOnly)) {
        ui->statusLabel->setText("已连接: " + portName + " @ " + QString::number(baudRate) + "bps");
        ui->openPortButton->setEnabled(false);
        ui->closePortButton->setEnabled(true);
        ui->portComboBox->setEnabled(false);
        ui->baudRateComboBox->setEnabled(false);
        ui->refreshPortsButton->setEnabled(false);  // 连接时禁用刷新按钮
    } else {
        ui->statusLabel->setText("连接失败: " + serialPort->errorString());
    }
}

void Frequency_analyzer::on_closePortButton_clicked()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    ui->statusLabel->setText("已断开连接");
    ui->openPortButton->setEnabled(true);
    ui->closePortButton->setEnabled(false);
    ui->portComboBox->setEnabled(true);
    ui->baudRateComboBox->setEnabled(true);
    ui->refreshPortsButton->setEnabled(true);  // 断开时启用刷新按钮
}

// 新增的刷新串口列表函数
void Frequency_analyzer::on_refreshPortsButton_clicked()
{
    bool wasConnected = serialPort->isOpen();
    QString currentPort;
    qint32 currentBaudRate;
    
    if (wasConnected) {
        // 保存当前连接状态
        currentPort = serialPort->portName();
        currentBaudRate = serialPort->baudRate();
        serialPort->close();
    }
    
    // 刷新串口列表
    populatePorts();
    
    if (wasConnected) {
        // 尝试重新连接到之前的串口
        int index = ui->portComboBox->findData(currentPort);
        if (index >= 0) {
            ui->portComboBox->setCurrentIndex(index);
            ui->baudRateComboBox->setCurrentText(QString::number(currentBaudRate));
            on_openPortButton_clicked();
        }
    }
}

void Frequency_analyzer::readData()
{
    QByteArray data = serialPort->readAll();
    ui->textBrowser->insertPlainText(QString::fromUtf8(data));
    
    // 自动滚动到底部
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textBrowser->setTextCursor(cursor);
}

void Frequency_analyzer::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        ui->statusLabel->setText("串口错误: " + serialPort->errorString());
        on_closePortButton_clicked();
    }
}

void Frequency_analyzer::on_clearButton_clicked()
{
    // 清空文本浏览器内容
    ui->textBrowser->clear();
    
    // 可选：添加状态提示
    ui->statusLabel->setText("接收区已清空");
}