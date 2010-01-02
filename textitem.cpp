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


#include "textitem.h"

namespace Hovel
{

	TextItem::TextItem(HovelItem * parent, QString title, QString text)
		: HovelItem()
	{
		_parentItem = parent;
		_roleData[TitleRole] = title;
		_roleData[TextRole] = text;
		_roleData[Qt::DecorationRole] = QIcon(QObject::tr(":/images/text"));
	}

	HovelItem * TextItem::child(int row)
	{
		return _childItems.value(row);
	}

	bool TextItem::isModified()
	{
		return true;
	}

	QDomElement TextItem::toQDomElement(QDomDocument& doc)
	{
		QDomElement e = doc.createElement("Text");
		e.setAttribute("Title", _roleData[TitleRole].toString());
		QString text = _roleData[TextRole].toString();
		QDomText textNode = doc.createTextNode(text);
		e.appendChild(textNode);

		foreach(HovelItem * item, _childItems) {
			e.appendChild(item->toQDomElement(doc));
		}

		return e;
	}

	void TextItem::fromQDomElement(QDomElement &el)
	{
		QDomText dt = el.firstChild().toText();
		if(dt.isNull()) return;
		_roleData[TextRole] = dt.data();
	}

}