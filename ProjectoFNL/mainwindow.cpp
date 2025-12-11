#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlTableModel>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, database::instance().getDatabase());
    model->setTable("components");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAgregar_clicked()
{
    Componentes c;
    c.nombre = ui->txtNombre->text();
    c.tipo = ui->txtTipo->text();
    c.cantidad = ui->spinCantidad->value();
    c.ubicacion = ui->txtUbicacion->text();
    c.dia_compra = ui->dateCompra->date().toString("yyyy-MM-dd");
    c.min_almacen = ui->spinMinimo->value();
    c.notas = ui->txtNotas->toPlainText();

    if (c.nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "El nombre no puede estar vacío");
        return;
    }

    if (inv.insertarComponente(c)) {
        QMessageBox::information(this, "OK", "El componente se agregó exitosamente");
        model->select();
    } else {
        QMessageBox::critical(this, "Error", "No se pudo agregar el componente");
    }
}

void MainWindow::on_btnEliminar_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();

    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Seleccione un registro");
        return;
    }

    model->removeRow(index.row());
    model->submitAll();
    model->select();

    QMessageBox::information(this, "OK", "Registro eliminado");
}

void MainWindow::on_btnEditar_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();

    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Seleccione un registro");
        return;
    }

    int fila = index.row();

    model->setData(model->index(fila, 1), ui->txtNombre->text());
    model->setData(model->index(fila, 2), ui->txtTipo->text());
    model->setData(model->index(fila, 3), ui->spinCantidad->value());
    model->setData(model->index(fila, 4), ui->txtUbicacion->text());
    model->setData(model->index(fila, 5), ui->dateCompra->date().toString("yyyy-MM-dd"));
    model->setData(model->index(fila, 6), ui->spinMinimo->value());
    model->setData(model->index(fila, 7), ui->txtNotas->toPlainText());

    model->submitAll();
    model->select();

    QMessageBox::information(this, "OK", "Registro actualizado");
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int fila = index.row();

    ui->txtNombre->setText(model->data(model->index(fila, 1)).toString());
    ui->txtTipo->setText(model->data(model->index(fila, 2)).toString());
    ui->spinCantidad->setValue(model->data(model->index(fila, 3)).toInt());
    ui->txtUbicacion->setText(model->data(model->index(fila, 4)).toString());
    ui->dateCompra->setDate(QDate::fromString(model->data(model->index(fila, 5)).toString(), "yyyy-MM-dd"));
    ui->spinMinimo->setValue(model->data(model->index(fila, 6)).toInt());
    ui->txtNotas->setPlainText(model->data(model->index(fila, 7)).toString());
}

void MainWindow::on_txtBuscar_textChanged(const QString &text)
{
    model->setFilter("name LIKE '%" + text + "%'");
    model->select();
}

void MainWindow::on_btnExportar_clicked()
{
    QString ruta = QFileDialog::getSaveFileName(this, "Guardar reporte", "", "Archivos CSV (*.csv)");
    if (ruta.isEmpty())
        return;

    if (rep.exportarCSV(ruta))
        QMessageBox::information(this, "OK", "El reporte fue exportado");
    else
        QMessageBox::critical(this, "Error", "No se pudo exportar el reporte");
}
