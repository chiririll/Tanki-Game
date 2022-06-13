#pragma once
#include "State.h"

class NetworkState : public State
{
private:

protected:

public:
	// Constructors and destructors
	NetworkState() = default;
	virtual ~NetworkState() = default;

	// Start
	bool Start() override;

	// Updaters
	void Update(const double& delta_time) override;
	void FixedUpdate() override;
	void Render() override;
	void DrawUI() override;
};
