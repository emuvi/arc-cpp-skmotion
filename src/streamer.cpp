#include "streamer.h"

Streamer::Streamer(Expected expected, QObject *parent)
    : m_expected(expected), QThread(parent) {}

QPixmap *Streamer::pop() {}

void Streamer::run() {}

void Streamer::push(QPixmap *shot) {}
