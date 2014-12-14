#include "NameLabel.h"
using namespace RsaToolbox;


/*!
 * \class RsaToolbox::NameLabel
 * \brief The %NameLabel class handles identifiers that include
 * both a name and a label.
 *
 * %NameLabel is primarily a data type for resources that
 * have both a name and a label as identifiers. For example,
 * a Vector Network Analyzer may have two calibration kits
 * registered that have the same name, but have different
 * serial numbers that can be applied as labels. A
 * NameLabel is then used to handle the identifier without having to
 * perform the extra business logic to handle two identifier strings.
 *
 * The example below iterates through each calibration kit
 * registered with the \c Vna object (\c vna) looking for cal kits that
 * contain a Male-to-Male thru standard:
 *
\code
    ...
    QVector<NameLabel> calKits = vna.GetCalibrationKits();
    foreach(NameLabel kit, calKits) {
        // Do something
    }
\endcode
 *
 * <B>Note:</B> NameLabels are case-sensitive. Although the name and the label
 * may not independently be unique, the combination of the two must
 * be unique to a particular resource.
 *
 *\sa RsaToolbox::Vna
 */

/*!
 * \brief the default (empty) constructor
 *
 * Constructs an empty NameLabel (name = "", label = "").
 */
NameLabel::NameLabel()
{
}

/*!
 * \brief the fully defined instance constructor
 *
 * Constructs a \c NameLabel with \a name and \a label. \a label is an empty string
 * by default.
 *
 * \param name
 * \param label
 */
NameLabel::NameLabel(QString name, QString label) {
    this->_name = name;
    this->_label = label;
}

/*!
 * \brief provides a user-friendly \c QString representation of \c NameLabel
 * \return the formatted string: "Name (Label)"
 */
QString NameLabel::displayText() const {
    QString display;
    if (_label.isEmpty())
        display = _name;
    else
        display = _name + " (" + _label + ")";
    return(display);
}
/*!
 * \brief Returns name of NameLabel object
 * \return name
 */
QString NameLabel::name() const {
    return(_name);
}
/*!
 * \brief returns label of \c NameLabel object
 * \return label
 */
QString NameLabel::label() const {
    return(_label);
}

/*!
 * \brief Sets name of \c NameLabel object
 * \param name New name of \c NameLabel
 */
void NameLabel::setName(QString name) {
    _name = name;
}
/*!
 * \brief Sets label of \c NameLabel object
 * \param label New label of \c NameLabel
 */
void NameLabel::setLabel(QString label) {
    _label = label;
}

/*!
 * \brief Returns the result of \c NameLabel::displayText()
 */
NameLabel::operator QString() const {
    return(displayText());
}

/*!
 * \brief Sets properties of \c this to that of \c other
 * \param other \c NameLabel object with desired properties
 */
void NameLabel::operator=(const NameLabel &other) {
    _name = other._name;
    _label = other._label;
}

/*!
 * \brief Separates \c name_labels into two lists: \c names and \c labels
 * \param[in] name_labels
 * \param[out] names The list of names from \c name_labels
 * \param[out] labels The list of labels from \c name_labels
 * \sa NameLabel::names(), NameLabel::labels()
 */
void NameLabel::separate(QVector<NameLabel> name_labels, QStringList &names, QStringList &labels) {
    names.clear();
    labels.clear();
    foreach (NameLabel nl, name_labels) {
        names.append(nl._name);
        labels.append(nl._label);
    }
}

/*!
 * \brief Creates a list of names from \c name_labels
 * \param name_labels
 * \return The names of \c name_labels
 */
QStringList NameLabel::names(QVector<NameLabel> name_labels) {
    QStringList names;
    foreach (NameLabel nl, name_labels) {
        names.append(nl._name);
    }
    return(names);
}

/*!
 * \brief NameLabel::labels
 * \param name_labels
 * \return The labels of \c name_labels
 */
