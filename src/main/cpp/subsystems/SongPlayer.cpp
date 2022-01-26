#include "subsystems/SongPlayer.h"

SongPlayer::SongPlayer() : mMotor1{1} {
	SetName("SongPlayer");
	SetSubsystem("SongPlayer");

	// I couldn't get this to compile properly, maybe revisit it in the future?
	// // Find all songs in deploy/music
	// for (const auto & song : std::experimental::filesystem::directory_iterator(frc::filesystem::GetDeployDirectory() + "/music")) {
	// 	if (song.path().extension() == "chrp") mSongs.push_back(song.path().stem()); // just save the title of the song, full path will be added in setSong
	// }

	// File is created by gradle when building
	std::ifstream songsFile(frc::filesystem::GetDeployDirectory() + "/songs.txt");
	std::string song;
	while (std::getline(songsFile, song)) {
		if (song.size() > 0) mSongs.push_back(song);
	}
	songsFile.close();

	mPlayer.AddInstrument(mMotor1);
}

void SongPlayer::Periodic() {
	// Put code here to be run every loop
	// printf("Time: %u playing %i\n", mPlayer.GetCurrentTime(), isPlaying());
}

void SongPlayer::setSong(std::string songName) {
	mPlayer.LoadMusic("music/" + songName + ".chrp");

	if (mPlayMode != PlayMode::kQueue) mPlayer.Play();
	else mPlayer.Stop();

	nowPlaying = songName;
	printf("Now Playing: %s\n", nowPlaying.c_str());
}

void SongPlayer::changeSongIndex(bool skipForward = true) {
	// Find current song's index
	std::vector<std::string>::iterator itr = std::find(mSongs.begin(), mSongs.end(), nowPlaying);
	int currentIndex = -1;
	if (itr != mSongs.cend()) currentIndex = std::distance(mSongs.begin(), itr);

	int newIndex = currentIndex + (skipForward ? 1 : -1);
	if (newIndex >= (int)mSongs.size()) newIndex = 0; // wrap around to first
	else if (newIndex < 0) newIndex = mSongs.size() - 1; // wrap around to last

	setSong(mSongs[newIndex]);
}