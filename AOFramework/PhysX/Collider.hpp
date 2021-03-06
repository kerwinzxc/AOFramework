/*************************************************************
*	@file   	Collider.hpp
*	@brief  	ColliderNXwb_[
*	@author		Tatsunori Aoyama
*	@date		2014/08/22
*************************************************************/

#ifndef _Include_Collider_hpp_	// CN[hK[h
#define _Include_Collider_hpp_

//------------------------------------------------------------
// CN[h
//------------------------------------------------------------
#include<Windows.h>
#include"PhysXHeader.hpp"
#include"PhysX.hpp"
#include"../Math/Math.hpp"


using namespace DirectX;

namespace ao
{
	class PhysX;

	enum class ColliderType : int{
		Plane,
		Box,
		Sphere,
		Capsule,
		Max
	};

	/*!-----------------------------------------------------------
	//	@class  Collider
	//	@brief  RC_[NX
	//	@author	Tatsunori Aoyama
	//	@date	2014/08/22
	------------------------------------------------------------*/
	class Collider
	{
	public:
		Collider(
			PhysX* _pPhysx,						///< tBWbNXÇNX
			const physx::PxGeometry& _geometry,	///< `ó
			float _staticFriction,				///< ÃCW(0.0f~1.0f)
			float _dynamicFriction,				///< ®CW(0.0f~1.0f)
			float _restitution);				///< ½­W(0.0f~1.0f)

		~Collider();

		/*!-----------------------------------------------------------
		//	@brief		}`æ¾
		//	@return		}`ÌíÞ
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/22
		------------------------------------------------------------*/
		virtual	ColliderType GetColliderType() const = 0;

		/*!-----------------------------------------------------------
		//	@brief		o^µ½PhysXÌ}`æ¾
		//	@return		o^µ½}`
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/22
		------------------------------------------------------------*/
		physx::PxShape* GetPxShape(){
			return this->pShape;
		}

		/*!-----------------------------------------------------------
		//	@brief		Îp¨ðÝè
		//	@param[in]	_x	XÀW
		//	@param[in]	_y	YÀW
		//	@param[in]	_z	ZÀW
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/22
		------------------------------------------------------------*/
		void SetLocalPose(float _x, float _y, float _z){
			this->pShape->setLocalPose(physx::PxTransform(physx::PxVec3(_x, _y, _z)));
		}

		/*!-----------------------------------------------------------
		//	@brief		Îp¨ðÝè
		//	@param[in]	_xPos	XÀW
		//	@param[in]	_yPos	YÀW
		//	@param[in]	_zPos	ZÀW
		//	@param[in]	_xRot	Xñ]Ê
		//	@param[in]	_yRot	Yñ]Ê
		//	@param[in]	_zRot	Zñ]Ê
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/22
		------------------------------------------------------------*/
		void SetLocalPose(float _xPos, float _yPos, float _zPos, float _xRot, float _yRot, float _zRot){
			XMFLOAT4X4 mtx;
			ao::MatrixIdentity(&mtx);
			ao::MatrixRollPitchYaw(&mtx, _xRot, _yRot, _zRot);
			ao::MatrixSetOffset(&mtx, _xPos, _yPos, _zPos);
			this->pShape->setLocalPose(physx::PxTransform(physx::PxMat44((float*)&mtx)));
		}

		/*!-----------------------------------------------------------
		//	@brief		gK[}`ÌÝè
		//	@param[in]	_isEnable	gK[ÌL³[ÈªÂ]
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/22
		------------------------------------------------------------*/
		void	EnableTriggerShape(bool _isEnable = false){
			if (_isEnable){
				this->pShape->setFlag(physx::PxShapeFlag::eSIMULATION_SHAPE, false);
				this->pShape->setFlag(physx::PxShapeFlag::eTRIGGER_SHAPE, true);
			}
			else{
				this->pShape->setFlag(physx::PxShapeFlag::eTRIGGER_SHAPE, false);
				this->pShape->setFlag(physx::PxShapeFlag::eSIMULATION_SHAPE, true);
			}
		}

	protected:
		physx::PxMaterial* pMaterial;
		physx::PxShape* pShape;
	};

	/*!-----------------------------------------------------------
	//	@class  PlaneCollider
	//	@brief  v[RC_[NX
	//	@author	Tatsunori Aoyama
	//	@date	2014/08/24
	------------------------------------------------------------*/
	class PlaneCollider : public Collider
	{
	public:
		/*!-----------------------------------------------------------
		//	@brief		RXgN^
		//	@param[in]	_pPhysx			tBWbNXÇNX
		//	@param[in]	_halfWidth		Ì¼ª[ÈªÂ]
		//	@param[in]	_halfDepth		s«Ì¼ª[ÈªÂ]
		//	@param[in]	_sFriction		ÃCW(0.0f-1.0f)[ÈªÂ]
		//	@param[in]	_dFriction		®CW(0.0f-1.0f)[ÈªÂ]
		//	@param[in]	_restitution	½­W(0.0f-1.0f)[ÈªÂ]
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/22
		------------------------------------------------------------*/
		PlaneCollider(
			PhysX* _pPhysx,
			float _halfWidth = 0.5f,
			float _halfDepth = 0.5f,
			float _sFriction = 1.0f,
			float _dFriction = 1.0f,
			float _restitution = 0.0f);

