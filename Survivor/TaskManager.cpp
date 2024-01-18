#include "stdafx.h"
#include "TaskManager.h"
using namespace Task;

#pragma region シングルトン実装
static std::unique_ptr<Task::TaskManager> instance;

Task::TaskManager* GetInstance()
{
	return instance.get();
}
#pragma endregion

#pragma region 内部処理
TaskManager::TaskManager()
{

}

/// @brief タスクの登録
/// @param task 登録するタスク
/// @param priority 登録するプライオリティ
void TaskManager::RegisterTask(ITask* task, Priority priority)
{
	_taskList[priority].push_back( task );
}

/// @brief タスクの登録解除リストへの登録
/// @param task 登録解除するタスク
/// @param priority 登録されているプライオリティ
void TaskManager::UnregisterTask(ITask* task, Priority priority)
{
	_unregisterList.push_back( std::pair<ITask*, Priority>(task, priority) );
}

/// @brief タスク更新
void TaskManager::UpdateTask()
{
	for (int i = 0; i < MAX_LEVEL; ++i) {
		for (const auto& obj : _taskList[i])
		{
			if ( obj->_initialized == false ) {
				obj->OnInitialize();
				obj->_initialized = true;
			}
			obj->OnUpdate();
		}
	}
}

/// @brief タスク描画
void TaskManager::DrawTask()
{
	for (int i = 0; i < MAX_LEVEL; ++i) {
		for (const auto& obj : _taskList[i])
		{
			obj->OnDraw();
		}
	}
}

/// @brief タスクを取り除く
void TaskManager::RemoveTask()
{
	for (auto itr = _unregisterList.begin(); itr != _unregisterList.end(); ++itr) {
		auto& refTaskList(_taskList[itr->second]);
		itr->first->OnErase();
		auto removeItr = std::remove(refTaskList.begin(), refTaskList.end(), itr->first);
		refTaskList.erase(removeItr, refTaskList.end());
	}
	_unregisterList.clear();
}

/// @brief タスク全実行
/// @param type 実行するタスクタイプ
void TaskManager::RunAll( TaskType type )
{
	switch ( type )
	{
	case TaskType::UPDATE: {
		UpdateTask();
	} break;

	case TaskType::DRAW: {
		DrawTask();
	} break;

	case TaskType::RELEASE: {
		RemoveTask();
	} break;
	}
}
#pragma endregion

/// @brief タスク更新
/// @param type タスクタイプ
void TaskManager::Run(TaskType type)
{
	GetInstance()->RunAll( type );
}

/// @brief タスクの登録
/// @param task タスク
/// @param priority タスク優先度
void TaskManager::Register(ITask* task, Priority priority)
{
	GetInstance()->RegisterTask(task, priority);
}

/// @brief タスクの登録解除
/// @param task タスク
/// @param priority タスク優先度
void TaskManager::Unregister(ITask* task, Priority priority)
{
	GetInstance()->UnregisterTask(task, priority);
}

/// @brief タスクマネージャーの初期化
void TaskManager::Create()
{
	if (instance == nullptr)
	{
		instance = std::unique_ptr<Task::TaskManager>(new Task::TaskManager());
	}
}

/// @brief タスクマネージャーの解放
void TaskManager::Release()
{
	instance.release();
}
