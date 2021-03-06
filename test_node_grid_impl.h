/*
 * Copyright 2016  Niclas Roßberger
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef TESTNODEGRIDIMPL_H
#define TESTNODEGRIDIMPL_H

#include "i_node_grid_impl.h"
#include "stringtestnodeimpl.h"

#include <QMap>
#include <QUuid>

class TestNodeGridImpl : public INodeGridImpl
{
public:
    TestNodeGridImpl();


    QList<INodeImpl *> getAllNodes() override;
    INodeImpl *getNode(const NodePortAddress &address) override;
    bool addNewNode(const QString &nodeClassName) override;
    bool addNode(INodeImpl * node);
    bool removeNode(const NodePortAddress &nodeAddress) override;
    QUuid getNodeGridAddress() override;
    INodeGridStateListener *setINodeGridStateListener(INodeGridStateListener *listener) override;
    INodeGridStateListener *getINodeGridStateListener() override;


protected:
    QMap<QUuid, INodeImpl *> m_nodes;
    QUuid m_sceneAddress = QUuid::createUuid();

    INodeGridStateListener *m_listener = nullptr;

};

#endif // TESTNODEGRIDIMPL_H
