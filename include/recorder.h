#ifndef __RECORDER_H__
#define __RECORDER_H__

#include <QDateTime>
#include <QPixmap>
#include <QScreen>
#include <QSize>
#include <QString>
#include <QThread>

#include <atomic>
#include <qglobal.h>

class Recorder : public QThread {
  Q_OBJECT

private:
  QString m_screen;
  QSize m_resolution;
  double m_sensitivity;
  int m_resilience;
  QString m_destiny;
  std::atomic<bool> m_running;
  QScreen *m_screen_ptr;
  qint64 m_shot_number;
  qint64 m_last_shot;
  bool is_in_time();
  QPixmap *take_a_shot();

protected:
  void run() override;

public:
  explicit Recorder(QString screen, QSize size, double sensitivity,
                    int resilience, QString destiny, QObject *parent = nullptr);
  void start();
  void stop();
};

#endif // __RECORDER_H__