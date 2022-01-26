#include "commands/SongPlayer/NextSong.h"

NextSong::NextSong(SongPlayer *pSongPlayer) : mpSongPlayer{pSongPlayer} {
	SetName("NextSong");
	AddRequirements(pSongPlayer);
}

// Called just before this Command runs the first time
void NextSong::Initialize() {
	mpSongPlayer->changeSongIndex(true);
}

// Called repeatedly when this Command is scheduled to run
void NextSong::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool NextSong::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void NextSong::End(bool interrupted) {
}