#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QRgb>

#include "streamer.h"

Streamer::Streamer(Expected expected) : m_expected(expected), QThread(nullptr) {
  m_shot_number = 1;
  connect(this, &QThread::finished, this, &Streamer::done);
}

void Streamer::start() {
  m_running = true;
  QThread::start();
}

void Streamer::run() {
  while (true) {
    auto shot = pop();
    if (shot != nullptr) {
      auto file_name =
          QString("%1/%2.png").arg(m_expected.destiny).arg(m_shot_number);
      shot->save(file_name, "PNG");
      m_shot_number++;
    } else if (!m_running) {
      break;
    }
  }
}

QPixmap *Streamer::pop() {
  mutex.lock();
  if (!shots.isEmpty()) {
    auto shot = shots.takeFirst();
    mutex.unlock();
    return shot;
  } else {
    mutex.unlock();
    return nullptr;
  }
}

void Streamer::push(QPixmap *shot) {
  mutex.lock();
  shots.push_back(shot);
  mutex.unlock();
}

void Streamer::stop() { m_running = false; }

void Streamer::done() {
  qDebug() << "done Streamer";
  deleteLater();
}

double get_difference(QImage *oldFrame, QImage *newFrame) {
  auto size = oldFrame->width() * oldFrame->height();
  auto oldBits = oldFrame->constBits();
  auto newBits = newFrame->constBits();
  auto diff = 0;
  for (auto i = 0; i < size; i++) {
    if (oldBits[i] != newBits[i]) {
      diff++;
    }
  }
  return (double)diff / size;
}
