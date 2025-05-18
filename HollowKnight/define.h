#pragma once

#define SINGLE(Type) public:\
		static Type* GetInst()\
		{\
			static Type type; return &type;\
}\
private:\
		Type();\
		~Type();


enum class SCENE_TYPE
{
	MAINMENU,
	STARTMAP,
	END,
};