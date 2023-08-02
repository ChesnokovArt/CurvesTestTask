#pragma once

#ifdef CURVES_EXPORTS
#define CURVES_API __declspec(dllexport)
#else
#define CURVES_API __declspec(dllimport)
#endif
