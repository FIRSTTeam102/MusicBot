#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SongPlayer.h"

class NextSong : public frc2::CommandHelper<frc2::CommandBase, NextSong> {
	public:
		explicit NextSong(SongPlayer *pSongPlayer);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		SongPlayer *mpSongPlayer;
};
