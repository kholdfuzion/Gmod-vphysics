#ifndef CPHYSICSMOTIONCONTROLLER_H
#define CPHYSICSMOTIONCONTROLLER_H

#include "IController.h"

class CPhysicsEnvironment;

class CPhysicsMotionController : public IController, public IPhysicsMotionController {
public:
	CPhysicsMotionController(IMotionEvent *pHandler, CPhysicsEnvironment *pEnv);
	virtual ~CPhysicsMotionController();
	virtual void SetEventHandler(IMotionEvent* handler);
	virtual void AttachObject(IPhysicsObject* pObject, bool checkIfAlreadyAttached);
	virtual void DetachObject(IPhysicsObject* pObject);

	virtual int CountObjects();
	virtual void GetObjects(IPhysicsObject** pObjectList);
	virtual void ClearObjects();
	virtual void WakeObjects();

	virtual void SetPriority(priority_t priority);
public:
	virtual void Tick(float deltaTime);
private:
	IMotionEvent* m_handler;
	CUtlVector<btCollisionObject*> m_objectList;
	CPhysicsEnvironment* m_pEnv;
};

IPhysicsMotionController *CreateMotionController(CPhysicsEnvironment *pEnv, IMotionEvent *pHandler);

#endif
