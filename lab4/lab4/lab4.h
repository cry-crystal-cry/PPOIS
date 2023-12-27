#include <vector>
#include <iostream>
#include <iterator>
#include <unordered_set>

template <typename T>
class DirectedGraph
{
public:
	typedef T ValueType;
	typedef std::unordered_multiset<ValueType> ListOfNodes;
	typedef std::pair<ValueType, ListOfNodes> AdjacencyListOfNode;
	typedef std::vector<AdjacencyListOfNode> AdjacencyList;

	typedef typename AdjacencyList::iterator nodeAdAdjacencyListIterator;
	nodeAdAdjacencyListIterator begin() const { return adjacencyList.begin(); }
	nodeAdAdjacencyListIterator end() const { return adjacencyList.end(); }

	DirectedGraph() = default;
	DirectedGraph(const DirectedGraph& other) {
		adjacencyList = other.adjacencyList;
	}
	~DirectedGraph() = default;

	bool empty() const {
		return adjacencyList.empty();
	}
	void clear() {
		adjacencyList.clear();
	}

	bool nodePresence(const ValueType& node_) const{
		for (const auto adjacencyListOfNode : adjacencyList)
			if (adjacencyListOfNode.first == node_)
				return true;
		return false;
	}
	bool edgePresence(const ValueType& firstNode_, const ValueType& secondNode_) {
		for (const auto node : getNodeAdjacencyList(firstNode_))
			if (node == secondNode_)
				return true;
		return false;
	}

	void addNode(const ValueType& node_) {
		if (nodePresence(node_))
			throw std::exception("Node is already exist");
		adjacencyList.push_back(std::make_pair(node_, ListOfNodes()));
	}
	void addEdge(const ValueType& firstNode_, const ValueType& secondNode_) {
		if (!nodePresence(firstNode_) || !nodePresence(secondNode_))
			throw std::exception("Node not exist");
		getNodeAdjacencyListPtr(firstNode_)->insert(secondNode_);
	}

	size_t getNodeCount()const {
		return adjacencyList.size();
	}
	size_t getEdgeCount() const {
		size_t count = 0;
		for (const auto adjacencyListOfNode : adjacencyList)
			count += adjacencyListOfNode.second.size();
		return count;
	}

	size_t getNodeDegree(const ValueType& node_) const{
		if (!nodePresence(node_))
			throw std::exception("Node not exist");
		return getNodeAdjacencyList(node_)->size();
	}
	size_t getEdgeDegree(const ValueType& firstNode_, const ValueType& secondNode_) {
		if (!nodePresence(firstNode_) || !nodePresence(secondNode_))
			throw std::exception("Node not exist");
		size_t count = 0;
		for (const auto node : getNodeAdjacencyList(firstNode_))
			if (node == secondNode_)
				count++;
		return count;
	}

	void deleteEdge(const ValueType& firstNode_, const ValueType& secondNode_) {
		if (!nodePresence(firstNode_) || !nodePresence(secondNode_))
			throw std::exception("Node not exist");
		if(!edgePresence(firstNode_,secondNode_))
			throw std::exception("Edge not exist");
		ListOfNodes* firstNodeAdjacencyList = getNodeAdjacencyListPtr(firstNode_);
		firstNodeAdjacencyList->erase(firstNodeAdjacencyList->find(secondNode_));

	}
	void deleteNode(const ValueType& node_) {
		if (!nodePresence(node_))
			throw std::exception("Node not exist");

		for (const auto adjacencyListOfNode : adjacencyList)
			for (int i = 0; i < getEdgeDegree(adjacencyListOfNode.first, node_); i++)
				deleteEdge(adjacencyListOfNode.first, node_);

		for (int i = 0; i < adjacencyList.size(); i++)
			if (adjacencyList[i].first == node_)
				adjacencyList.erase(adjacencyList.begin() + i);
	}

	bool operator==(DirectedGraph<ValueType>& other) {
		if (adjacencyList.size() != other.adjacencyList.size())
			return false;

		for (const auto adjacencyListOfNode : adjacencyList) {
			if (getNodeAdjacencyList(adjacencyListOfNode.first) != other.getNodeAdjacencyList(adjacencyListOfNode.first))
				return false;
		}
		return true;
	}
	bool operator!=(const DirectedGraph<ValueType>& other) const {
		return adjacencyList != other.adjacencyList;
	}
	void operator=(DirectedGraph<ValueType>& other) {
		adjacencyList = other.adjacencyList;
	}

	AdjacencyList getAdjacencyList() const { return adjacencyList; };
	ListOfNodes getNodeAdjacencyList(const ValueType& node_) {
		for (int i = 0; i < adjacencyList.size(); i++)
			if (adjacencyList[i].first == node_)
				return adjacencyList[i].second;
	}
private:
	AdjacencyList adjacencyList;
	ListOfNodes* getNodeAdjacencyListPtr(const ValueType& node_) {
		for (int i = 0; i < adjacencyList.size(); i++)
			if (adjacencyList[i].first == node_)
				return &(adjacencyList[i].second);
	}
};
