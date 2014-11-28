/*
 * windefs.c: default settings that are specific to Windows.
 */

#include "putty.h"

#include <commctrl.h>

FontSpec *platform_default_fontspec(const char *name)
{
#ifdef PERSOPORT
    /*
     * HACK: PuTTY-url
     * Set font to Consolas on Windows Vista and above
     */
    OSVERSIONINFO versioninfo;
    versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&versioninfo);

	if (!strcmp(name, "Font")) {
		if (versioninfo.dwMajorVersion >= 6) {
			return fontspec_new("Consolas", 0, 10, ANSI_CHARSET);
			}
		return fontspec_new("Courier New", 0, 10, ANSI_CHARSET);
		}
	return fontspec_new("", 0, 0, 0);
#else
    if (!strcmp(name, "Font"))
        return fontspec_new("Courier New", 0, 10, ANSI_CHARSET);
    else
        return fontspec_new("", 0, 0, 0);
#endif
}

Filename *platform_default_filename(const char *name)
{
    if (!strcmp(name, "LogFileName"))
	return filename_from_str("putty.log");
    else
	return filename_from_str("");
}

char *platform_default_s(const char *name)
{
    if (!strcmp(name, "SerialLine"))
	return dupstr("COM1");
    return NULL;
}

int platform_default_i(const char *name, int def)
{
    return def;
}
