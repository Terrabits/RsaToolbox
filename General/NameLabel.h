#ifndef NAMELABEL_H
#define NAMELABEL_H


#include <QString>
#include <QStringList>
#include <QVector>
#include <QMetaType>


namespace RsaToolbox {

class NameLabel
{
public:
    NameLabel();
    NameLabel(QString name, QString label = "");

    QString displayText() const;
    QString name() const;
    QString label() const;

    void setName(QString name);
    void setLabel(QString label);

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

bool operator==(const NameLabel &right, const NameLabel &left);
bool operator!=(const NameLabel &right, const NameLabel &left);
}
Q_DECLARE_METATYPE(RsaToolbox::NameLabel)

#endif // NAMELABEL_H
