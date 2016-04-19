#ifndef NAMELABEL_H
#define NAMELABEL_H


#include <QString>
#include <QStringList>
#include <QVector>
#include <QMetaType>
#include <QDataStream>


namespace RsaToolbox {

class NameLabel
{
public:
    NameLabel();
    NameLabel(QString name, QString label = "");

    bool isEmpty() const;
    QString name() const;
    QString label() const;
    void setName(QString name);
    void setLabel(QString label);
    void clear();

    QString displayText() const;

    operator QString() const;
    void operator=(const NameLabel &other);

    static void separate(QVector<NameLabel> nameLabels, QStringList &names, QStringList &labels);
    static QStringList names(QVector<NameLabel> nameLabels);
    static QStringList labels(QVector<NameLabel> nameLabels);
    static QStringList displayText(QVector<NameLabel> nameLabels);
    static QVector<NameLabel> parse(QString list, QString separator);
    static QVector<NameLabel> parse(QString list, QString separator, QString ignore);

private:
    QString _name;
    QString _label;

};

bool operator==(const RsaToolbox::NameLabel &right, const RsaToolbox::NameLabel &left);
bool operator!=(const RsaToolbox::NameLabel &right, const RsaToolbox::NameLabel &left);
QDataStream& operator<<(QDataStream &stream, const RsaToolbox::NameLabel &label);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::NameLabel &label);

} // RsaToolbox

Q_DECLARE_METATYPE(RsaToolbox::NameLabel)


#endif // NAMELABEL_H
