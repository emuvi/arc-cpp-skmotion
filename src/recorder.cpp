#include <QGuiApplication>
#include <QMessageBox>

#include <QRgb>
#include <QString>
#include <cstddef>

#include "recorder.h"

Recorder::Recorder(QString screen, QSize resolution, double sensitivity,
                   int resilience, QString destiny, QObject *parent)
    : m_screen(screen), m_resolution(resolution), m_sensitivity(sensitivity),
      m_resilience(resilience), m_destiny(destiny), QThread(parent) {
  m_running = false;
  m_screen_ptr = nullptr;
  auto all_screens = QGuiApplication::screens();
  for (auto one_screen : all_screens) {
    if (one_screen->name() == screen) {
      m_screen_ptr = one_screen;
      break;
    }
  }
  connect(this, &QThread::finished, this, &QObject::deleteLater);
}

void Recorder::start() {
  m_running = true;
  QThread::start();
}

void Recorder::run() {
  while (m_running) {
    qDebug() << "Recorder::run()";
  }
}

void Recorder::stop() { m_running = false; }

QPixmap Recorder::take_one_shot() { return m_screen_ptr->grabWindow(0); }

void check_shots() {
  auto screens = QGuiApplication::screens();
  auto index = 1;
  for (auto screen : screens) {
    QPixmap pixmap;
    pixmap = screen->grabWindow(0);
    auto image = pixmap.toImage();
    auto size = image.width() * image.height();
    auto pixels = (QRgb *)image.constBits();
    for (auto i = 0; i < size; i++) {
      auto pixel = pixels[i];
      auto r = qRed(pixel);
      auto g = qGreen(pixel);
      auto b = qBlue(pixel);
      qDebug() << "R:" << r << "G:" << g << "B:" << b << "\n";
    }
    auto filename = QString("screen%1.png").arg(index);
    pixmap.save(filename);
    index++;
  }
}
