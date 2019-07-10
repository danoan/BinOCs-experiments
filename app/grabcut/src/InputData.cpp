#include "InputData.h"

namespace GrabCut
{
    void usage(char* argv[])
    {
        std::cerr << "Usage: ./" << argv[0] << "imgPath fgSeedMask bgSeedMask outputObjectPath "
                  << "[-u unknownSeedMaskPath] [-o outputSegPath] [-s show segmented image] \n\n";
    }

    InputData readInput(int argc, char* argv[])
    {
        if(argc < 5)
        {
            usage(argv);
            exit(1);
        }

        InputData id;
        char opt;
        while( (opt=getopt(argc,argv,"u:o:s"))!=-1 )
        {
            switch(opt)
            {
                case 'u':
                {
                    id.unknownMask = optarg;
                    break;
                }
                case 'o':
                {
                    id.outputSegImage = optarg;
                    break;
                }
                case 's':
                {
                    id.showSeg=true;
                    break;
                }
                default:
                {
                    usage(argv);
                    exit(2);
                }
            }
        }

        id.imgPath = argv[optind++];
        id.fgSeedMask = argv[optind++];
        id.bgSeedMask = argv[optind++];
        id.outputObject = argv[optind++];

        return id;
    }
}
