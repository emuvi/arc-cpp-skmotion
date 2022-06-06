#ifndef __STREAMER_H__
#define __STREAMER_H__

#include <QPixmap>
#include <QThread>
#include <qpixmap.h>

#include "expected.h"

class Streamer : public QThread {
  Q_OBJECT

private:
  const Expected m_expected;
  QPixmap *pop();

protected:
  void run() override;

public:
  explicit Streamer(Expected expected, QObject *parent = nullptr);
  void push(QPixmap *shot);
};

#endif // __STREAMER_H__