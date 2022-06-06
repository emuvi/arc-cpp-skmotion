#ifndef __EXPECTED_H__
#define __EXPECTED_H__

#include <QSize>
#include <QString>

struct Expected {
  const QString screen;
  const QSize resolution;
  const double sensitivity;
  const int resilience;
  const QString destiny;
};

#endif // __EXPECTED_H__