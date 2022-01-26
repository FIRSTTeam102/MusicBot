#include "commands/SongPlayer/TogglePause.h"

TogglePause::TogglePause(SongPlayer *pSongPlayer) : mpSongPlayer{pSongPlayer} {
	SetName("TogglePause");
	AddRequirements(pSongPlayer);
}

// Called just before this Command runs the first time
void TogglePause::Initialize() {
	mpSongPlayer->togglePause();
}

// Called repeatedly when this Command is scheduled to run
void TogglePause::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool TogglePause::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TogglePause::End(bool interrupted) {
}