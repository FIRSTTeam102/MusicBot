#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc2/command/Command.h>
#include <frc2/command/button/Button.h>

#include "subsystems/SongPlayer.h"
#include "commands/SongPlayer/NextSong.h"
#include "commands/SongPlayer/PreviousSong.h"
#include "commands/SongPlayer/StopSong.h"
#include "commands/SongPlayer/TogglePause.h"

class RobotContainer {
	public:
		frc2::Command* GetAutonomousCommand();
		static RobotContainer* GetInstance();

		frc::XboxController* GetDriverController() { return &mDriverController; }

	private:
		RobotContainer();

		frc::XboxController mDriverController{0};
		frc2::Button mDriverButtonA{[&] { return mDriverController.GetAButton(); }};
		frc2::Button mDriverButtonB{[&] { return mDriverController.GetBButton(); }};
		frc2::Button mDriverButtonX{[&] { return mDriverController.GetXButton(); }};
		frc2::Button mDriverButtonY{[&] { return mDriverController.GetYButton(); }};
		frc2::Button mDriverUpDPad{[&] { return (mDriverController.GetPOV() == 0); }};
		frc2::Button mDriverLeftDPad{[&] { return (mDriverController.GetPOV() == 90); }};
		frc2::Button mDriverDownDPad{[&] { return (mDriverController.GetPOV() == 180); }};
		frc2::Button mDriverRightDPad{[&] { return (mDriverController.GetPOV() == 270); }};

		static RobotContainer* mRobotContainer;

		void ConfigureButtonBindings();

		// Subsystems and commands
		SongPlayer mSongPlayer;
		NextSong mNextSongCommand{&mSongPlayer};
		PreviousSong mPreviousSongCommand{&mSongPlayer};
		// SetSong mSetSongCommand{&mSongPlayer, "rickroll"};
		StopSong mStopSongCommand{&mSongPlayer};
		TogglePause mTogglePauseCommand{&mSongPlayer};
};