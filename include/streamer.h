#ifndef __STREAMER_H__
#define __STREAMER_H__

#include <QList>
#include <QMutex>
#include <QPixmap>
#include <QThread>

#include <atomic>

#include "expected.h"

class Streamer : public QThread {
  Q_OBJECT

private:
  const Expected m_expected;
  std::atomic<bool> m_running;
  QMutex mutex;
  QList<QPixmap *> shots;
  qint64 m_shot_number;
  QPixmap *pop();

protected:
  void run() override;

public:
  explicit Streamer(Expected expected);
  void start();
  void push(QPixmap *shot);
  void stop();

private slots:
  void done();
};

#endif // __STREAMER_H__