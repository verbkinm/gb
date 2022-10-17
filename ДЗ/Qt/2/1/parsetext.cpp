#include "parsetext.h"

const QList<std::pair<QString, QString>> ParseText::_list{{"#@RUB@", "₽"},
                                                          {"#@EUR@", "€"},
                                                          {"#@COPY@", "©"},
                                                          {"#@PROM@", "‰"}};

bool ParseText::isParsing(const QString &str)
{
    if (str != parse(str).second)
        return true;

    return false;
}

std::pair<int, QString> ParseText::parse(QString str)
{
    int originLength = str.length();

    for (auto &[key, value] : _list)
        str.replace(key, value);

    return {originLength - str.length(), str};
}
