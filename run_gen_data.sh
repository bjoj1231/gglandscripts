#!/bin/bash

# This is a script that will help generate data using ggland. It needs
# a file as input which have specfic commands in a specific order to
# work.
#
# ggland then creates at root-file which is opened by ROOT. From
# here the .txts containing the gun_vals etc. will be generated.
#
# Since this script is in the folder ~/bin it can be accessed from
# everywhere on the remote pc but should be run from the folder where
# ggland is installed.
#
# Run this command to generate data:
#
# mliden@pclab-110232: ~/land02/scripts/ggland$ run_gen_data.sh list_with_events.txt
#
# The commands are not shown here, but the order is futher down.

gglanddir=~/land02/scripts/ggland

# Compile the .root -> .txt converter
g++ -o convert_edep convert_edep.C `root-config --cflags --glibs`

. geant4.sh      # Need to run this before using ggland
while read line  # Run the following lines for each line in the given text file
do
    # 0: Number of particles fired
    # 1: Particle
    # 2: Energy interval
    # 3: Isotropic etc
    # 4: Number of events
    # 5: Type of detector
    # 6: Number of crystal deposits stored. ggland has a default value of 10.
    # 7: np is a command for running processes parallel., used to speed up
    #    this process.

    DATADIR1=./root/

    mkdir -p $DATADIR1

    # Array containing the input from the current line in input file.
    word=(${line})
    # Concatenating string for one gun.
    gun_line='--gun='${word[1]}',E='${word[2]}','${word[3]}
    gun_parse=""
    # Loop for concatenating strings to get the right number of guns
    # (value of word[0]).
    for ((i=0; i<${word[0]}; i++))
    do
        # Actual concatention.
	gun_parse="${gun_line}"' '"${gun_parse}"
    done

    filenamebase=${DATADIR1}mult${word[0]}ev${word[4]}cluster${word[6]}
    
    treeline='gunlist,'"$filenamebase.root"
    # Start generation of data for current line in input file.
    $gglanddir/land_geant4 \
	$gun_parse --events=${word[4]} \
	--xb=${word[5]},tree-num-clusters=${word[6]} \
	--tree=$treeline ${word[7]}
    
    # Replaces : with _, easier to navigate to directories without ":"
    # in the name, is interperted as a server otherwise.
    mod_energy=${word[2]//:/_}

    ## # Substitutes gen_data_dunedep_XB.sh from the group in 2018.
    ## root -q -b 'root_make_class_and_gen_data_files_XB.C('\"$filenamebase.root\"')'

    # Use the standalone ROOT conversion (.root -> .txt).
    ./convert_edep $filenamebase.root

    echo 'ROOT finished'

    
    # DATADIR=~/data/
    # Moves the files to a folder we have in common. Might need to be changed for next year.
    # mkdir -p ${DATADIR}"${word[0]}"_"$mod_energy"_"${word[4]}"
    # echo 'Moving files to another directory in' ${DATADIR}
    # mv XB_gun_vals.txt ${DATADIR}"${word[0]}"_"$mod_energy"_"${word[4]}"
    # mv XB_sum_of_dep_energies.txt ${DATADIR}"${word[0]}"_"$mod_energy"_"${word[4]}"
    # mv XB_det_data.txt ${DATADIR}"${word[0]}"_"$mod_energy"_"${word[4]}"
done < "$1"

#wait
# Runs the addback-routine on the generated .root-files
#~/land02/scripts/ggland/scripts/xb_run_addback.sh
#echo 'addback finished'

