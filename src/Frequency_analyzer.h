#pragma once
#include "ui_Frequency_analyzer.h"
#include <QMainWindow>

class Frequency_analyzer : public QMainWindow {
    Q_OBJECT
    
public:
    Frequency_analyzer(QWidget* parent = nullptr);
    ~Frequency_analyzer();

private:
    Ui_Frequency_analyzer* ui;
};