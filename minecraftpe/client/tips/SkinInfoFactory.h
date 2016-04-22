#pragma once

class ClientSkinInfoData;

class SkinInfoFactory {
	virtual ~SkinInfoFactory();
	virtual ClientSkinInfoData* createSkin() = 0;
};