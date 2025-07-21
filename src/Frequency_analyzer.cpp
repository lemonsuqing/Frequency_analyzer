#include "Frequency_analyzer.h"

Frequency_analyzer::Frequency_analyzer(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_Frequency_analyzer)
{
    ui->setupUi(this);
}

Frequency_analyzer::~Frequency_analyzer()
{
    delete ui; 
}