#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>

class UserFace : public QDialog {
  Q_OBJECT

public:
  UserFace();

private:
  QHBoxLayout *layout;
  QPushButton *action;

private slots:
  void start();
  void one_shot();
};

#endif // INTERFACE_H