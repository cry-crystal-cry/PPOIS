#pragma once

#include <sc-memory/kpm/sc_agent.hpp>
#include <sc-memory/cpp/sc_link.hpp>
#include "keynodes/keynodes.hpp"

#include "GraphAgent.generated.hpp"


using ScAddrUsedVector = std::vector<std::pair<ScAddr, bool>>;

namespace exampleModule{
	class GraphAgent : public ScAgent {
 		SC_CLASS(Agent, Event(Keynodes::question_find_diameter, ScEvent::Type::AddOutputEdge))
 		SC_GENERATED_BODY()

		void formResponseConstruction(ScAddr const& inputGraphObject, ScAddrVector& answerElements, int& diameter);

		int graphDiameter(ScAddr const& inputGraphObject);

		std::vector<int> BFS(ScAddr const& inputGraphObject, ScAddr start);

		std::vector<int> formEccentricitiesVector(ScAddr const& inputGraphObject);

		ScAddrVector findVertexNeighbors(ScAddr const& inputGraphObject, ScAddr vertex);

		ScAddrVector formVertexesVector(ScAddr const& inputGraphObject);

		int findVertexIndex(ScAddrVector vertexes, ScAddr vertex);
	};
}
