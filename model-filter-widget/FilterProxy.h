#ifndef FILTERPROXY_H
#define FILTERPROXY_H
#include <QSortFilterProxyModel>

class FilterProxy : public QSortFilterProxyModel
{
Q_OBJECT
public:
    FilterProxy(QObject *parent = nullptr);
    void addStringToBeFiltred(const QString& string);
    void removeStringFromBeingFiltred(const QString& string);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
//    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
    QList<QString> m_FiltredStringList;
};

#endif // FILTERPROXY_H
