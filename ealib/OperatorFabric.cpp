#include "OperatorFabric.h"

namespace ealib {

	OperatorCPUFabric& OperatorCPUFabric::getInstance()
	{
		static OperatorCPUFabric instance;
		return instance;
	}

	OperatorGPUFabric& OperatorGPUFabric::getInstance()
	{
		static OperatorGPUFabric instance;
		return instance;
	}
	
}
