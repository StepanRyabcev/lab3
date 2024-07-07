#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
//#include <QMediaPlayer>
//#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    SceneCarry a;
    bool complet = false;
    int counter, numPhotos, i;
    QStringList words;
    void blink();
    void startt();
    QTimer *timerg;
    void animfinished();
    //QMediaPlayer *music;
    //QAudioOutput *out;
    QString readRandomLineFromFile(const QString);

};
#endif // MAINWINDOW_H
