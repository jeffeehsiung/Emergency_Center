// Sound is one of the concrete strategies under parent interface ActionStrategy that is used by the SensorContext class.
// the Sound concrete strategy class header file is shown below:
#ifndef SOUND_H
#define SOUND_H

#include "ActionStrategy.h"

class Sound : public ActionStrategy
{
public:
    Sound();
    virtual ~Sound();
    void executeStrategy() override;
};

#endif  // SOUND_H
