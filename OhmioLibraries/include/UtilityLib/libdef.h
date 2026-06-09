#pragma once
#include "version.h"


//! Macro needed for DLLS under windows. Ignored by Linux
//! Only needed if usinmg DLLs in windows
#ifdef _WINDOWS // windows
	#ifdef EXPMODULE
		#define EXPORT_SYMBOL __declspec(dllexport)
	#else
		#define EXPORT_SYMBOL __declspec(dllimport)
	#endif
#else // Linux
	#define EXPORT_SYMBOL
#endif 



