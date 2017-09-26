#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_categoryBox_activated(int index);

    void on_actionQuit_triggered();

    void on_actionAdd_component_triggered();

    void on_actionSearch_components_triggered();

    void on_actionTa_bort_komponent_triggered();

    void on_pushButton_clicked();

    void on_clearButton_newComponent_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_ok_search_by_field_clicked();

    void on_categoryBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
