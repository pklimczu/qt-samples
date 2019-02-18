#include "FilterProxy.h"

FilterProxy::FilterProxy(QObject *parent)
    : QSortFilterProxyModel(parent)
{}

void FilterProxy::addStringToBeFiltred(const QString &string)
{
    m_FiltredStringList.append(string);
    invalidateFilter();
}

void FilterProxy::removeStringFromBeingFiltred(const QString &string)
{
    m_FiltredStringList.removeOne(string);
    invalidateFilter();
}

bool FilterProxy::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex indexColor = sourceModel()->index(sourceRow, 2, sourceParent);
    QString color = sourceModel()->data(indexColor).toString();

    return !m_FiltredStringList.contains(color);
}
