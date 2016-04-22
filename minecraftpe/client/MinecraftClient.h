#pragma once

#include <functional>
#include <memory>
#include <vector>

#include "App.h"
#include "tips/Vibration.h"
#include "tips/GameCallbacks.h"
#include "tips/SkinInfoFactory.h"
#include "tips/MinecraftKeyboardManager.h"

// Define abstract classes
namespace mce {
	class Texture;
	class UserManager;
}

namespace Social {
	class Multiplayer;
}

namespace ui {
	class GameEventNotification;
}

enum class InputMode;
enum class HoloUIInputMode;
enum class UserPermissionsLevel;
enum class DirectionId;
enum class Side;
enum class GameType;

class Vec2;
class ImageData;
class AbstractScreen;
class Entity;
class ExternalServer;
class Font;
class GameRenderer;
class GameStore;
class GeometryGroup;
class GuiData;
class HolosceneRenderer;
class MinecraftInputHandler;
class LevelArchiver;
class LevelRenderer;
class LocalPlayer;
class MobEffectsLayout;
class MouseDevice;
class OculusPlatformMessagePump;
class Options;
class ParticleEngine;
class Realms;
class Screen;
class ScreenChooser;
class Minecraft;
class SkinRepository;
class SoundEngine;
class MinecraftTelemetry;
class UIDefRepository;
class UserAuthentication;
class VoiceSystem;
class VoiceCommand;
class Player;
class Level;
class Vec3;
class HolographicPlatform;
class Dimension;
class LevelSettings;
class Timer;

