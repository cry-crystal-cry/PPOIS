#include "pch.h"
#include "CppUnitTest.h"
#include "lab4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab4UnitTest
{
	TEST_CLASS(ConstuctorsDestructorsUnitTest)
	{
	public:
		TEST_METHOD(DefaultoConstructorDestructorTest)
		{
			DirectedGraph<int> graph;
			Assert::IsTrue(true);
		}
		TEST_METHOD(CopyConstructorTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(3);
			graph.addEdge(3, 1);
			DirectedGraph<int> g(graph);
			Assert::IsTrue(g == graph);
		}
	};

	TEST_CLASS(FunctionsUnitTest)
	{
	public:
		TEST_METHOD(AddNodeTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			Assert::IsTrue(true);
			auto error = [] {
				DirectedGraph<int> graph; 
				graph.addNode(1);
				graph.addNode(1);
			};
			Assert::ExpectException<std::exception>(error);
		}
		TEST_METHOD(AddEdgeTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(2);
			graph.addEdge(1, 2);
			Assert::IsTrue(true);
			auto error = [] {
				DirectedGraph<int> graph;
				graph.addEdge(1, 2);
			};
			Assert::ExpectException<std::exception>(error);
		}
		TEST_METHOD(EmptyTest)
		{
			DirectedGraph<int> graph;
			Assert::IsTrue(graph.empty());
		}
		TEST_METHOD(ClearTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(3);
			graph.addEdge(3, 1);
			graph.clear();
			Assert::IsTrue(graph.empty());
		}
		TEST_METHOD(NodePresenceTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			Assert::IsTrue(graph.nodePresence(1));
		}
		TEST_METHOD(EdgePresenceTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(3);
			graph.addEdge(3, 1);
			Assert::IsTrue(graph.edgePresence(3, 1));
		}
		TEST_METHOD(GetNodeCountTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(3);
			graph.addNode(6);
			graph.addNode(321);
			Assert::IsTrue(graph.getNodeCount() == 4);
		}
		TEST_METHOD(GetEdgeCountTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(3);
			graph.addEdge(1, 3);
			graph.addEdge(1, 3);
			graph.addEdge(3, 1);
			graph.addEdge(1, 1);
			Assert::IsTrue(graph.getEdgeCount() == 4);
		}
		TEST_METHOD(DeleteEdgeTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(3);
			graph.addEdge(1, 3);
			graph.deleteEdge(1, 3);
			Assert::IsTrue(graph.getEdgeCount() == 0);
		}
		TEST_METHOD(DeleteNodeTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(3);
			graph.addEdge(1, 3);
			graph.deleteNode(1);
			Assert::IsTrue(graph.getEdgeCount() == 0 && graph.getNodeCount() == 1);
		}
	};

	TEST_CLASS(OperatorsUnitTest)
	{
	public:
		TEST_METHOD(OperatorEqualTest)
		{
			DirectedGraph<int> graph, g;
			graph.addNode(1);
			graph.addNode(3);
			graph.addEdge(1, 3);
			g.addNode(1);
			g.addNode(3);
			g.addEdge(1, 3);
			Assert::IsTrue(g == graph);
		}
		TEST_METHOD(OperatorNotEqualTest)
		{
			DirectedGraph<int> graph, g;
			graph.addNode(1);
			graph.addNode(2);
			graph.addNode(3);
			graph.addEdge(1, 2);
			graph.addEdge(1, 3);
			g.addNode(1);
			g.addNode(3);
			g.addNode(2);
			graph.addEdge(1, 3);
			graph.addEdge(1, 2);
			Assert::IsTrue(g != graph);
		}
		TEST_METHOD(OperatorAssignTest)
		{
			DirectedGraph<int> graph, g;
			graph.addNode(1);
			graph.addNode(3);
			graph.addEdge(1, 3);
			g = graph;
			Assert::IsTrue(g == graph);
		}
	};
	TEST_CLASS(GettersUnitTest)
	{
	public:
		TEST_METHOD(GetAdjacencyListTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(2);
			graph.addNode(3);
			graph.addEdge(1, 2);
			graph.addEdge(1, 3);
			graph.getAdjacencyList();
			Assert::IsTrue(true);
		}
		TEST_METHOD(GetNodeAdjacencyListTest)
		{
			DirectedGraph<int> graph;
			graph.addNode(1);
			graph.addNode(2);
			graph.addNode(3);
			graph.addEdge(1, 2);
			graph.addEdge(1, 3);
			graph.getNodeAdjacencyList(2);
			Assert::IsTrue(true);
		}
	};
}
