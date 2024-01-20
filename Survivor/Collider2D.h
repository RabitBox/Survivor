#pragma once

class PhysicsSystem;
class IGameObject;

/// @brief 2Dコライダー基底クラス
class Collider2D{
	friend PhysicsSystem;

public:
	enum class Tag {
		INVALID = -1,	// 固定
		PLAYER,
		ENEMY,
		BULLET,
		MAX_TAG,	// 固定
	};

	enum class Type{
		INVALID = -1,	// 固定
		CIRCLE,
		MAX_TYPE,	// 固定
	};

private:
	Tag _tag;
	Type _type;

protected:
	IGameObject* _owner;
	std::function<bool(Collider2D*)> _callback;

protected:
	Collider2D() : _tag(Tag::INVALID), _type(Type::INVALID), _owner(nullptr) {}

public:
	Collider2D(Type type, IGameObject* owner) : _tag(Tag::INVALID), _type(type), _owner(owner) {}
	virtual ~Collider2D() {}

	/// @brief タグ取得
	/// @return タグ
	Tag GetTag() const { return _tag; }

	/// @brief タグセット
	/// @param tag セットするタグ
	void SetTag(Tag tag) { _tag = tag; }

	/// @brief タイプ取得
	/// @return タイプ
	Type GetType() const { return _type; }

	/// @brief コリジョンの所有者を取得
	/// @return 所有者
	IGameObject* GetOwner() const { return _owner; }

	/// @brief コールバック関数登録
	/// @param callback 登録する関数
	void SetCallback(std::function<bool(Collider2D*)> callback) { _callback = callback; }

	virtual bool IsHit(Collider2D* target) = 0;
};

/// @brief 2Dコライダー 円
class CircleCollider final : public Collider2D {
private:
	CircleCollider() {}
	CircleCollider(CircleCollider&&) = delete;

public:
	CircleCollider(IGameObject* owner) : Collider2D(Type::CIRCLE, owner) {}

	bool IsHit(Collider2D* target) override;
};
