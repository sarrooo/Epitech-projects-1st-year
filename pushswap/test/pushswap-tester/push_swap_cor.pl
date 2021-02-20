#!/usr/bin/perl -w

BEGIN
{
    push @INC, "$ENV{HOME}/mbin";
}

use swap;
use Getopt::Std;
use File::Basename;

### Handler ###
$SIG{ALRM} = \&killer;

### Default Parameters ###
my $Class = 1;
my $Tree = $ENV{PWD};
my $Time = 120;
our($opt_h);
$dir_tst = "tests";

### Variables ###
my @Params;
my $ttxt = "$Tree/trace/trace.txt";
my $t_dir = "$Tree/trace";
my $elem;
my $exe = "push_swap";
my @Files;
#@l_a;
#@l_b;
#@l_tmp;

### Functions ###

sub	er_usage
{
    die  "usage: push_swap_cor.pl [Time(sec)] [Directory]\n";
}

sub	killer
{
    zprint "LE PROCESS GROUP $pid MORT\n";
    if ($Class == 0)
    {
	print kill -9 -1;
    }
    else
    {
	print kill -9, $pid;
    }
}

sub	get_files
{
    my($i) = 0;

    zprint "<<INITIALIZE>>\n";
    zprint ">                [ Time Limit(sec): $Time ]\n";
    zprint ">>               [ Directory : $dir_tst ]\n";
    print "DIR TEST = $dir_tst\n" if (defined($opt_d));
    chdir($dir_tst);
    @Files = glob("*");
    chdir($Tree); 
}

sub	start_ini
{
    zprint "<<COMPILATION>>\n";
    zprint ">>>              [ Clean Bin Push_swap ]\n";
    system ("/bin/rm $Tree/push_swap");
    if ( -e "Makefile" )
    {    zprint ">>>>             [ Makefile Exist ]\n";}
    else
    {    
	zprint ">>>>             [ Makefile Not Exist ]\n";
	er_user();
    }
    zprint ">>>>>            [ Make Fclean ]\n";
    if (!(system ("make fclean 2>> $ttxt >> $ttxt") >> 8))
    {    zprint ">>>>>            [ Make Fclean OK ]\n";}
    else
    {
	zprint ">>>>>            [Make Fclean FAILED ]\n";
	er_user();
    }
    print "1 # [$ENV{PWD}]\n" if (defined($opt_d));
    print "2 # [$ENV{PWD}]\n" if (defined($opt_d));
    zprint ">>>>>>           [ Make Push_swap ]\n";
    if (!(system ("make 2>> $ttxt >> $ttxt") >> 8))
    {    zprint ">>>>>>           [ Make OK ]\n";}
    else
    {
	zprint ">>>>>>           [ Make FAILED ]\n";
	er_user();
    }
    if ( -e "push_swap" )
    {    zprint ">>>>>>>          [ Bin Exist ]\n";}
    else
    {    
	zprint ">>>>>>>          [ Bin Not Exist ]\n";
	er_user();
    }
}

sub	start_exe
{
    my($i) = 0;
    my($name_File);

    zprint "<<EXECUTION>>\n";
    foreach $name_File (@Files)
    {
	print "NAME FILE = $name_File\n" if (defined($opt_d));
	zprint ">>>>>>>>         [ Params File N$i\t: $dir_tst/$name_File ]\n";
	next_exe("$name_File");
	$i++;
    }
}

sub	next_exe($)
{
    my($name_file) = @_;
    ($param) = open_file("$dir_tst/$name_file");
    chomp($param);
    $cmd = "$Tree/$exe $param";
    if ($pid = fork)
    {   #Pere
	alarm $Time;
	wait;
    } 
    else
    {   #Fils
	setpgrp;
	zprint ">>>>>>>>>        [ Cmd : $cmd ]\n";
	if ($Class == 0)
	{
	    syscall(&SYS_setuid, 27);
	    syscall(&SYS_seteuid, 27);
	}
	print "\#\#    [${name_file}.trace]\n" if (defined($opt_d));
	exec  "$cmd 2> $t_dir/${name_file}.trace > $t_dir/${name_file}.trace" || die "Bin Error: $!\n";
    }
}
 
