// #include "serialreader.h"
// #include <QTextStream>
// #include <QDebug>

// SerialReader::SerialReader(const QString& portName, int baudRate)
// {
//     serial.setPortName(portName);
//     serial.setBaudRate(baudRate);
//     serial.setDataBits(QSerialPort::Data8);
//     serial.setParity(QSerialPort::NoParity);
//     serial.setStopBits(QSerialPort::OneStop);
//     serial.setFlowControl(QSerialPort::NoFlowControl);
// }

// void SerialReader::start()
// {
//     if (serial.open(QIODevice::ReadOnly)) {
//         qDebug() << "串口已打开:" << serial.portName();
//         QObject::connect(&serial, &QSerialPort::readyRead, this, &SerialReader::handleReadyRead);
//     } else {
//         qCritical() << "无法打开串口:" << serial.errorString();
//     }
// }

// void SerialReader::handleReadyRead()
// {
//     QByteArray data = serial.readAll();
//     QTextStream(stdout) << QString::fromUtf8(data);
// }
