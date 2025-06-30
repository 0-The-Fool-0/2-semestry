// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QListView>
#include <QStringListModel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void convert();

private:
    QLineEdit *inputEdit;
    QLabel *resultLabel;
    QPushButton *convertButton;
    QRadioButton *radioToMetric;
    QRadioButton *radioToImperial;
    QListView *listView;
    QStringListModel *model;
};

#endif // MAINWINDOW_H
