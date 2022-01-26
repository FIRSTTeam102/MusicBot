#include "commands/SongPlayer/PreviousSong.h"

PreviousSong::PreviousSong(SongPlayer *pSongPlayer) : mpSongPlayer{pSongPlayer} {
	SetName("PreviousSong");
	AddRequirements(pSongPlayer);
}

// Called just before this Command runs the first time
void PreviousSong::Initialize() {
	mpSongPlayer->changeSongIndex(false);
}

// Called repeatedly when this Command is scheduled to run
void PreviousSong::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool PreviousSong::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void PreviousSong::End(bool interrupted) {
}