# /usr/bin/perl -w
###############################################################################
#
#            CONTINENTAL Automotive GmbH - 2014 - All right reserved
#
#
#
################################################################################
# Each out line is triggered on found packages
###############################################################################
#
# Author:      Roman Bitner 
# Email :      Roman.02.Bitner-EXT@continental-corporation.com
#
# Contens:     Takes a GIT log output file in a special format and converts
#              it into an appropriate CSV format
#           	
#
# Invocation:	perl parse.pl <path\GIT-LOGFILE>
#
# Change History:
#
# V1:       2013-10-29
#           Initial version
#
###############################################################################



my $Line;                    # variable for reading the git csv file line by line
my $ExtrLine;                # variable for line extract - used for line type recognition
my $CmpLine;                 # variable for recognition pattern
my $CmpLine2;                # variable for recognition pattern
my $CmpLine3;                # variable for  recognition pattern
my $LineCounter;             # well could be useful in the future
my $result;                  # package processing holder
my $packagename;             # actual packagename holder
my $old_packagename;         # old packagename holder
my $LastWasACommitLine;      # a bool to remember last line type
my $commit_hash;             # holds actual commit hast
my $commit_hash_unprocessed; # holds actual commit hast
my $user;                    #holds actual commiter
my $email;                   #holds actual commiter email
my $date;                    #holds actual commit date
my $subject;                 #holds actual commit subject
my $MRPosition1;              #different user MR patterns
my $MRPosition2;
my $MRPosition3;
my $MRPosition4;
my $MRTempName;
my $NumberOfMaxMRS = 10;
my $MRIndexOffset;

my $MRName;

my @temp_array;

# -- Prototypes ----------------------------------------------------------------
sub FlushLineToOutFile;     # Puts one commit log line with all the information to a CSV output file
sub processMRsPattern1;
sub processMRsPattern2;
sub processMRsPattern3;




# open CSV file
open CSVFILE, "<$ARGV[0]" or die "could not access $ARGV[0]\n\n";
open OUTFILE, ">$ARGV[1]";
$LastWasACommitLine = 0;
$old_packagename = "";
$packagename = "Package";
$commit_hash = "123456";
while ($Line = <CSVFILE>) {
	
	
	
	chomp $Line;
	$CmpLine = "-hv-";
	$CmpLine2 = "    ";
	$CmpLine3 = "";
	$char = "/";
	$ExtrLine = substr($Line, 0, 4);
	#####################################################################
	# split file lines
	#####################################################################
	if( $CmpLine eq $ExtrLine )
	{
		###############################
		#commit line detected
		###############################
		
		#when previous line was also a commit line flush the prev line,
		#as it did not contain file information
		#and because it didnt contain files - assume an empty package name
		if( 1 == $LastWasACommitLine)
		{
			$packagename = "";
			#flush last line to the outfile
			FlushLineToOutFile();
			#get this new line values to be available for package lines
			($commit_hash, $user, $email, $date, $subject) = split(/;/, $Line);
			
		}
		else
		{
			#new commit line - could be followed by filenames - just remeber line values
			($commit_hash, $user, $email, $date, $subject) = split(/;/, $Line);
		}
		#inform that last detected was a commit line
		$LastWasACommitLine = 1;
		#reset old package name
		$old_packagename = "";
		
	}
	elsif($CmpLine2 eq $ExtrLine)
	{
		#detected an empty line do nothing
		#print OUTFILE "Empty line\n";
		$LastWasACommitLine = 0;
	}
	elsif($CmpLine3 eq $ExtrLine)
	{
		#detected an empty line 
		#print OUTFILE "Empty line\n";
		$LastWasACommitLine = 0;
	}
	else
	{
		###############################
		#package line detected
		###############################

		#find first '/'
		$result = index($Line, $char);
		#find second '/'
		$result = index($Line, $char, $result+1);
		if( $result != -1)
		{
			$packagename = substr($Line, 0, $result); #get the package name finally
		}
		else
		{
			$packagename = "File changed: " . $Line;
		}
		if($old_packagename ne $packagename)
		{
			#new package in the row of packages detected
			#add a new commit line
			FlushLineToOutFile();
		}
		#else if the package is the same like old one, don't add any lines to file
		#remeber the packagename
		$old_packagename = $packagename;
		#inform that the last line was not a commit line
		$LastWasACommitLine = 0;

	}

}

#file ended, flush last line
FlushLineToOutFile();
close (CSVFILE);
close (OUTFILE);
	
