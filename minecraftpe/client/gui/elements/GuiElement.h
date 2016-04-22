#pragma once

#include <string>

#include "GuiComponent.h"

// Declare enum-classes
enum class StickDirection;

// Declare abstracted classes for compile
class MinecraftClient;
class Vec2;
class intRectange;
class Color;
class NinePatchLayer;

class GuiElement : public GuiComponent {
public:
	bool active; // 4
	bool visible; // 5
	int x; // 8
	int y; // 12
	int width; // 16
	int height; // 20
	// 24
public:
	GuiElement(bool, bool, int, int, int, int);
	virtual ~GuiElement();
	virtual void tick(MinecraftClient*);
	virtual void render(MinecraftClient*, int, int);
	virtual void topRender(MinecraftClient*, int, int);
	virtual void setupPositions();
	virtual void pointerPressed(MinecraftClient*, int, int);
	virtual void pointerReleased(MinecraftClient*, int, int);
	virtual void focusedMouseClicked(MinecraftClient*, int, int);
	virtual void focusedMouseReleased(MinecraftClient*, int, int);
	virtual void handleButtonPress(MinecraftClient*, short);
	virtual void handleButtonRelease(MinecraftClient*, short);
	virtual void handleTextChar(MinecraftClient*, const std::string&, bool);
	virtual void handleCaretLocation(int);
	virtual void backPressed(MinecraftClient*, bool);
	virtual void setKeyboardHeight(MinecraftClient*, float, const Vec2&);
	virtual void pointInside(int, int);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(const std::string&);
	virtual bool hasFocus();
	virtual void setFocus(bool);
	virtual void handleControllerDirectionHeld(int, StickDirection);
	virtual void drawSelected(int);
	virtual void drawPressed(int);
	virtual void drawSliderSelected();
	virtual void onSelectedChanged();
	virtual bool hasChildren();
	bool isSelected() const;
	void setSelected(bool);
	void setBackground(MinecraftClient*, const std::string&, const intRectange&, int, int);
	void setVisible(bool);
	void setBackground(const Color&);
	void clearBackground();
	void setActiveAndVisibility(bool);
	void setActiveAndVisibility(bool, bool);

};