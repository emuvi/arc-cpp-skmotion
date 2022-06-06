#include <QObject>
#include <QString>

class Recorder : public QObject {
  Q_OBJECT

private:
  QString m_screen;

public:
  explicit Recorder(QString screen, QObject *parent = nullptr);
  void start();
};