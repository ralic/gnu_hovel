/****************************************************************************

Copyright (C) 2010 Jonathan Crowe.

This file is part of Hovel.

Hovel is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Hovel is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Hovel.  If not, see <http://www.gnu.org/licenses/>.

****************************************************************************/


#ifndef PROPERTIESPROXYMODEL_H
#define PROPERTIESPROXYMODEL_H

#include <QAbstractProxyModel>

#include "hovelitem.h"

namespace Hovel
{
	enum PropertiesProxyColumn { PropertiesTitleColumn, PropertiesValueColumn };

	class PropertiesProxyModel : public QAbstractProxyModel
	{
	Q_OBJECT

	public:
		PropertiesProxyModel();

		QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
		QModelIndex parent(const QModelIndex &child) const;
		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;
		QModelIndex mapToSource(const QModelIndex &proxyIndex) const;
		QModelIndex mapFromSource(const QModelIndex &sourceIndex) const;
		QVariant data ( const QModelIndex &proxyIndex, int role = Qt::DisplayRole ) const;
		Qt::ItemFlags flags(const QModelIndex &index) const;
		bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
		const QStringList values ( int role ) const;
		const QStringList characters () const;
		const QStringList locations () const;

	private:
		DataRole indexDataRole(const QModelIndex &index) const;

	public slots:
		void selectionChanged(const QItemSelection& newSelection, const QItemSelection& previousSelection);

	private:
		QModelIndex			_selectedItem;
	};

}

#endif // PROPERTIESPROXYMODEL_H
