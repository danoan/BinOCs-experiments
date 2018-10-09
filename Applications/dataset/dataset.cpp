#include "DatasetControl.h"
#include "InputReader.h"

namespace BTools
{
    namespace Application
    {
        std::string projectDir = PROJECT_DIR;
        std::string imageDir = projectDir + "/images";
        std::string outputDir = projectDir + "/output";
    }
}


using namespace BTools::Application;

typedef Dataset::InputReader::InputData InputData;

template<typename TInstanceProfile>
void dataset(const std::string& prefix, const InputData& inputData)
{
    std::string outputFolder = outputDir + "/Dataset-" + prefix +
                               std::to_string(inputData.bcFlowInput.maxIterations) + "it";
    
    DatasetControl::runFlowOnDataset<TInstanceProfile>(inputData.datasetPath,
                                                       inputData.bcFlowInput,
                                                       outputFolder);
}

int main(int argc, char* argv[])
{
    typedef BTools::Model::CurvatureProfile CurvatureProfile;
    typedef BTools::Model::DataTermProfile DataTermProfile;
    
    Dataset::InputReader::InputData inputData;
    Dataset::InputReader::readInput(inputData,argc,argv);
    

    dataset<CurvatureProfile>("Curvature-",inputData);
    dataset<DataTermProfile>("Data-",inputData);
}