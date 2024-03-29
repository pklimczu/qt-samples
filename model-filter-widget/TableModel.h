#pragma once

#include <QObject>
#include <QAbstractItemModel>

struct Entry
{
    void addFromLine(QString line);

    QString origin;
    short year;
    QString color;

    bool operator==(const Entry &other) const
    {
        return origin == other.origin &&
                year == other.year &&
                color == other.color;
    }
};

class TableModel : public QAbstractTableModel
{
Q_OBJECT

public:
    TableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;

    QList<Entry> getEntries() const { return m_EntryList; }
    void readData(const QString &filePath);

private:
    QList<Entry> m_EntryList;
};
