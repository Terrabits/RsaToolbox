#ifndef INDEXNAME_H
#define INDEXNAME_H


#include <QString>
#include <QStringList>
#include <QVector>
#include <QMetaType>


namespace RsaToolbox {

class IndexName
{
public:
    IndexName();
    IndexName(uint index, QString name);

    uint index() const;
    QString name() const;

    void setIndex(uint index);
    void setName(QString name);

    void operator=(const IndexName &other);

    static QVector<IndexName> parse(QString list, QString separator);
    static QVector<IndexName> parse(QString list, QString separator, QString ignore);
    static void separate(QVector<IndexName> indexNames, QVector<uint> &indices, QStringList &names);
    static QVector<uint> indices(QVector<IndexName> indexNames);
    static QStringList names(QVector<IndexName> indexNames);

private:
    uint _index;
    QString _name;
};

bool operator==(const IndexName &right, const IndexName &left);
bool operator!=(const IndexName &right, const IndexName &left);
}
Q_DECLARE_METATYPE(RsaToolbox::IndexName)

#endif // INDEXNAME_H
