#pragma once
#include <array>
#include "Singleton.h"
#include "ITask.h"

namespace Task
{
	enum class TaskType
	{
		UPDATE,		// 更新
		DRAW,		// 描画
		RELEASE,	// タスク解放
	};

	/// @brief タスクの処理優先度
	enum Priority
	{
		LEVEL_1 = 0,
		LEVEL_2,
		LEVEL_3,
		MAX_LEVEL,	// 末尾固定
	};

	class TaskManager : public Singleton<TaskManager>
	{
		friend class Singleton<TaskManager>;

	private:
		std::vector<ITask*> _taskList[MAX_LEVEL];
		std::vector< std::pair<ITask*, Priority> > _unregisterList;

	private:
		TaskManager();
		void RegisterTask( ITask* task, Priority priority );
		void UnregisterTask( ITask* task, Priority priority );

		void UpdateTask();
		void DrawTask();
		void RemoveTask();

		void RunAll( TaskType type );
	public:
		/// @brief タスク更新
		static void Run( TaskType type );

		/// @brief タスクの登録
		/// @param task タスク
		/// @param priority タスク優先度
		static void Register( ITask* task, Priority priority );

		/// @brief タスクの登録解除
		/// @param task タスク
		/// @param priority タスク優先度
		static void Unregister( ITask* task, Priority priority );

		/// @brief タスクマネージャーの初期化
		static void Create();

		/// @brief タスクマネージャーの解放
		static void Release();
	};
}