sub	start_cor
{
    my($i) = 0;

    zprint "<<CORRECTION>>\n";
    foreach $name (@Files)
    {
	zprint ">>>>>>>>         [ Trace File N$i\t: $t_dir/${name}.trace ]\n";
	next_cor("$t_dir/${name}.trace", "$dir_tst/${name}");
	$i++;
    }
}

sub numerik { $a <=> $b; } 


sub	test_len($)
{
    my ($num) = @_;
    if (defined($num))
    {
	if (length($num) < 6)
	{
	    zprint "$num ";
	}
	else
	{
	    zprint substr($num, 0, 6);
	    zprint "... ";
	}
    }
}

sub	next_cor($$)
{
    my($tracefile, $Param) = @_;
    my $idx = 1;
    @l_a = ();
    @l_b = ();
    @l_tmp = ();

    ($step) = open_file($tracefile);
    chomp ($step);
    zprint ">>>>>>>>>        [ Trace File Content\t: $step ]\n";
    @STEP = split(/\ +/, $step);

    ($param) = open_file($Param);
    chomp ($param);
    @l_a = split(/\ +/, $param);
    @l_tmp = @l_a;
    zprint ">>>>>>>>>>       [ Param File Content\t: ";
    test_len($l_a[0]);
    test_len($l_a[1]);
    test_len($l_a[2]);
    test_len($l_a[3]);
    zprint "... " if (defined($l_a[4]));
    zprint "]\n";
    

    print "[COR]\t[L_A]\t[L_B]\n" if (defined($opt_d));
    if (defined($opt_d))
    {
	for($i=0; $i <= $#l_tmp; $i++)
	{
	    print "[$l_tmp[$i]]\t[$l_a[$i]]\t";
	    print "\n" if (!defined($l_b[$i]));
	    print "[$l_b[$i]] \n" if (defined($l_b[$i]));
	}
    }
    foreach $i (@STEP)
    {
	zprint "STEP $idx = [$i]\n";
	if (exists($func_list{$i}))
	{
	    $func = $func_list{$i};
	    &$func();
	    lprint();
	}
	else
	{
	    chomp($i);
	    zprint "Func '$i' Not Exists\n";
	}
	$idx++;
    }
    @l_tmp = sort numerik @l_tmp;
    for ($stat=0, $i=0; $i <= $#l_tmp; $i++)
    {
	if ($l_tmp[$i] != $l_a[$i])
	{
	    zprint "[END]\t[L_A]\n";
	    zprint "[$l_tmp[$i]]\t[$l_a[$i]]\n";    
	    zprint "[ Bad Sort On The $i Elem : $l_a[$i] ] \n";
	    $stat = 1;
	    last;
	}
    }
    if ($stat == 0)
    {
	zprint "[ Good Sort ]\n";
    }
}

sub	aff_usage
{
    print "./push_swap_cor.pl [-htrd]\n";
    print "h : print usage\n";
    print "t : change default time\n";
    print "r : change default test directory\n";
    print "d : start with debug mode\n";
    exit(0);
}

sub	init_base
{
    aff_usage() if defined ($opt_h);
    $User = $opt_l if defined($opt_l);
    print "Launch Default Params for $User\n" if defined($opt_v);
    $Time = $opt_t if defined($opt_t);
    $dir_tst = $opt_r if defined($opt_r);
    mkdir ($t_dir, 0755) if (!(-d $t_dir));
    unlink ($ttxt) if (-f $ttxt );
}

sub	launch
{
    open(TTXT , ">> $ttxt") or die "can 't open $ttxt\n";
    &get_files;
    &start_ini;
    &init_func;
    &start_exe;
    &start_cor;
    close (TTXT);
}

sub	main
{
    getopts('vhl:t:r:d');
    &init_base;
    #if (!(defined($opt_l)))
    #{
    #er_usage();
    #}
    print "<<MODE - USER>>\n" if defined($opt_v);
    &launch;
}

main();

