#include "userface.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication app(argc, argv);
  auto face = new UserFace();
  face->show();
  return app.exec();
}