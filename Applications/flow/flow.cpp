#include <InputReader.h>
#include "OneImageFlow.h"
#include "FlowControl.h"

namespace BTools
{
    namespace Application
    {
        std::string projectDir = PROJECT_DIR;
        std::string outputDir = projectDir + "/output";
    }
}

using namespace BTools::Application::Flow;
using namespace BTools::Application;

int main(int argc, char* argv[])
{
    InputReader::InputData id;
    InputReader::readInput(id,argc,argv);

    FlowControl::BCConfigInput bcInput(id.radius,
                                       id.dtWeight,
                                       id.sqWeight,
                                       id.lgWeight,
                                       id.optMethod);

    ODRConfigInput odrConfigInput(id.ac,
                                  id.cm,
                                  id.sm,
                                  id.levels,
                                  id.ld,
                                  id.neighborhood,
                                  id.optRegionInApplication,
                                  id.invertFrgBkg);

    FlowControl::BCFlowInput bcFlowInput("Digital Shapes Flow",
                                         bcInput,
                                         odrConfigInput,
                                         id.fp,
                                         id.iterations);

    std::string outputFilePath = id.outputFolder + "/" + id.flowName;

    FlowControl flow(bcFlowInput,
                     outputFilePath,
                     false);

    return 0;
}

