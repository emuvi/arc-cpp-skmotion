#include <QMessageBox>

#include "recorder.h"

Recorder::Recorder(QString screen, QObject *parent)
    : m_screen(screen), QObject(parent) {}

void Recorder::start() {
  QMessageBox::information(nullptr, "Recorder",
                           "Started on screen: " + m_screen);
}

// #include <QGuiApplication>
// #include <QPixmap>
// #include <QRgb>
// #include <QScreen>
// #include <QString>

// void one_shot() {
//   auto screens = QGuiApplication::screens();
//   auto index = 1;
//   for (auto screen : screens) {
//     QPixmap pixmap;
//     pixmap = screen->grabWindow(0);
//     auto image = pixmap.toImage();
//     auto size = image.width() * image.height();
//     auto pixels = (QRgb *)image.constBits();
//     for (auto i = 0; i < size; i++) {
//       auto pixel = pixels[i];
//       auto r = qRed(pixel);
//       auto g = qGreen(pixel);
//       auto b = qBlue(pixel);
//       qDebug() << "R:" << r << "G:" << g << "B:" << b << "\n";
//     }
//     auto filename = QString("screen%1.png").arg(index);
//     pixmap.save(filename);
//     index++;
//   }
// }
