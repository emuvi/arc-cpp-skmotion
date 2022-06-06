#include <QMessageBox>

#include "recorder.h"

Recorder::Recorder(QString screen, QSize resolution, double sensitivity,
                   int resilience, QString destiny, QObject *parent)
    : m_screen(screen), m_resolution(resolution), m_sensitivity(sensitivity),
      m_resilience(resilience), m_destiny(destiny), QObject(parent) {}

void Recorder::start() {
  QMessageBox::information(
      nullptr, "Recorder",
      "Started on screen: " + m_screen +
          " resolution: " + QString::number(m_resolution.width()) + "x" +
          QString::number(m_resolution.height()) +
          " sensitivity: " + QString::number(m_sensitivity) + " resilience: " +
          QString::number(m_resilience) + " destiny: " + m_destiny);
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