QStringList NameLabel::labels(QVector<NameLabel> name_labels) {
    QStringList labels;
    foreach (NameLabel nl, name_labels) {
        labels.append(nl._label);
    }
    return(labels);
}

/*!
 * \brief Generates user-friendly text for \c name_labels
 * \param name_labels
 * \return User-friendly text of \c name_labels
 */
QStringList NameLabel::displayText(QVector<NameLabel> name_labels) {
    QStringList displays;
    foreach (NameLabel nl, name_labels) {
        displays.append(nl.displayText());
    }
    return(displays);
}

/*!
 * \brief Parses \c NameLabels out of \c list
 *
 * \c list must follow a particular format.
 * For example, for \c separator = ",":
 * \c list = (\c name1, \c label1, \c name2, \c label2, ...)
 *
 * \param list Alternating list of names and labels
 * \param separator Delimiter used in \c list
 * \return %NameLabels in \c list
 */
QVector<NameLabel> NameLabel::parse(QString list, QString separator) {
    QStringList splitList = list.split(separator, QString::KeepEmptyParts);
    int splitListSize = splitList.size();
    QVector<NameLabel> nameLabels;
    for (int i = 0; i < splitListSize - 1; i += 2) {
        nameLabels.append(NameLabel(splitList[i], splitList[i+1]));
    }
    return(nameLabels);
}

/*!
 * \brief Parses \c NameLabels out of \c list while ignoring
 * instances of \c ignore
 *
 * \c list must follow a particular format.
 * For example, for \c separator = ",":
 * \c list = (\c name1, \c label1, \c name2, \c label2, ...)
 *
 * A typical Rohde \& Schwarz VNA response, for example:<br>
 * <tt>result = "name1,'label1',name2,'label2',..."</tt><br>
 * can be parsed with the following snippet:
 * \code
    NameLabel::parse(result, ",", "\'");
   \endcode
 *
 * \param list Alternating list of names and labels
 * \param separator Delimiter used in \c list
 * \param ignore String instances to ignore in \c list
 * \return %NameLabels in \c list
 */
QVector<NameLabel> NameLabel::parse(QString list, QString separator, QString ignore) {
    QString newList = list;
    return(parse(newList.remove(ignore), separator));
}

/*!
 * \relates RsaToolbox::NameLabel
 * \brief Compares \c right and \c left for equality
 *
 * Returns true if \c right and \c left have the same
 * name and label.
 *
 * \note Comparision is case-sensitive.
 *
 * \param right \c NameLabel on right-hand side of == operator
 * \param left \c NameLabel on left-hand side of == operator
 * \return Case-sensitive equality of objects
 * \sa RsaToolbox::operator!=(const NameLabel &right, const NameLabel &left)
 */
bool RsaToolbox::operator==(const NameLabel &right, const NameLabel &left) {
    return(right.name() == left.name()
           && right.label() == left.label());
}

/*!
 * \relates RsaToolbox::NameLabel
 * \brief Compares \c right and \c left for inequality
 *
 * Returns true if \c right and \c left do not have the same
 * name and label.
 *
 * \note Comparision is case-sensitive.
 *
 * \param right \c NameLabel on right-hand side of != operator
 * \param left \c NameLabel on left-hand side of != operator
 * \return Case-sensitive inequality of objects
 * \sa RsaToolbox::operator==(const NameLabel &right, const NameLabel &left)
 */
bool RsaToolbox::operator!=(const NameLabel &right, const NameLabel &left) {
    return(!(right == left));
}

QDataStream& RsaToolbox::operator<<(QDataStream &stream, const NameLabel &nameLabel) {
    stream << nameLabel.name();
    stream << nameLabel.label();
    return stream;
}
QDataStream& RsaToolbox::operator>>(QDataStream &stream, NameLabel &nameLabel) {
    QString string;
    stream >> string;
    nameLabel.setName(string);
    stream >> string;
    nameLabel.setLabel(string);
    return stream;
}
