#ifndef BTOOLS_WARMSTART_INPUTREADER_H
#define BTOOLS_WARMSTART_INPUTREADER_H

#include <iostream>
#include <unistd.h>

#include "BTools/core/model/input/BCConfigInput.h"
#include "BTools/core/model/input/ODRConfigInput.h"
#include "BTools/core/interface/IFlowProfile.h"

#include "Types.h"

namespace WarmStart
{
    namespace InputReader
    {

        struct InputData
        {
            typedef BTools::Core::ODRConfigInput ODRConfigInput;
            typedef BTools::Core::IFlowProfile::FlowProfile FlowProfile;
            typedef BTools::Core::BCConfigInput::QPBOSolverType OptMethod;
            typedef BTools::Core::BCConfigInput::PenalizationMode PenalizationMode;

            InputData();

            std::string outputFolder;

            int radius;
            int iterations;

            ODRConfigInput::StructuringElementType seType;

            Shape shape;
            double gridStep;

            int levels;
            ODRConfigInput::LevelDefinition ld;
            bool opt;

            ODRConfigInput::NeighborhoodType neighborhood;

            bool excludeOptPointsFromAreaComputation;
            PenalizationMode penalizationMode;
            double warmStartPercentage;

        };

        InputData readInput(int argc,
                            char** argv);

    };
}

#endif //BTOOLS_WARMSTART_INPUTREADER_H
