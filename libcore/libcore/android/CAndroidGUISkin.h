/*
 * CAndroidGUISkin.h
 *
 *  Created on: 2014-11-5
 *      Author: mabin
 */

#ifndef CANDROIDGUISKIN_H_
#define CANDROIDGUISKIN_H_

#include <IGUISkin.h>
#include <irrString.h>
#include <IrrCompileConfig.h>
#include <IVideoDriver.h>
#include <IGUIEnvironment.h>

namespace irr {
namespace gui {

class CAndroidGUISkin: public IGUISkin {
public:

	CAndroidGUISkin(EGUI_SKIN_TYPE type, video::IVideoDriver* driver, float x, float y);

	static CAndroidGUISkin* createAndroidSkin(EGUI_SKIN_TYPE type, video::IVideoDriver* driver, IGUIEnvironment* env, float x, float y);

	//! destructor
	virtual ~CAndroidGUISkin();

	//! returns default color
	virtual video::SColor getColor(EGUI_DEFAULT_COLOR color) const _IRR_OVERRIDE_;

	//! sets a default color
	virtual void setColor(EGUI_DEFAULT_COLOR which, video::SColor newColor) _IRR_OVERRIDE_;

	//! returns size for the given size type
	virtual s32 getSize(EGUI_DEFAULT_SIZE size) const _IRR_OVERRIDE_;

	//! sets a default size
	virtual void setSize(EGUI_DEFAULT_SIZE which, s32 size) _IRR_OVERRIDE_;

	//! returns the default font
	virtual IGUIFont* getFont(EGUI_DEFAULT_FONT which=EGDF_DEFAULT) const _IRR_OVERRIDE_;

	//! sets a default font
	virtual void setFont(IGUIFont* font, EGUI_DEFAULT_FONT which=EGDF_DEFAULT) _IRR_OVERRIDE_;

	//! sets the sprite bank used for drawing icons
	virtual void setSpriteBank(IGUISpriteBank* bank) _IRR_OVERRIDE_;

	//! gets the sprite bank used for drawing icons
	virtual IGUISpriteBank* getSpriteBank() const _IRR_OVERRIDE_;

	//! Returns a default icon
	/** Returns the sprite index within the sprite bank */
	virtual u32 getIcon(EGUI_DEFAULT_ICON icon) const _IRR_OVERRIDE_;

	//! Sets a default icon
	/** Sets the sprite index used for drawing icons like arrows,
	close buttons and ticks in checkboxes
	\param icon: Enum specifying which icon to change
	\param index: The sprite index used to draw this icon */
	virtual void setIcon(EGUI_DEFAULT_ICON icon, u32 index) _IRR_OVERRIDE_;

	//! Returns a default text.
	/** For example for Message box button captions:
	"OK", "Cancel", "Yes", "No" and so on. */
	virtual const wchar_t* getDefaultText(EGUI_DEFAULT_TEXT text) const _IRR_OVERRIDE_;

	//! Sets a default text.
	/** For example for Message box button captions:
	"OK", "Cancel", "Yes", "No" and so on. */
	virtual void setDefaultText(EGUI_DEFAULT_TEXT which, const wchar_t* newText) _IRR_OVERRIDE_;

	//! draws a standard 3d button pane
	/** Used for drawing for example buttons in normal state.
	It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
	EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details.
	\param rect: Defining area where to draw.
	\param clip: Clip area.
	\param element: Pointer to the element which wishes to draw this. This parameter
	is usually not used by ISkin, but can be used for example by more complex
	implementations to find out how to draw the part exactly. */
	virtual void draw3DButtonPaneStandard(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) _IRR_OVERRIDE_;

	//! draws a pressed 3d button pane
	/** Used for drawing for example buttons in pressed state.
	It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
	EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details.
	\param rect: Defining area where to draw.
	\param clip: Clip area.
	\param element: Pointer to the element which wishes to draw this. This parameter
	is usually not used by ISkin, but can be used for example by more complex
	implementations to find out how to draw the part exactly. */
	virtual void draw3DButtonPanePressed(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) _IRR_OVERRIDE_;

	//! draws a sunken 3d pane
	/** Used for drawing the background of edit, combo or check boxes.
	\param element: Pointer to the element which wishes to draw this. This parameter
	is usually not used by ISkin, but can be used for example by more complex
	implementations to find out how to draw the part exactly.
	\param bgcolor: Background color.
	\param flat: Specifies if the sunken pane should be flat or displayed as sunken
	deep into the ground.
	\param rect: Defining area where to draw.
	\param clip: Clip area.	*/
	virtual void draw3DSunkenPane(IGUIElement* element,
			video::SColor bgcolor, bool flat,
			bool fillBackGround,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) _IRR_OVERRIDE_;

