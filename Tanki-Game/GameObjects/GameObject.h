#pragma once


class GameObject
{
private:
	unsigned short m_id;

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
