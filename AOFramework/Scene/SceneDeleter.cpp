#include"stdafx.hpp"
#include"SceneDeleter.hpp"
#include"AoScene.hpp"


using namespace ao;


SceneDeleter::SceneDeleter(SceneControlProxy* _pSceneCtrlProxy) : SceneCtrlProxyComposite(_pSceneCtrlProxy)
{

}


SceneDeleter::~SceneDeleter()
{

}


//------------------------------------------------------------------------------
/**	@brief		シーンの削除 */
//------------------------------------------------------------------------------
//	Date		Time	Author		Summary
//	2015/02/28	16:54	T.Aoyama	作成
//------------------------------------------------------------------------------
void SceneDeleter::DeleteScene(ISceneBase** _ppDeleteScene)
{
	if (*_ppDeleteScene == nullptr)
	{
		return;
	}

	delete (*_ppDeleteScene);
	(*_ppDeleteScene) = nullptr;
}