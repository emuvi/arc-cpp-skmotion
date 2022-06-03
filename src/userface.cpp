#include <QGuiApplication>
#include <QPixmap>
#include <QScreen>

#include "userface.h"

UserFace::UserFace() {
  layout = new QHBoxLayout();
  action = new QPushButton();
  action->setText("Start");
  layout->addWidget(action);
  connect(action, &QPushButton::clicked, this, &UserFace::start);
  setLayout(layout);
  setWindowTitle(tr("SkMotions"));
}

void UserFace::start() { one_shot(); }

void UserFace::one_shot() {
  auto screens = QGuiApplication::screens();
  auto index = 1;
  for (auto screen : screens) {
    QPixmap pixmap;
    pixmap = screen->grabWindow(0);
    pixmap.save(tr("screen%1.png").arg(index));
    index++;
  }
}
