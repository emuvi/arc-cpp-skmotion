#include "userface.h"
#include <QApplication>
#include <QString>

QString mainStyles = R"__STYLES__(
* {
	background: #333333;
	color: #f6e5ff;
  padding: 5px;
	border-radius: 3px;
	border: 1px solid #f9eeff;
  font-family: Cambria, Cochin, Georgia, Times, 'Times New Roman', serif;
  font-size: 14px;
}

QLabel {
	border: none;
}
)__STYLES__";

int main(int argc, char **argv) {
  QApplication app(argc, argv);
  app.setStyleSheet(mainStyles);
  UserFace face;
  face.show();
  return app.exec();
}