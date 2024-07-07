#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <cmath>
#include "scenecarry.h"
#include "MyList.h"
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QObject>
//#include <QMediaPlayer>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->venok->move(3000, 3000);

    QString Line = readRandomLineFromFile("coutpoe.txt");

    words = Line.split(" ");

    a.sc = new QGraphicsScene;

    QDir directory("photo");
    QFileInfoList files = directory.entryInfoList(QDir::Files);

    numPhotos = files.size();
    qreal angle = 0;
    qreal angleIncrement = 2 * M_PI / numPhotos;
    qreal radius = 260;

    a.itm = new MyList<QGraphicsPixmapItem*>;

    for (int i = 0; i < numPhotos; ++i)
    {
        QFileInfo fileInfo = files.at(i);
        QPixmap pixmap(fileInfo.filePath());
        QGraphicsPixmapItem *item = a.sc->addPixmap(pixmap);
        a.itm->push_tail(item);


        qreal x = radius * cos(angle) + 200;
        qreal y = radius * sin(angle) + 200;

        item->setPos(x, y);

        angle += angleIncrement;
    }
    ui->graphicsView->setScene(a.sc);
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    counter = numPhotos;
    i = 0;
    timerg = new QTimer(this);
    connect(timerg, &QTimer::timeout, this, &MainWindow::startt);
    timerg->start(900);
}

void MainWindow::startt()
{
    ui->textoutput->setText(words[i]);
    QGraphicsPixmapItem *bb = a.itm->getelement(i);
    QTimer *timer = new QTimer(this);
    a.sc->removeItem(bb);
    connect(timer, &QTimer::timeout, this, &MainWindow::blink);
    timer->setSingleShot(true);
    timer->start(300);
}

void MainWindow::blink()
{
    if (complet == false)
    {
    QGraphicsPixmapItem *bb = a.itm->getelement(i);
    a.sc->addItem(bb);
    i = i + 1;
    if (i >= words.size())
    {
        timerg->stop();
        if (numPhotos == 2)
        {
            //music = new QMediaPlayer;
            //out = new QAudioOutput;
            //music->setAudioOutput(out);
            //music->setSource(QUrl("qrc:/music/resources/1.mp3"));
            //out->setVolume(50);
            //music->play();
            QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
            animation->setItem(bb);
            QTimeLine *timeLine = new QTimeLine(10000);
            timeLine->setFrameRange(0, 100);
            animation->setTimeLine(timeLine);
            animation->setPosAt(1.0, QPointF(0, 0));
            QObject::connect(timeLine, &QTimeLine::finished, this, animfinished);
            timeLine->start();
        }
        else
        {
        a.itm->DeleteElement(i - 1);
        a.sc->removeItem(bb);
        numPhotos = numPhotos - 1;
        ui->pushButton->setEnabled(true);
        }
    }
    }
}

void MainWindow::animfinished()
{
    //music->stop();
    //music->setSource(QUrl("qrc:/music/resources/2.mp3"));
    //music->play();
    ui->venok->move(0, 0);
    QPixmap pixmap(":/venok/resources/venok.png");
    ui->venok->setPixmap(pixmap);
    QGraphicsPixmapItem *bb = a.itm->getelement(i - 1);
    a.itm->DeleteElement(i - 1);
    a.sc->removeItem(bb);
    bb = a.itm->getelement(1);

    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->venok, "pos");
    animation1->setDuration(1000);
    animation1->setStartValue(ui->venok->pos());
    animation1->setEndValue(QPoint(200, 200));

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->venok, "pos");
    animation2->setDuration(1000);
    animation2->setStartValue(QPoint(200, 200));
    animation2->setEndValue(QPoint(bb->x() + 200, bb->y() + 50));

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    group->addAnimation(animation1);
    group->addAnimation(animation2);

    group->start();

}

QString MainWindow::readRandomLineFromFile(const QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "Не удалось открыть файл";
    }

    QTextStream in(&file);
    QStringList lines;
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }

    if (lines.isEmpty()) {
        return "Файл пуст";
    }

    srand(QTime::currentTime().msec());

    int randomIndex = rand() % lines.size();

    return lines[randomIndex];
}
