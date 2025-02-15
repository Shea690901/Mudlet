#ifndef MUDLET_TLINKSTORE_H
#define MUDLET_TLINKSTORE_H

/***************************************************************************
 *   Copyright (C) 2020 by Gustavo Sousa - gustavocms@gmail.com            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "pre_guard.h"
#include <QMap>
#include <QStringList>
#include <QVector>
#include "post_guard.h"

class Host;
// Keep together lists of links and hints associated
class TLinkStore {
    inline static const int scmMaxLinks = 20000;

    QMap<int, QStringList> mLinkStore;
    QMap<int, QStringList> mHintStore;
    QMap<int, QVector<int>> mReferenceStore;

    int mLinkID;
    int maxLinks;

public:
    TLinkStore() : TLinkStore(scmMaxLinks) {}

    explicit TLinkStore(int maxLinks) : mLinkID(0), maxLinks(maxLinks) {}

    int addLinks(const QStringList& links, const QStringList& hints, Host* pH = nullptr, const QVector<int>& luaReference = QVector<int>());

    QStringList& getLinks(int id);
    QStringList& getHints(int id);
    QStringList getLinksConst(int id) const;
    QStringList getHintsConst(int id) const;
    QVector<int> getReference(int id) const;

    int getCurrentLinkID() const;

    QStringList getCurrentLinks() const;
    void setCurrentLinks(const QStringList& links);

private:
    void freeReference(Host* pH, const QVector<int>& luaReference);
};

#endif //MUDLET_TLINKSTORE_H
