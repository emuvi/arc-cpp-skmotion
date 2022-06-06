#include <QDebug>
#include <QImage>
#include <QPixmap>

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
  QImage *lastSaved = nullptr;
  while (true) {
    auto shot = pop();
    if (shot != nullptr) {
      auto actualFrame = new QImage(shot->toImage());
      delete shot;
      bool shouldSave = true;
      if (lastSaved != nullptr) {
        auto difference = get_difference(lastSaved, actualFrame);
        if (difference < m_expected.sensitivity) {
          shouldSave = false;
        }
      }
      if (shouldSave) {
        QString filename =
            QString("%1/%2.png").arg(m_expected.destiny).arg(m_shot_number);
        actualFrame->save(filename);
        m_shot_number++;
        if (lastSaved != nullptr) {
          delete lastSaved;
        }
        lastSaved = actualFrame;
      } else {
        delete actualFrame;
      }
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

double Streamer::get_difference(QImage *oldFrame, QImage *newFrame) {
  auto size = oldFrame->width() * oldFrame->height();
  auto oldBits = oldFrame->constBits();
  auto newBits = newFrame->constBits();
  auto diff = 0;
  for (auto i = 0; i < size; i++) {
    if (oldBits[i] != newBits[i]) {
      diff++;
    }
  }
  auto result = (double)diff / size;
  return result;
}
