#pragma once

#include <QString>
#include <QList>

class ParseText
{
public:
    static bool isParsing(const QString &str);
    static std::pair<int, QString> parse(QString str);

    static const QList<std::pair<QString, QString>> _list;
};

