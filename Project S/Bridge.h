#pragma once

class VrpnBridge {
public:
	VrpnBridge(float mine);
	void ButtonH();
	void StartHandler(int*);
	void Param();

	int &ext;
};