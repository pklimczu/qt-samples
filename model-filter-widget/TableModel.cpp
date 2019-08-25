#include "TableModel.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

TableModel::TableModel(QObject *parent)
{
    Q_UNUSED(parent);
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_EntryList.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= m_EntryList.size() || index.row() < 0)
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        const auto &entry = m_EntryList.at(index.row());

        switch (index.column())
        {
        case 0:
            return entry.origin;
        case 1:
            return entry.year;
        case 2:
            return entry.color;
        default:
            return QVariant();
        }
    }

    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();

        auto entry = m_EntryList.value(row);

        switch (index.column())
        {
        case 0:
            entry.origin = value.toString();
            break;
        case 1:
            entry.year = static_cast<short>(value.toInt());
            break;
        case 2:
            entry.color = value.toString();
            break;
        default:
            return false;
        }

        m_EntryList.replace(row, entry);
        Q_EMIT dataChanged(index, index, {role});
        return true;
    }
    return false;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return tr("Origin");
        case 1:
            return tr("Year");
        case 2:
            return tr("Color");
        default:
            return QVariant();
        }
    }

    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index);
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++)
    {
        m_EntryList.removeAt(position);
    }

    endRemoveRows();
    return true;
}

void TableModel::readData(const QString& filePath)
{
    QFile file(filePath);
    removeRows(0, m_EntryList.size());

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textStream(&file);
        while (!textStream.atEnd())
        {
            Entry entry;
            entry.addFromLine(textStream.readLine());
            m_EntryList.append(entry);
        }
    }
    insertRows(0, m_EntryList.size());
}

void Entry::addFromLine(QString line)
{
    origin = line.split(",")[0];
    year = static_cast<short>(line.split(",")[1].toInt());
    color = line.split(",")[2];
}
