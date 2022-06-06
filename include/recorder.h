#ifndef __RECORDER_H__
#define __RECORDER_H__

#include <QDateTime>
#include <QPixmap>
#include <QScreen>
#include <QSize>
#include <QString>
#include <QThread>

#include <atomic>

#include "expected.h"

class Recorder : public QThread {
  Q_OBJECT

private:
  const Expected m_expected;
  std::atomic<bool> m_running;
  QScreen *m_screen_ptr;
  qint64 m_shot_number;
  qint64 m_last_shot;
  bool is_in_time();
  QPixmap *take_a_shot();

protected:
  void run() override;

public:
  explicit Recorder(Expected expected, QObject *parent = nullptr);
  void start();
  void stop();
};

#endif // __RECORDER_H__