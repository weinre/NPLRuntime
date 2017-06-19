#pragma once

#include "Physics/PhysicsObject.h"

namespace ParaEngine {
	class CPhysicsShape;
	class CPhysicsConstraint;

	class CPhysicsBody : public CPhysicsObject
	{
		friend class CPhysicsWorld;
	protected:
		CPhysicsBody(IParaPhysicsBody* pBody);

	public:
		virtual ~CPhysicsBody();

		IParaPhysicsBody* get();

		ATTRIBUTE_DEFINE_CLASS(CPhysicsBody);

		int GetInternalType() const;

	protected:
		IParaPhysicsBody* m_pBody;
	};

	class CPhysicsRigidBody : public CPhysicsBody
	{
		friend class CPhysicsWorld;
	protected:
		CPhysicsRigidBody(IParaPhysicsRigidbody* pBody, CPhysicsShape* pShape);
	public:
		virtual ~CPhysicsRigidBody();

		ATTRIBUTE_DEFINE_CLASS(CPhysicsRigidBody);

		void SetConstraint(CPhysicsConstraint* p);
		bool isConstrainted();

		// is this rigidbody added to physics world?
		bool isInWorld() const;
		// convert this body to kinematic body
		void Convert2Kinematic();

		typedef weak_ptr<IObject, CPhysicsRigidBody>  WeakPtr;
	private:
		ref_ptr<CPhysicsShape> m_pShape;
		CPhysicsConstraint* m_pConstraint;
	};
}