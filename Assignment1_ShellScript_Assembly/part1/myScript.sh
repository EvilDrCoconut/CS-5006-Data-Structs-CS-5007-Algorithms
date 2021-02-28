# !/bin/bash
# The line above makes your script executable.
# You should write your tutorial in here.
# Include comments inline with your script explaining what is going on.

# You might start out by first saying the purpose of the script and
# demonstrating its usage.

# The following code is used to demonstrate how a certain directory or select directories can be mapped for a user. We start by returning to the main menua of the user's file. From there, we move into any files we may want to go into. It is posible though to conduct a tree diagram of all directories from this point, though all directories in the user's files will be listed. In this program, we enter into the systems class files, then into the system's homeworks and lab file. Now would be a good spot to check all homeworks and labs done by the user, or is saved on file. This can also help locate extra swap files that may need to be deleted or a file that the user was looking for. Following this, the user (myself) chose a file (Assignment1) to further analize. From here, a tree diagram where the root is the Assignment1 File is created. This shows part1, part2, and the README of Assignment1, then travels into the first directory (part1) and creates a tree of all files in there. At this point, if there were other directories in part1, tree would recursively dig deeper into the other directories as a DFS until it can list off all files in a directory. Then it travels back to Assignment1 and then delves into part2 as the same way it did part1. After returning from listing all files in part2, it sees that no more directories exist within Assignment1 and ends there.

cd	# returns the terminal to the users overall files and directories.
cd systems/	# enters into one of the user's directories (systems).
cd Systems_homework/	# enters into another directory to further close the search gap.
cd Assignment1_ShellScript_Assembly/	# enters into one last directory so search area is not so wide.
tree -a		# from the entered directory above, displays all directories and files within, before displaying recursively all files and directories within nested directories.


# The code below then tells to displY all directories and files in Assignment1 for the user to see. The above tree helps the user to see where certain files are, and the below code allows them to continue and help correctly reach the file they wished to view.

ls	# displays the available options to user.
ls | wc -l	# Streamlines the options displayed for user.

