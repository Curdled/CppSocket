#ifndef _ACTION_TYPE_HPP_
#define _ACTION_TYPE_HPP_
namespace CppSocket
{
	class ActionType
	{
	public:
		enum ActionTypes
		{
			NOTHING,
			MSG,
			CONN,
			DISCONN
		};
	};
}

#endif