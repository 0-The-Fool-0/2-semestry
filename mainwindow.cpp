// mainwindow.cpp
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QHBoxLayout *inputLayout = new QHBoxLayout;
    QLabel *inputLabel = new QLabel("Введите длину:");
    inputEdit = new QLineEdit;
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputEdit);

    QHBoxLayout *radioLayout = new QHBoxLayout;
    radioToMetric = new QRadioButton("Англ. → Метрич.");
    radioToImperial = new QRadioButton("Метрич. → Англ.");
    radioToImperial->setChecked(true);
    radioLayout->addWidget(radioToImperial);
    radioLayout->addWidget(radioToMetric);

    QLabel *listLabel = new QLabel("Единицы измерения:");
    listView = new QListView;
    QStringList units = {"дюймы", "футы", "ярды", "мили", "морские мили"};
    model = new QStringListModel(units);
    listView->setModel(model);

    convertButton = new QPushButton("Конвертировать");
    resultLabel = new QLabel("Результат: ");

    QMenu *fileMenu = menuBar()->addMenu("Файл");
    QAction *exitAction = new QAction("Выход");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);
    fileMenu->addAction(exitAction);

    connect(convertButton, &QPushButton::clicked, this, &MainWindow::convert);

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(radioLayout);
    mainLayout->addWidget(listLabel);
    mainLayout->addWidget(listView);
    mainLayout->addWidget(convertButton);
    mainLayout->addWidget(resultLabel);
    central->setLayout(mainLayout);
    setCentralWidget(central);
    setWindowTitle("Конвертер длины");
}

void MainWindow::convert() {
    bool ok;
    qint16 value = inputEdit->text().toShort(&ok);

    if (!ok || value <= 0) {
        QMessageBox::warning(this, "Ошибка", "Введите положительное целое число.");
        return;
    }

    QString selectedUnit = model->data(model->index(listView->currentIndex().row())).toString();
    QString result;

    if (radioToImperial->isChecked()) {
        if (selectedUnit == "дюймы") {
            result = QString::number(value / 0.0254, 'f', 2) + " дюймов";
        } else if (selectedUnit == "футы") {
            result = QString::number(value / 0.3048, 'f', 2) + " футов";
        } else if (selectedUnit == "ярды") {
            result = QString::number(value / 0.9144, 'f', 2) + " ярдов";
        } else if (selectedUnit == "мили") {
            result = QString::number(value / 1609.34, 'f', 4) + " миль";
        } else if (selectedUnit == "морские мили") {
            result = QString::number(value / 1852.0, 'f', 4) + " морских миль";
        }
    } else {
        if (selectedUnit == "дюймы") {
            result = QString::number(value * 0.0254, 'f', 4) + " м";
        } else if (selectedUnit == "футы") {
            result = QString::number(value * 0.3048, 'f', 4) + " м";
        } else if (selectedUnit == "ярды") {
            result = QString::number(value * 0.9144, 'f', 4) + " м";
        } else if (selectedUnit == "мили") {
            result = QString::number(value * 1609.34, 'f', 4) + " м";
        } else if (selectedUnit == "морские мили") {
            result = QString::number(value * 1852.0, 'f', 4) + " м";
        }
    }

    resultLabel->setText("Результат: " + result);

    QFile log("log.txt");
    if (log.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&log);
        out << "Ввод: " << value << " → " << result << "\n";
    }
}