###############################################################################
#
# Prints a line to the resulting csv file
#
# Parameter:    none
#
# Returnvalue:  none
#	
sub FlushLineToOutFile
{
	###################################################################################
	#clean commit hash out of -hv- it assumes the short hash is always 7 CHR in length
	#this could be adapted to variable hash number length if needed
	$commit_hash_unprocessed = substr($commit_hash, 0, 4);
	if( $commit_hash_unprocessed eq $CmpLine) #check out if commit hash contains pattern recognition
	{
		$commit_hash = substr($commit_hash, 5, 9);
	}
	###################################################################################
	# try to extract MR number this function is just an example
	$MRName = ParseAllMRS();



	

	#$MRPosition1 = index($subject, "MR4");
	#if($MRPosition1 != -1)
	#{
	#	$MRTempName = substr($subject, $MRPosition1, 7);
    #	$MRTempName = "#" . $MRTempName;
	#	$MRName = $MRTempName;
	#}
	#$MRPosition1 = index($subject, "mr4");
	#if($MRPosition1 != -1)
	#{
	#	$MRTempName = substr($subject, $MRPosition1, 7);
    #	$MRTempName = "#" . $MRTempName;
	#	$MRName = uc $MRTempName;
	#}

	
	##########################
	print OUTFILE "$commit_hash; $MRName ; $user ; $packagename ; $email ; $date ; $subject\n";
}

sub ParseMR
{
	my $RecognitionPattern = shift;
	my $PatternLength      = shift;
	my $PatternPrefix      = shift;
	my $MrPositionOffset   = shift;
	my $MRName = "";
	my $MRIndexOffsetLocal      = shift;
	
	$MRPosition1 = index($subject, $RecognitionPattern, $MRIndexOffsetLocal);
	$MRIndexOffset = $MRPosition1 + 1;
	if($MRPosition1 != -1)
	{
		$MRTempName = substr($subject, $MRPosition1+$MrPositionOffset, $PatternLength, ); #extract bare MR Number itself
		$MRTempName =~ s/\s+//g;                          # remove white space
		$MRTempName = $PatternPrefix . $MRTempName;       # add prefix like #MR
		$MRTempName = $MRTempName . " ";                  # Add whitespace after
		$MRName = uc $MRTempName;                         # move to uppercase
		#$MRName = $MRName . $MRTempName;
	}
	return($MRName);
}

sub ParseAllMRS
{
	my $MRNameLocal = "";
	my $MRNameLocalTemp = "";
	####### DIFFERENT PATERNS ####################################
	##############################################################
	$MRIndexOffset = 0;
	for(my $i = 1; $i <= $NumberOfMaxMRS; $i++)
	{
		$MRNameLocalTemp = ParseMR("#4", 5, "#MR", 1, $MRIndexOffset);
		#add only, if not already in the MR list:
		if( index($MRNameLocal, $MRNameLocalTemp) == -1)
		{
			#add the new MR if not already in the list:
			$MRNameLocal = $MRNameLocal . $MRNameLocalTemp;
		}
	}
	##############################################################
	$MRIndexOffset = 0;
	for(my $i = 1; $i <= $NumberOfMaxMRS; $i++)
	{
		$MRNameLocalTemp = ParseMR("MR 4", 8, "#", 0, $MRIndexOffset);
		if( index($MRNameLocal, $MRNameLocalTemp) == -1)
		{
			#add the new MR if not already in the list:
			$MRNameLocal = $MRNameLocal . $MRNameLocalTemp;
		}
	}
	##############################################################
	$MRIndexOffset = 0;
	for(my $i = 1; $i <= $NumberOfMaxMRS; $i++)
	{
		$MRNameLocalTemp = ParseMR("MR4", 7, "#", 0, $MRIndexOffset);
		if( index($MRNameLocal, $MRNameLocalTemp) == -1)
		{
			#add the new MR if not already in the list:
			$MRNameLocal = $MRNameLocal . $MRNameLocalTemp;
		}
	}
	##############################################################
	$MRIndexOffset = 0;
	for(my $i = 1; $i <= $NumberOfMaxMRS; $i++)
	{
		$MRNameLocalTemp = ParseMR("mr4", 7, "#", 0, $MRIndexOffset);
		if( index($MRNameLocal, $MRNameLocalTemp) == -1)
		{
			#add the new MR if not already in the list:
			$MRNameLocal = $MRNameLocal . $MRNameLocalTemp;
		}
	}
	##############################################################
	$MRIndexOffset = 0;
	for(my $i = 1; $i <= $NumberOfMaxMRS; $i++)
	{
		$MRNameLocalTemp = ParseMR("_4", 5, "#MR", 1, $MRIndexOffset);
		if( index($MRNameLocal, $MRNameLocalTemp) == -1)
		{
			#add the new MR if not already in the list:
			$MRNameLocal = $MRNameLocal . $MRNameLocalTemp;
		}
	}
	##############################################################
	
	
	return($MRNameLocal);

}


__END__