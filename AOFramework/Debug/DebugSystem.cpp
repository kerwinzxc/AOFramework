#include"stdafx.hpp"
#include"DebugSystem.hpp"


#if defined(DEBUG)||defined(_DEBUG)||defined(RELEASE_DEBUG)
//------------------------------------------------------------------------------
/**	@brief		文字列の描画 */
//------------------------------------------------------------------------------
//	Date		Time	Author		Summary
//	2014/07/03	00:59	T.Aoyama	作成
//------------------------------------------------------------------------------
void ao::debug::Printf(CONST AOLPSTR _str, ...)
{
	DebugConsole::GetInstance()->SetColor();

	// 文字列を描画
	va_list args;
	va_start(args, _str);
	DebugConsole::OutPutStringArgList(_str, args);
	va_end(args);
}


//------------------------------------------------------------------------------
/**	@brief		指定色で文字列の描画 */
//------------------------------------------------------------------------------
//	Date		Time	Author		Summary
//	2014/07/03	01:00	T.Aoyama	作成
//------------------------------------------------------------------------------
void ao::debug::PrintfColor(ConsoleColor::Enum _textColor, CONST AOLPSTR _str, ...)
{
	// 色をセット
	DebugConsole::GetInstance()->SetColorF(_textColor);

	va_list args;
	va_start(args, _str);
	DebugConsole::OutPutStringArgList(_str, args);
	va_end(args);
}


//------------------------------------------------------------------------------
/**	@brief		文字列の描画 */
//------------------------------------------------------------------------------
//	Date		Time	Author		Summary
//	2014/07/03	01:00	T.Aoyama	作成
//------------------------------------------------------------------------------
void ao::debug::PrintfLog(CONST AOLPSTR _str, ...)
{
	DebugConsole::GetInstance()->SetColor();

	// 文字列を描画
	va_list args;
	va_start(args, _str);
	DebugConsole::OutPutStringArgListLog(_str, args);
	va_end(args);
}


//------------------------------------------------------------------------------
/**	@brief		指定色で文字列の描画 */
//------------------------------------------------------------------------------
//	Date		Time	Author		Summary
//	2014/07/03	01:01	T.Aoyama	作成
//------------------------------------------------------------------------------
void ao::debug::PrintfColorLog(ConsoleColor::Enum _textColor, CONST AOLPSTR _str, ...)
{
	// 色をセット
	DebugConsole::GetInstance()->SetColorF(_textColor);

	va_list args;
	va_start(args, _str);
	DebugConsole::OutPutStringArgListLog(_str, args);
	va_end(args);
}

#endif