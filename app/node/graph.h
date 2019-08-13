/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef NODEGRAPH_H
#define NODEGRAPH_H

#include <QObject>

#include "node/node.h"

/**
 * @brief A collection of nodes
 */
class NodeGraph : public QObject
{
  Q_OBJECT
public:
  /**
   * @brief NodeGraph Constructor
   */
  NodeGraph();

  /**
   * @brief Add a node to this graph
   *
   * The node will get added to this graph. It is not automatically connected to anything, any connections will need to
   * be made manually after the node is added. The graph takes ownership of the Node.
   */
  void AddNode(Node* node);

  /**
   * @brief Adds a node to this graph and all nodes connected to its inputs
   *
   * Adds the Node to the graph and runs through its inputs adding all of its dependencies (and all of their
   * dependencies and so forth).
   */
  void AddNodeWithDependencies(Node* node);

  /**
   * @brief Removes a Node from the graph BUT doesn't destroy it. Ownership is returned to the caller.
   */
  void TakeNode(Node* node);

  /**
   * @brief Retrieve a complete list of the nodes belonging to this graph
   */
  QList<Node*> nodes();

  /**
   * @brief Returns whether a certain Node is in the graph or not
   */
  bool ContainsNode(Node* n);

signals:
  /**
   * @brief Signal emitted when a Node is added to the graph
   */
  void NodeAdded(Node* node);

  /**
   * @brief Signal emitted when a Node is removed from the graph
   */
  void NodeRemoved(Node* node);

  /**
   * @brief Signal emitted when a member node of this graph has been connected to another (creating an "edge")
   */
  void EdgeAdded(NodeEdgePtr edge);

  /**
   * @brief Signal emitted when a member node of this graph has been disconnected from another (removing an "edge")
   */
  void EdgeRemoved(NodeEdgePtr edge);

private:
};

#endif // NODEGRAPH_H
