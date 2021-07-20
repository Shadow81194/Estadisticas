#include "principal.h"
#include "ui_principal.h"



Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //Crear el lienzo
    lienzo = QPixmap(500,500);

    //Invocar al metodo dibujar
    this->dibujar();

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    //Rellenar el lienzo de color blanco
    lienzo.fill(Qt::white);
    //Crear el pintor
    QPainter painter(&lienzo);
    int x = 50;
    int y = 50;
    int ancho = 100;
    int alto_1 = ui->inNota1->value();
    int alto_2 = ui->inNota2->value();
    int alto_3 = ui->inNota3->value();
    //Crear el pincel para el borde
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);
    //Establecer el pincel al pintor
    painter.setPen(pincel);
    //Dibujar la primera barra
    painter.drawRect(x, y+(400-alto_1), ancho, alto_1);
    //Crear un nuevo color
    QColor colorBorde2(78,3,48);
    QColor colorRelleno2(190,120,162);
    //Establecer el nuevo color al pincel
    pincel.setColor(colorBorde2);
    //Volver a establecer el pincel al objeto painter
    painter.setPen(pincel);
    //Establecer el color de la brocha del objeto painter
    painter.setBrush(colorRelleno2);
    //Dibujar la segunda barra
    painter.drawRect(x+150, y+(400-alto_2), ancho, alto_2);
    //Creando los colores de la tercera barra
    QColor colorRelleno3(253,253,115);
    QColor colorBorde3(174,174,51);
    //Establecer nuevo color al pincel
    pincel.setColor(colorBorde3);
    //Establecer el pincel y la brocha al painter
    painter.setPen(pincel);
    painter.setBrush(colorRelleno3);
    //Dibujar el rectangulo
    painter.drawRect(x+300, y+(400-alto_3), ancho, alto_3);
    //Mostrar el lienzo en el cuadro
    ui->cuadro->setPixmap(lienzo);
}


void Principal::on_cmdDibujar_clicked()
{
    dibujar();
}

void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota34_valueChanged(int arg1)
{

}

void Principal::on_actionGuardadr_triggered()
{
    //Crear un objeto Qdir a partir del direcion del usario
    QDir directorio = QDir::home();
    //Agregrar al path absoluto del objeto, un nombre por defeto del archivo
    QString pathArchivo = directorio.absolutePath() + "/sin_nombre.jpg";
    //Abrir un cuadro de dialogo para selecionar el nombre y ubicacion del archivo y guardar.
    QString fileName = QFileDialog::getSaveFileName(this, "* Un nombre para la Ventana *",
                                                    pathArchivo,
                                                    "Archivo imagen (*.jpg)");
    lienzo.save(fileName);
    ui->statusbar->showMessage("Archivo guarda en" + fileName,3000);
}

void Principal::on_actionSalir_triggered()
{
    this->close();
}
