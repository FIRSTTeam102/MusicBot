#include "commands/SongPlayer/StopSong.h"

StopSong::StopSong(SongPlayer *pSongPlayer) : mpSongPlayer{pSongPlayer} {
	SetName("StopSong");
	AddRequirements(pSongPlayer);
}

// Called just before this Command runs the first time
void StopSong::Initialize() {
	mpSongPlayer->stopSong();
}

// Called repeatedly when this Command is scheduled to run
void StopSong::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool StopSong::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void StopSong::End(bool interrupted) {
}