// Size : ?
class MinecraftClient : public App, public Vibration, public GameCallbacks, public SkinInfoFactory, public MinecraftKeyboardManager {
public:
	// void** vtable_vibration; // #16 0x10
	// void** vtable_gameCallbacks; // #20 0x14
	// void** vtable_skinInfoFactory; // #24 0x18
	// MinecraftKeyboardManager keyboard; // #28 0x1C
	float unknown1; // #40 0x28
	float unknown2; // #44 0x2C
	float unknown3; // #48 0x30
	char filler1[12]; // #52 0x34
	int unknown4; // #64 0x40
	std::string worldDir; // #68 0x44
	std::string minecraftpeDir; // #72 0x48
	std::string serviceConfigJSON; // #76 0x4C
	std::string idPublicEntityKey; // #80 0x50
public:
	static float GUI_SCALE_VALUES;
	static std::string INTERACTION_FREQ_MS;
	static void* _hasInitedStatics;
public:
	MinecraftClient(int, char**);
	virtual ~MinecraftClient();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual bool useTouchscreen();
	virtual void setTextboxText(const std::string&);
	virtual void update();
	virtual void setUISizeAndScale(int, int, float);
	virtual void setRenderingSize(int, int);
	virtual void init();
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void onInternetUpdate();
	virtual bool canActivateKeyboard();
	virtual void onLevelCorrupt();
	virtual void onGameModeChagned();
	virtual void onGameSessionReset();
	virtual ClientSkinInfoData* createSkin();
	virtual void onLevelExit();
	virtual void onTick(int, int);
	virtual void vibrate(int);
	virtual void enableKeyboard(const std::string&, int, bool, bool, const Vec2&);
	virtual void disableKeyboard();
	virtual bool isKeyboardEnabled();
	virtual bool isKeyboardActive();
	virtual float getKeyboardHeight();
	void ResetBai(int);
	double _getGuiScaleIndexForLargeScreen(int, int);
	float _getGuiScaleIndexForSmallScreen(int, float);
	void initMinecraftClient();
	void _popScreen(bool);
	void _processNewGazeHoloScreenData();
	void _registerOnInitUriListeners();
	void _reloadFancy(bool);
	void _reloadLanguages();
	void _toogleThirdPersonView();
	void _unregisterOnInitUriListeners();
	void _updateScreenshot();
	void allowPicking() const;
	void autoLoadLevel(const std::string&);
	void calculateGuiScale(int);
	void captureScreenAsImage(ImageData&);
	void checkForPiracy();
	void clearDictationDataAvailable();
	void composeScreenshot(ImageData&, const std::string&, bool);
	void endFrame();
	void exportScreenshotsToZipFile(const std::string&);
	void forEachScreen(std::function<bool(std::shared_ptr<AbstractScreen>&)>);
	void forEachVisibleScreen(std::function<void(std::shared_ptr<AbstractScreen>&)>);
	Entity* getCameraEntity() const;
	Entity* getCameraTargetEntity();
	int64_t getClientRandonId() const;
	int getConnectedPort() const;
	std::string getConnectedServer() const;
	InputMode getCurrentInputMode();
	std::string** getDictationText() const;
	float getDpadScale();
	ExternalServer* getExternelServer() const;
	Font* getFont() const;
	bool getForceMonoscopic() const;
	GameRenderer* getGameRenderer() const;
	GameStore* getGameStore() const;
	GeometryGroup* getGeometryGroup() const;
	GuiData* getGuiData();
	float getGuiScale(int);
	double getGuiScaleIndex(float);
	HoloUIInputMode getHoloInput() const;
	HolosceneRenderer* getHolosceneRenderer() const;
	float getHoloScreenHalfWidth();
	float getHoloviewerScale();
	MinecraftInputHandler* getInput() const;
	LevelArchiver* getLevelArchiver();
	LevelRenderer* getLevelRenderer();
	LocalPlayer* getLocalPlayer();
	MobEffectsLayout* getMobEffectsLayout();
	MouseDevice* getMouseGrabbed() const;
	Social::Multiplayer* getMultiplayer() const;
	OculusPlatformMessagePump* getOculusPlatformMessagePump() const;
	Options* getOptions();
	ParticleEngine* getParticleEngine() const;
	Realms* getRealms();
	Font* getRuneFont() const;
	Screen* getScreen();
	ScreenChooser* getScreenChooser() const;
	std::string getScreenName();
	std::vector<std::string> getScreenNames();
	Minecraft* getServer();
	std::string getSituationalMusic() const;
	SkinRepository* getSkinRepository() const;
	SoundEngine* getSoundEngine() const;
	UserPermissionsLevel getSuperUserPermissions();
	MinecraftTelemetry* getTelemetry() const;
	mce::Texture* getTextures() const;
	UIDefRepository* getUIDefRepo() const;
	UserAuthentication* getUserAuthentication();
	mce::UserManager* getUserManager() const;
	VoiceSystem* getVoiceSystem() const;
	float getWidth() const;
	float getHeight() const;
	void grabMouse();
	void handleAttackActionButtonRelease();
	void handleBackNoReturn();
	void handleBiomeDisplayButtonPress();
	void handleBuildActionButtonPress();
	void handleBuildOrAttackButtonPress();
	void handleCaretLocation(int);
	void handleChatButtonPress();
	void handleCommandEvent(const VoiceCommand&);
	void handleConsoleButtonPress();
	void handleCraftingButtonPress();
	void handleCreativeBlockSelectButtonRelease();
	void handleDebugToggleAnchorsCommand();
	void handleDebugToggleLSRCommand();
	void handleDecreaseRenderDistanceButtonPress();
	void handleDecrementMaxCullingStepesButtonPress();
	void handleDestroyOrAttackButtonPress();
	void handleDestroyOrInteractButtonPress();
	void handleDictationEvent();
	void handleDirection(DirectionId, float, float);
	void handleDismountButtonPress();
	void handleDropAllButtonPress();
	void handleDropAllItemsButtonPress();
	void handleForceDesktopScreensButtonPress();
	void handleForcePocketScreensButtonPress();
	void handleHideGuiButtonPress();
	void handleHoloInputModeChanged(HoloUIInputMode);
	void handleIncreaseRenderDistanceButtonPress();
	void handleIncrementMaxCullingStepsButtonPress();
	void handleInputModeChanged(InputMode);
	void handleInteractButtonPress();
	void handleInventoryButtonPress();
	void handleInventoryMoveButtonPress();
	void handleInvite();
	void handleLicenseChanged();
	void handleLowMemoryWarningButtonPress();
	void handleMemoryStatsButtonPress();
	void handleMenuButtonPress(short);
	void handleMenuButtonRelease(short);
	void handleMobEffectsButtonPress();
	void handleNextAVCStatButtonPress();
	void handleNextAVCStatButtonRelease();
	void handlePaddleButtonPress(Side);
	void handlePaddleButtonRelease(Side);
	void handlePauseButtonPress();
	void handlePickDebugObjectButtonPress();
	void handlePointerLocation(short, short);
	void handlePointerPressedButtonPress();
	void handlePointerPressedButtonRelease();
	void handleRedstoneLogButtonPress();
	void handleReloadUIDefinitions();
	void handleRenderDebugButtonPress();
	void handleSetSpawnPositionButtonPress();
	void handleShowUpsellScreen();
	void handleSimTimePause(bool);
	void handleSimTimeScale(float);
	void handleSlotSelectButtonPress(int);
	void handleStickCursorButtonPress();
	void handleStickCursorButtonRelease();
	void handleSuspendResumeButtonPress();
	void handleTextChar(const std::string&, bool);
	void handleTimeStepForwardButtonPress();
	void handleToggleAdvancedCullingButtonPress();
	void handleToggleDayCycleActiveButtonPress();
	void handleToggleEnableNewScreensDebugButtonPress();
	void handleToggleFlyFlastButtonPress();
	void handleToggleFrameTimerDisplayButtonPress();
	void handleToggleGameModeButtonPress();
	void handleToggleLivingroomButtonRelease();
	void handleToggleNoClipButtonPress();
	void handleTogglePlayerUpdateMobsButtonPress();
	void handleToggleShowChunkMapButtonPress();
	void handleToggleSimulateTouchButtonPress();
	void handleToggleTexelAAButtonPress();
	void handleToggleThirdPersonViewButtonPress();
	void handleVectorInput(short, float, float, float);
	void initFoliageAndBlockTextureTessellator();
	void initOptionObservers();
	void initTelemetry();
	void initalizeTrialWorld(Player*);
	bool isEduMode() const;
	bool isInBedScreen() const;
	bool isInGame();
	bool isKindleFire(int);
	bool isLaunchedFromOculusApp() const;
	bool isRealityFullVRMode();
	bool isSRPlacementMode() const;
	bool isScreenReplaceable() const;
	bool isServerVisible();
	bool isShowingMenu() const;
	void joinLiveGame(const std::string&);
	void joinMultiplayer(const char*, int);
	void joinRealmsGame(const char*, int);
	void leaveGame(bool);
	void newDictationDataAvailable();
	void onClientStatedLevel(std::unique_ptr<Level>, std::unique_ptr<LocalPlayer>);
	void onDimensionChagned();
	void onGameEventNotification(ui::GameEventNotification);
	void onGameModeChanged();
	void onMobEffectsChange();
	void onPlayerLoaded(Player&);
	void onPrepChagneDimension();
	void onUserSignin();
	void onUserSIgnout();
	void play(const std::string&, const Vec3&, float, float);
	void playUI(const std::string&, float, float);
	void popScreen(int);
	void pushScreen(std::shared_ptr<AbstractScreen>, bool);
	void refocusMouse();
	void registerUpsellScreen();
	void releaseMouse();
	void reloadShaders();
	void repopulatePlayScreenWorlds();
	void requestScreenshot(const std::string&);
	void resetInhibitInputDueToTextBoxMode();
	void resetInput();
	void restartServer();
	void sendLocalMessage(const std::string&, const std::string&);
	void setCameraEntity(Entity*);
	void setCameraTargetEntity(Entity*);
	void setDeferRenderingUntilChunksReady();
	void setDpadScale(float);
	void setEduMode(bool);
	void setGameMode(GameType);
	void setHoloInput(std::unique_ptr<HolographicPlatform>);
	void setHoloscreenHalfWidth(float);
	void setHoloviewerPlayerMode(bool, bool);
	void setInhibitInputDueToTextBoxMode();
	void setKeyboardForcedHeight(float);
	void setLaunchedFromOculusApp(bool);
	void setSuspendInput(bool);
	void setVoiceSystem(std::unique_ptr<VoiceSystem>);
	void setupClientGame(std::function<void(bool)>);
	void setupCommandParser();
	void setupLevelRendering(Level*, Dimension*, Entity*);
	void setupRenderer();
	void setupStartMenuScreenCommandParser();
	void startFrame();
	void startHoloviewerReveal();
	void setartLocalServer(std::string, std::string, LevelSettings);
	void teardownRenderer();
	void tickBuildAction();
	void tickInput();
	void transformResolution(int*, int*);
	void updateGraphics(const Timer&);
	void updateScheduledScreen();
	void updateStats();
	void useController();
	void validateLocalLevel(std::string, std::string, LevelSettings);
};