#ifndef BTOOLS_APPLICATION_FLOW_INPUTREADER_H
#define BTOOLS_APPLICATION_FLOW_INPUTREADER_H

#include <iostream>
#include <unistd.h>
#include <BTools/model/input/BCFlowInput.h>


namespace BTools
{
    namespace Application
    {
        namespace Flow
        {
            class InputReader
            {
            public:
                struct InputData
                {
                    typedef BinOCS::BoundaryCorrection::ODRConfigInput ODRConfigInput;
                    typedef BinOCS::BoundaryCorrection::IFlowProfile::FlowProfile FlowProfile;

                    std::string flowName;
                    std::string outputFolder;

                    int radius;
                    int iterations;
                    bool useDigitalArea;


                    ODRConfigInput::ApplicationCenter ac;
                    ODRConfigInput::ApplicationMode am;
                    ODRConfigInput::CountingMode cm;
                    ODRConfigInput::SpaceMode  sm;
                    ODRConfigInput::NeighborhoodType neighborhood;
                    int levels;

                    FlowProfile fp;

                    double sqWeight;
                    double dtWeight;
                    double lgWeight;
                };

                static void readInput(InputData& id,
                                      int argc,
                                      char** argv);

            private:
                static void defaultValues(InputData& id);
            };
        }
    }
}

#endif //BTOOLS_APPLICATION_FLOW_INPUTREADER_H
