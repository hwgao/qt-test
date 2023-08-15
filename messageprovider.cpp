#include "messageprovider.h"

MessageProvider::MessageProvider(const QString &m, QObject *parent)
    : QObject{parent}, m_message{m}
{

}

void MessageProvider::setMessage(const QString &m) {
    if (m != m_message) {
        m_message = m;
        emit messageChanged();
    }
}

QString MessageProvider::message() const {
    return m_message;
}
