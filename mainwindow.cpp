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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QList>
#include <QDebug>

#include "abstract_node_port_view.h"
#include "qstring_node_port_view.h"
#include "stringtestnodeimpl.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_nodeGridImpl = new TestNodeGridImpl;
    m_nodeGridScene = new NodeGridScene(m_nodeGridImpl);

    ui->nodeGridView->setScene(m_nodeGridScene);
    m_nodeGridScene->setSceneRect(QRect(QPoint(0,0),ui->nodeGridView->size()));

    on_addNode_clicked();


    ui->nodeGridView->setSceneRect(0, 0, ui->nodeGridView->width(), ui->nodeGridView->height());
    ui->nodeGridView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->nodeGridView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    AbstractIOGraphicsWidget *aiogw = AbstractIOGraphicsWidget::create<AbstractIOGraphicsWidget>();
//    AbstractIOGraphicsWidget *aiogw2 = AbstractIOGraphicsWidget::create<MainWindow>();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addNode_clicked()
{

    /*
    StringTestNodeImpl *nodeImpl = new StringTestNodeImpl("Node" + QString::number(m_nodes.size()));

    NodeView *nw = new NodeView(nodeImpl);
    m_nodes.append(nw);

    //qDebug() <<"Node: " <<nw->nodeName() <<"j: -1" <<" NodeGraphicsWidgetSize: " <<nw->size();
    //for( int j=0; j<3; j++){
    //    nw->addIOWidget(AbstractNodePortView::create<QStringNodePortView>(nw));
    //    qDebug() <<"Node: " <<nw->nodeName() <<"j: " <<j <<" NodeGraphicsWidgetSize: " <<nw->size();
    //}
    m_nodeGridScene->addNodeView(nw);
    */
}

void MainWindow::on_addIOWidget_clicked()
{
    if(m_nodes.size() < 1)
        return;
    /*
    NodeView *nw = m_nodes[m_nodes.size() - 1];
    nw->addIOWidget(AbstractNodePortView::create<QStringNodePortView>(nw));
    qDebug() <<"Node: " <<nw->nodeName() <<"j: **" <<" NodeGraphicsWidgetSize: " <<nw->size();
    */

}
