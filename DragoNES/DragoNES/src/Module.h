#ifndef __MODULE_H_
#define __MODULE_H_

class Module
{
public:

	virtual ~Module() {};

	virtual bool Start() { return true; }
	virtual bool PreUpdate() { return true; }
	virtual bool Update() { return true; }
	virtual bool PostUpdate() { return true; }
	virtual bool Close() { return true; }

	
};

#endif