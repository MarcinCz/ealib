#include "ObjectFactory.h"

namespace ealib {

	CPUObjectFactory& CPUObjectFactory::getInstance()
	{
		static CPUObjectFactory instance;
		return instance;
	}

	GPUObjectFactory& GPUObjectFactory::getInstance()
	{
		static GPUObjectFactory instance;
		return instance;
	}
	
}
