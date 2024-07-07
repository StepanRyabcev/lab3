    #include <QApplication>
    #include <QGraphicsView>
    #include <QGraphicsPixmapItem>
    #include <QGraphicsScene>
    #include <QPixmap>
    #include <QDir>
    #include <QFileInfoList>
    #include <QFileInfo>
    #include <cmath>
    #include "mainwindow.h"

    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        /*QGraphicsScene scene;
        QGraphicsView view(&scene);

        // Получаем список файлов в папке "photo"
        QDir directory("photo");
        QFileInfoList files = directory.entryInfoList(QDir::Files);

        int numPhotos = files.size();
        qreal angle = 0;
        qreal angleIncrement = 2 * M_PI / numPhotos;
        qreal radius = 260; // Увеличиваем радиус

        for (int i = 0; i < numPhotos; ++i)
        {
            QFileInfo fileInfo = files.at(i);
            QPixmap pixmap(fileInfo.filePath());
            QGraphicsPixmapItem *item = scene.addPixmap(pixmap);

            qreal x = radius * cos(angle) + 200; // Добавляем сдвиг по x
            qreal y = radius * sin(angle) + 200; // Добавляем сдвиг по y

            item->setPos(x, y);

            angle += angleIncrement;
        }

        //view.show();*/

        return a.exec();
    }