	//! draws a window background
	/** Used for drawing the background of dialogs and windows.
	\param element: Pointer to the element which wishes to draw this. This parameter
	is usually not used by ISkin, but can be used for example by more complex
	implementations to find out how to draw the part exactly.
	\param titleBarColor: Title color.
	\param drawTitleBar: True to enable title drawing.
	\param rect: Defining area where to draw.
	\param clip: Clip area.
	\param checkClientArea: When set to non-null the function will not draw anything,
	but will instead return the clientArea which can be used for drawing by the calling window.
	That is the area without borders and without titlebar.
	\return Returns rect where it would be good to draw title bar text. This will
	work even when checkClientArea is set to a non-null value.*/
	virtual core::rect<s32> draw3DWindowBackground(IGUIElement* element,
			bool drawTitleBar, video::SColor titleBarColor,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip,
			core::rect<s32>* checkClientArea) _IRR_OVERRIDE_;

	//! draws a standard 3d menu pane
	/** Used for drawing for menus and context menus.
	It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
	EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details.
	\param element: Pointer to the element which wishes to draw this. This parameter
	is usually not used by ISkin, but can be used for example by more complex
	implementations to find out how to draw the part exactly.
	\param rect: Defining area where to draw.
	\param clip: Clip area.	*/
	virtual void draw3DMenuPane(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) _IRR_OVERRIDE_;

	//! draws a standard 3d tool bar
	/** Used for drawing for toolbars and menus.
	\param element: Pointer to the element which wishes to draw this. This parameter
	is usually not used by ISkin, but can be used for example by more complex
	implementations to find out how to draw the part exactly.
	\param rect: Defining area where to draw.
	\param clip: Clip area.	*/
	virtual void draw3DToolBar(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) _IRR_OVERRIDE_;

	//! draws a tab button
	/** Used for drawing for tab buttons on top of tabs.
	\param element: Pointer to the element which wishes to draw this. This parameter
	is usually not used by ISkin, but can be used for example by more complex
	implementations to find out how to draw the part exactly.
	\param active: Specifies if the tab is currently active.
	\param rect: Defining area where to draw.
	\param clip: Clip area.	*/
	virtual void draw3DTabButton(IGUIElement* element, bool active,
		const core::rect<s32>& rect, const core::rect<s32>* clip=0,
		EGUI_ALIGNMENT alignment=EGUIA_UPPERLEFT) _IRR_OVERRIDE_;

	//! draws a tab control body
	/** \param element: Pointer to the element which wishes to draw this. This parameter
	is usually not used by ISkin, but can be used for example by more complex
	implementations to find out how to draw the part exactly.
	\param border: Specifies if the border should be drawn.
	\param background: Specifies if the background should be drawn.
	\param rect: Defining area where to draw.
	\param clip: Clip area.	*/
	virtual void draw3DTabBody(IGUIElement* element, bool border, bool background,
		const core::rect<s32>& rect, const core::rect<s32>* clip=0, s32 tabHeight=-1,
		EGUI_ALIGNMENT alignment=EGUIA_UPPERLEFT) _IRR_OVERRIDE_;

	//! draws an icon, usually from the skin's sprite bank
	/** \param element: Pointer to the element which wishes to draw this icon.
	This parameter is usually not used by IGUISkin, but can be used for example
	by more complex implementations to find out how to draw the part exactly.
	\param icon: Specifies the icon to be drawn.
	\param position: The position to draw the icon
	\param starttime: The time at the start of the animation
	\param currenttime: The present time, used to calculate the frame number
	\param loop: Whether the animation should loop or not
	\param clip: Clip area.	*/
	virtual void drawIcon(IGUIElement* element, EGUI_DEFAULT_ICON icon,
			const core::position2di position,
			u32 starttime=0, u32 currenttime=0,
			bool loop=false, const core::rect<s32>* clip=0) _IRR_OVERRIDE_;


	//! draws a 2d rectangle.
	/** \param element: Pointer to the element which wishes to draw this icon.
	This parameter is usually not used by IGUISkin, but can be used for example
	by more complex implementations to find out how to draw the part exactly.
	\param color: Color of the rectangle to draw. The alpha component specifies how
	transparent the rectangle will be.
	\param pos: Position of the rectangle.
	\param clip: Pointer to rectangle against which the rectangle will be clipped.
	If the pointer is null, no clipping will be performed. */
	virtual void draw2DRectangle(IGUIElement* element, const video::SColor &color,
			const core::rect<s32>& pos, const core::rect<s32>* clip = 0) _IRR_OVERRIDE_;


	//! get the type of this skin
	virtual EGUI_SKIN_TYPE getType() const _IRR_OVERRIDE_;

	//! Writes attributes of the skin
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const _IRR_OVERRIDE_;

	//! Reads attributes of the skin
	virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) _IRR_OVERRIDE_;

private:

	video::SColor Colors[EGDC_COUNT];
	s32 Sizes[EGDS_COUNT];
	u32 Icons[EGDI_COUNT];
	IGUIFont* Fonts[EGDF_COUNT];
	IGUISpriteBank* SpriteBank;
	core::stringw Texts[EGDT_COUNT];
	irr::video::IVideoDriver* Driver;
	bool UseGradient;

	EGUI_SKIN_TYPE Type;

	float XScale;
	float YScale;
};

} /* namespace gui */
} /* namespace irr */
#endif /* CANDROIDGUISKIN_H_ */