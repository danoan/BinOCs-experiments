#!/bin/sh

PROJECT_FOLDER=/home-local/dantu1/GIT/PhD/BTools
RADIUS_PLOT_APP=${PROJECT_FOLDER}/exp/utils/radius-plot.sh
FLOW_APP=${PROJECT_FOLDER}/cmake-build-debug/Applications/flow/flow
SUMMARY_FLOW_APP=${PROJECT_FOLDER}/cmake-build-debug/Applications/flow/make-summary-flow
MAX_IT=30

MODE=0

list_of_folders()
{
    MAIN_FOLDER=$1

    LIST_FILES=`ls $MAIN_FOLDER`
    LIST_FLOW_FOLDER=""
    for F in $LIST_FILES
    do
     if [ -d "${MAIN_FOLDER}/${F}" ]
     then
        LIST_FLOW_FOLDER="${LIST_FLOW_FOLDER} $F"
     fi
    done

    echo $LIST_FLOW_FOLDER
}

summary_flow()
{
    FLOW_FOLDER=$1
    LIST_FLOW_FOLDER=$(list_of_folders $FLOW_FOLDER)

    for F in $LIST_FLOW_FOLDER
    do
        $SUMMARY_FLOW_APP ${FLOW_FOLDER}/${F} 5
    done

}

create_plots()
{
    FLOW_FOLDER=$1
    SUFFIX=$2

    LIST_FLOW_FOLDER=$(list_of_folders $FLOW_FOLDER)

    $RADIUS_PLOT_APP $FLOW_FOLDER BALL-$SUFFIX Ball.txt ${LIST_FLOW_FOLDER} $MODE
    $RADIUS_PLOT_APP $FLOW_FOLDER FLOWER-$SUFFIX Flower.txt ${LIST_FLOW_FOLDER} $MODE
    $RADIUS_PLOT_APP $FLOW_FOLDER TRIANGLE-$SUFFIX Triangle.txt ${LIST_FLOW_FOLDER} $MODE
    $RADIUS_PLOT_APP $FLOW_FOLDER SQUARE-$SUFFIX Square.txt ${LIST_FLOW_FOLDER} $MODE
    $RADIUS_PLOT_APP $FLOW_FOLDER PENTAGON-$SUFFIX Pentagon.txt ${LIST_FLOW_FOLDER} $MODE
    $RADIUS_PLOT_APP $FLOW_FOLDER HEPTAGON-$SUFFIX Heptagon.txt ${LIST_FLOW_FOLDER} $MODE
    $RADIUS_PLOT_APP $FLOW_FOLDER ELLIPSE-$SUFFIX Ellipse.txt ${LIST_FLOW_FOLDER} $MODE
}

#-------------RADIUS----------------
OUTPUT_SUBFOLDER=real/

$FLOW_APP -r 3 -i $MAX_IT -m around -a 0 -c 0 -s 0 -p single -n 4 -l 3 -q 1 -t 0 -g 0  single-ps-r3 $OUTPUT_SUBFOLDER&
$FLOW_APP -r 3 -i $MAX_IT -m around -a 0 -c 0 -s 0 -p double -n 4 -l 3 -q 1 -t 0 -g 0  double-ps-r3 $OUTPUT_SUBFOLDER&

$FLOW_APP -r 7 -i $MAX_IT -m around -a 0 -c 0 -s 0 -p single -n 4 -l 7 -q 1 -t 0 -g 0 single-ps-r7 $OUTPUT_SUBFOLDER&
$FLOW_APP -r 7 -i $MAX_IT -m around -a 0 -c 0 -s 0 -p double -n 4 -l 7 -q 1 -t 0 -g 0 double-ps-r7 $OUTPUT_SUBFOLDER&


$FLOW_APP -r 3 -i $MAX_IT -m around -a 0 -c 1 -s 1 -p single -n 4 -l 3 -q 1 -t 0 -g 0  single-cptl-r3 $OUTPUT_SUBFOLDER&
$FLOW_APP -r 3 -i $MAX_IT -m around -a 0 -c 1 -s 1 -p double -n 4 -l 3 -q 1 -t 0 -g 0  double-cptl-r3 $OUTPUT_SUBFOLDER&

$FLOW_APP -r 7 -i $MAX_IT -m around -a 0 -c 1 -s 1 -p single -n 4 -l 7 -q 1 -t 0 -g 0  single-cptl-r7 $OUTPUT_SUBFOLDER&
$FLOW_APP -r 7 -i $MAX_IT -m around -a 0 -c 1 -s 1 -p double -n 4 -l 7 -q 1 -t 0 -g 0  double-cptl-r7 $OUTPUT_SUBFOLDER&


$FLOW_APP -r 3 -i $MAX_IT -m around -a 1 -c 0 -s 1 -p single -n 4 -l 3 -q 1 -t 0 -g 0  single-cpxl-r3 $OUTPUT_SUBFOLDER&
$FLOW_APP -r 3 -i $MAX_IT -m around -a 1 -c 0 -s 1 -p double -n 4 -l 3 -q 1 -t 0 -g 0  double-cpxl-r3 $OUTPUT_SUBFOLDER&

$FLOW_APP -r 7 -i $MAX_IT -m around -a 1 -c 0 -s 1 -p single -n 4 -l 7 -q 1 -t 0 -g 0  single-cpxl-r7 $OUTPUT_SUBFOLDER&
$FLOW_APP -r 7 -i $MAX_IT -m around -a 1 -c 0 -s 1 -p double -n 4 -l 7 -q 1 -t 0 -g 0  double-cpxl-r7 $OUTPUT_SUBFOLDER&

wait
summary_flow ${PROJECT_FOLDER}/output/flow/${OUTPUT_SUBFOLDER}
