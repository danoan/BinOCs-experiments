#ifndef BINOCS_FLOWSTEPCONFIG_H
#define BINOCS_FLOWSTEPCONFIG_H

#include <BinOCS/core/interface/IFlowStepConfig.h>

namespace BinOCS
{
    namespace Core
    {
        class Correct:public IFlowStepConfig
        {
        public:
            typedef SCaBOliC::Core::ODRModel::OptimizationMode  OptimizationMode;
            typedef SCaBOliC::Core::ODRModel::ApplicationMode  ApplicationMode;

        public:
            Correct(bool optInApplicationRegion=false,
                    bool invertFrgBkg=false):flagOptInApplicationRegion(optInApplicationRegion){}

            OptimizationMode optimizationMode() const{ return OptimizationMode::OM_OriginalBoundary; }
            ApplicationMode applicationMode() const { return ApplicationMode::AM_AroundBoundary; }
            bool optInApplicationRegion() const{ return flagOptInApplicationRegion; }

            void initialSolution(LabelsVector& labelsVector) const { labelsVector.setZero(); }

        private:
            bool flagOptInApplicationRegion;
        };
    }
}
#endif //BINOCS_FLOWSTEPCONFIG_H