#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QModelIndex>

#include "inventario.h"
#include "database.h"
#include "reportef.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAgregar_clicked();
    void on_btnEliminar_clicked();
    void on_btnEditar_clicked();
    void on_btnExportar_clicked();
    void on_txtBuscar_textChanged(const QString &text);
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    inventario inv;
    reportef rep;
};

#endif
