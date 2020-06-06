#pragma once

class BaseContext {
protected:
	virtual void draw() = 0;
	virtual void handleEvents() = 0;

public:
	void run();

};