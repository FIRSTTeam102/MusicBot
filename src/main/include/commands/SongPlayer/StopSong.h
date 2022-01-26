#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SongPlayer.h"

class StopSong : public frc2::CommandHelper<frc2::CommandBase, StopSong> {
	public:
		explicit StopSong(SongPlayer *pSongPlayer);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		SongPlayer *mpSongPlayer;
};
