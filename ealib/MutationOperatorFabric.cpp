#include "OperatorFabric.h"

namespace ealib {

	OperatorFabric& OperatorFabric::getInstance()
	{
		static OperatorFabric instance;
		return instance;
	}
}
