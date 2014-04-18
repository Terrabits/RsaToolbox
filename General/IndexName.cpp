#include "IndexName.h"
using namespace RsaToolbox;


/*!
 * \class RsaToolbox::IndexName
 * \brief The %IndexName class handles identifiers that include
 * both an index and a name.
 *
 * %IndexName is primarily a data type for resources that
 * have both a name and a label as identifiers. For example,
 * Rohde \& Schwarz Vector Network Analyzers identify
 * channels by both an index number and a name.
 *
 * <B>Note:</B> &IndexName is case-sensitive.
 *
 *\sa RsaToolbox::Vna
 */

/*!
 * \brief Default constructor
 *
 * index() returns 0 and name() is empty
 */
IndexName::IndexName()
{
    _index = 0;
    _name.clear();
}

/*!
 * \brief Full constructor
 *
 * Constructs a &IndexName object with \c index
 * and \c name.
 *
 * \param index Index of constructed object
 * \param name Name of constructed object
 */
IndexName::IndexName(uint index, QString name) {
    _index = index;
    _name = name;
}

/*!
 * \brief Returns the index
 * \return Index of the object
 */
uint IndexName::index() const {
    return(_index);
}

/*!
 * \brief Returns the name
 * \return Name of the object
 */
QString IndexName::name() const {
    return(_name);
}

/*!
 * \brief Sets the index
 * \param index Index for object to be set to
 */
void IndexName::setIndex(uint index) {
    _index = index;
}

/*!
 * \brief Sets the name
 * \param name Name for object to be set to
 */
void IndexName::setName(QString name) {
    _name = name;
}

/*!
 * \brief Assignment operator
 *
 * Sets the properties of the left-hand object to that
 * of the right-hand object (\c other).
 *
 * \param other Object whose properties will be copied
 */
void IndexName::operator=(const IndexName &other) {
    this->_index = other._index;
    this->_name = other._name;
}

/*!
 * \brief Parses a formatted list of %IndexName values
 *
 * For a separator value of ',', a formatted list
 * is as follows:<br>
 * <tt>list = "index1,name1,index2,name2,...";</tt><br>
 *
 * Such a list can be paresed with the following snippet:
   \code
    IndexName::parse(list, ",");
   \endcode
 *
 * \param list List to parse
 * \param separator Delimiter of list values
 * \return A vector of %IndexName objects
 */
QVector<IndexName> IndexName::parse(QString list, QString separator) {
    QVector<IndexName> result;
    QStringList parsedList = list.split(separator, QString::KeepEmptyParts);
    int items = parsedList.count();
    if (items < 2)
        return(result);

    for (int i = 0; i < items; i+=2) {
        result.append(IndexName(parsedList[i].toUInt(), parsedList[i+1]));
    }
    return(result);
}

/*!
 * \brief Parses a formatted list of %IndexName values
 * while ignoring instances of \c ignore
 *
 * A list of index,name pairs as follows:<br>
 * <tt>list = "index1,'name1',index2,'name2',...";</tt><br>
 *
 * can be parsed with the following snippet:
   \code
    IndexName::parse(list, ",", "\'");
   \endcode
 *
 * \param list List to parse
 * \param separator Delimiter of list values
 * \param ignore String instances to ignore while parsing
 * \return A vector of %IndexName objects
 */
QVector<IndexName> IndexName::parse(QString list, QString separator, QString ignore) {
    QString newList = list;
    return(parse(newList.remove(ignore), separator));
}

/*!
 * \brief Separates a list of \c %IndexNames into \c indices
 * and \c names
 *
 * \note Order of \c indexNames is preserved. Specifically,
 * indexNames[i] has index \c indices[i]
 * and name \c names[i].
 *
 * \param indexNames Group of %IndexName objects to separate
 * \param indices Indices of the %IndexName objects
 * \param names Names of the %IndexName objects
 */
void IndexName::separate(QVector<IndexName> indexNames, QVector<uint> &indices, QStringList &names) {
    indices.clear();
    names.clear();
    foreach(IndexName i, indexNames) {
        indices.append(i.index());
        names.append(i.name());
    }
}

/*!
 * \brief Returns the indices in \c indexNames
 *
 * \note Order of \c indexNames is preserved. Specifically,
 * indexNames[i] has \c i-th index of the return value.
 *
 * \param indexNames Group of %IndexName objects to separate
 * \return Indices of \c indexNames, in order
 */
QVector<uint> IndexName::indices(QVector<IndexName> indexNames) {
    QVector<uint> indices;
    QStringList names;
    separate(indexNames, indices, names);
    return(indices);
}

/*!
 * \brief Returns the names in \c indexNames
 *
 * \note Order of \c indexNames is preserved. Specifically,
 * indexNames[i] has \c i-th name of the return value.
 *
 * \param indexNames Group of %IndexName objects to separate
 * \return Names of the \c indexNames, in order
 */
QStringList IndexName::names(QVector<IndexName> indexNames) {
    QVector<uint> indices;
    QStringList names;
    separate(indexNames, indices, names);
    return(names);
}
