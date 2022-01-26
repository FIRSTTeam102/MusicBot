#include "RobotContainer.h"

#include <frc2/command/ParallelRaceGroup.h>

RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() {
	ConfigureButtonBindings();
}

RobotContainer* RobotContainer::GetInstance() {
	if (mRobotContainer == NULL) mRobotContainer = new RobotContainer();
	return (mRobotContainer);
}

void RobotContainer::ConfigureButtonBindings() {
	mDriverButtonY.WhenPressed(&mStopSongCommand);
	mDriverButtonA.WhenPressed(&mTogglePauseCommand);
	mDriverButtonX.WhenPressed(&mPreviousSongCommand);
	mDriverButtonB.WhenPressed(&mNextSongCommand);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	return nullptr;
}