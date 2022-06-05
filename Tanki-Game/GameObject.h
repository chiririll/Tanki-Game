#pragma once


class GameObject
{
private:
	unsigned short m_id;

	friend class NetworkState;

protected:


public:
	// Constructors and destructors
	GameObject();
	virtual ~GameObject();

	// Updaters
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Render();
};
