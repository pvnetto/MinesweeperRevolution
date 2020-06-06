#pragma once

#include "BaseContext.h"

class ContextManager {
private:
	BaseContext* currentContext;

public:
	void switchContext(BaseContext& newContext);
	void run();

};