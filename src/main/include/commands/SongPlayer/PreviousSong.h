#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SongPlayer.h"

class PreviousSong : public frc2::CommandHelper<frc2::CommandBase, PreviousSong> {
	public:
		explicit PreviousSong(SongPlayer *pSongPlayer);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		SongPlayer *mpSongPlayer;
};
