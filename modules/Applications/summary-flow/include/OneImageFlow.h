#ifndef BTOOLS_APPLICATION_FLOW_ONEIMAGEFLOW_H
#define BTOOLS_APPLICATION_FLOW_ONEIMAGEFLOW_H

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include <DGtal/helpers/StdDefs.h>
#include <DGtal/io/boards/Board2D.h>

#include <DIPaCUS/base/Representation.h>
#include <DIPaCUS/derivates/Misc.h>
#include <DIPaCUS/components/Neighborhood.h>
#include <DIPaCUS/base/Representation.h>


namespace SummaryFlow
{
    class OneImageFlow
    {
    public:
        typedef DGtal::Z2i::DigitalSet DigitalSet;
        typedef DGtal::Z2i::Point Point;
        typedef DGtal::Z2i::Domain Domain;
        typedef DGtal::Color Color;
        typedef DGtal::Board2D Board2D;

        typedef std::set<Point> SetPoint;
        typedef std::vector< SetPoint > SetPointSequence;
        typedef SetPointSequence::const_iterator SetPointSequenceIterator;

        typedef DIPaCUS::Representation::Image2D Image2D;
        typedef DIPaCUS::Neighborhood::EightNeighborhoodPredicate Pred8;


    public:
        OneImageFlow(const std::string& imageSrcFolder,
                     const std::string& imageOutputPath,
                     int seqTep=1);

    private:
        Domain commonDomain(SetPointSequenceIterator begin,
                            SetPointSequenceIterator end);

        void createUnifiedImage(const std::string& imgOutputPath,
                                SetPointSequenceIterator begin,
                                SetPointSequenceIterator end,
                                int seqStep);
    };

}

#endif //BTOOLS_APPLICATION_FLOW_ONEIMAGEFLOW_H
