The files in this repository will generate data from ggland (ggland needs to be installed). The .sh-file needs to be copied into your bin/ directory to work properly at the moment.

The files which has the name "rel" in them are unmodified files from previous years. For them to work the file-paths in those files need to be updated, and there might be other issues or bugs with them.

"run_gen_data.sh" needs "list.txt" as an argument. The .txt-file contains the various arguments in order to generate the sought data. This is to speed up and quickly generate different data. More info is in the script itself. To note is that due to how the gglands' addback-scripts work, it's not possible to properly run them with this script at the moment.

The .C files manipulates the generated .root file to extract the data needed for our training. This needs to be investigated more to see if there's any bugs in those scripts. 