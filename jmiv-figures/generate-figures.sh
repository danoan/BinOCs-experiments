#!/usr/bin/env bash

usage(){ echo "Usage: $0 BTOOLS_BINARIES_FOLDER EXT_PROJECTS_BINARIES_FOLDER" 1>&2; exit 1;}

while getopts ":ucs" o; do
    case "${o}" in
        *)
            usage
            ;;
    esac
done

SCRIPT_FOLDER=$( cd $(dirname ${BASH_SOURCE[0]}) >/dev/null 2>&1 && pwd)

BTOOLS_BIN=$(realpath $1)
EXT_BIN=$(realpath $2)

echo "Generating JMIV figure 1"
${SCRIPT_FOLDER}/fig1/jmiv-fig1.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 2"
${SCRIPT_FOLDER}/fig2/jmiv-fig2.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 3 and 4"
${SCRIPT_FOLDER}/fig3-4/jmiv-fig3-4.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 5"
${SCRIPT_FOLDER}/fig5/jmiv-fig5.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 6"
${SCRIPT_FOLDER}/fig6/jmiv-fig6.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 7"
${SCRIPT_FOLDER}/fig7/jmiv-fig7.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 8"
${SCRIPT_FOLDER}/fig8/jmiv-fig8.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 9"
${SCRIPT_FOLDER}/fig9/jmiv-fig9.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 10"
${SCRIPT_FOLDER}/fig10-11/jmiv-fig10-11.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 12"
${SCRIPT_FOLDER}/fig12/jmiv-fig12.sh ${BTOOLS_BIN} ${EXT_BIN}
echo "Generating JMIV figure 13-14"
${SCRIPT_FOLDER}/fig13-14/jmiv-fig13-14.sh ${BTOOLS_BIN} ${EXT_BIN}