/*************************************************************
*	@file   	UiObject.hpp
*	@brief  	UiObjectNXwb_[
*	@author		Tatsunori Aoyama
*	@date		2014/02/10
*************************************************************/

#ifndef _Include_UiObject_hpp_	// CN[hK[h
#define _Include_UiObject_hpp_

//------------------------------------------------------------
// CN[h
//------------------------------------------------------------
#include"GameObject.hpp"
#include"../Math/MathDefine.hpp"
#include"../Api/DirectX11Resource.hpp"


namespace ao
{
	/*!-----------------------------------------------------------
	//	@class  UiObject
	//	@brief  UIpΜIuWFNg
	//	@author	Tatsunori Aoyama
	//	@date	2014/02/10
	------------------------------------------------------------*/
	class UiObject : public GameObject
	{
	public:
		/// RXgN^
		UiObject();

		/// fXgN^
		~UiObject();

		/*!-----------------------------------------------------------
		//	@brief		\[XΗέέ
		//	@param[in]	_filePath	t@CpX
		//	@param[in]	_filter		tB^[[ΘͺΒ]
		//	@author		Tatsunori Aoyama
		//	@date		2014/02/10
		------------------------------------------------------------*/
		virtual void LoadResource(const ao::string& _filePath,const SamplerState _filter = SamplerState::POINT);

		/*!-----------------------------------------------------------
		//	@brief		_O
		//	@param[in]	_x		XΐW
		//  @param[in]  _y		YΐW
		//  @param[in]  _w		‘
		//  @param[in]  _h		c
		//	@param[in]	_degree	ρ]px(fO[l)[ΘͺΒ]
		//	@param[in]	_r		ΤF[ΘͺΒ]
		//	@param[in]	_g		ΞF[ΘͺΒ]
		//	@param[in]	_b		ΒF[ΘͺΒ]
		//	@param[in]	_a		§ί¦[ΘͺΒ]
		//	@author		Tatsunori Aoyama
		//	@date		2014/03/02
		------------------------------------------------------------*/
		virtual void Render(
			const int _x, const int _y,
			const float _w, const float _h,
			const float _degree,
			const float _r,const float _g,const float _b,const float _a);

		/*!-----------------------------------------------------------
		//	@brief		_O
		//	@param[in]	_x		XΐW
		//  @param[in]  _y		YΐW
		//  @param[in]  _w		‘
		//  @param[in]  _h		c
		//	@param[in]	_degree	ρ]px(fO[l)[ΘͺΒ]
		//	@param[in]	_r		ΤF[ΘͺΒ]
		//	@param[in]	_g		ΞF[ΘͺΒ]
		//	@param[in]	_b		ΒF[ΘͺΒ]
		//	@param[in]	_a		§ί¦[ΘͺΒ]
		//	@author		Tatsunori Aoyama
		//	@date		2014/02/10
		------------------------------------------------------------*/
		virtual void Render(
			const int _x, const int _y,
			const float _w, const float _h,
			const float _degree = 0,
			const float4& _color=float4::one);

	private:
		BaseTexture* pTexture;
	};
}

#endif // _Include_UiObject_hpp_