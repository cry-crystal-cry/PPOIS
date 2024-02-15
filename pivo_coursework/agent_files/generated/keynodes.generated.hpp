#include <memory>

#include "sc-memory/sc_memory.hpp"


#include "sc-memory/sc_event.hpp"




#define keynodes_hpp_18_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "Keynodes::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define keynodes_hpp_18_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "Keynodes::_InitStaticInternal"); \
    bool result = true; \
	question_find_subdividing = ctx.HelperResolveSystemIdtf("question_find_subdividing", ScType::Node); result = result && question_find_subdividing.IsValid(); \
	nrel_subdividing = ctx.HelperResolveSystemIdtf("nrel_subdividing", ScType::Node); result = result && nrel_subdividing.IsValid(); \
	question_find_isomorphic_structures = ctx.HelperResolveSystemIdtf("question_find_isomorphic_structures", ScType::Node); result = result && question_find_isomorphic_structures.IsValid(); \
	nrel_search_result = ctx.HelperResolveSystemIdtf("nrel_search_result", ScType::Node); result = result && nrel_search_result.IsValid(); \
	empty_set = ctx.HelperResolveSystemIdtf("empty_set", ScType::Node); result = result && empty_set.IsValid(); \
	question_find_diameter = ctx.HelperResolveSystemIdtf("question_find_diameter", ScType::Node); result = result && question_find_diameter.IsValid(); \
	nrel_diameter_node = ctx.HelperResolveSystemIdtf("nrel_diameter_node", ScType::Node); result = result && nrel_diameter_node.IsValid(); \
	diameter = ctx.HelperResolveSystemIdtf("diameter", ScType::Node); result = result && diameter.IsValid(); \
    return result; \
}


#define keynodes_hpp_18_decl 

#define keynodes_hpp_Keynodes_impl 

#undef ScFileID
#define ScFileID keynodes_hpp

