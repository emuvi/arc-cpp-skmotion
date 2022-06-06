#include "streamer.h"

Streamer::Streamer(Expected expected, QObject *parent)
    : m_expected(expected), QThread(parent) {
  m_shot_number = 1;
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