		/*!-----------------------------------------------------------
		//	@brief		}`æ¾
		//	@return		}`ÌíÞ
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/24
		------------------------------------------------------------*/
		ColliderType GetColliderType() const final {
			return ColliderType::Plane;
		}
	};

	/*!-----------------------------------------------------------
	//	@class  BoxCollider
	//	@brief  {bNXRC_[NX
	//	@author	Tatsunori Aoyama
	//	@date	2014/08/24
	------------------------------------------------------------*/
	class BoxCollider : public Collider
	{
	public:
		/*!-----------------------------------------------------------
		//	@brief		RXgN^
		//	@param[in]	_pPhysx			tBWbNXÇNX
		//	@param[in]	_radius			¼a[ÈªÂ]
		//	@param[in]	_sFriction		ÃCW(0.0f-1.0f)[ÈªÂ]
		//	@param[in]	_dFriction		®CW(0.0f-1.0f)[ÈªÂ]
		//	@param[in]	_restitution	½­W(0.0f-1.0f)[ÈªÂ]
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/24
		------------------------------------------------------------*/
		BoxCollider(
			PhysX* _pPhysx,
			float _halfWidth = 0.5f,
			float _halfHeight = 0.5f,
			float _halfDepth = 0.5f,
			float _sFriction = 1.0f,
			float _dFriction = 1.0f,
			float _restitution = 0.0f);

		/*!-----------------------------------------------------------
		//	@brief		}`æ¾
		//	@return		}`ÌíÞ
		//	@author		Tatsunori Aoyama
		//	@date		2014/08/24
		------------------------------------------------------------*/
		ColliderType GetColliderType() const final {
			return ColliderType::Box;
		}
	private:
		float halfWidth;
		float halfHeight;
		float halfDepth;
	};

	/*!-----------------------------------------------------------
	//	@class  SphereCollider
	//	@brief  XtBARC_[NX
	//	@author	Tatsunori Aoyama
	//	@date	2014/08/24
	------------------------------------------------------------*/
	class SphereCollider : public Collider
	{
	public:
		/*!-----------------------------------------------------------
		//	@brief		RXgN^
		//	@param[in]	_pPhysx			tBWbNXÇNX
		//	@param[in]	_radius			¼a[ÈªÂ]
		//	@param[in]	_sFriction		ÃCW(0.0f-1.0f)[ÈªÂ]
		//	@param[in]	_dFriction		®CW(0.0f-1.0f)[ÈªÂ]
		//	@param[in]	_restitution	½­W(0.0f-1.0f)[ÈªÂ]
		------------------------------------------------------------*/
		SphereCollider(
			PhysX* _pPhysx,
			float _radius = 0.5f,
			float _sFriction = 1.0f,
			float _dFriction = 1.0f,
			float _restitution = 0.0f);

		//----------------------------------------------------------------------
		/**	@brief		}`ÌíÞðæ¾
		//	@return		}`ÌíÞ */
		//----------------------------------------------------------------------
		ColliderType GetColliderType() const final {
			return ColliderType::Sphere;
		}
	private:
		float radius;
	};

	/*!-----------------------------------------------------------
	//	@class  CapsuleCollider
	//	@brief  JvZRC_[NX
	//	@author	Tatsunori Aoyama
	//	@date	2014/08/24
	------------------------------------------------------------*/
	class CapsuleCollider : public Collider
	{
	public:
		/*!-----------------------------------------------------------
		//	@brief		RXgN^
		//	@param[in]	_pPhysx			tBWbNXÇNX
		//	@param[in]	_radius			¼a[ÈªÂ]
		//	@param[in]	_halfHeight		³Ì¼ª[ÈªÂ]
		//	@param[in]	_sFriction		ÃCW(0.0f-1.0f)[ÈªÂ]
		//	@param[in]	_dFriction		®CW(0.0f-1.0f)[ÈªÂ]
		//	@param[in]	_restitution	½­W(0.0f-1.0f)[ÈªÂ]
		------------------------------------------------------------*/
		CapsuleCollider(
			PhysX* _pPhysx,
			float _radius = 0.5f,
			float _halfHeight = 0.5f,
			float _sFriction = 1.0f,
			float _dFriction = 1.0f,
			float _restitution = 0.0f);

		//----------------------------------------------------------------------
		/**	@brief		}`ÌíÞðæ¾
		//	@return		}`ÌíÞ */
		//----------------------------------------------------------------------
		ColliderType GetColliderType() const final {
			return ColliderType::Capsule;
		}
	private:
		float radius;
		float halfHeight;
	};
}

#endif // _Include_Collider_hpp_