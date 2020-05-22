#!/usr/bin/perl -w
#####################################################################
# FILE:  ClaytonNathaniel.pl
#
# PURPOSE:  This program parses data from the file "/etc/group" and 
#           displays a report regarding group members and their
#           WTAMU account affiliation on the thor server. Members of
#           each of the groups are displayed as either members of the
#           WT students domain or non-domain users.
#
#           DATE: 05/07/2019
#
#    NOTE:  This script must be run directly on thor to
#           get intended results. This program utilizes
#           PBIS find-user-by-name command.
#
#           Attributions: Professor Haiduk
#           Resources used: 
#               perlmaven.com (Array manipulation)
#               perldoc.perl.org (array sorting)
#               stackoverflow.com user: Shiplu Mokaddim 
#                       (capturing command output)
#                           
#    Programmer: Nathaniel Clayton
#
####################################################################

open(GROUP, "</etc/group") || die "Error: File not found";

@lines = <GROUP>;  # @lines an array of all lines in the file

$date = `/opt/pbis/bin/get-dc-time \"wtstudents.wtamu.edu\"`;  # get date and time
@datestring = split("TIME: ", $date);                          # manipulate date
$date = $datestring[1];					       # to remove DC TIME:

# print date centered to 80 columns
$spaces = ' ' x int((80 - length($date)) / 2); # used to center date/time
printf "\n$spaces $date $spaces";

# print byLine centered to 80 columns
$byLine = "By: Nathaniel Clayton"; # set the byline
$spaces = ' ' x int((80 - length($byLine)) / 2); # used to center byLine
printf "\n$spaces $byLine $spaces\n\n";

foreach $line (@lines) {
    chomp($line);       #NOTE: removes only newline from $line
                        #      and returns number of characters in $line

    @tokens = split( /:/, $line );
    $numTokens = scalar @tokens;   # $#tokens gives last index
    if($numTokens > 3){
	# array declaration scopred to if statement
        my @nonWT;		
        my @wtDom;
	
	# print group name
	printf "$tokens[0]:\n";
	
	# grab members from group
	@tokens = split(/,/, $tokens[3]);
	
	# cycle through each member
	foreach $token (@tokens) {
	    # use PBIS command to get user data
    	    my @pibs = `/opt/pbis/bin/find-user-by-name $token 2>&1`;
            
	    # check return code of PIBS command
            if($? == 0) {
		# get user first and last name
                @placeHolder = split(/:/, $pibs[6]);
                @placeHolder = split(" ", $placeHolder[1]);
		# format name and create string from name and token(userID)                
		my $name = $placeHolder[1] . ", " . $placeHolder[0];
                my $userString = $name . ":" . $token;
		
		# add user to wt domain array
                push @wtDom, $userString;

            } else {
		# add user to non wt domain array
                push @nonWT, $token;
            }
        }
	# if there are non wt domain members
	# sort and print them
        if(scalar @nonWT > 0){
            @nonWT = sort @nonWT;	# sort nonWT array
            printf "\t%38s", "User IDs not in wtstudents domain\n"; # non member header
	    # print each non member
            foreach $student(@nonWT){
                printf "%6s", " ";
                printf "%-20s\n", $student;
            }
            printf "\n"
        }
	# if there are wt domain members
	# sort and print them
        if(scalar @wtDom > 0){
            @wtDom = sort @wtDom;	# sort wtDom Array
            printf "\t%42s", "User IDs members of wtstudents domain\n"; # member header
            foreach $student(@wtDom){
                my @stud = split(":", $student); # split userId and name
                printf "%6s", " ";
                printf "%-18s", $stud[1]; # print userId
                printf "%s\n", $stud[0]; # print name
            }
            print "\n";
        }
    }
}
