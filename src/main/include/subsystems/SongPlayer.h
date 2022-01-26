#pragma once

#include <ctre/Phoenix.h>
#include <ctre/phoenix/music/Orchestra.h>
#include <frc/Filesystem.h>
#include <frc2/command/SubsystemBase.h>

#include <algorithm>
#include <fstream>
// #include <experimental/filesystem>
#include <vector>

class SongPlayer : public frc2::SubsystemBase {
	public:
		SongPlayer();
		std::vector<std::string> mSongs;

		enum PlayMode {
			kSingle = 1, // play song and then stop playing
			kQueue = 2, // set song, but don't play it until told to

			// there is no way to tell when a song has ended
			// kAutoplay = 3, // play next song after current one finishes
			// kRepeat = 4 // repeat current song
		};
		PlayMode mPlayMode = PlayMode::kSingle;
		void setPlayMode(PlayMode playMode) {
			mPlayMode = playMode;
		}

		void setSong(std::string songName);
		void changeSongIndex(bool skipForward);

		bool isPlaying() {
			return mPlayer.IsPlaying();
		};
		void togglePause() {
			if (mPlayer.IsPlaying()) mPlayer.Pause();
			else mPlayer.Play();
		};
		// Resets the track position
		void stopSong() {
			mPlayer.Stop();
		}

		void Periodic() override;

	private:
		Orchestra mPlayer;
		TalonFX mMotor1;

		std::string nowPlaying;
};
