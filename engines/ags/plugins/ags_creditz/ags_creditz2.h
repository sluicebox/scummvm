/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or(at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef AGS_PLUGINS_AGSCREDITZ_AGSCREDITZ2_H
#define AGS_PLUGINS_AGSCREDITZ_AGSCREDITZ2_H

#include "ags/plugins/ags_creditz/ags_creditz.h"
#include "ags/plugins/ags_creditz/drawing.h"

namespace AGS3 {
namespace Plugins {
namespace AGSCreditz {

typedef int (*IntFunction)(int val1);

class AGSCreditz2 : public AGSCreditz, public Drawing {
private:
	static IntFunction _playSound;
private:
	static const char *AGS_GetPluginName();
	static void AGS_EngineStartup(IAGSEngine *engine);

	static void RunCreditSequence(ScriptMethodParams &params);
	static void SetCredit(ScriptMethodParams &params);
	static void GetCredit(ScriptMethodParams &params);
	static void CreditsSettings(ScriptMethodParams &params);
	static void SequenceSettings(ScriptMethodParams &params);
	static void IsSequenceFinished(ScriptMethodParams &params);
	static void PauseScrolling(ScriptMethodParams &params);
	static void SetCreditImage(ScriptMethodParams &params);
	static void ResetSequence(ScriptMethodParams &params);

	static void SetStaticCredit(ScriptMethodParams &params);
	static void SetStaticCreditTitle(ScriptMethodParams &params);
	static void SetStaticPause(ScriptMethodParams &params);
	static void RunStaticCreditSequence(ScriptMethodParams &params);
	static void IsStaticSequenceFinished(ScriptMethodParams &params);
	static void ShowStaticCredit(ScriptMethodParams &params);
	static void SetStaticImage(ScriptMethodParams &params);
	static void GetCurrentStaticCredit(ScriptMethodParams &params);

	static void makeMask(int sequence);
	static void drawMask(int sequence, int getput);
	static int drawCredit(int sequence, int credit);
	static void doCredits();
	static int countLines(const Common::String &text);
	static Common::String extractParameter(Common::String &line, const Common::String &separator);
	static void specialEffect(int sequence, int credit, const Common::String &text,
		int font, int color, int32 x_pos);
	static void drawStEffects(int sequence, int id, int style);
	static void speeder(int sequence);
private:
	static void calculateSequenceHeight(int sequence);
	static int VGACheck(int value);
	static void draw();
public:
	AGSCreditz2();
};

} // namespace AGSCreditz
} // namespace Plugins
} // namespace AGS3

#endif
