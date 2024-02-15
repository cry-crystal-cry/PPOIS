#include <sc-agents-common/utils/GenerationUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/IteratorUtils.hpp>

////#include <sc-memory/cpp/sc_link.hpp> ////

#include "GraphAgent.hpp"

#include <queue>

using namespace std;
using namespace utils;

namespace exampleModule 
{
	SC_AGENT_IMPLEMENTATION(GraphAgent) 
	{
		ScAddr actionNode = otherAddr;
		ScAddr inputGraphObject = IteratorUtils::getAnyFromSet(ms_context.get(), actionNode);

		if(!inputGraphObject.IsValid())
		{
			SC_LOG_ERROR("invalid input data");
			utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, false);
			return SC_RESULT_ERROR_INVALID_PARAMS;
		}

		int diameter = graphDiameter(inputGraphObject);	
		ScAddrVector answerElements;
		formResponseConstruction(inputGraphObject, answerElements, diameter);

		
		SC_LOG_DEBUG("Diameter is:");
		SC_LOG_DEBUG(diameter);
		utils::AgentUtils::finishAgentWork(ms_context.get(), actionNode, answerElements, true);
 		return SC_RESULT_OK;
	}
	
	void GraphAgent::formResponseConstruction(ScAddr const& inputGraphObject, ScAddrVector& answerElements, int& diameter)
	{
		ScAddr diameterNode = m_memoryCtx.CreateNode(ScType::NodeConst);
		////ScLink diameterLink(linkAddr); ////
		////diameterLink.Set(diameter); ////
		ScLink link(linkAddr);

		m_memoryCtx.HelperSetSystemIdtf(std::to_string(diameter),diameterNode);
		ScAddr edgeToDiameter = m_memoryCtx.CreateEdge(ScType::EdgeDCommonConst, inputGraphObject, diameterNode);
		ScAddr relativeEdge = m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, Keynodes::nrel_diameter_node, edgeToDiameter);
		answerElements.insert(answerElements.end(),{inputGraphObject,Keynodes::nrel_diameter_node,diameterNode,edgeToDiameter,relativeEdge});
		///////answerElements.insert(answerElements.end(),{edgeToDiameter,Keynodes::diameter});



		//answerElements.insert(answerElements.end(), {Keynodes::nrel_diameter_node, relativeEdge, edgeToDiameter});
		//answerElements.insert(answerElements.end(), {inputGraphObject, edgeToDiameter, diameterNode});
	}



	int GraphAgent::graphDiameter(ScAddr const& inputGraphObject)
	{
		vector<int> eccentricities = formEccentricitiesVector(inputGraphObject);
		int diameter = eccentricities[0];
		for(size_t i = 1; i < eccentricities.size(); i ++)
			diameter = max(diameter, eccentricities[i]);
		return diameter;
	}


	vector<int> GraphAgent::formEccentricitiesVector(ScAddr const& inputGraphObject)
	{
		ScAddrVector vertexes = formVertexesVector(inputGraphObject);
		vector<int> eccentrities;
		for(size_t i = 0; i < vertexes.size(); i ++)
		{
			vector<int> distances = BFS(inputGraphObject, vertexes[i]);
			int eccentricity = distances[0];
			for(size_t j = 1; j < distances.size(); j ++)
				eccentricity = max(eccentricity, distances[j]);
			eccentrities.insert(eccentrities.end(), eccentricity);
		}
		return eccentrities;
	}
	
	vector<int> GraphAgent::BFS(ScAddr const& inputGraphObject, ScAddr start)
	{
		ScAddrVector vertexes = formVertexesVector(inputGraphObject);
		vector<int> distances(vertexes.size(), 0);
		ScAddrUsedVector usedVertexes;
		for(size_t i = 0; i < vertexes.size(); i ++)
			usedVertexes.insert(usedVertexes.end(), {vertexes[i], false});
		int startIndex = findVertexIndex(vertexes, start);
		usedVertexes[startIndex].second = true;
		queue<ScAddr> vertexQueue;
		vertexQueue.push(start);
		while(!vertexQueue.empty())
		{
			ScAddr currentVertex = vertexQueue.front();
			int currentVertexIndex = findVertexIndex(vertexes, currentVertex);
			vertexQueue.pop();
			ScAddrVector neighbors = findVertexNeighbors(inputGraphObject, currentVertex);
			for(size_t i = 0; i < neighbors.size(); i ++)
			{
				int neighborIndex = findVertexIndex(vertexes, neighbors[i]);
				if(!usedVertexes[neighborIndex].second)
				{
					vertexQueue.push(neighbors[i]);
					usedVertexes[neighborIndex].second = true;
					distances[neighborIndex] = distances[currentVertexIndex] + 1;
				}
			}
		}
		return distances;
	}
	
	ScAddrVector GraphAgent::findVertexNeighbors(ScAddr const& inputGraphObject, ScAddr vertex)
	{
		ScAddrVector neighbors;

		ScIterator5Ptr it5 = m_memoryCtx.Iterator5(
			vertex,
			ScType::EdgeUCommon,
			ScType::NodeConst,
			ScType::EdgeAccessConstPosPerm,
			inputGraphObject
		);
		while(it5->Next())
		{
			neighbors.insert(neighbors.end(), it5->Get(2));
		}

		ScIterator5Ptr it5_2 = m_memoryCtx.Iterator5(
			ScType::NodeConst,
			ScType::EdgeUCommon,
			vertex,
			ScType::EdgeAccessConstPosPerm,
			inputGraphObject
		);
		while(it5_2->Next())
		{
			neighbors.insert(neighbors.end(), it5_2->Get(0));
		}
		return neighbors;
	}

	ScAddrVector GraphAgent::formVertexesVector(ScAddr const& inputGraphObject)
	{
		ScAddrVector vertexes;
		ScIterator3Ptr it3 = m_memoryCtx.Iterator3(
			inputGraphObject,
			ScType::EdgeAccessConstPosPerm,
			ScType::NodeConst
		);
		while(it3->Next())
		{
			vertexes.insert(vertexes.end(), it3->Get(2));
		}
		return vertexes;
	}
	
	int GraphAgent::findVertexIndex(ScAddrVector vertexes, ScAddr vertex)
	{
		for(size_t i = 0; i < vertexes.size(); i ++)
			if(vertexes[i] == vertex)
				return i;
		return -1;
	}
}
