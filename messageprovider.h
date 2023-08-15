#ifndef MESSAGEPROVIDER_H
#define MESSAGEPROVIDER_H

#include <QObject>
#include <QQmlEngine>

class MessageProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged FINAL)

public:
    explicit MessageProvider(const QString &m, QObject *parent = nullptr);
    void setMessage(const QString &m);
    QString message() const;

signals:
    void messageChanged();

private:
    QString m_message;
};

#endif // MESSAGEPROVIDER_H
