#include <QGuiApplication>
#include <QPixmap>
#include <QRgb>
#include <QScreen>

#include "userface.h"

UserFace::UserFace() {
  layout = new QHBoxLayout();
  action = new QPushButton();
  action->setText("Start");
  layout->addWidget(action);
  connect(action, &QPushButton::clicked, this, &UserFace::start);
  setLayout(layout);
  setWindowTitle(tr("SkMotion"));
}

void UserFace::start() { one_shot(); }

void UserFace::one_shot() {
  auto screens = QGuiApplication::screens();
  auto index = 1;
  for (auto screen : screens) {
    QPixmap pixmap;
    pixmap = screen->grabWindow(0);
    auto image = pixmap.toImage();
    auto size = image.width() * image.height();
    auto pixels = (QRgb *)image.constBits();
    for (auto i = 0; i < size; i++) {
      auto pixel = pixels[i];
      auto r = qRed(pixel);
      auto g = qGreen(pixel);
      auto b = qBlue(pixel);
      qDebug() << "R:" << r << "G:" << g << "B:" << b << "\n";
    }
    pixmap.save(tr("screen%1.png").arg(index));
    index++;
  }
}
