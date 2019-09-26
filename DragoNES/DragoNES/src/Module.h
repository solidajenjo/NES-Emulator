#ifndef __MODULE_H_
#define __MODULE_H_

class Module
{
public:
	Module();
	virtual ~Module() = 0;

	virtual bool Start() { return true; }
	virtual bool Update() { return true; }
	virtual bool Close() { return true; }
};

#endif