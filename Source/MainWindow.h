/*
 * Copyright 2015 Przemysław Buczkowski <przemub@przemub.pl>
 * Copyright 2014 George White
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_


#include <Bitmap.h>
#include <Button.h>
#include <GridLayout.h>
#include <GridView.h>
#include <MenuBar.h>
#include <Resources.h>
#include <String.h>
#include <StringView.h>
#include <View.h>
#include <Window.h>

#define CEL(T) (5.0 / 9.0) * (T - 32.0)
	// Macro converting a Fahrenheit value to a Celsius value

const int32 kSettingsMessage = 'Pref';

extern const char* kSettingsFileName;


class MainWindow : public BWindow {
public:
					MainWindow(void);
	void 			MessageReceived(BMessage* msg);
	BMenuBar 		*PrepareMenuBar(void);
	void 			AddView(BView *);
	
private:
	void 			_LoadBitmaps();
	void			_DownloadData();
	status_t		_LoadSettings();
	status_t		_SaveSettings();

	BGridView* 		fView;
	BGridLayout* 	fLayout;
	
	BString			fCity;
	BString			fCityId;
	
	int32			fTemperature;
	int32			fCondition;
	
	BResources*		fResources;
	
	BBitmap* 		fAlert;
	BBitmap* 		fClearNight;
	BBitmap* 		fClear;
	BBitmap* 		fClouds;
	BBitmap* 		fFewClouds;
	BBitmap* 		fFog;
	BBitmap* 		fNightFewClouds;
	BBitmap* 		fRainingScattered;
	BBitmap* 		fRaining;
	BBitmap* 		fShining;
	BBitmap* 		fShiny;
	BBitmap* 		fSnow;
	BBitmap* 		fStorm;
	BBitmap* 		fThunder;
	
	BButton*		fConditionButton;
	BStringView*	fConditionView;
	BStringView*	fTemperatureView;
	BStringView*	fCityView;
};


#endif // _MAINWINDOW_H_
