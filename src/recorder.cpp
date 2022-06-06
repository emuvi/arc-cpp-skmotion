#include <QGuiApplication>
#include <QMessageBox>
#include <QPixmap>
#include <QString>

#include "recorder.h"

Recorder::Recorder(Expected expected) : m_expected(expected), QThread(nullptr) {
  m_running = false;
  m_streamer = new Streamer(expected);
  m_screen_ptr = nullptr;
  auto all_screens = QGuiApplication::screens();
  for (auto one_screen : all_screens) {
    if (one_screen->name() == m_expected.screen) {
      m_screen_ptr = one_screen;
      break;
    }
  }
  m_last_shot = QDateTime::currentMSecsSinceEpoch();
  connect(this, &QThread::finished, this, &Recorder::done);
}

void Recorder::start() {
  m_running = true;
  QThread::start();
  m_streamer->start();
}

void Recorder::run() {
  while (m_running) {
    if (is_in_time()) {
      auto shot = take_a_shot();
      m_streamer->push(shot);
    }
  }
}

bool Recorder::is_in_time() {
  auto now = QDateTime::currentMSecsSinceEpoch();
  if (now - m_last_shot > 1000) {
    m_last_shot = now;
    return true;
  } else {
    return false;
  }
}

QPixmap *Recorder::take_a_shot() {
  return new QPixmap(m_screen_ptr->grabWindow(0));
}

void Recorder::stop() {
  m_running = false;
  m_streamer->stop();
}

void Recorder::done() {
  qDebug() << "done Recorder";
  deleteLater();
}
