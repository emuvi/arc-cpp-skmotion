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
#include "streamer.h"

class Recorder : public QThread {
  Q_OBJECT

private:
  const Expected m_expected;
  Streamer *m_streamer;
  std::atomic<bool> m_running;
  QScreen *m_screen_ptr;
  qint64 m_last_shot;
  bool is_in_time();
  QPixmap *take_a_shot();

protected:
  void run() override;

public:
  explicit Recorder(Expected expected);
  void start();
  void stop();

private slots:
  void done();
};

#endif // __RECORDER_H__